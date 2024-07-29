#include "spoiler_log.hpp"

#include "dungeon.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
//#include "entrance.hpp"
#include "random.hpp"
#include "settings.hpp"
//#include "trial.hpp"
#include "tinyxml2.h"
#include "utils.hpp"

#include <3ds.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace rnd;
namespace {
  std::string placementtxt;

  constexpr std::array<std::string_view, 62> hashIcons = {
      "Ocarina",
      "Hero's Bow",
      "Fire Arrow",
      "Ice Arrow",
      "Light Arrow",
      "Bomb",
      "Bombchu",
      "Deku Stick",
      "Deku Nut",
      "Magic Bean",
      "Powder Keg",
      "Pictograph Box",
      "Lens of Truth",
      "Hookshot",
      "Great Fairy Sword",
      "Empty Bottle",
      "Deku Princess",
      "Bottled Bugs",
      "Bottled Big Poe",
      "Bottled Hot Water",
      "Bottled Zora Egg",
      "Bottled Gold Dust",
      "Bottled Magical Mushroom",
      "Bottled Seahorse",
      "Chateau Romani",
      "Moon's Tear",
      "Town Deed",
      "Room Key",
      "Letter To Mama",
      "Letter To Kafei",
      "Pendant of Memories",
      "Map",
      "Deku Mask",
      "Zora mask",
      "Fierce Deity Mask",
      "Kafei Mask",
      "All Night's Mask",
      "Bunny Hood",
      "Keaton Mask",
      "Garo Mask",
      "Romani Mask",
      "Circus Leader's Mask",
      "Postman Hat",
      "Couple's Mask",
      "Great Fairy Mask",
      "Gibdo Mask",
      "Don Gero Mask",
      "Kamaro Mask",
      "Captain's Hat",
      "Stone Mask",
      "Bremen Mask",
      "Blast Mask",
      "Mask Of Scents",
      "Giant Mask",
      "Kokiri Sword",
      "Gilded Sword",
      "Helix Sword",
      "Hero Shield",
      "Mirror Shield",
      "Quiver",
      "Adult Wallet",
      "Bomber's Notebook",
  };
}

static RandomizerHash randomizerHash;
static SpoilerData spoilerData;

void GenerateHash() {
  for (size_t i = 0; i < randomizerHash.size(); i++) {
    const auto iconIndex = static_cast<u8>(Random(0, hashIcons.size()));
    Settings::hashIconIndexes[i] = iconIndex;
    randomizerHash[i] = hashIcons[iconIndex];
  }

  // Clear out spoiler log data here, in case we aren't going to re-generate it
  spoilerData = { 0 };
}

const RandomizerHash& GetRandomizerHash() {
  return randomizerHash;
}

// Returns the randomizer hash as concatenated string, separated by comma.
const std::string GetRandomizerHashAsString() {
  std::string hash = "";
  for (const std::string& str : randomizerHash) {
    hash += str + ", ";
  }
  hash.erase(hash.length() - 2); // Erase last comma
  return hash;
}

const SpoilerData& GetSpoilerData() {
  return spoilerData;
}

static auto GetGeneralPath() {
  return "/3ds/mm3dr/spoiler_logs/" + Settings::seed + " (" + GetRandomizerHashAsString() + ")";
}

static auto GetSpoilerLogPath() {
  return GetGeneralPath() + "-spoilerlog.xml";
}

static auto GetPlacementLogPath() {
  return GetGeneralPath() + "-placementlog.xml";
}

static void WriteIngameSpoilerLog() {
    u16 spoilerTotalItems       = 0;
    u16 spoilerItemIndex        = 0;
    u32 spoilerStringOffset     = 0;
    u16 spoilerSphereItemoffset = 0;
    u16 spoilerGroupOffset      = 0;
    // Intentionally junk value so we trigger the 'new group, record some stuff' code
    u8 currentGroup        = SpoilerCollectionCheckGroup::SPOILER_COLLECTION_GROUP_COUNT;
    bool spoilerOutOfSpace = false;

    // Create map of string data offsets for all _unique_ item locations and names in the playthrough
    // Some item names, like gold skulltula tokens, can appear many times in a playthrough
    std::unordered_map<LocationKey, u16>
        itemLocationsMap; // Map of LocationKey to an index into spoiler data item locations
    itemLocationsMap.reserve(allLocations.size());
    std::unordered_map<std::string, u16>
        stringOffsetMap; // Map of strings to their offset into spoiler string data array
    stringOffsetMap.reserve(allLocations.size() * 2);

    // Sort all locations by their group, so the in-game log can show a group of items by simply starting/ending at
    // certain indices
    std::stable_sort(allLocations.begin(), allLocations.end(), [](const LocationKey& a, const LocationKey& b) {
        auto groupA = Location(a)->GetCollectionCheckGroup();
        auto groupB = Location(b)->GetCollectionCheckGroup();
        return groupA < groupB;
    });

    for (const LocationKey key : allLocations) {
        if (spoilerTotalItems >= SPOILER_ITEMS_MAX * SPOILER_LOCDATS) {
            spoilerOutOfSpace = true;
            break;
        }
        auto loc = Location(key);

        // Hide excluded locations from ingame tracker
        if (loc->IsExcluded()) {
            continue;
        }
        
        // Cows
        else if (!Settings::ShuffleCows && loc->IsCategory(Category::cCow)) {
            continue;
        }
        // Deku Merchant Trade Quest
        else if (!Settings::ShuffleMerchants && loc->IsCategory(Category::cTradeItem)) {
            continue;
        }
        // Aju and Kafei
        else if (!Settings::ShuffleTradeItems && loc->IsCategory(Category::cAnjuAndKafei)) {
            continue;
        }
        // Shops
        else if ((Settings::Shopsanity.Is(ShopsanitySetting::SHOPSANITY_OFF)) && loc->IsCategory(Category::cShop)){
          continue;
        }
        // Stray Fairies
        if (!Settings::StrayFairysanity &&Location(key)->GetPlacedItemKey() == CT_STRAY_FAIRY) {
          continue;
         }
        if (!Settings::StrayFairysanity &&Location(key)->GetPlacedItemKey() == WF_STRAY_FAIRY) {
          continue;
        }
        if (!Settings::StrayFairysanity &&Location(key)->GetPlacedItemKey() == SH_STRAY_FAIRY) {
          continue;
        }
        if (!Settings::StrayFairysanity &&Location(key)->GetPlacedItemKey() == GBT_STRAY_FAIRY) {
          continue;
        }
        if (!Settings::StrayFairysanity && Location(key)->GetPlacedItemKey() == ST_STRAY_FAIRY) {
          continue;
        }
        // Skulltula Tokens
        if (!Settings::Tokensanity && Location(key)->GetPlacedItemKey() == OCEANSIDE_SKULLTULA_TOKEN) {
          continue;
        }
        if (!Settings::Tokensanity && Location(key)->GetPlacedItemKey() == SWAMP_SKULLTULA_TOKEN) {
          continue;
        }
        // Songs
        if ((Settings::ShuffleSongs.Is(SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS)) && Location(key)->IsCategory(Category::cSong)) {
          continue;
        }
        // Tingle Maps
        if (!Settings::ShuffleTingleMaps && Location(key)->IsCategory(Category::cTingleMap)) {
          continue;
        }
        // If Starting with Song of Healing hide Deku Mask and Bombers Notebook as they're unobtainable and junk
        if (key == HMS_DEKU_MASK && (Settings::StartingSongOfHealing.Value<u8>() == u8(1) || !Settings::ShuffleTransformation)) {
           continue;
        }
        if (key == HMS_BOMBERS_NOTEBOOK && (Settings::StartingSongOfHealing.Value<u8>() == u8(1) || !Settings::ShuffleBombersNotebook)) {
           continue;
        }
        // Always hide unreachable checks
        if (key == CLOCK_TOWER_OCARINA_OF_TIME) {
          continue;
        }
        if (key == HMS_STARTING_SWORD){ // && Settings::StartingKokiriSword.Is((u8)StartingSwordSetting::STARTINGSWORD_KOKIRI)) {
          continue;     
        }
        if (key == HMS_STARTING_SHIELD) {
          continue;           
        }
        //Hide Deku Princess & Zora Eggs as they're not randomized yet
        if (key == WOODFALL_TEMPLE_DEKU_PRINCESS) {
          continue;
        }
        if (Location(key)->IsCategory(Category::cZoraEgg)) {
          continue;
        }
            
            

        // Copy at most 51 chars from the name and location name to avoid issues with names that don't fit on screen
        // Only copy enough characters that can fit on the screen
        const char* locNameFormat  = "%.51s";
        const char* itemNameFormat = "%.49s";

        auto locName = loc->GetName();
        if (stringOffsetMap.find(locName) == stringOffsetMap.end()) {
            if (spoilerStringOffset + locName.size() + 1 >= SPOILER_STRING_DATA_SIZE) {
                spoilerOutOfSpace = true;
                break;
            } else {
                stringOffsetMap[locName] = spoilerStringOffset;
                spoilerStringOffset +=
                    sprintf(&spoilerData.StringData[spoilerStringOffset], locNameFormat, locName.c_str()) + 1;
            }
        }

        auto locItem = loc->GetPlacedItemName().GetEnglish();
        /*if (loc->IsCategory(Category::cShop)) {
            if (loc->GetPlacedItemKey() == ICE_TRAP) {
                locItem = NonShopItems[TransformShopIndex(GetShopIndex(key))].Name.GetNAEnglish();
            }
            locItem += ": " + std::to_string(loc->GetPrice()) + " Rupees";
        }*/
        if (stringOffsetMap.find(locItem) == stringOffsetMap.end()) {
            if (spoilerStringOffset + locItem.size() + 1 >= SPOILER_STRING_DATA_SIZE) {
                spoilerOutOfSpace = true;
                break;
            } else {
                stringOffsetMap[locItem] = spoilerStringOffset;
                spoilerStringOffset +=
                    sprintf(&spoilerData.StringData[spoilerStringOffset], itemNameFormat, locItem.c_str()) + 1;
            }
        }

            spoilerData.ItemLocations[spoilerItemIndex].LocationStrOffset = stringOffsetMap[locName];
            spoilerData.ItemLocations[spoilerItemIndex].ItemStrOffset = stringOffsetMap[locItem];
            spoilerData.ItemLocations[spoilerItemIndex].CollectionCheckType = loc->GetCollectionCheck().type;
            spoilerData.ItemLocations[spoilerItemIndex].OverrideType = loc->GetOverrideType();
            spoilerData.ItemLocations[spoilerItemIndex].LocationScene = loc->GetScene();
            spoilerData.ItemLocations[spoilerItemIndex].LocationFlag = loc->GetFlag();
            
            //Set Repeatable locations CollectType(Used for changing color in spoiler log)
            if (Location(key)->IsRepeatable())
            {
              spoilerData.ItemLocations[spoilerItemIndex].CollectType = COLLECTTYPE_REPEATABLE;
            }
              
            auto checkGroup                                   = loc->GetCollectionCheckGroup();
        spoilerData.ItemLocations[spoilerItemIndex].Group = checkGroup;

        // Group setup
        if (checkGroup != currentGroup) {
            currentGroup                           = checkGroup;
            spoilerData.GroupOffsets[currentGroup] = spoilerGroupOffset;
        }
        ++spoilerData.GroupItemCounts[currentGroup];
        ++spoilerGroupOffset;

        itemLocationsMap[key] = spoilerTotalItems++;

        spoilerItemIndex++;
        if (spoilerItemIndex >= SPOILER_ITEMS_MAX) {
            stringOffsetMap.clear();
            spoilerItemIndex    = 0;
            spoilerStringOffset = 0;
        }
    }
    spoilerData.ItemLocationsCount = spoilerTotalItems;

    if (Settings::IngameSpoilers) {
        bool playthroughItemNotFound = false;
        // Write playthrough data to in-game spoiler log
        if (!spoilerOutOfSpace) {
            for (u32 i = 0; i < playthroughLocations.size(); i++) {
                if (i >= SPOILER_SPHERES_MAX) {
                    spoilerOutOfSpace = true;
                    break;
                }
                spoilerData.Spheres[i].ItemLocationsOffset = spoilerSphereItemoffset;
                for (u32 loc = 0; loc < playthroughLocations[i].size(); ++loc) {
                    if (spoilerSphereItemoffset >= SPOILER_ITEMS_MAX) {
                        spoilerOutOfSpace = true;
                        break;
                    }

                    const auto foundItemLoc = itemLocationsMap.find(playthroughLocations[i][loc]);
                    if (foundItemLoc != itemLocationsMap.end()) {
                        spoilerData.SphereItemLocations[spoilerSphereItemoffset++] = foundItemLoc->second;
                    } else {
                        playthroughItemNotFound = true;
                    }
                    ++spoilerData.Spheres[i].ItemCount;
                }
                ++spoilerData.SphereCount;
            }
        }
        if (spoilerOutOfSpace || playthroughItemNotFound) {
            printf("%sError!%s ", YELLOW, WHITE);
        }
    }
}

    // Writes the location to the specified node.
    static void WriteLocation(
        tinyxml2::XMLElement * parentNode,
        const LocationKey locationKey,
        const bool withPadding = false) {
        ItemLocation* location = Location(locationKey);

        auto node = parentNode->InsertNewChildElement("location");
        node->SetAttribute("name", location->GetName().c_str());
        node->SetText(location->GetPlacedItemName().GetEnglish().c_str());

        if (withPadding) {
            constexpr int16_t LONGEST_NAME = 56; // The longest name of a location.
            constexpr int16_t PRICE_ATTRIBUTE = 12; // Length of a 3-digit price attribute.

            // Insert a padding so we get a kind of table in the XML document.
            int16_t requiredPadding = LONGEST_NAME - location->GetName().length();
            if (location->IsCategory(Category::cShop)) {
                // Shop items have short location names, but come with an additional price attribute.
                requiredPadding -= PRICE_ATTRIBUTE;
            }
            if (requiredPadding >= 0) {
                std::string padding(requiredPadding, ' ');
                node->SetAttribute("_", padding.c_str());
            }
        }

        if (location->IsCategory(Category::cShop)) {
            char price[6];
            sprintf(price, "%03d", location->GetPrice());
            node->SetAttribute("price", price);
        }
        if (!location->IsAddedToPool()) {
#ifdef ENABLE_DEBUG  
            node->SetAttribute("not-added", true);
#endif
        }
    }


/*
//Writes a shuffled entrance to the specified node
static void WriteShuffledEntrance(
  tinyxml2::XMLElement* parentNode,
  Entrance* entrance,
  const bool withPadding = false
) {
  auto node = parentNode->InsertNewChildElement("entrance");
  node->SetAttribute("name", entrance->GetName().c_str());
  auto text = entrance->GetConnectedRegion()->regionName + " from " + entrance->GetReplacement()->GetParentRegion()->regionName;
  node->SetText(text.c_str());

  if (withPadding) {
    constexpr int16_t LONGEST_NAME = 56; //The longest name of a vanilla entrance

    //Insert padding so we get a kind of table in the XML document
    int16_t requiredPadding = LONGEST_NAME - entrance->GetName().length();
    if (requiredPadding > 0) {
      std::string padding(requiredPadding, ' ');
      node->SetAttribute("_", padding.c_str());
    }
  }
}*/

// Writes the settings (without excluded locations, starting inventory and tricks) to the spoilerLog document.
static void WriteSettings(tinyxml2::XMLDocument& spoilerLog, const bool printAll = false) {
  auto parentNode = spoilerLog.NewElement("settings");

  std::vector<Menu*> allMenus = Settings::GetAllMenus();

  for (const Menu* menu : allMenus) {
    //This is a menu of settings, write them
    if (menu->mode == OPTION_SUB_MENU && menu->printInSpoiler) {
      for (const Option* setting : *menu->settingsList) {
        if (printAll || (!setting->IsHidden() && setting->IsCategory(OptionCategory::Setting))) {
          auto node = parentNode->InsertNewChildElement("setting");
          node->SetAttribute("name", RemoveLineBreaks(setting->GetName()).c_str());
          node->SetText(setting->GetSelectedOptionText().c_str());
        }
      }
    }
  }
  spoilerLog.RootElement()->InsertEndChild(parentNode);
}

// Writes the excluded locations to the spoiler log, if there are any.
static void WriteExcludedLocations(tinyxml2::XMLDocument& spoilerLog) {
  auto parentNode = spoilerLog.NewElement("excluded-locations");

  for (const auto& location : Settings::excludeLocationsOptions) {
    if (location->GetSelectedOptionIndex() == (u8)ExcludeLocationSetting::INCLUDE) {
      continue;
    }

    tinyxml2::XMLElement* node = spoilerLog.NewElement("location");
    node->SetAttribute("name", RemoveLineBreaks(location->GetName()).c_str());
    parentNode->InsertEndChild(node);
  }

  if (!parentNode->NoChildren()) {
    spoilerLog.RootElement()->InsertEndChild(parentNode);
  }
}

// Writes the starting inventory to the spoiler log, if there is any.
static void WriteStartingInventory(tinyxml2::XMLDocument& spoilerLog) {
  auto parentNode = spoilerLog.NewElement("starting-inventory");

  for (size_t i = 0; i < Settings::startingInventoryInventory.size(); ++i) {
    const auto setting = Settings::startingInventoryInventory[i];
    //Ignore no starting bottles and the Choose/All On toggles
    if (setting->GetSelectedOptionIndex() == (u8)StartingBottleSetting::STARTINGBOTTLE_NONE || setting->GetSelectedOptionText() == "Choose" || setting->GetSelectedOptionText() == "All On") {
      continue;
    } 
  
    auto node = parentNode->InsertNewChildElement("item");
    node->SetAttribute("name", setting->GetName().c_str());
    node->SetText(setting->GetSelectedOptionText().c_str());
  }

  for (size_t i = 0; i < Settings::startingInventoryMasks.size(); ++i) {
    const auto setting = Settings::startingInventoryMasks[i];
    if (setting->GetSelectedOptionIndex() == 0) { 
      continue;
    }
    auto node = parentNode->InsertNewChildElement("item");
    node->SetAttribute("name", setting->GetName().c_str());
    node->SetText(setting->GetSelectedOptionText().c_str());
  }

  for (size_t i = 0; i < Settings::startingInventorySongs.size(); ++i) {
    const auto setting = Settings::startingInventorySongs[i];
    if (setting->GetSelectedOptionIndex() == 0) { 
      continue;
    }
    auto node = parentNode->InsertNewChildElement("item");
    node->SetAttribute("name", setting->GetName().c_str());
    node->SetText(setting->GetSelectedOptionText().c_str());
  }

  for (size_t i = 0; i < Settings::startingInventoryUpgrades.size(); ++i) {
    const auto setting = Settings::startingInventoryUpgrades[i];
    if (setting->GetSelectedOptionIndex() == 0) { 
      continue;
    } 
    auto node = parentNode->InsertNewChildElement("item");
    node->SetAttribute("name", setting->GetName().c_str());
    node->SetText(setting->GetSelectedOptionText().c_str());
  }

  for (size_t i = 0; i < Settings::startingInventoryRemains.size(); ++i) {
    const auto setting = Settings::startingInventoryRemains[i];
    if (setting->GetSelectedOptionIndex() == 0) { 
      continue;
    }
    auto node = parentNode->InsertNewChildElement("item");
    node->SetAttribute("name", setting->GetName().c_str());
    node->SetText(setting->GetSelectedOptionText().c_str());
  }

  if (!parentNode->NoChildren()) {
    spoilerLog.RootElement()->InsertEndChild(parentNode);
  }
}
/*
// Writes the enabled tricks to the spoiler log, if there are any.
static void WriteEnabledTricks(tinyxml2::XMLDocument& spoilerLog) {
  auto parentNode = spoilerLog.NewElement("enabled-tricks");

  for (const auto& setting : Settings::trickOptions) {
    if (setting->GetSelectedOptionIndex() != TRICK_ENABLED || !setting->IsCategory(OptionCategory::Setting)) {
      continue;
    }

    auto node = parentNode->InsertNewChildElement("trick");
    node->SetAttribute("name", RemoveLineBreaks(setting->GetName()).c_str());
  }

  if (!parentNode->NoChildren()) {
    spoilerLog.RootElement()->InsertEndChild(parentNode);
  }
}*/


// Writes the intended playthrough to the spoiler log, separated into spheres.
static void WritePlaythrough(tinyxml2::XMLDocument& spoilerLog) {
  auto playthroughNode = spoilerLog.NewElement("playthrough");

  for (uint i = 0; i < playthroughLocations.size(); ++i) {
    auto sphereNode = playthroughNode->InsertNewChildElement("sphere");
    sphereNode->SetAttribute("level", i + 1);

    for (const LocationKey key : playthroughLocations[i]) {
      WriteLocation(sphereNode, key, true);
    }
  }

  spoilerLog.RootElement()->InsertEndChild(playthroughNode);
}
/*
//Write the randomized entrance playthrough to the spoiler log, if applicable
static void WriteShuffledEntrances(tinyxml2::XMLDocument& spoilerLog) {
  if (!Settings::ShuffleEntrances || noRandomEntrances) {
    return;
  }

  auto playthroughNode = spoilerLog.NewElement("entrance-playthrough");

  for (uint i = 0; i < playthroughEntrances.size(); ++i) {
    auto sphereNode = playthroughNode->InsertNewChildElement("sphere");
    sphereNode->SetAttribute("level", i + 1);

    for (Entrance* entrance : playthroughEntrances[i]) {
      WriteShuffledEntrance(sphereNode, entrance, true);
    }
  }

  spoilerLog.RootElement()->InsertEndChild(playthroughNode);
}
*/
// Writes the WOTH locations to the spoiler log, if there are any.
static void WriteWayOfTheHeroLocation(tinyxml2::XMLDocument& spoilerLog) {
  auto parentNode = spoilerLog.NewElement("way-of-the-hero-locations");

  for (const LocationKey key : wothLocations) {
    WriteLocation(parentNode, key, true);
  }

  if (!parentNode->NoChildren()) {
    spoilerLog.RootElement()->InsertEndChild(parentNode);
  }
}

// Writes the hints to the spoiler log, if they are enabled.
static void WriteHints(tinyxml2::XMLDocument& spoilerLog) {
  if (Settings::GossipStoneHints.Is((u8)GossipStoneHintsSetting::HINTS_NO_HINTS)) {
    return;
  }

  auto parentNode = spoilerLog.NewElement("hints");

  for (const LocationKey key : gossipStoneLocations) {
    ItemLocation* location = Location(key);

    auto node = parentNode->InsertNewChildElement("hint");
    node->SetAttribute("location", location->GetName().c_str());

    auto text = location->GetPlacedItemName().GetEnglish();
    std::replace(text.begin(), text.end(), '&', ' ');
    std::replace(text.begin(), text.end(), '^', ' ');
    node->SetText(text.c_str());
  }

  spoilerLog.RootElement()->InsertEndChild(parentNode);
}

static void WriteAllLocations(tinyxml2::XMLDocument& spoilerLog) {
  auto parentNode = spoilerLog.NewElement("all-locations");

  for (const LocationKey key : allLocations) {
    WriteLocation(parentNode, key, true);
  }

  spoilerLog.RootElement()->InsertEndChild(parentNode);
}

bool SpoilerLog_Write() {
  WriteIngameSpoilerLog();

  auto spoilerLog = tinyxml2::XMLDocument(false);
  spoilerLog.InsertEndChild(spoilerLog.NewDeclaration());

  auto rootNode = spoilerLog.NewElement("spoiler-log");
  spoilerLog.InsertEndChild(rootNode);

  rootNode->SetAttribute("version", Settings::version.c_str());
  rootNode->SetAttribute("seed", Settings::seed.c_str());
  rootNode->SetAttribute("hash", GetRandomizerHashAsString().c_str());

  WriteSettings(spoilerLog);
  WriteExcludedLocations(spoilerLog);
  WriteStartingInventory(spoilerLog);
  //WriteEnabledTricks(spoilerLog);
  WritePlaythrough(spoilerLog);
  WriteWayOfTheHeroLocation(spoilerLog);

  playthroughLocations.clear();
  playthroughBeatable = false;
  wothLocations.clear();

  WriteHints(spoilerLog);
 // WriteShuffledEntrances(spoilerLog);
  WriteAllLocations(spoilerLog);

  auto e = spoilerLog.SaveFile(GetSpoilerLogPath().c_str());
  return e == tinyxml2::XML_SUCCESS;
}

void PlacementLog_Msg(std::string_view msg) {
  placementtxt += msg;
}

void PlacementLog_Clear() {
  placementtxt = "";
}

bool PlacementLog_Write() {
  auto placementLog = tinyxml2::XMLDocument(false);
  placementLog.InsertEndChild(placementLog.NewDeclaration());

  auto rootNode = placementLog.NewElement("placement-log");
  placementLog.InsertEndChild(rootNode);

  rootNode->SetAttribute("version", Settings::version.c_str());
  rootNode->SetAttribute("seed", Settings::seed.c_str());
  rootNode->SetAttribute("hash", GetRandomizerHashAsString().c_str());

  WriteSettings(placementLog, true); // Include hidden settings.
  WriteExcludedLocations(placementLog);
  WriteStartingInventory(placementLog);
  //WriteEnabledTricks(placementLog);
  
  placementtxt = "\n" + placementtxt;

  auto node = rootNode->InsertNewChildElement("log");
  auto contentNode = node->InsertNewText(placementtxt.c_str());
  contentNode->SetCData(true);

  auto e = placementLog.SaveFile(GetPlacementLogPath().c_str());
  return e == tinyxml2::XML_SUCCESS;
}
