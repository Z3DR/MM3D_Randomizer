#include <dirent.h>

#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <vector>

#include "cosmetics.hpp"
#include "menu.hpp"
#include "patch.hpp"
#include "preset.hpp"
#include "version.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
#include "location_access.hpp"
#include "debug.hpp"
#include "ui.hpp"

using namespace Settings;

namespace {
  u16 settingBound = 0;
  std::vector<std::string> presetEntries;
  std::vector<Menu*> menuList;
  Option* currentSetting;
  Menu* currentMenu;

  // transient status message shown in the top-screen info panel
  std::string toastMsg;
  u32 toastColor;
  // result of the last save-preset action, shown while in SAVE_PRESET mode
  std::string savePresetMsg;
  bool savePresetOk;
  // scroll offset for plain item/preset lists
  u16 listScroll = 0;

  // ——— bottom screen layout ———
  constexpr float HDR_H    = 26.0f;
  constexpr float LIST_TOP = 30.0f;
  constexpr float ROW_H    = 14.5f;
  constexpr float FOOT_TOP = 221.0f;
  constexpr int   LIST_VISIBLE = MAX_SUBMENU_SETTINGS_ON_SCREEN;
  constexpr float TXT = 0.44f;

  void SetToast(const std::string& msg, u32 color) {
    toastMsg = msg;
    toastColor = color;
  }
}

void ClearDescription() {
  toastMsg.clear();
}

void MenuInit() {
  Settings::InitSettings();

  Menu* main = new Menu("Main", MenuType::MainMenu, &Settings::mainMenu, MAIN_MENU);
  menuList.push_back(main);
  currentMenu = main;

  srand(time(NULL));

  // Create directories
  FS_Archive sdmcArchive;
  if (R_SUCCEEDED(FSUSER_OpenArchive(&sdmcArchive, ARCHIVE_SDMC, fsMakePath(PATH_EMPTY, "")))) {
    InitLogDirectories(sdmcArchive);
    CreatePresetDirectories(sdmcArchive);

    FSUSER_CloseArchive(sdmcArchive);
  } else {
    while (aptMainLoop()) {
      hidScanInput();
      if (hidKeysHeld() & KEY_B) {
        break;
      }
      UI::FrameBegin();
      UI::SceneTop();
      UI::RectGradV(0, 0, UI::TopW, UI::TopH, UI::ColBgTop, UI::ColBgTopBot);
      UI::Panel(30, 70, 340, 100);
      UI::TextCentered("Failed to create directories.", 200, 82, 0.55f, UI::ColBad);
      UI::TextCentered("Spoiler logs won't be written.", 200, 108, 0.45f, UI::ColText);
      UI::TextCentered("Loading presets might crash.", 200, 124, 0.45f, UI::ColText);
      UI::TextCentered(u8"Press  to continue.", 200, 146, 0.45f, UI::ColTextDim);
      UI::SceneBottom();
      UI::FrameEnd();
    }
  }

  //If cached presets exist, load them
  LoadCachedSettings();
  LoadCachedCosmetics();
  //If Randomize all settings in a category is selected
  //Re-randomize them
  Settings::RandomizeAllSettings();

  // repaint the whole frame whenever blocking logic code prints progress
  UI::SetRedrawCallback(MenuDraw);
}

void MoveCursor(u32 kDown) {
  //Option sub menus need special checking for locked options
  if (currentMenu->mode == OPTION_SUB_MENU) {
    //Loop through settings until an unlocked one is reached
    do {
      if ((kDown & KEY_DUP) != 0) {
        currentMenu->menuIdx--;
      }
      if ((kDown & KEY_DDOWN) != 0)  {
        currentMenu->menuIdx++;
      }

      //Bounds checking
      if (currentMenu->menuIdx == currentMenu->settingsList->size()) {
        currentMenu->menuIdx = 0;
      } else if (currentMenu->menuIdx == 0xFFFF) {
        currentMenu->menuIdx = static_cast<u16>(currentMenu->settingsList->size() - 1);
      }

      currentSetting = currentMenu->settingsList->at(currentMenu->menuIdx);
    } while (currentSetting->IsLocked() || currentSetting->IsHidden());
  }
  //All other menus except reset-to-defaults confirmation
  else if (currentMenu->mode != RESET_TO_DEFAULTS) {
    if (kDown & KEY_DUP) {
      currentMenu->menuIdx--;
    }
    if (kDown & KEY_DDOWN) {
      currentMenu->menuIdx++;
    }

    //Bounds checking
    u16 max = -1;
    if (currentMenu->mode == LOAD_PRESET || currentMenu->mode == DELETE_PRESET) { //Number of presets if applicable
      max = presetEntries.size();
    } else if (currentMenu->mode == GENERATE_MODE) { //Generate menu: 2 options
      max = 2;
    } else if (currentMenu->itemsList != nullptr) {
      max = currentMenu->itemsList->size(); //Default max: Number of items in menu
    }
    if (currentMenu->menuIdx == max) {
      currentMenu->menuIdx = 0;
    } else if (currentMenu->menuIdx == 0xFFFF) {
      currentMenu->menuIdx = max - 1;
    }
  }
}

void MenuUpdate(u32 kDown) {
  toastMsg.clear();

  //Check for menu change
  //If user pressed A on a non-option, non-action menu, they're navigating to a new menu
  if (kDown & KEY_A && currentMenu->mode != OPTION_SUB_MENU && currentMenu->type != MenuType::Action) {
    if (currentMenu->itemsList->size() > currentMenu->menuIdx) {
      Menu* newMenu;
      newMenu = currentMenu->itemsList->at(currentMenu->menuIdx);
      menuList.push_back(newMenu);
      currentMenu = menuList.back();
      ModeChangeInit();
      kDown = 0;
    }
  }
  //if they're pressing B in the inputs menu check if any options are the same
    if (kDown & KEY_B && currentMenu->name == customInputs.name){
     if (!CheckCustomButtons())
     {
       SetToast("You cannot have duplicate button combinations!", UI::ColBad);
      //  CitraPrint("Checking Custom Button in Menus");
     }
     else
     {
      menuList.pop_back();
      currentMenu = menuList.back();
      ModeChangeInit();
      kDown = 0;
     }
    }
  //If they pressed B on any menu other than main, go backwards to the previous menu
  else if (kDown & KEY_B && currentMenu->mode != MAIN_MENU) {

    //Want to reset generate menu when leaving
    if (currentMenu->mode == POST_GENERATE) {
      currentMenu->mode = GENERATE_MODE;
    }
    menuList.pop_back();
    currentMenu = menuList.back();
    ModeChangeInit();
    kDown = 0;
  }

  if (currentMenu->mode != GENERATE_MODE) {

    //New Random Seed
    if (kDown & KEY_Y) {
      Settings::seed = std::to_string(rand());
    }

    //Input Custom Seed

    if (kDown & KEY_X) {
      Settings::seed = GetInput("Enter Seed");
    }
  }

  //Update current menu (if applicable)
  MoveCursor(kDown); //Move cursor, if applicable
  if (currentMenu->mode == MAIN_MENU) {
    ClearDescription();
  } else if (currentMenu->mode == OPTION_SUB_MENU) {
    UpdateOptionSubMenu(kDown);
  } else if (currentMenu->mode == LOAD_PRESET) {
    UpdatePresetsMenu(kDown);
  } else if (currentMenu->mode == DELETE_PRESET) {
    UpdatePresetsMenu(kDown);
  } else if (currentMenu->mode == RESET_TO_DEFAULTS) {
    UpdateResetToDefaultsMenu(kDown);
  } else if (currentMenu->mode == GENERATE_MODE) {
    UpdateGenerateMenu(kDown);
  }
}

void ModeChangeInit() {
  if (currentMenu->mode == OPTION_SUB_MENU) {
    //loop through until we reach an unlocked setting
    while(currentMenu->settingsList->at(currentMenu->menuIdx)->IsLocked() || currentMenu->settingsList->at(currentMenu->menuIdx)->IsHidden()) {
      currentMenu->menuIdx++;
    }
    currentSetting = currentMenu->settingsList->at(currentMenu->menuIdx);

  } else if (currentMenu->mode == SAVE_PRESET) {
    ClearDescription();
   if (SaveSpecifiedPreset(GetInput("Preset Name").substr(0, 19), OptionCategory::Setting)) {
      savePresetMsg = "Preset saved!";
      savePresetOk = true;
    } else {
      savePresetMsg = "Failed to save preset.";
      savePresetOk = false;
    }

  } else if (currentMenu->mode == LOAD_PRESET || currentMenu->mode == DELETE_PRESET) {
    presetEntries = GetSettingsPresets();

  } else if (currentMenu->mode == GENERATE_MODE) {

  }

}

void UpdateCustomCosmeticColors(u32 kDown) {
  if (kDown & KEY_A) {
    if (currentSetting->GetSelectedOptionText().compare(0, 8, Cosmetics::CUSTOM_COLOR_PREFIX) == 0) {
      std::string newColor = GetInput("Enter a 6 digit hex color").substr(0, 6);
      if (Cosmetics::ValidHexString(newColor)) {
        currentSetting->SetSelectedOptionText(Cosmetics::CustomColorOptionText(newColor));
      }
    }
  }
}

void UpdateOptionSubMenu(u32 kDown) {
  if ((kDown & KEY_DRIGHT) != 0) {
    currentSetting->NextOptionIndex();
  }
  if ((kDown & KEY_DLEFT) != 0) {
    currentSetting->PrevOptionIndex();
  }

  // Bounds checking
  currentSetting->SanitizeSelectedOptionIndex();

  currentSetting->SetVariable();
  Settings::ForceChange(kDown, currentSetting);
  UpdateCustomCosmeticColors(kDown);
}

void UpdatePresetsMenu(u32 kDown) {
  //clear any potential message
  ClearDescription();
  if (kDown & KEY_A && currentMenu->mode == LOAD_PRESET && !presetEntries.empty()) {
    if (LoadPreset(presetEntries[currentMenu->menuIdx], OptionCategory::Setting)) {
      SetToast("Preset loaded!", UI::ColGood);
    } else {
      SetToast("Failed to load preset.", UI::ColBad);
    }
  } else if (kDown & KEY_A && currentMenu->mode == DELETE_PRESET && !presetEntries.empty()) {
    if (DeletePreset(presetEntries[currentMenu->menuIdx], OptionCategory::Setting)) {
      presetEntries.erase(presetEntries.begin() + currentMenu->menuIdx);
      if(currentMenu->menuIdx == presetEntries.size()) { //Catch when last preset is deleted
        currentMenu->menuIdx--;
      }
      SetToast("Preset deleted.", UI::ColGood);
    } else {
      SetToast("Failed to delete preset.", UI::ColBad);
    }
  }
}

void UpdateResetToDefaultsMenu(u32 kDown) {
  //clear any potential message
  ClearDescription();
  if (kDown & KEY_A) {
    Settings::SetDefaultSettings();
    SetToast("Settings have been reset to defaults.", UI::ColGood);
  }
}

void UpdateGenerateMenu(u32 kDown) {
        GenerateRandomizer();
        //This is just a dummy mode to stop the prompt from appearing again
        currentMenu->mode = POST_GENERATE;
        }

void GenerateRandomizer() {

    UI::ConsoleGridClear();
    printf("\x1b[6;10HCaching Settings...");

    //After choosing to generate, cache chosen settings for later
    SaveCachedSettings();
    SaveCachedCosmetics();
    printf("Done");

    //if a blank seed was entered, make a random one
    if (Settings::seed.empty()) {
        Settings::seed = std::to_string(rand());
    }
    else if (Settings::seed.rfind("seed_testing_count", 0) == 0) {
        const int count = std::stoi(Settings::seed.substr(18), nullptr);
        Playthrough::Playthrough_Repeat(count);
        return;
    }

    int ret = Playthrough::Playthrough_Init(std::hash<std::string>{}(Settings::seed));
    if (ret < 0) {
      if(ret == -1) { //Failed to generate after 5 tries
        printf("\n\nFailed to generate after 5 tries.\nPress Select to exit or B to go back to the menu.\n");
        return;
      }
      else {
        printf("\n\nError %d with fill.\nPress Select to exit or B to go back to the menu.\n", ret);
        return;
      }
    }
    printf("\x1b[13;10HWriting Patch...");
    if (WriteAllPatches()) {
        printf("Done");
        if (Settings::PlayOption.Value<u8>() == PATCH_CONSOLE) {
            printf("\x1b[15;10HQuit out using the home menu. Then\n");
            printf("\x1b[16;10Henable game patching and launch MM3D!\n");
        }
        else if (Settings::PlayOption.Value<u8>() == PATCH_CITRA) {
            printf("\x1b[15;10HCopy code.ips, exheader.bin and romfs to\n");
            printf("\x1b[16;10Hthe MM3D mods folder, then launch MM3D!\n");
        }


        const auto& randomizerHash = GetRandomizerHash();
        printf("\x1b[18;10HHash:");
        for (size_t i = 0; i < randomizerHash.size(); i++) {
            printf("\x1b[%zu;11H- %s", i + 19, randomizerHash[i].c_str());
        }
    }
    else {
    printf("Failed\nPress Select to exit.\n");
    }
}

//opens up the 3ds software keyboard for getting user input
std::string GetInput(const char* hintText) {
  SwkbdState swkbd;
  char text[60];
  SwkbdButton button = SWKBD_BUTTON_NONE;

  swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 2, -1);
  swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
  swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
  swkbdSetHintText(&swkbd, hintText);
  swkbdSetButton(&swkbd, SWKBD_BUTTON_LEFT, "Cancel", false);

  button = swkbdInputText(&swkbd, text, sizeof(text));

  if (button == SWKBD_BUTTON_LEFT) {
    return "";
  }

  return std::string(text);
}

// ————————————————————————————————————————————————————————————————
// Rendering (citro2d) — pure functions of the menu state above.
// ————————————————————————————————————————————————————————————————
namespace {

bool InGenerateView() {
  return currentMenu->mode == GENERATE_MODE || currentMenu->mode == POST_GENERATE;
}

// Scroll window for plain item/preset lists; keeps the selection visible.
u16 UpdateListScroll(size_t count) {
  if (currentMenu->menuIdx < listScroll) {
    listScroll = currentMenu->menuIdx;
  }
  if (currentMenu->menuIdx >= (u16)(listScroll + LIST_VISIBLE)) {
    listScroll = currentMenu->menuIdx - LIST_VISIBLE + 1;
  }
  u16 maxScroll = count > (size_t)LIST_VISIBLE ? (u16)(count - LIST_VISIBLE) : 0;
  if (listScroll > maxScroll) listScroll = maxScroll;
  return listScroll;
}

// Original PrintOptionSubMenu window logic, kept verbatim: accounts for
// hidden settings so the visible window always holds 13 selectable rows.
void UpdateOptionBounds() {
  u16 hiddenSettings = 0;
  u16 visibleSettings = 0;
  for (u16 i = settingBound; visibleSettings < MAX_SUBMENU_SETTINGS_ON_SCREEN; i++) {
    if (i >= currentMenu->settingsList->size()) {
      break;
    }
    if (currentMenu->settingsList->at(i)->IsHidden()) {
      hiddenSettings++;
    } else {
      visibleSettings++;
    }
  }
  if (currentMenu->menuIdx >= settingBound + MAX_SUBMENU_SETTINGS_ON_SCREEN + hiddenSettings) {
    settingBound = currentMenu->menuIdx;
    u8 offset = 0;
    //skip over hidden settings
    while (offset < MAX_SUBMENU_SETTINGS_ON_SCREEN - 1) {
      settingBound--;
      if (settingBound == 0) {
        break;
      }
      offset += currentMenu->settingsList->at(settingBound)->IsHidden() ? 0 : 1;
    }
  } else if (currentMenu->menuIdx < settingBound)  {
    settingBound = currentMenu->menuIdx;
  }
}

// Indices of the settings currently on screen, top row first.
std::vector<u16> VisibleOptionRows() {
  UpdateOptionBounds();
  std::vector<u16> rows;
  u16 hiddenSettings = 0;
  for (u16 i = 0; i - hiddenSettings < MAX_SUBMENU_SETTINGS_ON_SCREEN; i++) {
    if (i + settingBound >= currentMenu->settingsList->size()) break;
    Option* setting = currentMenu->settingsList->at(i + settingBound);
    if (setting->IsHidden()) {
      hiddenSettings++;
      continue;
    }
    rows.push_back(i + settingBound);
  }
  return rows;
}

void DrawBottomHeader(const std::string& title) {
  UI::Rect(0, 0, UI::BotW, HDR_H, UI::ColHeader);
  UI::Rect(0, HDR_H - 1.5f, UI::BotW, 1.5f, UI::ColHeaderEdge);
  UI::TextCentered(UI::FitToWidth(title, 0.52f, 300.0f), UI::BotW / 2, 4.0f, 0.52f, UI::ColText);
}

void DrawBottomFooter(const std::string& hints, bool backButton) {
  UI::Rect(0, FOOT_TOP, UI::BotW, UI::BotH - FOOT_TOP, UI::ColHeader);
  if (backButton) {
    UI::Text(u8" Back", 8, FOOT_TOP + 2.0f, 0.40f, UI::ColTextDim);
    UI::TextRight(hints, UI::BotW - 8, FOOT_TOP + 2.0f, 0.40f, UI::ColTextDim);
  } else {
    UI::TextCentered(hints, UI::BotW / 2, FOOT_TOP + 2.0f, 0.40f, UI::ColTextDim);
  }
}

void DrawRowHighlight(int row) {
  float y = LIST_TOP + row * ROW_H;
  UI::Rect(0, y, UI::BotW, ROW_H, UI::ColSelBar);
  UI::Rect(0, y, 3.0f, ROW_H, UI::ColSelNotch);
}

// A plain list of names (main menu, sub menus, presets).
void DrawItemList(const std::vector<std::string>& names, u16 selected, bool accentLast) {
  u16 scroll = UpdateListScroll(names.size());
  for (int row = 0; row < LIST_VISIBLE; row++) {
    size_t idx = scroll + row;
    if (idx >= names.size()) break;
    float y = LIST_TOP + row * ROW_H;
    bool isSel = (idx == selected);
    if (isSel) DrawRowHighlight(row);
    u32 col = UI::ColText;
    if (accentLast && idx == names.size() - 1) col = UI::ColAccent;
    UI::Text(UI::FitToWidth(names[idx], TXT, 290.0f), 10, y + 1.0f, TXT, col);
    if (isSel) UI::TextRight(u8"", UI::BotW - 10, y + 1.0f, TXT, UI::ColTextDim);
  }
  UI::ScrollBar(UI::BotW - 4, LIST_TOP, LIST_VISIBLE * ROW_H, names.size(), LIST_VISIBLE, scroll);
}

void DrawOptionList() {
  std::vector<u16> rows = VisibleOptionRows();
  for (size_t row = 0; row < rows.size(); row++) {
    Option* setting = currentMenu->settingsList->at(rows[row]);
    float y = LIST_TOP + row * ROW_H;
    bool isSel = (rows[row] == currentMenu->menuIdx);
    bool locked = setting->IsLocked();

    if (isSel) DrawRowHighlight((int)row);

    u32 nameCol = locked ? UI::ColTextLocked : UI::ColText;
    u32 valCol  = locked ? UI::ColTextLocked : (isSel ? UI::ColValue : UI::ColTextDim);
    UI::Text(UI::FitToWidth(setting->GetName(), TXT, 170.0f), 10, y + 1.0f, TXT, nameCol);

    std::string value = UI::FitToWidth(setting->GetSelectedOptionText(), TXT, 112.0f);
    if (isSel && !locked) {
      UI::TextRight("<", 186, y + 1.0f, TXT, UI::ColAccent);
      UI::Text(">", UI::BotW - 14, y + 1.0f, TXT, UI::ColAccent);
      UI::TextCentered(value, (192 + UI::BotW - 18) / 2, y + 1.0f, TXT, valCol);
    } else {
      UI::TextRight(value, UI::BotW - 14, y + 1.0f, TXT, valCol);
    }
  }

  // scrollbar over the non-hidden settings
  size_t total = 0, first = 0;
  for (size_t i = 0; i < currentMenu->settingsList->size(); i++) {
    if (!currentMenu->settingsList->at(i)->IsHidden()) {
      if (i < settingBound) first++;
      total++;
    }
  }
  UI::ScrollBar(UI::BotW - 4, LIST_TOP, LIST_VISIBLE * ROW_H, total, LIST_VISIBLE, first);
}

void DrawMessageCard(const std::string& line1, u32 col1, const std::string& line2) {
  UI::Panel(20, 84, UI::BotW - 40, 72);
  UI::TextCentered(line1, UI::BotW / 2, 98, 0.50f, col1);
  UI::TextCentered(line2, UI::BotW / 2, 124, 0.42f, UI::ColTextDim);
}

void DrawBottomScreen() {
  switch (currentMenu->mode) {
    case MAIN_MENU: {
      DrawBottomHeader("Main Settings");
      std::vector<std::string> names;
      for (Menu* m : *currentMenu->itemsList) names.push_back(m->name);
      DrawItemList(names, currentMenu->menuIdx, /*accentLast=*/true);
      DrawBottomFooter(u8" Open    New Seed    Enter Seed", false);
      break;
    }
    case SUB_MENU: {
      DrawBottomHeader(currentMenu->name);
      std::vector<std::string> names;
      for (Menu* m : *currentMenu->itemsList) names.push_back(m->name);
      DrawItemList(names, currentMenu->menuIdx, false);
      DrawBottomFooter(u8" Open", true);
      break;
    }
    case OPTION_SUB_MENU: {
      DrawBottomHeader(currentMenu->name);
      DrawOptionList();
      DrawBottomFooter(u8" Change", true);
      break;
    }
    case LOAD_PRESET:
    case DELETE_PRESET: {
      bool loading = currentMenu->mode == LOAD_PRESET;
      DrawBottomHeader(loading ? "Load Preset" : "Delete Preset");
      if (presetEntries.empty()) {
        DrawMessageCard("No presets detected!", UI::ColTextDim, u8" Return to the preset menu");
      } else {
        DrawItemList(presetEntries, currentMenu->menuIdx, false);
      }
      DrawBottomFooter(loading ? u8" Load" : u8" Delete", true);
      break;
    }
    case SAVE_PRESET: {
      DrawBottomHeader("Save Preset");
      DrawMessageCard(savePresetMsg, savePresetOk ? UI::ColGood : UI::ColBad,
                      u8" Return to the preset menu");
      DrawBottomFooter("", true);
      break;
    }
    case RESET_TO_DEFAULTS: {
      DrawBottomHeader("Reset to Defaults");
      DrawMessageCard(u8" Reset all settings to defaults", UI::ColText,
                      u8" Return to the preset menu");
      DrawBottomFooter(u8" Reset", true);
      break;
    }
    case GENERATE_MODE:
    case POST_GENERATE: {
      DrawBottomHeader("Generate Randomizer");
      DrawMessageCard("Output is shown on the top screen.", UI::ColText,
                      u8" Back    SELECT Quit");
      DrawBottomFooter("Hold L+R to launch MM3D (cartridge)", true);
      break;
    }
  }
}

void DrawTopScreen() {
  UI::RectGradV(0, 0, UI::TopW, UI::TopH, UI::ColBgTop, UI::ColBgTopBot);

  // header
  UI::Rect(0, 0, UI::TopW, 34, UI::ColHeader);
  UI::Rect(0, 32.5f, UI::TopW, 1.5f, UI::ColHeaderEdge);
  UI::TextCentered("Majora's Mask 3D Randomizer", UI::TopW / 2, 5.0f, 0.60f, UI::ColAccent);
  UI::TextRight(RANDOMIZER_VERSION, UI::TopW - 6, 20.0f, 0.32f, UI::ColTextDim);

  if (InGenerateView()) {
    UI::DrawConsolePanel(8, 42, UI::TopW - 16, 190);
    return;
  }

  // seed card
  UI::Panel(8, 42, UI::TopW - 16, 28);
  UI::Text("Seed", 18, 48, 0.45f, UI::ColTextDim);
  if (Settings::seed.empty()) {
    UI::Text("(random at generation)", 62, 48, 0.45f, UI::ColTextDim);
  } else {
    UI::Text(UI::FitToWidth(Settings::seed, 0.45f, 220.0f), 62, 48, 0.45f, UI::ColAccent);
  }
  UI::TextRight(u8" random    enter", UI::TopW - 16, 49, 0.38f, UI::ColTextDim);

  // info / description panel
  UI::Panel(8, 78, UI::TopW - 16, 138);
  if (!toastMsg.empty()) {
    UI::TextCentered(toastMsg, UI::TopW / 2, 86, 0.50f, toastColor);
  } else if (currentMenu->mode == OPTION_SUB_MENU && currentSetting != nullptr) {
    UI::Text(UI::FitToWidth(currentSetting->GetName(), 0.50f, 360.0f), 18, 84, 0.50f, UI::ColText);
    UI::Rect(18, 101, 60, 1.0f, UI::ColPanelEdge);
    UI::TextWrapped(std::string(currentSetting->GetSelectedOptionDescription()),
                    18, 108, 0.44f, UI::ColTextDim, UI::TopW - 36);
  } else {
    UI::TextCentered("Pick a category and tune the settings,", UI::TopW / 2, 120, 0.45f, UI::ColTextDim);
    UI::TextCentered("then select Generate Randomizer.", UI::TopW / 2, 136, 0.45f, UI::ColTextDim);
  }

  // legend
  UI::TextCentered(u8" Navigate    Select    Back   SELECT Exit",
                   UI::TopW / 2, 224, 0.38f, UI::ColTextDim);
}

}  // namespace

void MenuDraw() {
  UI::SceneTop();
  DrawTopScreen();
  UI::SceneBottom();
  DrawBottomScreen();
}

// ————————————————————————————————————————————————————————————————
// Touch input: taps synthesize the same button events the D-pad logic
// already handles, so menu behavior stays identical.
// ————————————————————————————————————————————————————————————————
u32 MenuHandleTouch() {
  if (!(hidKeysDown() & KEY_TOUCH)) return 0;
  touchPosition t;
  hidTouchRead(&t);

  // footer back button (everywhere but the main menu)
  if (t.py >= FOOT_TOP && t.px < 70 && currentMenu->mode != MAIN_MENU) {
    return KEY_B;
  }

  // list area
  if (t.py >= LIST_TOP && t.py < LIST_TOP + LIST_VISIBLE * ROW_H) {
    int row = (int)((t.py - LIST_TOP) / ROW_H);

    switch (currentMenu->mode) {
      case OPTION_SUB_MENU: {
        std::vector<u16> rows = VisibleOptionRows();
        if (row >= (int)rows.size()) return 0;
        u16 idx = rows[row];
        Option* setting = currentMenu->settingsList->at(idx);
        if (setting->IsLocked()) return 0;
        if (idx == currentMenu->menuIdx) {
          // tap the selected row again: left half = previous, right half = next
          return (t.px >= UI::BotW / 2) ? KEY_DRIGHT : KEY_DLEFT;
        }
        currentMenu->menuIdx = idx;
        currentSetting = setting;
        return 0;
      }
      case MAIN_MENU:
      case SUB_MENU: {
        size_t idx = listScroll + row;
        if (currentMenu->itemsList == nullptr || idx >= currentMenu->itemsList->size()) return 0;
        if ((u16)idx == currentMenu->menuIdx) return KEY_A;
        currentMenu->menuIdx = (u16)idx;
        return 0;
      }
      case LOAD_PRESET:
      case DELETE_PRESET: {
        size_t idx = listScroll + row;
        if (idx >= presetEntries.size()) return 0;
        if ((u16)idx == currentMenu->menuIdx) return KEY_A;
        currentMenu->menuIdx = (u16)idx;
        return 0;
      }
      case RESET_TO_DEFAULTS:
        return KEY_A;
      default:
        return 0;
    }
  }

  return 0;
}
