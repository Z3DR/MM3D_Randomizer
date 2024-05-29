#include "dungeon.hpp"

#include "category.hpp"
#include "item_location.hpp"
#include "pool_functions.hpp"
#include "keys.hpp"

namespace Dungeon {

	DungeonInfo::DungeonInfo(std::string name_, ItemKey map_, ItemKey compass_,
                         ItemKey smallKey_, ItemKey bossKey_, u8 vanillaKeyCount_,
                         std::vector<LocationKey> vanillaLocations_,
						 std::vector<LocationKey> strayLocations_)
  : name(std::move(name_)),
    map(map_),
    compass(compass_),
    smallKey(smallKey_),
    bossKey(bossKey_),
    vanillaKeyCount(vanillaKeyCount_),
    vanillaLocations(std::move(vanillaLocations_)),
	strayLocations(std::move(strayLocations_))  {}

DungeonInfo::~DungeonInfo() = default;

ItemKey DungeonInfo::GetSmallKey() const {
  return smallKey;
}

ItemKey DungeonInfo::GetMap() const {
  return map;
}

ItemKey DungeonInfo::GetCompass() const {
  return compass;
}

ItemKey DungeonInfo::GetBossKey() const {
  return bossKey;
}

void DungeonInfo::PlaceVanillaMap() {
  if (map == NONE) {
    return;
  }

  auto dungeonLocations = GetDungeonLocations();
  auto mapLocation = FilterFromPool(dungeonLocations, [](const LocationKey loc){ return Location(loc)->IsCategory(Category::cVanillaMap); })[0];
  PlaceItemInLocation(mapLocation, map);
}

void DungeonInfo::PlaceVanillaCompass() {
  if (compass == NONE) {
    return;
  }

  auto dungeonLocations = GetDungeonLocations();
  auto compassLocation = FilterFromPool(dungeonLocations, [](const LocationKey loc){ return Location(loc)->IsCategory(Category::cVanillaCompass); })[0];
  PlaceItemInLocation(compassLocation, compass);
}

void DungeonInfo::PlaceVanillaBossKey() {
	if (bossKey == NONE) {
		return;
	}

	auto dungeonLocations = GetDungeonLocations();
	auto bossKeyLocation = FilterFromPool(dungeonLocations, [](const LocationKey loc) { return Location(loc)->IsCategory(Category::cVanillaBossKey); })[0];
	PlaceItemInLocation(bossKeyLocation, bossKey);
}
/*
void DungeonInfo::PlaceVanillaSwampToken() {
	auto dungeonLocations = GetDungeonLocations();
	auto tokenLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cSwampSkulltula);});
	for (auto location : tokenLocations) {
		PlaceItemInLocation(location, SWAMP_SKULLTULA_TOKEN);
	}
}

void DungeonInfo::PlaceVanillaOceanToken() {
	auto dungeonLocations = GetDungeonLocations();
	auto tokenLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cOceanSkulltula);});
	for (auto location : tokenLocations) {
		PlaceItemInLocation(location, OCEANSIDE_SKULLTULA_TOKEN);
	}
}

void DungeonInfo::PlaceVanillaWFStray() {
	auto dungeonLocations = GetDungeonLocations();
	auto wfstrayLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cWFStray);});
	for (auto location : wfstrayLocations) {
		PlaceItemInLocation(location, WF_STRAY_FAIRY);
	}
}

void DungeonInfo::PlaceVanillaSHStray() {
	auto dungeonLocations = GetDungeonLocations();
	auto shstrayLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cSHStray);});
	for (auto location : shstrayLocations) {
		PlaceItemInLocation(location, SH_STRAY_FAIRY);
	}
}

void DungeonInfo::PlaceVanillaGBTStray() {
	auto dungeonLocations = GetDungeonLocations();
	auto gbtstrayLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cGBTStray);});
	for (auto location : gbtstrayLocations) {
		PlaceItemInLocation(location, GBT_STRAY_FAIRY);
	}
}

void DungeonInfo::PlaceVanillaSTStray() {
	auto dungeonLocations = GetDungeonLocations();
	auto ststrayLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){return Location(loc)->IsCategory(Category::cSTStray);});
	for (auto location : ststrayLocations) {
		PlaceItemInLocation(location, ST_STRAY_FAIRY);
	}
}
*/
void DungeonInfo::PlaceVanillaSmallKeys() {
  if (smallKey == NONE) {
    return;
  }

  auto dungeonLocations = GetDungeonLocations();
  auto smallKeyLocations = FilterFromPool(dungeonLocations, [](const LocationKey loc){ return Location(loc)->IsCategory(Category::cVanillaSmallKey); });
  for (auto location : smallKeyLocations) {
	  PlaceItemInLocation(location, smallKey);  
  }
}

//Gets the chosen dungeon locations for a playthrough 
std::vector<LocationKey> DungeonInfo::GetDungeonLocations() const {
  auto locations = vanillaLocations;
  AddElementsToPool(locations, strayLocations);
  return locations;
}

//Gets all dungeon locations 
std::vector<LocationKey> DungeonInfo::GetEveryLocation() const {
  auto locations = vanillaLocations;
  AddElementsToPool(locations, strayLocations);
  return locations;
}

  DungeonInfo WoodfallTemple = DungeonInfo("Woodfall Temple", WOODFALL_TEMPLE_MAP, WOODFALL_TEMPLE_COMPASS, WOODFALL_TEMPLE_SMALL_KEY, WOODFALL_TEMPLE_BOSS_KEY, 1, {
                            //Vanilla Locations
                            WOODFALL_TEMPLE_MAP_CHEST,
                            WOODFALL_TEMPLE_COMPASS_CHEST,
                            WOODFALL_TEMPLE_SMALL_KEY_CHEST,
                            WOODFALL_TEMPLE_HEROS_BOW_CHEST,
							WOODFALL_TEMPLE_BOSS_KEY_CHEST,
                            ODOLWA_HEART_CONTAINER,
                            ODOLWA,
							WOODFALL_TEMPLE_DEKU_PRINCESS,
							},{
							//STRAY FAIRY LOCATIONS
							WF_SF_ENTRANCE_FAIRY,
							WF_SF_ENTRANCE_PLATFORM,
							WF_SF_MAIN_ROOM_BUBBLE,
							WF_SF_MAIN_ROOM_SWITCH,
							WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE,
							WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE,
							WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE,
							WF_SF_PRE_BOSS_PILLAR_BUBBLE,
							WF_SF_DEKU_BABA,
							WF_SF_DRAGONFLY_ROOM_BUBBLE,
							WF_SF_SKULLTULA,
							WF_SF_DARK_ROOM,
							WF_SF_JAR_FAIRY,
							WF_SF_BRIDGE_ROOM_BEEHIVE,
							WF_SF_PLATFORM_ROOM_BEEHIVE,	
                          });

  DungeonInfo SnowheadTemple = DungeonInfo("Snowhead Temple", SNOWHEAD_TEMPLE_MAP, SNOWHEAD_TEMPLE_COMPASS, SNOWHEAD_TEMPLE_SMALL_KEY, SNOWHEAD_TEMPLE_BOSS_KEY, 3, {
                            //Vanilla Locations
                            SNOWHEAD_TEMPLE_MAP_CHEST,
                            SNOWHEAD_TEMPLE_COMPASS_CHEST,
							SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST,
							SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST,
							SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST,
							SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST,
							SNOWHEAD_TEMPLE_BOSS_KEY_CHEST,
							GOHT_HEART_CONTAINER,
							GOHT,
  							},{
							//STRAY FAIRY LOCATIONS
							SH_SF_SNOW_ROOM_BUBBLE,
							SH_SF_CEILING_BUBBLE,
							SH_SF_DINOLFOS_1,
							SH_SF_DINOLFOS_2,
							SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE,
							SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE,
							SH_SF_MAP_ROOM_FAIRY,
							SH_SF_MAP_ROOM_LEDGE,
							SH_SF_BASEMENT,
							SH_SF_TWIN_BLOCK,
							SH_SF_ICICLE_ROOM_WALL,
							SH_SF_MAIN_ROOM_WALL,
							SH_SF_PILLAR_FREEZARDS,
							SH_SF_ICE_PUZZLE,
							SH_SF_CRATE,
							
                          });

  DungeonInfo GreatBayTemple = DungeonInfo("Great Bay Temple", GBT_MAP, GBT_COMPASS, GBT_SMALL_KEY, GBT_BOSS_KEY, 1, {
                            //Vanilla Locations
                            GBT_MAP_CHEST,
                            GBT_COMPASS_CHEST,
                            GBT_SMALL_KEY_CHEST,
                            GBT_ICE_ARROW_CHEST,
							GBT_BOSS_KEY_CHEST,
							GYORG_HEART_CONTAINER,
                            GYORG,
  							},{
							//STRAY FAIRY LOCATIONS
							GBT_SF_SKULLTULA,
							GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE,
							GBT_SF_WATERWHEEL_ROOM_LOWER,
							GBT_SF_WATERWHEEL_ROOM_UPPER,
							GBT_SF_GREEN_VALVE,
							GBT_SF_SEESAW_ROOM,
							GBT_SF_ENTRANCE_TORCHES,
							GBT_SF_BIO_BABAS,
							GBT_SF_UNDERWATER_BARREL,
							GBT_SF_WHIRLPOOL_JAR,
							GBT_SF_WHIRLPOOL_BARREL,
							GBT_SF_DEXIHANDS_JAR,
							GBT_SF_LEDGE_JAR,
							GBT_SF_PRE_BOSS_ROOM_BUBBLE,
							GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE,
                          } );

  DungeonInfo StoneTowerTemple = DungeonInfo("Stone Tower Temple", STONE_TOWER_TEMPLE_MAP, STONE_TOWER_TEMPLE_COMPASS, STONE_TOWER_TEMPLE_SMALL_KEY, STONE_TOWER_TEMPLE_BOSS_KEY, 4, {
                            //Vanilla Locations
                            STONE_TOWER_TEMPLE_MAP_CHEST,
                            STONE_TOWER_TEMPLE_COMPASS_CHEST,
							STONE_TOWER_TEMPLE_BOSS_KEY_CHEST,
							STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST,
							STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST,
							STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST,
							STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST,
							STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST,
							STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST,
							TWINMOLD_HEART_CONTAINER,
							TWINMOLD,
  							},{
							//STRAY FAIRY LOCATIONS
							ST_SF_MIRROR_SUN_BLOCK,
							ST_SF_LAVA_ROOM_LEDGE,
							ST_SF_LAVA_ROOM_FIRE_RING,
							ST_SF_EYEGORE,
							ST_SF_UPDRAFT_FIRE_RING,
							ST_SF_MIRROR_SUN_SWITCH,
							ST_SF_BOSS_WARP,
							ST_SF_WIZZROBE,
							ST_SF_DEATH_ARMOS,
							ST_SF_UPDRAFT_FROZEN_EYE,
							ST_SF_THIN_BRIDGE,
							ST_SF_BASEMENT_LEDGE,
							ST_SF_STATUE_EYE,
							ST_SF_UNDERWATER,
							ST_SF_BRIDGE_CRYSTAL,
							
                          } );

  DungeonInfo SwampSpiderHouse = DungeonInfo("Swamp Spider House", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD,
							//Skulltula Locations
							SSH_MAIN_ROOM_NEAR_CEILING,
							SSH_MAIN_ROOM_WATER,
							SSH_MAIN_ROOM_LOWER_LEFT_SOIL,
							SSH_MAIN_ROOM_UPPER_SOIL,
							SSH_MAIN_ROOM_LOWER_RIGHT_SOIL,
							SSH_MAIN_ROOM_PILLAR,
							SSH_MAIN_ROOM_UPPER_PILLAR,
							SSH_MAIN_ROOM_JAR,
							SSH_MONUMENT_ROOM_CRATE_1,
							SSH_MONUMENT_ROOM_CRATE_2,
							SSH_MONUMENT_ROOM_TORCH,
							SSH_MONUMENT_ROOM_ON_MONUMENT,
							SSH_MONUMENT_ROOM_LOWER_WALL,
							SSH_GOLD_ROOM_NEAR_CEILING,
							SSH_GOLD_ROOM_PILLAR,
							SSH_GOLD_ROOM_BEEHIVE,
							SSH_GOLD_ROOM_WALL,
							SSH_POT_ROOM_JAR,
							SSH_POT_ROOM_POT_1,
							SSH_POT_ROOM_POT_2,
							SSH_POT_ROOM_BEHIND_VINES,
							SSH_POT_ROOM_WALL,
							SSH_POT_ROOM_BEEHIVE_1,
							SSH_POT_ROOM_BEEHIVE_2,
							SSH_TREE_ROOM_TREE_1,
							SSH_TREE_ROOM_TREE_2,
							SSH_TREE_ROOM_TREE_3,
							SSH_TREE_ROOM_GRASS_1,
							SSH_TREE_ROOM_GRASS_2,
							SSH_TREE_ROOM_BEEHIVE,
							},{} );

  DungeonInfo OceansideSpiderHouse = DungeonInfo("Oceanside Spider house", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            GBC_OCEAN_SPIDER_DAY1,
							GBC_OCEAN_SPIDER_CHEST,
							//Skulltula Locations
							OSH_ENTRANCE_LEFT_WALL,
							OSH_ENTRANCE_RIGHT_WALL,
							OSH_ENTRANCE_WEB,
							OSH_LIBRARY_HOLE_BEHIND_PICTURE,
							OSH_LIBRARY_HOLE_BEHIND_CABINET,
							OSH_LIBRARY_ON_CORNER_BOOKSHELF,
							OSH_LIBRARY_CEILING_EDGE,
							OSH_LIBRARY_BEHIND_BOOKCASE_1,
							OSH_LIBRARY_BEHIND_BOOKCASE_2,
							OSH_LIBRARY_BEHIND_PICTURE,
							OSH_SECOND_ROOM_CEILING_EDGE,
							OSH_SECOND_ROOM_CEILING_PLANK,
							OSH_SECOND_ROOM_JAR,
							OSH_SECOND_ROOM_WEBBED_HOLE,
							OSH_SECOND_ROOM_WEBBED_POT,
							OSH_SECOND_ROOM_UPPER_POT,
							OSH_SECOND_ROOM_BEHIND_SKULL_1,
							OSH_SECOND_ROOM_BEHIND_SKULL_2,
							OSH_SECOND_ROOM_LOWER_POT,
							OSH_STORAGE_ROOM_CEILING_WEB,
							OSH_STORAGE_ROOM_BEHIND_CRATE,
							OSH_STORAGE_ROOM_WALL,
							OSH_STORAGE_ROOM_CRATE,
							OSH_STORAGE_ROOM_BARREL,
							OSH_COLORED_SKULLS_CEILING_EDGE,
							OSH_COLORED_SKULLS_CHANDELIER_1,
							OSH_COLORED_SKULLS_CHANDELIER_2,
							OSH_COLORED_SKULLS_CHANDELIER_3,
							OSH_COLORED_SKULLS_BEHIND_PICTURE,
							OSH_COLORED_SKULLS_POT,
							
                          },{} );

  DungeonInfo PiratesFortress = DungeonInfo("Pirates Fortress", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            PF_EXTERIOR_CORNER_CHEST,
							PF_EXTERIOR_LOG_CHEST,
							PF_EXTERIOR_SAND_CHEST,
							PF_SEWER_CAGE,
							PF_CAGE_ROOM_DEEP_CHEST,
							PF_CAGE_ROOM_SHALLOW_CHEST,
							PF_MAZE_CHEST,
							PF_INTERIOR_HOOKSHOT_CHEST,
							PF_INT_GUARD_ROOM_CHEST,
							PF_INT_LOWER_CHEST,
							PF_INT_UPPER_CHEST,
							PF_INT_TANK_CHEST,
							PF_INT_INVISIBLE_SOLDIER,
                            PF_INT_HOOKSHOT_ROOM_ZORA_EGG,
                            PF_INT_GUARD_ROOM_ZORA_EGG,
                            PF_INT_BARREL_MAZE_ZORA_EGG,
                            PF_INT_LAVA_ROOM_ZORA_EGG,
                          },{} );

  DungeonInfo BeneathTheWell = DungeonInfo("Beneath The Well", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            BENEATH_THE_WELL_MIRROR_SHIELD_CHEST,
							WELL_LEFT_PATH_CHEST,
							WELL_RIGHT_PATH_CHEST,
							BENEATH_THE_WELL_COW,
                          },{} );

  DungeonInfo AncientCastleOfIkana = DungeonInfo("Ancient Castle of Ikana", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            IKANA_CASTLE_PILLAR,
							IKANA_CASTLE_IKANA_KING,
                          },{} );

  DungeonInfo SecretShrine = DungeonInfo("Secret Shrine", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            SECRET_SHRINE_DINOLFOS_CHEST,
							SECRET_SHRINE_FINAL_CHEST,
							SECRET_SHRINE_GARO_CHEST,
							SECRET_SHRINE_WART_CHEST,
							SECRET_SHRINE_WIZZROBE_CHEST,
							//SECRET_SHRINE_SOIL,
                          },{} );

  DungeonInfo TheMoon = DungeonInfo("The Moon", NONE, NONE, NONE, NONE, 0, {
                            //Vanilla Locations
                            THE_MOON_DEKU_TRIAL_BONUS,
							THE_MOON_GORON_TRIAL_BONUS,
							THE_MOON_ZORA_TRIAL_BONUS,
							THE_MOON_GARO_CHEST,
							THE_MOON_IRON_KNUCKLE_CHEST,
							THE_MOON_LINK_TRIAL_BONUS,
							THE_MOON_MAJORA_CHILD,
                          },{} );

  
  const DungeonArray dungeonList = {
	&WoodfallTemple,
	&SnowheadTemple,
	&GreatBayTemple,
	&StoneTowerTemple,
	&SwampSpiderHouse,
	&OceansideSpiderHouse,
	&PiratesFortress,
	&BeneathTheWell,
	&AncientCastleOfIkana,
	&SecretShrine,
	&TheMoon,
  };

} //namespace Dungeon
