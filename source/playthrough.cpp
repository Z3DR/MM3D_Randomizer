#include "playthrough.hpp"

//#include "custom_messages.hpp"
#include "fill.hpp"
#include "location_access.hpp"
#include "logic.hpp"
#include "random.hpp"
#include "spoiler_log.hpp"
#include "rnd/item_override.h"
#include "custom_messages.hpp"
#include "hints.hpp"

#include <3ds.h>
#include <unistd.h>

namespace Playthrough {

    int Playthrough_Init(u32 seed) {
      //initialize the RNG with just the seed incase any settings need to be
      //resolved to something random
      Random_Init(seed);

      overrides.clear();
      //CustomMessages::ClearMessages();
      ItemReset();
      HintReset();
      Areas::AccessReset();

      Settings::UpdateSettings();
      //once the settings have been finalized turn them into a string for hashing
      std::string settingsStr;
      for (Menu* menu : Settings::GetAllMenus()) {
        //don't go through non-menus
        if (menu->mode != OPTION_SUB_MENU) {
          continue;
        }

        for (size_t i = 0; i < menu->settingsList->size(); i++) {
          Option* setting = menu->settingsList->at(i);
          if (setting->IsCategory(OptionCategory::Setting)) {
            settingsStr += setting->GetSelectedOptionText();
          }
        }
      }
      unsigned int finalHash = std::hash<std::string>{}(Settings::seed + settingsStr);
      Random_Init(finalHash);

      Logic::UpdateHelpers();
      
      if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_VANILLA)) {
        VanillaFill(); //Just place items in their vanilla locations
      }
      else { //Fill locations with logic
        int ret = Fill(); 
        if (ret < 0) {
            return ret;
        }
      }

      GenerateHash();

      if (Settings::GenerateSpoilerLog) {
        //write logs
        printf("\x1b[12;10HWriting Spoiler Log...");
        if (SpoilerLog_Write()) {
          printf("Done");
        } else {
          printf("Failed");
        }
        #ifdef ENABLE_DEBUG
          printf("\x1b[12;10HWriting Placement Log...");
          if (PlacementLog_Write()) {
            printf("Done\n");
          } else {
            printf("Failed\n");
          }
        #endif
        PlacementLog_Clear();
      }
      CreateTingleHintText();

      playthroughLocations.clear();
      wothLocations.clear();
      playthroughBeatable = false;

      return 1;
    }

    //used for generating a lot of seeds at once
    int Playthrough_Repeat(int count /*= 1*/) {
      printf("\x1b[0;0HGENERATING %d SEEDS", count);
      u32 repeatedSeed = 0;
      for (int i = 0; i < count; i++) {
        repeatedSeed = rand() % 0xFFFFFFFF;
        Settings::seed = std::to_string(repeatedSeed);
        // CitraPrint("testing seed: " + Settings::seed);
        Playthrough_Init(std::hash<std::string>{}(Settings::seed));
        PlacementLog_Clear();
        printf("\x1b[15;15HSeeds Generated: %d\n", i + 1);
      }

      return 1;
    }
}
