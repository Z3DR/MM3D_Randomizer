#include "fill.hpp"

//#include "custom_messages.hpp"
#include "dungeon.hpp"
#include "item_location.hpp"
#include "item_pool.hpp"
#include "location_access.hpp"
#include "logic.hpp"
#include "random.hpp"
#include "spoiler_log.hpp"
#include "starting_inventory.hpp"
#include "hints.hpp"
#include "hint_list.hpp"
#include "entrance.hpp"
//#include "shops.hpp"
#include "debug.hpp"

#include <vector>
#include <unistd.h>
#include <list>

//using namespace CustomMessages;
using namespace Logic;
using namespace Settings;

static bool placementFailure = false;

static void RemoveStartingItemsFromPool() {
    for (ItemKey startingItem : StartingInventory) {
        for (size_t i = 0; i < ItemPool.size(); i++) {
            if (startingItem == GREAT_FAIRYS_SWORD) {
                if (ItemPool[i] == GREAT_FAIRYS_SWORD) {
                    ItemPool[i] = GetJunkItem();
                }
                continue;
            }
            else if (startingItem == ItemPool[i] || (ItemTable(startingItem).IsBottleItem() && ItemTable(ItemPool[i]).IsBottleItem())) {
                if (AdditionalHeartContainers > 0 && (startingItem == PIECE_OF_HEART)) {
                    ItemPool[i] = HEART_CONTAINER;
                    AdditionalHeartContainers--;
                }
                else {
                    ItemPool[i] = GetJunkItem();
                }
                break;
            }
        }
    }
}


//This function propigates time of day access through entrances
/*
static bool UpdateToDAccess(Entrance* entrance) {

    bool ageTimePropigated = false;

    Area* parent = entrance->GetParentRegion();
    //PlacementLog_Msg("\nparent = ");
    //PlacementLog_Msg(parent->regionName+"\n");
    Area* connection = entrance->GetConnectedRegion();
    //PlacementLog_Msg("\nconnection = ");
    //PlacementLog_Msg(connection->regionName+"\n");
    if (!connection && parent->HereCheck() && entrance->ConditionsMet()){
        ageTimePropigated = true;
    }

    return ageTimePropigated;
}*/

std::vector<LocationKey> GetAllEmptyLocations() {
    return FilterFromPool(allLocations, [](const LocationKey loc) { return Location(loc)->GetPlacedItemKey() == NONE;});
}

//This function will return a vector of ItemLocations that are accessible with
//where items have been placed so far within the world. The allowedLocations argument
//specifies the pool of locations that we're trying to search for an accessible location in
std::vector<LocationKey> GetAccessibleLocations(const std::vector<LocationKey>& allowedLocations, SearchMode mode) {
    std::vector<LocationKey> accessibleLocations;
    //PlacementLog_Msg("Allowed Locations passed to AcceessibleLocations Function:\n");
    //for (LocationKey loc : allowedLocations)
    //{
    //    PlacementLog_Msg(Location(loc)->GetName() + "\n");
    //}
    //Reset all access to begin a new search
    ApplyStartingInventory();
   
    Areas::AccessReset();
    LocationReset();

    
    std::vector<AreaKey> areaPool = { ROOT };
    
    //Variables for playthrough
    //bool bombchusFound = false;
    std::vector<std::string> buyIgnores;
    //Variables for search
    std::vector<ItemLocation*> newItemLocations;
    bool updatedEvents = false;
    //bool ageTimePropigated = false;
    bool firstIteration = true;

    //If no new items are found and no events are updated, then the next iteration won't provide any new location
    while (newItemLocations.size() > 0  || firstIteration || updatedEvents) { // || ageTimePropigated 
        firstIteration = false;
        //ageTimePropigated = false;
        updatedEvents = false;

        for (ItemLocation* location : newItemLocations) {
            location->ApplyPlacedItemEffect();
        }
        newItemLocations.clear();

        std::vector<LocationKey> itemSphere;
        std::list<Entrance*> entranceSphere;
        
        for (size_t i = 0; i < areaPool.size(); i++) {
            Area* area = AreaTable(areaPool[i]);

            if (area->UpdateEvents()) {
                updatedEvents = true;
            }
            
            //for each exit in this area
            
            for (auto& exit : area->exits) {

                //Update Time of Day Access for the exit
                //if (UpdateToDAccess(&exit)){
                //    ageTimePropigated=true;
               // }

                //if the exit is accessable and hasn't been added yet, add it to pool
                Area* exitArea = exit.GetConnectedRegion();
                if (!exitArea->addedToPool && exit.GetConditionsMet()) {
                    exitArea->addedToPool = true;
                    areaPool.push_back(exit.GetAreaKey());
                    //PlacementLog_Msg("Added :" + exitArea->regionName + " to the pool \n");
                    //CitraPrint("Added " + exitArea->regionName + " to the pool");
                }
                //add shuffled entrances to the entrance playthrough
                /*
                if (mode == SearchMode::GeneratePlaythrough && exit.IsShuffled() && !exit.IsAddedToPool() && !noRandomEntrances) {
                    entranceSphere.push_back(&exit);
                    exit.AddToPool();
                    //don't list a coupled entrance from both directions 
                    if (exit.GetReplacement()->GetReverse() != nullptr */ /*&& not decoupled_entrances*/ /*) { 
                        exit.GetReplacement()->GetReverse()->AddToPool();
                    }
                }*/
            }
            
            //for each ItemLocation in this area
            for (size_t k = 0; k < area->locations.size(); k++) {
                LocationAccess& locPair = area->locations[k];
                LocationKey loc = locPair.GetLocation();
                ItemLocation* location = Location(loc);

                if ((!location->IsAddedToPool())  && (locPair.GetConditionsMet())) {

                    location->AddToPool();

                    if (location->GetPlacedItemKey() == NONE) {
                        accessibleLocations.push_back(loc); //Empty location, consider for placement  
                    } else { 
                        newItemLocations.push_back(location); //Add item to cache to be considered in logic next iteration
                    }
                    
                    //Playthrough stuff
                    //Generate the playthrough, so we want to add advancement items, unless we know to ignore them
                    if (mode == SearchMode::GeneratePlaythrough) {
                        //Item is an advancement item, figure out if it should be added to this sphere
                        if (!playthroughBeatable && location->GetPlacedItem().IsAdvancement()) {
                            //ItemType type = location->GetPlacedItem().GetItemType();//type needed to check for gold skulltula
                            std::string itemName(location->GetPlacedItemName().GetEnglish());
                            //bool bombchus = itemName.find("Bombchu") != std::string::npos; //Is a bombchu location

                            //Decide whether to exclude this location
                            //This preprocessing is done to reduce the amount of searches performed in PareDownPlaythrough
                            //Want to exclude:
                            //2) Bombchus after the first (including buy bombchus)
                            bool exclude = false;
                            //Only print first bombchu location found
                            /*if (bombchus && !bombchusFound) {
                                bombchusFound = true;
                                exclude = false;
                            }*/

                            //Add all other advancement items
                            //to-do, for now excldue is always true as we dont need to exclude shops/tokens/bombchus/ammodrops 
                            
                            //Has not been excluded, add to playthrough
                            if (!exclude) {
                                itemSphere.push_back(loc);
                            }
                        }
                        //MAJORA'S_MASK has been found, seed is beatable, nothing else in this or future spheres matters
                        if (location->GetPlacedItemKey() == MAJORAS_MASK) {
                            CitraPrint("Majoras Mask has been found!");
                            itemSphere.clear();
                            itemSphere.push_back(loc);
                            playthroughBeatable = true;
                        }
                    }
                    //All we care about is if the game is beatable, used to pare down playthrough
                    else if (location->GetPlacedItemKey() == MAJORAS_MASK && mode == SearchMode::CheckBeatable) {
                        playthroughBeatable = true;
                        return {}; //Return early for efficiency
                    }
                }
            }
        }

        //this actually seems to slow down the search algorithm, will leave commented out for now
        //erase_if(areaPool, [](const AreaKey e){ return AreaTable(e)->AllAccountedFor();});

        if (mode == SearchMode::GeneratePlaythrough && itemSphere.size() > 0) {
            playthroughLocations.push_back(itemSphere);
        }
        if (mode == SearchMode::GeneratePlaythrough && entranceSphere.size() > 0 ) { //&& !noRandomEntrances
            playthroughEntrances.push_back(entranceSphere);
        }
    }

    //Check to see if all locations were reached
    if (mode == SearchMode::AllLocationsReachable) {
        allLocationsReachable = true;
        for (const LocationKey loc : allLocations) {
            if (!Location(loc)->IsAddedToPool()) {
                allLocationsReachable = false;
                auto message = "Location " + Location(loc)->GetName() + " not reachable\n";
                PlacementLog_Msg(message);
                CitraPrint(message);
                #ifndef ENABLE_DEBUG
                    break;
                #endif
            }
        }
        return {};
    }
    
    erase_if(accessibleLocations, [&allowedLocations](LocationKey loc) {
        for (LocationKey allowedLocation : allowedLocations) {
            if (loc == allowedLocation || Location(loc)->GetPlacedItemKey() != NONE) {
                return false;
            }
        }
        return true;
        });

    return accessibleLocations;
    
}

static void GeneratePlaythrough() {
    playthroughBeatable = false;
    Logic::LogicReset();
    GetAccessibleLocations(allLocations, SearchMode::GeneratePlaythrough);
}

//Remove unnecessary items from playthrough by removing their location, and checking if game is still beatable
//To reduce searches, some preprocessing is done in playthrough generation to avoid adding obviously unnecessary items
static void PareDownPlaythrough() {
    std::vector<LocationKey> toAddBackItem;
    //Start at sphere before Majora's and count down
    for (int i = playthroughLocations.size() - 2; i >= 0; i--) {
        //Check each item location in sphere
        std::vector<int> erasableIndices;
        std::vector<LocationKey> sphere = playthroughLocations.at(i);
        for (int j = sphere.size() - 1; j >= 0; j--) {
            LocationKey loc = sphere.at(j);
            ItemKey copy = Location(loc)->GetPlacedItemKey(); //Copy out item
            Location(loc)->SetPlacedItem(NONE); //Write in empty item
            playthroughBeatable = false;
            Logic::LogicReset();
            GetAccessibleLocations(allLocations, SearchMode::CheckBeatable); //Check if game is still beatable
            //Playthrough is still beatable without this item, therefore it can be removed from playthrough section.
            if (playthroughBeatable) {
                //Uncomment to print playthrough deletion log in citra
                 std::string itemname(ItemTable(copy).GetName().GetEnglish());
                 std::string locationname(Location(loc)->GetName());
                 std::string removallog = itemname + " at " + locationname + " removed from playthrough";
                 CitraPrint(removallog);
                playthroughLocations[i].erase(playthroughLocations[i].begin() + j);
                Location(loc)->SetDelayedItem(copy); //Game is still beatable, don't add back until later
                toAddBackItem.push_back(loc);
            }
            else {
                Location(loc)->SetPlacedItem(copy); //Immediately put item back so game is beatable again
            }
        }
    }

    //Some spheres may now be empty, remove these
    for (int i = playthroughLocations.size() - 2; i >= 0; i--) {
        if (playthroughLocations.at(i).size() == 0) {
            playthroughLocations.erase(playthroughLocations.begin() + i);
        }
    }

    //Now we can add back items which were removed previously
    for (LocationKey loc : toAddBackItem) {
        Location(loc)->SaveDelayedItem();
    }
}

//Very similar to PareDownPlaythrough except it creates the list of Way of the Hero items
//Way of the Hero items are more specific than playthrough items in that they are items which *must*
// be obtained to logically be able to complete the seed, rather than playthrough items which
// are just possible items you *can* collect to complete the seed.
static void CalculateWotH() {
    //First copy locations from the 2-dimensional playthroughLocations into the 1-dimensional wothLocations
    //size - 1 so Majora's Mask is not counted
    for (size_t i = 0; i < playthroughLocations.size() - 1; i++) {
        for (size_t j = 0; j < playthroughLocations[i].size(); j++) {
            if (Location(playthroughLocations[i][j])->IsHintable()) {
                wothLocations.push_back(playthroughLocations[i][j]);
            }
        }
    }

    //Now go through and check each location, seeing if it is strictly necessary for game completion
    for (int i = wothLocations.size() - 1; i >= 0; i--) {
        LocationKey loc = wothLocations[i];
        ItemKey copy = Location(loc)->GetPlacedItemKey(); //Copy out item
        Location(loc)->SetPlacedItem(NONE); //Write in empty item
        playthroughBeatable = false;
        Logic::LogicReset();
        GetAccessibleLocations(allLocations, SearchMode::CheckBeatable); //Check if game is still beatable
        Location(loc)->SetPlacedItem(copy); //Immediately put item back
        //If removing this item and no other item caused the game to become unbeatable, then it is strictly necessary, so keep it
        //Else, delete from wothLocations
        if (playthroughBeatable) {
            wothLocations.erase(wothLocations.begin() + i);
        }
    }

    playthroughBeatable = true;
    Logic::LogicReset();
    GetAccessibleLocations(allLocations);
}

//Will place things completely randomly, no logic checks are performed
static void FastFill(std::vector<ItemKey> items, std::vector<LocationKey> locations, bool endOnItemsEmpty = false) {
    //Loop until locations are empty, or also end if items are empty and the parameters specify to end then
    while (!locations.empty() && (!endOnItemsEmpty || !items.empty())) {
        LocationKey loc = RandomElement(locations, true);
        ItemKey item = RandomElement(items, true);
        /*if ( (Location(loc)->IsRepeatable() == false) && (ItemTable(item).IsReusable() == true) ){
                    //unsuccessfulPlacement = true;
                    CitraPrint("Attemting to place repeatable item in nonrepeatable spot in FastFill");
                    PlacementLog_Msg("\n Attempted to place " + ItemTable(item).GetName().GetEnglish() + " at " + Location(loc)->GetName());
                    items.push_back(item);
                    locations.push_back(loc);
                }
        else {*/
        Location(loc)->SetAsHintable();
        PlaceItemInLocation(loc, item);
        
        if (items.empty() && !endOnItemsEmpty) {
            items.push_back(GetJunkItem());
        }
    }
}

/*
| The algorithm places items in the world in reverse.
| This means we first assume we have every item in the item pool and
| remove an item and try to place it somewhere that is still reachable
| This method helps distribution of items locked behind many requirements.
| - OoT Randomizer
*/
static void AssumedFill(const std::vector<ItemKey>& items, const std::vector<LocationKey>& allowedLocations, bool setLocationsAsHintable = false) {

    if (items.size() > allowedLocations.size()) {
        printf("\x1b[2;2HERROR: MORE ITEMS THAN LOCATIONS IN GIVEN LISTS");
        PlacementLog_Msg("Items:\n");
        for (const ItemKey item : items) {
            PlacementLog_Msg("\t");
            PlacementLog_Msg(ItemTable(item).GetName().GetEnglish());
            PlacementLog_Msg("\n");
        }
        PlacementLog_Msg("\nAllowed Locations:\n");
        for (const LocationKey loc : allowedLocations) {
            PlacementLog_Msg("\t");
            PlacementLog_Msg(Location(loc)->GetName());
            PlacementLog_Msg("\n");
        }
        PlacementLog_Write();
        placementFailure = true;
        return;
    }

    //keep retrying to place everything until it works or takes too long
    int retries = 10;
    bool unsuccessfulPlacement = false;
    std::vector<LocationKey> attemptedLocations;
    do {
        retries--;
        if (retries <= 0) {
            placementFailure = true;
            CitraPrint("Placement Failed");
            return;
        }

        unsuccessfulPlacement = false;
        std::vector<ItemKey> itemsToPlace = items;

        //copy all not yet placed advancement items so that we can apply their effects for the fill algorithm
        //std::vector<ItemKey> itemsToNotPlace = FilterFromPool(ItemPool, [](const ItemKey i) { 
            //CitraPrint("Added item to itemsToNotPlace: ");
            //CitraPrint(ItemTable(i).GetName().GetEnglish());
          //  return ItemTable(i).IsAdvancement();});
        std::vector<ItemKey> itemsToNotPlace = ItemPool;
        //PlacementLog_Msg("ItemsNotToPlace:\n");
        //for (ItemKey items : itemsToNotPlace)
        //{
        //    PlacementLog_Msg(" " + ItemTable(items).GetName().GetEnglish() + "," );
        //}

        //shuffle the order of items to place
        Shuffle(itemsToPlace);
        while (!itemsToPlace.empty()) {
            ItemKey item = std::move(itemsToPlace.back());
            ItemTable(item).SetAsPlaythrough();
            itemsToPlace.pop_back();

            //assume we have all unplaced items
            LogicReset();
            //PlacementLog_Msg("\nCurrent item for placement is: " + ItemTable(item).GetName().GetEnglish());
            //PlacementLog_Msg("\nitemsToPlace: ");
            for (ItemKey unplacedItem : itemsToPlace) {
                ItemTable(unplacedItem).ApplyEffect();
                //PlacementLog_Msg(" " + ItemTable(unplacedItem).GetName().GetEnglish() + ", ");
            }
            for (ItemKey unplacedItem : itemsToNotPlace) {
                ItemTable(unplacedItem).ApplyEffect();
            }
            //Print allowed locations to view active list at this point
            //PlacementLog_Msg("\nAllowed Locations are: \n"); 
            //CitraPrint("Allowed Locations are:");
            //for (LocationKey loc : allowedLocations)
            //   {                
            //      PlacementLog_Msg(Location(loc)->GetName());
            //      PlacementLog_Msg("\n");
            //      CitraPrint(Location(loc)->GetName());
            //    }

            //get all accessible locations that are allowed
            //CitraPrint("Accessible Locations: ");
            const std::vector<LocationKey> accessibleLocations = GetAccessibleLocations(allowedLocations);
            //print accessable locations to see what's accessable 
            //CitraPrint("Accessable Locations are:");
            //PlacementLog_Msg("\nAccessable Locations are: \n");
            //for (LocationKey loc : accessibleLocations)
            //    {                
            //    PlacementLog_Msg(Location(loc)->GetName());
            //    PlacementLog_Msg("\n");
            //    //CitraPrint(Location(loc)->GetName());
            //    }

            //retry if there are no more locations to place items
            if (accessibleLocations.empty()) {

                PlacementLog_Msg("\nCANNOT PLACE ");
                PlacementLog_Msg(ItemTable(item).GetName().GetEnglish());
                PlacementLog_Msg(". TRYING AGAIN...\n");
                //DebugPrint("%s: accessable locations according to code %u\n", __func__, accessibleLocations);
                
                #ifdef ENABLE_DEBUG
                PlacementLog_Write();
                #endif

                //reset any locations that got an item
                for (LocationKey loc : attemptedLocations) {
                    Location(loc)->SetPlacedItem(NONE);
                    itemsPlaced--;
                }
                attemptedLocations.clear();

                unsuccessfulPlacement = true;
                break;
            }

            //place the item within one of the allowed locations accounting for if this item needs to be able to be obtained more than once and if location allows that
            //the only situation we don't want is a non repeatable location with a reusable item
            LocationKey selectedLocation = RandomElement(accessibleLocations);
            if ( !(Location(selectedLocation)->IsRepeatable()) && ItemTable(item).IsReusable() ){
                    //unsuccessfulPlacement = true;
                    CitraPrint("Attemting to place repeatable item in non repeatable spot in AssumedFill");
                    PlacementLog_Msg("\n Attempted to place " + ItemTable(item).GetName().GetEnglish() + " at " + Location(selectedLocation)->GetName());
                    itemsToPlace.push_back(item);
                }
            else { 
                PlaceItemInLocation(selectedLocation, item); 
                //PlacementLog_Msg("Placed " + ItemTable(item).GetName().GetEnglish() + " at " + Location(selectedLocation)->GetName());
                //CitraPrint("Placed " + ItemTable(item).GetName().GetEnglish() + " at " + Location(selectedLocation)->GetName());
                attemptedLocations.push_back(selectedLocation);

                //This tells us the location went through the randomization algorithm
                //to distinguish it from locations which did not or that the player already
                //knows
                if (setLocationsAsHintable) {
                    Location(selectedLocation)->SetAsHintable();
                }

                //If ALR is off, then we check beatability after placing the item.
                //If the game is beatable, then we can stop placing items with logic.
                if (!LocationsReachable) {
                    playthroughBeatable = false;
                    Logic::LogicReset();
                    GetAccessibleLocations(allLocations, SearchMode::CheckBeatable);
                    if (playthroughBeatable) {
                        FastFill(itemsToPlace, GetAllEmptyLocations(), true);
                        return;
                    }
                }
            }
        }
    } while (unsuccessfulPlacement);
}

//This function will specifically randomize dungeon rewards for the End of Dungeons
//setting, or randomize one dungeon reward to Link's Pocket if that setting is on

static void RandomizeDungeonRewards() {

std::vector<ItemKey> rewards = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_DUNGEONREWARD;});
        if (Settings::Logic.Is(LogicSetting::LOGIC_VANILLA)) { //Place dungeon rewards in vanilla locations
            for (LocationKey loc : dungeonRewardLocations) {
                Location(loc)->PlaceVanillaItem();
            }
        }
        else { //Randomize dungeon rewards with assumed fill -- for now both place vanilla as random dungeon rewards is not implemented yet
            for (LocationKey loc : dungeonRewardLocations) {
                Location(loc)->PlaceVanillaItem();
            }
              // AssumedFill(rewards, dungeonRewardLocations);
        }
/*
    //quest item bit mask of each stone/medallion for the savefile
    static constexpr std::array<u32, 9> bitMaskTable = {
      0x00040000, //Kokiri Emerald
      0x00080000, //Goron Ruby
      0x00100000, //Zora Sapphire
      0x00000001, //Forest Medallion
      0x00000002, //Fire Medallion
      0x00000004, //Water Medallion
      0x00000008, //Spirit Medallion
      0x00000010, //Shadow Medallion
      0x00000020, //Light Medallion
    };
    int baseOffset = ItemTable(KOKIRI_EMERALD).GetItemID();

    //End of Dungeons includes Link's Pocket
    if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
        //get stones and medallions
        std::vector<ItemKey> rewards = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_DUNGEONREWARD;});
        if (Settings::Logic.Is(LOGIC_VANILLA)) { //Place dungeon rewards in vanilla locations
            for (LocationKey loc : dungeonRewardLocations) {
                Location(loc)->PlaceVanillaItem();
            }
        }
        else { //Randomize dungeon rewards with assumed fill
            AssumedFill(rewards, dungeonRewardLocations);
        }

        for (size_t i = 0; i < dungeonRewardLocations.size(); i++) {
            const auto index = Location(dungeonRewardLocations[i])->GetPlacedItem().GetItemID() - baseOffset;
            rDungeonRewardOverrides[i] = index;

            //set the player's dungeon reward on file creation instead of pushing it to them at the start.
            //This is done mainly because players are already familiar with seeing their dungeon reward
            //before opening up their file
            if (i == dungeonRewardLocations.size() - 1) {
                LinksPocketRewardBitMask = bitMaskTable[index];
            }
        }
    }
    else if (LinksPocketItem.Is(LINKSPOCKETITEM_DUNGEON_REWARD)) {
        //get 1 stone/medallion
        std::vector<ItemKey> rewards = FilterFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_DUNGEONREWARD;});
        ItemKey startingReward = RandomElement(rewards, true);

        LinksPocketRewardBitMask = bitMaskTable[ItemTable(startingReward).GetItemID() - baseOffset];
        PlaceItemInLocation(LINKS_POCKET, startingReward);
        //erase the stone/medallion from the Item Pool
        FilterAndEraseFromPool(ItemPool, [startingReward](const ItemKey i) {return i == startingReward;});
    }*/
}

//Fills any locations excluded by the player with junk items so that advancement items
//can't be placed there.
static void FillExcludedLocations() {
    //Only fill in excluded locations that don't already have something and are forbidden
    std::vector<LocationKey> excludedLocations = FilterFromPool(allLocations, [](const LocationKey loc) {
        return Location(loc)->IsExcluded();
        });

    for (LocationKey loc : excludedLocations) {
        PlaceJunkInExcludedLocation(loc);
    }
}

//Function to handle the Own Dungeon setting
static void RandomizeOwnDungeon(const Dungeon::DungeonInfo* dungeon) {
    std::vector<LocationKey> dungeonLocations = dungeon->GetDungeonLocations();
    std::vector<ItemKey> dungeonItems;

    //filter out locations that may be required to have songs placed at them
    
    dungeonLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc) {
        if (ShuffleSongs.Is(rnd::SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS)) {
            return !(Location(loc)->IsCategory(Category::cSong));
        }
        if (ShuffleSongs.Is(rnd::SongShuffleSetting::SONGSHUFFLE_DUNGEON_REWARDS)) {
            return !(Location(loc)->IsCategory(Category::cDungeonReward));
        }
        return true;
        });
        /*
         PlacementLog_Msg("\nAllowed Locations are: \n"); 
            CitraPrint("Allowed Locations are:");
            for (LocationKey loc : dungeonLocations)
                {                PlacementLog_Msg(Location(loc)->GetName());
                PlacementLog_Msg("\n");
                CitraPrint(Location(loc)->GetName());
                }
        */
    //Add specific items that need be randomized within this dungeon
    if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_OWN_DUNGEON) && dungeon->GetSmallKey() != NONE) {
        std::vector<ItemKey> dungeonSmallKeys = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) { return i == dungeon->GetSmallKey();});
        AddElementsToPool(dungeonItems, dungeonSmallKeys);
    }

    if (BossKeysanity.Is((u8)BossKeysanitySetting::BOSSKEYSANITY_OWN_DUNGEON) && dungeon->GetBossKey() != NONE) {
        auto dungeonBossKey = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) { return i == dungeon->GetBossKey();});
        AddElementsToPool(dungeonItems, dungeonBossKey);
    }

    //randomize boss key and small keys together for even distribution
    AssumedFill(dungeonItems, dungeonLocations);

    //randomize map and compass separately since they're not progressive
    if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_OWN_DUNGEON) && dungeon->GetMap() != NONE && dungeon->GetCompass() != NONE) {
        auto dungeonMapAndCompass = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) { return i == dungeon->GetMap() || i == dungeon->GetCompass();});
        AssumedFill(dungeonMapAndCompass, dungeonLocations);
    }
}

/*Randomize items restricted to a certain set of locations.
  The fill order of location groups is as follows:
    - Own Dungeon
    - Any Dungeon
    - Overworld
  Small Keys, Gerudo Keys, Boss Keys, Ganon's Boss Key, and/or dungeon rewards
  will be randomized together if they have the same setting. Maps and Compasses
  are randomized separately once the dungeon advancement items have all been placed.*/
static void RandomizeDungeonItems() {
    using namespace Dungeon;

    //Get Any Dungeon and Overworld group locations
    std::vector<LocationKey> anyDungeonLocations = FilterFromPool(allLocations, [](const LocationKey loc) {return Location(loc)->IsDungeon();});
    //overworldLocations defined in item_location.cpp

    //Create Any Dungeon and Overworld item pools
    std::vector<ItemKey> anyDungeonItems;
    std::vector<ItemKey> overworldItems;

    for (auto dungeon : dungeonList) {
        if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_ANY_DUNGEON)) {
            auto dungeonKeys = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetSmallKey();});
            AddElementsToPool(anyDungeonItems, dungeonKeys);
        }
        else if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_OVERWORLD)) {
            auto dungeonKeys = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetSmallKey();});
            AddElementsToPool(overworldItems, dungeonKeys);
        }

        if (BossKeysanity.Is((u8)BossKeysanitySetting::BOSSKEYSANITY_ANY_DUNGEON) && dungeon->GetBossKey() != NONE) {
            auto bossKey = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetBossKey();});
            AddElementsToPool(anyDungeonItems, bossKey);
        }
        else if (BossKeysanity.Is((u8)BossKeysanitySetting::BOSSKEYSANITY_OVERWORLD) && dungeon->GetBossKey() != NONE) {
            auto bossKey = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetBossKey();});
            AddElementsToPool(overworldItems, bossKey);
        }

    }
/*
    if (ShuffleRewards.Is(rnd::RewardShuffleSetting::REWARDSHUFFLE_ANY_DUNGEON)) {
        auto rewards = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_DUNGEONREWARD;});
        AddElementsToPool(anyDungeonItems, rewards);
    }
    else if (ShuffleRewards.Is(rnd::RewardShuffleSetting::REWARDSHUFFLE_OVERWORLD)) {
        auto rewards = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_DUNGEONREWARD;});
        AddElementsToPool(overworldItems, rewards);
    }
*/
    //Randomize Any Dungeon and Overworld pools
    AssumedFill(anyDungeonItems, anyDungeonLocations, true);
    AssumedFill(overworldItems, overworldLocations, true);

    //Randomize maps and compasses after since they're not advancement items
    for (auto dungeon : dungeonList) {
        if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_ANY_DUNGEON)) {
            auto mapAndCompassItems = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetMap() || i == dungeon->GetCompass();});
            AssumedFill(mapAndCompassItems, anyDungeonLocations, true);
        }
        else if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_OVERWORLD)) {
            auto mapAndCompassItems = FilterAndEraseFromPool(ItemPool, [dungeon](const ItemKey i) {return i == dungeon->GetMap() || i == dungeon->GetCompass();});
            AssumedFill(mapAndCompassItems, overworldLocations, true);
        }
    }
}
/*
static void RandomizeLinksPocket() {
    if (LinksPocketItem.Is(rnd::LinksPocketSetting::LINKSPOCKETITEM_ADVANCEMENT)) {
        //Get all the advancement items                                                                                                     don't include tokens
        std::vector<ItemKey> advancementItems = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).IsAdvancement() && ItemTable(i).GetItemCategory() != ItemCategory::SkulltulaTokens;});
        //select a random one
        ItemKey startingItem = RandomElement(advancementItems, true);
        //add the others back
        AddElementsToPool(ItemPool, advancementItems);

        PlaceItemInLocation(LINKS_POCKET, startingItem);
    }
    else if (LinksPocketItem.Is(rnd::LinksPocketSetting::LINKSPOCKETITEM_NOTHING)) {
        PlaceItemInLocation(LINKS_POCKET, GREEN_RUPEE);
    }
}*/

int VanillaFill() {
    //Perform minimum needed initialization
    CitraPrint("Starting VanillaFill\n");
     AreaTable_Init(); //Reset the world graph to intialize the proper locations
    ItemReset(); //Reset shops incase of shopsanity random
    GenerateLocationPool();
    GenerateItemPool();
    GenerateStartingInventory();
    RemoveStartingItemsFromPool();
    FillExcludedLocations();
    RandomizeDungeonRewards();
    for (LocationKey loc : allLocations) {
        Location(loc)->PlaceVanillaItem();
    }
    //If necessary, handle ER stuff
    //if (ShuffleEntrances) {
    //    printf("\x1b[7;10HShuffling Entrances...");
    //    ShuffleAllEntrances();
    //    printf("\x1b[7;32HDone");
    //}
    //Finish up
    GeneratePlaythrough();
    printf("Done");
    printf("\x1b[9;10HCalculating Playthrough..."); 
    PareDownPlaythrough();
    printf("Done");
    printf("\x1b[10;10HCalculating Way of the Hero..."); 
    CalculateWotH();
    printf("Done");
    CitraPrint("Creating Item Overrides");
    CreateItemOverrides();
    // CreateEntranceOverrides();
    // CreateAlwaysIncludedMessages();
    if (GossipStoneHints.IsNot(rnd::GossipStoneHintsSetting::HINTS_NO_HINTS)) {
        printf("\x1b[11;10HCreating Hints...");
        CreateAllHints();
        printf("Done");
     }
     
    return 1;
}

int NoLogicFill() {
    CitraPrint("StartingNoLogicFill\n");
    AreaTable_Init(); //Reset the world graph to intialize the proper locations
    ItemReset(); //Reset shops incase of shopsanity random
    GenerateLocationPool();
    GenerateItemPool();
    GenerateStartingInventory();
    RemoveStartingItemsFromPool();
    FillExcludedLocations();
    RandomizeDungeonRewards();
    std::vector<ItemKey> remainingPool = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return true;});
    FastFill(remainingPool, GetAllEmptyLocations(), false);
    GeneratePlaythrough();
    printf("Done");
    printf("\x1b[9;10HCalculating Playthrough..."); 
    PareDownPlaythrough();
    printf("Done");
    printf("\x1b[10;10HCalculating Way of the Hero..."); 
    CalculateWotH();
    printf("Done");
    CitraPrint("Creating Item Overrides");
    CreateItemOverrides();
    // CreateEntranceOverrides();
    // CreateAlwaysIncludedMessages();
    if (GossipStoneHints.IsNot(rnd::GossipStoneHintsSetting::HINTS_NO_HINTS)) {
        printf("\x1b[11;10HCreating Hints...");
        CreateAllHints();
        printf("Done");
     }
     
     return 1;
}
   

int Fill() {
    int retries = 0;
    while (retries < 5) {
        placementFailure = false;
        showItemProgress = false;
        playthroughLocations.clear();
        playthroughEntrances.clear();
        wothLocations.clear();
        AreaTable_Init(); //Reset the world graph to intialize the proper locations
        ItemReset(); //Reset shops incase of shopsanity random
        GenerateLocationPool();
        GenerateItemPool();
        GenerateStartingInventory();
        RemoveStartingItemsFromPool();
        FillExcludedLocations();
        
        showItemProgress = true;

        //Place dungeon rewards - always vanilla for now
        RandomizeDungeonRewards();
        
        //Place dungeon items restricted to their Own Dungeon
        for (auto dungeon : Dungeon::dungeonList) {
            RandomizeOwnDungeon(dungeon);
        }

        //Then place dungeon items that are assigned to restrictive location pools
        RandomizeDungeonItems();

        if (ShuffleGFRewards.Is((u8)GreatFairyRewardShuffleSetting::GFREWARDSHUFFLE_ALL_GREAT_FARIES)){
            //get GF locations
            std::vector<LocationKey> gfLocations = FilterFromPool(allLocations, [](const LocationKey loc) {return Location(loc)->IsCategory(Category::cFairyFountain);});
            std::vector<ItemKey> gfItems = FilterAndEraseFromPool(ItemPool, [gfLocations](const ItemKey i) { return ItemTable(i).GetItemType() == ITEMTYPE_GFAIRY;});
            
            AssumedFill(gfItems, gfLocations, true);
        }

        //Place Main Inventory First
        //So first get all items in the pool + DekuMask,
        std::vector<ItemKey> mainadvancementItems = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).IsAdvancement() && ItemTable(i).GetItemType() != ITEMTYPE_QUEST;});//(ItemTable(i).GetItemType() == ITEMTYPE_ITEM || ItemTable(i).GetItemType() == ITEMTYPE_MASK || ItemTable(i).GetItemType() == ITEMTYPE_TRADE || ItemTable(i).GetItemType() == ITEMTYPE_GFAIRY)
        //Then Place those to expand the amount of checks available
        AssumedFill(mainadvancementItems, allLocations,true);
        
        //Then Place Anju & Kafei Items in spots accessable on Day 1, this should prevent situations where you cant get an item in time for its use
        std::vector<LocationKey> day1Locations = FilterFromPool(allLocations, [](const LocationKey loc) {return Location(loc)->IsCategory(Category::cDayOne);});
        std::vector<ItemKey> anjukafeiitems = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_QUEST;});
        AssumedFill(anjukafeiitems, day1Locations,true);

        //Then Place Deku Merchant Items
       /* if(ShuffleMerchants) {
            std::vector<ItemKey> dekuTrades = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_TRADE;});
            AssumedFill(dekuTrades, allLocations);
        }   */
        
        //Then Place songs if song shuffle is set to specific locations
        /*
        if (ShuffleSongs.IsNot(SongShuffleSetting::SONGSHUFFLE_ANYWHERE)) {

            //Get each song
            std::vector<ItemKey> songs = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) { return ItemTable(i).GetItemType() == ITEMTYPE_SONG;});

            //Get each song location
            std::vector<LocationKey> songLocations;
            if (ShuffleSongs.Is(SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS)) {
                songLocations = FilterFromPool(allLocations, [](const LocationKey loc) { return Location(loc)->IsCategory(Category::cSong);});
            }
            else if (ShuffleSongs.Is(SongShuffleSetting::SONGSHUFFLE_ANYWHERE)) {
                songLocations = allLocations;
            }
            AssumedFill(songs, songLocations, true);
        }*/
        
        

        

        //Then place Link's Pocket Item if it has to be an advancement item
        //Links Pocket is useless as there is no unobtainable check due to a certain time travel sword pedistal 
        //Any check that occurs before MM3D world initialization like Ocarina/KokiriSword/Shield/SongofTime
        //Can just be handled by starting inventory 
        //RandomizeLinksPocket();  

        //Place Tokens before junk
        std::vector<ItemKey> tokens = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return ItemTable(i).GetItemType() == ITEMTYPE_TOKEN; });
        AssumedFill(tokens, allLocations, true);

        CitraPrint("Starting AssumedFill...");
         //Then place the rest of the advancement items
        std::vector<ItemKey> remainingAdvancementItems = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) { return ItemTable(i).IsAdvancement();});
        AssumedFill(remainingAdvancementItems, allLocations, true);
        CitraPrint("AssumedFill was sucessful");
        CitraPrint("Starting Fast Fill...");
        //Fast fill for the rest of the pool
        std::vector<ItemKey> remainingPool = FilterAndEraseFromPool(ItemPool, [](const ItemKey i) {return true;});
        FastFill(remainingPool, GetAllEmptyLocations(), false);
        CitraPrint("Fast Fill of Remaining locations was sucessful");
        //CitraPrint("Generating Playthrough...");
        GeneratePlaythrough(); //TODO::FIX PLAYTHROUGH

        //Successful placement, produced beatable result
        if (!placementFailure && playthroughBeatable ) {
            printf("Done");
            printf("\x1b[9;10HCalculating Playthrough..."); 
            PareDownPlaythrough();
            printf("Done");
            printf("\x1b[10;10HCalculating Way of the Hero..."); 
            CalculateWotH();
            printf("Done");
            CitraPrint("Creating Item Overrides");
            CreateItemOverrides();
           // CreateEntranceOverrides();
           // CreateAlwaysIncludedMessages();
            if (GossipStoneHints.IsNot(rnd::GossipStoneHintsSetting::HINTS_NO_HINTS)) {
                printf("\x1b[11;10HCreating Hints...");
                CreateAllHints();
                printf("Done");
             }
            /*if (ShuffleMerchants.Is(SHUFFLEMERCHANTS_HINTS)) {
                CreateMerchantsHints();
            }*/
            return 1;
        }
        //Unsuccessful placement
        if (retries < 4) {
            //LogicReset();
            //GetAccessibleLocations(allLocations, SearchMode::AllLocationsReachable);
            printf("\x1b[9;10HFailed. Retrying... %d", retries + 2);
            CitraPrint("Failed. Retrying...");
            Areas::ResetAllLocations();
            LogicReset();
        }
        retries++;
    }
    //All retries failed
    return -1;
}