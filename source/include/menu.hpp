#pragma once

#include <3ds.h>
#include <string>

#define MAIN_MENU 0
#define OPTION_SUB_MENU 1
#define SUB_MENU 2
#define GENERATE_MODE 3
#define LOAD_PRESET 4
#define SAVE_PRESET 5
#define DELETE_PRESET 6
#define POST_GENERATE 7
#define RESET_TO_DEFAULTS 8
#define MAX_MAINMENU_SETTINGS_ON_SCREEN 20
#define MAX_SUBMENUS_ON_SCREEN 27
#define MAX_SUBMENU_SETTINGS_ON_SCREEN 13
#define TOP_WIDTH 50
#define BOTTOM_WIDTH 40
#define SCREEN_HEIGHT 30

// ANSI color strings are still emitted by the logic code (fill, spoiler log,
// ...) via printf; the UI layer captures stdout and renders them.
#define RESET   "\x1b[0m"
#define DIM     "\x1b[2m"

#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MEGANTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
// --- PROJECT RESTORATION STYLE PALETTE ---
#define COLOR_PR_TAB_BG        C2D_Color32(28, 32, 42, 255)    // Dark slate grey tab
#define COLOR_PR_TAB_ACTIVE    C2D_Color32(20, 80, 160, 255)   // Bright blue active tab
#define COLOR_PR_ROW_BG        C2D_Color32(18, 22, 30, 255)    // Dark row background
#define COLOR_PR_BORDER        C2D_Color32(90, 95, 110, 255)   // Slate border
#define COLOR_PR_YELLOW_GLOW   C2D_Color32(245, 220, 80, 255)  // Selected row yellow outline
#define COLOR_PR_TOGGLE_OFF    C2D_Color32(120, 120, 120, 255) // Grey toggle track
#define COLOR_PR_TOGGLE_ON     C2D_Color32(70, 210, 100, 255)  // Green toggle track
#define COLOR_PR_KNOB          C2D_Color32(220, 215, 200, 255) // Toggle knob off-white
#define COLOR_PR_DESC_BG       C2D_Color32(35, 12, 55, 240)    // Purple bottom description box
void ModeChangeInit();
void UpdateOptionSubMenu(u32 kDown);
void UpdatePresetsMenu(u32 kdown);
void UpdateResetToDefaultsMenu(u32 kdown);
void UpdateGenerateMenu(u32 kDown);
void ClearDescription();
void GenerateRandomizer();
std::string GetInput(const char* hintText);

extern void MenuInit();
extern void MenuUpdate(u32 kDown);

// citro2d rendering + touch input (see menu.cpp / ui.cpp)
void MenuDraw();
u32 MenuHandleTouch();
