#include "preset.hpp"

#include <3ds.h>
#include <unistd.h>

#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>

#include "category.hpp"
#include "settings.hpp"
#include "tinyxml2.h"
#include "utils.hpp"

namespace fs = std::filesystem;

static const std::string CACHED_SETTINGS_FILENAME = "CACHED_SETTINGS";
static const std::string CACHED_COSMETICS_FILENAME = "CACHED_COSMETICS";

static std::string_view GetBasePath(OptionCategory category) {
  static constexpr std::array<std::string_view, 2> paths{
    "/MM3DR/Presets/Settings/",
    "/MM3DR/Presets/Cosmetics/",
  };

  switch(category) {
    case OptionCategory::Setting :
    case OptionCategory::Cosmetic :
      return paths[static_cast<size_t>(category)];
    case OptionCategory::Toggle :
      break;
  }
  return "";
}

//Creates preset directories if they don't exist
void CreatePresetDirectories(FS_Archive sdmcArchive) {
  std::vector<std::string> dirs = {
    "/MM3DR/",
    "/MM3DR/Presets/",
    "/MM3DR/Presets/Settings/",
    "/MM3DR/Presets/Cosmetics/",
  };

  const auto printInfo = [&](int progress) {
    consoleClear();
    printf("\x1b[10;10HCreating Preset Directories");
    printf("\x1b[11;10HProgress: %d/%d", progress, dirs.size());
  };

  printInfo(0);
  for (size_t i = 0; i < dirs.size(); i++) {
    FSUSER_CreateDirectory(sdmcArchive, fsMakePath(PATH_ASCII, dirs[i].c_str()), FS_ATTRIBUTE_DIRECTORY);
    printInfo(i + 1);
  }

  // Migrate presets to new directories

  std::vector<std::pair<std::string, std::string>> dirPairs = {
      { "/3ds/presets/mm3dr/settings/",  "/MM3DR/Presets/Settings/"  },
      { "/3ds/presets/mm3dr/cosmetics/", "/MM3DR/Presets/Cosmetics/" },
  };

  for (auto dirPair : dirPairs) {
    if (R_FAILED(FSUSER_OpenDirectory(nullptr, sdmcArchive, fsMakePath(PATH_ASCII, dirPair.first.c_str())))) {
      continue;
    }
    for (const auto& entry : fs::directory_iterator(dirPair.first)) {
      if (entry.is_regular_file() && entry.path().extension().string() == ".xml") {
        auto filename = entry.path().filename().string();
        consoleClear();
        printf("\x1b[10;10HMigrating Presets");
        printf("\x1b[11;10HMoving %s", filename.c_str());
        FSUSER_RenameFile(sdmcArchive, fsMakePath(PATH_ASCII, std::string(dirPair.first + filename).c_str()),
                          sdmcArchive, fsMakePath(PATH_ASCII, std::string(dirPair.second + filename).c_str()));
      }
    }
  }
}

//Gets the preset filenames
std::vector<std::string> GetSettingsPresets() {
  std::vector<std::string> presetEntries = {};
  for (const auto& entry : fs::directory_iterator(GetBasePath(OptionCategory::Setting))) {
    if(entry.path().stem().string() != CACHED_SETTINGS_FILENAME) {
      presetEntries.push_back(entry.path().stem().string());
    }
  }
  return presetEntries;
}

static std::string PresetPath(std::string_view presetName, OptionCategory category) {
  return std::string(GetBasePath(category)).append(presetName).append(".xml");
}

// Presets are now saved as XML files using the tinyxml2 library.
// Documentation: https://leethomason.github.io/tinyxml2/index.html
bool SavePreset(std::string_view presetName, OptionCategory category) {
  using namespace tinyxml2;

  XMLDocument preset = XMLDocument(false);

  // Create and insert the XML declaration
  preset.InsertEndChild(preset.NewDeclaration());

  // Create the root node
  XMLElement* rootNode = preset.NewElement("settings");
  preset.InsertEndChild(rootNode);
  
  for (Menu* menu : Settings::GetAllMenus()) {
    if (menu->mode != OPTION_SUB_MENU) {
      continue;
    }
    for (const Option* setting : *menu->settingsList) {
      if (!setting->IsCategory(category)) {
        continue;
      }

      XMLElement* newSetting = rootNode->InsertNewChildElement("setting");
      newSetting->SetAttribute("name", RemoveLineBreaks(setting->GetName()).c_str());
      newSetting->SetText(setting->GetSelectedOptionText().c_str());
    }
  }

  XMLError e = preset.SaveFile(PresetPath(presetName, category).c_str());
  return e == XML_SUCCESS;
}

//Read the preset XML file
bool LoadPreset(std::string_view presetName, OptionCategory category) {
  using namespace tinyxml2;

  XMLDocument preset;
  XMLError e = preset.LoadFile(PresetPath(presetName, category).c_str());
  if (e != XML_SUCCESS) {
    return false;
  }

  XMLElement* rootNode = preset.RootElement();
  if (strcmp(rootNode->Name(), "settings") != 0) {
      // We do not have our <settings> root node, so it may be the old structure. We don't support that one anymore.
      return false;
  }

  XMLElement* curNode = rootNode->FirstChildElement();
  
  for (Menu* menu : Settings::GetAllMenus()) {
    if (menu->mode != OPTION_SUB_MENU) {
      continue;
    }

    for (Option* setting : *menu->settingsList) {
      if (!setting->IsCategory(category)) {
        continue;
      } else if (!curNode->GetText()) {
        curNode->SetText("");
      }
      // Since presets are saved linearly, we can simply loop through the nodes as
      // we loop through the settings to find most of the matching elements.
      const std::string& settingToFind = RemoveLineBreaks(setting->GetName());
      if (settingToFind == RemoveLineBreaks(curNode->Attribute("name"))) {
        setting->SetSelectedIndexByString(curNode->GetText());
        curNode = curNode->NextSiblingElement();
      } else {
        // If the current setting and element don't match, then search
        // linearly from the beginning. This will get us back on track if the
        // next setting and element line up with each other.
        curNode = rootNode->FirstChildElement();
        while (curNode != nullptr) {
          if (settingToFind == RemoveLineBreaks(curNode->Attribute("name"))) {
            setting->SetSelectedIndexByString(curNode->GetText());
            curNode = curNode->NextSiblingElement();
            break;
          }
          curNode = curNode->NextSiblingElement();
        }
      }

      // Reset to the beginning if we reached the end.
      if (curNode == nullptr) {
        curNode = rootNode->FirstChildElement();
      }
    }
  }
  return true;
}

//Delete the selected preset
bool DeletePreset(std::string_view presetName, OptionCategory category) {
  Result res;
  FS_Archive sdmcArchive = 0;

  const std::string filepath = PresetPath(presetName, category);

  // Open SD archive
  if (!R_SUCCEEDED(res = FSUSER_OpenArchive(&sdmcArchive, ARCHIVE_SDMC, fsMakePath(PATH_EMPTY, "")))) {
    printf("\x1b[22;5HFailed to load SD Archive.");
    return false;
  }

  FSUSER_DeleteFile(sdmcArchive, fsMakePath(PATH_ASCII, filepath.c_str()));
  return true;
}

//Saves the new preset to a file
bool SaveSpecifiedPreset(std::string_view presetName, OptionCategory category) {
  //don't save if the user cancelled
  if (presetName.empty()) {
    return false;
  }
  return SavePreset(presetName, category);
}

void SaveCachedSettings() {
  SavePreset(CACHED_SETTINGS_FILENAME, OptionCategory::Setting);
}

void LoadCachedSettings() {
  //If cache file exists, load it
  for (const auto& entry : fs::directory_iterator(GetBasePath(OptionCategory::Setting))) {
    if(entry.path().stem().string() == CACHED_SETTINGS_FILENAME) {
      //File exists, open
      LoadPreset(CACHED_SETTINGS_FILENAME, OptionCategory::Setting);
    }
  }
}

bool SaveCachedCosmetics() {
  return SavePreset(CACHED_COSMETICS_FILENAME, OptionCategory::Cosmetic);
}

void LoadCachedCosmetics() {
  //If cache file exists, load it
  for (const auto& entry : fs::directory_iterator(GetBasePath(OptionCategory::Cosmetic))) {
    if(entry.path().stem().string() == CACHED_COSMETICS_FILENAME) {
      //File exists, open
      LoadPreset(CACHED_COSMETICS_FILENAME, OptionCategory::Cosmetic);
    }
  }
}
