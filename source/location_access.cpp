#include "location_access.hpp"

#include "dungeon.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "item_pool.hpp"
#include "logic.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
#include "entrance.hpp"

#include <unistd.h>

using namespace Logic;
using namespace Settings;


bool LocationAccess::ConditionsMet() const {
	
	bool conditionsMet =  false;

	UpdateHelpers();
	if (GetConditionsMet()) {
		conditionsMet= true;
	}
	
	return conditionsMet;// && CanBuy();
}

bool LocationAccess::CanBuy() const {
	//if its not a shop you dont need to check if it can  be bought
	if (!(Location(location)->IsCategory(Category::cShop))) {
		return true;
	}

	//Check if current walet is large enough
	bool SufficientWallet = true;
	if (Location(location)->GetPrice() > 500) {
		SufficientWallet = Logic::ProgressiveWallet >= 3;
	}
	else if (Location(location)->GetPrice() > 200) {
		SufficientWallet = Logic::ProgressiveWallet >= 2;
	}
	else if (Location(location)->GetPrice() > 99) {
		SufficientWallet = Logic::ProgressiveWallet >= 1;
	}

	bool OtherCondition = true;
	u32 placed = Location(location)->GetPlacedItemKey();
	//Need bottle to buy bottle items
	if (placed == BUY_BLUE_POTION || placed == BUY_FAIRYS_SPIRIT || placed == BUY_GREEN_POTION) {
		OtherCondition = Logic::HasBottle;
	}
	//Need Bombbag to buy bombs/bombchus
	else if (placed == BUY_BOMBS_10 || placed == BUY_BOMBCHU_10) {
		OtherCondition = Logic::AnyBombBag;
	}
	return SufficientWallet && OtherCondition;
}

Area::Area() = default;
Area::Area(std::string regionName_, std::string scene_, u32 hintKey_,
		std::vector<EventAccess> events_,
		std::vector<LocationAccess> locations_,
		std::list<Entrance> exits_ )
	: regionName(std::move(regionName_)),
	scene(std::move(scene_)),
	hintKey(hintKey_),
	events(std::move(events_)),
	locations(std::move(locations_)),
	exits(std::move(exits_)) {}

Area::~Area() = default;

bool Area::UpdateEvents() {

	bool eventsUpdated = false;

	for (EventAccess& event : events)
	{
		//if event happened dont check it.
		if (event.GetEvent()) {
			continue;
		}
		//check condition on all days/nights
		if (event.ConditionsMet()){
			event.EventOccurred();
			eventsUpdated=true;
		}
	}
	return eventsUpdated;
}

void Area::AddExit(AreaKey parentKey, AreaKey newExitKey, ConditionFn condition) {
  Entrance newExit = Entrance(newExitKey, {condition});
  newExit.SetParentRegion(parentKey);
  exits.push_front(newExit);
}

//The exit will be completely removed from this area
void Area::RemoveExit(Entrance* exitToRemove) {
  exits.remove_if([exitToRemove](const auto exit){return &exit == exitToRemove;});
}

//The exit will still exist in the area, but won't be accessible
void Area::DisconnectExit(AreaKey exitToDisconnect) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToDisconnect) {
      exit.Disconnect();
      return;
    }
  }
}

void Area::SetAsPrimary(AreaKey exitToBePrimary) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToBePrimary) {
      exit.SetAsPrimary();
      return;
    }
  }
}

Entrance* Area::GetExit(AreaKey exitToReturn) {
  for (auto& exit : exits) {
    if (exit.GetAreaKey() == exitToReturn) {
      return &exit;
    }
  }
  auto message = "ERROR: EXIT " + AreaTable(exitToReturn)->regionName + " DOES NOT EXIST IN " + this->regionName;
  CitraPrint(message);
  return nullptr;
}

bool Area::CanPlantBeanCheck() const {
	return(Logic::MagicBean || Logic::MagicBeanPack);
}


bool Area::AllAccountedFor() const {
	for (const EventAccess& event : events) {
		if (!event.GetEvent()) {
			return false;
		}
	}

	for (const LocationAccess& loc : locations) {
		if (!(Location(loc.GetLocation())->IsAddedToPool())) {
			return false;
		}
	}

	for (const auto& exit : exits) {
		if (!exit.GetConnectedRegion()->AllAccess()) {
		return false;
		}
	}

	return AllAccess();
}

bool Area::CheckAllAccess(const AreaKey exitKey) {
	if (!AllAccess()) {
		return false;
	}

	for(Entrance& exit: exits) {
		if(exit.GetAreaKey() == exitKey) {
			exit.GetConditionsMet();
		}
	}
	return false;
}


void Area::ResetVariables() {
	addedToPool = false;
	for (auto& exit : exits) {
		exit.RemoveFromPool();
	}
}

static std::array<Area, KEY_ENUM_MAX> areaTable;

bool Here(const AreaKey area, ConditionFn condition) {
	return areaTable[area].HereCheck(condition);
}

bool CanPlantBean(const AreaKey area) {
	return areaTable[area].CanPlantBeanCheck();
}

bool HasAccessTo(const AreaKey area) {
	return areaTable[area].HasAccess();
}

void AreaTable_Init() {
	//clear array from previous playthroughs
	areaTable.fill(Area("Invalid Area", "Invalid Area", NONE, {}, {}, {}));
						//Name,          Scene,      hint text, events, locations, exits
	areaTable[ROOT] = Area("Root", "Root", LINKS_POCKET, {}, {
			//Locations
			//LocationAccess(LINKS_POCKET, {[] {return true;}})
		},
		{
			//Exits
			Entrance(ROOT_EXITS, {[]{return true;}})
		});

	areaTable[ROOT_EXITS] = Area("Root Exits", "Root Exits", NONE, {}, {}, {
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});

	/*--------------------------
	|    OVERWORLD             |
	---------------------------*/

	/*--------------------------
	|    Clock Town            |
	---------------------------*/
	
	areaTable[N_CLOCK_TOWN] = Area("North Clock Town", "North Clock Town", N_CLOCK_TOWN, {
		//Events
		EventAccess(&OldLadySaved, {[]{return Fighting || Bow;}}),
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
		EventAccess(&PostedKafeiLetter, {[]{return LetterKafei;}}),
	},
	{
		//Locations
		LocationAccess(N_CLOCK_TOWN_KEATON_QUIZ, {[] {return KeatonMask;}}),
		LocationAccess(N_CLOCK_TOWN_TREE, {[] {return true;}}),
		LocationAccess(N_CLOCK_TOWN_OLD_LADY, {[] {return Fighting;}}),
		LocationAccess(TINGLE_N_CLOCK_TOWN_CT, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_N_CLOCK_TOWN_WF, {[]{return CanUseProjectile;}}),
		LocationAccess(N_CLOCK_TOWN_POSTBOX, {[]{return PostmansHat;}}),

	},
	{
		//Exits
		Entrance(CLOCK_TOWN_FAIRY_FOUNTAIN, {[]{return true;}}),
		Entrance(CLOCK_TOWN_DEKU_PLAYGROUND, {[]{return DekuMask;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),//to-do add variables depending on future settings
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = Area("Clock Town Fairy Fountain", "Clock Town Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, {[] {return ClockTownStrayFairy && DekuMask;}}),
		LocationAccess(N_CLOCK_TOWN_GREAT_FAIRY_HUMAN, {[] {return ClockTownStrayFairy;}}),
		
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_DEKU_PLAYGROUND] = Area("Clock Town Deku Playground", "Clock Town Deku Playground", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}})
	});

	areaTable[E_CLOCK_TOWN] = Area("East Clock Town", "East Clock Town", E_CLOCK_TOWN, {
		//Events
		EventAccess(&PostedKafeiLetter, {[]{return LetterKafei;}}),
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_CHEST, {[] {return true;}}),
		LocationAccess(E_CLOCK_TOWN_POSTBOX, {[]{return PostmansHat;}}),
		LocationAccess(E_CLOCK_TOWN_POSTMAN_FREEDOM, {[]{return LetterMama;}}),

	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(CLOCK_TOWN_OBSERVATORY, {[]{return BombersNotebook || SkipBombersMinigame;}}),
		Entrance(STOCKPOTINN, {[]{return true;}}),//to-Do Stock Pot Inn Night Access
		Entrance(CLOCK_TOWN_BAR, {[]{return RomanisMask;}}),
		Entrance(CLOCK_TOWN_HONEY_DARLING, {[]{return true;}}),
		Entrance(CLOCK_TOWN_TREASURE_CHEST_GAME, {[]{return true;}}),
		Entrance(CLOCK_TOWN_ARCHERY, {[]{return true;}}),
		Entrance(CLOCK_TOWN_MAYOR_HOUSE, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});
	
	areaTable[STOCKPOTINN] = Area("Stock Pot Inn", "Stock Pot Inn", STOCKPOTINN, {
		//Events
		EventAccess(&MilkQuestStart, {[] {return CircusLeadersMask;}}),
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(STOCKPOTINN_RESERVATION, {[] {return GoronMask;}}),
		LocationAccess(STOCKPOTINN_TOILET_HAND, {[] {return AnyPaper;}}),//Inn unlocked on day 3
	},
	{
		//Exits
		Entrance(STOCKPOTINN_GUEST_ROOM, {[]{return RoomKey;}}),
		Entrance(STOCKPOTINN_STAFF_ROOM, {[]{return  true;}}),
		Entrance(STOCKPOTINN_GRANDMA_ROOM, {[]{return true;}}),
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_GUEST_ROOM] = Area("Stock Pot Inn Guest Room", "Stock Pot Inn Guest Room", NONE, {
		//Events
		//Listen to Anju? --probably not needed as its not hard required
	},
	{
		//Locations
		LocationAccess(STOCKPOTINN_GUEST_ROOM_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_STAFF_ROOM] = Area("Stock Pot Inn Staff Room", "Stock Pot Inn Staff Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STOCKPOTINN_MIDNIGHT_MEETING, {[] {return KafeisMask && (DekuMask || RoomKey);}}),
		LocationAccess(STOCKPOTINN_ANJU_AND_KAFEI, {[] {return KafeisMask && SpokeToKafei && PendantAccess && SunMask;}}),
		LocationAccess(STOCKPOTINN_STAFF_ROOM_CHEST, {[] {return true;}}),//Day 3?
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[STOCKPOTINN_GRANDMA_ROOM] = Area("Stock Pot Inn Grandma's Room", "Stock Pot Inn Grandma's Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STOCKPOTINN_GRANDMA_SHORT_STORY, {[] {return AllNightMask;}}),
		LocationAccess(STOCKPOTINN_GRANDMA_LONG_STORY, {[] {return AllNightMask;}}),
	},
	{
		//Exits
		Entrance(STOCKPOTINN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_OBSERVATORY] = Area("Astral Observatory/Bombers Hideout", "Astral Obseravtory/Bombers Hideout", NONE, {
		//Events
		EventAccess(&WatchMoonTearFall, {[]{return true;}}),
		EventAccess(&ScarecrowSong, {[]{return Ocarina;}}),
	},
	{
		//Locations
		LocationAccess(BOMBERS_HIDEOUT_CHEST, {[] {return HasExplosives;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD_OUTSIDE_OBSERVATORY, {[]{return CanUseProjectile || KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED);}}),//Pots can be used to pop the balloon
	});

	areaTable[CLOCK_TOWN_BAR] = Area("Milk Bar", "Milk Bar", NONE, {
		//Events
		EventAccess(&Milk, {[]{return RomanisMask && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_GORMAN, {[] {return DekuMask && GoronMask && ZoraMask && RomanisMask;}}),
		LocationAccess(E_CLOCK_TOWN_AROMA_IN_BAR, {[] {return LetterMama && KafeisMask;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_HONEY_DARLING] = Area("Honey And Darling Shop", "Honey And Darling Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_HONEY_DARLING_3DAYS, {[] {return Bow && AnyBombBag;}}),//Deku does not replace bow
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = Area("Treasure Chest Game", "Treasure Chest Game", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON, {[] {return GoronMask;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_ARCHERY] = Area("Clock Town Archery", "Clock Town Archery", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_ARCHERY_1, {[] {return Bow;}}),
		LocationAccess(E_CLOCK_TOWN_ARCHERY_2, {[] {return Bow;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	areaTable[CLOCK_TOWN_MAYOR_HOUSE] = Area("Mayor's House", "Mayor's House", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(E_CLOCK_TOWN_MAYOR, {[]{return CouplesMask;}}),
		LocationAccess(E_CLOCK_TOWN_AROMA_IN_OFFICE, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
	});
	
		
	areaTable[W_CLOCK_TOWN] = Area("West Clock Town", "West Clock Town", W_CLOCK_TOWN, {
		//Events
	},
	{
		//Locations
		LocationAccess(W_CLOCK_TOWN_ROSA_SISTERS, {[] {return KamarosMask;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(CLOCK_TOWN_SWORDSMANS_SCHOOL, {[]{return true;}}),
		Entrance(CLOCK_TOWN_POSTMAN_HOUSE, {[]{return true;}}),
		Entrance(CLOCK_TOWN_LOTTERY, {[]{return true;}}),
		Entrance(CLOCK_TOWN_BOMB_SHOP, {[]{return true;}}),
		Entrance(CLOCK_TOWN_TRADING_POST, {[]{return true;}}),
		Entrance(CLOCK_TOWN_CURIOSITY_SHOP, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = Area("Swordmans' School", "Swordsmans' School", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(W_CLOCK_TOWN_SWORDSMANS_SCHOOL, {[] {return AnyBSword;}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_POSTMAN_HOUSE] = Area("Post Office", "Post Office", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(W_CLOCK_TOWN_POSTMANS_GAME, {[] {return BunnyHood;}}),//trick to do without?
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_LOTTERY] = Area("Lottery Shop", "Lottery Shop", NONE, {
		//Events
	},
	{
		//Locations
		//LocationAccess(W_CLOCK_TOWN_LOTTERY, {[] {return;}}),

	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_BOMB_SHOP] = Area("Clock Town Bomb Shop", "Clock Town Bomb Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(BOMB_SHOP_ITEM_1, {[]{return true;}}),
		LocationAccess(BOMB_SHOP_ITEM_2, {[]{return true;}}),
		LocationAccess(W_CLOCK_TOWN_BOMB_BAG_BUY, {[] {return true;}}),
		LocationAccess(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, {[] {return OldLadySaved;}}),
		LocationAccess(W_CLOCK_TOWN_BOMB_SHOP_GORON, {[] {return GoronMask && PowderKeg;}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_TRADING_POST] = Area("Trading Post", "Trading Post", NONE, {
		//Events
		EventAccess(&ScarecrowSong, {[]{return Ocarina;}}),
		EventAccess(&SpringWater,   {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(TRADING_POST_ITEM_1, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_2, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_3, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_4, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_5, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_6, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_7, {[]{return true;}}),
		LocationAccess(TRADING_POST_ITEM_8, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWN_CURIOSITY_SHOP] = Area("Curiosity Shop", "Curiosity Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY, {[] {return (ProgressiveWallet >= 2);}}),
	},
	{
		//Exits
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[S_CLOCK_TOWN] = Area("South Clock Town", "South Clock Town", S_CLOCK_TOWN, {
		//Events
		EventAccess(&PostedKafeiLetter, {[]{return LetterKafei;}}),
	},
	{
		//Locations
		LocationAccess(S_CLOCK_TOWN_SCRUB_TRADE, {[] {return MoonsTear;}}),
		LocationAccess(S_CLOCK_TOWN_POSTBOX, {[] {return PostmansHat;}}),
		LocationAccess(S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE, {[] {return true;}}),
		LocationAccess(S_CLOCK_TOWN_STRAW_ROOF_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		LocationAccess(S_CLOCK_TOWN_FINAL_DAY_CHEST, {[] {return Hookshot || (DekuMask && MoonsTear);}}),
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_1, {[] {return true;}}),
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_2, {[] {return AnyWallet;}}),//Adult Wallet for lenience
		LocationAccess(S_CLOCK_TOWN_BANK_REWARD_3, {[] {return (OceanWallet500 || ProgressiveWallet > 1);}}),//Giant Wallet for lenience
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(E_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(W_CLOCK_TOWN,  {[]{return true;}}),
		Entrance(LAUNDRY_POOL,  {[]{return true;}}),
		Entrance(CLOCK_TOWER,   {[]{return true;}}),
		Entrance(CLOCK_TOWER_ROOF, {[]{return true;}}),
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWER] = Area("Clock Tower Interior", "Clock Tower Interior", CLOCK_TOWER, {
		//Events
	},
	{
		//Locations
		LocationAccess(HMS_SONG_OF_HEALING, {[]{return true;}}),
		LocationAccess(HMS_BOMBERS_NOTEBOOK, {[]{return true;}}),
		LocationAccess(HMS_DEKU_MASK, {[]{return true;}}),
		LocationAccess(HMS_STARTING_SWORD, {[]{return true;}}),
		LocationAccess(HMS_STARTING_SHIELD, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
	});

	areaTable[CLOCK_TOWER_ROOF] = Area("Clock Tower Roof", "Clock Tower Roof", CLOCK_TOWER_ROOF, {
		//Events
		EventAccess(&CanGoToMoon, {[]{return OdolwaRemains && GohtRemains && GyorgRemains && TwinmoldRemains && CanPlay(OathToOrder);}}),
	},
	{
		//Locations
		LocationAccess(CLOCK_TOWER_OCARINA_OF_TIME, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(THE_MOON_TREE_ROOM, {[]{return CanGoToMoon;}}),
	});

	areaTable[LAUNDRY_POOL] = Area("Laundry Pool", "Laundry Pool", LAUNDRY_POOL, {
		//Events
		EventAccess(&LaundryFrog, {[]{return DonGerosMask;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE, {[] {return SpokeToKafei;}}),
		LocationAccess(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO, {[] {return SpokeToKafei;}}),
		LocationAccess(LAUNDRY_POOL_GURU_GURU, {[] {return true;}}), //No Reqs, Talk on night of day 1 or 2
		LocationAccess(LAUNDRY_POOL_SF, { [] {return true;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(LAUNDRY_POOL_KAFEI_HIDEOUT, {[]{return PostedKafeiLetter;}}),
	});

	areaTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = Area("Kafei's Hideout", "Kafei's Hideout", NONE, {
		//Events
		EventAccess(&SpokeToKafei, {[]{return PostedKafeiLetter;}}),
	},
	{
		//Locations
		LocationAccess(LAUNDRY_POOL_KAFEI, {[] {return PostedKafeiLetter;}}),
		
	},
	{
		//Exits
		Entrance(LAUNDRY_POOL, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD] = Area("Termina Field", "Termina Field", TERMINA_FIELD, {
		//Events
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return AnySword;}}),
		//Moons Tear Event
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_KAMARO, {[] {return CanPlay(SongOfHealing);}}),
		LocationAccess(TERMINA_FIELD_UNDERWATER_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(TERMINA_FIELD_GRASS_CHEST, {[] {return true;}}),
		LocationAccess(TERMINA_FIELD_STUMP_CHEST, {[] {return Hookshot || BeansAndWater;}}),
		//Gossip Stones
		LocationAccess(TF_MILK_ROAD_TREE_GOSSIP, {[] {return true;}}),
		LocationAccess(TF_IKANA_SNOWHEAD_GOSSIP, {[] {return true;}}),
		LocationAccess(TF_TOP_SNOWHEAD_GOSSIP, {[] {return true;}}),
		LocationAccess(TF_LOWER_SNOWHEAD_GOSSIP, {[] {return true;}}),
		LocationAccess(TF_NEAR_GRASS_CHEST_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(N_CLOCK_TOWN, {[]{return true;}}),
		Entrance(E_CLOCK_TOWN, {[]{return true;}}),
		Entrance(W_CLOCK_TOWN, {[]{return true;}}),
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(TERMINA_FIELD_PEAHAT_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_DODONGO_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_BIO_BABA_GROTTO, {[]{return CanBlastOrSmash;}}),
		Entrance(TERMINA_FIELD_PILLAR_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_GRASS_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_BUSINESS_SCRUB_GROTTO, {[]{return true;}}),
		Entrance(TERMINA_FIELD_COW_GROTTO, {[]{return HasExplosives && (MaskOfTruth || KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED));}}),
		Entrance(TERMINA_FIELD_GOSSIP_STONES_GROTTO, {[]{return CanBlastOrSmash;}}),//Something to break rocks
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(PATH_TO_MOUNTAIN_VILLAGE, {[]{return Bow;}}),// || (HotSpringWater && AnyBottle)
		Entrance(MILK_ROAD, {[]{return true;}}),
		Entrance(GREAT_BAY_COAST, {[]{return CanPlay(EponasSong);}}),
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
		Entrance(TERMINA_FIELD_OUTSIDE_OBSERVATORY, {[]{return DekuMask;}}),
	});

	areaTable[TERMINA_FIELD_OUTSIDE_OBSERVATORY] = Area("Termina Field Outside Observatory","Termina Field Outside Observatory", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_MOONS_TEAR, {[] {return WatchMoonTearFall;}}),
		//Gossip Stones
		LocationAccess(TF_OBSERVATORY_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return BeansAndWater;}}),
		Entrance(CLOCK_TOWN_OBSERVATORY, {[]{return true;}}),
	});
	
	areaTable[TERMINA_FIELD_PEAHAT_GROTTO] = Area("Termina Field Peahat Grotto","Termina Field Peahat Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_PEAHAT_GROTTO_CHEST, {[] {return Fighting || Bow;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});

	areaTable[TERMINA_FIELD_DODONGO_GROTTO] = Area("Termina Field Dodongo Grotto","Termina Field Dodongo Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_DODONGO_GROTTO_CHEST, {[] {return Fighting || Bow || AnyBombBag;}}),
		
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_BIO_BABA_GROTTO] = Area("Termina Field Bio Baba Grotto","Termina Field Bio Baba Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_PILLAR_GROTTO] = Area("Termina Field Pillar Grotto","Termina Field Pillar Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_PILLAR_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_GRASS_GROTTO] = Area("Termina Field Grass Grotto","Termina Field Grass Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_GRASS_GROTTO_CHEST, {[] {return true;}}),
		
	},
	{
		//Exits
	});
	areaTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = Area("Termina Field Business Scrub Grotto","Termina Field Business Scrub Grotto", NONE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_BUSINESS_SCRUB, {[] {return AnyWallet && WatchMoonTearFall;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_COW_GROTTO] = Area("Termina Field Cow Grotto","Termina Field Cow Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Milk, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_GROTTO_COW1, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
		LocationAccess(TERMINA_FIELD_GROTTO_COW2, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});
	areaTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = Area("Termina Field Gossip Stones Grotto","Termina Field Gossip Stones Grotto", NONE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&SpringWater, {[] {return AnyBottle;}}),
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
	},
	{
		//Locations
		LocationAccess(TERMINA_FIELD_GOSSIP_STONES, {[] {return (GoronMask && CanPlay(GoronsLullaby)) ||
																(DekuMask && CanPlay(SonataOfAwakening)) ||
																(ZoraMask && CanPlay(NewWaveBossaNova));}}),
		LocationAccess(TF_FOUR_STONE_GROTTO_1, {[] {return true;}}),
		LocationAccess(TF_FOUR_STONE_GROTTO_2, {[] {return true;}}),
		LocationAccess(TF_FOUR_STONE_GROTTO_3, {[] {return true;}}),
		LocationAccess(TF_FOUR_STONE_GROTTO_4, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SOUTHERN_SWAMP] = Area("Road to Southern Swamp", "Road to Southern Swamp", ROAD_TO_SOUTHERN_SWAMP, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
	},
	{
		//Locations
		LocationAccess(ROAD_TO_SS_TREE, {[] {return CanUseProjectile;}}),//something to kill the dragonfly
		LocationAccess(TINGLE_ROAD_TO_SS_WF, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_ROAD_TO_SS_SH, {[]{return CanUseProjectile;}}),
		//Gossip Stones
		LocationAccess(ROAD_TO_SS_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(ROAD_TO_SOUTHERN_SWAMP_ARCHERY, {[]{return true;}}),
		Entrance(ROAD_TO_SWAMP_GROTTO, {[]{return true;}}),
		//Entrance(ROAD_TO_SWAMP_FISHING_HOLE, {[]{return true;}}), //eventually add?
	});

	areaTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = Area("Road To Southern Swamp Archery", "Road to Southern Swamp Archery", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_SS_ARCHERY_1, {[] {return Bow;}}),
		LocationAccess(ROAD_TO_SS_ARCHERY_2, {[] {return Bow;}}),
		
	},
	{
		//Exits
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SWAMP_GROTTO] = Area("Road To Southen Swamp Grotto", "Road To Southern Swamp Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations		
		LocationAccess(ROAD_TO_SWAMP_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
	});

	
	areaTable[SOUTHERN_SWAMP] = Area("Southern Swamp", "Southern Swamp", SOUTHERN_SWAMP, {
		//Events
		EventAccess(&Mushroom, {[]{return MaskOfScents && AnyBottle;}}),//Base logic expects mushrooms from SS or Woods
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
		EventAccess(&SwampFrog, {[]{return DonGerosMask;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_SCRUB_TRADE, {[] {return LandTitle;}}),
		LocationAccess(SOUTHERN_SWAMP_SCRUB_PURCHASE, {[]{return DekuMask;}}),
		LocationAccess(SOUTHERN_SWAMP_MUSIC_STATUE, {[] {return true;}}),
		LocationAccess(SWAMP_TOURIST_CENTER_ROOF, {[] {return DekuMask && LandTitle;}}),
		LocationAccess(SOUTHERN_SWAMP_SCRUB_TRADE_CLEAR, {[] {return LandTitle && WoodfallClear;}}),
		LocationAccess(SOUTHERN_SWAMP_SCRUB_PURCHASE_CLEAR, {[]{return DekuMask && WoodfallClear;}}),
		LocationAccess(SWAMP_TOURIST_CENTER_ROOF_CLEAR, {[] {return DekuMask && LandTitle && WoodfallClear;}}),
		//Gossip Stones
		LocationAccess(SS_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(MYSTERY_WOODS, {[]{return true;}}),
		Entrance(SWAMP_TOURIST_CENTER, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP_HAGS_POTION_SHOP, {[]{return true;}}),
		
		Entrance(DEKU_PALACE, {[]{return KoumeSaved || WoodfallClear || (DekuMask && (Bow || ZoraMask || Hookshot));}}),
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return false;}}),//Only accessable From top route falling down
		Entrance(SSH_ENTRANCE, {[]{return (DekuMask && (KoumeSaved || Bow || ZoraMask || Hookshot)) || WoodfallClear;}}),
		Entrance(SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO, {[]{return (DekuMask && (KoumeSaved || Bow || ZoraMask || Hookshot)) || WoodfallClear;}}),
	});

	areaTable[SWAMP_TOURIST_CENTER] = Area("Swamp Tourist Center", "Swamp Tourist Center", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOUME, {[] {return KoumeSaved;}}),
		LocationAccess(SOUTHERN_SWAMP_PICTOGRAPH_WINNER, {[] {return WinnerPicture;}}),
		LocationAccess(SOUTHERN_SWAMP_BOAT_ARCHERY, {[] {return WoodfallClear && KoumeSaved;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = Area("Swamp Potion Shop", "Swamp Potion Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOTAKE, {[] {return SpokeToKoume;}}),
		LocationAccess(SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE, {[] {return Mushroom;}}),
		LocationAccess(POTION_SHOP_ITEM_1, {[]{return AnyBottle;}}),
		LocationAccess(POTION_SHOP_ITEM_2, {[]{return AnyBottle;}}),
		LocationAccess(POTION_SHOP_ITEM_3, {[]{return AnyBottle;}}),
		
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[MYSTERY_WOODS] = Area("Mystery Woods", "Mystery Woods", MYSTERY_WOODS, {
		//Events
		EventAccess(&SpokeToKoume, {[]{return true;}}),
		EventAccess(&Mushroom, {[]{return MaskOfScents && AnyBottle;}}),//Base logic expects mushrooms from SS or Woods
		EventAccess(&KoumeSaved, {[]{return AnyBottle;}}),//Add Red Potion requirement for shuffle shops
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_KOTAKE_IN_WOODS, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = Area("Mystery Woods Grotto", "Mystery Woods Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MYSTERY_WOODS, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = Area("Near Swamp Spider House Grotto", "Near Swamp Spider House Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
	});

	areaTable[SOUTHERN_SWAMP_TOP] = Area("Southern Swamp Top Route", "Southern Swamp Top Route", SOUTHERN_SWAMP, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),//just fall off
		Entrance(WOODFALL, {[]{return DekuMask;}}),
	});

	areaTable[DEKU_PALACE] = Area("Deku Palace", "Deku Palace", DEKU_PALACE, {
		//Events
		EventAccess(&Mushroom, {[]{return /*DekuMask || WoodfallClear*/ KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&DekuBabaNuts, {[]{return DekuMask || (WoodfallClear && Fighting);}}),
	},
	{
		//locations
		LocationAccess(DEKU_PALACE_WEST_GARDEN, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		//SOUTHERN_SWAMP_TOP might not be needed but theres two entrances/exits from deku palace that lead to southern swamp
		//BUT only the top route can reach woodfall
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return DekuMask;}}),
		Entrance(DEKU_PALACE_INTERIOR, {[]{return DekuMask && BeansAndWater;}}),
		Entrance(DEKU_PALACE_BEAN_GROTTO, {[]{return DekuMask || WoodfallClear;}}),
		Entrance(DEKU_SHRINE, {[]{return WoodfallClear;}}),
	});

	areaTable[DEKU_PALACE_INTERIOR] = Area("Deku Palace Throne Room", "Deku Palace Throne Room", NONE, {
		//Events
		EventAccess(&DekuPrincessReturned, {[]{return DekuMask && DekuPrincess;}}),
		EventAccess(&WinnerPicture, {[]{return DekuMask && Pictobox;}}),
	},
	{
		//Locations
		LocationAccess(DEKU_PALACE_IMPRISONED_MONKEY, {[] {return DekuMask && Ocarina;}}),
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[]{return true;}}),
	});

	areaTable[DEKU_PALACE_BEAN_GROTTO] = Area("Deku Palace Bean Grotto", "Deku Palace Bean Grotto", NONE, {
		//Events
		EventAccess(&LimitlessBeans, {[]{return true;}}),
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(DEKU_PALACE_BEAN_SELLER, {[] {return true;}}),
		LocationAccess(DEKU_PALACE_BEAN_GROTTO_CHEST, {[] {return BeansAndWater || Hookshot;}}),
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[] {return true;}}),
	});

	areaTable[DEKU_SHRINE] = Area("Deku Shrine", "Deku Shrine", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(DEKU_PALACE_BUTLER_RACE, {[] {return (Fighting || CanUseProjectile) && DekuPrincessReturned;}}),
	},
	{
		//Exits
		Entrance(DEKU_PALACE, {[]{return true;}}),
	});

	areaTable[WOODFALL] = Area("Woodfall", "Woodfall", WOODFALL, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_BRIDGE_CHEST, {[] {return (DekuMask && (Fighting || CanUseProjectile)) || Hookshot;}}),//Fighting or projectile to get past the Hiploop
		LocationAccess(WOODFALL_BEHIND_OWL_CHEST, {[] {return DekuMask && (Fighting || CanUseProjectile);}}),//Fighting or projectile to get past the Hiploop
		LocationAccess(ENTRANCE_TO_WOODFALL_CHEST, {[] {return DekuMask || WoodfallClear || Hookshot;}}),

	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_ENTRANCE, {[]{return DekuMask && CanPlay(SonataOfAwakening);}}),
		Entrance(SOUTHERN_SWAMP_TOP, {[]{return true;}}),
		Entrance(WOODFALL_FAIRY_FOUNTAIN, {[]{return DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_PRINCESS_ROOM, {[]{return WoodfallClear;}}),
	});

	areaTable[WOODFALL_FAIRY_FOUNTAIN] = Area("Woodfall Great Fairy Fountain", "Woodfall Great Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_GREAT_FAIRY, {[] {return StrayFairyCount(WoodfallStrayFairies,15);}}),
	},
	{
		//Exits
		Entrance(WOODFALL, {[]{return true;}}),
	});

	areaTable[PATH_TO_MOUNTAIN_VILLAGE] = Area("Path to Mountain Village", "Path to Mountain Village", PATH_TO_MOUNTAIN_VILLAGE, {
		//Events
	},
	{
		//Locations
		//Path Grotto - requires Bombs & (maybe)Mask of Truth? - has no items just freestanding money
		//Gossip Stones
		LocationAccess(PATH_TO_MV_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(MOUNTAIN_VILLAGE, {[]{return HasExplosives || CanUse(FIRE_ARROWS) || GoronMask;}}),
	});

	areaTable[MOUNTAIN_VILLAGE] = Area("Mountain Village", "Mountain Village", MOUNTAIN_VILLAGE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle && SnowheadClear;}}),
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_FROG_CHOIR, {[] {return SnowheadClear && LaundryFrog && SwampFrog && WoodfallFrog && GreatBayFrog && DonGerosMask;}}),
		LocationAccess(MOUNTAIN_VILLAGE_HUNGRY_GORON, {[] {return GoronMask && RockSirloin;}}),
		LocationAccess(MOUNTAIN_WATERFALL_CHEST, {[] {return SnowheadClear && CanUse(LENS_OF_TRUTH);}}),
		LocationAccess(MOUNTAIN_VILLAGE_KEATON_QUIZ, {[]{return SnowheadClear && KeatonMask && AnySword;}}),
		//Gossip Stones
		LocationAccess(MV_NEAR_FROGS_GOSSIP, {[] {return true;}}),
		LocationAccess(MV_NEAR_GROTTO_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(PATH_TO_MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
		Entrance(GORON_GRAVEYARD, {[]{return CanUse(LENS_OF_TRUTH);}}),
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
		Entrance(MOUNTAIN_SMITHY, {[]{return true;}}),
		Entrance(MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO, {[]{return SnowheadClear;}}),
	});

	areaTable[GORON_GRAVEYARD] = Area("Goron Graveyard", "Goron Graveyard", NONE, {
		//Events
		EventAccess(&HotSpringWater, {[]{return GoronMask && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_DARMANI, {[] {return CanUse(LENS_OF_TRUTH) && CanPlay(SongOfHealing);}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[MOUNTAIN_SMITHY] = Area("Mountain Smith", "Mountain Smith", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_ONE, {[] {return AnyWallet && AnyBSword && (HotSpringWater || SnowheadClear || CanUse(FIRE_ARROWS));}}), //Need to check for B sword
		LocationAccess(MOUNTAIN_VILLAGE_SMITH_DAY_TWO, {[] {return GoronRaceBottle && AnyWallet && AnyBSword && (HotSpringWater || SnowheadClear || CanUse(FIRE_ARROWS));}}), //Currently need at least one progressive wallet as these are not independent checks
	    //Hot Spring Water may not be viable in ER, can timer be removed?
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = Area("Mountain Village Spring Water Grotto", "Mountain Village Spring Water Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
	});

	areaTable[TWIN_ISLANDS] = Area("Twin Islands", "Twin Islands", TWIN_ISLANDS, {
		//Events
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
	},
	 {
		//Locations
		LocationAccess(TWIN_ISLANDS_UNDERWATER_RAMP_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
		LocationAccess(TWIN_ISLANDS_CAVE_CHEST, {[] {return SnowheadClear && ZoraMask;}}),
		LocationAccess(TWIN_ISLANDS_LULLABY_INTRO, {[] {return SpokeToBabyGoron && GoronMask && (HotSpringWater || CanUse(FIRE_ARROWS));}}),//Hot Spring Water may not be viable in ER, can timer be removed?
		LocationAccess(TINGLE_TWIN_ISLANDS_SH, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_TWIN_ISLANDS_RR, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_TWIN_ISLANDS_SH_SPRING, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_TWIN_ISLANDS_RR_SPRING, {[]{return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(GORON_RACETRACK, {[]{return PowderKeg && GoronMask;}}),
		Entrance(TWIN_ISLANDS_SPRING_WATER_GROTTO, {[]{return (HotSpringWater || CanUse(FIRE_ARROWS)) || SnowheadClear;}}),//Hot Spring Water may not be viable in ER, can timer be removed?
		Entrance(GORON_VILLAGE, {[]{return true;}}),
	});

	areaTable[GORON_RACETRACK] = Area("Goron Racetrack", "Goron Racetrack", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(TWIN_ISLANDS_GORON_RACE, {[] {return SnowheadClear && GoronMask && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
		Entrance(TWIN_ISLANDS_GORON_RACETRACK_GROTTO, {[]{return HasExplosives && (MaskOfTruth || KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED)) && ((Hookshot && CanPlay(ScarecrowSong)) || GoronMask);}}),
	});

	areaTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = Area("Goron Racetrack Grotto", "Goron Racetrack Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(GORON_RACETRACK, {[]{return true;}}),
	});

	areaTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = Area("Twin Islands Hot Spring Water Grotto", "Twin Islands Hot Spring Water Grotto", NONE, {
		//Events
		EventAccess(&HotSpringWater, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
	},
	{
		//Locations
		LocationAccess(HOT_SPRING_WATER_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE] = Area("Goron Village", "Goron Village", GORON_VILLAGE, {
		//Events
		//Owl talk?
	},
	{
		//Locations
		LocationAccess(GORON_VILLAGE_POWDER_KEG_CHALLENGE, {[] {return GoronMask && (SnowheadClear || CanUse(FIRE_ARROWS));}}),
		LocationAccess(GORON_VILLAGE_SCRUB_PURCHASE, {[] {return AnyWallet && GoronMask && (ProgressiveBombBag >= 2);}}),
		LocationAccess(GORON_VILLAGE_SCRUB_TRADE, {[] {return DekuMask && SwampTitle;}}),
		LocationAccess(GORON_VILLAGE_LEDGE, {[] {return DekuMask && SwampTitle;}}),
		LocationAccess(GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING, {[] {return GoronMask && (SnowheadClear || CanUse(FIRE_ARROWS));}}),
		LocationAccess(GORON_VILLAGE_SCRUB_PURCHASE_SPRING, {[] {return AnyWallet && GoronMask && (ProgressiveBombBag >= 2);}}),
		LocationAccess(GORON_VILLAGE_SCRUB_TRADE_SPRING, {[] {return DekuMask && SwampTitle;}}),
		LocationAccess(GORON_VILLAGE_LEDGE_SPRING, {[] {return DekuMask && SwampTitle;}}),
	},
	{
		//Exits
		Entrance(GORON_VILLAGE_LENS_CAVE, {[]{return true;}}),
		Entrance(GORON_VILLAGE_INTERIOR, {[]{return GoronMask || CanUse(FIRE_ARROWS);}}),//Ensure entry is available all days. Explosives do not work here
		Entrance(TWIN_ISLANDS, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_LENS_CAVE] = Area("Lens of Truth Cave", "Lens of Truth Cave", NONE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(GORON_VILLAGE_LENS_OF_TRUTH_CHEST, {[] {return true;}}),
		LocationAccess(LENS_CAVE_RED_RUPEE, {[] {return CanUse(LENS_OF_TRUTH);}}),
		LocationAccess(LENS_CAVE_PURPLE_RUPEE, {[] {return HasExplosives;}}),//Do not need Lens for this chest
	},
	{
		//Exits
		Entrance(GORON_VILLAGE, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_INTERIOR] = Area("Goron Village Interior", "Goron Village Interior", GORON_VILLAGE, {
		//Events
		EventAccess(&SpokeToBabyGoron, {[]{return true;}}),
		EventAccess(&RockSirloin, {[]{return GoronMask && MagicMeter && (CanUse(FIRE_ARROWS) || (CanPlay(LullabyIntro) && HasFireSourceWithTorch));}}),
	},
	{
		//Locations
		LocationAccess(GORON_VILLAGE_GORON_LULLABY, {[]{return GoronMask && CanPlay(LullabyIntro);}}),
	},
	{
		//Exits
		Entrance(GORON_VILLAGE, {[]{return GoronMask;}}),
		Entrance(GORON_VILLAGE_SHOP, {[]{return true;}}),
	});

	areaTable[GORON_VILLAGE_SHOP] = Area("Goron Village Shop", "Goron Village Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GORON_SHOP_ITEM_1, {[]{return true;}}),
		LocationAccess(GORON_SHOP_ITEM_2, {[]{return true;}}),
		LocationAccess(GORON_SHOP_ITEM_3, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(GORON_VILLAGE_INTERIOR, {[]{return true;}}),
	});

	areaTable[ROAD_TO_SNOWHEAD] = Area("Road To Snowhead", "Road To Snowhead", ROAD_TO_SNOWHEAD, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_SNOWHEAD_PILLAR, {[] {return GoronMask && CanUse(LENS_OF_TRUTH) && Hookshot && CanPlay(ScarecrowSong);}}),

	},
	{
		//Exits
		Entrance(ROAD_TO_SNOWHEAD_GROTTO, {[]{return GoronMask && MagicMeter && HasExplosives && (MaskOfTruth || KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED));}}),
		Entrance(MOUNTAIN_VILLAGE, {[]{return true;}}),
		Entrance(SNOWHEAD, {[]{return GoronMask && MagicMeter;}}),//Trick for no magic?
	});

	areaTable[ROAD_TO_SNOWHEAD_GROTTO] = Area("Road To Snowhead Grotto", "Road to Snowhead Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(ROAD_TO_SNOWHEAD_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
	});

	areaTable[SNOWHEAD] = Area("Snowhead", "Snowhead", SNOWHEAD, {
		//Events
		//SleepyGoron
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return GoronMask && MagicMeter && CanPlay(GoronsLullaby);}}),
		Entrance(SNOWHEAD_FAIRY_FOUNTAIN, {[]{return GoronMask && MagicMeter && CanPlay(GoronsLullaby);}}),
		Entrance(ROAD_TO_SNOWHEAD, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_FAIRY_FOUNTAIN] = Area("Snowhead Fairy Fountain", "Snowhead Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_GREAT_FAIRY, {[] {return StrayFairyCount(SnowheadStrayFairies, 15);}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD, {[]{return true;}}),
	});

	areaTable[MILK_ROAD] = Area("Milk Road", "Milk Road", MILK_ROAD, {
		//Events
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
	},
	{
		//Locations
		LocationAccess(TINGLE_MILK_ROAD_RR, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_MILK_ROAD_GB, {[]{return CanUseProjectile;}}),
		LocationAccess(MILK_ROAD_KEATON_QUIZ, {[] {return KeatonMask;}}),
		//Gossip Stones
		LocationAccess(MR_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return true;}}),
		Entrance(GORMAN_TRACK, {[]{return true;}}),
		Entrance(ROMANI_RANCH, {[]{return true;}}), //Set to True because its open on Day 3 for one potential early check, checks for days 1 and 2 require powderkeg
		//Will add in day
	});

	areaTable[GORMAN_TRACK] = Area("Gorman Track", "Gorman Track", NONE, {
		//Events
		EventAccess(&UsableMysteryMilkBottle, {[] {return MilkQuestStart && CircusLeadersMask && MysteryMilkBottle;}}), // Assumes that if you could start the quest, you can finish it
		EventAccess(&Milk, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(MILK_ROAD_GORMAN_RACE,     {[]{return CanPlay(EponasSong);}}),
		LocationAccess(MILK_ROAD_GORMAN_MILK_BUY, {[]{return AnyBottle;}}),
		LocationAccess(GORMAN_TRACK_MYSTERY_MILK_QUEST, {[] {return MilkQuestStart && CircusLeadersMask;}}),
	},
	{
		//Exits
		Entrance(MILK_ROAD, {[]{return true;}}),
	});

	areaTable[ROMANI_RANCH] = Area("Romani Ranch", "Romani Ranch", ROMANI_RANCH, {
		EventAccess(&Epona, {[]{return Epona || CanPlay(EponasSong);}}),
	},
	{
		//Locations
		LocationAccess(ROMANI_RANCH_ALIEN_DEFENSE, {[] {return GoronMask && PowderKeg && Bow;}}),//Day1 Night
		LocationAccess(ROMANI_RANCH_CREMIA_ESCORT, {[] {return GoronMask && PowderKeg && Bow;}}),//Day2
		LocationAccess(ROMANI_RANCH_ROMANIS_GAME,  {[] {return GoronMask && PowderKeg && Bow;}}),//Day1
		//Gossip Stones
		LocationAccess(RR_ENTRANCE_GOSSIP, {[] {return true;}}),
		LocationAccess(RR_BARN_GOSSIP, {[] {return true;}}),
		LocationAccess(RR_FIELD_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MILK_ROAD, {[]{return true;}}),
		Entrance(DOGGY_RACETRACK, {[]{return true;}}),
		Entrance(CUCCO_SHACK, {[]{return true;}}),
		Entrance(ROMANI_RANCH_HOUSE, {[]{return true;}}),
		Entrance(ROMANI_RANCH_BARN, {[]{return true;}}),
	});

	areaTable[DOGGY_RACETRACK] = Area("Doggy Racetrack", "Doggy Racetrack", NONE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(ROMANI_RANCH_DOG_RACE, {[] {return MaskOfTruth;}}),
		LocationAccess(DOGGY_RACETRACK_ROOF_CHEST, {[] {return Hookshot || BeansAndWater;}}),
		//Gossip Stones
		LocationAccess(DOGGY_RACETRACK_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[CUCCO_SHACK] = Area("Cucco Shack", "Cucco Shack", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROMANI_RANCH_GROG, {[] {return BremenMask;}}),
		//Gossip Stones
		LocationAccess(CUCCO_SHACK_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[ROMANI_RANCH_HOUSE] = Area("Romani Ranch House", "Romani Ranch House", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[ROMANI_RANCH_BARN] = Area("Romani Ranch Barn", "Romani Ranch Barn", NONE, {
		//Events
		EventAccess(&Milk, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(ROMANI_RANCH_COW_1, {[]{return CanPlay(EponasSong) && AnyBottle && PowderKeg && GoronMask;}}),
		LocationAccess(ROMANI_RANCH_COW_2, {[]{return CanPlay(EponasSong) && AnyBottle && PowderKeg && GoronMask;}}),
		LocationAccess(ROMANI_RANCH_COW_3, {[]{return CanPlay(EponasSong) && AnyBottle && PowderKeg && GoronMask;}}),
	},
	{
		//Exits
		Entrance(ROMANI_RANCH, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST] = Area("Great Bay Coast", "Great Bay Coast", GREAT_BAY_COAST, {
		//Events
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(GBC_FISHERMAN_GAME, {[] {return GreatBayClear && Hookshot;}}),
		LocationAccess(GBC_LEDGE, {[] {return Hookshot && BeansAndWater && AnyBottle;}}),
		LocationAccess(GBC_MIKAU, {[] {return CanPlay(SongOfHealing);}}),
		LocationAccess(TINGLE_GBC_GB, {[]{ return CanUseProjectile;}}),
		LocationAccess(TINGLE_GBC_ST, {[]{ return CanUseProjectile;}}),
		//Gossip Stones
		LocationAccess(GBC_BENEATH_COW_GROTTO_GOSSIP, {[] {return true;}}),
		LocationAccess(GBC_OUTSIDE_FORTRESS_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return CanPlay(EponasSong);}}),
		Entrance(OSH_ENTRANCE, {[]{return true;}}),
		Entrance(GREAT_BAY_COAST_MARINE_LAB, {[]{return true;}}),
		Entrance(ZORA_CAPE,  {[]{return true;}}),
		Entrance(GREAT_BAY_COAST_GROTTO, {[]{return true;}}),
		Entrance(GREAT_BAY_COAST_COW_GROTTO, {[]{return Hookshot;}}),
		Entrance(PIRATE_FORTRESS_EXTERIOR, {[]{return ZoraMask;}}),
		Entrance(PINNACLE_ROCK, {[]{return ZoraMask;}}),
		Entrance(FISHERMAN_HUT, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST_MARINE_LAB] = Area("Great Bay Marine Lab", "Great Bay Marine Lab", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBC_LAB_FISH, {[] {return Fish;}}),
		LocationAccess(GBC_BABY_ZORAS, {[] {return  ZoraEggCount(ZoraEgg, 7);}}), //ZoraMask && Hookshot && Seahorse && MagicMeter && GoronMask
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST_GROTTO] = Area("Great Bay Coast Grotto", "Great Bay Coast Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(GBC_GROTTO_CHEST, {[] {return CanPlay(EponasSong);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_COAST_COW_GROTTO] = Area("Great Bay Coast Cow Grotto", "Great Bay Coast Cow Grotto", NONE, {
		//Events
		EventAccess(&Milk, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(GBC_GROTTO_COW1, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
		LocationAccess(GBC_GROTTO_COW2, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[FISHERMAN_HUT] = Area("Fisherman's Hut", "Fisherman's Hut", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBC_FISHERMAN_PHOTO, {[] {return PiratePicture && ZoraMask;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
	});

	areaTable[PINNACLE_ROCK] = Area("Pinnacle Rock", "Pinnacle Rock", PINNACLE_ROCK, {
		//Events
	},
	{
		//Locations
		LocationAccess(PINNACLE_ROCK_SEAHORSES,   {[]{return ZoraMask && MagicMeter && Seahorse;}}),
		LocationAccess(PINNACLE_ROCK_UPPER_CHEST, {[]{return ZoraMask && MagicMeter && Seahorse;}}),
		LocationAccess(PINNACLE_ROCK_LOWER_CHEST, {[]{return ZoraMask && MagicMeter && Seahorse;}}),
		LocationAccess(PINNACLE_ROCK_ZORA_EGG1,   {[]{return ZoraMask && MagicMeter && TwoBottles && Seahorse;}}),//Require at least two bottles for lenience
		LocationAccess(PINNACLE_ROCK_ZORA_EGG2,   {[]{return ZoraMask && MagicMeter && TwoBottles && Seahorse;}}),//Require at least two bottles for lenience
		LocationAccess(PINNACLE_ROCK_ZORA_EGG3,   {[]{return ZoraMask && MagicMeter && TwoBottles && Seahorse;}}),//Require at least two bottles for lenience
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return ZoraMask;}}),
	});

	areaTable[ZORA_CAPE] = Area("Zora Cape", "Zora Cape", ZORA_CAPE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(ZORA_CAPE_LIKE_LIKE, {[] {return ZoraMask;}}),
		LocationAccess(ZORA_CAPE_LEDGE_NO_TREE, {[] {return Hookshot;}}),
		LocationAccess(ZORA_CAPE_LEDGE_WITH_TREE, {[] {return Hookshot;}}),
		LocationAccess(ZORA_CAPE_UNDERWATER_CHEST, {[] {return ZoraMask;}}),
		//Gossip Stones
		LocationAccess(ZC_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return true;}}),
		Entrance(ZORA_HALL, {[]{return ZoraMask && MagicMeter;}}),//Trick to avoid Skullfish without shield?
		Entrance(WATERFALL_RAPIDS, {[]{return Hookshot;}}),
		Entrance(GREAT_BAY_FAIRY_FOUNTAIN, {[]{return Hookshot;}}),
		Entrance(ZORA_CAPE_GROTTO, {[]{return CanBlastOrSmash;}}),
		Entrance(GREAT_BAY_TEMPLE_ENTRANCE, {[]{return Hookshot && ZoraMask && MagicMeter && CanPlay(NewWaveBossaNova);}}),//Trick to avoid Skullfish without shield?
		Entrance(ZORA_HALL_BACK_ENTRANCE, {[]{return (ZoraMask && MagicMeter) || Hookshot;}}),//Trick to avoid Skullfish without shield?
	});

	areaTable[WATERFALL_RAPIDS] = Area("Waterfall Rapids", "Waterfall Rapids", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ZORA_CAPE_BEAVER_RACE_1, {[] {return ZoraMask && MagicMeter;}}),
		LocationAccess(ZORA_CAPE_BEAVER_RACE_2, {[] {return ZoraMask && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_FAIRY_FOUNTAIN] = Area("Great Bay Fairy Fountain", "Great Bay Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ZORA_CAPE_GREAT_FAIRY, {[] {return StrayFairyCount(GreatBayStrayFairies, 15);}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	areaTable[ZORA_CAPE_GROTTO] = Area("Zora Cape Grotto", "Zora Cape Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Loactions
		LocationAccess(ZORA_CAPE_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
	});

	
	areaTable[ZORA_HALL] = Area("Zora Hall", "Zora Hall", ZORA_HALL, {
		//Events
	},
	{
		//Locations
		//LocationAccess(ZORA_HALL_STAGE_LIGHTS, {[] {return;}}),
		//ZORA_HALL_BAD_PHOTO_LULU
		//ZORA_HALL_GOOD_PHOTO_LULU

	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_BACK_ENTRANCE, {[]{return true;}}),
		Entrance(ZORA_HALL_EVANS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_LULUS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_JAPAS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_TIJOS_ROOM, {[]{return ZoraMask;}}),
		Entrance(ZORA_HALL_SHOP, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_EVANS_ROOM] = Area("Zora Hall Evan's Room", "Zora Hall Evan's Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ZORA_HALL_EVAN, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_LULUS_ROOM] = Area("Zora Hall Lulu's Room", "Zora Hall Lulu's Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ZORA_HALL_SCRUB_TRADE, {[] {return GoronMask && MountainTitle;}}),
		LocationAccess(ZORA_HALL_LULU_ROOM_LEDGE, {[] {return GoronMask && DekuMask && MountainTitle;}}),
		LocationAccess(ZORA_HALL_SCRUB_PURCHASE, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_JAPAS_ROOM] = Area("Zora Hall Japas' Room", "Zora Hall Japas' Room", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_TIJOS_ROOM] = Area("Zora Hall Tijo's Room", "Zora Hall Tijo's Room", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ZORA_HALL_SHOP] = Area("Zora Hall Shop", "Zora Hall Shop", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ZORA_SHOP_ITEM_1, {[]{return true;}}),
		LocationAccess(ZORA_SHOP_ITEM_2, {[]{return true;}}),
		LocationAccess(ZORA_SHOP_ITEM_3, {[]{return true;}}),
	},
	{
		//Exits
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	//This one might not be needed?? but there's two entrances/exits to Zora Hall that both go to Zora Cape
	areaTable[ZORA_HALL_BACK_ENTRANCE] = Area("Zora Hall Back Entrance", "Zora Hall Back Entrance", ZORA_HALL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return true;}}),
		Entrance(ZORA_HALL, {[]{return true;}}),
	});

	areaTable[ROAD_TO_IKANA] = Area("Road To Ikana", "Road To Ikana", ROAD_TO_IKANA, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_IKANA_PILLAR_CHEST, {[] {return Hookshot;}}),

	},
	{
		//Exits
		Entrance(TERMINA_FIELD, {[]{return CanPlay(EponasSong);}}),
		Entrance(IKANA_GRAVEYARD, {[]{return CanPlay(EponasSong);}}),
		Entrance(IKANA_CANYON, {[]{return Hookshot && (GarosMask || (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && GibdosMask)) && CanPlay(EponasSong);}}),
		Entrance(ROAD_TO_IKANA_GROTTO, {[]{return GoronMask;}}),//Goron-only boulder
	});

	areaTable[ROAD_TO_IKANA_GROTTO] = Area("Road To Ikana Grotto", "Road to Ikana Grotto", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ROAD_TO_IKANA_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD] = Area("Ikana Graveyard", "Ikana Graveyard", IKANA_GRAVEYARD, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST, {[] {return CanPlay(SonataOfAwakening) && Fighting;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE1, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE2, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE3, {[]{return CaptainsHat;}}),
		Entrance(IKANA_GRAVEYARD_GROTTO, {[]{return HasExplosives && (MaskOfTruth || KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED));}}),
	});

	areaTable[IKANA_GRAVEYARD_GROTTO] = Area("Ikana Graveyard Grotto", "Ikana Graveyard Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = Area("Ikana Graveyard Below Grave Day 1", "Ikana Graveyard Below Grave Day 1", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BATS_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BATS_ROOM] = Area("Ikana Graveyard Below Graves Bats Room", "Ikana Graveyard Below Graves Bats Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS, {[] {return CaptainsHat && Fighting;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE1, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_TABLET_ROOM, {[]{return Fighting || DekuMask;}}),//a spin as deku can kill the bats to get the door open
	});

	areaTable[IKANA_GRAVEYARD_TABLET_ROOM] = Area("Ikana Graveyard Below Graves Tablet Room", "Ikana Graveyard Below Graves Tablet Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET, {[] {return Fighting;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BATS_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = Area("Ikana Graveyard Below Graves Day 2", "Ikana Graveyard Below Graves Day 2", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM] = Area("Ikana Graveyard Below Graves Pre Iron Knuckle Room", "Ikana Graveyard Below Graves Pre Iron Knuckle Room", NONE, {
		//Evvents
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE2, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM, {[]{return CanUse(LENS_OF_TRUTH) && HasExplosives && (Fighting || CanUseProjectile);}}),//Projectiles or melee required to get past Skulltulas
	});

	areaTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = Area("Ikana Graveyard Below Graves Iron Knuckle Room", "Ikana Graveyard Below Graves Iron Knuckle Room", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST, {[] {return Fighting;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE2, {[]{return true;}}),
	});

	areaTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = Area("Ikana Graveyard Below Graves Day 3", "Ikana Graveyard Below Graves Day 3", NONE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(DAMPES_HUT, {[]{return true;}}),
	});

	areaTable[DAMPES_HUT] = Area("Dampe's Hut", "Dampe's Hut", NONE, {
		//Events
		EventAccess(&BigPoe, {[]{return (CanUseProjectile && AnyBottle && KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED));}}),
	},
	{
		//Locations
		LocationAccess(IKANA_GRAVEYARD_DAMPE_DIGGING, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(IKANA_GRAVEYARD, {[]{return true;}}),
		Entrance(IKANA_GRAVEYARD_BELOW_GRAVE3, {[]{return false;}}),//I think this one is one way? if not easy fix
	});

	areaTable[IKANA_CANYON] = Area("Lower Ikana Canyon", "Lower Ikana Canyon", IKANA_CANYON, {
		//Events
		EventAccess(&EnterSakonHideout, {[]{return SpokeToKafei;}}),//Sakon spawns if Kafei was met in Laundry Pool
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_LEDGE, {[] {return ZoraMask && OceanTitle && DekuMask;}}),
		LocationAccess(IKANA_CANYON_SCRUB_TRADE, {[] {return ZoraMask && OceanTitle;}}),
		LocationAccess(IKANA_CANYON_SCRUB_PURCHASE, {[]{return AnyWallet && AnyBottle;}}),
		//Gossip Stones
		LocationAccess(IC_DOCK_GOSSIP, {[] {return true;}}),
		LocationAccess(IC_SAKON_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(ROAD_TO_IKANA, {[]{return true;}}),
		Entrance(SAKONS_HIDEOUT, {[]{return EnterSakonHideout;}}),
		Entrance(SECRET_SHRINE_ENTRANCE, {[]{return true;}}),//slow swim but don't NEED zora mask
		Entrance(IKANA_CANYON_SECRET_SHRINE_GROTTO, {[]{return true;}}),
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),//end of river
		Entrance(IKANA_CANYON_UPPER, {[]{return CanUse(ICE_ARROWS) && Hookshot;}}),
	});

	areaTable[IKANA_CANYON_UPPER] = Area("Upper Ikana Canyon", "Upper Ikana Canyon", IKANA_CANYON, {
		//Events
		EventAccess(&WinnerPicture, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && Pictobox;}}),
	},
	{
		//Locations
		LocationAccess(TINGLE_IKANA_CANYON_ST, {[]{return CanUseProjectile;}}),
		LocationAccess(TINGLE_IKANA_CANYON_CT, {[]{return CanUseProjectile;}}),
		//Gossip Stones
		LocationAccess(IC_SPIRIT_HOUSE_GOSSIP, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(MUSIC_BOX_HOUSE, {[]{return MusicBoxOn;}}),
		Entrance(IKANA_CANYON_GREAT_FAIRY_FOUNTAIN, {[]{return true;}}),
		Entrance(IKANA_CANYON_POE_HUT, {[]{return true;}}),
		Entrance(STONE_TOWER, {[]{return true;}}),
		Entrance(IKANA_CANYON_CAVE, {[]{return true;}}),
		Entrance(IKANA_CASTLE_SHORTCUT, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_CAVE] = Area("Ikana Canyon Cave", "Ikana Canyon Cave", NONE, {
		//Events
		EventAccess(&MusicBoxOn, {[]{return CanPlay(SongOfStorms);}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[SAKONS_HIDEOUT] = Area("Sakon's Hideout", "Sakon's Hideout", SAKONS_HIDEOUT, {
		//Events
		EventAccess(&SunMask, {[]{return Fighting;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[MUSIC_BOX_HOUSE] = Area("Music Box House", "Music Box House", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_PAMELAS_FATHER, {[] {return CanPlay(SongOfHealing);}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});
	
	areaTable[IKANA_CANYON_POE_HUT] = Area("Ikana Canyon Poe Hut", "Ikana Canyon Poe Hut", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_POE_HUT_HP, {[] {return Fighting && Bow;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = Area("Ikana Canyon Great Fairy Fountain", "Ikana Canyon Great Fairy Fountain", NONE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_GREAT_FAIRY, {[] {return StrayFairyCount(StoneTowerStrayFairies, 15);}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
	});

	areaTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = Area("Ikana Canyon Near Secret Shrine Grotto", "Ikana Canyon Near Secret Shrine Grotto", NONE, {
		//Events
		EventAccess(&Mushroom, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && AnyBottle && MaskOfScents;}}),
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
	});

	areaTable[STONE_TOWER] = Area("Stone Tower", "Stone Tower", STONE_TOWER, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return CanPlay(ElegyOfEmptiness) && GoronMask && ZoraMask && Hookshot;}}),
		Entrance(INVERTED_STONE_TOWER, {[]{return CanPlay(ElegyOfEmptiness) && GoronMask && ZoraMask && Hookshot && CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[INVERTED_STONE_TOWER] = Area("Inverted Stone Tower", "Inverted Stone Tower", INVERTED_STONE_TOWER, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_INVERTED_LEFT_CHEST, {[] {return BeansAndWater;}}),
		LocationAccess(STONE_TOWER_INVERTED_CENTER_CHEST, {[] {return BeansAndWater;}}),
		LocationAccess(STONE_TOWER_INVERTED_RIGHT_CHEST, {[] {return BeansAndWater;}}),

	},
	{
		//Exits
		Entrance(STONE_TOWER, {[]{return CanUse(LIGHT_ARROWS);}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return true;}}),
	});

	/*--------------------------
	|         DUNGEONS         |
	---------------------------*/

	/*--------------------------
	|      WOODFALL TEMPLE     |
	---------------------------*/

	areaTable[WOODFALL_TEMPLE_ENTRANCE] = Area("Woodfall Temple Entrance", "Woodfall Temple Entrance", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WF_SF_ENTRANCE_FAIRY, {[] {return DekuMask || GreatFairyMask;}}),
		LocationAccess(WF_SF_ENTRANCE_PLATFORM, {[] {return DekuMask || Hookshot;}}),
	},
	{
		//Exits
		Entrance(WOODFALL, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return DekuMask || Hookshot;}}),
	});

	areaTable[WOODFALL_TEMPLE_MAIN_ROOM] = Area("Woodfall Temple Main Room", "Woodfall Temple Main Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&WoodfallPoisonClear, {[]{return CanUse(FIRE_ARROWS);}}),
	},
	{
		//Locations
		LocationAccess(WF_SF_MAIN_ROOM_BUBBLE, {[] {return (Bow || Hookshot) && GreatFairyMask;}}),//Stricter to make sure it can be obtained from the entrance platform
		LocationAccess(WF_SF_JAR_FAIRY, {[] {return DekuMask && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
		LocationAccess(WF_SF_DEKU_BABA, {[] {return Fighting || DekuMask;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return SmallKeys(WoodfallTempleKeys, 1);}}),
		Entrance(WOODFALL_TEMPLE_PLATFORM_ROOM, {[]{return DekuMask || WoodfallPoisonClear;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return WoodfallLadder || WoodfallPoisonClear;}}),//Trick for hookshot on moth torch?
	});

	areaTable[WOODFALL_TEMPLE_UPPER_MAIN_ROOM] = Area("Woodfall Temple Main Room 2F", "Woodfall Temple Main Room 2F", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&WoodfallPoisonClear, {[]{return Bow;}}),
		EventAccess(&WoodfallLadder, {[]{return true;}}),
	},
	{
		//Locations
		LocationAccess(WF_SF_MAIN_ROOM_SWITCH, {[] {return DekuMask;}}),//Torch is not hookshotable
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),//just jump
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_DRAGONFLY_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_PRE_BOSS_ROOM, {[]{return Bow;}}),
	});

	areaTable[WOODFALL_TEMPLE_PLATFORM_ROOM] = Area("Woodfall Temple Platform Room", "Woodfall Temple Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_SMALL_KEY_CHEST, {[] {return DekuMask || Hookshot;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return Bow && DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_MAP_ROOM, {[]{return DekuMask || Hookshot;}}),
	}),

	areaTable[WOODFALL_TEMPLE_MAP_ROOM] = Area("Woodfall Temple Map Room", "Woodfall Temple Map Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_MAP_CHEST, {[] {return DekuMask || (GoronMask && KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED));}}),//Turtle can be flipped with Goron pound
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM] = Area("Woodfall Temple Upper Platform Room", "Woodfall Temple Upper Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WF_SF_PLATFORM_ROOM_BEEHIVE, {[] {return CanUseProjectile && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BOSS_KEY_ROOM, {[]{return Bow && DekuMask;}}),
		Entrance(WOODFALL_TEMPLE_BOW_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_BOSS_KEY_ROOM] = Area("Woodfall Temple Boss Key Room", "Woodfall Temple Boss Key Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&WoodfallFrog, {[]{return (DekuMask || (GoronMask && KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED))) && Fighting && Bow && DonGerosMask;}}),//Turtle can be flipped with Goron pound
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_BOSS_KEY_CHEST, {[] {return (DekuMask || (GoronMask && KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED))) && Fighting && Bow;}}),//Turtle can be flipped with Goron pound
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_BOW_ROOM] = Area("Woodfall Temple Bow Room", "Woodfall Temple Bow Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_HEROS_BOW_CHEST, {[] {return Fighting;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_BRIDGE_ROOM] = Area("Woodfall Temple Bridge Room", "Woodfall Temple Bridge Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
		LocationAccess(WF_SF_BRIDGE_ROOM_BEEHIVE, {[] {return CanUseProjectile && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
		LocationAccess(WF_SF_SKULLTULA, {[] {return Fighting && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_COMPASS_ROOM, {[]{return CanUse(FIRE_ARROWS) || HasFireSourceWithTorch;}}),
		Entrance(WOODFALL_TEMPLE_DARK_ROOM, {[]{return CanUse(FIRE_ARROWS) || HasFireSourceWithTorch;}}),
	});

	areaTable[WOODFALL_TEMPLE_COMPASS_ROOM] = Area("Woodfall Temple Compass Room", "Woodfall Temple Compass Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_COMPASS_CHEST, {[] {return DekuMask || Bow || ZoraMask;}}),//Cannot kill with Hookshot, Trick for Fighting?
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
	});

	areaTable[WOODFALL_TEMPLE_DARK_ROOM] = Area("Woodfall Temple Dark Room", "Woodfall Temple Dark Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WF_SF_DARK_ROOM, {[] {return HasFireSourceWithTorch && Fighting;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_DRAGONFLY_ROOM, {[]{return CanUse(FIRE_ARROWS) || HasFireSourceWithTorch;}})
	});

	areaTable[WOODFALL_TEMPLE_DRAGONFLY_ROOM] = Area("Woodfall Temple Dragonfly Platform Room", "Woodfall Temple Dragonfly Platform Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WF_SF_DRAGONFLY_ROOM_BUBBLE, {[] {return true;}}),//No need for GFM here, Fairy is ground level
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_DARK_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[WOODFALL_TEMPLE_PRE_BOSS_ROOM] = Area("Woodfall Temple Pre-Boss Room", "Woodfall Temple Pre-Boss Room", WOODFALL_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE, {[] {return true;}}),//These fairies are ground level and you can jump on the platforms and run into them
		LocationAccess(WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE, {[] {return true;}}),
		LocationAccess(WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE, {[] {return true;}}),
		LocationAccess(WF_SF_PRE_BOSS_PILLAR_BUBBLE, {[] {return DekuMask || (GreatFairyMask && (Bow || Hookshot));}}), //Can either hit the switch with Deku or make the fairy come to you with bow/hookshot
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_UPPER_MAIN_ROOM, {[]{return true;}}),
		Entrance(WOODFALL_TEMPLE_BOSS_ROOM, {[]{return ((DekuMask && CanUseProjectile) || Hookshot) && BossKeyWoodfallTemple;}}),//Crystal switch and Deku Flower, or Hookshot a torch
	});

	areaTable[WOODFALL_TEMPLE_BOSS_ROOM] = Area("Woodfall Temple Boss Room", "Woodfall Temple Boss Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&WoodfallClear, {[]{return (DekuMask && Nuts && Fighting) || FierceDeityMask;}}),//Trick for beating without Deku/Nuts?
	},
	{
		//Locations
		LocationAccess(ODOLWA, {[]{return (DekuMask && Nuts && Fighting) || FierceDeityMask;}}),//Trick for beating without Deku/Nuts?
		LocationAccess(ODOLWA_HEART_CONTAINER, {[]{return (DekuMask && Nuts && Fighting) || FierceDeityMask;}}),//Trick for beating without Deku/Nuts?
		LocationAccess(GIANTS_OATH_TO_ORDER, {[]{return (DekuMask && Nuts && Fighting) || FierceDeityMask;}}),//Trick for beating without Deku/Nuts?
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_PRE_BOSS_ROOM, {[]{return false;}}),//One-way door
		Entrance(WOODFALL_TEMPLE_PRINCESS_ROOM, {[]{return (DekuMask && Nuts && Fighting) || FierceDeityMask;}}),//Trick for beating without Deku/Bow?
	});

	areaTable[WOODFALL_TEMPLE_PRINCESS_ROOM] = Area("Deku Princess Room", "Deku Princess Room", WOODFALL_TEMPLE, {
		//Events
		EventAccess(&DekuPrincess, {[]{return WoodfallClear && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(WOODFALL_TEMPLE_DEKU_PRINCESS, {[]{return AnyBottle && AnySword;}}),
	},
	{
		//Exits
		Entrance(WOODFALL_TEMPLE_BOSS_ROOM, {[]{return false;}}),//One Way from warp
		Entrance(WOODFALL, {[]{return true;}}),
	});

	/*--------------------------
	|    SNOWHEAD TEMPLE       |
	---------------------------*/

	areaTable[SNOWHEAD_TEMPLE_ENTRANCE] = Area("Snowhead Temple Entrance", "Snowhead Temple Entrance", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_BRIDGE_ROOM, {[]{return GoronMask || (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && ZoraMask);}}),//Zora can also push the block
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return GoronMask && SmallKeys(SnowheadTempleKeys, 1);}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM] = Area("Snowhead Temple Bridge Room", "Snowhead Temple Bridge Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST, {[] {return CanUse(FIRE_ARROWS) && (GoronMask || Hookshot);}}),
		//StrayFairies
		LocationAccess(SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE, {[] {return GoronMask || (GreatFairyMask && (Bow || Hookshot));}}),//Can walk up to it with Goron
		LocationAccess(SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE, {[] {return GreatFairyMask && (Bow || Hookshot);}}),//Unlike N64, does not need Lens
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return GoronMask || (CanUse(FIRE_ARROWS) && Hookshot);}}),
		Entrance(SNOWHEAD_TEMPLE_LOWER_MAP_ROOM, {[]{return GoronMask || (CanUse(FIRE_ARROWS) && Hookshot);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_LOWER_MAP_ROOM] = Area("Snowhead Temple Lower Map Room", "Snowhead Temple Lower Map Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_MAP_ROOM_FAIRY, {[] {return true;}}),//its free floating in the corner
		LocationAccess(SNOWHEAD_TEMPLE_MAP_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_UPPER_MAP_ROOM, {[]{return CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_UPPER_MAP_ROOM] = Area("Snowhead Temple Upper Map Room", "Snowhead Temple Upper Map Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_MAP_ROOM_LEDGE, {[] {return Hookshot || CanUse(LENS_OF_TRUTH);}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_LOWER_MAP_ROOM, {[]{return true;}}),//Just jump down
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_1F] = Area("Snowhead Temple Main Room 1F", "Snowhead Temple Main Room 1F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BASEMENT, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return Bow;}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return CanUse(FIRE_ARROWS);}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return Hookshot && CanPlay(ScarecrowSong);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BASEMENT]= Area("Snowhead Temple Basement", "Snowhead Temple Basement", SNOWHEAD_TEMPLE, {
		//Events
		//Pillar Lowering Switch
	},
	{
		//Locations
		LocationAccess(SH_SF_BASEMENT, {[] {return GoronMask;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM] = Area("Snowhead Temple Lower Pillar Freezards Room", "Snowhead Temple Lower Pillar Freezards Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BASEMENT, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return DekuMask && CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER] = Area("Snowhead Temple Double Block Room Lower", "Snowhead Temple Block Room Lower", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER, {[]{return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && ZoraMask;}}),//Blocks are climbable as Zora
	});

	areaTable[SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER] = Area("Snowhead Temple Double Block Room Upper", "Snowhead Temple Double Block Room Upper", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations	
		LocationAccess(SH_SF_TWIN_BLOCK, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER, {[]{return true;}}),//jump lol
	});

	areaTable[SNOWHEAD_TEMPLE_COMPASS_ROOM] = Area("Snowhead Temple Compass Room", "Snowhead Temple Compass Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_COMPASS_CHEST, {[] {return true;}}),
		
		//Stray Fairies
		LocationAccess(SH_SF_ICE_PUZZLE, {[] {return CanUse(FIRE_ARROWS);}}),
		LocationAccess(SH_SF_CRATE, {[] {return HasExplosives && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),//Trick for Goron pound?
		
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER, {[]{return Hookshot || CanUse(FIRE_ARROWS);}}),
		Entrance(SNOWHEAD_TEMPLE_ICICLE_ROOM, {[]{return HasExplosives;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_ICICLE_ROOM] = Area("Snowhead Temple Icicle Room", "Snowhead Temple Icicle Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST, {[] {return (Bow || ZoraMask) && (CanBlastOrSmash || CanUse(FIRE_ARROWS));}}), //Shoot icicles down or climb as Zora. Make Zora into a trick?
		LocationAccess(SH_SF_ICICLE_ROOM_WALL, {[] {return KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || (Bow && GreatFairyMask && CanUse(LENS_OF_TRUTH));}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM, {[]{return SmallKeys(SnowheadTempleKeys, 2);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM] = Area("Snowhead Temple Goron Switch Puzzle Room", "Snowhead Temple Goron Switch Puzzle Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_CEILING_BUBBLE, {[] {return (Hookshot || Bow) && GreatFairyMask && CanUse(LENS_OF_TRUTH);}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_ICICLE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return GoronMask || CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_2F] = Area("Snowhead Temple Main Room 2F", "Snowhead Temple Main Room 2F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_MAIN_ROOM_WALL, {[] {return Hookshot && CanPlay(ScarecrowSong) && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask) && CanUse(LENS_OF_TRUTH);}}),//Trick for Hookshot-less?
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_UPPER_MAP_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MINIBOSS_ROOM, {[]{return GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_3F, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MINIBOSS_ROOM] = Area("Snowhead Temple Miniboss Room", "Snowhead Temple Miniboss Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST, {[] {return Bow || Fighting;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM] = Area("Snowhead Temple Pillar Freezards Room", "Snowhead Temple Pillar Freezards Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_PILLAR_FREEZARDS, {[] {return CanUse(FIRE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_1F, {[]{return CanUse(FIRE_ARROWS);}}),
		Entrance(SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM, {[]{return CanUse(FIRE_ARROWS);}}),
	});

	areaTable[SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM] = Area("Snowhead Temple Pillar Switch Room", "Snowhead Temple Pillar Switch Room", SNOWHEAD_TEMPLE, {
		//Events
		EventAccess(&SHSwitchPress, {[]{return SHSwitchPress;}}),//Raise Pillar
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_3F] = Area("Snowhead Temple Main Room 3F", "Snowhead Temple Main Room 3F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return SHSwitchPress && GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_2F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_SNOW_ROOM, {[]{return SmallKeys(SnowheadTempleKeys, 3) && GoronMask;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_SNOW_ROOM] = Area("Snowhead Temple Snow Room", "Snowhead Temple Snow Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_SNOW_ROOM_BUBBLE, {[] {return GreatFairyMask && CanUse(LENS_OF_TRUTH) && CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_3F, {[]{return SmallKeys(SnowheadTempleKeys, 3);}}),
		Entrance(SNOWHEAD_TEMPLE_DINOLFOS_ROOM, {[]{return true;}}) //Need Fire Arrows to melt the ice and progress, but you can also just jump down
	});

	areaTable[SNOWHEAD_TEMPLE_MAIN_ROOM_4F] = Area("Snowhead Temple Main Room 4F", "Snowhead Temple Main Room 4F", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_BOSS_ROOM, {[]{return BossKeySnowheadTemple && GoronMask;}}),
		Entrance(SNOWHEAD_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),//jump or use deku mask to fly over
		Entrance(SNOWHEAD_TEMPLE_BOSS_KEY_ROOM, {[]{return false;}}),//One Way Door
		Entrance(SNOWHEAD_TEMPLE_DINOLFOS_ROOM, {[]{return true;}}),//jump or use deku mask to fly over
	});

	areaTable[SNOWHEAD_TEMPLE_DINOLFOS_ROOM] = Area("Snowhead Temple Dinolfos Room", "Snowhead Temple Dinolfos Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SH_SF_DINOLFOS_1, {[] {return Fighting;}}),
		LocationAccess(SH_SF_DINOLFOS_2, {[] {return Fighting;}}),//gotta kill em to get their juices
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_SNOW_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_WIZZROBE_ROOM] = Area("Snowhead Temple Wizzrobe Room", "Snowhead Temple Wizzrobe Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_BOSS_KEY_ROOM, {[]{return Bow || Fighting;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BOSS_KEY_ROOM] = Area("Snowhead Temple Boss Key Room", "Snowhead Temple Boss Key Room", SNOWHEAD_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SNOWHEAD_TEMPLE_BOSS_KEY_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return true;}}),
	});

	areaTable[SNOWHEAD_TEMPLE_BOSS_ROOM] = Area("Snowhead Temple Boss Room", "Snowhead Temple Boss Room", SNOWHEAD_TEMPLE, {
		//Events
		EventAccess(&SnowheadClear, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
	},
	{
		//Locations
		LocationAccess(GOHT, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
		LocationAccess(GOHT_HEART_CONTAINER, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
		LocationAccess(GIANTS_OATH_TO_ORDER, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(SNOWHEAD_TEMPLE_MAIN_ROOM_4F, {[]{return false;}}),
		Entrance(SNOWHEAD, {[]{return GoronMask && CanUse(FIRE_ARROWS);}}),
	});

	/*--------------------------
	|    GREAT BAY TEMPLE     |
	---------------------------*/
	
	areaTable[GREAT_BAY_TEMPLE_ENTRANCE] = Area("Great Bay Temple Entrance", "Great Bay Temple Entrance", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_SF_ENTRANCE_TORCHES, {[] {return CanUse(FIRE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM, {[]{return true;}}),
		Entrance(ZORA_CAPE, {[]{return Hookshot;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM] = Area("Great Bay Temple Water Control Room", "Great Bay Temple Water Control Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&ReverseWaterFlow, {[]{return RedSwitch && RedSwitch2 && Hookshot;}}),
	},
	{
		//Locations
		LocationAccess(GBT_SF_SKULLTULA, {[] {return CanUseProjectile && GreatFairyMask;}}),
		LocationAccess(GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE, {[] {return ZoraMask || ((Bow || Hookshot) && GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),//Needed to trun yellow switch
	});

	areaTable[GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM] = Area("Great Bay Temple Whirlpool Room", "Great Bay Temple Whirlpool Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_SF_WHIRLPOOL_JAR, {[] {return (ZoraMask || Bow) && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
		LocationAccess(GBT_SF_WHIRLPOOL_BARREL, {[] {return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM, {[]{return CanUse(ICE_ARROWS);}}),
		Entrance(GREAT_BAY_TEMPLE_PRE_BOSS_ROOM, {[]{return ReverseWaterFlow && ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return ReverseWaterFlow && ZoraMask;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_RED_SWITCH_ROOM] = Area("Great Bay Temple Red Switch Room", "Great Bay Temple Red Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&RedSwitch, {[]{return CanUse(ICE_ARROWS);}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM, {[]{return ZoraMask && SmallKeys(GreatBayTempleKeys, 1);}}),
	});

	areaTable[GREAT_BAY_TEMPLE_MAP_ROOM] = Area("Great Bay Temple Map Room", "Great Bay Temple Map Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_MAP_CHEST, {[] {return Hookshot || CanUse(ICE_ARROWS);}}),
		LocationAccess(GBT_SF_LEDGE_JAR, {[] {return CanUseProjectile && (GreatFairyMask || CanUse(ICE_ARROWS));}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM, {[]{return CanUse(ICE_ARROWS);}}),
		Entrance(GREAT_BAY_TEMPLE_BIO_BABA_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ReverseWaterFlow;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM] = Area("Great Bay Temple 2nd Red Switch Room", "Great Bay Temple 2nd Red Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&RedSwitch2, {[]{return CanUse(ICE_ARROWS);}}),//Need to freeze chu to get to switch
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_BIO_BABA_ROOM] = Area("Great Bay Temple Bio Baba Room", "Great Bay Temple Bio Baba Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_SF_BIO_BABAS, {[] {return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return ZoraMask;}}),//just swim back, no current
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_COMPASS_ROOM] = Area("Great Bay Temple Compass/Key Room", "Great Bay Temple Compass/Key Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_COMPASS_CHEST, {[] {return CanUseProjectile || Hookshot;}}),//Projectile sever Bio Baba from platforms
		LocationAccess(GBT_SMALL_KEY_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(GBT_SF_DEXIHANDS_JAR, {[] {return CanUseProjectile && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_BIO_BABA_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return !ReverseWaterFlow;}}),
		Entrance(GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM, {[]{return CanUse(ICE_ARROWS) && CanUse(FIRE_ARROWS);}}),
		Entrance(GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM, {[]{return ReverseWaterFlow;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM] = Area("Great Bay Temple Frog MiniBoss", "Great Bay Temple Frog MiniBoss", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreatBayFrog, {[]{return CanUse(ICE_ARROWS) && Fighting && DonGerosMask;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return CanUse(ICE_ARROWS) && Fighting;}}),
		Entrance(GREAT_BAY_TEMPLE_BOSS_KEY_ROOM, {[]{return CanUse(ICE_ARROWS) && Fighting;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_BOSS_KEY_ROOM] = Area("Great Bay Temple Boss Key Room", "Great Bay Temple Boss Key Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_BOSS_KEY_CHEST, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM] = Area("Great Bay Temple Pre-Miniboss Room", "Great Bay Temple Pre-Miniboss Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_RED_SWITCH_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_MINI_BOSS_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_MINI_BOSS_ROOM] = Area("Great Bay Temple Miniboss Room", "Great Bay Temple Miniboss Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_ICE_ARROW_CHEST, {[] {return Fighting && CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM, {[]{return Fighting && CanUseProjectile;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM] = Area("Great Bay Temple Green Switch Room", "Great Bay Temple Green Switch Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenSwitch, {[]{return CanUse(ICE_ARROWS);}}),
	},
	{
		//Locations
		LocationAccess(GBT_SF_GREEN_VALVE, {[] {return Hookshot && CanUse(ICE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return true;}}),
	});

	areaTable[GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM] = Area("Great Bay Temple Waterwheel Room", "Great Bay Temple Waterwheel Room", GREAT_BAY_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBT_SF_WATERWHEEL_ROOM_LOWER, {[] {return Hookshot && CanUse(ICE_ARROWS);}}),
		LocationAccess(GBT_SF_WATERWHEEL_ROOM_UPPER, {[] {return Hookshot && CanUse(ICE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_COMPASS_ROOM, {[]{return false;}}),//Cant go back against current
		Entrance(GREAT_BAY_TEMPLE_SEESAW_ROOM, {[]{return CanUse(ICE_ARROWS) && CanUse(FIRE_ARROWS);}}),//CanUse(FIRE_ARROWS) included to avoid potential softlock
	});

	areaTable[GREAT_BAY_TEMPLE_SEESAW_ROOM] = Area("Great Bay Temple Seesaw Room", "Great Bay Temple Seesaw Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenSwitch2, {[]{return CanUse(FIRE_ARROWS) && CanUse(ICE_ARROWS);}}),
	},
	{
		//Locations
		LocationAccess(GBT_SF_SEESAW_ROOM, {[] {return CanUse(FIRE_ARROWS) && CanUse(ICE_ARROWS);}}),
		LocationAccess(GBT_SF_UNDERWATER_BARREL, {[] {return ZoraMask && (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || GreatFairyMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM, {[]{return true;}}),
		Entrance(GREAT_BAY_TEMPLE_MAP_ROOM, {[]{return CanUse(FIRE_ARROWS) && CanUse(ICE_ARROWS);}}),
	});

	areaTable[GREAT_BAY_TEMPLE_PRE_BOSS_ROOM] = Area("Great Bay Temple Pre-Boss Room", "Great Bay Temple Pre-Boss Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreenValve, {[]{return GreenSwitch && GreenSwitch2;}}),
	},
	{
		//Locations
		LocationAccess(GBT_SF_PRE_BOSS_ROOM_BUBBLE, {[] {return ZoraMask && GreatFairyMask;}}),
		LocationAccess(GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE, {[] {return ZoraMask && GreatFairyMask;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM, {[]{return ZoraMask;}}),
		Entrance(GREAT_BAY_TEMPLE_BOSS_ROOM, {[]{return BossKeyGreatBayTemple && GreenValve;}}),
	});
	
	areaTable[GREAT_BAY_TEMPLE_BOSS_ROOM] = Area("Great Bay Temple Boss Room", "Great Bay Temple Boss Room", GREAT_BAY_TEMPLE, {
		//Events
		EventAccess(&GreatBayClear, {[]{return ZoraMask && MagicMeter && CanUseProjectile;}}),
	},
	{
		//Locations
		LocationAccess(GYORG, {[]{return ZoraMask && MagicMeter && CanUseProjectile;}}),
		LocationAccess(GYORG_HEART_CONTAINER, {[]{return ZoraMask && MagicMeter && CanUseProjectile;}}),
		LocationAccess(GIANTS_OATH_TO_ORDER, {[]{return ZoraMask && MagicMeter && CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_TEMPLE_PRE_BOSS_ROOM, {[]{return true;}}),
		Entrance(ZORA_CAPE, {[]{return ZoraMask && MagicMeter && CanUseProjectile;}}),
	});

	/*--------------------------
	|   STONE TOWER TEMPLE     |
	---------------------------*/

	areaTable[STONE_TOWER_TEMPLE_ENTRANCE] = Area("Stone Tower Temple Entrance", "Stone Tower Temple Entrance", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_STATUE_EYE, {[] {return Bow;}}),
		LocationAccess(ST_SF_DEATH_ARMOS, {[] {return InvertedChestSpawn;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return CanUse(LIGHT_ARROWS);}}),
		Entrance(STONE_TOWER_TEMPLE_EYEGORE_ROOM, {[]{return false;}}),//OneWay
	});

	areaTable[STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM] = Area("Stone Tower Temple Upright Death Armos Room", "Stone Tower Temple Upright Death Armos Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&ArmosRoomLightHole, {[]{return CanPlay(ElegyOfEmptiness) && ZoraMask && GoronMask && HasExplosives;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_ARMOS_ROOM, {[]{return CanPlay(ElegyOfEmptiness) && ZoraMask && GoronMask;}}),
		Entrance(STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM, {[]{return CanPlay(ElegyOfEmptiness) && ZoraMask && GoronMask && SmallKeys(StoneTowerTempleKeys, 1);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_ARMOS_ROOM] = Area("Stone Tower Temple Armos Room", "Stone Tower Temple Armos Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_MAP_CHEST, {[] {return true;}}),
		LocationAccess(STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST, {[] {return (ArmosRoomLightHole && MirrorShield) || CanUse(LIGHT_ARROWS);}}),
		LocationAccess(ST_SF_BASEMENT_LEDGE, {[] {return Hookshot;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM] = Area("Stone Tower Temple Water Bridge Room", "Stone Tower Temple Water Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST, {[] {return DekuMask && ZoraMask;}}),//Zora Mask required to go underneath the bridge
		LocationAccess(ST_SF_BRIDGE_CRYSTAL, {[] {return ZoraMask && CanUse(LIGHT_ARROWS);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM] = Area("Stone Tower Temple Upright Updraft Room", "Stone Tower Temple Upright Updraft Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&UpdraftRoomSwitchUpright, {[]{return ZoraMask;}}),
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_COMPASS_CHEST, {[] {return MirrorShield || CanUse(LIGHT_ARROWS);}}),
		LocationAccess(ST_SF_UNDERWATER, {[] {return ZoraMask && UpdraftRoomSwitchInverted;}}),//Trick to hit the switch with Light+Ice while still upright?
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return MirrorShield || CanUse(LIGHT_ARROWS);}}),
		Entrance(STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM, {[]{return SmallKeys(StoneTowerTempleKeys, 2);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM] = Area("Stone Tower Temple Sun Block Puzzle Room", "Stone Tower Temple Sun Block Puzzle Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_MIRROR_SUN_BLOCK, {[] {return (MirrorShield && GoronMask) || CanUse(LIGHT_ARROWS);}}),
		LocationAccess(ST_SF_MIRROR_SUN_SWITCH, {[] {return (MirrorShield && GoronMask) || CanUse(LIGHT_ARROWS);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_LAVA_ROOM, {[]{return (MirrorShield && GoronMask) || CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_LAVA_ROOM] = Area("Stone Tower Temple Lava Room", "Stone Tower Temple Lava Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_LAVA_ROOM_LEDGE, {[] {return DekuMask;}}),
		LocationAccess(ST_SF_LAVA_ROOM_FIRE_RING, {[] {return GoronMask && DekuMask;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_GARO_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_GARO_ROOM] = Area("Stone Tower Temple Garo Miniboss Room", "Stone Tower Temple Garo Miniboss Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST, {[] {return Fighting;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM, {[]{return Fighting;}}),
		Entrance(STONE_TOWER_TEMPLE_LAVA_ROOM, {[]{return false;}}),//OneWay Door
	});

	areaTable[STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM] = Area("Stone Tower Temple Thin Bridge Room", "Stone Tower Temple Thin Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_THIN_BRIDGE, {[] {return ThinBridgeCrystalChest;}}),//Trick to activate the switch with explosives while still upright?
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_EYEGORE_ROOM, {[]{return Hookshot;}}),//Failsafe
		Entrance(STONE_TOWER_TEMPLE_GARO_ROOM, {[]{return false;}})//One Way Door
	});

	areaTable[STONE_TOWER_TEMPLE_EYEGORE_ROOM] = Area("Stone Tower Temple Eyegore Room", "Stone Tower Temple Eyegore Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_EYEGORE, {[] {return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM, {[]{return false;}}),//One Way Door
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_ENTRANCE] = Area("Inverted Stone Tower Temple Entrance Room", "Inverted Stone Tower Temple Entrance Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_BOSS_WARP, {[] {return CanUse(LIGHT_ARROWS);}}),//Shoot sun switch while upright
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_EYEGORE_ROOM, {[]{return Hookshot && InvertedChestSpawn && SmallKeys(StoneTowerTempleKeys, 4);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM] = Area("Inverted Stone Tower Temple Updraft Room", "Inverted Stone Tower Temple Updraft Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&UpdraftRoomSwitchInverted, {[]{return CanUse(LIGHT_ARROWS);}}),
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST, {[] {return DekuMask;}}),		
		LocationAccess(ST_SF_UPDRAFT_FROZEN_EYE, {[] {return CanUse(FIRE_ARROWS) && DekuMask;}}),
		LocationAccess(ST_SF_UPDRAFT_FIRE_RING, {[] {return UpdraftRoomSwitchUpright && DekuMask && CanPlay(ElegyOfEmptiness);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return DekuMask;}}),//Failsafe
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM, {[]{return DekuMask && SmallKeys(StoneTowerTempleKeys, 3);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM] = Area("Inverted Stone Tower Temple Flipping Lava Room", "Inverted Stone Tower Temple Flipping Lava Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_UPDRAFT_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE, {[]{return CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE] = Area("Inverted Stone Tower Flipping Block Puzzle", "Inverted Stone Tower Flipping Block Puzzle", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_WIZZROBE_ROOM, {[]{return CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_WIZZROBE_ROOM] = Area("Inverted Stone Tower Temple Wizzrobe Room", "Inverted Stone Tower Temple Wizzrobe Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(ST_SF_WIZZROBE, {[] {return (Fighting || CanUseProjectile) && Hookshot;}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM, {[]{return (Fighting || CanUseProjectile) && Hookshot;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM] = Area("Inverted Stone Tower Temple Death Armos Room", "Inverted Stone Tower Temple Death Armos Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST, {[] {return DekuMask && CanPlay(ElegyOfEmptiness) && CanUse(LIGHT_ARROWS);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM] = Area("Inverted Stone Tower Temple Bridge Room", "Inverted Stone Tower Temple Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM, {[]{return DekuMask && CanUseProjectile;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE] = Area("Inverted Stone Tower Temple Entrance Death Armos Ledge", "Inverted Stone Tower Temple Entrance Death Armos Ledge", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&InvertedChestSpawn, {[]{return true;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM] = Area("Inverted Stone Tower Temple Pre-Gomess Hallway", "Inverted Stone Tower Temple Pre-Gomess Hallway", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_GOMESS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_GOMESS_ROOM] = Area("Inverted Stone Tower Temple Gomess Room", "Inverted Stone Tower Temple Gomess Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_BOSS_KEY_CHEST, {[] {return Fighting && CanUse(LIGHT_ARROWS);}}),
		
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM, {[]{return Fighting && CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_EYEGORE_ROOM] = Area("Inverted Stone Tower Eyegore Room", "Inverted Stone Tower Eyegore Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM, {[]{return CanUse(LIGHT_ARROWS);}})
	});

	areaTable[STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM] = Area("Inverted Stone Tower Thin Bridge Room", "Inverted Stone Tower Thin Bridge Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&ThinBridgeCrystalChest, {[]{return Fighting || CanUseProjectile;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_INVERTED_ENTRANCE, {[]{return true;}}),
		Entrance(STONE_TOWER_TEMPLE_PRE_BOSS_ROOM, {[]{return BossKeyStoneTowerTemple && Hookshot;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_PRE_BOSS_ROOM] = Area("Stone Tower Temple Pre-Boss Room", "Stone Tower Temple Pre-Boss Room", STONE_TOWER_TEMPLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE_BOSS_ROOM, {[]{return true;}}),
	});

	areaTable[STONE_TOWER_TEMPLE_BOSS_ROOM] = Area("Stone Tower Temple Boss Room", "Stone Tower Temple Boss Room", STONE_TOWER_TEMPLE, {
		//Events
		EventAccess(&StoneTowerClear, {[]{return CanUse(LIGHT_ARROWS) && CanUse(GIANTS_MASK);}}),
	},
	{
		//Locations
		LocationAccess(STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST, {[]{return CanUse(LIGHT_ARROWS) || CanUse(GIANTS_MASK);}}),
		LocationAccess(TWINMOLD, {[]{return CanUse(LIGHT_ARROWS) && CanUse(GIANTS_MASK);}}),
		LocationAccess(TWINMOLD_HEART_CONTAINER, {[]{return CanUse(LIGHT_ARROWS) && CanUse(GIANTS_MASK);}}),
		LocationAccess(GIANTS_OATH_TO_ORDER, {[]{return CanUse(LIGHT_ARROWS) && CanUse(GIANTS_MASK);}}),
	},
	{
		//Exits
		Entrance(STONE_TOWER_TEMPLE, {[]{return CanUse(LIGHT_ARROWS) && CanUse(GIANTS_MASK);}}),
	});

	areaTable[PIRATE_FORTRESS_EXTERIOR] = Area("Pirates Fortress Exterior", "Pirates Fortress Exterior", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
	},
	{
		//Locations
		LocationAccess(PF_EXTERIOR_LOG_CHEST, {[] {return ZoraMask && MagicMeter;}}),//Trick to avoid Skullfish without shield?
		LocationAccess(PF_EXTERIOR_SAND_CHEST, {[] {return ZoraMask && MagicMeter;}}),//Trick to avoid Skullfish without shield?
		LocationAccess(PF_EXTERIOR_CORNER_CHEST, {[] {return ZoraMask && MagicMeter;}}),//Trick to avoid Skullfish without shield?
	},
	{
		//Exits
		Entrance(ZORA_CAPE, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_MAZE_ROOM, {[]{return ZoraMask && MagicMeter && GoronMask;}}),//Trick to avoid Skullfish without shield?
	});

	areaTable[PIRATE_FORTRESS_MAZE_ROOM] = Area("Pirates Fortress Maze Room", "Pirates Fortress Maze Room", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_MAZE_CHEST, {[] {return ZoraMask;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_CAGE_ROOM, {[]{return ZoraMask;}}),
	});

	areaTable[PIRATE_FORTRESS_CAGE_ROOM] = Area("Pirates Fortress Cage Room", "Pirates Fortress Cage Room", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
		LocationAccess(PF_CAGE_ROOM_SHALLOW_CHEST, {[] {return ZoraMask;}}),
		LocationAccess(PF_CAGE_ROOM_DEEP_CHEST, {[]{return ZoraMask;}}),
		LocationAccess(PF_SEWER_CAGE, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_MAZE_ROOM, {[]{return ZoraMask;}}),
		Entrance(PIRATE_FORTRESS_EXTERIOR_TOP, {[]{return CanUseProjectile;}}),
	});

	areaTable[PIRATE_FORTRESS_EXTERIOR_TOP] = Area("Pirates Fortress Exterior Top", "Pirates Fortress Exterior Top", PIRATE_FORTRESS, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_CAGE_ROOM, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_EXTERIOR, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
	});

	areaTable[PIRATE_FORTRESS_INTERIOR] = Area("Pirates Fortress Interior", "Pirates Fortress Interior", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
	},
	{
		//Locations
		LocationAccess(PF_INT_LOWER_CHEST, {[] {return Hookshot;}}),
		LocationAccess(PF_INT_UPPER_CHEST, {[] {return Hookshot;}}),
		LocationAccess(PF_INT_INVISIBLE_SOLDIER, {[] {return CanUse(LENS_OF_TRUTH) && AnyHealingPotion;}}),
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_EXTERIOR_TOP, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP, {[]{return CanUseProjectile || StoneMask;}}),
		Entrance(PIRATE_FORTRESS_BARREL_MAZE, {[]{return Hookshot;}}),
		Entrance(PIRATE_FORTRESS_LAVA_ROOM, {[]{return Hookshot;}}),
		Entrance(PIRATE_FORTRESS_GUARD_ROOM, {[]{return Hookshot && (CanUseProjectile || StoneMask);}}),
	});

	areaTable[PIRATE_FORTRESS_HOOKSHOT_ROOM] = Area("Pirates Fortress Hookshot Room", "Pirates Fortress Hookshot Room", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
	},
	{
		//Locations
		LocationAccess(PF_INTERIOR_HOOKSHOT_CHEST, {[] {return PirateBees;}}),
		LocationAccess(PF_INT_HOOKSHOT_ROOM_ZORA_EGG, {[]{return PirateBees && Hookshot && ZoraMask && TwoBottles;}}),//Require at least two bottles for lenience
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
	});

	areaTable[PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP] = Area("Pirates Fortress Upper Hookshot Room", "Pirates Fortress Upper Hookshot Room", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PirateBees, {[]{return Bow || (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && (ZoraMask || (DekuMask && MagicMeter)));}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return true;}}),
		Entrance(PIRATE_FORTRESS_HOOKSHOT_ROOM, {[]{return PirateBees;}}),
	});

	areaTable[PIRATE_FORTRESS_BARREL_MAZE] = Area("Pirates Fortress Barrel Maze", "Pirates Fortress Barrel Maze", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
	},
	{
		//Locations
		LocationAccess(PF_INT_BARREL_MAZE_ZORA_EGG, {[]{return Hookshot && ZoraMask && TwoBottles;}}),//Require at least two bottles for lenience
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return (CanUseProjectile || StoneMask) && Fighting;}}),//Projectile/Stone to get past guards, Fighting for swordswoman
	});

	areaTable[PIRATE_FORTRESS_LAVA_ROOM] = Area("Pirate Fortress Lava Room", "Pirate Fortress Lava Room", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
	},
	{
		//Locations
		LocationAccess(PF_INT_TANK_CHEST, {[] {return Hookshot && ZoraMask;}}),
		LocationAccess(PF_INT_LAVA_ROOM_ZORA_EGG, {[]{return Hookshot && ZoraMask && TwoBottles;}}),//Require at least two bottles for lenience
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return (CanUseProjectile || StoneMask) && Fighting;}}),//Projectile/Stone to get past guards, Fighting for swordswoman
	});

	areaTable[PIRATE_FORTRESS_GUARD_ROOM] = Area("Pirates Fortress Guard Room", "Pirates Fortress Guard Room", PIRATE_FORTRESS, {
		//Events
		EventAccess(&PiratePicture, {[]{return Pictobox && StoneMask;}}),//Trick for no Stone Mask?
		EventAccess(&Fish, {[]{return AnyBottle && ZoraMask && Hookshot;}}),
	},
	{
		//Locations
		LocationAccess(PF_INT_GUARD_ROOM_CHEST, {[] {return CanUseProjectile || StoneMask;}}),
		LocationAccess(PF_INT_GUARD_ROOM_ZORA_EGG, {[]{return Hookshot && ZoraMask && TwoBottles;}}),//Require at least two bottles for lenience
	},
	{
		//Exits
		Entrance(PIRATE_FORTRESS_INTERIOR, {[]{return (CanUseProjectile || StoneMask) && Fighting;}}),//Projectile/Stone to get past guards, Fighting for swordswoman
	});

	areaTable[BENEATH_THE_WELL_ENTRANCE] = Area("Beneath The Well Entrance", "Beneath The Well Entrance", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return GibdosMask && (AnyRedPotion || AnyBluePotion);}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return GibdosMask && MagicBean;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_ROOM] = Area("Beneath The Well Left Path", "Beneath The Well Left Path", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM, {[]{return GibdosMask && Fish;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return GibdosMask && SpringWater;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM] = Area("Beneath The Well Hot Water Room", "Beneath The Well Hot Water Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Fish, {[]{return AnyBottle;}}),
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
		EventAccess(&HotSpringWater, {[]{return ZoraMask && AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM] = Area("Beneath The Well Left Path Right Room", "Beneath The Well Left Path Right Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle && (CanUse(FIRE_ARROWS) || HasFireSourceWithTorch);}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN, {[]{return GibdosMask && Bugs;}}),
		Entrance(BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM, {[]{return GibdosMask && Bugs;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN] = Area("Beneath The Well Fairy Fountain", "Beneath The Well Fairy Fountain", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM] = Area("Beneath The Well Left Path Chest", "Beneath The Well Left Path Chest", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
		LocationAccess(WELL_LEFT_PATH_CHEST, {[] {return CanUse(LENS_OF_TRUTH);}}),//invisible chest
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_ROOM] = Area("Beneath The Well Right Path", "Beneath The Well Right Path", BENEATH_THE_WELL, {
		//Events
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_ENTRANCE, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return GibdosMask && Fish;}}),
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return GibdosMask && DekuBabaNuts;}}),
	});

	areaTable[BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM] = Area("Beneath The Well Before Cow/Big Poe Room", "Beneath The Well Before Cow/Big Poe Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_COW_ROOM, {[]{return GibdosMask && HotSpringWater;}}),
		Entrance(BENEATH_THE_WELL_BIG_POE_ROOM, {[]{return GibdosMask && AnyBombBag;}}),
	});

	areaTable[BENEATH_THE_WELL_COW_ROOM] = Area("Beneath The Well Cow Room", "Beneath The Well Cow Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Milk, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(BENEATH_THE_WELL_COW, {[]{return CanPlay(EponasSong) && AnyBottle;}}),
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_BIG_POE_ROOM] = Area("Beneath The Well Big Poe Room", "Beneath The Well Big Poe Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&BigPoe, {[]{return CanUseProjectile && AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM] = Area("Beneath The Well Right Path Left Door Room", "Beneath The Well Right Path Left Door Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&DekuBabaNuts, {[]{return Fighting;}}),
		EventAccess(&DekuBabaSticks, {[]{return Fighting;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM, {[]{return GibdosMask && Bugs;}}),
		Entrance(BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM, {[]{return GibdosMask && BigPoe;}}),
	});

	areaTable[BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM] = Area("Beneath The Well Right Path Chest Room", "Beneath The Well Right Path Chest Room", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
		LocationAccess(WELL_RIGHT_PATH_CHEST, {[] {return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && HasFireSourceWithTorch) || CanUse(FIRE_ARROWS);}}),
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return true;}}),
	});

	areaTable[BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM] = Area("Beneath The Well Pre Mirror Shield Room", "Beneath The Well Pre Mirror Shield Room", BENEATH_THE_WELL, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle && (CanUse(FIRE_ARROWS));}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM, {[]{return true;}}),
		Entrance(BENEATH_THE_WELL_MIRROR_SHIELD_ROOM, {[]{return GibdosMask && Milk;}}),
	});

	areaTable[BENEATH_THE_WELL_MIRROR_SHIELD_ROOM] = Area("Beneath The Well Mirror Shield Room", "Beneath The Well Mirror Shield Room", BENEATH_THE_WELL, {
		//Events
	},
	{
		//Locations
		LocationAccess(BENEATH_THE_WELL_MIRROR_SHIELD_CHEST, {[] {return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && HasFireSourceWithTorch && GibdosMask && Milk && BigPoe) || CanUse(FIRE_ARROWS);}}),//Torch is before the Big Poe Gibdo
	},
	{
		//Exits
		Entrance(BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return MirrorShield || CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_LOWER] = Area("Ikana Castle Lower Exterior", "Ikana Castle Lower Exterior", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_SHORTCUT, {[]{return CanUse(LIGHT_ARROWS);}}),
		Entrance(BENEATH_THE_WELL_MIRROR_SHIELD_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_SHORTCUT] = Area("Ikana Castle Shortcut", "Ikana Castle Shortcut", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON_UPPER, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return CanUse(LIGHT_ARROWS) || (MirrorShield && (Fighting || CanUseProjectile));}}),
	});

	areaTable[IKANA_CASTLE_ENTRANCE] = Area("Ikana Castle Entrance", "Ikana Castle Entrance", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LAVA_BLOCKS_ROOM, {[]{return CanUse(FIRE_ARROWS);}}),
		Entrance(IKANA_CASTLE_RIGHT_ROOM, {[]{return CanUse(FIRE_ARROWS);}}),
		Entrance(IKANA_CASTLE_THRONE_ROOM, {[]{return (IkanaCastleRoofHole && MirrorShield) || CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[IKANA_CASTLE_LAVA_BLOCKS_ROOM] = Area("Ikana Castle Lava Blocks Room", "Ikana Castle Lava Blocks Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CASTLE_NO_FLOOR_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[IKANA_CASTLE_NO_FLOOR_ROOM] = Area("Ikana Castle No Floor Room", "Ikana Castle No Floor Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LAVA_BLOCKS_ROOM, {[]{return DekuMask;}}),
		Entrance(IKANA_CASTLE_LEFT_STAIRWELL, {[]{return DekuMask;}}),
	});

	areaTable[IKANA_CASTLE_LEFT_STAIRWELL] = Area("Ikana Castle Left Stairwell", "Ikana Castle Left Stairwell", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_NO_FLOOR_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_UPPER_LEFT, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_UPPER_LEFT] = Area("Ikana Castle Exterior Upper Left", "Ikana Castle Exterior Upper Left", IKANA_CASTLE, {
		//Events
		EventAccess(&IkanaLightSwitch, {[]{return DekuMask;}}),
	},
	{
		//Locations
		LocationAccess(IKANA_CASTLE_PILLAR, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_LEFT_STAIRWELL, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_RIGHT_ROOM] = Area("Ikana Castle Right Room", "Ikana Castle Right Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
		Entrance(IKANA_CASTLE_WIZZROBE_ROOM, {[]{return (MirrorShield && IkanaLightSwitch) || CanUse(LIGHT_ARROWS);}})
	});

	areaTable[IKANA_CASTLE_WIZZROBE_ROOM] = Area("Ikana Castle Wizzrobe Room", "Ikana Castle Wizzrobe Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_RIGHT_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_RIGHT_STAIRWELL, {[]{return CanUseProjectile || Fighting;}}),
	});

	areaTable[IKANA_CASTLE_RIGHT_STAIRWELL] = Area("Ikana Castle Right Stairwell", "Ikana Castle Right Starwell", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(IKANA_CASTLE_EXTERIOR_UPPER_RIGHT, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_EXTERIOR_UPPER_RIGHT] = Area("Ikana Castle Exterior Upper Right", "Ikana Caastle Exterior Upper Right", IKANA_CASTLE, {
		//Events
		EventAccess(&IkanaCastleRoofHole, {[]{return GoronMask && PowderKeg;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_RIGHT_STAIRWELL, {[]{return true;}}),
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return IkanaCastleRoofHole;}}),//jump in hole
		Entrance(IKANA_CASTLE_EXTERIOR_LOWER, {[]{return true;}}),
	});

	areaTable[IKANA_CASTLE_THRONE_ROOM] = Area("Ikana Castle Throne Room", "Ikana Castle Throne Room", IKANA_CASTLE, {
		//Events
	},
	{
		//Locations
		LocationAccess(IKANA_CASTLE_IKANA_KING, {[] {return MirrorShield && Fighting && CanUse(FIRE_ARROWS);}}),//Light arrows don't work here
	},
	{
		//Exits
		Entrance(IKANA_CASTLE_ENTRANCE, {[]{return true;}}),
	});


	areaTable[SECRET_SHRINE_ENTRANCE] = Area("Secret Shrine Entrance", "Secret Shrine Entrance", SECRET_SHRINE, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
		EventAccess(&SpringWater, {[] {return AnyBottle;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(IKANA_CANYON, {[]{return true;}}),
		Entrance(SECRET_SHRINE_CENTER_ROOM, {[]{return CanUse(LIGHT_ARROWS);}}),
	});

	areaTable[SECRET_SHRINE_CENTER_ROOM] = Area("Secret Shrine Center Room", "Secret Shrine Center Room", SECRET_SHRINE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SECRET_SHRINE_FINAL_CHEST, {[] {return Fighting && TotalHeartContainers(16);}}),
	},
	{
		//Exits
		Entrance(SECRET_SHRINE_ENTRANCE, {[]{return true;}}),
		Entrance(SECRET_SHRINE_DINOLFOS_ROOM, {[]{return true;}}),
		Entrance(SECRET_SHRINE_WIZZROBE_ROOM, {[]{return true;}}),
		Entrance(SECRET_SHRINE_WART_ROOM, {[]{return true;}}),
		Entrance(SECRET_SHRINE_GARO_ROOM, {[]{return true;}}),
	});

	areaTable[SECRET_SHRINE_DINOLFOS_ROOM] = Area("Secret Shrine Dinolfos Room", "Secret Shrine Dinolfos Room", SECRET_SHRINE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SECRET_SHRINE_DINOLFOS_CHEST, {[] {return Fighting && TotalHeartContainers(4);}}),
	},
	{
		//Exits
		Entrance(SECRET_SHRINE_CENTER_ROOM, {[]{return true;}}),
	});

	areaTable[SECRET_SHRINE_WIZZROBE_ROOM] = Area("Secret Shrine Wizzrobe Room", "Secret Shrine Wizzrobe Room", SECRET_SHRINE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SECRET_SHRINE_WIZZROBE_CHEST, {[] {return Fighting && TotalHeartContainers(8);}}),
	},
	{
		//Exits
		Entrance(SECRET_SHRINE_CENTER_ROOM, {[]{return true;}}),
	});

	areaTable[SECRET_SHRINE_WART_ROOM] = Area("Secret Shrine Wart Room", "Secret Shrine Wart Room", SECRET_SHRINE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SECRET_SHRINE_WART_CHEST, {[] {return Fighting && TotalHeartContainers(12);}}),
	},
	{
		//Exits
		Entrance(SECRET_SHRINE_CENTER_ROOM, {[]{return true;}}),
	});

	areaTable[SECRET_SHRINE_GARO_ROOM] = Area("Secret Shrine Garo Room", "Secret Shrine Garo Room", SECRET_SHRINE, {
		//Events
	},
	{
		//Locations
		LocationAccess(SECRET_SHRINE_GARO_CHEST, {[] {return Fighting && TotalHeartContainers(16);}}),
	},
	{
		//Exits
		Entrance(SECRET_SHRINE_CENTER_ROOM, {[]{return true;}}),
	});

	areaTable[THE_MOON_TREE_ROOM] = Area("The Moon Tree Room", "The Moon Tree Room", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_MAJORA_CHILD, {[] {return DekuTrialClear && GoronTrialClear && ZoraTrialClear && LinkTrialClear;}}),	
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),
		Entrance(THE_MOON_BOSS_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_DEKU_TRIAL, {[]{return (TotalMaskCount() >= 1);}}),
		Entrance(THE_MOON_GORON_TRIAL, {[]{return (TotalMaskCount() >= 2);}}),
		Entrance(THE_MOON_ZORA_TRIAL, {[]{return (TotalMaskCount() >= 3);}}),
		Entrance(THE_MOON_LINK_TRIAL_ENTRANCE, {[]{return (TotalMaskCount() >= 4);}}),
	});

	areaTable[THE_MOON_DEKU_TRIAL] = Area("The Moon Deku Trial", "The Moon Deku Trial", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_DEKU_TRIAL_BONUS, {[] {return DekuMask;}}),
		//Gossip Stones
		LocationAccess(MOON_DEKU_GOSSIP_1, {[] {return DekuMask;}}),
		LocationAccess(MOON_DEKU_GOSSIP_2, {[] {return DekuMask;}}),
		LocationAccess(MOON_DEKU_GOSSIP_3, {[] {return DekuMask;}}),
		LocationAccess(MOON_DEKU_GOSSIP_4, {[] {return DekuMask;}}),
		LocationAccess(MOON_DEKU_GOSSIP_5, {[] {return DekuMask;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_DEKU_TRIAL_KID_ROOM, {[]{return DekuMask;}}),
	});

	areaTable[THE_MOON_DEKU_TRIAL_KID_ROOM] = Area("The Moon Deku Trial Kid Room", "The Moon Deku Trial Kid Room", THE_MOON, {
		//Events
		EventAccess(&DekuTrialClear, {[]{return AllMasks;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),//Talk to child
		Entrance(THE_MOON_DEKU_TRIAL, {[]{return true;}}),
	});

	areaTable[THE_MOON_GORON_TRIAL] = Area("The Moon Goron Trial", "The Moon Goron Trial", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_GORON_TRIAL_BONUS, {[] {return GoronMask && MagicMeter;}}),
		//Gossip Stones
		LocationAccess(MOON_GORON_GOSSIP_1, {[] {return GoronMask && MagicMeter;}}),
		LocationAccess(MOON_GORON_GOSSIP_2, {[] {return GoronMask && MagicMeter;}}),
		LocationAccess(MOON_GORON_GOSSIP_3, {[] {return GoronMask && MagicMeter;}}),
		LocationAccess(MOON_GORON_GOSSIP_4, {[] {return GoronMask && MagicMeter;}}),
		LocationAccess(MOON_GORON_GOSSIP_5, {[] {return GoronMask && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_GORON_TRIAL_KID_ROOM, {[]{return GoronMask && MagicMeter;}}),
	});

	areaTable[THE_MOON_GORON_TRIAL_KID_ROOM] = Area("The Moon Goron Trial Kid Room", "The Moon Goron Trial Kid Room", THE_MOON, {
		//Events
		EventAccess(&GoronTrialClear, {[]{return AllMasks;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),//Talk to child
		Entrance(THE_MOON_GORON_TRIAL, {[]{return true;}}),
	});

	areaTable[THE_MOON_ZORA_TRIAL] = Area("The Moon Zora Trial", "The Moon Zora Trial", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_ZORA_TRIAL_BONUS, {[] {return ZoraMask && MagicMeter;}}),
		//Gossip Stones
		LocationAccess(MOON_ZORA_GOSSIP_1, {[] {return ZoraMask && MagicMeter;}}),
		LocationAccess(MOON_ZORA_GOSSIP_2, {[] {return ZoraMask && MagicMeter;}}),
		LocationAccess(MOON_ZORA_GOSSIP_3, {[] {return ZoraMask && MagicMeter;}}),
		LocationAccess(MOON_ZORA_GOSSIP_4, {[] {return ZoraMask && MagicMeter;}}),
		LocationAccess(MOON_ZORA_GOSSIP_5, {[] {return ZoraMask && MagicMeter;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_ZORA_TRIAL_KID_ROOM, {[]{return ZoraMask && MagicMeter;}}),
	});

	areaTable[THE_MOON_ZORA_TRIAL_KID_ROOM] = Area("The Moon Zora Trial Kid Room", "The Moon Zora Trial Kid Room", THE_MOON, {
		//Events
		EventAccess(&ZoraTrialClear, {[]{return AllMasks;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),//Talk to child
		Entrance(THE_MOON_ZORA_TRIAL, {[]{return true;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_ENTRANCE] = Area("The Moon Link Trial Entrance", "The Moon Link Trial Entrance", THE_MOON, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_LINK_TRIAL_DINOLFOS_ROOM, {[]{return true;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_DINOLFOS_ROOM] = Area("The Moon Link Trial Dinolfos Room", "The Moon Link Trial Dinolfos Room", THE_MOON, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_ENTRANCE, {[]{return Fighting;}}),
		Entrance(THE_MOON_LINK_TRIAL_GOSSIP_ROOM_1, {[]{return Fighting;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_GOSSIP_ROOM_1] = Area("The Moon Link Trial Gossip Room 1", "The Moon Link Trial Gossip Room 1", THE_MOON, {
		//Events
	},
	{
		//Locations
		//Gossip Stones
		LocationAccess(MOON_LINK_GOSSIP_1, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_DINOLFOS_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_LINK_TRIAL_GARO_ROOM, {[]{return true;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_GARO_ROOM] = Area("The Moon Link Trial Garo Room", "The Moon Link Trial Garo Room", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_GARO_CHEST, {[] {return Fighting && Hookshot;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_GOSSIP_ROOM_1, {[]{return Fighting;}}),
		Entrance(THE_MOON_LINK_TRIAL_GOSSIP_ROOM_2, {[]{return Fighting && Hookshot;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_GOSSIP_ROOM_2] = Area("The Moon Link Trial Gossip Room 2", "The Moon Link Trial Gossip Room 2", THE_MOON, {
		//Events
	},
	{
		//Locations
		//Gossip Stones
		LocationAccess(MOON_LINK_GOSSIP_2, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_GARO_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_LINK_TRIAL_IRON_KNUCKLE_ROOM, {[]{return true;}}),
	});

	areaTable[THE_MOON_LINK_TRIAL_IRON_KNUCKLE_ROOM] = Area("The Moon Link Trial Iron Knuckle Room", "The Moon Link Trial Iron Knuckle Room", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_IRON_KNUCKLE_CHEST, {[] {return Fighting;}}),
		//Gossip Stones
		LocationAccess(MOON_LINK_GOSSIP_3, {[] {return true;}}),
		LocationAccess(MOON_LINK_GOSSIP_4, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_GOSSIP_ROOM_2, {[]{return Fighting;}}),
		Entrance(THE_MOON_LINK_TRIAL_PIECE_OF_HEART_ROOM, {[]{return Fighting && ((KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && CanPlay(SongOfStorms)) || (HasBombchus && Bow));}}),//SoS in front of the previous Gossip Stone makes the ladder appear
	});

	areaTable[THE_MOON_LINK_TRIAL_PIECE_OF_HEART_ROOM] = Area("The Moon Link Trial Piece of Heart Room", "The Moon Link Trial Piece of Heart Room", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(THE_MOON_LINK_TRIAL_BONUS, {[] {return true;}}),
		//Gossip Stones
		LocationAccess(MOON_LINK_GOSSIP_5, {[] {return true;}}),
	},
	{
		//Exits
		Entrance(THE_MOON_LINK_TRIAL_IRON_KNUCKLE_ROOM, {[]{return true;}}),
		Entrance(THE_MOON_LINK_TRIAL_KID_ROOM, {[]{return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && CanPlay(SongOfStorms)) || (HasBombchus && CanUse(FIRE_ARROWS));}}),//SoS in front of the previous Gossip Stone makes the door open
	});

	areaTable[THE_MOON_LINK_TRIAL_KID_ROOM] = Area("The Moon Link Trial Kid Room", "The Moon Link Trial Kid Room", THE_MOON, {
		//Events
		EventAccess(&LinkTrialClear, {[]{return AllMasks;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(THE_MOON_TREE_ROOM, {[]{return true;}}),//Talk to child
		Entrance(THE_MOON_LINK_TRIAL_PIECE_OF_HEART_ROOM, {[]{return true;}}),
	});

	areaTable[THE_MOON_BOSS_ROOM] = Area("The Moon Majora's Boss Room", "The Moon Majora's Boss Room", THE_MOON, {
		//Events
	},
	{
		//Locations
		LocationAccess(MAJORA, {[] {return Fighting && CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(S_CLOCK_TOWN, {[]{return true;}}),//just play SoT
	});


	areaTable[SSH_ENTRANCE] = Area("Swamp Spider House Entrance", "Swamp Spider House Entrance", SSH, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD, {[] {return SkulltulaCount(SwampSkulltulaTokens, 30);}}),
	},
	{
		//Exits
		Entrance(SOUTHERN_SWAMP, {[]{return true;}}),
		Entrance(SSH_MAIN_ROOM_LOWER, {[]{return true;}}),
	});

	areaTable[SSH_MAIN_ROOM_LOWER] = Area("Swamp Spider House Main Room", "Swamp Spider House Main Room", SSH, {
		//Events
		EventAccess(&SpringWater, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(SSH_MAIN_ROOM_WATER, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MAIN_ROOM_LOWER_LEFT_SOIL, {[] {return Bugs && (Fighting || CanUseProjectile);}}),
		LocationAccess(SSH_MAIN_ROOM_LOWER_RIGHT_SOIL, {[] {return Bugs && (Fighting || CanUseProjectile);}}),
		LocationAccess(SSH_MAIN_ROOM_PILLAR, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MAIN_ROOM_JAR, {[] {return Fighting || CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(SSH_ENTRANCE, {[]{return true;}}),
		Entrance(SSH_MONUMENT_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_POT_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_GOLD_ROOM_LOWER, {[]{return true;}}),
	});

	areaTable[SSH_MAIN_ROOM_UPPER] = Area("Swamp Spider House Main Room Upper", "Swamp Spider House Main Room Upper", SSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(SSH_MAIN_ROOM_UPPER_SOIL, {[] {return Bugs && (Fighting || CanUseProjectile);}}),
		LocationAccess(SSH_MAIN_ROOM_UPPER_PILLAR, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MAIN_ROOM_NEAR_CEILING, {[] {return DekuMask || ZoraMask || Hookshot;}}),
	},
	{
		//Exits
		Entrance(SSH_MAIN_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_MONUMENT_ROOM_UPPER, {[]{return DekuMask;}}),
		Entrance(SSH_POT_ROOM_UPPER, {[]{return DekuMask;}}),
	});

	areaTable[SSH_MONUMENT_ROOM_LOWER] = Area("Swamp Spider House Monument Room", "Swamp Spider House Monument Room", SSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(SSH_MONUMENT_ROOM_CRATE_1, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MONUMENT_ROOM_CRATE_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MONUMENT_ROOM_LOWER_WALL, {[] {return (CanBlastOrSmash && BeansAndWater && (Fighting || CanUseProjectile)) || Hookshot || ZoraMask ;}}),
	},
	{
		//Exits
		Entrance(SSH_MAIN_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_MONUMENT_ROOM_UPPER, {[]{return true;}}),
	});

	areaTable[SSH_MONUMENT_ROOM_UPPER] = Area("Swamp Spider House Monument Room", "Swamp Spider House Monument", SSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(SSH_MONUMENT_ROOM_TORCH, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_MONUMENT_ROOM_ON_MONUMENT, {[] {return Fighting || CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(SSH_MONUMENT_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_MAIN_ROOM_UPPER, {[]{return true;}}),
	});

	areaTable[SSH_POT_ROOM_LOWER] = Area("Swamp Spider House Pot Room", "Swamp Spider House Pot Room", SSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(SSH_POT_ROOM_JAR, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_POT_ROOM_POT_1, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_POT_ROOM_POT_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_POT_ROOM_BEHIND_VINES, {[] {return AnySword;}}),
		LocationAccess(SSH_POT_ROOM_WALL, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_1, {[] {return CanUseProjectile;}}),
		LocationAccess(SSH_POT_ROOM_BEEHIVE_2, {[] {return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(SSH_POT_ROOM_UPPER, {[]{return DekuMask && CanPlay(SonataOfAwakening);}}),
		Entrance(SSH_MAIN_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_MAIN_ROOM_UPPER, {[]{return DekuMask && CanPlay(SonataOfAwakening);}}),
	});

	areaTable[SSH_POT_ROOM_UPPER] = Area("Swamp Spider House Pot Room", "Swamp Spider House Pot Room", SSH, {
		//Events
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SSH_POT_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_GOLD_ROOM_UPPER_RIGHT, {[]{return DekuMask;}}),
		Entrance(SSH_MAIN_ROOM_UPPER, {[]{return DekuMask;}}),
	});

	areaTable[SSH_GOLD_ROOM_LOWER] = Area("Swamp Spider House Gold Room", "Swamp Spider House Gold Room", SSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(SSH_GOLD_ROOM_PILLAR, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_GOLD_ROOM_BEEHIVE, {[] {return CanUseProjectile;}}),
		LocationAccess(SSH_GOLD_ROOM_WALL, {[] {return (GoldRoomLadder && CanUseProjectile) || Hookshot || ZoraMask;}}),
	},
	{
		//Exits
		Entrance(SSH_MAIN_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_GOLD_ROOM_UPPER_LEFT, {[]{return (GoldRoomLadder && CanUseProjectile) || Hookshot;}}),
	});

	areaTable[SSH_GOLD_ROOM_UPPER_LEFT] = Area("Swamp Spider House Gold Room", "Swamp Spider House Gold Room", SSH, {
		//Events
		EventAccess(&GoldRoomLadder, {[]{return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) && HasBombchus) || CanUseProjectile;}}),//Trick for Bombchu to hit the switch from lower?
	},
	{
		//Locations
		LocationAccess(SSH_GOLD_ROOM_NEAR_CEILING, {[] {return (BeansAndWater && (Fighting || CanUseProjectile)) || Hookshot || ZoraMask;}}),
	},
	{
		//Exits
		Entrance(SSH_GOLD_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_TREE_ROOM, {[]{return BeansAndWater;}}),//Trick for beanless jump?
	});

	areaTable[SSH_GOLD_ROOM_UPPER_RIGHT] = Area("Swamp Spider House Gold Room", "Swamp Spider House Gold Room", SSH, {
		//Events
		EventAccess(&GoldRoomLadder, {[]{return Fighting || CanUseProjectile;}}),
	},
	{
		//Locations
	},
	{
		//Exits
		Entrance(SSH_GOLD_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_POT_ROOM_UPPER, {[]{return true;}}),
		Entrance(SSH_TREE_ROOM, {[]{return false;}}),//Trick for jumping over?
	});

	areaTable[SSH_TREE_ROOM] = Area("Swamp Spider House Tree Room", "Swamp Spider House Tree Room", SSH, {
		//Events
		EventAccess(&Bugs, {[]{return AnyBottle;}}),
	},
	{
		//Locations
		LocationAccess(SSH_TREE_ROOM_TREE_1, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_TREE_ROOM_TREE_3, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_1, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_TREE_ROOM_GRASS_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(SSH_TREE_ROOM_BEEHIVE, {[] {return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(SSH_GOLD_ROOM_LOWER, {[]{return true;}}),
		Entrance(SSH_GOLD_ROOM_UPPER_LEFT, {[]{return false;}}),//Trick for jumping over?
		Entrance(SSH_GOLD_ROOM_UPPER_RIGHT, {[]{return false;}}),//Trick for jumping over?
	});


	areaTable[OSH_ENTRANCE] = Area("Ocean Spider House Entrance", "Ocean Spider House Entrance", OSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(GBC_OCEAN_SPIDER_DAY1, {[] {return SkulltulaCount(OceanSkulltulaTokens, 30);}}),

		//Skulltulas
		LocationAccess(OSH_ENTRANCE_LEFT_WALL, {[] {return HasExplosives && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_ENTRANCE_RIGHT_WALL, {[] {return HasExplosives && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_ENTRANCE_WEB, {[] {return HasExplosives && CanUse(FIRE_ARROWS) && (Hookshot || ZoraMask);}}),
	},
	{
		//Exits
		Entrance(GREAT_BAY_COAST, {[]{return GoronMask;}}),
		Entrance(OSH_SECOND_ROOM, {[]{return Hookshot && HasExplosives;}}),
	});

	areaTable[OSH_SECOND_ROOM] = Area("Ocean Spider House Second Room", "Ocean Spider House Second Room", OSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(OSH_SECOND_ROOM_CEILING_EDGE, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_SECOND_ROOM_CEILING_PLANK, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_SECOND_ROOM_JAR, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_SECOND_ROOM_WEBBED_HOLE, {[] {return (CanUse(FIRE_ARROWS) || HasFireSourceWithTorch) && Hookshot;}}),
		LocationAccess(OSH_SECOND_ROOM_WEBBED_POT, {[] {return (CanUse(FIRE_ARROWS) || HasFireSourceWithTorch) && (Fighting || CanUseProjectile);}}),
		LocationAccess(OSH_SECOND_ROOM_UPPER_POT, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_SECOND_ROOM_BEHIND_SKULL_1, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_SECOND_ROOM_BEHIND_SKULL_2, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_SECOND_ROOM_LOWER_POT, {[] {return Fighting || CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(OSH_ENTRANCE, {[]{return true;}}),
		Entrance(OSH_LIBRARY, {[]{return (CanUse(FIRE_ARROWS) || HasFireSourceWithTorch);}}),
		Entrance(OSH_COLORED_SKULLS, {[]{return true;}}),
		Entrance(OSH_STORAGE_ROOM, {[]{return (CanUse(FIRE_ARROWS) || HasFireSourceWithTorch);}}),
	});

	areaTable[OSH_LIBRARY] = Area("Ocean Spider House Library", "Ocean Spider House Library", OSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(OSH_LIBRARY_HOLE_BEHIND_PICTURE, {[] {return Hookshot;}}),
		LocationAccess(OSH_LIBRARY_HOLE_BEHIND_CABINET, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_LIBRARY_ON_CORNER_BOOKSHELF, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_LIBRARY_CEILING_EDGE, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_LIBRARY_BEHIND_BOOKCASE_1, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_LIBRARY_BEHIND_BOOKCASE_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_LIBRARY_BEHIND_PICTURE, {[] {return CanUseProjectile;}}),
	},
	{
		//Exits
		Entrance(OSH_SECOND_ROOM, {[]{return true;}}),
	});

	areaTable[OSH_COLORED_SKULLS] = Area("Ocean Spider House Colored Skulls Room", "Ocean Spider House Colored Skulls Room", OSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(OSH_COLORED_SKULLS_CEILING_EDGE, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_1, {[] {return Fighting || CanUseProjectile;}}),//Just roll into the table to get them down
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_2, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_COLORED_SKULLS_CHANDELIER_3, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_COLORED_SKULLS_BEHIND_PICTURE, {[] {return Hookshot || ZoraMask;}}),
		LocationAccess(OSH_COLORED_SKULLS_POT, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(GBC_OCEAN_SPIDER_CHEST, {[] {return (KnowTheGame.Is(rnd::KnowSetting::KNOW_ADVANCED) || CaptainsHat) && Bow;}}),
	},
	{
		//Exits
		Entrance(OSH_SECOND_ROOM, {[]{return true;}}),
	});

	areaTable[OSH_STORAGE_ROOM] = Area("Ocean Spider House Storage Room", "Ocean Spider House Storage Room", OSH, {
		//Events
	},
	{
		//Locations
		LocationAccess(OSH_STORAGE_ROOM_CEILING_WEB, {[] {return CanUse(FIRE_ARROWS) && (Hookshot || ZoraMask);}}),
		LocationAccess(OSH_STORAGE_ROOM_BEHIND_CRATE, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_STORAGE_ROOM_WALL, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_STORAGE_ROOM_CRATE, {[] {return Fighting || CanUseProjectile;}}),
		LocationAccess(OSH_STORAGE_ROOM_BARREL, {[] {return Hookshot;}}),
	},
	{
		//Exits
		Entrance(OSH_SECOND_ROOM, {[]{return true;}}),
	});

		//Set parent regions
		for (AreaKey i = ROOT; i <= THE_MOON; i++) {
			for (LocationAccess& locPair : areaTable[i].locations) {
			LocationKey location = locPair.GetLocation();
			Location(location)->SetParentRegion(i);
			}
			for (Entrance& exit : areaTable[i].exits) {
			exit.SetParentRegion(i);
			exit.SetName();
			}
		}
}

namespace Areas {
	static std::array < const AreaKey, 270> allAreas = {
		ROOT,
		ROOT_EXITS,
		N_CLOCK_TOWN,
		CLOCK_TOWN_FAIRY_FOUNTAIN,
		CLOCK_TOWN_DEKU_PLAYGROUND,
		E_CLOCK_TOWN,
		STOCKPOTINN,
		STOCKPOTINN_GUEST_ROOM,
		STOCKPOTINN_STAFF_ROOM,
		STOCKPOTINN_GRANDMA_ROOM,
		CLOCK_TOWN_OBSERVATORY,
		CLOCK_TOWN_BAR,
		CLOCK_TOWN_HONEY_DARLING,
		CLOCK_TOWN_TREASURE_CHEST_GAME,
		CLOCK_TOWN_ARCHERY,
		CLOCK_TOWN_MAYOR_HOUSE,
		W_CLOCK_TOWN,
		CLOCK_TOWN_SWORDSMANS_SCHOOL,
		CLOCK_TOWN_POSTMAN_HOUSE,
		CLOCK_TOWN_LOTTERY,
		CLOCK_TOWN_BOMB_SHOP,
		CLOCK_TOWN_TRADING_POST,
		CLOCK_TOWN_CURIOSITY_SHOP,
		S_CLOCK_TOWN,
		CLOCK_TOWER,
		CLOCK_TOWER_ROOF,
		LAUNDRY_POOL,
		LAUNDRY_POOL_KAFEI_HIDEOUT,
		TERMINA_FIELD,
		TERMINA_FIELD_OUTSIDE_OBSERVATORY,
		TERMINA_FIELD_PEAHAT_GROTTO,
		TERMINA_FIELD_DODONGO_GROTTO,
		TERMINA_FIELD_BIO_BABA_GROTTO,
		TERMINA_FIELD_PILLAR_GROTTO,
		TERMINA_FIELD_GRASS_GROTTO,
		TERMINA_FIELD_BUSINESS_SCRUB_GROTTO,
		TERMINA_FIELD_COW_GROTTO,
		TERMINA_FIELD_GOSSIP_STONES_GROTTO,
		ROAD_TO_SOUTHERN_SWAMP,
		ROAD_TO_SOUTHERN_SWAMP_ARCHERY,
		ROAD_TO_SWAMP_GROTTO,
		SOUTHERN_SWAMP,
		SWAMP_TOURIST_CENTER,
		SOUTHERN_SWAMP_HAGS_POTION_SHOP,
		MYSTERY_WOODS,
		SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO,
		SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO,
		SOUTHERN_SWAMP_TOP,
		DEKU_PALACE,
		DEKU_PALACE_INTERIOR,
		DEKU_PALACE_BEAN_GROTTO,
		DEKU_SHRINE,
		WOODFALL,
		WOODFALL_FAIRY_FOUNTAIN,
		PATH_TO_MOUNTAIN_VILLAGE,
		MOUNTAIN_VILLAGE,
		GORON_GRAVEYARD,
		MOUNTAIN_SMITHY,
		MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO,
		TWIN_ISLANDS,
		GORON_RACETRACK,
		TWIN_ISLANDS_GORON_RACETRACK_GROTTO,
		TWIN_ISLANDS_SPRING_WATER_GROTTO,
		GORON_VILLAGE,
		GORON_VILLAGE_LENS_CAVE,
		GORON_VILLAGE_INTERIOR,
		GORON_VILLAGE_SHOP,
		ROAD_TO_SNOWHEAD,
		ROAD_TO_SNOWHEAD_GROTTO,
		SNOWHEAD,
		SNOWHEAD_FAIRY_FOUNTAIN,
		MILK_ROAD,
		GORMAN_TRACK,
		ROMANI_RANCH,
		DOGGY_RACETRACK,
		CUCCO_SHACK,
		ROMANI_RANCH_HOUSE,
		ROMANI_RANCH_BARN,
		GREAT_BAY_COAST,
		GREAT_BAY_COAST_MARINE_LAB,
		GREAT_BAY_COAST_GROTTO,
		GREAT_BAY_COAST_COW_GROTTO,
		FISHERMAN_HUT,
		PINNACLE_ROCK,
		ZORA_CAPE,
		WATERFALL_RAPIDS,
		GREAT_BAY_FAIRY_FOUNTAIN,
		ZORA_CAPE_GROTTO,
		ZORA_HALL,
		ZORA_HALL_EVANS_ROOM,
		ZORA_HALL_LULUS_ROOM,
		ZORA_HALL_JAPAS_ROOM,
		ZORA_HALL_TIJOS_ROOM,
		ZORA_HALL_SHOP,
		ZORA_HALL_BACK_ENTRANCE,
		ROAD_TO_IKANA,
		ROAD_TO_IKANA_GROTTO,
		IKANA_GRAVEYARD,
		IKANA_GRAVEYARD_GROTTO,
		IKANA_GRAVEYARD_BELOW_GRAVE1,
		IKANA_GRAVEYARD_BATS_ROOM,
		IKANA_GRAVEYARD_TABLET_ROOM,
		IKANA_GRAVEYARD_BELOW_GRAVE2,
		IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM,
		IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM,
		IKANA_GRAVEYARD_BELOW_GRAVE3,
		DAMPES_HUT,
		IKANA_CANYON,
		IKANA_CANYON_UPPER,
		IKANA_CANYON_CAVE,
		SAKONS_HIDEOUT,
		MUSIC_BOX_HOUSE,
		IKANA_CANYON_POE_HUT,
		IKANA_CANYON_GREAT_FAIRY_FOUNTAIN,
		IKANA_CANYON_SECRET_SHRINE_GROTTO,
		STONE_TOWER,
		INVERTED_STONE_TOWER,
		WOODFALL_TEMPLE_ENTRANCE,
		WOODFALL_TEMPLE_MAIN_ROOM,
		WOODFALL_TEMPLE_UPPER_MAIN_ROOM,
		WOODFALL_TEMPLE_PLATFORM_ROOM,
		WOODFALL_TEMPLE_MAP_ROOM,
		WOODFALL_TEMPLE_UPPER_PLATFORM_ROOM,
		WOODFALL_TEMPLE_BOSS_KEY_ROOM,
		WOODFALL_TEMPLE_BOW_ROOM,
		WOODFALL_TEMPLE_BRIDGE_ROOM,
		WOODFALL_TEMPLE_COMPASS_ROOM,
		WOODFALL_TEMPLE_DARK_ROOM,
		WOODFALL_TEMPLE_DRAGONFLY_ROOM,
		WOODFALL_TEMPLE_PRE_BOSS_ROOM,
		WOODFALL_TEMPLE_BOSS_ROOM,
		WOODFALL_TEMPLE_PRINCESS_ROOM,
		SNOWHEAD_TEMPLE_ENTRANCE,
		SNOWHEAD_TEMPLE_BRIDGE_ROOM,
		SNOWHEAD_TEMPLE_LOWER_MAP_ROOM,
		SNOWHEAD_TEMPLE_UPPER_MAP_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_1F,
		SNOWHEAD_TEMPLE_BASEMENT,
		SNOWHEAD_TEMPLE_LOWER_PILLAR_FREEZARDS_ROOM,
		SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_LOWER,
		SNOWHEAD_TEMPLE_DOUBLE_BLOCK_ROOM_UPPER,
		SNOWHEAD_TEMPLE_COMPASS_ROOM,
		SNOWHEAD_TEMPLE_ICICLE_ROOM,
		SNOWHEAD_TEMPLE_GORON_SWITCH_PUZZLE_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_2F,
		SNOWHEAD_TEMPLE_MINIBOSS_ROOM,
		SNOWHEAD_TEMPLE_PILLAR_FREEZARDS_ROOM,
		SNOWHEAD_TEMPLE_PILLAR_SWITCH_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_3F,
		SNOWHEAD_TEMPLE_SNOW_ROOM,
		SNOWHEAD_TEMPLE_MAIN_ROOM_4F,
		SNOWHEAD_TEMPLE_DINOLFOS_ROOM,
		SNOWHEAD_TEMPLE_WIZZROBE_ROOM,
		SNOWHEAD_TEMPLE_BOSS_KEY_ROOM,
		SNOWHEAD_TEMPLE_BOSS_ROOM,
		GREAT_BAY_TEMPLE_ENTRANCE,
		GREAT_BAY_TEMPLE_WATER_CONTROL_ROOM,
		GREAT_BAY_TEMPLE_WHIRLPOOL_ROOM,
		GREAT_BAY_TEMPLE_RED_SWITCH_ROOM,
		GREAT_BAY_TEMPLE_MAP_ROOM,
		GREAT_BAY_TEMPLE_RED_SWITCH2_ROOM,
		GREAT_BAY_TEMPLE_BIO_BABA_ROOM,
		GREAT_BAY_TEMPLE_COMPASS_ROOM,
		GREAT_BAY_TEMPLE_FROG_MINIBOSS_ROOM,
		GREAT_BAY_TEMPLE_BOSS_KEY_ROOM,
		GREAT_BAY_TEMPLE_PRE_MINIBOSS_ROOM,
		GREAT_BAY_TEMPLE_MINI_BOSS_ROOM,
		GREAT_BAY_TEMPLE_GREEN_SWITCH_ROOM,
		GREAT_BAY_TEMPLE_WATER_WHEEL_ROOM,
		GREAT_BAY_TEMPLE_SEESAW_ROOM,
		GREAT_BAY_TEMPLE_PRE_BOSS_ROOM,
		GREAT_BAY_TEMPLE_BOSS_ROOM,
		STONE_TOWER_TEMPLE_ENTRANCE,
		STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_WATER_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_UPRIGHT_UPDRAFT_ROOM,
		STONE_TOWER_TEMPLE_SUN_BLOCK_PUZZLE_ROOM,
		STONE_TOWER_TEMPLE_LAVA_ROOM,
		STONE_TOWER_TEMPLE_GARO_ROOM,
		STONE_TOWER_TEMPLE_THIN_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_EYEGORE_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_ENTRANCE,
		STONE_TOWER_TEMPLE_UPDRAFT_ROOM,
		STONE_TOWER_TEMPLE_FLIPPING_LAVA_ROOM,
		STONE_TOWER_TEMPLE_FLIPPING_BLOCK_PUZZLE,
		STONE_TOWER_TEMPLE_WIZZROBE_ROOM,
		STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_ENTRANCE_DEATH_ARMOS_LEDGE,
		STONE_TOWER_TEMPLE_PRE_GOMESS_ROOM,
		STONE_TOWER_TEMPLE_GOMESS_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_EYEGORE_ROOM,
		STONE_TOWER_TEMPLE_INVERTED_THIN_BRIDGE_ROOM,
		STONE_TOWER_TEMPLE_PRE_BOSS_ROOM,
		STONE_TOWER_TEMPLE_BOSS_ROOM,
		PIRATE_FORTRESS_EXTERIOR,
		PIRATE_FORTRESS_MAZE_ROOM,
		PIRATE_FORTRESS_CAGE_ROOM,
		PIRATE_FORTRESS_EXTERIOR_TOP,
		PIRATE_FORTRESS_INTERIOR,
		PIRATE_FORTRESS_HOOKSHOT_ROOM,
		PIRATE_FORTRESS_HOOKSHOT_ROOM_TOP,
		PIRATE_FORTRESS_BARREL_MAZE,
		PIRATE_FORTRESS_LAVA_ROOM,
		PIRATE_FORTRESS_GUARD_ROOM,
		BENEATH_THE_WELL_ENTRANCE,
		BENEATH_THE_WELL_LEFT_PATH_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_HOT_WATER_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_RIGHT_DOOR_ROOM,
		BENEATH_THE_WELL_LEFT_PATH_FAIRY_FOUNTAIN,
		BENEATH_THE_WELL_LEFT_PATH_CHEST_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_ROOM,
		BENEATH_THE_WELL_PRE_COW_AND_BIG_POE_ROOM,
		BENEATH_THE_WELL_COW_ROOM,
		BENEATH_THE_WELL_BIG_POE_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_LEFT_DOOR_ROOM,
		BENEATH_THE_WELL_RIGHT_PATH_CHEST_ROOM,
		BENEATH_THE_WELL_PRE_MIRROR_SHIELD_ROOM,
		BENEATH_THE_WELL_MIRROR_SHIELD_ROOM,
		IKANA_CASTLE_EXTERIOR_LOWER,
		IKANA_CASTLE_SHORTCUT,
		IKANA_CASTLE_ENTRANCE,
		IKANA_CASTLE_LAVA_BLOCKS_ROOM,
		IKANA_CASTLE_NO_FLOOR_ROOM,
		IKANA_CASTLE_LEFT_STAIRWELL,
		IKANA_CASTLE_EXTERIOR_UPPER_LEFT,
		IKANA_CASTLE_RIGHT_ROOM,
		IKANA_CASTLE_WIZZROBE_ROOM,
		IKANA_CASTLE_RIGHT_STAIRWELL,
		IKANA_CASTLE_EXTERIOR_UPPER_RIGHT,
		IKANA_CASTLE_THRONE_ROOM,
		SECRET_SHRINE_ENTRANCE,
		SECRET_SHRINE_CENTER_ROOM,
		SECRET_SHRINE_DINOLFOS_ROOM,
		SECRET_SHRINE_WIZZROBE_ROOM,
		SECRET_SHRINE_WART_ROOM,
		SECRET_SHRINE_GARO_ROOM,
		THE_MOON_DEKU_TRIAL,
		THE_MOON_DEKU_TRIAL_KID_ROOM,
		THE_MOON_GORON_TRIAL,
		THE_MOON_GORON_TRIAL_KID_ROOM,
		THE_MOON_ZORA_TRIAL,
		THE_MOON_ZORA_TRIAL_KID_ROOM,
		THE_MOON_LINK_TRIAL_ENTRANCE,
		THE_MOON_LINK_TRIAL_DINOLFOS_ROOM,
		THE_MOON_LINK_TRIAL_GOSSIP_ROOM_1,
		THE_MOON_LINK_TRIAL_GARO_ROOM,
		THE_MOON_LINK_TRIAL_GOSSIP_ROOM_2,
		THE_MOON_LINK_TRIAL_IRON_KNUCKLE_ROOM,
		THE_MOON_LINK_TRIAL_PIECE_OF_HEART_ROOM,
		THE_MOON_LINK_TRIAL_KID_ROOM,
		THE_MOON_TREE_ROOM,
		THE_MOON_BOSS_ROOM,
		SSH_ENTRANCE,
		SSH_MAIN_ROOM_LOWER,
		SSH_MAIN_ROOM_UPPER,
		SSH_MONUMENT_ROOM_LOWER,
		SSH_MONUMENT_ROOM_UPPER,
		SSH_GOLD_ROOM_LOWER,
		SSH_GOLD_ROOM_UPPER_RIGHT,
		SSH_GOLD_ROOM_UPPER_LEFT,
		SSH_POT_ROOM_LOWER,
		SSH_POT_ROOM_UPPER,
		SSH_TREE_ROOM,
		OSH_ENTRANCE,
		OSH_LIBRARY,
		OSH_SECOND_ROOM,
		OSH_STORAGE_ROOM,
		OSH_COLORED_SKULLS,
	};

	void AccessReset() {
		for (const AreaKey area : allAreas) {
			AreaTable(area)->ResetVariables();
		}
	}

	void ResetAllLocations() {
		for (const AreaKey area : allAreas) {
			AreaTable(area)->ResetVariables();
			//Erase item from every locatoin in this area
			for (LocationAccess& locPair : AreaTable(area)->locations) {
				LocationKey location = locPair.GetLocation();
				Location(location)->ResetVariables();
			}
		}
	}
}//namespace Areas

	Area* AreaTable(const AreaKey areaKey) {
		if (areaKey > KEY_ENUM_MAX) {
			printf("\x1b[1;1HERROR: AREAKEY TOO BIG\n");
			//needs error handling eventually
			//return 0;
		}
		return &(areaTable[areaKey]);
	}
