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
  // CitraPrint("Our hint text is " + hint.GetNAEnglish());
  if (hint.GetNAEnglish().find("$")) {
    icons.push_back(B_BUTTON);
  }
  CustomMessages::CreateMessageFromTextObject(messageId, 0xFFFF, 0x3FFFFFFF, 0xFF0020, hint, colors, icons, {}, 0x0, false, false, MESSAGE_END_NORMAL);
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
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetNAEnglish());
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
  PlacementLog_Msg(finalHint.NAenglish);
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
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetNAEnglish());
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
  PlacementLog_Msg(finalWothHint.NAenglish);
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
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetNAEnglish());
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
  PlacementLog_Msg(finalBarrenHint.NAenglish);
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
  PlacementLog_Msg(Location(hintedLocation)->GetPlacedItemName().GetNAEnglish());
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
              "'s item which is " + Location(hintedLocation)->GetPlacedItemName().GetNAEnglish() + \
              " and GetItemID of " + Location(hintedLocation)->GetPlacedItem().GetItemId() + "\n"); 
  DebugPrint("Checking location %s's item which is %s and GetItemID of %#04x and hint text is %s\n", Location(hintedLocation)->GetName().c_str(), \
             Location(hintedLocation)->GetPlacedItemName().GetNAEnglish().c_str(), \
             Location(hintedLocation)->GetPlacedItem().GetItemId(), \
             Location(hintedLocation)->GetPlacedItem().GetHint().GetText().GetNAEnglish().c_str()); */
  Text itemText = Location(hintedLocation)->GetPlacedItem().GetHint().GetText();
  if (Location(hintedLocation)->IsDungeon()) {
    AreaKey parentRegion = Location(hintedLocation)->GetParentRegionKey();
    Text locationText = AreaTable(parentRegion)->GetHint().GetText();
    // CitraPrint("Random Loc Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(parentRegion)->GetName());
    Text finalHint = Hint(PREFIX).GetText()+"#"+locationText+"# "+Hint(HOARDS).GetText()+" #"+itemText+"#.";
    PlacementLog_Msg("\tMessage: ");
    PlacementLog_Msg(finalHint.NAenglish);
    PlacementLog_Msg("\n\n");
    AddHint(finalHint, gossipStone, {QM_GREEN, QM_RED});
  } else {
    // CitraPrint("Random Loc Hint: Getting " + Location(hintedLocation)->GetName() + "'s parent region which is " + Location(Location(hintedLocation)->GetParentRegionKey())->GetName());
    Text locationText = GetHintRegion(Location(hintedLocation)->GetParentRegionKey())->GetHint().GetText();
    Text finalHint = Hint(PREFIX).GetText()+"#"+itemText+"# "+Hint(CAN_BE_FOUND_AT).GetText()+" #"+locationText+"#.";
    PlacementLog_Msg("\tMessage: ");
    PlacementLog_Msg(finalHint.NAenglish);
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
  PlacementLog_Msg(hint.NAenglish);
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
        Text clockTownMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_CT)->GetPlacedItemKey()).GetName();
        Text woodfallMap = ItemTable(Location(TINGLE_N_CLOCK_TOWN_WF)->GetPlacedItemKey()).GetName();
        Text snowHeadMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_SH)->GetPlacedItemKey()).GetName();
        Text romaniMap = ItemTable(Location(TINGLE_TWIN_ISLANDS_RR)->GetPlacedItemKey()).GetName();
        Text greatBayMap = ItemTable(Location(TINGLE_GBC_GB)->GetPlacedItemKey()).GetName();
        Text ikanaMap = ItemTable(Location(TINGLE_GBC_ST)->GetPlacedItemKey()).GetName();

        //                 {"English",           "French",           "Spanish"            "German"          };      "Italian"
        Text priceFive =   {"    ##5 Rupees#&#",  "    ##5 Rubis#&#",  "    ##5 rupias#&#",  " - ##5 Rubine#&#" }; // , "    ##5 rupie#&"
        Text priceTwenty = {"    ##20 Rupees#&#", "    ##20 Rubis#&#", "    ##20 rupias#&#", " - ##20 Rubine#&#"}; // , "    ##20 rupie#&"
        Text priceForty =  {"    ##40 Rupees#",  "    ##40 Rubis#",  "    ##40 rupias#",  " - ##40 Rubine#" }; // , "    ##40 rupie#"
        Text leaveShop =   {"&#No thanks#",      "&#Non merci#",     "&#No, gracias#",    "&#Nein, danke!#" }; // , "&#No, grazie#"

        // Clock Town message
        CustomMessages::CreateMessageFromTextObject(0x1D11, 0xFFFF, 0x3FF0A005, 0xFF1001,
          Text{">3#"}+clockTownMap+priceFive+woodfallMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);

        // Woodfall message
        CustomMessages::CreateMessageFromTextObject(0x1D12, 0xFFFF, 0x3FF0A014, 0xFF1001,
          Text{">3#"}+woodfallMap+priceTwenty+snowHeadMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);

        // Snowhead message
        CustomMessages::CreateMessageFromTextObject(0x1D13, 0xFFFF, 0x3FF0A014, 0xFF1001,
          Text{">3#"}+snowHeadMap+priceTwenty+romaniMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);

        // Milk Road message
        CustomMessages::CreateMessageFromTextObject(0x1D14, 0xFFFF, 0x3FF0A014, 0xFF1001,
          Text{">3#"}+romaniMap+priceTwenty+greatBayMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);

        // Great Bay message
        CustomMessages::CreateMessageFromTextObject(0x1D15, 0xFFFF, 0x3FF0A014, 0xFF1001,
          Text{">3#"}+greatBayMap+priceTwenty+ikanaMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);

        // Ikana message
        CustomMessages::CreateMessageFromTextObject(0x1D16, 0xFFFF, 0x3FF0A014, 0xFF1001,
          Text{">3#"}+ikanaMap+priceTwenty+clockTownMap+priceForty+leaveShop,
          {QM_GREEN, QM_RED, QM_GREEN, QM_RED, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);
      }
}

void CreateShopMessage(u16 messageID, ItemKey shopItem, u16 buyingPrice, bool isRepeatable) {
  Text itemName = ItemTable(shopItem).GetName();
  Text shopIntro = Text{"#"}+itemName+Text{
      "&>>"
      // itemName.NAenglish.length()  <= 30 ?  ": " : "&>>",
      // itemName.NAfrench.length()   <= 30 ? " : " : "&>>",
      // itemName.NAspanish.length()  <= 30 ?  ": " : "&>>",
      // itemName.EURgerman.length()  <= 30 ?  ": " : "&>>",
      // // itemName.EURitalian.length() <= 30 ?  ": " : "&>>",
      // itemName.EURenglish.length() <= 30 ?  ": " : "&>>",
      // itemName.EURfrench.length()  <= 30 ? " : " : "&>>",
      // itemName.EURspanish.length() <= 30 ?  ": " : "&>>",
    }+std::to_string(buyingPrice)+Text{
      " Rupees#&", " rubis#&", " rupias#&", " Rubine#&",// " rupie#&"
    };
  Text shopDescription = {"oops"};
  if ((messageID < 0x06C9) || (messageID > 0x06D8)) {
    // Regular shop
    if (isRepeatable) {
      shopDescription = {
        /*NaEnglish*/"Special deal!&Buy as many as you want!",
        /*NaFrench */"Offre spéciale!&Achetez-en à volonté!",
        /*NaSpanish*/"¡Oferta especial!&¡Compra todo lo que quieras!",
        /*EuGerman */"Sonderangebot!&Kauft so viel ihr wollt!",
        // /*EuItalian*/"Offerta speciale!&Compratene a volontà!",
        /*EuEnglish*/"",
        /*EuFrench */"Offre spéciale !&Achetez-en à volonté !",
        /*EuSpanish*/"",
      };
    } else {
      shopDescription = {
        /*NaEnglish*/"Special deal! ONE LEFT!&Get it while it lasts!",
        /*NaFrench */"Offre spéciale! DERNIER EN STOCK!&Maintenant ou jamais!",
        /*NaSpanish*/"¡Oferta especial! ¡SOLO QUEDA UNA UNIDAD!&¡Hazte con ella antes de que se agote!",
        /*EuGerman */"Sonderangebot! NUR EINS AUF LAGER!&Schlagt zu solange ihr noch könnt!",
        // /*EuItalian*/"Offerta speciale! ULTIMO PEZZO!&Affrettatevi ad aquistarlo!",
        /*EuEnglish*/"",
        /*EuFrench */"Offre spéciale ! DERNIER EN STOCK !&Maintenant ou jamais !",
        /*EuSpanish*/"",
      };
    }
  } else {
    // Trading post part-timer
    if (isRepeatable) {
      shopDescription = {
        /*English*/"Pretty sure we've got a bunch.&Oh and it's, like, a special deal.",
        /*French */"On doit en avoir un tas dans le stock.&Ah oui, et c'est une offre spéciale.",
        /*Spanish?*/"¡Oferta especial!&¡Compra todo lo que quieras!",
        /*German ?*/"Sonderangebot!&Kauft so viel ihr wollt!",
        // /*Italian?*/"Offerta speciale!&Compratene a volontà!",
      };
    } else {
      shopDescription = {
        /*English*/"This one's a special deal, and uh,&I think we only have the one...",
        /*French */"C't'un genre d'offre spéciale, ouais.&Et j'crois qu'c'est tout ce qu'on a...",
        /*Spanish?*/"¡Oferta especial! ¡SOLO QUEDA UNA UNIDAD!&¡Hazte con ella antes de que se agote!",
        /*German ?*/"Sonderangebot! NUR EINS AUF LAGER!&Schlagt zu solange ihr noch könnt!",
        // /*Italian?*/"Offerta speciale! ULTIMO PEZZO!&Affrettatevi ad aquistarlo!",
      };
    }
  }

  CustomMessages::CreateMessageFromTextObject(messageID, 0xFFFF, (0x3FFFFC00 | buyingPrice), 0xFF0301,
    shopIntro+shopDescription, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_ENDLESS);
  // Handle blue potion variant for mushroomless hag
  // WILL OVERFLOW IN MOST LANGUAGES WHEN ITEM NAME TRIGGERS LINE BREAK
  if (messageID == 0x0843) {
    CustomMessages::CreateMessageFromTextObject(0x0880, 0xFFFF, (0x3FFFFC00 | buyingPrice), 0xFF0301,
      shopIntro+Text{
        /*NaEnglish*/"Actually, I can't get the ingredients&for this, so I'm sold out. Sorry.",
        /*NaFrench */"En fait, je n'arrive pas à trouver&les ingrédients pour ça, alors je&n'en ai plus. Désolée.",
        /*NaSpanish*/"No puedo conseguir los&ingredientes, así que está&agotada. Lo siento.",
        /*EuGerman */"Leider habe ich nicht die passenden&Zutaten auf Lager, daher ist dieser&Artikel gerade nicht lieferbar.",
        // /*EuItalian*/"In realtà, questa pozione è esaurita&e non ho gli ingredienti per&prepararne altra. Mi spiace.",
        /*EuEnglish*/"",
        /*EuFrench */"",
        /*EuSpanish*/"En realidad, no puedo conseguir&los ingredientes para esto, así que&no me queda más. Lo siento.",
      }, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_ENDLESS);
  }

  CustomMessages::CreateMessageFromTextObject(messageID + 1, 0xFFFF, (0x3FFFFC00 | buyingPrice), 0xFF1301,
    shopIntro+">2"+Text{
      /*English*/"#Buy&Don't Buy#",
      /*French */"#J'achète&J'achète pas#",
      /*Spanish*/"#Comprar&No comprar#",
      /*German */"#Kaufen!&Nicht kaufen!#",
      // /*Italian*/"#Compra&Non comprare#",
    }, {QM_WHITE, QM_GREEN}, {}, {}, 0x0, false, false, MESSAGE_END_NULL);
}

void CreateOtherHints() {
  // Create other hints for various texts

  //Bank Reward 1 hint (Vanilla Wallet)
  CustomMessages::CreateMessageFromTextObject(0x044D, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"For example, if you deposit #200 Rupees#, you'll get #",
    /*French*/"Par exemple, si tu déposes #200 rubis#, je te donnerai #",
    /*Spanish*/"Por ejemplo, si depositas #200 rupias#, te entregaré #",
    /*German ?*/"Wenn du zum Beispiel #200 Rubine# sparst, gebe ich dir #",
    // /*Italian?*/"Per esempio, se depositi #200 rupie#, otterrai #",
  }+ItemTable(Location(S_CLOCK_TOWN_BANK_REWARD_1)->GetPlacedItemKey()).GetHint().GetText()
  +"#.", {QM_RED, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_EVENTNEXT);

  //Termina Field Deku Salesman Heart Piece
  CustomMessages::CreateMessageFromTextObject(0x1631, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"Please! I'll sell you #",
    /*French*/"OK, je te vends #",
    /*Spanish?*/"¡Por favor! Le venderé #",
    /*German ?*/"Oh, bitte! Ich verkaufe dir #",
    // /*Italian?*/"Ti prego! Ti vendo #",
  }+ItemTable(Location(TERMINA_FIELD_BUSINESS_SCRUB)->GetPlacedItemKey()).GetHint().GetText()+Text{
    /*English*/"# if you just keep this place a secret...",
    /*French*/"# si tu gardes le secret de cet endroit.",
    /*Spanish*/"# si mantiene este lugar en secreto...",
    /*German ?*/"#, aber bitte behalte dieses Geheimnis für dich!",
    // /*Italian?*/"# se mantieni il segreto su questo posto...",
  }, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_EVENTNEXT);

  //Beaver Hints
  Text beaverBottleHint = ItemTable(Location(ZORA_CAPE_BEAVER_RACE_1)->GetPlacedItemKey()).GetHint().GetText();

  CustomMessages::CreateMessageFromTextObject(0x10CF, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"You want #",
    /*French */"Tu veux #",
    /*Spanish?*/"Quieres #",
    /*German ?*/"Du willst doch #",
    // /*Italian?*/"Vuoi #",
  }+beaverBottleHint+Text{
    /*NaEnglish*/"#, don't you? You never learn your lesson!",
    /*NaFrench */"#, c'est ça? Tu n'apprends jamais ta leçon!",
    /*NaSpanish?*/"#, ¿verdad? ¡Nunca aprenderás la lección!",
    /*EuGerman ?*/"#, nicht wahr? Hast du deine Lektion noch immer nicht gelernt?",
    // /*EuItalian?*/"#, eh? Non impari mai!",
    /*EuEnglish*/"",
    /*EuFrench */"#, c'est ça ?&Tu ne retiens jamais la leçon !",
    /*EuSpanish*/"",
  }, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);
  CustomMessages::CreateMessageFromTextObject(0x10D0, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"Koo, koo, koo...&OK. But...",
    /*French */"Kii, kii, kii.&OK. Mais...",
    /*Spanish?*/"Cu, cu, cu.&Muy bien. Pero...",
    /*German ?*/"Quiek, quiek, quiek!&Okay. Aber...",
    // /*Italian?*/"Uh uh uh.&Va bene. Ma...",
  }, {}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);

  CustomMessages::CreateMessageFromTextObject(0x10D4, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"Koo, koo, koo.&I can give you #",
    /*French */"Kii, kii, kii.&Je peux te donner #",
    /*Spanish?*/"Cu, cu, cu.&Puedo darte #",
    /*German ?*/"Quiek, quiek, quiek. Kann ich dir eine geben #",
    // /*Italian?*/"Uh uh uh...&Posso dartela io #",
  }+beaverBottleHint+Text{
    /*English*/"#...^But only if you can swim through #all# the #rings# in the river in under #two minutes#.",
    /*French */"#...^Seulement si tu peux passer à&travers #tous# les #anneaux# sous la&rivière en moins de #deux minutes#.",
    /*Spanish?*/"#...^Pero solo si puedes nadar a&través de todos los #anillos# del río&en menos de #dos minutos#.",
    /*German ?*/"#...^Aber nur, wenn du es schaffst, in&weniger als #zwei Minuten# durch&alle #Ringe# im Fluss zu schwimmen.**",
    // /*Italian?*/"#...^Ma solo se riesci a nuotare&attraverso tutti gli #anelli&#nel fiume #entro 2 minuti#.",
  }, {QM_RED, QM_RED, QM_RED, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);

  // Remove French mention of bottle
  CustomMessages::CreateMessage(0x10DD, 0xFFFF, 0x3FFFFFFF, 0xFF0000, {
    /*English*/"Uh... That was perfect.^That's not good...",
    /*French */"Ooh... Tu as parfaitement réussi...^C'est pas bon...",
    /*Spanish*/"Eh... Perfecto.^Esto no está bien...",
    /*German */"Uh... Das war perfekt!^Das ist gar nicht gut...",
    /*Italian*/"Uh... Sei stato perfetto.^Accidenti...",
  }, {}, {}, {}, 0x0, false, false, MESSAGE_END_EVENT);

  CustomMessages::CreateMessageFromTextObject(0x10E0, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*NaEnglish*/"What?&He wants #",
    /*NaFrench */"Quoi?&Il veut #",
    /*NaSpanish?*/"¿Qué?&¿#",
    /*EuGerman ?*/"Was?&#",
    // /*EuItalian?*/"Cosa?&#",
    /*EuEnglish*/"",
    /*EuFrench */"Quoi ?&Il veut #",
    /*EuSpanish*/"",
  }+beaverBottleHint+Text{
    /*NaEnglish*/"#?",
    /*NaFrench */"#?",
    /*NaSpanish*/"#?",
    /*EuGerman */"#?",
    // /*EuItalian*/"#?",
    /*EuEnglish*/"",
    /*EuFrench */"# ?",
    /*EuSpanish*/"",
  }, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);
  CustomMessages::CreateMessageFromTextObject(0x10E1, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"Yeah...&He Wants #",
    /*French */"Ouaip...&Il veut #",
    /*Spanish?*/"Sí...&#",
    /*German */"Ja...&#",
    // /*Italian*/"Sì...&#",
  }+beaverBottleHint+"#.", {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);
  CustomMessages::CreateMessage(0x10E3, 0xFFFF, 0x3FFFFFFF, 0xFF0000, {
    /*English*/"Look. That's really precious to us, so just beating my little brother isn't enough.",
    /*French */"Écoute. On tient beaucoup à ça, alors une simple victoire ne suffira pas.",
    // /*Spanish*/"**SPANISH**",
    // /*German */"**GERMAN**",
    // /*Italian*/"**ITALIAN**",
  }, {}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);
  CustomMessages::CreateMessage(0x10E4, 0xFFFF, 0x3FFFFFFF, 0xFF0000, {
    /*English*/"It's not enough.",
    /*French */"Ça suffit pas.",
    // /*Spanish*/"**SPANISH**",
    // /*German */"**GERMAN**",
    // /*Italian*/"**ITALIAN**",
  }, {}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);

  CustomMessages::CreateMessageFromTextObject(0x10F5, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"This time, we only have #",
    /*French */"Cette fois, on n'a plus que #",
    /*Spanish?*/"This time, we only have #",
    /*German ?*/"This time, we only have #",
    // /*Italian*/"**ITALIAN**#",
  }+ItemTable(Location(ZORA_CAPE_BEAVER_RACE_2)->GetPlacedItemKey()).GetHint().GetText()+Text{
    /*English*/"#... Right, Little Brother?",
    /*French */"#... Pas vrai, p'tit frère?",
    /*Spanish?*/"#... Right, Little Brother?",
    /*German ?*/"#... Right, Little Brother?",
    // /*Italian*/"#**ITALIAN**",
  }, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);
  CustomMessages::CreateMessage(0x10F6, 0xFFFF, 0x3FFFFFFF, 0xFF0000, {
    /*English*/"That's right, Big Brother...",
    /*French */"Ouaip, grand frère...",
    // /*Spanish*/"**SPANISH**",
    // /*German */"**GERMAN**",
    // /*Italian*/"**ITALIAN**",
  }, {}, {}, {}, 0x0, false, false, MESSAGE_END_NEXT);

  CustomMessages::CreateMessageFromTextObject(0x1240, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"You know the #beavers# above the #waterfall# are the type to have #empty bottles#, right?^Lately, they've been braggin about #",
    /*French */"Je t'ai parlé des #castors# qui vivent en haut de la #cascade#, non? Ils adorent les #flacons vides#.^Mais ces temps-ci, leur truc c'est #",
    /*Spanish?*/"You know the #beavers# above the #waterfall# are the type to have #empty bottles#, right?^Lately, they've been braggin about #",
    /*German ?*/"You know the #beavers# above the #waterfall# are the type to have #empty bottles#, right?^Lately, they've been braggin about #",
    // /*Italian?*/"You know the #beavers# above the #waterfall# are the type to have #empty bottles#, right?^Lately, they've been braggin about #",
  }+beaverBottleHint
  +"#.", {QM_RED, QM_RED, QM_RED, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_EVENT);

  CustomMessages::CreateMessageFromTextObject(0x1242, 0xFFFF, 0x3FFFFFFF, 0xFF0000, Text{
    /*English*/"And remember what I told you about the #beavers# above the #waterfall#.^It seems like they have #",
    /*French */"Et rappelle toi ce que j'ai dit sur les #castors# qui vivent en haut de la #cascade#.^Il paraît qu'ils ont #",
    /*Spanish?*/"And remember what I told you about the #beavers# above the #waterfall#.^It seems like they have #",
    /*German */"**GERMAN**#",
    // /*Italian*/"**ITALIAN**#",
  }+beaverBottleHint
  +"#.", {QM_RED, QM_RED, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_EVENT);
  


}

//Find the location which has the given itemKey and create the generic altar text for the reward

/*static Text BuildDungeonRewardText(ItemID itemID, const ItemKey itemKey) {
  LocationKey location = FilterFromPool(allLocations, [itemKey](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == itemKey;})[0];
  //Calling ITEM_OBTAINED draws the passed in itemID to the left side of the textbox
  return Text()+ITEM_OBTAINED(itemID)+"#"+GetHintRegion(Location(location)->GetParentRegionKey())->GetHint().GetText()+"#...^";
}*/

static Text BuildDoorText(const ItemKey itemKey) {
  LocationKey location = FilterFromPool(allLocations, [itemKey](const LocationKey loc){return Location(loc)->GetPlacedItemKey() == itemKey;})[0];
  if (Location(location)->GetParentRegionKey() == NONE) {
    Location(location)->SetParentRegion(LINKS_POCKET);
  }
  return Text{"#"}+GetHintRegion(Location(location)->GetParentRegionKey())->GetHint().GetText()+"#.";
}

void CreateClockTowerDoorHints() {
  // Determine which hint to display first
  u16 clockDoorFirstHint = 0x8002;
  if (StartingOcarina.Value<u8>() == 0) clockDoorFirstHint = 0x8000;
  else if (ShuffleSongOfTime) clockDoorFirstHint = 0x8001;

  // Create hint text
  Text ocarinaHint = Text{
    /*NaEnglish*/"Hey, didn't you have some sort of #musical instrument#?&If I know the Skull Kid, I bet he hid it at ",
    /*NaFrench */"Dis, t'avais pas un &#instrument de musique#?&Je parie que Skull Kid, l'a caché vers ",
    /*NaSpanish*/"**SPANISH** ",
    /*EuGerman */"Hey, hast du nicht eine Art #Musikinstrument#?&Wenn ich das Horror-Kid kenne, würde ich wetten, er versteckt es bei ",
    /*EuEnglish*/"",
    /*EuFrench */"Dis, t'avais pas un &#instrument de musique# ?&Je parie que Skull Kid, l'a caché vers ",
    /*EuSpanish*/"",
  }+BuildDoorText(OCARINA_OF_TIME);
  Text songTimeHint = Text{
    /*NaEnglish*/"How could you forget the #Song of Time#?&We'll need to relearn it in ",
    /*NaFrench */"T'as sérieusement oublié le #Chant du temps#?&Va falloir le réapprendre dans ",
    /*NaSpanish?*/"¿Cómo pudiste olvidar la #canción del tiempo#?&Vamos a necesitar aprenderla en ",
    /*EuGerman ?*/"How could you forget the #Song of Time#?&We'll need to relearn it in ",
    /*EuEnglish*/"",
    /*EuFrench */"T'as sérieusement oublié le #Chant du temps# ?&Va falloir le réapprendre dans ",
    /*EuSpanish*/"",
  }+BuildDoorText(SONG_OF_TIME);
  Text remainsPreHint = Text{
    /*English*/"Also, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
    /*French */"D'ailleurs, ce #concours de masques# me rappelle que j'ai entendu des rumeurs dans le coin sur des #masques très uniques#.",
    /*Spanish?*/"Also, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
    /*German */"Außerdem klingt dieser #Maskenwettbewerb# interessant! Ich habe Gerüchte über ziemlich #seltene Masken# hier in der Gegend gehört, echte Einzelstücke!",
  };
  if (clockDoorFirstHint == 0x8002) {
    remainsPreHint = Text{
      /*English*/"Hey, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
      /*French */"Dis, ce #concours de masques# me rappelle que j'ai entendu des rumeurs dans le coin sur des #masques très uniques#.",
      /*Spanish?*/"Hey, that #mask competition# sounds interesting! I've heard rumours of some pretty #rare masks# around here, truly one of a kind stuff!",
      /*German */"Hey, dieser #Maskenwettbewerb# klingt interessant! Ich habe Gerüchte über ziemlich #seltene Masken# hier in der Gegend gehört, echte Einzelstücke!",
    };
  }
  Text odolwaHint = Text{
    /*English*/"There's one with a #crown# and #jewellery# said to be found at ",
    /*French */"Y'en a un avec une #couronne# et des #bijoux# situé vers ",
    /*Spanish*/"**SPANISH** ",
    /*German */"Es gibt eine mit einer #Krone# und #Schmuck#, die man angeblich findet bei ",
  }+BuildDoorText(ODOLWAS_REMAINS);
  Text gohtHint = Text{
    /*English*/"Another #extremely sturdy# one with #huge horns# at ",
    /*French */"Un autre #très solide# avec des #cornes immenses# situé vers ",
    /*Spanish*/"**SPANISH** ",
    /*German */"Eine weitere #extrem robuste# mit #riesigen Hörnern# bei ",
  }+BuildDoorText(GOHTS_REMAINS);
  Text gyorgHint = Text{
    /*English*/"One with #giant fins# and #razor sharp teeth# at ",
    /*French */"Un qui a des #nageoires géantes# et #dents acérées# situé vers ",
    /*Spanish*/"**SPANISH** ",
    /*German */"Eine mit #riesigen Flossen# und #rasiermesserscharfen Zähnen# bei ",
  }+BuildDoorText(GYORGS_REMAINS);
  Text twinmoldHint = Text{
    /*English*/"And one with #three eyes# and #enormous mandibles# at ",
    /*French */"Et un avec #trois yeux# et d'#énormes mandibules# situé vers ",
    /*Spanish*/"**SPANISH** ",
    /*German */"Und eine mit #drei Augen# und #gewaltigen Mundwerkzeugen# bei ",
  }+BuildDoorText(TWINMOLDS_REMAINS);
  if (StartingOdolwaRemains.Value<u8>() == 1) {
    odolwaHint = Text{
      /*English*/"There's one with a #crown# and #jewellery# said to be found in ",
      /*French */"Y'en a un avec une #couronne# et des #bijoux# situé dans ",
      /*Spanish*/"**SPANISH** ",
      /*German */"Es gibt eine mit einer #Krone# und #Schmuck#, die man angeblich findet in ",
    }+BuildDoorText(ODOLWAS_REMAINS);
  }
  if (StartingGohtRemains.Value<u8>() == 1) {
    gohtHint = Text{
      /*English*/"Another #extremely sturdy# one with #huge horns# in ",
      /*French */"Un autre #très solide# avec des #cornes immenses# situé dans ",
      /*Spanish*/"**SPANISH** ",
      /*German */"Eine weitere #extrem robuste# mit #riesigen Hörnern# in ",
    }+BuildDoorText(GOHTS_REMAINS);
  }
  if (StartingGyorgRemains.Value<u8>() == 1) {
    gyorgHint = Text{
      /*English*/"One with #giant fins# and #razor sharp teeth# in ",
      /*French */"Un qui a des #nageoires géantes# et #dents acérées# situé dans ",
      /*Spanish*/"**SPANISH** ",
      /*German */"Eine mit #riesigen Flossen# und #rasiermesserscharfen Zähnen# in ",
    }+BuildDoorText(GYORGS_REMAINS);
  }
  if (StartingTwinmoldRemains.Value<u8>() == 1){
    twinmoldHint = Text{
      /*English*/"And one with #three eyes# and #enormous mandibles# in ",
      /*French */"Et un avec #trois yeux# et d'#énormes mandibules# situé dans ",
      /*Spanish*/"**SPANISH** ",
      /*German */"Und eine mit #drei Augen# und #gewaltigen Mundwerkzeugen# in ",
    }+BuildDoorText(TWINMOLDS_REMAINS);
  }
  Text remainsNeededHint = {
    /*English*/"The rumours say having #all four# causes something good to happen.",
    /*French */"D'après les rumeurs, si on a #les quatre#, un truc bien va se produire.",
    /*Spanish*/"**SPANISH_4_REMAINS_NEEDED**",
    /*German */"Den Gerüchten zufolge sorgen #alle vier# dafür, dass etwas Gutes passiert.",
    };
  switch (4 - MoonRemainsRequired.Value<u8>()) {
    case 0:
      remainsNeededHint = {
      /*English*/"I think collecting them would just be a #waste of time# though.",
      /*French */"Mais à mon avis, les collectionner ne serait qu'une #perte de temps#.",
      /*Spanish*/"**SPANISH_0_REMAINS_NEEDED**",
      /*German */"Ich denke aber, sie zu sammeln wäre nur #Zeitverschwendung#.",
      };
      break;
    case 1:
      remainsNeededHint = {
      /*English*/"The rumours say having #just one# is enough to make something good happen.",
      /*French */"D'après les rumeurs, il suffit d'en avoir #un seul# pour qu'un truc bien se produise.",
      /*Spanish*/"**SPANISH_1_REMAINS_NEEDED**",
      /*German */"Den Gerüchten zufolge reicht schon #eine einzige#, damit etwas Gutes passiert.",
      };
      break;
    case 2:
      remainsNeededHint = {
      /*English*/"The rumours say having #half of them# causes something good to happen.",
      /*French */"D'après les rumeurs, si on en a #la moitié#, un truc bien va se produire.",
      /*Spanish*/"**SPANISH_2_REMAINS_NEEDED**",
      /*German */"Den Gerüchten zufolge sorgt #die Hälfte von ihnen# dafür, dass etwas Gutes passiert.",
      };
      break;
    case 3:
      remainsNeededHint = {
      /*English*/"The rumours say having #three of them# causes something good to happen.",
      /*French */"D'après les rumeurs, si on en a #trois#, un truc bien va se produire.",
      /*Spanish*/"**SPANISH_3_REMAINS_NEEDED**",
      /*German */"Den Gerüchten zufolge sorgen #drei von ihnen# dafür, dass etwas Gutes passiert.",
      };
      break;
  }

  CustomMessages::CreateMessage(0x0630, clockDoorFirstHint, 0x3FFFFFFF, 0x0FF0211,
    {"Rooftop access strictly prohibited!&(Enforceable until #midnight# on the&#eve# of the carnival.)^"
    "#Notice of carnival activities:#&Musical Performance Contest&Unique Mask Contest&#Prizes available!#",
      // French
      "Accès aux toits strictement&interdit jusqu'à #minuit#, la&#veille #du carnaval.^"
      "#Notice d'activités du carnaval:#&Concours de performance musicale&Concours de masques singuliers&#Prix à la clé!#",
      // Spanish
      "Acceso al tejado.&¡Prohibida la entrada hasta&la #medianoche de la víspera&#del carnaval!^"
      "**SPANISH**",
      // German
      "Zugang zum Dach&Betreten streng verboten!&(bis um #Mitternacht# am&Vorabend des #Karnevals#)^"
      "#Hinweise zum Karnevalsprogramm:#&Musik-Wettbewerb&Wettbewerb: Die originellste Maske&#Tolle Preise zu gewinnen!#",
      // // Italian
      // "Porta del tetto&Ingresso vietato fino alla&#mezzanotte# della #vigilia# del&carnevale.^"
      // "**ITALIAN**",
    },
    {QM_RED, QM_RED, QM_RED, QM_MAGENTA}, {}, {}, 0x0, false, false, MESSAGE_END_NORMAL);
  CustomMessages::CreateMessageFromTextObject(0x8000, ShuffleSongOfTime ? 0x8001 : 0x8002, 0x3FFFFFFF, 0x000000, ocarinaHint, {QM_BLUE, QM_RED}, {}, {}, 0x083E, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8001, 0x8002, 0x3FFFFFFF, 0x000000, songTimeHint, {QM_BLUE, QM_RED}, {}, {}, (clockDoorFirstHint == 0x8001) ? 0x083E : 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8002, 0x8003, 0x3FFFFFFF, 0xFF0000, remainsPreHint, {QM_RED, QM_RED}, {}, {}, (clockDoorFirstHint == 0x8002) ? 0x083E : 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8003, 0x8004, 0x3FFFFFFF, 0x5D0000, odolwaHint, {QM_GREEN, QM_GREEN, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8004, 0x8005, 0x3FFFFFFF, 0x5E0000, gohtHint, {QM_MAGENTA, QM_MAGENTA, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8005, 0x8006, 0x3FFFFFFF, 0x5F0000, gyorgHint, {QM_CYAN, QM_CYAN, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8006, 0x8007, 0x3FFFFFFF, 0x600000, twinmoldHint, {QM_YELLOW, QM_YELLOW, QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_PSEUDO);
  CustomMessages::CreateMessageFromTextObject(0x8007, 0xFFFF, 0x3FFFFFFF, 0xFF0000, remainsNeededHint, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NORMAL);
}

void CreateMoonChildHint() {
  // Create textbox with main hint
  Text moonChildHint = {
    /*English*/"^Come back with &#four Bosses' Remains#...",
    /*French */"^Reviens avec les &#restes de quatre boss#...",
    /*Spanish*/"^**SPANISH_4_REMAINS_NEEDED**",
    /*German */"^Komm wieder mit den &#Vermächtnissen von vier Endgegnern#...",
    };
  switch (4 - MajoraRemainsRequired.Value<u8>()) {
    case 1:
      moonChildHint = {
      /*English*/"^Come back with &#one Boss's Remains#...",
      /*French */"^Reviens avec les &#restes d'un boss#...",
      /*Spanish*/"^**SPANISH_1_REMAINS_NEEDED**",
      /*German */"^Komm wieder mit dem &#Vermächtnis eines Endgegners#...",
      };
      break;
    case 2:
      moonChildHint = {
      /*English*/"^Come back with &#two Bosses' Remains#...",
      /*French */"^Reviens avec les &#restes de deux boss#...",
      /*Spanish*/"^**SPANISH_2_REMAINS_NEEDED**",
      /*German */"^Komm wieder mit den &#Vermächtnissen von zwei Endgegnern#...",
      };
      break;
    case 3:
      moonChildHint = {
      /*English*/"^Come back with &#three Bosses' Remains#...",
      /*French */"^Reviens avec les &#restes de trois boss#...",
      /*Spanish*/"^**SPANISH_3_REMAINS_NEEDED**",
      /*German */"^Komm wieder mit den &#Vermächtnissen von drei Endgegnern#...",
      };
      break;
  }

  // Add opening and closing textboxes to hint
  moonChildHint = Text{
    /*NaEnglish*/"You...^You don't have many masks...do you?",
    /*NaFrench */"Toi...^Tu n'as pas beaucoup de masques... n'est-ce pas?",
    /*NaSpanish*/"**SPANISH**",
    /*EuGerman */"Du...^Du hast nicht viele Masken... oder?",
    /*EuEnglish*/"",
    /*EuFrench */"Toi...^Tu n'as pas beaucoup de masques... n'est-ce pas ?",
    /*EuSpanish*/"",
  }+moonChildHint+Text{
    /*English*/"^Then we can play.",
    /*French */"^Alors, on pourra jouer.",
    /*Spanish*/"^**SPANISH**",
    /*German */"^Dann können wir spielen.",
  };

  CustomMessages::CreateMessageFromTextObject(0x6149, 0xFFFF, 0x3FFFFFFF, 0x0FF0020, moonChildHint, {QM_RED}, {}, {}, 0x0, false, false, MESSAGE_END_NORMAL);
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