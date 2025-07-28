#include "hints.hpp"

//#include "custom_messages.hpp"
#include "item_location.hpp"
#include "item_pool.hpp"
#include "location_access.hpp"
#include "logic.hpp"
#include "random.hpp"
#include "spoiler_log.hpp"
#include "fill.hpp"
#include "hint_list.hpp"
#include "custom_messages.hpp"
//#include "trial.hpp"
//#include "entrance.hpp"

//using namespace CustomMessages;
using namespace Logic;
using namespace Settings;
//using namespace Trial;

constexpr std::array<HintSetting, 4> hintSettingTable{{
  // Useless hints
  {
    .dungeonsWothLimit = 2,
    .dungeonsBarrenLimit = 1,
    .namedItemsRequired = false,
    .distTable = {{
      {.type = HintType::Trial,     .order =  1, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Always,    .order =  2, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Woth,      .order =  3, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Barren,    .order =  4, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Entrance,  .order =  5, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Sometimes, .order =  6, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Random,    .order =  7, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Item,      .order =  8, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Song,      .order =  9, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Overworld, .order = 10, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Dungeon,   .order = 11, .weight =  0, .fixed = 0, .copies = 0},
      {.type = HintType::Junk,      .order = 12, .weight = 99, .fixed = 0, .copies = 0},
      {.type = HintType::NamedItem, .order = 13, .weight =  0, .fixed = 0, .copies = 0},
    }},
  },

  // Balanced hints
  {
    .dungeonsWothLimit = 2,
    .dungeonsBarrenLimit = 1,
    .namedItemsRequired = true,
    .distTable = {{
      {.type = HintType::Trial,     .order =  1, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Always,    .order =  2, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Woth,      .order =  3, .weight =  7, .fixed = 0, .copies = 1},
      {.type = HintType::Barren,    .order =  4, .weight =  4, .fixed = 0, .copies = 1},
      {.type = HintType::Entrance,  .order =  5, .weight =  6, .fixed = 0, .copies = 1},
      {.type = HintType::Sometimes, .order =  6, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Random,    .order =  7, .weight = 12, .fixed = 0, .copies = 1},
      {.type = HintType::Item,      .order =  8, .weight = 10, .fixed = 0, .copies = 1},
      {.type = HintType::Song,      .order =  9, .weight =  2, .fixed = 0, .copies = 1},
      {.type = HintType::Overworld, .order = 10, .weight =  4, .fixed = 0, .copies = 1},
      {.type = HintType::Dungeon,   .order = 11, .weight =  3, .fixed = 0, .copies = 1},
      {.type = HintType::Junk,      .order = 12, .weight =  6, .fixed = 0, .copies = 1},
      {.type = HintType::NamedItem, .order = 13, .weight =  0, .fixed = 0, .copies = 1},
    }},
  },

  // Strong hints
  {
    .dungeonsWothLimit = 2,
    .dungeonsBarrenLimit = 1,
    .namedItemsRequired = true,
    .distTable = {{
      {.type = HintType::Trial,     .order =  1, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Always,    .order =  2, .weight =  0, .fixed = 0, .copies = 2},
      {.type = HintType::Woth,      .order =  3, .weight = 12, .fixed = 0, .copies = 2},
      {.type = HintType::Barren,    .order =  4, .weight = 12, .fixed = 0, .copies = 1},
      {.type = HintType::Entrance,  .order =  5, .weight =  4, .fixed = 0, .copies = 1},
      {.type = HintType::Sometimes, .order =  6, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Random,    .order =  7, .weight =  8, .fixed = 0, .copies = 1},
      {.type = HintType::Item,      .order =  8, .weight =  8, .fixed = 0, .copies = 1},
      {.type = HintType::Song,      .order =  9, .weight =  4, .fixed = 0, .copies = 1},
      {.type = HintType::Overworld, .order = 10, .weight =  6, .fixed = 0, .copies = 1},
      {.type = HintType::Dungeon,   .order = 11, .weight =  6, .fixed = 0, .copies = 1},
      {.type = HintType::Junk,      .order = 12, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::NamedItem, .order = 13, .weight =  0, .fixed = 0, .copies = 1},
    }},
  },

  // Very strong hints
  {
    .dungeonsWothLimit = 40,
    .dungeonsBarrenLimit = 40,
    .namedItemsRequired = true,
    .distTable = {{
      {.type = HintType::Trial,     .order =  1, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Always,    .order =  2, .weight =  0, .fixed = 0, .copies = 2},
      {.type = HintType::Woth,      .order =  3, .weight = 15, .fixed = 0, .copies = 2},
      {.type = HintType::Barren,    .order =  4, .weight = 15, .fixed = 0, .copies = 1},
      {.type = HintType::Entrance,  .order =  5, .weight = 10, .fixed = 0, .copies = 1},
      {.type = HintType::Sometimes, .order =  6, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Random,    .order =  7, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::Item,      .order =  8, .weight =  5, .fixed = 0, .copies = 1},
      {.type = HintType::Song,      .order =  9, .weight =  2, .fixed = 0, .copies = 1},
      {.type = HintType::Overworld, .order = 10, .weight =  7, .fixed = 0, .copies = 1},
      {.type = HintType::Dungeon,   .order = 11, .weight =  7, .fixed = 0, .copies = 1},
      {.type = HintType::Junk,      .order = 12, .weight =  0, .fixed = 0, .copies = 1},
      {.type = HintType::NamedItem, .order = 13, .weight =  0, .fixed = 0, .copies = 1},
    }},
  },
}};

static Area* GetHintRegion(const AreaKey area) {

  std::vector<AreaKey> alreadyChecked = {};
  std::vector<AreaKey> spotQueue = {area};

  while (!spotQueue.empty()) {
    AreaKey region = spotQueue.back();
    alreadyChecked.push_back(region);
    spotQueue.pop_back();

    if (AreaTable(region)->hintKey != NONE) {
      return AreaTable(region);
    }

    //add unchecked exits to spot queue
    for (auto& exit : AreaTable(region)->exits) {
      bool checked = false;

      for (AreaKey checkedExit : alreadyChecked) {
        if (exit.GetAreaKey() == checkedExit) {
          checked = true;
          break;
        }
      }

      if (!checked) {
        spotQueue.insert(spotQueue.begin(), exit.GetAreaKey());
      }
    }
  }
  return AreaTable(NONE);
}

static std::vector<LocationKey> GetAccessibleGossipStones(const LocationKey hintedLocation = MAJORA) {
  //temporarily remove the hinted location's item, and then perform a
  //reachability search for gossip stone locations.
  ItemKey originalItem = Location(hintedLocation)->GetPlacedItemKey();
  Location(hintedLocation)->SetPlacedItem(NONE);

  LogicReset();
  auto accessibleGossipStones = GetAccessibleLocations(gossipStoneLocations);
  //Give the item back to the location
  Location(hintedLocation)->SetPlacedItem(originalItem);
  
  return accessibleGossipStones;
}

static void AddHint(Text hint, const LocationKey gossipStone, const std::vector<colType>& colors = {}) {
  //save hints as dummy items for writing to the spoiler log
  NewItem(gossipStone, Item{ false, true, &noVariable, hint, NONE, (u32)GetItemID::GI_RUPEE_BLUE, ITEMTYPE_EVENT, (u16)0});
  Location(gossipStone)->SetPlacedItem(gossipStone);

  //create the in game message
  u16 messageId = Location(gossipStone)->GetTextID();
  std::vector<iconType> icons = {};
  //u32 sariaMessageId = 0xA00 + Location(gossipStone)->GetFlag();
  // CitraPrint("Our hint text is " + hint.GetEnglish());
  if (hint.GetEnglish().find("$")) {
    icons.push_back(B_BUTTON);
  }
  CustomMessages::CreateMessage(messageId, 0xFFFF, 0x3FFFFFFF, 0xFF0020, hint.GetEnglish().c_str(), colors, icons, {}, 0x0, false, false);
  //CreateMessageFromTextObject(messageId, 0, 2, 3, AddColorsAndFormat(hint, colors));
  //CreateMessageFromTextObject(sariaMessageId, 0, 2, 3, AddColorsAndFormat(hint + EVENT_TRIGGER(), colors));
}

static void CreateLocationHint(const std::vector<LocationKey>& possibleHintLocations) {
  //return if there aren't any hintable locations or gossip stones available
  if (possibleHintLocations.empty()) {
    PlacementLog_Msg("\tNO LOCATIONS TO HINT\n\n");
    return;
  }

  LocationKey hintedLocation = RandomElement(possibleHintLocations);
  const std::vector<LocationKey> accessibleGossipStones = GetAccessibleGossipStones(hintedLocation);

  PlacementLog_Msg("\tLocation: ");
  PlacementLog_Msg(Location(hintedLocation)->GetName());
  PlacementLog_Msg("\n");

  PlacementLog_Msg("\tItem: ");
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetEnglish());
  PlacementLog_Msg("\n");

  if (accessibleGossipStones.empty()) {
    PlacementLog_Msg("\tNO GOSSIP STONES TO PLACE HINT\n\n");
    return;
  }

  LocationKey gossipStone = RandomElement(accessibleGossipStones);
  Location(hintedLocation)->SetAsHinted();

  //make hint text
  Text locationHintText = Location(hintedLocation)->GetHint().GetText();
  Text itemHintText = Location(hintedLocation)->GetPlacedItem().GetHint().GetText();
  Text prefix = Hint(PREFIX).GetText();

  Text finalHint = prefix + locationHintText + " #"+itemHintText+"#.";
  PlacementLog_Msg("\tMessage: ");
  PlacementLog_Msg(finalHint.english);
  PlacementLog_Msg("\n\n");

  AddHint(finalHint, gossipStone, {QM_GREEN, QM_RED});
}

static void CreateWothHint(u8* remainingDungeonWothHints) {
  //get locations that are in the current playthrough
  std::vector<LocationKey> possibleHintLocations = {};
  //iterate through playthrough locations by sphere
  std::vector<LocationKey> wothHintLocations = FilterFromPool(wothLocations, [remainingDungeonWothHints](LocationKey loc){
    return Location(loc)->IsHintable()    && //only filter hintable locations
          !(Location(loc)->IsHintedAt())  && //only filter locations that haven't been hinted at
          (Location(loc)->IsOverworld() || (Location(loc)->IsDungeon() && (*remainingDungeonWothHints) > 0)); //make sure we haven't surpassed the woth dungeon limit
  });
  AddElementsToPool(possibleHintLocations, wothHintLocations);

  //If no more locations can be hinted at for woth, then just try to get another hint
  if (possibleHintLocations.empty()) {
    PlacementLog_Msg("\tNO LOCATIONS TO HINT\n\n");
    return;
  }
  LocationKey hintedLocation = RandomElement(possibleHintLocations);

  PlacementLog_Msg("\tLocation: ");
  PlacementLog_Msg(Location(hintedLocation)->GetName());
  PlacementLog_Msg("\n");

  PlacementLog_Msg("\tItem: ");
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetEnglish());
  PlacementLog_Msg("\n");

  //get an accessible gossip stone
  const std::vector<LocationKey> gossipStoneLocations = GetAccessibleGossipStones(hintedLocation);

  if (gossipStoneLocations.empty()) {
    PlacementLog_Msg("\tNO GOSSIP STONES TO PLACE HINT\n\n");
    return;
  }
  Location(hintedLocation)->SetAsHinted();
  LocationKey gossipStone = RandomElement(gossipStoneLocations);

  //form hint text
  Text locationText;
  if (Location(hintedLocation)->IsDungeon()) {
    *remainingDungeonWothHints -= 1;
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    // CitraPrint("WoTH Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    locationText = AreaTable(parentRegion)->GetHint().GetText();

  } else {
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    // CitraPrint("WoTH Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    locationText = GetHintRegion(parentRegion)->GetHint().GetText();
  }
  Text finalWothHint = Hint(PREFIX).GetText()+"#"+locationText+"#"+Hint(WAY_OF_THE_HERO).GetText();
  PlacementLog_Msg("\tMessage: ");
  PlacementLog_Msg(finalWothHint.english);
  PlacementLog_Msg("\n\n");
  AddHint(finalWothHint, gossipStone, {QM_BLUE});
}

static void CreateBarrenHint(u8* remainingDungeonBarrenHints, std::vector<LocationKey>& barrenLocations) {
  //remove dungeon locations if necessary
  if (*remainingDungeonBarrenHints < 1) {
    barrenLocations = FilterFromPool(barrenLocations, [](const LocationKey loc){return !(Location(loc)->IsDungeon());});
  }

  if (barrenLocations.empty()) {
    return;
  }

  LocationKey hintedLocation = RandomElement(barrenLocations, true);

  PlacementLog_Msg("\tLocation: ");
  PlacementLog_Msg(Location(hintedLocation)->GetName());
  PlacementLog_Msg("\n");

  PlacementLog_Msg("\tItem: ");
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetEnglish());
  PlacementLog_Msg("\n");

  //get an accessible gossip stone
  const std::vector<LocationKey> gossipStoneLocations = GetAccessibleGossipStones(hintedLocation);
  if (gossipStoneLocations.empty()) {
    PlacementLog_Msg("\tNO GOSSIP STONES TO PLACE HINT\n\n");
    return;
  }
  Location(hintedLocation)->SetAsHinted();
  LocationKey gossipStone = RandomElement(gossipStoneLocations);

  //form hint text
  Text locationText;
  if (Location(hintedLocation)->IsDungeon()) {
    *remainingDungeonBarrenHints -= 1;
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    // CitraPrint("Barrent Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    locationText = Hint(AreaTable(parentRegion)->hintKey).GetText();
  } else {
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    // CitraPrint("Barrent Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    locationText = Hint(GetHintRegion(parentRegion)->hintKey).GetText();
  }
  Text finalBarrenHint = Hint(PREFIX).GetText()+Hint(PLUNDERING).GetText()+"#"+locationText+"#"+Hint(FOOLISH).GetText();
  PlacementLog_Msg("\tMessage: ");
  PlacementLog_Msg(finalBarrenHint.english);
  PlacementLog_Msg("\n\n");
  AddHint(finalBarrenHint, gossipStone, {QM_RED});

  //get rid of all other locations in this same barren region
  barrenLocations = FilterFromPool(barrenLocations, [hintedLocation](LocationKey loc){
    return GetHintRegion(Location(loc)->GetParentRegionKey())->hintKey != GetHintRegion(Location(hintedLocation)->GetParentRegionKey())->hintKey;
  });

}

static void CreateRandomLocationHint(const bool goodItem = false) {
  const std::vector<LocationKey> possibleHintLocations = FilterFromPool(allLocations, [goodItem](const LocationKey loc) {
    return Location(loc)->IsHintable() && !(Location(loc)->IsHintedAt()) && (!goodItem || Location(loc)->GetPlacedItem().IsMajorItem());
  });
  //If no more locations can be hinted at, then just try to get another hint
  if (possibleHintLocations.empty()) {
    PlacementLog_Msg("\tNO LOCATIONS TO HINT\n\n");
    return;
  }
  LocationKey hintedLocation = RandomElement(possibleHintLocations);

  PlacementLog_Msg("\tLocation: ");
  PlacementLog_Msg(Location(hintedLocation)->GetName());
  PlacementLog_Msg("\n");

  PlacementLog_Msg("\tItem: ");
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetEnglish());
  PlacementLog_Msg("\n");

  //get an acessible gossip stone
  const std::vector<LocationKey> gossipStoneLocations = GetAccessibleGossipStones(hintedLocation);
  if (gossipStoneLocations.empty()) {
    PlacementLog_Msg("\tNO GOSSIP STONES TO PLACE HINT\n\n");
    return;
  }
  Location(hintedLocation)->SetAsHinted();
  LocationKey gossipStone = RandomElement(gossipStoneLocations);

  //form hint text
  /* CitraPrint("Checking location " + Location(hintedLocation)->GetName() + \
              "'s item which is " + Location(hintedLocation)->GetPlacedItemName().GetEnglish() + \
              " and GetItemID of " + Location(hintedLocation)->GetPlacedItem().GetItemId() + "\n"); 
  DebugPrint("Checking location %s's item which is %s and GetItemID of %#04x and hint text is %s\n", Location(hintedLocation)->GetName().c_str(), \
             Location(hintedLocation)->GetPlacedItemName().GetEnglish().c_str(), \
             Location(hintedLocation)->GetPlacedItem().GetItemId(), \
             Location(hintedLocation)->GetPlacedItem().GetHint().GetText().GetEnglish().c_str()); */
  Text itemText = Location(hintedLocation)->GetPlacedItem().GetHint().GetText();
  if (Location(hintedLocation)->IsDungeon()) {
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    Text locationText = AreaTable(parentRegion)->GetHint().GetText();
    // CitraPrint("Random Loc Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    Text finalHint = Hint(PREFIX).GetText()+"#"+locationText+"# "+Hint(HOARDS).GetText()+" #"+itemText+"#.";
    PlacementLog_Msg("\tMessage: ");
    PlacementLog_Msg(finalHint.english);
    PlacementLog_Msg("\n\n");
    AddHint(finalHint, gossipStone, {QM_GREEN, QM_RED});
  } else {
    // CitraPrint("Random Loc Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(Location(hintedLocation)->GetParentRegionKey())->GetName());
    Text locationText = GetHintRegion(Location(hintedLocation)->GetParentRegionKey())->GetHint().GetText();
    Text finalHint = Hint(PREFIX).GetText()+"#"+itemText+"# "+Hint(CAN_BE_FOUND_AT).GetText()+" #"+locationText+"#.";
    PlacementLog_Msg("\tMessage: ");
    PlacementLog_Msg(finalHint.english);
    PlacementLog_Msg("\n\n");
    AddHint(finalHint, gossipStone, {QM_RED, QM_GREEN});
  }
}

static void CreateGoodItemHint() {
  CreateRandomLocationHint(true);
}

static void CreateJunkHint() {
  //duplicate junk hints are possible for now
  const HintText junkHint = RandomElement(GetHintCategory(HintCategory::Junk));

  LogicReset();
  const std::vector<LocationKey> gossipStones = GetAccessibleLocations(gossipStoneLocations);
  if (gossipStones.empty()) {
    PlacementLog_Msg("\tNO GOSSIP STONES TO PLACE HINT\n\n");
    return;
  }
  LocationKey gossipStone = RandomElement(gossipStones);
  Text hint = junkHint.GetText();

  PlacementLog_Msg("\tMessage: ");
  PlacementLog_Msg(hint.english);
  PlacementLog_Msg("\n");

  PlacementLog_Msg("\tLocation: ");
  PlacementLog_Msg(Location(gossipStone)->GetName());
  PlacementLog_Msg("\n\n");

  AddHint(hint, gossipStone, {QM_RED});
}

static std::vector<LocationKey> CalculateBarrenRegions() {
  std::vector<LocationKey> barrenLocations = {};
  std::vector<LocationKey> potentiallyUsefulLocations = {};

  for (LocationKey loc : allLocations) {
    if (Location(loc)->GetPlacedItem().IsMajorItem()) {
      AddElementsToPool(potentiallyUsefulLocations, std::vector{loc});
    } else {
      if (loc != LINKS_POCKET) { //Nobody cares to know if Link's Pocket is barren
        AddElementsToPool(barrenLocations, std::vector{loc});
      }
    }
  }

  //leave only locations at barren regions in the list
  auto finalBarrenLocations = FilterFromPool(barrenLocations, [&potentiallyUsefulLocations](LocationKey loc){
    for (LocationKey usefulLoc : potentiallyUsefulLocations) {
      HintKey barrenKey = GetHintRegion(Location(loc)->GetParentRegionKey())->hintKey;
      HintKey usefulKey = GetHintRegion(Location(usefulLoc)->GetParentRegionKey())->hintKey;
      if (barrenKey == usefulKey) {
        return false;
      }
    }
    return true;
  });

  return finalBarrenLocations;
}

void CreateTingleHintText() {
  // Create custom messages for Tingle items if we shuffled.
      if (Settings::ShuffleTingleMaps.Is(true)) {
        // Logic: Get item names from location.
        // Create custom message for each tingle location (6)
        std::string clockTownMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_CT)->GetPlacedItemKey()).GetName().GetEnglish();
        std::string woodfallMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_WF)->GetPlacedItemKey()).GetName().GetEnglish();
        std::string snowHeadMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_SH)->GetPlacedItemKey()).GetName().GetEnglish();
        std::string romaniMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_RR)->GetPlacedItemKey()).GetName().GetEnglish();
        std::string greatBayMap = ItemTable(Location(TINGLE_GBC_GB)->GetPlacedItemKey()).GetName().GetEnglish();
        std::string stoneTowerMap = ItemTable(Location(TINGLE_GBC_ST)->GetPlacedItemKey()).GetName().GetEnglish();
        
        CustomMessages::CreateMessage(0x1D11, 0xFFFF, 0x3FF0A005, 0xFF1001,
        clockTownMap.insert(0, "#").append("#    #5 Rupees#&").append(woodfallMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
        clockTownMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_CT)->GetPlacedItemKey()).GetName().GetEnglish();
        woodfallMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_WF)->GetPlacedItemKey()).GetName().GetEnglish();

        CustomMessages::CreateMessage(0x1D12, 0xFFFF, 0x3FF0A014, 0xFF1001,
        woodfallMap.insert(0, "#").append("#    #20 Rupees#&").append(snowHeadMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
        woodfallMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_WF)->GetPlacedItemKey()).GetName().GetEnglish();
        snowHeadMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_SH)->GetPlacedItemKey()).GetName().GetEnglish();

        CustomMessages::CreateMessage(0x1D13, 0xFFFF, 0x3FF0A014, 0xFF1001,
        snowHeadMap.insert(0, "#").append("#    #20 Rupees#&").append(romaniMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
        snowHeadMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_SH)->GetPlacedItemKey()).GetName().GetEnglish();
        romaniMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_RR)->GetPlacedItemKey()).GetName().GetEnglish();

        CustomMessages::CreateMessage(0x1D14, 0xFFFF, 0x3FF0A014, 0xFF1001,
        romaniMap.insert(0, "#").append("#    #20 Rupees#&").append(greatBayMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
        romaniMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_RR)->GetPlacedItemKey()).GetName().GetEnglish();
        greatBayMap = ItemTable(Location(TINGLE_GBC_GB)->GetPlacedItemKey()).GetName().GetEnglish();

        CustomMessages::CreateMessage(0x1D15, 0xFFFF, 0x3FF0A014, 0xFF1001,
        greatBayMap.insert(0, "#").append("#    #20 Rupees#&").append(stoneTowerMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
        greatBayMap = ItemTable(Location(TINGLE_GBC_GB)->GetPlacedItemKey()).GetName().GetEnglish();
        stoneTowerMap = ItemTable(Location(TINGLE_GBC_ST)->GetPlacedItemKey()).GetName().GetEnglish();

        CustomMessages::CreateMessage(0x1D16, 0xFFFF, 0x3FF0A014, 0xFF1001,
        stoneTowerMap.insert(0, "#").append("#    #20 Rupees#&").append(clockTownMap.insert(0, "#").c_str()).append("#     #40 Rupees#").append("&#No thanks#").c_str(),
        {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false);
      }
}
//Find the location which has the given itemKey and create the generic altar text for the reward

/*static Text BuildDungeonRewardText(ItemID itemID, const ItemKey itemKey) {
  LocationKey location = FilterFromPool(allLocations, [itemKey](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == itemKey;})[0];
  //Calling ITEM_OBTAINED draws the passed in itemID to the left side of the textbox
  return Text()+ITEM_OBTAINED(itemID)+"#"+GetHintRegion(Location(location)->GetParentRegionKey())->GetHint().GetText()+"#...^";
}*/

static std::string BuildDoorText(const ItemKey itemKey) {
  LocationKey location = FilterFromPool(allLocations, [itemKey](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == itemKey;})[0];
  return "#"+GetHintRegion(Location(location)->GetParentRegionKey())->GetHint().GetText().GetEnglish()+"#.";
}

void CreateClockTowerDoorHints() {
  // Create hint text
  std::string ocarinaHint   = "Hey, didn't you have some sort of #musical instrument#?&If I know the Skull Kid, I bet he hid it at "+BuildDoorText(OCARINA_OF_TIME);
  std::string odolwaHint    = "There's one with a #crown# and #jewellery# said to be found at "+BuildDoorText(ODOLWAS_REMAINS);
  std::string gohtHint      = "Another #extremely sturdy# one with #huge horns# at "+BuildDoorText(GOHTS_REMAINS);
  std::string gyorgHint     = "One with #giant fins# and #razor sharp teeth# at "+BuildDoorText(GYORGS_REMAINS);
  std::string twinmoldHint  = "And one with #three eyes# and #enormous mandibles# at "+BuildDoorText(TWINMOLDS_REMAINS);

  CustomMessages::CreateMessage(0x0630, (StartingOcarina.Value<u8>() == 0) ? 0x8000 : 0x8002, 0x3FFFFFFF, 0x0FF0211,
    "Rooftop access strictly prohibited!&(Enforceable until #midnight# on the&#eve# of the carnival.)^"
    "#Notice of carnival activities:#&Musical Performance Contest&Unique Mask Contest&#Prizes available!#",
    {QM_RED, QM_RED, QM_RED, QM_MAGENTA}, {}, {}, 0x0, false, false);
  CustomMessages::CreateMessage(0x8000, 0x8001, 0x3FFFFFFF, 0x1000000, ocarinaHint.c_str(), {QM_BLUE, QM_RED}, {}, {}, 0x037C, false, false);
  CustomMessages::CreateMessage(0x8001, 0x8003, 0x3FFFFFFF, 0x1FF0000,
    "Also, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
    {QM_RED, QM_RED}, {}, {}, 0x0, false, false);
  CustomMessages::CreateMessage(0x8002, 0x8003, 0x3FFFFFFF, 0x1FF0000,
    "Hey, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
    {QM_RED, QM_RED}, {}, {}, 0x037C, false, false);
  CustomMessages::CreateMessage(0x8003, 0x8004, 0x3FFFFFFF, 0x15D0000, odolwaHint.c_str(), {QM_GREEN, QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);
  CustomMessages::CreateMessage(0x8004, 0x8005, 0x3FFFFFFF, 0x15E0000, gohtHint.c_str(), {QM_MAGENTA, QM_MAGENTA, QM_RED}, {}, {}, 0x0, false, false);
  CustomMessages::CreateMessage(0x8005, 0x8006, 0x3FFFFFFF, 0x15F0000, gyorgHint.c_str(), {QM_CYAN, QM_CYAN, QM_RED}, {}, {}, 0x0, false, false);
  CustomMessages::CreateMessage(0x8006, 0xFFFF, 0x3FFFFFFF, 0x0600000, twinmoldHint.c_str(), {QM_YELLOW, QM_YELLOW, QM_RED}, {}, {}, 0x0, false, false);
}

//insert the required number into the hint and set the singular/plural form
/*
static Text BuildCountReq(const HintKey req, const Option& count) {
  Text requirement = Hint(req).GetTextCopy();
  if (count.Value<u8>() == 1) {
    requirement.SetForm(SINGULAR);
  } else {
    requirement.SetForm(PLURAL);
  }
  requirement.Replace("%d", std::to_string(count.Value<u8>()));
  return requirement;
}
*/
void CreateAllHints() {

  //CreateGanonText();

  PlacementLog_Msg("\nNOW CREATING HINTS\n");
  const HintSetting& hintSetting = hintSettingTable[Settings::HintDistribution.Value<u8>()];

  u8 remainingDungeonWothHints = hintSetting.dungeonsWothLimit;
  u8 remainingDungeonBarrenHints = hintSetting.dungeonsBarrenLimit;

  // Add 'always' location hints
  if (hintSetting.distTable[static_cast<int>(HintType::Always)].copies > 0) {
    // Only filter locations that had a random item placed at them (e.g. don't get cow locations if shuffle cows is off)
    const auto alwaysHintLocations = FilterFromPool(allLocations, [](const LocationKey loc){
        return Location(loc)->GetHint().GetType() == HintCategory::Always &&
               Location(loc)->IsHintable()        && !(Location(loc)->IsHintedAt());
    });
    for (LocationKey location : alwaysHintLocations) {
      CreateLocationHint({location});
    }
  }


  //create a vector with each hint type proportional to it's weight in the distribution setting.
  //ootr uses a weighted probability function to decide hint types, but selecting randomly from
  //this vector will do for now
  std::vector<HintType> remainingHintTypes = {};
  for (HintDistributionSetting hds : hintSetting.distTable) {
    remainingHintTypes.insert(remainingHintTypes.end(), hds.weight, hds.type);
  }
  Shuffle(remainingHintTypes);

  //get barren regions
  auto barrenLocations = CalculateBarrenRegions();

  //while there are still gossip stones remaining
  while (FilterFromPool(gossipStoneLocations, [](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == NONE;}).size() != 0) {
    //TODO: fixed hint types

    if (remainingHintTypes.empty()) {
      break;
    }

    //get a random hint type from the remaining hints
    HintType type = RandomElement(remainingHintTypes, true);
    PlacementLog_Msg("Attempting to make hint of type: ");
    PlacementLog_Msg(std::to_string(static_cast<int>(type)));
    PlacementLog_Msg("\n");

    //create the appropriate hint for the type
    if (type == HintType::Woth) {
      CreateWothHint(&remainingDungeonWothHints);

    } else if (type == HintType::Barren) {
      CreateBarrenHint(&remainingDungeonBarrenHints, barrenLocations);

    } else if (type == HintType::Sometimes){
      std::vector<LocationKey> sometimesHintLocations = FilterFromPool(allLocations, [](const LocationKey loc){return Location(loc)->GetHint().GetType() == HintCategory::Sometimes && Location(loc)->IsHintable() && !(Location(loc)->IsHintedAt());});
      CreateLocationHint(sometimesHintLocations);

    } else if (type == HintType::Random) {
      CreateRandomLocationHint();

    } else if (type == HintType::Item) {
      CreateGoodItemHint();

    } else if (type == HintType::Song){
      std::vector<LocationKey> songHintLocations = FilterFromPool(allLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cSong) && Location(loc)->IsHintable() && !(Location(loc)->IsHintedAt());});
      CreateLocationHint(songHintLocations);

    } else if (type == HintType::Overworld){
      std::vector<LocationKey> overworldHintLocations = FilterFromPool(allLocations, [](const LocationKey loc){return Location(loc)->IsOverworld() && Location(loc)->IsHintable() && !(Location(loc)->IsHintedAt());});
      CreateLocationHint(overworldHintLocations);

    } else if (type == HintType::Dungeon){
      std::vector<LocationKey> dungeonHintLocations = FilterFromPool(allLocations, [](const LocationKey loc){return Location(loc)->IsDungeon() && Location(loc)->IsHintable() && !(Location(loc)->IsHintedAt());});
      CreateLocationHint(dungeonHintLocations);

    } else if (type == HintType::Junk) {
      CreateJunkHint();
    }
  }

  //If any gossip stones failed to have a hint placed on them for some reason, place a junk hint as a failsafe.
  for (LocationKey gossipStone : FilterFromPool(gossipStoneLocations, [](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == NONE;})) {
    const HintText junkHint = RandomElement(GetHintCategory(HintCategory::Junk));
    AddHint(junkHint.GetText(), gossipStone, {QM_RED});
  }

  //Getting gossip stone locations temporarily sets one location to not be reachable.
  //Call the function one last time to get rid of false positives on locations not
  //being reachable.
  GetAccessibleLocations({});

  
}
