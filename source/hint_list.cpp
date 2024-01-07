#include "hint_list.hpp"
//#include "custom_messages.hpp"

#include <array>

//using namespace CustomMessages;

static std::array<HintText, KEY_ENUM_MAX> hintTable;

void HintTable_Init() {
   /*--------------------------
    |       GENERAL TEXT       |
    ---------------------------*/

    hintTable[NONE]            = HintText::Exclude({Text{"No Hint","",""}});
    hintTable[PREFIX]          = HintText::Exclude({Text{"They say that ",              /*french*/"Selon moi, ",                  /*spanish*/"Según dicen, "}});
    hintTable[WAY_OF_THE_HERO] = HintText::Exclude({Text{" is on the way of the hero.", /*french*/" est sur le chemin du héros.", /*spanish*/" conduce a la senda del héroe."}});
    hintTable[PLUNDERING]      = HintText::Exclude({Text{"plundering ",                 /*french*/"explorer ",                    /*spanish*/"inspeccionar "}});
    hintTable[FOOLISH]         = HintText::Exclude({Text{" is a foolish choice.",       /*french*/" est futile.",                 /*spanish*/" no es una sabia decisión."}});
    hintTable[CAN_BE_FOUND_AT] = HintText::Exclude({Text{"can be found at",             /*french*/"se trouve dans",               /*spanish*/"aguarda en"}});
    hintTable[HOARDS]          = HintText::Exclude({Text{"hoards",                      /*french*/"recèle",                       /*spanish*/"acapara"}});


    //hintTable[ITEM] = HintText::Item({ Text{"English","French","Spanish"} });
    /*-------------------------
	|        ITEM HINTS       |
	--------------------------*/

    hintTable[KOKIRI_SWORD] = HintText::Item({ Text{"a forest blade", "a forest blade", "a forest blade"} });
	hintTable[RAZOR_SWORD]  = HintText::Item({ Text{"a sharp blade", "a sharp blade", "a sharp blade"} });
	hintTable[GILDED_SWORD] = HintText::Item({ Text{"a very sharp blade", "a very sharp blade", "a very sharp blade"} });
	hintTable[GREAT_FAIRYS_SWORD] = HintText::Item({ Text{"A powerful fairy blade", "a powerful fairy blade", "a powerful fairy blade"} });
	hintTable[HEROS_SHIELD] = HintText::Item({ Text{"a basic shield", "a basic shield", "a basic shield"} });
	hintTable[MIRROR_SHIELD] = HintText::Item({ Text{"a reflective shield", "a reflective shield", "a reflective shield"} });
	hintTable[DEKU_STICK] = HintText::Item({ Text{"a flammable weapon", "a flammable weapon", "a flammable weapon"} });
	hintTable[LAND_TITLE] = HintText::Item({ Text{"a property deal", "a property deal", "a property deal"} });
	hintTable[SWAMP_TITLE] = HintText::Item({ Text{"a property deal", "a property deal", "a property deal"} });
	hintTable[MOUNTAIN_TITLE] = HintText::Item({ Text{"a property deal", "a property deal", "a property deal"} });
	hintTable[OCEAN_TITLE] = HintText::Item({ Text{"a property deal", "a property deal", "a property deal"} });
	hintTable[BOMBERS_NOTEBOOK] = HintText::Item({ Text{"a handy notepad", "a handy notepad", "a handy notepad"} });
	hintTable[ROOM_KEY] = HintText::Item({ Text{"a hotel door opener", "a hotel door opener", "a hotel door opener"} });
	hintTable[LETTER_KAFEI] = HintText::Item({ Text{"a lover's letter", "a lover's letter", "a lover's letter"} });
	hintTable[PENDANT_MEMORIES] = HintText::Item({ Text{"a cherished necklace","a cherished necklace","a cherished necklace"} });
	hintTable[LETTER_MAMA] = HintText::Item({ Text{"A special delivery", "a special delivery", "a special delivery"}});
	hintTable[MOONS_TEAR] = HintText::Item({ Text{"a lunar teardrop", "a lunar teardrop", "a lunar teardrop"} });
	hintTable[SPIN_ATTACK] = HintText::Item({ Text{"a magic attack", "a magic attack", "a magic attack"} });
	hintTable[LENS_OF_TRUTH] = HintText::Item({ Text{"a lie detector","a lie detector", "a lie detector"} });
	hintTable[FIRE_ARROWS] = HintText::Item({ Text{"the power of fire", "the power of fire", "the power of fire"} });
	hintTable[ICE_ARROWS] = HintText::Item({ Text{"the power of ice", "the power of ice", "the power of ice"} });
	hintTable[LIGHT_ARROWS] = HintText::Item({ Text{"the power of light", "the power of light", "the power of light"} });
	hintTable[HOOKSHOT] = HintText::Item({ Text{"a chain and grapple", "a chain and grapple", "a chain and grapple"} });
	hintTable[MAGIC_BEAN] = HintText::Item({ Text{"a plant seed", "a plant seed", "a plant seed"} });
	//	MAGIC_BEAN_PACK,
	hintTable[DOUBLE_DEFENSE] = HintText::Item({ Text{"magical defence", "magical defence", "magical defence"} });
	//	OCARINA_OF_TIME,
	hintTable[PICTOGRAPH_BOX] = HintText::Item({ Text{"a capture device", "a capture device", "a capture device"} });
	hintTable[POWDER_KEG] = HintText::Item({ Text{"an explosive barrel", "an explosive barrel", "an explosive barrel"}});
	hintTable[KEATON_MASK] = HintText::Item({ Text{"a popular mask", "a popular mask", "a popular mask"} });
	hintTable[BUNNY_HOOD] = HintText::Item({ Text{"the ears of the wild", "the ears of the wild", "the ears of the wild"}});
	hintTable[GORON_MASK] = HintText::Item({ Text{"a mountain spirit", "a mountain spirit", "a mountain spirit"}});
	hintTable[ZORA_MASK] = HintText::Item({ Text{"an ocean spirit", "an ocean spirit", "an ocean spirit"}});
	hintTable[DEKU_MASK] = HintText::Item({ Text{"a forest spirit", "a forest spirit", "a forest spirit"}});
	hintTable[POSTMANS_HAT] = HintText::Item({ Text{"a hard worker's hat", "a hard worker's hat", "a hard worker's hat"}});
	hintTable[ALL_NIGHT_MASK] = HintText::Item({ Text{"insomnia","insomnia","insomnia"}});
	hintTable[BLAST_MASK] = HintText::Item({ Text{"a dangerous mask", "a dangerous mask", "a dangerous mask"}});
	hintTable[STONE_MASK] = HintText::Item({ Text{"inconspicousness", "inconspicousness", "inconspicousness"}});
	hintTable[GREAT_FAIRYS_MASK] = HintText::Item({ Text{"a friend of fairies", "a friend of fairies", "a friend of fairies"}});
	hintTable[BREMEN_MASK] = HintText::Item({ Text{"a bird's mask", "a bird's mask", "a bird's mask"}});
	hintTable[DON_GEROS_MASK] = HintText::Item({ Text{"a conductor's mask", "a conductor's mask", "a conductor's mask"}});
	hintTable[MASK_OF_SCENTS] = HintText::Item({ Text{"a pig's mask", "a pig's mask", "a pig's mask"}});
	hintTable[ROMANIS_MASK] = HintText::Item({ Text{"a cow's mask", "a cow's mask", "a cow's mask"}});
	hintTable[CIRCUS_LEADERS_MASK] = HintText::Item({ Text{"a mask of sadness", "a mask of sadness", "a mask of sadness"}});
	hintTable[KAFEIS_MASK] = HintText::Item({ Text{"the mask of a missing one", "the mask of a missing one", "the mask of a missing one"}});
	hintTable[COUPLES_MASK] = HintText::Item({ Text{"the mark of a couple", "the mark of a couple", "the mark of a couple"}});
	hintTable[KAMAROS_MASK] = HintText::Item({ Text{"dance moves", "dance moves", "dance moves"}});
	hintTable[GIBDOS_MASK] = HintText::Item({ Text{"a mask of monsters", "a mask of monsters", "a mask of monsters"}});
	hintTable[GAROS_MASK] = HintText::Item({ Text{"the mask of spies", "the mask of spies", "the mask of spies"}});
	hintTable[CAPTAINS_HAT] = HintText::Item({ Text{"a commanding presence", "a commanding presence", "a commanding presence"}});
	hintTable[GIANTS_MASK] = HintText::Item({ Text{"a growth spurt", "a growth spurt", "a growth spurt"}});
	hintTable[FIERCE_DIETY_MASK] = HintText::Item({ Text{"the wrath of a god", "the wrath of a god", "the wrath of a god"}});
	hintTable[MASK_OF_TRUTH] = HintText::Item({ Text{"a piercing gaze", "a piercing gaze", "a piercing gaze"}});
	
	//SKULLTULA TOKENS
	hintTable[SWAMP_SKULLTULA_TOKEN] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	
	//Stray Fairies
	hintTable[CT_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[WF_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[SH_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	//PROGRESSIVE ITEMS (unused currently)
	hintTable[PROGRESSIVE_SWORD] = HintText::Item({ Text{"a progressive sword", "", ""} });
	hintTable[PROGRESSIVE_BOMB_BAG] = HintText::Item({ Text{"a progressive bomb bag", "", ""} });
	hintTable[PROGRESSIVE_BOW] = HintText::Item({ Text{"a progressive bow", "", ""} });
	hintTable[PROGRESSIVE_WALLET] = HintText::Item({ Text{"a progressive wallet", "", ""} });
	hintTable[PROGRESSIVE_MAGIC_METER] = HintText::Item({ Text{"progressive magic meter", "", ""} });
	//	PROGRESSIVE_BOMBCHUS,

	//BOTTLE ITEMS
	hintTable[EMPTY_BOTTLE1] = HintText::Item({ Text{"a glass container", "a glass container", "a glass container"} });
	hintTable[EMPTY_BOTTLE2] = HintText::Item({ Text{"a glass container", "a glass container", "a glass container"} });
	hintTable[BOTTLE_WITH_MILK] = HintText::Item({ Text{"a dairy product", "a dairy product", "a dairy product"}});
	hintTable[BOTTLE_WITH_RED_POTION] = HintText::Item({ Text{"a vessel of health", "a vessel of health", "a vessel of health"}});
	hintTable[BOTTLE_WITH_GREEN_POTION] = HintText::Item({ Text{"a magic potion", "a magic potion", "a magic potion"}});
	hintTable[BOTTLE_WITH_BLUE_POTION] = HintText::Item({ Text{"a blue drink", "a blue drink","a blue drink"}});
	hintTable[BOTTLE_WITH_FAIRY] = HintText::Item({ Text{"a fairy", "a fairy", "a fairy"}});
	hintTable[BOTTLE_WITH_FISH] = HintText::Item({ Text{"something fresh", "something fresh", "something fresh"}});
	hintTable[CHATEAU_ROMANI] = HintText::Item({ Text{"an adult beverage", "an adult beverage", "an adult beverage"}});
	hintTable[BOTTLE_WITH_BUGS] = HintText::Item({ Text{"an insect", "an insect", "an insect"}});
	hintTable[BOTTLE_WITH_POE] = HintText::Item({ Text{"a captured spirit", "a captured spirit", "a captred spirit"}});
	hintTable[BOTTLE_WITH_BIG_POE] = HintText::Item({ Text{"a large captured spirit", "a large captured spirit", "a large captured spirit"}});
	hintTable[BOTTLE_WITH_HOT_SPRING_WATER] = HintText::Item({ Text{"a hot liquid", "a hot liquid", "a hot liquid"}});
	hintTable[BOTTLE_WITH_SPRING_WATER] = HintText::Item({ Text{"a fresh drink", "a fresh drink", "a fresh drink"}});
	hintTable[DEKU_PRINCESS] = HintText::Item({ Text{"a princes", "a princess","a princess"}});
	hintTable[GOLD_DUST] = HintText::Item({ Text{"a gleaming powder", "a gleaming powder", "a gleaning powder"}});
	hintTable[BOTTLE_WITH_ZORA_EGG] = HintText::Item({ Text{"a lost child", "a lost child", "a lost child"}});
	hintTable[SEAHORSE] = HintText::Item({ Text{"a sea creature", "a sea creatre", "a sea creature"}});
	hintTable[BOTTLE_WITH_MUSHROOM] = HintText::Item({ Text{"a strange fungus", "a strange fungus", "a strange fungus"}});
		//UPGRADABLE ITEMS
	hintTable[LARGE_QUIVER] = HintText::Item({ Text{"a ranged weapon", "a ranged weapon", "a ranged weapon"}});
	hintTable[LARGEST_QUIVER] = HintText::Item({ Text{"a ranged weapon", "a ranged weapon", "a ranged weapon"}});
	hintTable[BOMB_BAG] = HintText::Item({ Text{"a vessel of explosives", "a vessel of explosives", "a vessel of explosives"}});
	hintTable[BIG_BOMB_BAG] = HintText::Item({ Text{"a vessel of explosives", "a vessel of explosives", "a vessel of explosives"}});
	hintTable[BIGGEST_BOMB_BAG] = HintText::Item({ Text{"a vessel of explosives", "a vessel of explosives", "a vessel of explosives"}});
	hintTable[ADULT_WALLET] = HintText::Item({ Text{"a coin purse", "a coin purse", "a coin purse"}});
	hintTable[GIANT_WALLET] = HintText::Item({ Text{"a coin purse", "a coin purse", "a coin purse"}});
	hintTable[MAGIC_POWER] = HintText::Item({ Text{"magic power", "magic power", "magic power"}});
	hintTable[EXTENDED_MAGIC_POWER] = HintText::Item({ Text{"magic power", "magic power", "magic power"}});
		//SONGS
	//hintTable[SONG_OF_TIME] = HintText::Item({ Text{"song of time", "song of time", "song of time"}});
	hintTable[SONG_OF_STORMS] = HintText::Item({ Text{"stormy weather", "stormy weather", "stormy weather"}});
	hintTable[SONG_OF_HEALING] = HintText::Item({ Text{"a soothing melody", "a soothing melody", "a soothing melody"}});
	hintTable[SONG_OF_SOARING] = HintText::Item({ Text{"white wings", "white wings", "white wings"}});
	//hintTable[SONG_OF_DOUBLE_TIME] = HintText::Item({ Text{"double time", "double time", "double time"}});
	//hintTable[INVERTED_SONG_OF_TIME] = HintText::Item({ Text{"slowed time", "slowed time", "slowed time"}});
	hintTable[EPONAS_SONG] = HintText::Item({ Text{"a horses song", "a horses song", "a horses song"}});
	hintTable[SONATA_OF_AWAKENING] = HintText::Item({ Text{"a royal song", "a royal song", "a royal song"}});
	hintTable[GORONS_LULLABY] = HintText::Item({ Text{"a sleepy melody", "a sleepy melody", "a sleepy melody"}});
	hintTable[NEW_WAVE_BOSSA_NOVA] = HintText::Item({ Text{"a song of newborns", "a song of newborns", "a song of newborns"}});
	hintTable[ELEGY_OF_EMPTINESS] = HintText::Item({ Text{"empty shells", "empty shells", "empty shells"}});
	hintTable[OATH_TO_ORDER] = HintText::Item({ Text{"a song of giants", "a song of giants", "a song of giants"}});
		//PIECES OF HEART
	hintTable[PIECE_OF_HEART] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	
	//MAPS
	hintTable[MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"}});
	hintTable[WOODFALL_TEMPLE_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[SNOWHEAD_TEMPLE_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[GBT_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[STONE_TOWER_TEMPLE_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[CLOCK_TOWN_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[WOODFALL_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[SNOWHEAD_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[GREAT_BAY_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[STONE_TOWER_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
	hintTable[ROMANI_RANCH_MAP] = HintText::Item({ Text{"a paper guide", "a paper guide", "a paper guide"} });
		//COMPASSES
	hintTable[COMPASS] = HintText::Item({ Text{"a magnetic needle", "a magnetic needle", "a magnetic needle"} });
	hintTable[WOODFALL_TEMPLE_COMPASS] = HintText::Item({ Text{"a magnetic needle", "a magnetic needle", "a magnetic needle"} });
	hintTable[SNOWHEAD_TEMPLE_COMPASS] = HintText::Item({ Text{"a magnetic needle", "a magnetic needle", "a magnetic needle"} });
	hintTable[GBT_COMPASS] = HintText::Item({ Text{"a magnetic needle", "a magnetic needle", "a magnetic needle"} });
	hintTable[STONE_TOWER_TEMPLE_COMPASS] = HintText::Item({ Text{"a magnetic needle", "a magnetic needle", "a magnetic needle"} });
		//BOSSKEYS
	hintTable[BOSS_KEY] = HintText::Item({ Text{"an important key", "an important key", "an important key"} });
	hintTable[WOODFALL_TEMPLE_BOSS_KEY] = HintText::Item({ Text{"an important key", "an important key", "an important key"} });
	hintTable[SNOWHEAD_TEMPLE_BOSS_KEY] = HintText::Item({ Text{"an important key", "an important key", "an important key"} });
	hintTable[GBT_BOSS_KEY] = HintText::Item({ Text{"an important key", "an important key", "an important key"} });
	hintTable[STONE_TOWER_TEMPLE_BOSS_KEY] = HintText::Item({ Text{"an important key", "an important key", "an important key"} });
		//SMALLKEYS
	hintTable[SMALL_KEY] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	hintTable[WOODFALL_TEMPLE_SMALL_KEY] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[SNOWHEAD_TEMPLE_SMALL_KEY1] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[SNOWHEAD_TEMPLE_SMALL_KEY2] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[SNOWHEAD_TEMPLE_SMALL_KEY3] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	hintTable[GBT_SMALL_KEY] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[STONE_TOWER_TEMPLE_SMALL_KEY1] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[STONE_TOWER_TEMPLE_SMALL_KEY2] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[STONE_TOWER_TEMPLE_SMALL_KEY3] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
	//hintTable[STONE_TOWER_TEMPLE_SMALL_KEY4] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
		//DUNGEON REWARDS
	hintTable[ODOLWAS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GOHTS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GYORGS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[TWINMOLDS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });

	/*-----------------------
	|  SOMETIMES HINT TEXT  |
	-----------------------*/
	// Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({ "A Musical Instrument"});
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({"a cursed removed"});
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({"a masked man's melody"});
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({"a masked man's gift"});
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({"a new file"});
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({"a new file"});
  //PRE_CLOCK_TOWN_CHEST,
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({"a gorging merchant"});
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({"the home of scrubs"});
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({"the royal servant"});
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({"a merchant's cave"});
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({"a false imprisonment"});
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({"an important lady"});
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({"a town activity"});
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({"a town activity"});
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({"a town leader"});
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({"a lovers game"});
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({"a treasure game"});
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({"a delivery person"});
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({"a miserable leader"});
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({"an important lady"});
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({"a secret hideout"});
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({"a shop roof"});
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({"a correspondence box"});
  //E_CLOCK_TOWN_MILK_BAR_CHATEAU,
  //E_CLOCK_TOWN_MILK_BAR_MILK,
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({"an upset stomach cure"});
  //E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU,
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({"a large goron"});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({"a northern merchant"});
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({"a lonely peak"});
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({"a northern merchant"});
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({"a cold ledge"});
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({"a lonely child"});
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({"a lonely peak"});
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({"a lonely peak"});
  //GORON_SHOP_ITEM_1, //To-Do?
  //GORON_SHOP_ITEM_2,
  //GORON_SHOP_ITEM_3,
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({"an ocean spider reward"});
  //GBC_OCEAN_SPIDER_DAY2,
  //GBC_OCEAN_SPIDER_DAY3,
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({"an ocean game"});
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({"the colored masks"});
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({"feeding the fish"});
    hintTable[GBC_LEDGE] = HintText::Sometimes({"an ocean ledge"});
    hintTable[GBC_MIKAU] = HintText::Sometimes({"a healed spirit"});
    hintTable[GBC_BABY_ZORAS]  = HintText::Sometimes({"the pirates' loot"});
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({"an ocean cave"});
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({"a lost creature"});
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({"a lost creature"});
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({"a fisherman"});
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({"a map maker"});
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({"a map maker"});
//Ikana Canyon
  IKANA_CANYON_GREAT_FAIRY,
  IKANA_CANYON_POE_HUT_HP,
  IKANA_CANYON_LEDGE,
  IKANA_CANYON_PAMELAS_FATHER,
  IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST,
  IKANA_CANYON_SCRUB_TRADE,
  IKANA_CANYON_SCRUB_PURCHASE,
  TINGLE_IKANA_CANYON_ST,
  TINGLE_IKANA_CANYON_CT,
//Ikana Graveyard
  IKANA_GRAVEYARD_DAMPE_DIGGING,
  IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST,
  IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST,
  IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET,
  IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS,
  IKANA_GRAVEYARD_GROTTO_CHEST,
//Laundry Pool
  LAUNDRY_POOL_KAFEI,
  LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE,
  LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO,
  LAUNDRY_POOL_GURU_GURU,
  LAUNDRY_POOL_SF,
//Milk Road
  MILK_ROAD_GORMAN_RACE,
  MILK_ROAD_GORMAN_MILK_BUY,
  MILK_ROAD_KEATON_QUIZ,
  TINGLE_MILK_ROAD_RR,
  TINGLE_MILK_ROAD_GB,
//Mountain Village
  MOUNTAIN_VILLAGE_SMITH_DAY_ONE,
  MOUNTAIN_VILLAGE_SMITH_DAY_TWO,
  MOUNTAIN_VILLAGE_FROG_CHOIR,
  MOUNTAIN_VILLAGE_DARMANI,
  MOUNTAIN_VILLAGE_HUNGRY_GORON,
  MOUNTAIN_WATERFALL_CHEST,
  MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST,
//N Clock Town
  N_CLOCK_TOWN_GREAT_FAIRY_DEKU,
  //N_CLOCK_TOWN_BOMBERS_HIDE_SEEK, doesn't give an item in 3d
  N_CLOCK_TOWN_KEATON_QUIZ,
  N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS,
  N_CLOCK_TOWN_TREE,
  N_CLOCK_TOWN_OLD_LADY,
  N_CLOCK_TOWN_GREAT_FAIRY_HUMAN,
  TINGLE_N_CLOCK_TOWN_CT,
  TINGLE_N_CLOCK_TOWN_WF,
  N_CLOCK_TOWN_POSTBOX,
  //N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY,
//Road to Snowhead
  ROAD_TO_SNOWHEAD_PILLAR,
  ROAD_TO_SNOWHEAD_GROTTO_CHEST,
//Pinnacle Rock
  PINNACLE_ROCK_SEAHORSES,
  PINNACLE_ROCK_UPPER_CHEST,
  PINNACLE_ROCK_LOWER_CHEST,
  PINNACLE_ROCK_ZORA_EGG1,
  PINNACLE_ROCK_ZORA_EGG2,
  PINNACLE_ROCK_ZORA_EGG3,
//Road to Ikana
  ROAD_TO_IKANA_PILLAR_CHEST,
  ROAD_TO_IKANA_GROTTO_CHEST,
//Road to Southern Swamp
  ROAD_TO_SS_ARCHERY_1,
  ROAD_TO_SS_ARCHERY_2,
  ROAD_TO_SS_TREE,
  ROAD_TO_SWAMP_GROTTO_CHEST,
  TINGLE_ROAD_TO_SS_WF,
  TINGLE_ROAD_TO_SS_SH,
//Romani Ranch
  ROMANI_RANCH_ALIEN_DEFENSE,
  ROMANI_RANCH_DOG_RACE,
  ROMANI_RANCH_GROG,
  ROMANI_RANCH_CREMIA_ESCORT,
  ROMANI_RANCH_ROMANIS_GAME,
  ROMANI_RANCH_COW_1,
  ROMANI_RANCH_COW_2,
  ROMANI_RANCH_COW_3,
  DOGGY_RACETRACK_ROOF_CHEST,
//S Clock Town
  S_CLOCK_TOWN_SCRUB_TRADE,
  S_CLOCK_TOWN_POSTBOX,
  S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE,
  S_CLOCK_TOWN_STRAW_ROOF_CHEST,
  S_CLOCK_TOWN_FINAL_DAY_CHEST,
  S_CLOCK_TOWN_BANK_REWARD_1,
  S_CLOCK_TOWN_BANK_REWARD_2,
  S_CLOCK_TOWN_BANK_REWARD_3,
//Snowhead
  SNOWHEAD_GREAT_FAIRY,
//Southern Swamp
  SOUTHERN_SWAMP_KOUME,
  SOUTHERN_SWAMP_KOTAKE,
  SOUTHERN_SWAMP_KOTAKE_IN_WOODS,
  SOUTHERN_SWAMP_SCRUB_TRADE,
  SOUTHERN_SWAMP_PICTOGRAPH_WINNER,
  SOUTHERN_SWAMP_BOAT_ARCHERY,
  SWAMP_TOURIST_CENTER_ROOF,
  SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST,
  //SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD,--Handled in Dungeon.cpp
  SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST,
  SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE,
  //SOUTHERN_SWAMP_PICTOGRAPH_STANDARD,
  //SOUTHERN_SWAMP_PICTOGRAPH_GOOD,
  SOUTHERN_SWAMP_SCRUB_PURCHASE,
  POTION_SHOP_ITEM_1,
  POTION_SHOP_ITEM_2,
  POTION_SHOP_ITEM_3,
//StockPotInn
  STOCKPOTINN_RESERVATION,
  STOCKPOTINN_MIDNIGHT_MEETING,
  STOCKPOTINN_TOILET_HAND,
  STOCKPOTINN_GRANDMA_SHORT_STORY,
  STOCKPOTINN_GRANDMA_LONG_STORY,
  STOCKPOTINN_ANJU_AND_KAFEI,
  STOCKPOTINN_STAFF_ROOM_CHEST,
  STOCKPOTINN_GUEST_ROOM_CHEST,
//Stone Tower
  STONE_TOWER_INVERTED_RIGHT_CHEST,
  STONE_TOWER_INVERTED_CENTER_CHEST,
  STONE_TOWER_INVERTED_LEFT_CHEST,
//Termina Field
  TERMINA_FIELD_MOONS_TEAR,
  TERMINA_FIELD_GOSSIP_STONES,
  TERMINA_FIELD_BUSINESS_SCRUB,
  TERMINA_FIELD_PEAHAT_GROTTO_CHEST,
  TERMINA_FIELD_DODONGO_GROTTO_CHEST,
  TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE,
  TERMINA_FIELD_KAMARO,
  TERMINA_FIELD_PILLAR_GROTTO_CHEST,
  TERMINA_FIELD_GRASS_GROTTO_CHEST,
  TERMINA_FIELD_UNDERWATER_CHEST,
  TERMINA_FIELD_GRASS_CHEST,
  TERMINA_FIELD_STUMP_CHEST,
  TERMINA_FIELD_GROTTO_COW1,
  TERMINA_FIELD_GROTTO_COW2,
//Twin Islands
  HOT_SPRING_WATER_GROTTO_CHEST,
  TWIN_ISLANDS_GORON_RACE,
  TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST,
  TWIN_ISLANDS_UNDERWATER_RAMP_CHEST,
  TWIN_ISLANDS_CAVE_CHEST,
  TINGLE_TWIN_ISLANDS_SH,
  TINGLE_TWIN_ISLANDS_RR,
  TINGLE_TWIN_ISLANDS_SH_SPRING,
  TINGLE_TWIN_ISLANDS_RR_SPRING,
//W Clock Town
  W_CLOCK_TOWN_BOMB_BAG_BUY,
  W_CLOCK_TOWN_BIG_BOMB_BAG_BUY,
  W_CLOCK_TOWN_POSTMANS_GAME,
  W_CLOCK_TOWN_ROSA_SISTERS,
  W_CLOCK_TOWN_SWORDSMANS_SCHOOL,
  W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY,
  W_CLOCK_TOWN_BOMB_SHOP_GORON,
  W_CLOCK_TOWN_POSTBOX,
  //W_CLOCK_TOWN_LOTTERY,
  TRADING_POST_ITEM_1,
  TRADING_POST_ITEM_2,
  TRADING_POST_ITEM_3,
  TRADING_POST_ITEM_4,
  TRADING_POST_ITEM_5,
  TRADING_POST_ITEM_6,
  TRADING_POST_ITEM_7,
  TRADING_POST_ITEM_8,
  BOMB_SHOP_ITEM_1,
  BOMB_SHOP_ITEM_2,
  //BOMB_SHOP_ITEM_3,
//Woodfall
  WOODFALL_BRIDGE_CHEST,
  WOODFALL_BEHIND_OWL_CHEST,
  ENTRANCE_TO_WOODFALL_CHEST,
  WOODFALL_GREAT_FAIRY,
//Zora Cape
  ZORA_CAPE_GREAT_FAIRY,
  ZORA_CAPE_BEAVER_RACE_1,
  ZORA_CAPE_BEAVER_RACE_2,
  ZORA_CAPE_LIKE_LIKE,
  ZORA_CAPE_LEDGE_NO_TREE,
  ZORA_CAPE_LEDGE_WITH_TREE,
  ZORA_CAPE_GROTTO_CHEST,
  ZORA_CAPE_UNDERWATER_CHEST,
//Zora Hall
  ZORA_HALL_SCRUB_TRADE,
  ZORA_HALL_EVAN,
  ZORA_HALL_LULU_ROOM_LEDGE,
  ZORA_HALL_SCRUB_PURCHASE,
  //ZORA_HALL_STAGE_LIGHTS,
  //ZORA_HALL_BAD_PHOTO_LULU,
  //ZORA_HALL_GOOD_PHOTO_LULU,
  ZORA_SHOP_ITEM_1,
  ZORA_SHOP_ITEM_2,
  ZORA_SHOP_ITEM_3,

  /*----------------------
  |   REGTION HINT TEXT  |
  ----------------------*/
    HintTable[N_CLOCK_TOWN] = HintText::Region({ Text{"N Clock Town"}});
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

  /*---------------------
  |   JUNK HINT TEXT    |
  ---------------------*/
    HintTable[JUNK01] = HintText::Junk({Text{"junk hint here"}});
  JUNK02,
  JUNK03,
  JUNK04,
  JUNK05,
  JUNK06,
  JUNK07,
  JUNK08,
  JUNK09,
  JUNK10,
  JUNK11,
  JUNK12,
  JUNK13,
  JUNK14,
  JUNK15,
  JUNK16,
  JUNK17,
  JUNK18,
  JUNK19,
  JUNK20,
  JUNK21,
  JUNK22,
  JUNK23,
  JUNK24,
  JUNK25,
  JUNK26,
  JUNK27,
  JUNK28,
  JUNK29,
  JUNK30,
  JUNK31,
  JUNK32,
  JUNK33,
  JUNK34,
  JUNK35,
  JUNK36,
  JUNK37,
  JUNK38,
  JUNK39,
  JUNK40,
  JUNK41,
  JUNK42,
  JUNK43,
  JUNK44,
  JUNK45,
  JUNK46,
  JUNK47,
  JUNK48,
  JUNK49,
  JUNK50,
  JUNK51,
  JUNK52,
  JUNK53,
  JUNK54,
  JUNK55,
  JUNK56,
  JUNK57,
  JUNK58,
  JUNK59,
  JUNK60,
  JUNK61,
  JUNK62,
  JUNK63,
  JUNK64,
  JUNK65,
  JUNK66,
  JUNK67,
  JUNK68,
  JUNK69,
  JUNK70,
  JUMK71,
  JUNK72,
  JUNK73,
  JUNK74,
  JUNK75,
  JUNK76,
  JUNK77,

  /*------------------------
  |   DUNGEON HINT TEXT    |
  ------------------------*/

    hintTable[WOODFALL_TEMPLE] = HintText::DungeonName({Text{"the sleeping temple", "the sleeping temple", "the sleeping temple"}}),
  hintTable[SNOWHEAD_TEMPLE] = HintText::DungeonName({Text{"an icy temple", "an icy temple", "an icy temple"}});
  hintTable[GREAT_BAY_TEMPLE] = HintText::DungeonName({Text{"the murky watered temple", "the murky watered temple", "the murky watered temple"}});
  hintTable[STONE_TOWER_TEMPLE] = HintText::DungeonName({Text{"a rocky temple", "a rocky temple", "a rocky temple"}});
  hintTable[PIRATE_FORTRESS] = HintText::DungeonName({Text{"the home of pirates", "the home of pirates", "the home of pirates"}});
  hintTable[BENEATH_THE_WELL] = HintText::DungeonName({Text{"an empty watering hole", "an empty watering hole", "an empty watering hole"}});
  hintTable[IKANA_CASTLE]  = HintText::DungeonName({Text{"a fallen castle", "a fallen castle", "a fallen castle"}});
  hintTable[SECRET_SHRINE] = HintText::DungeonName({Text{"a mini boss run area", "a mini boss run area", "a mini boss run area"}});
  hintTable[SSH] = HintText::DungeonName({Text{"a home to muddy spiders", "a home to muddy spiders", "a home to muddy spiders"}});
  hintTable[OSH] = HintText::DungeonName({Text{"a home To swimming spiders", "a home To swimming spiders", "a home To swimming spiders"}});
  hintTable[THE_MOON] = HintText::DungeonName({Text{"a dungeon out of this world", "a dungeon out of this world", "a dungeon out of this world"}});

  /*-----------------------
  |    BOSS HINT TEXT     |
  -----------------------*/
  hintTable[ODOLWA] = HintText::Boss({Text{"A Tattooed Warrior", "A Tattooed Warrior", "A Tattooed Warrior"}});
  hintTable[GOHT] = HintText::Boss({Text{"A Mechanical Bull","A Mechanical Bull", "A Mechanical Bull"}});
  hintTable[GYORG] = HintText::Boss({Text{"A Poisonous Fish", "A Poisonous Fish", "A Poisonous Fish"}});
  hintTable[TWINMOLD] = HintText::Boss({Text{"A Giant Centipede Duo", "A Giant Centipede Duo", "A Giant Centipede Duo"}}),
  hintTable[MAJORA] = HintText::Boss({Text{"A Cursed Mask", "A Cursed Mask", "A Cursed Mask"}});
}

const HintText& Hint(const HintKey hintKey) {
    return hintTable[hintKey];
}

std::vector<HintText> GetHintCategory(HintCategory category) {

    std::vector<HintText> hintsInCategory = {};

    for (const auto& hint : hintTable) {
        if (hint.GetType() == category) {
            hintsInCategory.push_back(hint);
        }
    }
    return hintsInCategory;
}