#pragma once

#include <3ds.h>
#include <citro2d.h>

#include <string>

// citro2d UI layer for the randomizer menu.
//
// Owns the gfx/citro3d/citro2d lifecycle, the two screen targets, text
// rendering through the system font, and a virtual console that captures
// everything the logic code writes to stdout (fill.cpp, playthrough.cpp,
// spoiler_log.cpp all report progress with ANSI-positioned printf; none of
// that code changes). While a blocking task prints, the capture hook can
// re-render the whole frame through a registered callback so the user sees
// live progress.
namespace UI {

// ——— palette ———
extern const u32 ColBgTop;        // top screen background (gradient top)
extern const u32 ColBgTopBot;     // top screen background (gradient bottom)
extern const u32 ColBgBottom;     // bottom screen background
extern const u32 ColHeader;       // header bar
extern const u32 ColHeaderEdge;   // header underline accent
extern const u32 ColPanel;        // panel background
extern const u32 ColPanelEdge;    // panel top accent line
extern const u32 ColSelBar;       // selection row highlight
extern const u32 ColSelNotch;     // selection left notch (gold)
extern const u32 ColAccent;       // gold accent / titles
extern const u32 ColText;         // primary text
extern const u32 ColTextDim;      // secondary text
extern const u32 ColTextLocked;   // locked settings
extern const u32 ColValue;        // option values (teal)
extern const u32 ColGood;         // success messages
extern const u32 ColBad;          // error messages
extern const u32 ColScrollTrack;
extern const u32 ColScrollThumb;

constexpr float TopW = 400.0f, TopH = 240.0f;
constexpr float BotW = 320.0f, BotH = 240.0f;

bool Init();
void Exit();

void FrameBegin();
void FrameEnd();
void SceneTop();
void SceneBottom();

// Full-frame redraw callback used by the stdout hook to repaint the screen
// while blocking logic code prints progress. Called between FrameBegin and
// FrameEnd internally; the callback just issues scene/draw calls.
typedef void (*DrawFn)();
void SetRedrawCallback(DrawFn fn);

// ——— text (system font) ———
float TextWidth(const std::string& s, float scale);
void  Text(const std::string& s, float x, float y, float scale, u32 color);
void  TextCentered(const std::string& s, float cx, float y, float scale, u32 color);
void  TextRight(const std::string& s, float rightX, float y, float scale, u32 color);
void  TextWrapped(const std::string& s, float x, float y, float scale, u32 color, float maxWidth);
// Truncates with an ellipsis so the rendered string fits maxWidth.
std::string FitToWidth(const std::string& s, float scale, float maxWidth);

// ——— shapes ———
void Rect(float x, float y, float w, float h, u32 color);
void RectGradV(float x, float y, float w, float h, u32 top, u32 bottom);
void Panel(float x, float y, float w, float h);
void ScrollBar(float x, float y, float h, size_t total, size_t visible, size_t first);

// ——— captured stdout (virtual console) ———
void ConsoleGridClear();
// Renders the tail of the captured console output inside the given box.
void DrawConsolePanel(float x, float y, float w, float h);

}  // namespace UI
