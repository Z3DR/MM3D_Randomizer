#pragma once

#include <3ds.h>

#include <string>
#include <vector>

enum class OptionCategory;

void CreatePresetDirectories(FS_Archive sdmcArchive);
std::vector<std::string> GetSettingsPresets();
bool SavePreset(std::string_view presetName, OptionCategory category);
bool LoadPreset(std::string_view presetName, OptionCategory category);
bool DeletePreset(std::string_view presetName, OptionCategory category);
bool SaveSpecifiedPreset(std::string_view presetName, OptionCategory category);
void SaveCachedSettings();
void LoadCachedSettings();
bool SaveCachedCosmetics();
void LoadCachedCosmetics();
