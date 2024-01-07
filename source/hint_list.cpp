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
	hintTable[GBT_SMALL_KEY] = HintText::Item({ Text{"a useful key", "a useful key", "a useful key"} });
		//DUNGEON REWARDS
	hintTable[ODOLWAS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GOHTS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GYORGS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[TWINMOLDS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });

	/*-----------------------
	|  SOMETIMES HINT TEXT  |
	-----------------------*/
	// Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({ Text{"A Musical Instrument"}});
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({ Text{"a cursed removed"}});
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({ Text{"a masked man's melody"}});
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({ Text{"a masked man's gift"}});
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({ Text{"a new file"}});
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({ Text{"a new file"}});
  //PRE_CLOCK_TOWN_CHEST,
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({ Text{"a gorging merchant"}});
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({ Text{"the home of scrubs"}});
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({ Text{"the royal servant"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({ Text{"a merchant's cave"}});
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({ Text{"a false imprisonment"}});
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({ Text{"an important lady"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({ Text{"a town activity"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({ Text{"a town activity"}});
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({ Text{"a town leader"}});
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({ Text{"a lovers game"}});
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({ Text{"a treasure game"}});
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({ Text{"a delivery person"}});
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({ Text{"a miserable leader"}});
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({ Text{"an important lady"}});
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({ Text{"a secret hideout"}});
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({ Text{"a shop roof"}});
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({ Text{"a correspondence box"}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU] = HintText::Sometimes({ Text{""}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_MILK] = HintText::Sometimes({ Text{""}});
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({ Text{"an upset stomach cure"}});
  //hintTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY] = HintText::Sometimes({ Text{""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN] = HintText::Sometimes({ Text{""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA] = HintText::Sometimes({ Text{""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU] = HintText::Sometimes({ Text{""}});
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({ Text{"a large goron"}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({ Text{"a northern merchant"}});
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({ Text{"a lonely peak"}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({ Text{"a northern merchant"}});
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({ Text{"a cold ledge"}});
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({ Text{"a lonely child"}});
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({ Text{"a lonely peak"}});
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({ Text{"a lonely peak"}});
  //hintTable[GORON_SHOP_ITEM_1] = HintText::Sometimes({ Text{""}}); //To-Do?
  //hintTable[GORON_SHOP_ITEM_2] = HintText::Sometimes({ Text{""}});
  //hintTable[GORON_SHOP_ITEM_3] = HintText::Sometimes({ Text{""}});
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({ Text{"an ocean spider reward"}});
  //hintTable[GBC_OCEAN_SPIDER_DAY2] = HintText::Sometimes({ Text{""}});
  //hintTable[GBC_OCEAN_SPIDER_DAY3] = HintText::Sometimes({ Text{""}});
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({ Text{"an ocean game"}});
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({ Text{"the colored masks"}});
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({ Text{"feeding the fish"}});
    hintTable[GBC_LEDGE] = HintText::Sometimes({ Text{"an ocean ledge"}});
    hintTable[GBC_MIKAU] = HintText::Sometimes({ Text{"a healed spirit"}});
    hintTable[GBC_BABY_ZORAS]  = HintText::Sometimes({ Text{"the pirates' loot"}});
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({ Text{"an ocean cave"}});
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({ Text{"a lost creature"}});
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({ Text{"a lost creature"}});
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({ Text{"a fisherman"}});
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({ Text{"a map maker"}});
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({ Text{"a map maker"}});
//Ikana Canyon
    hintTable[IKANA_CANYON_GREAT_FAIRY] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_POE_HUT_HP] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_LEDGE] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_PAMELAS_FATHER] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_SCRUB_TRADE] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_CANYON_SCRUB_PURCHASE] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_IKANA_CANYON_ST] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_IKANA_CANYON_CT] = HintText::Sometimes({Text{""}});
//Ikana Graveyard
    hintTable[IKANA_GRAVEYARD_DAMPE_DIGGING] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS] = HintText::Sometimes({Text{""}});
    hintTable[IKANA_GRAVEYARD_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
//Laundry Pool
    hintTable[LAUNDRY_POOL_KAFEI] = HintText::Sometimes({Text{""}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE] = HintText::Sometimes({Text{""}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO] = HintText::Sometimes({Text{""}});
    hintTable[LAUNDRY_POOL_GURU_GURU] = HintText::Sometimes({Text{""}});
    hintTable[LAUNDRY_POOL_SF] = HintText::Sometimes({Text{""}});
//Milk Road
    hintTable[MILK_ROAD_GORMAN_RACE] = HintText::Sometimes({Text{""}});
    hintTable[MILK_ROAD_GORMAN_MILK_BUY] = HintText::Sometimes({Text{""}});
    hintTable[MILK_ROAD_KEATON_QUIZ] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_MILK_ROAD_RR] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_MILK_ROAD_GB] = HintText::Sometimes({Text{""}});
//Mountain Village
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_FROG_CHOIR] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_DARMANI] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_HUNGRY_GORON] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_WATERFALL_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
//N Clock Town
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU] = HintText::Sometimes({Text{""}});
  //hintTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK] = HintText::Sometimes({Text{""}}); doesn't give an item in 3d
    hintTable[N_CLOCK_TOWN_KEATON_QUIZ] = HintText::Sometimes({Text{""}});
    hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS] = HintText::Sometimes({Text{""}});
    hintTable[N_CLOCK_TOWN_TREE] = HintText::Sometimes({Text{""}});
    hintTable[N_CLOCK_TOWN_OLD_LADY] = HintText::Sometimes({Text{""}});
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_N_CLOCK_TOWN_CT] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_N_CLOCK_TOWN_WF] = HintText::Sometimes({Text{""}});
    hintTable[N_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({Text{""}});
  //hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY] = HintText::Sometimes({Text{""}});
//Road to Snowhead
    hintTable[ROAD_TO_SNOWHEAD_PILLAR] = HintText::Sometimes({Text{""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
//Pinnacle Rock
    hintTable[PINNACLE_ROCK_SEAHORSES] = HintText::Sometimes({Text{""}});
    hintTable[PINNACLE_ROCK_UPPER_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[PINNACLE_ROCK_LOWER_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG1] = HintText::Sometimes({Text{""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG2] = HintText::Sometimes({Text{""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG3] = HintText::Sometimes({Text{""}});
//Road to Ikana
    hintTable[ROAD_TO_IKANA_PILLAR_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[ROAD_TO_IKANA_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
//Road to Southern Swamp
    hintTable[ROAD_TO_SS_ARCHERY_1] = HintText::Sometimes({Text{""}});
    hintTable[ROAD_TO_SS_ARCHERY_2] = HintText::Sometimes({Text{""}});
    hintTable[ROAD_TO_SS_TREE] = HintText::Sometimes({Text{""}});
    hintTable[ROAD_TO_SWAMP_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_ROAD_TO_SS_WF] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_ROAD_TO_SS_SH] = HintText::Sometimes({Text{""}});
//Romani Ranch
    hintTable[ROMANI_RANCH_ALIEN_DEFENSE] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_DOG_RACE] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_GROG] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_CREMIA_ESCORT] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_ROMANIS_GAME] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_COW_1] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_COW_2] = HintText::Sometimes({Text{""}});
    hintTable[ROMANI_RANCH_COW_3] = HintText::Sometimes({Text{""}});
    hintTable[DOGGY_RACETRACK_ROOF_CHEST] = HintText::Sometimes({Text{""}});
//S Clock Town
    hintTable[S_CLOCK_TOWN_SCRUB_TRADE] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_FINAL_DAY_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_1] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_2] = HintText::Sometimes({Text{""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_3] = HintText::Sometimes({Text{""}});
//Snowhead
    hintTable[SNOWHEAD_GREAT_FAIRY] = HintText::Sometimes({Text{""}});
//Southern Swamp
    hintTable[SOUTHERN_SWAMP_KOUME] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_BOAT_ARCHERY] = HintText::Sometimes({Text{""}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
  //hintTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD] = HintText::Sometimes({Text{""}});--Handled in Dungeon.cpp
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE] = HintText::Sometimes({Text{""}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD] = HintText::Sometimes({Text{""}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD] = HintText::Sometimes({Text{""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE] = HintText::Sometimes({Text{""}});
    hintTable[POTION_SHOP_ITEM_1] = HintText::Sometimes({Text{""}});
    hintTable[POTION_SHOP_ITEM_2] = HintText::Sometimes({Text{""}});
    hintTable[POTION_SHOP_ITEM_3] = HintText::Sometimes({Text{""}});
//StockPotInn
    hintTable[STOCKPOTINN_RESERVATION] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_MIDNIGHT_MEETING] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_TOILET_HAND] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_GRANDMA_SHORT_STORY] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_GRANDMA_LONG_STORY] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_ANJU_AND_KAFEI] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_STAFF_ROOM_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[STOCKPOTINN_GUEST_ROOM_CHEST] = HintText::Sometimes({Text{""}});
//Stone Tower
    hintTable[STONE_TOWER_INVERTED_RIGHT_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[STONE_TOWER_INVERTED_CENTER_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[STONE_TOWER_INVERTED_LEFT_CHEST] = HintText::Sometimes({Text{""}});
//Termina Field
    hintTable[TERMINA_FIELD_MOONS_TEAR] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_KAMARO] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_UNDERWATER_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_GRASS_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_STUMP_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_GROTTO_COW1] = HintText::Sometimes({Text{""}});
    hintTable[TERMINA_FIELD_GROTTO_COW2] = HintText::Sometimes({Text{""}});
//Twin Islands
    hintTable[HOT_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TWIN_ISLANDS_GORON_RACE] = HintText::Sometimes({Text{""}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TWIN_ISLANDS_CAVE_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_TWIN_ISLANDS_SH] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_TWIN_ISLANDS_RR] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_TWIN_ISLANDS_SH_SPRING] = HintText::Sometimes({Text{""}});
    hintTable[TINGLE_TWIN_ISLANDS_RR_SPRING] = HintText::Sometimes({Text{""}});
//W Clock Town
    hintTable[W_CLOCK_TOWN_BOMB_BAG_BUY] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_POSTMANS_GAME] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_ROSA_SISTERS] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_BOMB_SHOP_GORON] = HintText::Sometimes({Text{""}});
    hintTable[W_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({Text{""}});
  //hintTable[W_CLOCK_TOWN_LOTTERY] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_1] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_2] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_3] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_4] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_5] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_6] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_7] = HintText::Sometimes({Text{""}});
    hintTable[TRADING_POST_ITEM_8] = HintText::Sometimes({Text{""}});
    hintTable[BOMB_SHOP_ITEM_1] = HintText::Sometimes({Text{""}});
    hintTable[BOMB_SHOP_ITEM_2] = HintText::Sometimes({Text{""}});
  //hintTable[BOMB_SHOP_ITEM_3] = HintText::Sometimes({Text{""}});
//Woodfall
    hintTable[WOODFALL_BRIDGE_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[WOODFALL_BEHIND_OWL_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[ENTRANCE_TO_WOODFALL_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[WOODFALL_GREAT_FAIRY] = HintText::Sometimes({Text{""}});
//Zora Cape
    hintTable[ZORA_CAPE_GREAT_FAIRY] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_BEAVER_RACE_1] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_BEAVER_RACE_2] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_LIKE_LIKE] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_LEDGE_NO_TREE] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_LEDGE_WITH_TREE] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_GROTTO_CHEST] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_CAPE_UNDERWATER_CHEST] = HintText::Sometimes({Text{""}});
//Zora Hall
    hintTable[ZORA_HALL_SCRUB_TRADE] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_HALL_EVAN] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_HALL_LULU_ROOM_LEDGE] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_HALL_SCRUB_PURCHASE] = HintText::Sometimes({Text{""}});
  //hintTable[ZORA_HALL_STAGE_LIGHTS] = HintText::Sometimes({Text{""}});
  //hintTable[ZORA_HALL_BAD_PHOTO_LULU] = HintText::Sometimes({Text{""}});
  //hintTable[ZORA_HALL_GOOD_PHOTO_LULU] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_SHOP_ITEM_1] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_SHOP_ITEM_2] = HintText::Sometimes({Text{""}});
    hintTable[ZORA_SHOP_ITEM_3] = HintText::Sometimes({Text{""}});

  /*----------------------
  |   REGTION HINT TEXT  |
  ----------------------*/
    hintTable[N_CLOCK_TOWN] = HintText::Region({ Text{"N Clock Town"}});
    hintTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_DEKU_PLAYGROUND] = HintText::Region({Text{""}});
    hintTable[E_CLOCK_TOWN] = HintText::Region({Text{""}});
    hintTable[STOCKPOTINN] = HintText::Region({Text{""}});
    hintTable[STOCKPOTINN_GUEST_ROOM] = HintText::Region({Text{""}});
    hintTable[STOCKPOTINN_STAFF_ROOM] = HintText::Region({Text{""}});
    hintTable[STOCKPOTINN_GRANDMA_ROOM] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_OBSERVATORY] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_BAR] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_HONEY_DARLING] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_ARCHERY] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_MAYOR_HOUSE] = HintText::Region({Text{""}});
    hintTable[W_CLOCK_TOWN] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_POSTMAN_HOUSE] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_LOTTERY] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_BOMB_SHOP] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_TRADING_POST] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWN_CURIOSITY_SHOP] = HintText::Region({Text{""}});
    hintTable[S_CLOCK_TOWN] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWER] = HintText::Region({Text{""}});
    hintTable[CLOCK_TOWER_ROOF] = HintText::Region({Text{""}});
    hintTable[LAUNDRY_POOL] = HintText::Region({Text{""}});
    hintTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_COW_GROTTO] = HintText::Region({Text{""}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_SWAMP_GROTTO] = HintText::Region({Text{""}});
    hintTable[SOUTHERN_SWAMP] = HintText::Region({Text{""}});
    hintTable[SWAMP_TOURIST_CENTER] = HintText::Region({Text{""}});
    hintTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = HintText::Region({Text{""}});
    hintTable[MYSTERY_WOODS] = HintText::Region({Text{""}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = HintText::Region({Text{""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = HintText::Region({Text{""}});
    hintTable[SOUTHERN_SWAMP_TOP] = HintText::Region({Text{""}});
    hintTable[DEKU_PALACE] = HintText::Region({Text{""}});
    hintTable[DEKU_PALACE_INTERIOR] = HintText::Region({Text{""}});
    hintTable[DEKU_PALACE_BEAN_GROTTO] = HintText::Region({Text{""}});
    hintTable[DEKU_SHRINE] = HintText::Region({Text{""}});
    hintTable[WOODFALL] = HintText::Region({Text{""}});
    hintTable[WOODFALL_FAIRY_FOUNTAIN] = HintText::Region({Text{""}});
    hintTable[PATH_TO_MOUNTAIN_VILLAGE] = HintText::Region({Text{""}});
    hintTable[MOUNTAIN_VILLAGE] = HintText::Region({Text{""}});
    hintTable[GORON_GRAVEYARD] = HintText::Region({Text{""}});
    hintTable[MOUNTAIN_SMITHY] = HintText::Region({Text{""}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = HintText::Region({Text{""}});
    hintTable[TWIN_ISLANDS] = HintText::Region({Text{""}});
    hintTable[GORON_RACETRACK] = HintText::Region({Text{""}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = HintText::Region({Text{""}});
    hintTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = HintText::Region({Text{""}});
    hintTable[GORON_VILLAGE] = HintText::Region({Text{""}});
    hintTable[GORON_VILLAGE_LENS_CAVE] = HintText::Region({Text{""}});
    hintTable[GORON_VILLAGE_INTERIOR] = HintText::Region({Text{""}});
    hintTable[GORON_VILLAGE_SHOP] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_SNOWHEAD] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO] = HintText::Region({Text{""}});
    hintTable[SNOWHEAD] = HintText::Region({Text{""}});
    hintTable[SNOWHEAD_FAIRY_FOUNTAIN] = HintText::Region({Text{""}});
    hintTable[MILK_ROAD] = HintText::Region({Text{""}});
    hintTable[GORMAN_TRACK] = HintText::Region({Text{""}});
    hintTable[ROMANI_RANCH] = HintText::Region({Text{""}});
    hintTable[DOGGY_RACETRACK] = HintText::Region({Text{""}});
    hintTable[CUCCO_SHACK] = HintText::Region({Text{""}});
    hintTable[ROMANI_RANCH_HOUSE] = HintText::Region({Text{""}});
    hintTable[ROMANI_RANCH_BARN] = HintText::Region({Text{""}});
    hintTable[GREAT_BAY_COAST] = HintText::Region({Text{""}});
    hintTable[GREAT_BAY_COAST_MARINE_LAB] = HintText::Region({Text{""}});
    hintTable[GREAT_BAY_COAST_GROTTO] = HintText::Region({Text{""}});
    hintTable[GREAT_BAY_COAST_COW_GROTTO] = HintText::Region({Text{""}});
    hintTable[FISHERMAN_HUT] = HintText::Region({Text{""}});
    hintTable[PINNACLE_ROCK] = HintText::Region({Text{""}});
    hintTable[ZORA_CAPE] = HintText::Region({Text{""}});
    hintTable[WATERFALL_RAPIDS] = HintText::Region({Text{""}});
    hintTable[GREAT_BAY_FAIRY_FOUNTAIN] = HintText::Region({Text{""}});
    hintTable[ZORA_CAPE_GROTTO] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_EVANS_ROOM] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_LULUS_ROOM] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_JAPAS_ROOM] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_TIJOS_ROOM] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_SHOP] = HintText::Region({Text{""}});
    hintTable[ZORA_HALL_BACK_ENTRANCE] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_IKANA] = HintText::Region({Text{""}});
    hintTable[ROAD_TO_IKANA_GROTTO] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_GROTTO] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_BATS_ROOM] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_TABLET_ROOM] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = HintText::Region({Text{""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = HintText::Region({Text{""}});
    hintTable[DAMPES_HUT] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON_UPPER] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON_CAVE] = HintText::Region({Text{""}});
    hintTable[SAKONS_HIDEOUT] = HintText::Region({Text{""}});
    hintTable[MUSIC_BOX_HOUSE] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON_POE_HUT] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = HintText::Region({Text{""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = HintText::Region({Text{""}});
    hintTable[STONE_TOWER] = HintText::Region({Text{""}});
    hintTable[INVERTED_STONE_TOWER] = HintText::Region({Text{""}});

  /*---------------------
  |   JUNK HINT TEXT    |
  ---------------------*/
    hintTable[JUNK01] = HintText::Junk({Text{"junk hint here"}});
    hintTable[JUNK02] = HintText::Junk({Text{""}});
    hintTable[JUNK03] = HintText::Junk({Text{""}});
    hintTable[JUNK04] = HintText::Junk({Text{""}});
    hintTable[JUNK05] = HintText::Junk({Text{""}});
    hintTable[JUNK06] = HintText::Junk({Text{""}});
    hintTable[JUNK07] = HintText::Junk({Text{""}});
    hintTable[JUNK08] = HintText::Junk({Text{""}});
    hintTable[JUNK09] = HintText::Junk({Text{""}});
    hintTable[JUNK10] = HintText::Junk({Text{""}});
    hintTable[JUNK11] = HintText::Junk({Text{""}});
    hintTable[JUNK12] = HintText::Junk({Text{""}});
    hintTable[JUNK13] = HintText::Junk({Text{""}});
    hintTable[JUNK14] = HintText::Junk({Text{""}});
    hintTable[JUNK15] = HintText::Junk({Text{""}});
    hintTable[JUNK16] = HintText::Junk({Text{""}});
    hintTable[JUNK17] = HintText::Junk({Text{""}});
    hintTable[JUNK18] = HintText::Junk({Text{""}});
    hintTable[JUNK19] = HintText::Junk({Text{""}});
    hintTable[JUNK20] = HintText::Junk({Text{""}});
    hintTable[JUNK21] = HintText::Junk({Text{""}});
    hintTable[JUNK22] = HintText::Junk({Text{""}});
    hintTable[JUNK23] = HintText::Junk({Text{""}});
    hintTable[JUNK24] = HintText::Junk({Text{""}});
    hintTable[JUNK25] = HintText::Junk({Text{""}});
    hintTable[JUNK26] = HintText::Junk({Text{""}});
    hintTable[JUNK27] = HintText::Junk({Text{""}});
    hintTable[JUNK28] = HintText::Junk({Text{""}});
    hintTable[JUNK29] = HintText::Junk({Text{""}});
    hintTable[JUNK30] = HintText::Junk({Text{""}});
    hintTable[JUNK31] = HintText::Junk({Text{""}});
    hintTable[JUNK32] = HintText::Junk({Text{""}});
    hintTable[JUNK33] = HintText::Junk({Text{""}});
    hintTable[JUNK34] = HintText::Junk({Text{""}});
    hintTable[JUNK35] = HintText::Junk({Text{""}});
    hintTable[JUNK36] = HintText::Junk({Text{""}});
    hintTable[JUNK37] = HintText::Junk({Text{""}});
    hintTable[JUNK38] = HintText::Junk({Text{""}});
    hintTable[JUNK39] = HintText::Junk({Text{""}});
    hintTable[JUNK40] = HintText::Junk({Text{""}});
    hintTable[JUNK41] = HintText::Junk({Text{""}});
    hintTable[JUNK42] = HintText::Junk({Text{""}});
    hintTable[JUNK43] = HintText::Junk({Text{""}});
    hintTable[JUNK44] = HintText::Junk({Text{""}});
    hintTable[JUNK45] = HintText::Junk({Text{""}});
    hintTable[JUNK46] = HintText::Junk({Text{""}});
    hintTable[JUNK47] = HintText::Junk({Text{""}});
    hintTable[JUNK48] = HintText::Junk({Text{""}});
    hintTable[JUNK49] = HintText::Junk({Text{""}});
    hintTable[JUNK50] = HintText::Junk({Text{""}});
    hintTable[JUNK51] = HintText::Junk({Text{""}});
    hintTable[JUNK52] = HintText::Junk({Text{""}});
    hintTable[JUNK53] = HintText::Junk({Text{""}});
    hintTable[JUNK54] = HintText::Junk({Text{""}});
    hintTable[JUNK55] = HintText::Junk({Text{""}});
    hintTable[JUNK56] = HintText::Junk({Text{""}});
    hintTable[JUNK57] = HintText::Junk({Text{""}});
    hintTable[JUNK58] = HintText::Junk({Text{""}});
    hintTable[JUNK59] = HintText::Junk({Text{""}});
    hintTable[JUNK60] = HintText::Junk({Text{""}});
    hintTable[JUNK61] = HintText::Junk({Text{""}});
    hintTable[JUNK62] = HintText::Junk({Text{""}});
    hintTable[JUNK63] = HintText::Junk({Text{""}});
    hintTable[JUNK64] = HintText::Junk({Text{""}});
    hintTable[JUNK65] = HintText::Junk({Text{""}});
    hintTable[JUNK66] = HintText::Junk({Text{""}});
    hintTable[JUNK67] = HintText::Junk({Text{""}});
    hintTable[JUNK68] = HintText::Junk({Text{""}});
    hintTable[JUNK69] = HintText::Junk({Text{""}});
    hintTable[JUNK70] = HintText::Junk({Text{""}});
    hintTable[JUMK71] = HintText::Junk({Text{""}});
    hintTable[JUNK72] = HintText::Junk({Text{""}});
    hintTable[JUNK73] = HintText::Junk({Text{""}});
    hintTable[JUNK74] = HintText::Junk({Text{""}});
    hintTable[JUNK75] = HintText::Junk({Text{""}});
    hintTable[JUNK76] = HintText::Junk({Text{""}});
    hintTable[JUNK77] = HintText::Junk({Text{""}});

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