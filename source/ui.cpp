#include "ui.hpp"

#include <sys/iosupport.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace UI {

// ——— palette (Majora twilight purple + mask gold) ———
const u32 ColBgTop       = C2D_Color32(0x16, 0x10, 0x22, 0xFF);
const u32 ColBgTopBot    = C2D_Color32(0x21, 0x18, 0x33, 0xFF);
const u32 ColBgBottom    = C2D_Color32(0x18, 0x12, 0x26, 0xFF);
const u32 ColHeader      = C2D_Color32(0x2A, 0x1D, 0x44, 0xFF);
const u32 ColHeaderEdge  = C2D_Color32(0xF0, 0xC4, 0x3C, 0xFF);
const u32 ColPanel       = C2D_Color32(0x24, 0x1A, 0x38, 0xFF);
const u32 ColPanelEdge   = C2D_Color32(0x4E, 0x38, 0x78, 0xFF);
const u32 ColSelBar      = C2D_Color32(0x46, 0x2E, 0x74, 0xFF);
const u32 ColSelNotch    = C2D_Color32(0xF0, 0xC4, 0x3C, 0xFF);
const u32 ColAccent      = C2D_Color32(0xF0, 0xC4, 0x3C, 0xFF);
const u32 ColText        = C2D_Color32(0xED, 0xE8, 0xF5, 0xFF);
const u32 ColTextDim     = C2D_Color32(0x9A, 0x90, 0xB4, 0xFF);
const u32 ColTextLocked  = C2D_Color32(0x5E, 0x56, 0x74, 0xFF);
const u32 ColValue       = C2D_Color32(0x7F, 0xE3, 0xC8, 0xFF);
const u32 ColGood        = C2D_Color32(0x86, 0xD9, 0x86, 0xFF);
const u32 ColBad         = C2D_Color32(0xE0, 0x60, 0x60, 0xFF);
const u32 ColScrollTrack = C2D_Color32(0x2E, 0x22, 0x48, 0xFF);
const u32 ColScrollThumb = C2D_Color32(0x8A, 0x6C, 0xC8, 0xFF);

namespace {

C3D_RenderTarget* topTarget;
C3D_RenderTarget* botTarget;
C2D_TextBuf textBuf;
bool inFrame = false;
DrawFn redrawFn = nullptr;

// ————————————————————————————————————————————————
// Virtual console: captures stdout so the untouched logic code's
// ANSI-positioned printf progress can be rendered by the new UI.
// ————————————————————————————————————————————————
constexpr int ConRows = 32;
constexpr int ConCols = 64;

char conChar[ConRows][ConCols];
u8   conColor[ConRows][ConCols];
int  conRow = 0, conCol = 0;
u8   curColor = 7;  // white

// ANSI SGR color indices → render colors
u32 AnsiColor(u8 idx) {
    switch (idx) {
        case 1:  return ColTextDim;                              // dim
        case 0:  return C2D_Color32(0x66, 0x60, 0x78, 0xFF);     // black
        case 2:  return ColGood;                                 // green
        case 3:  return C2D_Color32(0xE8, 0xD0, 0x6A, 0xFF);     // yellow
        case 4:  return C2D_Color32(0x7A, 0xA2, 0xE8, 0xFF);     // blue
        case 5:  return C2D_Color32(0xC9, 0x8F, 0xE8, 0xFF);     // magenta
        case 6:  return C2D_Color32(0x7A, 0xDC, 0xE0, 0xFF);     // cyan
        default: return ColText;                                 // white / reset
    }
}

enum class AnsiState { Normal, Esc, Csi };
AnsiState ansiState = AnsiState::Normal;
char ansiParams[16];
int  ansiLen = 0;

void GridClear() {
    memset(conChar, ' ', sizeof(conChar));
    memset(conColor, 7, sizeof(conColor));
    conRow = conCol = 0;
    curColor = 7;
}

void GridScroll() {
    memmove(conChar[0], conChar[1], sizeof(conChar[0]) * (ConRows - 1));
    memmove(conColor[0], conColor[1], sizeof(conColor[0]) * (ConRows - 1));
    memset(conChar[ConRows - 1], ' ', ConCols);
    memset(conColor[ConRows - 1], 7, ConCols);
}

void GridPut(char c) {
    if (c == '\n') {
        conCol = 0;
        if (++conRow >= ConRows) { conRow = ConRows - 1; GridScroll(); }
        return;
    }
    if (c == '\r') { conCol = 0; return; }
    if (c == '\t') {
        for (int i = 0; i < 4; i++) GridPut(' ');
        return;
    }
    if ((unsigned char)c < 32) return;
    if (conCol >= ConCols) {
        conCol = 0;
        if (++conRow >= ConRows) { conRow = ConRows - 1; GridScroll(); }
    }
    conChar[conRow][conCol] = c;
    conColor[conRow][conCol] = curColor;
    conCol++;
}

void AnsiFinish(char final) {
    ansiParams[ansiLen] = '\0';
    if (final == 'H' || final == 'f') {
        int r = 0, c = 0;
        sscanf(ansiParams, "%d;%d", &r, &c);
        conRow = std::clamp(r > 0 ? r - 1 : r, 0, ConRows - 1);
        conCol = std::clamp(c > 0 ? c - 1 : c, 0, ConCols - 1);
    } else if (final == 'm') {
        const char* p = ansiParams;
        do {
            int n = atoi(p);
            if (n == 0 || n == 39) curColor = 7;
            else if (n == 2) curColor = 1;  // dim → our dim slot
            else if (n >= 30 && n <= 37) curColor = (n == 31) ? 8 : (u8)(n - 30);
            p = strchr(p, ';');
        } while (p++);
    } else if (final == 'J') {
        GridClear();
    }
    // anything else (K, A/B/C/D, ...) is ignored — the codebase doesn't use it
}

void ConsoleFeed(const char* ptr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        char c = ptr[i];
        switch (ansiState) {
            case AnsiState::Normal:
                if (c == '\x1b') ansiState = AnsiState::Esc;
                else GridPut(c);
                break;
            case AnsiState::Esc:
                if (c == '[') { ansiState = AnsiState::Csi; ansiLen = 0; }
                else ansiState = AnsiState::Normal;
                break;
            case AnsiState::Csi:
                if ((c >= '0' && c <= '9') || c == ';') {
                    if (ansiLen < (int)sizeof(ansiParams) - 1) ansiParams[ansiLen++] = c;
                } else {
                    AnsiFinish(c);
                    ansiState = AnsiState::Normal;
                }
                break;
        }
    }
}

// Repaint the screen from inside blocking logic code (throttled).
constexpr u64 TICKS_PER_MSEC = 268123;
u64 lastRedrawTick = 0;

void MaybeRedraw() {
    if (redrawFn == nullptr || inFrame) return;
    u64 now = svcGetSystemTick();
    if (lastRedrawTick != 0 && now - lastRedrawTick < 80 * TICKS_PER_MSEC) return;
    lastRedrawTick = now;
    FrameBegin();
    redrawFn();
    FrameEnd();
}

// stdout/stderr devoptab hook
ssize_t UiWrite(struct _reent* r, void* fd, const char* ptr, size_t len) {
    (void)r; (void)fd;
    ConsoleFeed(ptr, len);
    MaybeRedraw();
    return (ssize_t)len;
}

devoptab_t dotabUi;

void HookStdout() {
    memset(&dotabUi, 0, sizeof(dotabUi));
    dotabUi.name = "uiout";
    dotabUi.structSize = sizeof(void*);
    dotabUi.write_r = UiWrite;
    devoptab_list[STD_OUT] = &dotabUi;
    devoptab_list[STD_ERR] = &dotabUi;
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
}

// Parse a string into the shared frame text buffer.
bool ParseText(C2D_Text* out, const std::string& s) {
    if (s.empty()) return false;
    if (C2D_TextParse(out, textBuf, s.c_str()) == nullptr) return false;
    C2D_TextOptimize(out);
    return true;
}

}  // namespace

// ————————————————————————————————————————————————
// lifecycle
// ————————————————————————————————————————————————
bool Init() {
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    topTarget = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    botTarget = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
    textBuf = C2D_TextBufNew(4096);
    GridClear();
    HookStdout();
    return topTarget && botTarget && textBuf;
}

void Exit() {
    if (textBuf) { C2D_TextBufDelete(textBuf); textBuf = nullptr; }
    C2D_Fini();
    C3D_Fini();
    gfxExit();
}

void FrameBegin() {
    inFrame = true;
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TextBufClear(textBuf);
    C2D_TargetClear(topTarget, ColBgTop);
    C2D_TargetClear(botTarget, ColBgBottom);
}

void FrameEnd() {
    C3D_FrameEnd(0);
    inFrame = false;
}

void SceneTop()    { C2D_SceneBegin(topTarget); }
void SceneBottom() { C2D_SceneBegin(botTarget); }

void SetRedrawCallback(DrawFn fn) { redrawFn = fn; }

// ————————————————————————————————————————————————
// text
// ————————————————————————————————————————————————
float TextWidth(const std::string& s, float scale) {
    C2D_Text t;
    if (!ParseText(&t, s)) return 0.0f;
    float w = 0.0f, h = 0.0f;
    C2D_TextGetDimensions(&t, scale, scale, &w, &h);
    return w;
}

void Text(const std::string& s, float x, float y, float scale, u32 color) {
    C2D_Text t;
    if (!ParseText(&t, s)) return;
    C2D_DrawText(&t, C2D_WithColor, x, y, 0.0f, scale, scale, color);
}

void TextCentered(const std::string& s, float cx, float y, float scale, u32 color) {
    C2D_Text t;
    if (!ParseText(&t, s)) return;
    C2D_DrawText(&t, C2D_WithColor | C2D_AlignCenter, cx, y, 0.0f, scale, scale, color);
}

void TextRight(const std::string& s, float rightX, float y, float scale, u32 color) {
    C2D_Text t;
    if (!ParseText(&t, s)) return;
    C2D_DrawText(&t, C2D_WithColor | C2D_AlignRight, rightX, y, 0.0f, scale, scale, color);
}

void TextWrapped(const std::string& s, float x, float y, float scale, u32 color, float maxWidth) {
    C2D_Text t;
    if (!ParseText(&t, s)) return;
    C2D_DrawText(&t, C2D_WithColor | C2D_WordWrap, x, y, 0.0f, scale, scale, color, maxWidth);
}

std::string FitToWidth(const std::string& s, float scale, float maxWidth) {
    if (TextWidth(s, scale) <= maxWidth) return s;
    std::string out = s;
    while (out.length() > 1 && TextWidth(out + "…", scale) > maxWidth) {
        out.pop_back();
    }
    return out + "…";
}

// ————————————————————————————————————————————————
// shapes
// ————————————————————————————————————————————————
void Rect(float x, float y, float w, float h, u32 color) {
    C2D_DrawRectSolid(x, y, 0.0f, w, h, color);
}

void RectGradV(float x, float y, float w, float h, u32 top, u32 bottom) {
    C2D_DrawRectangle(x, y, 0.0f, w, h, top, top, bottom, bottom);
}

void Panel(float x, float y, float w, float h) {
    C2D_DrawRectSolid(x, y, 0.0f, w, h, ColPanel);
    C2D_DrawRectSolid(x, y, 0.0f, w, 1.0f, ColPanelEdge);
}

void ScrollBar(float x, float y, float h, size_t total, size_t visible, size_t first) {
    if (total <= visible) return;
    Rect(x, y, 3.0f, h, ColScrollTrack);
    float thumbH = std::max(10.0f, h * (float)visible / (float)total);
    float maxFirst = (float)(total - visible);
    float t = maxFirst > 0 ? (float)first / maxFirst : 0.0f;
    Rect(x, y + t * (h - thumbH), 3.0f, thumbH, ColScrollThumb);
}

// ————————————————————————————————————————————————
// captured console rendering
// ————————————————————————————————————————————————
void ConsoleGridClear() { GridClear(); }

void DrawConsolePanel(float x, float y, float w, float h) {
    Panel(x, y, w, h);

    constexpr float scale = 0.40f;
    constexpr float lineH = 12.5f;
    const int maxLines = (int)((h - 10.0f) / lineH);

    // collect non-empty rows, keep only the tail that fits
    std::vector<int> rows;
    for (int r = 0; r < ConRows; r++) {
        for (int c = 0; c < ConCols; c++) {
            if (conChar[r][c] != ' ') { rows.push_back(r); break; }
        }
    }
    int first = std::max(0, (int)rows.size() - maxLines);

    float ty = y + 6.0f;
    for (size_t i = first; i < rows.size(); i++) {
        const char* line = conChar[rows[i]];
        const u8* colors = conColor[rows[i]];
        int end = ConCols;
        while (end > 0 && line[end - 1] == ' ') end--;
        int start = 0;
        while (start < end && line[start] == ' ') start++;

        // draw runs of the same color
        float tx = x + 8.0f;
        int runStart = start;
        while (runStart < end) {
            int runEnd = runStart;
            while (runEnd < end && colors[runEnd] == colors[runStart]) runEnd++;
            std::string seg(line + runStart, line + runEnd);
            u32 col = (colors[runStart] == 8) ? ColBad : AnsiColor(colors[runStart]);
            Text(seg, tx, ty, scale, col);
            tx += TextWidth(seg, scale);
            runStart = runEnd;
        }
        ty += lineH;
    }
}

}  // namespace UI
