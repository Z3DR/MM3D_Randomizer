#include "item_pool.hpp"

#include "dungeon.hpp"
#include "fill.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "pool_functions.hpp"
#include "random.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"

using namespace Settings;
using namespace Dungeon;
using namespace rnd;

std::vector<ItemKey> ItemPool = {};
std::vector<ItemKey> PendingJunkPool = {};
std::vector<u8> IceTrapModels = {};
const std::array<ItemKey, 5> dungeonRewards = {
	ODOLWAS_REMAINS,
	GOHTS_REMAINS,
	GYORGS_REMAINS,
	TWINMOLDS_REMAINS,
	//MAJORAS_MASK,
};
const std::array<ItemKey, 17> JunkPoolItems = {
	BOMBS_5,
	BOMBS_10,
	BOMBS_20,
	DEKU_NUTS_5,
	BOMBCHU_5,
	BOMBCHU_10,
	RECOVERY_HEART,
	ARROWS_50,
	ARROWS_10,
	ARROWS_30,
	BLUE_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	SILVER_RUPEE,
	HUGE_RUPEE,
	DEKU_NUTS_10,
	ICE_TRAP,
};
const std::array<ItemKey, 12> alwaysItems = {
	BOMBS_10,
	BOMBS_5,
	BOMBS_5,
	BOMBS_20,
	ARROWS_10,
	ARROWS_30,
	ARROWS_10,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
	RECOVERY_HEART,
};
const std::array<ItemKey, 83> easyItems = {
	KOKIRI_SWORD,
	GREAT_FAIRYS_SWORD,
	HEROS_SHIELD,
	MIRROR_SHIELD,
	DEKU_STICK,
	LAND_TITLE,
	SWAMP_TITLE,
	MOUNTAIN_TITLE,
	OCEAN_TITLE,
	BOMBERS_NOTEBOOK,
	ROOM_KEY,
	LETTER_KAFEI,
	PENDANT_MEMORIES,
	LETTER_MAMA,
	MOONS_TEAR,
	SPIN_ATTACK,
	LENS_OF_TRUTH,
	FIRE_ARROWS,
	ICE_ARROWS,
	LIGHT_ARROWS,
	HOOKSHOT,
	//OCARINA_OF_TIME,
	PICTOGRAPH_BOX,
	POWDER_KEG,
	KEATON_MASK,
	BUNNY_HOOD,
	DEKU_MASK,
	GORON_MASK,
	ZORA_MASK,
	POSTMANS_HAT,
	ALL_NIGHT_MASK,
	BLAST_MASK,
	STONE_MASK,
	GREAT_FAIRYS_MASK,
	BREMEN_MASK,
	DON_GEROS_MASK,
	MASK_OF_SCENTS,
	ROMANIS_MASK,
	CIRCUS_LEADERS_MASK,
	KAFEIS_MASK,
	COUPLES_MASK,
	KAMAROS_MASK,
	GIBDOS_MASK,
	GAROS_MASK,
	CAPTAINS_HAT,
	GIANTS_MASK,
	FIERCE_DIETY_MASK,
	MASK_OF_TRUTH,
	EMPTY_BOTTLE1,
	EMPTY_BOTTLE2,
	BOTTLE_WITH_MILK,
	BOTTLE_WITH_RED_POTION,
	GOLD_DUST,
	CHATEAU_ROMANI,
	RAZOR_SWORD,
	GILDED_SWORD,
	LARGE_QUIVER,
	LARGEST_QUIVER,
	BIG_BOMB_BAG,
	BIGGEST_BOMB_BAG,
	ADULT_WALLET,
	GIANT_WALLET,
	PROGRESSIVE_MAGIC_METER,
	PROGRESSIVE_MAGIC_METER,
	HEART_CONTAINER, //all 4 heart containers
	HEART_CONTAINER,
	HEART_CONTAINER,
	HEART_CONTAINER,
	PIECE_OF_HEART,//16 Pieces of Heart
};
const std::array<ItemKey, 141> normalItems = {
	MAGIC_BEAN,
	DOUBLE_DEFENSE,
	//PIECE_OF_HEART17, 34 pieces of heart
	HEART_CONTAINER, //4 HEART_CONTAINER
	HEART_CONTAINER,
	HEART_CONTAINER,
	HEART_CONTAINER,
};

const std::array<ItemKey, 4> MOON_Vanilla = {
	BLUE_RUPEE,
	BLUE_RUPEE,
	BLUE_RUPEE,
	BLUE_RUPEE,
};
const std::array<ItemKey, 18> normalBottles = {
  EMPTY_BOTTLE1,
  BOTTLE_WITH_MILK,
  BOTTLE_WITH_RED_POTION,
  BOTTLE_WITH_GREEN_POTION,
  BOTTLE_WITH_BLUE_POTION,
  BOTTLE_WITH_FAIRY,
  BOTTLE_WITH_FISH,
  BOTTLE_WITH_BUGS,
  BOTTLE_WITH_POE,
  BOTTLE_WITH_BIG_POE,
  BOTTLE_WITH_MYSTERY_MILK,
  DEKU_PRINCESS,
  CHATEAU_ROMANI,
  BOTTLE_WITH_HOT_SPRING_WATER,
  BOTTLE_WITH_SPRING_WATER,
  GOLD_DUST,
  BOTTLE_WITH_ZORA_EGG,
  SEAHORSE,
};
const std::array<ItemKey, 36> normalRupees = {
	RED_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	HUGE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	SILVER_RUPEE, //added some extra silver instead of red because its more convenient
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
};
const std::array<ItemKey, 36> shopsanityRupees = {
	RED_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	HUGE_RUPEE,
	HUGE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	HUGE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	SILVER_RUPEE, //added some extra silver instead of red because its more convenient
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	SILVER_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	RED_RUPEE,
	PURPLE_RUPEE,
};
const std::array<ItemKey, 4> dekuScrubItems = {
	HUGE_RUPEE,
	BLUE_POTION_REFILL,
	MAGIC_BEAN,
	GREEN_POTION_REFILL,
};

const std::array<ItemKey, 8> chestItems = {
	LENS_OF_TRUTH,
	MAGIC_BEAN,
	HEROS_BOW,
	FIRE_ARROWS,
	ICE_ARROWS,
	LIGHT_ARROWS,
	HOOKSHOT,
	MIRROR_SHIELD,
};

const std::array<ItemKey, 11> songList = {
	//SONG_OF_TIME,
	//SONG_OF_DOUBLE_TIME,
	//INVERTED_SONG_OF_TIME, //SoT not included yet
	SONG_OF_STORMS,
	EPONAS_SONG,
	SONG_OF_HEALING,
	//SONG_OF_SOARING,
	SONATA_OF_AWAKENING,
	GORONS_LULLABY,
	NEW_WAVE_BOSSA_NOVA,
	ELEGY_OF_EMPTINESS,
	OATH_TO_ORDER
};

static void PlaceVanillaSongs() {
	PlaceItemInLocation(HMS_SONG_OF_HEALING, SONG_OF_HEALING);
	PlaceItemInLocation(DEKU_PALACE_IMPRISONED_MONKEY, SONATA_OF_AWAKENING);
	PlaceItemInLocation(GORON_VILLAGE_GORON_LULLABY, GORONS_LULLABY);
	PlaceItemInLocation(ROMANI_RANCH_ROMANIS_GAME, EPONAS_SONG);
	PlaceItemInLocation(GBC_BABY_ZORAS, NEW_WAVE_BOSSA_NOVA);
	PlaceItemInLocation(IKANA_CASTLE_IKANA_KING, ELEGY_OF_EMPTINESS);
	PlaceItemInLocation(IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET, SONG_OF_STORMS);
	PlaceItemInLocation(GIANTS_OATH_TO_ORDER, OATH_TO_ORDER);
};

const std::array<ItemKey, 18> maskList = {
	KEATON_MASK,
	BUNNY_HOOD,
	POSTMANS_HAT,
	ALL_NIGHT_MASK,
	BLAST_MASK,
	STONE_MASK,
	GREAT_FAIRYS_MASK,
	BREMEN_MASK,
	DON_GEROS_MASK,
	MASK_OF_SCENTS,
	ROMANIS_MASK,
	CIRCUS_LEADERS_MASK,
	KAMAROS_MASK,
	GIBDOS_MASK,
	GAROS_MASK,
	CAPTAINS_HAT,
	GIANTS_MASK,
	MASK_OF_TRUTH,
};

static void PlaceVanillaMasks() {
	PlaceItemInLocation(E_CLOCK_TOWN_GORMAN, CIRCUS_LEADERS_MASK);
	PlaceItemInLocation(DEKU_PALACE_BUTLER_RACE, MASK_OF_SCENTS);
	PlaceItemInLocation(E_CLOCK_TOWN_POSTMAN_FREEDOM, POSTMANS_HAT);
	PlaceItemInLocation(IKANA_CANYON_PAMELAS_FATHER, GIBDOS_MASK);
	PlaceItemInLocation(IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST, CAPTAINS_HAT);
	PlaceItemInLocation(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE, KEATON_MASK);
	PlaceItemInLocation(LAUNDRY_POOL_GURU_GURU, BREMEN_MASK);
	PlaceItemInLocation(MILK_ROAD_GORMAN_RACE, GAROS_MASK);
	PlaceItemInLocation(MOUNTAIN_VILLAGE_HUNGRY_GORON, DON_GEROS_MASK);
	PlaceItemInLocation(N_CLOCK_TOWN_GREAT_FAIRY_HUMAN, GREAT_FAIRYS_MASK);
	PlaceItemInLocation(N_CLOCK_TOWN_OLD_LADY, BLAST_MASK);
	PlaceItemInLocation(ROMANI_RANCH_GROG, BUNNY_HOOD);
	PlaceItemInLocation(ROMANI_RANCH_CREMIA_ESCORT, ROMANIS_MASK);
	PlaceItemInLocation(SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD, MASK_OF_TRUTH);
	PlaceItemInLocation(TERMINA_FIELD_KAMARO, KAMAROS_MASK);
	PlaceItemInLocation(W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY, ALL_NIGHT_MASK);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST, GIANTS_MASK);
	PlaceItemInLocation(PF_INT_INVISIBLE_SOLDIER, STONE_MASK);
};

const std::array<ItemKey, 16> mainInventoryList= {
	FIRE_ARROWS,
	ICE_ARROWS,
	LIGHT_ARROWS,
	//MAGIC_BEAN,
	//MAGIC_BEAN_PACK,
	POWDER_KEG,
	PICTOGRAPH_BOX,
	HOOKSHOT,
	//GREAT_FAIRYS_SWORD,
	LENS_OF_TRUTH,
	MIRROR_SHIELD,
	EMPTY_BOTTLE1,
	EMPTY_BOTTLE2,
	BOTTLE_WITH_RED_POTION,
	BOTTLE_WITH_MILK,
	CHATEAU_ROMANI,
	GOLD_DUST,
	BOTTLE_WITH_MYSTERY_MILK,//7 Bottles(currently 7th is empty instead of mystery milk)
	SEAHORSE,
};

static void PlaceVanillaMainInventory() {
	PlaceItemInLocation(SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST, FIRE_ARROWS);
	PlaceItemInLocation(GBT_ICE_ARROW_CHEST, ICE_ARROWS);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST, LIGHT_ARROWS);
	//PlaceItemInLocation(DEKU_PALACE_BEAN_DADDY, MAGIC_BEAN);//Shopsanity
	PlaceItemInLocation(GORON_VILLAGE_POWDER_KEG_CHALLENGE, POWDER_KEG);
	PlaceItemInLocation(SOUTHERN_SWAMP_KOTAKE, PICTOGRAPH_BOX);
	PlaceItemInLocation(PF_INTERIOR_HOOKSHOT_CHEST, HOOKSHOT);
	PlaceItemInLocation(GORON_VILLAGE_LENS_OF_TRUTH_CHEST, LENS_OF_TRUTH);
	PlaceItemInLocation(BENEATH_THE_WELL_MIRROR_SHIELD_CHEST, MIRROR_SHIELD);
	PlaceItemInLocation(SOUTHERN_SWAMP_KOUME, BOTTLE_WITH_RED_POTION);
	PlaceItemInLocation(TWIN_ISLANDS_GORON_RACE, GOLD_DUST);
	PlaceItemInLocation(E_CLOCK_TOWN_AROMA_IN_BAR, CHATEAU_ROMANI);
	PlaceItemInLocation(GORMAN_TRACK_MYSTERY_MILK_QUEST, BOTTLE_WITH_MYSTERY_MILK);
	PlaceItemInLocation(ZORA_CAPE_BEAVER_RACE_1,EMPTY_BOTTLE2);
	PlaceItemInLocation(IKANA_GRAVEYARD_DAMPE_DIGGING,EMPTY_BOTTLE1);
	PlaceItemInLocation(ROMANI_RANCH_ALIEN_DEFENSE,BOTTLE_WITH_MILK);
	PlaceItemInLocation(GBC_FISHERMAN_PHOTO, SEAHORSE);
};

const std::array<ItemKey, 7> progressiveItemsList = {
	PROGRESSIVE_BOW,
	PROGRESSIVE_BOW,
	PROGRESSIVE_BOW, //1 Bow + 2 Quiver Upgrades
	//PROGRESSIVE_BOMB_BAG,
	//PROGRESSIVE_BOMB_BAG,
	//PROGRESSIVE_BOMB_BAG, //3 Bomb Bags - 2 are in Bomb Shop - part of Shopsanity
	//PROGRESSIVE_MAGIC_METER,
	//PROGRESSIVE_MAGIC_METER,//2 Magic Meters part of Great Fairy Reward Shuffle
	PROGRESSIVE_WALLET,
	PROGRESSIVE_WALLET,//2 Wallets
	//PROGRESSIVE_SWORD,
	PROGRESSIVE_SWORD,
	PROGRESSIVE_SWORD,//2 Swords -- One added or not depending on ShuffleKokriSword Settings
};

static void PlaceVanillaProgressive() {
	PlaceItemInLocation(WOODFALL_TEMPLE_HEROS_BOW_CHEST, PROGRESSIVE_BOW);
	PlaceItemInLocation(E_CLOCK_TOWN_ARCHERY_1, PROGRESSIVE_BOW);
	PlaceItemInLocation(ROAD_TO_SS_ARCHERY_1, PROGRESSIVE_BOW);
	PlaceItemInLocation(W_CLOCK_TOWN_BOMB_BAG_BUY, PROGRESSIVE_BOMB_BAG);
	PlaceItemInLocation(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, PROGRESSIVE_BOMB_BAG);
	PlaceItemInLocation(GORON_VILLAGE_SCRUB_PURCHASE, PROGRESSIVE_BOMB_BAG);
	PlaceItemInLocation(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, PROGRESSIVE_MAGIC_METER);
	PlaceItemInLocation(SNOWHEAD_GREAT_FAIRY, PROGRESSIVE_MAGIC_METER);
	PlaceItemInLocation(S_CLOCK_TOWN_BANK_REWARD_1, PROGRESSIVE_WALLET);
	PlaceItemInLocation(GBC_OCEAN_SPIDER_DAY1, PROGRESSIVE_WALLET);
	PlaceItemInLocation(HMS_STARTING_SWORD, PROGRESSIVE_SWORD);
	PlaceItemInLocation(MOUNTAIN_VILLAGE_SMITH_DAY_ONE, PROGRESSIVE_SWORD);
	PlaceItemInLocation(MOUNTAIN_VILLAGE_SMITH_DAY_TWO, PROGRESSIVE_SWORD);
};

const std::array<ItemKey, 13> nonProgressiveItemsList = {
	HEROS_BOW,
	LARGE_QUIVER,
	LARGEST_QUIVER,
	BOMB_BAG,
	BIG_BOMB_BAG,
	BIGGEST_BOMB_BAG,
	MAGIC_POWER,
	EXTENDED_MAGIC_POWER,
	ADULT_WALLET,
	GIANT_WALLET,
	KOKIRI_SWORD,
	RAZOR_SWORD,
	GILDED_SWORD,
};
/*
static void PlaceVanillaNonProgressive() {
	PlaceItemInLocation(WOODFALL_TEMPLE_HEROS_BOW_CHEST, HEROS_BOW);
	PlaceItemInLocation(E_CLOCK_TOWN_ARCHERY_1, LARGE_QUIVER);
	PlaceItemInLocation(ROAD_TO_SS_ARCHERY_1, LARGEST_QUIVER);
	PlaceItemInLocation(W_CLOCK_TOWN_BOMB_BAG_BUY, BOMB_BAG);
	PlaceItemInLocation(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, BIG_BOMB_BAG);
	PlaceItemInLocation(GORON_VILLAGE_SCRUB_PURCHASE, BIGGEST_BOMB_BAG);
	PlaceItemInLocation(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, MAGIC_POWER);
	PlaceItemInLocation(SNOWHEAD_GREAT_FAIRY, EXTENDED_MAGIC_POWER);
	PlaceItemInLocation(S_CLOCK_TOWN_BANK_REWARD_1, ADULT_WALLET);
	PlaceItemInLocation(GBC_OCEAN_SPIDER_DAY1, GIANT_WALLET);
	PlaceItemInLocation(HMS_STARTING_SWORD, KOKIRI_SWORD);
	PlaceItemInLocation(MOUNTAIN_VILLAGE_SMITH_DAY_ONE, RAZOR_SWORD);
	PlaceItemInLocation(MOUNTAIN_VILLAGE_SMITH_DAY_TWO, GILDED_SWORD);
};*/

static void PlaceVanillaHeartPieces() {
   for (LocationKey loc: GetLocations(allLocations, Category::cVanillaHeartPiece)) {
	if (Location(loc)->IsCategory(Category::cTheMoon)){
		return;
	}
	else PlaceItemInLocation(loc, PIECE_OF_HEART);
   }
};
const std::array<ItemKey, 8> vanillaCows = {
	MILK,
	MILK,
	MILK,
	MILK,
	MILK,
	MILK,
	MILK,
	MILK,	
};

const std::array<ItemKey,4> scrubPurchaseItems = {
	MAGIC_BEAN,
	PROGRESSIVE_BOMB_BAG,//BIGGEST_BOMB_BAG
	GREEN_POTION_REFILL,
	BLUE_POTION_REFILL,
};

const std::array<ItemKey, 4> moonItemList = {
	//2Chests and 4 trial rewards, FDM separate
	//ARROWS_30,  -just replace with junk
	//BOMBCHU_10,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
	PIECE_OF_HEART,
};

const std::array<ItemKey, 5> scrubTradeItems = {
	MOONS_TEAR,
	LAND_TITLE,
	SWAMP_TITLE,
	MOUNTAIN_TITLE,
	OCEAN_TITLE,
};

const std::array<ItemKey, 6> anjuKafeiTradeItems = {
	LETTER_KAFEI,
	LETTER_MAMA,
	PENDANT_MEMORIES,
	ROOM_KEY,
	KAFEIS_MASK,
	COUPLES_MASK,
};

std::array<ItemKey, 7> zoraEggs = {
	ZORA_EGG,
	ZORA_EGG,
	ZORA_EGG,
	ZORA_EGG,
	ZORA_EGG,
	ZORA_EGG,
	ZORA_EGG,
};

std::array<ItemKey, 6> tingleMaps = {
	CLOCK_TOWN_MAP,
	WOODFALL_MAP,
	SNOWHEAD_MAP,
	GREAT_BAY_MAP,
	STONE_TOWER_MAP,
	ROMANI_RANCH_MAP,
};

void AddItemToPool(std::vector<ItemKey>& pool, ItemKey item, size_t count /*= 1*/) {
	pool.insert(pool.end(), count, item);
}

template <typename FromPool>
static void AddItemsToPool(std::vector<ItemKey>& toPool, const FromPool& fromPool) {
	AddElementsToPool(toPool, fromPool);
}

static void AddItemToMainPool(const ItemKey item, size_t count = 1) {
	ItemPool.insert(ItemPool.end(), count, item);
}

/*static void AddRandomBottle(std::vector<ItemKey>& bottlePool) {
	AddItemToMainPool(RandomElement(bottlePool, true));
}*/

ItemKey GetJunkItem() {
	if (IceTrapValue.Is(rnd::IceTrapSetting::ICETRAPS_MAYHEM) || IceTrapValue.Is(rnd::IceTrapSetting::ICETRAPS_ONSLAUGHT)) {
		return ICE_TRAP;
	}
	else if (IceTrapValue.Is(rnd::IceTrapSetting::ICETRAPS_EXTRA)) {
		return RandomElement(JunkPoolItems);
	}
	//Ice Trap is the last item in JunkPoolItems, so subtract 1 to never hit that index
	u8 idx = Random(0, JunkPoolItems.size() - 1);
	return JunkPoolItems[idx];
};

static ItemKey GetPendingJunkItem() {
	if (PendingJunkPool.empty()) {
		return GetJunkItem();
	}

	return RandomElement(PendingJunkPool, true);
};

//Replace junk items in the pool with pending junk
static void ReplaceMaxItem(const ItemKey itemToReplace, int max) {
	int itemCount = 0;
	for (size_t i = 0; i < ItemPool.size(); i++) {
		if (ItemPool[i] == itemToReplace) {
			if (itemCount >= max) {
				ItemPool[i] = GetJunkItem();
			}
			itemCount++;
		}
	}
};

void PlaceJunkInExcludedLocation(const LocationKey il) {
	//place a non-advancement item in this location
	if (JunkPoolItems.size() != 0) {
		PlaceItemInLocation(il, GetJunkItem());
		return;
	}
	else {
		printf("ERROR: No Junk to Place!!!\n:");
	}
	//for (size_t i = 0; i < ItemPool.size(); i++) {
	//	if (!ItemTable(ItemPool[i]).IsAdvancement()) {
	//		PlaceItemInLocation(il, ItemPool[i]);
	//		ItemPool.erase(ItemPool.begin() + i);
	//		return;
	//	}
	//}
	//printf("ERROR: No Junk to Place!!!\n");
};

static void PlaceVanillaMapsAndCompasses() {
	//Place Dungeon Maps and Compasses
	for (auto dungeon : dungeonList) {
		dungeon->PlaceVanillaMap();
		dungeon->PlaceVanillaCompass();
	}
	
	/*
	PlaceItemInLocation(WOODFALL_TEMPLE_COMPASS_CHEST, WOODFALL_TEMPLE_COMPASS);
	PlaceItemInLocation(WOODFALL_TEMPLE_MAP_CHEST, WOODFALL_TEMPLE_MAP);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_MAP_CHEST, SNOWHEAD_TEMPLE_MAP);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_COMPASS_CHEST, SNOWHEAD_TEMPLE_COMPASS);
	PlaceItemInLocation(GBT_MAP_CHEST, GBT_MAP);
	PlaceItemInLocation(GBT_COMPASS_CHEST, GBT_COMPASS);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_MAP_CHEST, STONE_TOWER_TEMPLE_MAP);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_COMPASS_CHEST, STONE_TOWER_TEMPLE_COMPASS);
*/
};

static void PlaceVanillaZoraEggs() {
	PlaceItemInLocation(PINNACLE_ROCK_ZORA_EGG1, ZORA_EGG);
	PlaceItemInLocation(PINNACLE_ROCK_ZORA_EGG2, ZORA_EGG);
	PlaceItemInLocation(PINNACLE_ROCK_ZORA_EGG3, ZORA_EGG);
	PlaceItemInLocation(PF_INT_HOOKSHOT_ROOM_ZORA_EGG, ZORA_EGG);
	PlaceItemInLocation(PF_INT_GUARD_ROOM_ZORA_EGG, ZORA_EGG);
	PlaceItemInLocation(PF_INT_LAVA_ROOM_ZORA_EGG, ZORA_EGG);
	PlaceItemInLocation(PF_INT_BARREL_MAZE_ZORA_EGG, ZORA_EGG);
};

static void PlaceVanillaSmallKeys() {
	for (auto dungeon : dungeonList) {
		dungeon->PlaceVanillaSmallKeys();
	}
	/*
	PlaceItemInLocation(WOODFALL_TEMPLE_SMALL_KEY_CHEST, WOODFALL_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST, SNOWHEAD_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST, SNOWHEAD_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST, SNOWHEAD_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(GBT_SMALL_KEY_CHEST, GBT_SMALL_KEY);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST, STONE_TOWER_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST, STONE_TOWER_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST, STONE_TOWER_TEMPLE_SMALL_KEY);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST, STONE_TOWER_TEMPLE_SMALL_KEY);
	*/
};

static void PlaceVanillaBossKeys() {
	for (auto dungeon : dungeonList) {
		dungeon->PlaceVanillaBossKey();
	}
	/*
	PlaceItemInLocation(WOODFALL_TEMPLE_BOSS_KEY_CHEST, WOODFALL_TEMPLE_BOSS_KEY);
	PlaceItemInLocation(SNOWHEAD_TEMPLE_BOSS_KEY_CHEST, SNOWHEAD_TEMPLE_BOSS_KEY);
	PlaceItemInLocation(GBT_BOSS_KEY_CHEST, GBT_BOSS_KEY);
	PlaceItemInLocation(STONE_TOWER_TEMPLE_BOSS_KEY_CHEST, STONE_TOWER_TEMPLE_BOSS_KEY);
	*/
};

static void PlaceVanillaStrayFairies() {
	/*TO-DO::make simpler
	for (auto dungeon : dungeonList) {
		dungeon->PlaceVanillaWFStray();
		dungeon->PlaceVanillaSHStray();
		dungeon->PlaceVanillaGBTStray();
		dungeon->PlaceVanillaSTStray();
	}*/
	//Clock Town
	PlaceItemInLocation(LAUNDRY_POOL_SF, CT_STRAY_FAIRY);
	//Woodfall Temple
	PlaceItemInLocation(WF_SF_ENTRANCE_FAIRY, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_ENTRANCE_PLATFORM, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_MAIN_ROOM_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_MAIN_ROOM_SWITCH, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_PRE_BOSS_PILLAR_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_DEKU_BABA, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_DRAGONFLY_ROOM_BUBBLE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_SKULLTULA, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_DARK_ROOM, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_JAR_FAIRY, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_BRIDGE_ROOM_BEEHIVE, WF_STRAY_FAIRY);
	PlaceItemInLocation(WF_SF_PLATFORM_ROOM_BEEHIVE, WF_STRAY_FAIRY);
	//SnowheadTemple
	PlaceItemInLocation(SH_SF_SNOW_ROOM_BUBBLE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_CEILING_BUBBLE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_DINOLFOS_1, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_DINOLFOS_2, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_MAP_ROOM_FAIRY, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_MAP_ROOM_LEDGE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_BASEMENT, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_TWIN_BLOCK, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_ICICLE_ROOM_WALL, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_MAIN_ROOM_WALL, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_PILLAR_FREEZARDS, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_ICE_PUZZLE, SH_STRAY_FAIRY);
	PlaceItemInLocation(SH_SF_CRATE, SH_STRAY_FAIRY);
	//Great Bay Temple
	PlaceItemInLocation(GBT_SF_SKULLTULA, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_WATERWHEEL_ROOM_LOWER, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_WATERWHEEL_ROOM_UPPER, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_GREEN_VALVE, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_SEESAW_ROOM, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_ENTRANCE_TORCHES, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_BIO_BABAS, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_UNDERWATER_BARREL, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_WHIRLPOOL_JAR, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_WHIRLPOOL_BARREL, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_DEXIHANDS_JAR, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_LEDGE_JAR, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_PRE_BOSS_ROOM_BUBBLE, GBT_STRAY_FAIRY);
	PlaceItemInLocation(GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE, GBT_STRAY_FAIRY);
	//Stone Tower Temple
	PlaceItemInLocation(ST_SF_MIRROR_SUN_BLOCK, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_LAVA_ROOM_LEDGE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_LAVA_ROOM_FIRE_RING, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_EYEGORE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_UPDRAFT_FIRE_RING, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_MIRROR_SUN_SWITCH, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_BOSS_WARP, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_WIZZROBE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_DEATH_ARMOS, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_UPDRAFT_FROZEN_EYE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_THIN_BRIDGE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_BASEMENT_LEDGE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_STATUE_EYE, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_UNDERWATER, ST_STRAY_FAIRY);
	PlaceItemInLocation(ST_SF_BRIDGE_CRYSTAL, ST_STRAY_FAIRY);
};

static void PlaceVanillaSkulltulaTokens() {
	/* TO-DO::make simpler
	for (auto dungeon : dungeonList) {
		dungeon->PlaceVanillaSwampToken();
		dungeon->PlaceVanillaOceanToken();
	}*/
	//Swamp Skull Tokens
	PlaceItemInLocation(SSH_MAIN_ROOM_NEAR_CEILING, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_WATER, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_LOWER_LEFT_SOIL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_UPPER_SOIL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_LOWER_RIGHT_SOIL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_PILLAR, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_UPPER_PILLAR, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MAIN_ROOM_JAR, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MONUMENT_ROOM_CRATE_1, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MONUMENT_ROOM_CRATE_2, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MONUMENT_ROOM_TORCH, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MONUMENT_ROOM_ON_MONUMENT, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_MONUMENT_ROOM_LOWER_WALL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_GOLD_ROOM_NEAR_CEILING, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_GOLD_ROOM_PILLAR, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_GOLD_ROOM_BEEHIVE, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_GOLD_ROOM_WALL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_JAR, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_POT_1, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_POT_2, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_BEHIND_VINES, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_WALL, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_BEEHIVE_1, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_POT_ROOM_BEEHIVE_2, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_TREE_1, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_TREE_2, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_TREE_3, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_GRASS_1, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_GRASS_2, SWAMP_SKULLTULA_TOKEN);
	PlaceItemInLocation(SSH_TREE_ROOM_BEEHIVE, SWAMP_SKULLTULA_TOKEN);
	//Ocean Skull Tokens
	PlaceItemInLocation(OSH_ENTRANCE_LEFT_WALL, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_ENTRANCE_RIGHT_WALL, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_ENTRANCE_WEB, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_HOLE_BEHIND_PICTURE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_HOLE_BEHIND_CABINET, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_ON_CORNER_BOOKSHELF, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_CEILING_EDGE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_BEHIND_BOOKCASE_1, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_BEHIND_BOOKCASE_2, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_LIBRARY_BEHIND_PICTURE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_CEILING_EDGE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_CEILING_PLANK, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_JAR, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_WEBBED_HOLE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_WEBBED_POT, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_UPPER_POT, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_BEHIND_SKULL_1, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_BEHIND_SKULL_2, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_SECOND_ROOM_LOWER_POT, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_STORAGE_ROOM_CEILING_WEB, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_STORAGE_ROOM_BEHIND_CRATE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_STORAGE_ROOM_WALL, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_STORAGE_ROOM_CRATE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_STORAGE_ROOM_BARREL, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_CEILING_EDGE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_CHANDELIER_1, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_CHANDELIER_2, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_CHANDELIER_3, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_BEHIND_PICTURE, OCEANSIDE_SKULLTULA_TOKEN);
	PlaceItemInLocation(OSH_COLORED_SKULLS_POT, OCEANSIDE_SKULLTULA_TOKEN);
};

static void PlaceVanillaCowMilk() {
	PlaceItemInLocation(GBC_GROTTO_COW1, MILK);
	PlaceItemInLocation(GBC_GROTTO_COW2, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_1, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_2, MILK);
	PlaceItemInLocation(ROMANI_RANCH_COW_3, MILK);
	PlaceItemInLocation(TERMINA_FIELD_GROTTO_COW1, MILK);
	PlaceItemInLocation(TERMINA_FIELD_GROTTO_COW2, MILK);
	PlaceItemInLocation(BENEATH_THE_WELL_COW, MILK);
};


static void PlaceVanillaShopItems() {
	PlaceItemInLocation(TRADING_POST_ITEM_1, BUY_RED_POTION);
	PlaceItemInLocation(TRADING_POST_ITEM_2, BUY_GREEN_POTION);
	PlaceItemInLocation(TRADING_POST_ITEM_3, BUY_HEROS_SHIELD);
	PlaceItemInLocation(TRADING_POST_ITEM_4, BUY_FAIRYS_SPIRIT);
	PlaceItemInLocation(TRADING_POST_ITEM_5, BUY_DEKU_STICK_1);
	PlaceItemInLocation(TRADING_POST_ITEM_6, BUY_ARROWS_30);
	PlaceItemInLocation(TRADING_POST_ITEM_7, BUY_DEKU_NUT_10);
	PlaceItemInLocation(TRADING_POST_ITEM_8, BUY_MAGIC_BEAN);
	PlaceItemInLocation(BOMB_SHOP_ITEM_1, BUY_BOMBS_10);
	PlaceItemInLocation(BOMB_SHOP_ITEM_2, BUY_BOMBCHU_10);
	PlaceItemInLocation(POTION_SHOP_ITEM_1, BUY_BLUE_POTION);
	PlaceItemInLocation(POTION_SHOP_ITEM_2, BUY_GREEN_POTION);
	PlaceItemInLocation(POTION_SHOP_ITEM_3, BUY_RED_POTION);
	PlaceItemInLocation(GORON_SHOP_ITEM_1, BUY_BOMBS_10);
	PlaceItemInLocation(GORON_SHOP_ITEM_2, BUY_BOMBCHU_10);
	PlaceItemInLocation(GORON_SHOP_ITEM_3, BUY_RED_POTION);
	PlaceItemInLocation(ZORA_SHOP_ITEM_1, BUY_HEROS_SHIELD);
	PlaceItemInLocation(ZORA_SHOP_ITEM_2, BUY_ARROWS_10);
	PlaceItemInLocation(ZORA_SHOP_ITEM_3, BUY_RED_POTION);
	PlaceItemInLocation(GORON_VILLAGE_SCRUB_PURCHASE, PROGRESSIVE_BOMB_BAG);
	PlaceItemInLocation(IKANA_CANYON_SCRUB_PURCHASE, BLUE_POTION_REFILL);
	PlaceItemInLocation(ZORA_HALL_SCRUB_PURCHASE, GREEN_POTION_REFILL);
	PlaceItemInLocation(MILK_ROAD_GORMAN_MILK_BUY, MILK);
	//other 2 scrub sales handled in beans and main inventory
};

static void SetScarceItemPool() {
	ReplaceMaxItem(BOMBCHU_5, 1);
	ReplaceMaxItem(BOMBCHU_10, 3);
	ReplaceMaxItem(PROGRESSIVE_MAGIC_METER, 1);
	ReplaceMaxItem(DOUBLE_DEFENSE, 0);
	ReplaceMaxItem(PROGRESSIVE_BOW, 2);
	ReplaceMaxItem(PROGRESSIVE_BOMB_BAG, 2);
	ReplaceMaxItem(HEART_CONTAINER, 0);

};
static void SetMinimalItemPool(){
	ReplaceMaxItem(BOMBCHU_5, 1);
	ReplaceMaxItem(BOMBCHU_10, 0);
	ReplaceMaxItem(BOMBCHU_20,0);
	ReplaceMaxItem(PROGRESSIVE_MAGIC_METER, 1);
	ReplaceMaxItem(PROGRESSIVE_BOW,1);
	ReplaceMaxItem(PROGRESSIVE_BOMB_BAG, 1);
	ReplaceMaxItem(PIECE_OF_HEART,0);
	//ReplaceMaxItem(HEART_CONTAINER, 2);
};

void GenerateItemPool() {
	
	ItemPool.clear();//start fresh

	//Initialize ice trap models to always major items
	IceTrapModels = {
	  0x33, //GetItemID::GI_SHIELD_MIRROR,
	  0x41, //GetItemID::GI_HOOKSHOT,
	  0x42, //GetItemID::GI_LENS_OF_TRUTH,
	  0x3B, //GetItemID::GI_GREAT_FAIRY_SWORD,
	  0x34, //GetItemID::GI_POWDER_KEG,
	  0x25, //GetItemID::GI_FIRE_ARROW,
	  0x26, //GetItemID::GI_ICE_ARROW,
	  0x27, //GetItemID::GI_LIGHT_ARROW,
	  0xB8, //Double defense
	  0x46, //Progressive bomb bag
	  0x47, //Progressive bow
	  0x48, //Progressive wallet
	  0x49, //Progressive magic
	  0x4A, //ProgressiveSword
	};
	//Check song shuffle and dungeon reward shuffle just for ice traps
	/*
	if (ShuffleSongs.Is(rnd::SongShuffleSetting::SONGSHUFFLE_ANYWHERE)) {
		//Push item ids for songs
		IceTrapModels.push_back(0x4B);
		IceTrapModels.push_back(0x4C);
		IceTrapModels.push_back(0x4D);
		IceTrapModels.push_back(0x4E);
		IceTrapModels.push_back(0x4F);
		IceTrapModels.push_back(0x51);
		IceTrapModels.push_back(0x54);
		//IceTrapModels.push_back(0x53); // should be song of time but not included yet
		//IceTrapModels.push_back(0xC6);
	}
	if (ShuffleRewards.Is(rnd::RewardShuffleSetting::REWARDSHUFFLE_ANYWHERE)) {
		//Push item ids for dungeon rewards
		IceTrapModels.push_back(0x55);
		IceTrapModels.push_back(0x56);
		IceTrapModels.push_back(0x57);
		IceTrapModels.push_back(0x58);
	}
     */
	//Fixed Item Locations
	PlaceItemInLocation(MAJORA, MAJORAS_MASK, true);
	PlaceItemInLocation(CLOCK_TOWER_OCARINA_OF_TIME, OCARINA_OF_TIME, true);
	PlaceItemInLocation(WOODFALL_TEMPLE_DEKU_PRINCESS, DEKU_PRINCESS);
	PlaceItemInLocation(W_CLOCK_TOWN_BOMB_BAG_BUY, PROGRESSIVE_BOMB_BAG);
	PlaceItemInLocation(W_CLOCK_TOWN_BIG_BOMB_BAG_BUY, PROGRESSIVE_BOMB_BAG);
    	
	//temp placement until shopsanity works
	PlaceItemInLocation(SOUTHERN_SWAMP_SCRUB_PURCHASE, MAGIC_BEAN);
	

	//Place Temp Items at alt locations so they don't get filled with important stuff - will be replaced later
	PlaceItemInLocation(SOUTHERN_SWAMP_KOTAKE_IN_WOODS, BLUE_RUPEE);
	PlaceItemInLocation(N_CLOCK_TOWN_POSTBOX, BLUE_RUPEE);
	PlaceItemInLocation(E_CLOCK_TOWN_POSTBOX, BLUE_RUPEE);
	PlaceItemInLocation(W_CLOCK_TOWN_POSTBOX, BLUE_RUPEE);
	PlaceItemInLocation(MILK_ROAD_KEATON_QUIZ, BLUE_RUPEE);
	
	//Check Non Dungeon Settings

	//KOKIRISWORD SHUFFLE
	if(StartingKokiriSword.Value<u8>() == (u8)StartingSwordSetting::STARTINGSWORD_NONE) {//if starting with no sword we need to add an extra to the pool
		AddItemToMainPool(PROGRESSIVE_SWORD);
		IceTrapModels.push_back(0x37);//GetItemID::GI_KOKIRI_SWORD
		PlaceItemInLocation(HMS_STARTING_SWORD,GREEN_RUPEE);//Add Junk to this location because theres no way to get it otherwise
	} else {
		PlaceItemInLocation(HMS_STARTING_SWORD, KOKIRI_SWORD); //if starting with any sword place this here because this location is unobtainable
	}

	//SHUFFLE STARTING SHIELD
	if(StartingShield.Value<u8>() == (u8)StartingSheildSetting::STARTINGSHIELD_NONE){//if starting with no shield add an extra to the pool
		AddItemToMainPool(HEROS_SHIELD);
		PlaceItemInLocation(HMS_STARTING_SHIELD, GREEN_RUPEE);//PlaceJunk Here because you cant not get this
	}
	else { PlaceItemInLocation(HMS_STARTING_SHIELD, HEROS_SHIELD);}//if starting with any other shield place this here because this location is unobtainable
	
	//SHUFFLE BOMBERS NOTEBOOK
	if(ShuffleBombersNotebook){
		AddItemToMainPool(BOMBERS_NOTEBOOK);
		//PlaceItemInLocation(HMS_BOMBERS_NOTEBOOK, GREEN_RUPEE);//Need to add check if starting with Song of Healing 
	}
	else {PlaceItemInLocation(HMS_BOMBERS_NOTEBOOK, BOMBERS_NOTEBOOK);}

	//ShuffleOcarina

	//COWSANITY
	//if (ShuffleCows) {
		//8 total cows -- rather have junk than 8 extra milk refills
	//	for (u8 i = 0; i < 8; i++) {
    //  AddItemToMainPool(GetJunkItem());
    //	}
	//} else {
		PlaceVanillaCowMilk();
	//}

	//MAGIC BEAN SHUFFLE--NEEDS WORK
	PlaceItemInLocation(DEKU_PALACE_BEAN_SELLER, MAGIC_BEAN);//vanilla for now because replacing causes odd occurances where you cannot buy beans elsewhere
	/*
	if(ShuffleMagicBeans) { //does not shuffle bean salesman yet
		AddItemToMainPool(MAGIC_BEAN);
		if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_PLENTIFUL)){
			AddItemToPool(PendingJunkPool, MAGIC_BEAN);
		}
		IceTrapModels.push_back(0x75);

		if(Shopsanity){
			AddItemToMainPool(MAGIC_BEAN);
			if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_PLENTIFUL)){
			AddItemToPool(PendingJunkPool, MAGIC_BEAN);
			}
		}
	} else {
		PlaceItemInLocation(STONE_TOWER_INVERTED_LEFT_CHEST, MAGIC_BEAN);
		if(!Shopsanity){PlaceItemInLocation(SOUTHERN_SWAMP_SCRUB_PURCHASE, MAGIC_BEAN);}
	}*/

	//MAININVENTORY SHUFFLE
	if(ShuffleMainInventory){
		AddItemsToPool(ItemPool, mainInventoryList);
		AddItemsToPool(ItemPool, progressiveItemsList);
	}
	else{
		PlaceVanillaMainInventory();
		PlaceVanillaProgressive();
	}
	
	//NON TRANSFORM MASK SHUFFLE
	if (ShuffleMasks) {
		AddItemsToPool(ItemPool, maskList);
	}
	else {
		PlaceVanillaMasks();
	}

	//SONG SHUFFLE
	//add extra songs only if song shuffle is anywhere
	//if (ShuffleSongs.Is(SongShuffleSetting::SONGSHUFFLE_ANYWHERE)){
	//	AddItemsToPool(ItemPool, songList);
	//}
	//else if (ShuffleSongs.Is(SongShuffleSetting::SONGSHUFFLE_ANYWHERE) && ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_PLENTIFUL)) {
	//	AddItemsToPool(PendingJunkPool, songList);
	//}
	//else {
		PlaceVanillaSongs();
	//}

	//if (ShuffleSoaring)
	//{
	//	AddItemToPool(ItemPool, SONG_OF_SOARING);
	//}
	//else {
		PlaceItemInLocation(SOUTHERN_SWAMP_MUSIC_STATUE, SONG_OF_SOARING); 
	//	}

	
	//GREAT FAIRY SHUFFLE
	if(ShuffleGFRewards.Is((u8)GreatFairyRewardShuffleSetting::GFREWARDSHUFFLE_VANILLA)){
		PlaceItemInLocation(N_CLOCK_TOWN_GREAT_FAIRY_DEKU, PROGRESSIVE_MAGIC_METER);
		PlaceItemInLocation(WOODFALL_GREAT_FAIRY, SPIN_ATTACK);
		PlaceItemInLocation(SNOWHEAD_GREAT_FAIRY, PROGRESSIVE_MAGIC_METER);
		if(!ShuffleMainInventory){PlaceItemInLocation(IKANA_CANYON_GREAT_FAIRY, GREAT_FAIRYS_SWORD);}
		if(!RemoveDoubleDefense){PlaceItemInLocation(ZORA_CAPE_GREAT_FAIRY, DOUBLE_DEFENSE);}
	}
	else{
		
		AddItemToMainPool(PROGRESSIVE_MAGIC_METER); 
		AddItemToMainPool(PROGRESSIVE_MAGIC_METER); 
		AddItemToMainPool(SPIN_ATTACK);
		if(ShuffleMainInventory){AddItemToMainPool(GREAT_FAIRYS_SWORD);}
		if(!RemoveDoubleDefense){AddItemToMainPool(DOUBLE_DEFENSE);}
	}
	
	//REMOVE DD MAYBE?
	if (RemoveDoubleDefense) { //Prob not needed since its not added unless this is off
		ReplaceMaxItem(DOUBLE_DEFENSE, 0);
	}
	
	
	
	//DEKU/GORON/ZORA MAASK SHUFFLE
	if(ShuffleTransformation){
		AddItemToMainPool(DEKU_MASK);
		AddItemToMainPool(GORON_MASK);
		AddItemToMainPool(ZORA_MASK);
	}
	else { 
		PlaceItemInLocation(HMS_DEKU_MASK,DEKU_MASK);
		PlaceItemInLocation(MOUNTAIN_VILLAGE_DARMANI, GORON_MASK);
		PlaceItemInLocation(GBC_MIKAU, ZORA_MASK);
	}
	
	//FIERECE DIETY SHUFFLE
	if(ShuffleFierceDiety){
		AddItemToMainPool(FIERCE_DIETY_MASK);
	}
	else{
		PlaceItemInLocation(THE_MOON_MAJORA_CHILD,FIERCE_DIETY_MASK);
	}
	
	//PIECEOFHEART SHUFFLE
	if(ShufflePiecesOfHeart){
		AddItemToMainPool(PIECE_OF_HEART,48);//52Total-4MoonHearts
	}

	else{
		PlaceVanillaHeartPieces();
	}
	
	//MOONITEMSHUFFLE
	if(ShuffleMoonItems){
		AddItemsToPool(ItemPool, moonItemList);
	}
	else {
		PlaceItemInLocation(THE_MOON_DEKU_TRIAL_BONUS, PIECE_OF_HEART);
		PlaceItemInLocation(THE_MOON_GORON_TRIAL_BONUS, PIECE_OF_HEART);
		PlaceItemInLocation(THE_MOON_ZORA_TRIAL_BONUS, PIECE_OF_HEART);
		PlaceItemInLocation(THE_MOON_LINK_TRIAL_BONUS, PIECE_OF_HEART);
		PlaceItemInLocation(THE_MOON_GARO_CHEST, ARROWS_30);
		PlaceItemInLocation(THE_MOON_IRON_KNUCKLE_CHEST, BOMBCHU_10);
	}

	//TOKENSANITY
	//if(Tokensanity){
	//	AddItemToMainPool(SWAMP_SKULLTULA_TOKEN, 30);
	//	AddItemToMainPool(OCEANSIDE_SKULLTULA_TOKEN, 30);
	//}
	//else {
		PlaceVanillaSkulltulaTokens();
	//}

	//DEKU MERCHANT TRADE QUEST
	if (ShuffleMerchants){//Merchants is Deku Scrub Trade Quest
		AddItemsToPool(ItemPool, scrubTradeItems);
	} else {
		PlaceItemInLocation(TERMINA_FIELD_MOONS_TEAR, MOONS_TEAR);
		PlaceItemInLocation(S_CLOCK_TOWN_SCRUB_TRADE, LAND_TITLE);
		PlaceItemInLocation(SOUTHERN_SWAMP_SCRUB_TRADE, SWAMP_TITLE);
		PlaceItemInLocation(GORON_VILLAGE_SCRUB_TRADE, MOUNTAIN_TITLE);
		PlaceItemInLocation(ZORA_HALL_SCRUB_TRADE, OCEAN_TITLE);
		PlaceItemInLocation(IKANA_CANYON_SCRUB_TRADE, HUGE_RUPEE);
	}

	//ANJU AND KAFEI QUEST ITEMS
	if (ShuffleTradeItems){//TradeItems refers to Anju&Kafei Items
		AddItemsToPool(ItemPool, anjuKafeiTradeItems);
	} else {
		if(ShuffleMasks){
			AddItemToMainPool(KAFEIS_MASK);
			AddItemToMainPool(COUPLES_MASK);
		}
		else{
		PlaceItemInLocation(E_CLOCK_TOWN_AROMA_IN_OFFICE, KAFEIS_MASK);
		PlaceItemInLocation(STOCKPOTINN_ANJU_AND_KAFEI, COUPLES_MASK);
		}
		PlaceItemInLocation(STOCKPOTINN_MIDNIGHT_MEETING, LETTER_KAFEI);
		PlaceItemInLocation(LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO, LETTER_MAMA);
		PlaceItemInLocation(STOCKPOTINN_RESERVATION, ROOM_KEY);
		PlaceItemInLocation(LAUNDRY_POOL_KAFEI,PENDANT_MEMORIES);
	}

	//TO-DO----SHOP SANITY
	//for now... its all vanilla lol
	//if (Settings::Shopsanity.Is(ShopsanitySetting::SHOPSANITY_OFF) || Settings::Shopsanity.Is(ShopsanitySetting::SHOPSANITY_ZERO)) {
    AddItemsToPool(ItemPool, normalRupees);
	PlaceVanillaShopItems();
 	// } else { //Shopsanity 1-4, random
    //AddItemsToPool(ItemPool, shopsanityRupees); //Shopsanity gets extra large rupees
	//PlaceVanillaShopItems();
  	//}

	//Then Place Tingle Maps
	if (ShuffleTingleMaps) {
		//Add the 6 maps
		AddItemsToPool(ItemPool, tingleMaps);
		//Place Junk in "Duplicate spots" so each map check contains the same item in both locations
		PlaceItemInLocation(TINGLE_N_CLOCK_TOWN_WF, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_ROAD_TO_SS_SH, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_TWIN_ISLANDS_SH_SPRING, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR_SPRING, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_MILK_ROAD_GB, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_GBC_ST, BLUE_RUPEE);
		PlaceItemInLocation(TINGLE_IKANA_CANYON_CT, BLUE_RUPEE);
	}
	else {
		//Place Vanilla Maps
	PlaceItemInLocation(TINGLE_N_CLOCK_TOWN_CT, CLOCK_TOWN_MAP);
	PlaceItemInLocation(TINGLE_N_CLOCK_TOWN_WF, WOODFALL_MAP);
	PlaceItemInLocation(TINGLE_ROAD_TO_SS_WF, WOODFALL_MAP);
	PlaceItemInLocation(TINGLE_ROAD_TO_SS_SH, SNOWHEAD_MAP);
	PlaceItemInLocation(TINGLE_TWIN_ISLANDS_SH, SNOWHEAD_MAP);
	PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR, ROMANI_RANCH_MAP);
	PlaceItemInLocation(TINGLE_TWIN_ISLANDS_SH_SPRING, SNOWHEAD_MAP);
	PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR_SPRING, ROMANI_RANCH_MAP);
	PlaceItemInLocation(TINGLE_MILK_ROAD_RR, ROMANI_RANCH_MAP);
	PlaceItemInLocation(TINGLE_MILK_ROAD_GB, GREAT_BAY_MAP);
	PlaceItemInLocation(TINGLE_GBC_GB, GREAT_BAY_MAP);
	PlaceItemInLocation(TINGLE_GBC_ST, STONE_TOWER_MAP);
	PlaceItemInLocation(TINGLE_IKANA_CANYON_ST, STONE_TOWER_MAP);
	PlaceItemInLocation(TINGLE_IKANA_CANYON_CT, CLOCK_TOWN_MAP);
	}

	//DUNGEON STUFF 

	//PlaceVanillaBossRemains(); //done in fill.cpp - RandomizeDungeonRewards()
	//PlaceVanillaBossKeys(); //todo Keysanity settings
	//PlaceVanillaSmallKeys(); // for now all vanilla
	PlaceVanillaZoraEggs(); //for now all vanilla
	//PlaceVanillaMapsAndCompasses();//for now all vanilla
	//PlaceVanillaStrayFairies();//for now all vanilla

	if(ShuffleHeartContainers) {
		AddItemToMainPool(HEART_CONTAINER, 4);
	}
	else{
		PlaceItemInLocation(ODOLWA_HEART_CONTAINER,HEART_CONTAINER);
		PlaceItemInLocation(GOHT_HEART_CONTAINER, HEART_CONTAINER);
		PlaceItemInLocation(GYORG_HEART_CONTAINER, HEART_CONTAINER);
		PlaceItemInLocation(TWINMOLD_HEART_CONTAINER, HEART_CONTAINER);
	}


	//AddItemsToPool(ItemPool, normalRupees);
	//For item pool generation, dungeon items are either placed in their vanilla
	// location, or added to the pool now and filtered out later depending on when
	// they need to get placed or removed in fill.cpp. These items are kept in the
	// pool until removal because the filling algorithm needs to know all of the
	// advancement items that haven't been placed yet for placing higher priority
	// items like boss remains.

	if (MapsAndCompasses.Is(MapsAndCompassesSetting::MAPSANDCOMPASSES_VANILLA)) {
		PlaceVanillaMapsAndCompasses();
	}
	else {
		for (auto dungeon : dungeonList) {
			if (dungeon->GetMap() != NONE) {
				AddItemToMainPool(dungeon->GetMap());
			}

			if (dungeon->GetCompass() != NONE) {
				AddItemToMainPool(dungeon->GetCompass());
			}
		}
		AddItemsToPool(ItemPool, tingleMaps);
	}

	if (Keysanity.Is(KeysanitySetting::KEYSANITY_VANILLA)) {
		PlaceVanillaSmallKeys();
	}
	else {
		for (auto dungeon : dungeonList) {
			if (dungeon->GetSmallKeyCount() > 0) {
				AddItemToMainPool(dungeon->GetSmallKey(), dungeon->GetSmallKeyCount());
			}
		}
	}

	if (BossKeysanity.Is(BossKeysanitySetting::BOSSKEYSANITY_VANILLA)) {
		PlaceVanillaBossKeys();
	}
	else {
		AddItemToMainPool(WOODFALL_TEMPLE_BOSS_KEY);
		AddItemToMainPool(SNOWHEAD_TEMPLE_BOSS_KEY);
		AddItemToMainPool(GBT_BOSS_KEY);
		AddItemToMainPool(STONE_TOWER_TEMPLE_BOSS_KEY);
	}
    
	//STRAY FAIRY SANITY
	
	if (StrayFairysanity.Is(StrayFairySanitySetting::STRAYFAIRYSANITY_VANILLA)) {//if off place in vanilla locations
		PlaceVanillaStrayFairies();
	}
	else {
		AddItemToMainPool(CT_STRAY_FAIRY, 1); //if no selection or error ??
		AddItemToMainPool(WF_STRAY_FAIRY, 15);
		AddItemToMainPool(SH_STRAY_FAIRY, 15);
		AddItemToMainPool(GBT_STRAY_FAIRY, 15);
		AddItemToMainPool(ST_STRAY_FAIRY, 15);
	}

	//TO-DO--DungeonRewards
	//AddItemsToPool(ItemPool, dungeonRewards);


	// TO-DO ItemPool for extra items & Scarce and Minimal pools
	//if (ItemPoolValue.Is(ITEMPOOL_PLENTIFUL)) {
		//AddItemsToPool(ItemPool, easyItems);
	//}
	//else {
		//AddItemsToPool(ItemPool, normalItems);
	//}
	if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_SCARCE)) {//TO DO 
		SetScarceItemPool();
	}
	else if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_MINIMAL)) {
		SetMinimalItemPool();
	}

	if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_PLENTIFUL)) {

		//Plentiful small keys
		if (Keysanity.Is(KeysanitySetting::KEYSANITY_ANYWHERE)) {
			AddItemToPool(PendingJunkPool, WOODFALL_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, GBT_SMALL_KEY);
			AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_SMALL_KEY);
			AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_SMALL_KEY);
		}

		if (BossKeysanity.Is(BossKeysanitySetting::BOSSKEYSANITY_ANYWHERE)) {
			AddItemToPool(PendingJunkPool, WOODFALL_TEMPLE_BOSS_KEY);
			AddItemToPool(PendingJunkPool, SNOWHEAD_TEMPLE_BOSS_KEY);
			AddItemToPool(PendingJunkPool, GBT_BOSS_KEY);
			AddItemToPool(PendingJunkPool, STONE_TOWER_TEMPLE_BOSS_KEY);
		}
    
	}
	
	//Replace ice traps with junk from the pending junk pool if necessary
	if (IceTrapValue.Is(IceTrapSetting::ICETRAPS_OFF)) {
		ReplaceMaxItem(ICE_TRAP, 0);
	}
	//Replace all junk items with ice traps for onslaught mode
	else if (IceTrapValue.Is(IceTrapSetting::ICETRAPS_ONSLAUGHT)) {
		for (u8 i = 0; i < JunkPoolItems.size() - 3; i++) { // -3 Omits Huge Rupees and Deku Nuts 10
			ReplaceMaxItem(JunkPoolItems[i], 0);
		}
	}

	//this feels ugly and there's probably a better way, but
   //it replaces random junk with pending junk.

	bool junkSet;
	for (ItemKey pendingJunk : PendingJunkPool) {
		junkSet = false;
		for (ItemKey& item : ItemPool) {
			for (ItemKey junk : JunkPoolItems) {
				if (item == junk && item != HUGE_RUPEE && item != DEKU_NUTS_10) {
					item = pendingJunk;
					junkSet = true;
					break;
				}
			}
			if (junkSet) break;
		}
	}
	
}
void AddJunk() {
	PlacementLog_Msg("HAD TO PLACE EXTRA JUNK ");
	AddItemToMainPool(GetPendingJunkItem());
};
