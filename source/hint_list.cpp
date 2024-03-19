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
	hintTable[HEROS_BOW] = HintText::Item({Text{"a bow", "a bow", "a bow"}});
    hintTable[FIRE_ARROWS] = HintText::Item({ Text{"the power of fire", "the power of fire", "the power of fire"} });
	hintTable[ICE_ARROWS] = HintText::Item({ Text{"the power of ice", "the power of ice", "the power of ice"} });
	hintTable[LIGHT_ARROWS] = HintText::Item({ Text{"the power of light", "the power of light", "the power of light"} });
	hintTable[HOOKSHOT] = HintText::Item({ Text{"a chain and grapple", "a chain and grapple", "a chain and grapple"} });
	hintTable[MAGIC_BEAN] = HintText::Item({ Text{"a plant seed", "a plant seed", "a plant seed"} });
	hintTable[MAGIC_BEAN_PACK] = HintText::Item({ Text{"multiple plant seeds", "multiple plant seeds", "multiple plant seeds"} });
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
	hintTable[FIERCE_DEITY_MASK] = HintText::Item({ Text{"the wrath of a god", "the wrath of a god", "the wrath of a god"}});
	hintTable[MASK_OF_TRUTH] = HintText::Item({ Text{"a piercing gaze", "a piercing gaze", "a piercing gaze"}});
	hintTable[FISHING_PASS] = HintText::Item({Text{"a fishing pass", "a fishing passs", "a fishing pass"}});
	hintTable[ICE_TRAP] = HintText::Item({Text{"a frosty surprise", "a frosty surprise", "a frosty surprise"}});
    hintTable[ZORA_EGG] = HintText::Item({Text{"a zora egg", "a zora egg", "a zora egg"}});
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
	hintTable[EMPTY_BOTTLE] = HintText::Item({ Text{"a glass container", "a glass container", "a glass container"} });
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
	hintTable[BOTTLE_WITH_MYSTERY_MILK] = HintText::Item({ Text{"a strange drink", "a strange drink", "a strange drink"}});
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
    hintTable[LULLABY_INTRO] =  HintText::Item({ Text{"a sleepy melody intro", "a sleepy melody intro", "a sleepy melody intro"}});
	hintTable[GORONS_LULLABY] = HintText::Item({ Text{"a sleepy melody", "a sleepy melody", "a sleepy melody"}});
	hintTable[NEW_WAVE_BOSSA_NOVA] = HintText::Item({ Text{"a song of newborns", "a song of newborns", "a song of newborns"}});
	hintTable[ELEGY_OF_EMPTINESS] = HintText::Item({ Text{"empty shells", "empty shells", "empty shells"}});
	hintTable[OATH_TO_ORDER] = HintText::Item({ Text{"a song of giants", "a song of giants", "a song of giants"}});
		//PIECES OF HEART
	hintTable[PIECE_OF_HEART] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[HEART_CONTAINER] = HintText::Item({Text{"a new heart","a new heart", "a new heart"}});
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
	hintTable[WOODFALL_TEMPLE_SMALL_KEY] = HintText::Item({Text{"swampy small key", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_SMALL_KEY] = HintText::Item({Text{"icy small key", "", ""}});
    hintTable[GBT_SMALL_KEY] = HintText::Item({Text{"ocean small key", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_SMALL_KEY] = HintText::Item({Text{"rocky small key", "", ""}});
        //DUNGEON REWARDS
	hintTable[ODOLWAS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GOHTS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[GYORGS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
	hintTable[TWINMOLDS_REMAINS] = HintText::Item({ Text{"a boss's remains", "a boss's remains", "a boss's remains"} });
    
    /*-----------------------
    |    REFILL ITEMS       |
    -----------------------*/
    hintTable[RECOVERY_HEART] = HintText::Item({Text{"Recovery Heart","",""}});
    hintTable[GREEN_RUPEE] = HintText::Item({Text{"Green rupee", "", ""}});
    hintTable[BLUE_RUPEE] = HintText::Item({Text{"Blue rupee", "", ""}});
    hintTable[RED_RUPEE] = HintText::Item({Text{"Red rupee", "", ""}});
    hintTable[PURPLE_RUPEE] = HintText::Item({Text{"Purple rupee", "", ""}});
    hintTable[SILVER_RUPEE] = HintText::Item({Text{"Silver rupee", "", ""}});
    hintTable[HUGE_RUPEE] = HintText::Item({Text{"Huge rupee", "", ""}});
    hintTable[DEKU_NUTS_5] = HintText::Item({Text{"5 nuts", "", ""}});
    hintTable[DEKU_NUTS_10] = HintText::Item({Text{"10 nuts", "", ""}});
    hintTable[BOMBS_5] = HintText::Item({Text{"5 explosive orbs", "", ""}});
    hintTable[BOMBS_10] = HintText::Item({Text{"10 explosive orbs", "", ""}});
    hintTable[BOMBS_20] = HintText::Item({Text{"20 explosive orbs", "", ""}});
    hintTable[BOMBCHU_5] = HintText::Item({Text{"5 explosive mice", "", ""}});
    hintTable[BOMBCHU_10] = HintText::Item({Text{"10 explosive mice", "", ""}});
    hintTable[BOMBCHU_20] = HintText::Item({Text{"20 explosive mice", "", ""}});
    hintTable[ARROWS_10] = HintText::Item({Text{"10 projectile sticks", "", ""}});
    hintTable[ARROWS_30] = HintText::Item({Text{"30 projectile sticks", "", ""}});
    hintTable[ARROWS_40] = HintText::Item({Text{"40 projectile sticks", "", ""}});
    hintTable[ARROWS_50] = HintText::Item({Text{"50 projectile sticks", "", ""}});
    hintTable[BLUE_POTION_REFILL] = HintText::Item({Text{"Blue Potion Refill", "", ""}});
    hintTable[GREEN_POTION_REFILL] = HintText::Item({Text{"Green Potion Refill", "", ""}});
    hintTable[RED_POTION_REFILL] = HintText::Item({Text{"Red Potion Refill", "", ""}});
    hintTable[BOMBCHU_DROP] = HintText::Item({Text{"explosive mice", "", ""}});
    hintTable[DEKU_STICK_1] = HintText::Item({Text{"1 stick", "",""}});
	
    /*----------------
    |   SHOP ITEMS   |
    ----------------*/
    hintTable[BUY_ARROWS_10] = HintText::Item({Text{"Buy 10 Arrows","",""}});
    hintTable[BUY_ARROWS_30] = HintText::Item({Text{"Buy 30 Arrows","",""}});
    hintTable[BUY_BLUE_POTION] = HintText::Item({Text{"Buy Blue Potion","",""}});
    hintTable[BUY_BOMBCHU_10] = HintText::Item({Text{"Buy 10 Bombchu","",""}});
    hintTable[BUY_BOMBS_10] = HintText::Item({Text{"Buy 10 Bombs","",""}});
    hintTable[BUY_DEKU_NUT_10] = HintText::Item({Text{"Buy 10 Deku Nuts","",""}});
    hintTable[BUY_DEKU_STICK_1] = HintText::Item({Text{"Buy 1 Deku Stick","",""}});
    hintTable[BUY_FAIRYS_SPIRIT] = HintText::Item({Text{"Buy Fairy","",""}});
    hintTable[BUY_GREEN_POTION] = HintText::Item({Text{"Buy Green Potion","",""}});
    hintTable[BUY_HEROS_SHIELD] = HintText::Item({Text{"Buy Hero Shield","",""}});
    hintTable[BUY_MAGIC_BEAN] = HintText::Item({Text{"Buy Magic Bean","",""}});
    hintTable[BUY_RED_POTION] = HintText::Item({Text{"Buy Red Potion","",""}});

    /*-----------------------
	|  SOMETIMES HINT TEXT  |
	-----------------------*/
	// Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({ Text{"A Musical Instrument","A Musical Instrument","A Musical Instrument"}});
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({ Text{"a forest curse removed rewards","a cursed removed","a cursed removed"}});
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({ Text{"a masked man's melody teaches","a masked man's melody","a masked man's melody"}});
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({ Text{"a masked man's gift rewards","a masked man's gift","a masked man's gift"}});
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({ Text{"a new file yields","a new file","a new file"}});
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({ Text{"a new file yields","a new file","a new file"}});
  //PRE_CLOCK_TOWN_CHEST,
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({ Text{"a gorging merchant sells", "", ""}});
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({ Text{"the home of scrubs contains", "", ""}});
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({ Text{"the royal servant rewards", "", ""}});
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({ Text{"a merchant's cave contains", "", ""}});
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({ Text{"a false imprisonment teaches", "", ""}});
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({ Text{"an important lady rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({ Text{"a town activity rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({ Text{"a town activity rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({ Text{"a town leader rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({ Text{"a lovers game rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({ Text{"a treasure game rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({ Text{"a delivery person rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({ Text{"a miserable leader rewards", "", ""}});
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({ Text{"an important lady rewards", "", ""}});
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({ Text{"a secret hideout contains", "", ""}});
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({ Text{"a shop roof contains", "", ""}});
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({ Text{"a correspondence box contains", "", ""}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU] = HintText::Sometimes({ Text{"", "", ""}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_MILK] = HintText::Sometimes({ Text{"", "", ""}});
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({ Text{"an upset stomach cure rewards", "", ""}});
  //hintTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY] = HintText::Sometimes({ Text{"", "", ""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN] = HintText::Sometimes({ Text{"", "", ""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA] = HintText::Sometimes({ Text{"", "", ""}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU] = HintText::Sometimes({ Text{"", "", ""}});
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({ Text{"a large goron rewards", "", ""}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({ Text{"a northern merchant sells", "", ""}});
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({ Text{"a lonely peak contains", "", ""}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({ Text{"a northern merchant trades", "", ""}});
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({ Text{"a cold ledge contains", "", ""}});
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING] = HintText::Sometimes({ Text{"a large goron rewards", "", ""}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE_SPRING] = HintText::Sometimes({ Text{"a northern merchant sells", "", ""}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE_SPRING] = HintText::Sometimes({ Text{"a northern merchant trades", "", ""}});
    hintTable[GORON_VILLAGE_LEDGE_SPRING] = HintText::Sometimes({ Text{"a cold ledge contains", "", ""}});
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({ Text{"a lonely child teaches", "", ""}});
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({ Text{"a lonely peak contains", "", ""}});
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({ Text{"a lonely peak contains", "", ""}});
    hintTable[GORON_SHOP_ITEM_1] = HintText::Sometimes({ Text{"a goron shop sells", "", ""}});
    hintTable[GORON_SHOP_ITEM_2] = HintText::Sometimes({ Text{"a goron shop sells", "", ""}});
    hintTable[GORON_SHOP_ITEM_3] = HintText::Sometimes({ Text{"a goron shop sells", "", ""}});
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({ Text{"a new ocean home owner rewards", "", ""}});
  //hintTable[GBC_OCEAN_SPIDER_DAY2] = HintText::Sometimes({ Text{"", "", ""}});
  //hintTable[GBC_OCEAN_SPIDER_DAY3] = HintText::Sometimes({ Text{"", "", ""}});
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({ Text{"an ocean game rewards", "", ""}});
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({ Text{"the colored masks contains", "", ""}});
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({ Text{"feeding the fish rewards", "", ""}});
    hintTable[GBC_LEDGE] = HintText::Sometimes({ Text{"an ocean ledge contains", "", ""}});
    hintTable[GBC_MIKAU] = HintText::Sometimes({ Text{"a healed spirit rewards", "", ""}});
    hintTable[GBC_BABY_ZORAS]  = HintText::Sometimes({ Text{"the pirates' loot teaches", "", ""}});
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({ Text{"an ocean cave contains", "", ""}});
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({ Text{"a lost creature gives", "", ""}});
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({ Text{"a lost creature gives", "", ""}});
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({ Text{"a fisherman rewards", "", ""}});
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({ Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({ Text{"a map maker sells", "", ""}});
//Ikana Canyon
    hintTable[IKANA_CANYON_GREAT_FAIRY] = HintText::Sometimes({Text{"the fairy of kindness rewards", "", ""}});
    hintTable[IKANA_CANYON_POE_HUT_HP] = HintText::Sometimes({Text{"a game of ghosts rewards", "", ""}});
    hintTable[IKANA_CANYON_LEDGE] = HintText::Sometimes({Text{"a canyon ledge contains", "", ""}});
    hintTable[IKANA_CANYON_PAMELAS_FATHER] = HintText::Sometimes({Text{"a lost father rewards", "", ""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST] = HintText::Sometimes({Text{"a waterfall cave contains", "", ""}});
    hintTable[IKANA_CANYON_SCRUB_TRADE] = HintText::Sometimes({Text{"an eastern merchant trades", "", ""}});
    hintTable[IKANA_CANYON_SCRUB_PURCHASE] = HintText::Sometimes({Text{"an eastern merchant sells", "", ""}});
    hintTable[TINGLE_IKANA_CANYON_ST] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_IKANA_CANYON_CT] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
//Ikana Graveyard
    hintTable[IKANA_GRAVEYARD_DAMPE_DIGGING] = HintText::Sometimes({Text{"a fearful basement contains", "", ""}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST] = HintText::Sometimes({Text{"a hollow ground contains", "", ""}});
    hintTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST] = HintText::Sometimes({Text{"a skeletal leader rewards", "", ""}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET] = HintText::Sometimes({Text{"a hollow ground teaches", "", ""}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS] = HintText::Sometimes({Text{"a cloud of bats contains", "", ""}});
    hintTable[IKANA_GRAVEYARD_GROTTO_CHEST] = HintText::Sometimes({Text{"a circled cave contains", "", ""}});
//Laundry Pool
    hintTable[LAUNDRY_POOL_KAFEI] = HintText::Sometimes({Text{"a posted letter rewards", "", ""}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE] = HintText::Sometimes({Text{"a shady dealer rewards", "", ""}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO] = HintText::Sometimes({Text{"a shady dealer rewards", "", ""}});
    hintTable[LAUNDRY_POOL_GURU_GURU] = HintText::Sometimes({Text{"a musician gives", "", ""}});
    hintTable[LAUNDRY_POOL_SF] = HintText::Sometimes({Text{"a lost fairy is", "", ""}});
//Milk Road
    hintTable[MILK_ROAD_GORMAN_RACE] = HintText::Sometimes({Text{"a sporting event rewards", "", ""}});
    hintTable[MILK_ROAD_GORMAN_MILK_BUY] = HintText::Sometimes({Text{"a dodgy seller sells", "", ""}});
    hintTable[MILK_ROAD_KEATON_QUIZ] = HintText::Sometimes({Text{"a mysterious fox rewards", "", ""}});
    hintTable[TINGLE_MILK_ROAD_RR] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_MILK_ROAD_GB] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
//Mountain Village
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE] = HintText::Sometimes({Text{"a moutain smith crafts", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO] = HintText::Sometimes({Text{"a mountain smith crafts", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_FROG_CHOIR] = HintText::Sometimes({Text{"a frog choir rewards", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_KEATON_QUIZ] = HintText::Sometimes({Text{"a mysterious fox rewards", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_DARMANI] = HintText::Sometimes({Text{"a mountain spirit rewards", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_HUNGRY_GORON] = HintText::Sometimes({Text{"a hungry goron rewards", "", ""}});
    hintTable[MOUNTAIN_WATERFALL_CHEST] = HintText::Sometimes({Text{"a springtime waterfall contains", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({Text{"a springtime cave contains", "", ""}});
//N Clock Town
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU] = HintText::Sometimes({Text{"the fairy of magic rewards", "", ""}});
  //hintTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK] = HintText::Sometimes({Text{"", "", ""}}); doesn't give an item in 3d
    hintTable[N_CLOCK_TOWN_KEATON_QUIZ] = HintText::Sometimes({Text{"a mysterious fox rewards", "", ""}});
    hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS] = HintText::Sometimes({Text{"a game for scrubs rewards", "", ""}});
    hintTable[N_CLOCK_TOWN_TREE] = HintText::Sometimes({Text{"a town playground contains", "", ""}});
    hintTable[N_CLOCK_TOWN_OLD_LADY] = HintText::Sometimes({Text{"an old lady's struggle rewards", "", ""}});
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN] = HintText::Sometimes({Text{"the fairy of magi rewardsc", "", ""}});
    hintTable[TINGLE_N_CLOCK_TOWN_CT] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_N_CLOCK_TOWN_WF] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[N_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({Text{"a correspondence box contains", "", ""}});
  //hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY] = HintText::Sometimes({Text{"a game for scrubs", "", ""}});
//Road to Snowhead
    hintTable[ROAD_TO_SNOWHEAD_PILLAR] = HintText::Sometimes({Text{"a cold platform contains", "", ""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST] = HintText::Sometimes({Text{"a snowy cave contains", "", ""}});
//Pinnacle Rock
    hintTable[PINNACLE_ROCK_SEAHORSES] = HintText::Sometimes({Text{"a fishy reunion rewards", "", ""}});
    hintTable[PINNACLE_ROCK_UPPER_CHEST] = HintText::Sometimes({Text{"a marine trench contains", "", ""}});
    hintTable[PINNACLE_ROCK_LOWER_CHEST] = HintText::Sometimes({Text{"a marine trench contains", "", ""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG1] = HintText::Sometimes({Text{"in a marine trench rests", "", ""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG2] = HintText::Sometimes({Text{"in a marine trench rests", "", ""}});
    hintTable[PINNACLE_ROCK_ZORA_EGG3] = HintText::Sometimes({Text{"in a marine trench rests", "", ""}});
//Road to Ikana
    hintTable[ROAD_TO_IKANA_PILLAR_CHEST] = HintText::Sometimes({Text{"a high chest contains", "", ""}});
    hintTable[ROAD_TO_IKANA_GROTTO_CHEST] = HintText::Sometimes({Text{"a blocked cave contains", "", ""}});
//Road to Southern Swamp
    hintTable[ROAD_TO_SS_ARCHERY_1] = HintText::Sometimes({Text{"a swamp game rewards", "", ""}});
    hintTable[ROAD_TO_SS_ARCHERY_2] = HintText::Sometimes({Text{"a swamp game rewards", "", ""}});
    hintTable[ROAD_TO_SS_TREE] = HintText::Sometimes({Text{"a batty tree contains", "", ""}});
    hintTable[ROAD_TO_SWAMP_GROTTO_CHEST] = HintText::Sometimes({Text{"a southern cave contains", "", ""}});
    hintTable[TINGLE_ROAD_TO_SS_WF] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_ROAD_TO_SS_SH] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
//Romani Ranch
    hintTable[ROMANI_RANCH_ALIEN_DEFENSE] = HintText::Sometimes({Text{"a ranch invasion rewards", "", ""}});
    hintTable[ROMANI_RANCH_DOG_RACE] = HintText::Sometimes({Text{"a sporting event rewards", "", ""}});
    hintTable[ROMANI_RANCH_GROG] = HintText::Sometimes({Text{"a chicken lover rewards", "", ""}});
    hintTable[ROMANI_RANCH_CREMIA_ESCORT] = HintText::Sometimes({Text{"an older sister rewards", "", ""}});
    hintTable[ROMANI_RANCH_ROMANIS_GAME] = HintText::Sometimes({Text{"an equine reunion teaches", "", ""}});
    hintTable[ROMANI_RANCH_COW_1] = HintText::Sometimes({Text{"a lost creature gives", "", ""}});
    hintTable[ROMANI_RANCH_COW_2] = HintText::Sometimes({Text{"a lost creature gives", "", ""}});
    hintTable[ROMANI_RANCH_COW_3] = HintText::Sometimes({Text{"a lost creature gives", "", ""}});
    hintTable[DOGGY_RACETRACK_ROOF_CHEST] = HintText::Sometimes({Text{"a day at the races contains", "", ""}});
//S Clock Town
    hintTable[S_CLOCK_TOWN_SCRUB_TRADE] = HintText::Sometimes({Text{"a town merchant trades", "", ""}});
    hintTable[S_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({Text{"a correspondence box contains", "", ""}});
    hintTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE] = HintText::Sometimes({Text{"the tower doors contains", "", ""}});
    hintTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST] = HintText::Sometimes({Text{"a straw roof contains", "", ""}});
    hintTable[S_CLOCK_TOWN_FINAL_DAY_CHEST] = HintText::Sometimes({Text{"a carnival tower contains", "", ""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_1] = HintText::Sometimes({Text{"a keeper of wealth rewards", "", ""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_2] = HintText::Sometimes({Text{"interest rewards", "", ""}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_3] = HintText::Sometimes({Text{"being rich rewards", "", ""}});
//Snowhead
    hintTable[SNOWHEAD_GREAT_FAIRY] = HintText::Sometimes({Text{"the fairy of power rewards", "", ""}});
//Southern Swamp
    hintTable[SOUTHERN_SWAMP_KOUME] = HintText::Sometimes({Text{"a witch rewards", "", ""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE] = HintText::Sometimes({Text{"a sleeping witch rewards", "", ""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS] = HintText::Sometimes({Text{"a witch rewards", "", ""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE] = HintText::Sometimes({Text{"a southern merchant trades", "", ""}});
    hintTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER] = HintText::Sometimes({Text{"a swamp game rewards", "", ""}});
    hintTable[SOUTHERN_SWAMP_BOAT_ARCHERY] = HintText::Sometimes({Text{"a swamp game rewards", "", ""}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF] = HintText::Sometimes({Text{"a tourist center contains", "", ""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST] = HintText::Sometimes({Text{"a swampy cave contains", "", ""}});
    hintTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD] = HintText::Sometimes({Text{"a swamp spider man rewards", "", ""}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST] = HintText::Sometimes({Text{"a mystery cave contains", "", ""}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE] = HintText::Sometimes({Text{"a sleeping witch rewards", "", ""}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD] = HintText::Sometimes({Text{"", "", ""}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD] = HintText::Sometimes({Text{"", "", ""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE] = HintText::Sometimes({Text{"a southern merchant sells", "", ""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE_CLEAR] = HintText::Sometimes({Text{"a southern merchant sells", "", ""}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE_CLEAR] = HintText::Sometimes({Text{"a southern merchant trades", "", ""}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF_CLEAR] = HintText::Sometimes({Text{"a tourist center contains", "", ""}});
    hintTable[POTION_SHOP_ITEM_1] = HintText::Sometimes({Text{"a potion maker sells", "", ""}});
    hintTable[POTION_SHOP_ITEM_2] = HintText::Sometimes({Text{"a potion maker sells", "", ""}});
    hintTable[POTION_SHOP_ITEM_3] = HintText::Sometimes({Text{"a potion maker sells", "", ""}});
//Stock Pot Inn
    hintTable[STOCKPOTINN_RESERVATION] = HintText::Sometimes({Text{"checking-in rewards", "", ""}});
    hintTable[STOCKPOTINN_MIDNIGHT_MEETING] = HintText::Sometimes({Text{"a late meeting rewards", "", ""}});
    hintTable[STOCKPOTINN_TOILET_HAND] = HintText::Sometimes({Text{"a strange palm rewards", "", ""}});
    hintTable[STOCKPOTINN_GRANDMA_SHORT_STORY] = HintText::Sometimes({Text{"an old lady rewards", "", ""}});
    hintTable[STOCKPOTINN_GRANDMA_LONG_STORY] = HintText::Sometimes({Text{"an old lady rewards", "", ""}});
    hintTable[STOCKPOTINN_ANJU_AND_KAFEI] = HintText::Sometimes({Text{"a lovers' reunion rewards", "", ""}});
    hintTable[STOCKPOTINN_STAFF_ROOM_CHEST] = HintText::Sometimes({Text{"an employee room contains", "", ""}});
    hintTable[STOCKPOTINN_GUEST_ROOM_CHEST] = HintText::Sometimes({Text{"a guest bedroom contains", "", ""}});
//Stone Tower
    hintTable[STONE_TOWER_INVERTED_RIGHT_CHEST] = HintText::Sometimes({Text{"a sky below contains", "", ""}});
    hintTable[STONE_TOWER_INVERTED_CENTER_CHEST] = HintText::Sometimes({Text{"a sky below contains", "", ""}});
    hintTable[STONE_TOWER_INVERTED_LEFT_CHEST] = HintText::Sometimes({Text{"a sky below contains", "", ""}});
//Termina Field
    hintTable[TERMINA_FIELD_MOONS_TEAR] = HintText::Sometimes({Text{"a falling star contains", "", ""}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES] = HintText::Sometimes({Text{"mysterious stones reward", "", ""}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB] = HintText::Sometimes({Text{"a hidden merchant sells", "", ""}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST] = HintText::Sometimes({Text{"a hollow ground contains", "", ""}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST] = HintText::Sometimes({Text{"a hollow ground contains", "", ""}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE] = HintText::Sometimes({Text{"a beehive contains", "", ""}});
    hintTable[TERMINA_FIELD_KAMARO] = HintText::Sometimes({Text{"a dancer rewards", "", ""}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST] = HintText::Sometimes({Text{"a hollow pillar contains", "", ""}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO_CHEST] = HintText::Sometimes({Text{"a grassy cave contains", "", ""}});
    hintTable[TERMINA_FIELD_UNDERWATER_CHEST] = HintText::Sometimes({Text{"a sunken chest contains", "", ""}});
    hintTable[TERMINA_FIELD_GRASS_CHEST] = HintText::Sometimes({Text{"a grassy chest contains", "", ""}});
    hintTable[TERMINA_FIELD_STUMP_CHEST] = HintText::Sometimes({Text{"a tree chest contains", "", ""}});
    hintTable[TERMINA_FIELD_GROTTO_COW1] = HintText::Sometimes({Text{"a lost creature gives", "", ""}});
    hintTable[TERMINA_FIELD_GROTTO_COW2] = HintText::Sometimes({Text{"a lost creature gibes", "", ""}});
//Twin Islands
    hintTable[HOT_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({Text{"a steamy grotto contains", "", ""}});
    hintTable[TWIN_ISLANDS_GORON_RACE] = HintText::Sometimes({Text{"a sporting event rewards", "", ""}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST] = HintText::Sometimes({Text{"a hidden cave contains", "", ""}});
    hintTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST] = HintText::Sometimes({Text{"a spring treasure contains", "", ""}});
    hintTable[TWIN_ISLANDS_CAVE_CHEST] = HintText::Sometimes({Text{"a sunken springtime treasure contains", "", ""}});
    hintTable[TWIN_ISLANDS_LULLABY_INTRO] = HintText::Sometimes({Text{"a goron elder teaches", "", ""}});
    hintTable[TINGLE_TWIN_ISLANDS_SH] = HintText::Sometimes({Text{"a map maker sells ", "", ""}});
    hintTable[TINGLE_TWIN_ISLANDS_RR] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_TWIN_ISLANDS_SH_SPRING] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
    hintTable[TINGLE_TWIN_ISLANDS_RR_SPRING] = HintText::Sometimes({Text{"a map maker sells", "", ""}});
//W Clock Town
    hintTable[W_CLOCK_TOWN_BOMB_BAG_BUY] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[W_CLOCK_TOWN_POSTMANS_GAME] = HintText::Sometimes({Text{"a delivery person rewards", "", ""}});
    hintTable[W_CLOCK_TOWN_ROSA_SISTERS] = HintText::Sometimes({Text{"traveling sisters reward", "", ""}});
    hintTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Sometimes({Text{"a town game rewards", "", ""}});
    hintTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY] = HintText::Sometimes({Text{"a shady town merchant sells", "", ""}});
    hintTable[W_CLOCK_TOWN_BOMB_SHOP_GORON] = HintText::Sometimes({Text{"a town goron merchant sells", "", ""}});
  //hintTable[W_CLOCK_TOWN_LOTTERY] = HintText::Sometimes({Text{"", "", ""}});
    hintTable[TRADING_POST_ITEM_1] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_2] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_3] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_4] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_5] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_6] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_7] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[TRADING_POST_ITEM_8] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[BOMB_SHOP_ITEM_1] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
    hintTable[BOMB_SHOP_ITEM_2] = HintText::Sometimes({Text{"a town merchant sells", "", ""}});
  //hintTable[BOMB_SHOP_ITEM_3] = HintText::Sometimes({Text{"a town merchant", "", ""}});
//Woodfall
    hintTable[WOODFALL_BRIDGE_CHEST] = HintText::Sometimes({Text{"a swamp chest contains", "", ""}});
    hintTable[WOODFALL_BEHIND_OWL_CHEST] = HintText::Sometimes({Text{"a swamp chest contains", "", ""}});
    hintTable[ENTRANCE_TO_WOODFALL_CHEST] = HintText::Sometimes({Text{"a swamp chest contains", "", ""}});
    hintTable[WOODFALL_GREAT_FAIRY] = HintText::Sometimes({Text{"the fairy of wisdom rewards", "", ""}});
//Zora Cape
    hintTable[ZORA_CAPE_GREAT_FAIRY] = HintText::Sometimes({Text{"the fairy of courage rewards", "", ""}});
    hintTable[ZORA_CAPE_BEAVER_RACE_1] = HintText::Sometimes({Text{"a river dweller rewards", "", ""}});
    hintTable[ZORA_CAPE_BEAVER_RACE_2] = HintText::Sometimes({Text{"a river dweller rewards", "", ""}});
    hintTable[ZORA_CAPE_LIKE_LIKE] = HintText::Sometimes({Text{"a shield eater contains", "", ""}});
    hintTable[ZORA_CAPE_LEDGE_NO_TREE] = HintText::Sometimes({Text{"a high place contains", "", ""}});
    hintTable[ZORA_CAPE_LEDGE_WITH_TREE] = HintText::Sometimes({Text{"a high place contains", "", ""}});
    hintTable[ZORA_CAPE_GROTTO_CHEST] = HintText::Sometimes({Text{"a beach cave contains", "", ""}});
    hintTable[ZORA_CAPE_UNDERWATER_CHEST] = HintText::Sometimes({Text{"a sunken chest contains ", "", ""}});
//Zora Hall
    hintTable[ZORA_HALL_SCRUB_TRADE] = HintText::Sometimes({Text{"a western merchant trades", "", ""}});
    hintTable[ZORA_HALL_EVAN] = HintText::Sometimes({Text{"a musician rewards", "", ""}});
    hintTable[ZORA_HALL_LULU_ROOM_LEDGE] = HintText::Sometimes({Text{"the singer's room contains", "", ""}});
    hintTable[ZORA_HALL_SCRUB_PURCHASE] = HintText::Sometimes({Text{"a western merchant sells", "", ""}});
  //hintTable[ZORA_HALL_STAGE_LIGHTS] = HintText::Sometimes({Text{"a fan", "", ""}});
  //hintTable[ZORA_HALL_BAD_PHOTO_LULU] = HintText::Sometimes({Text{"a fan", "", ""}});
  //hintTable[ZORA_HALL_GOOD_PHOTO_LULU] = HintText::Sometimes({Text{"a fan", "", ""}});
    hintTable[ZORA_SHOP_ITEM_1] = HintText::Sometimes({Text{"a zora merchant sells", "", ""}});
    hintTable[ZORA_SHOP_ITEM_2] = HintText::Sometimes({Text{"a zora merchant sells", "", ""}});
    hintTable[ZORA_SHOP_ITEM_3] = HintText::Sometimes({Text{"a zora merchant sells", "", ""}});
  
  /*-------------------------
  |  DUNGEON LOCATION TEXT  |
  -------------------------*/

    hintTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST] = HintText::Exclude({Text{"the sleeping temple contains", "", ""}});
    hintTable[WOODFALL_TEMPLE_MAP_CHEST] = HintText::Exclude({Text{"the sleeping temple contains", "", ""}});
    hintTable[WOODFALL_TEMPLE_COMPASS_CHEST] = HintText::Exclude({Text{"the sleeping temple contains", "", ""}});
    hintTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({Text{"the sleeping temple contains", "", ""}});
    hintTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST] = HintText::Exclude({Text{"the sleeping temple contains", "", ""}});
    hintTable[WOODFALL_TEMPLE_DEKU_PRINCESS] = HintText::Exclude({Text{"the sleeping temple rewards", "", ""}});
    hintTable[WF_SF_ENTRANCE_FAIRY] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_ENTRANCE_PLATFORM] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_MAIN_ROOM_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_MAIN_ROOM_SWITCH] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_DEKU_BABA] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_DRAGONFLY_ROOM_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_SKULLTULA] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_DARK_ROOM] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_JAR_FAIRY] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_BRIDGE_ROOM_BEEHIVE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[WF_SF_PLATFORM_ROOM_BEEHIVE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ODOLWA_HEART_CONTAINER] = HintText::Exclude({Text{"a masked evil contains", "", ""}});	
//Snowhead Temple
    hintTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_MAP_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_COMPASS_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST] = HintText::Exclude({Text{"an icy temple contains", "", ""}});
    hintTable[SH_SF_SNOW_ROOM_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_CEILING_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_DINOLFOS_1] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_DINOLFOS_2] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_MAP_ROOM_FAIRY] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_MAP_ROOM_LEDGE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_BASEMENT] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_TWIN_BLOCK] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_ICICLE_ROOM_WALL] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_MAIN_ROOM_WALL] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_PILLAR_FREEZARDS] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_ICE_PUZZLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[SH_SF_CRATE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GOHT_HEART_CONTAINER] = HintText::Exclude({Text{"a masked evil contains", "", ""}});
//Great bay Temple
    hintTable[GBT_ICE_ARROW_CHEST] = HintText::Exclude({Text{"the murky watered temple contains", "", ""}});
    hintTable[GBT_MAP_CHEST] = HintText::Exclude({Text{"the murky watered temple contains", "", ""}});
    hintTable[GBT_COMPASS_CHEST] = HintText::Exclude({Text{"the murky watered temple contains", "", ""}});
    hintTable[GBT_BOSS_KEY_CHEST] = HintText::Exclude({Text{"the murky watered temple contains", "", ""}});
    hintTable[GBT_SMALL_KEY_CHEST] = HintText::Exclude({Text{"the murky watered temple contains", "", ""}});
    hintTable[GBT_SF_SKULLTULA] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_LOWER] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_UPPER] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_GREEN_VALVE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_SEESAW_ROOM] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_ENTRANCE_TORCHES] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_BIO_BABAS] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_UNDERWATER_BARREL] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_WHIRLPOOL_BARREL] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_WHIRLPOOL_JAR] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_DEXIHANDS_JAR] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_LEDGE_JAR] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[GYORG_HEART_CONTAINER] = HintText::Exclude({Text{"a masked evil contains", "", ""}});
//Stone Tower Temple
    hintTable[STONE_TOWER_TEMPLE_MAP_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_COMPASS_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST] = HintText::Exclude({Text{"a rocky temple contains", "", ""}});
    hintTable[ST_SF_MIRROR_SUN_BLOCK] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_LAVA_ROOM_LEDGE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_LAVA_ROOM_FIRE_RING] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_EYEGORE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_UPDRAFT_FIRE_RING] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_MIRROR_SUN_SWITCH] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_BOSS_WARP] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_WIZZROBE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_DEATH_ARMOS] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_UPDRAFT_FROZEN_EYE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_THIN_BRIDGE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_BASEMENT_LEDGE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_STATUE_EYE] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_UNDERWATER] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[ST_SF_BRIDGE_CRYSTAL] = HintText::Exclude({Text{"a lost fairy is", "", ""}});
    hintTable[TWINMOLD_HEART_CONTAINER] = HintText::Exclude({Text{"a masked evil contains", "", ""}});
//Pirate Fortress
    hintTable[PF_INTERIOR_HOOKSHOT_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_LOWER_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_UPPER_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_TANK_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_GUARD_ROOM_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_CAGE_ROOM_SHALLOW_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_CAGE_ROOM_DEEP_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_MAZE_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_SEWER_CAGE] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_EXTERIOR_LOG_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_EXTERIOR_SAND_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_EXTERIOR_CORNER_CHEST] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_INVISIBLE_SOLDIER] = HintText::Exclude({Text{"the home of pirates contains", "", ""}});
    hintTable[PF_INT_HOOKSHOT_ROOM_ZORA_EGG] = HintText::Exclude({Text{"in the home of pirates rests", "", ""}});
    hintTable[PF_INT_GUARD_ROOM_ZORA_EGG] = HintText::Exclude({Text{"in the home of pirates rests", "", ""}});
    hintTable[PF_INT_BARREL_MAZE_ZORA_EGG] = HintText::Exclude({Text{"in the home of pirates rests", "", ""}});
    hintTable[PF_INT_LAVA_ROOM_ZORA_EGG] = HintText::Exclude({Text{"in the home of pirates rests", "", ""}});
//Beneath the Well
    hintTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST] = HintText::Exclude({Text{"a frightful exchange contains", "", ""}});
    hintTable[WELL_LEFT_PATH_CHEST] = HintText::Exclude({Text{"a frightful exchange contains", "", ""}});
    hintTable[WELL_RIGHT_PATH_CHEST] = HintText::Exclude({Text{"a frightful exchange contains", "", ""}});  
    hintTable[BENEATH_THE_WELL_COW] = HintText::Exclude({Text{"a lost creature contains", "", ""}});
//Ikana Castle
    hintTable[IKANA_CASTLE_PILLAR] = HintText::Exclude({Text{"a fiery pilar contains", "", ""}});
    hintTable[IKANA_CASTLE_IKANA_KING] = HintText::Exclude({Text{"a fallen king teaches", "", ""}});
//Secret Shrine 
    hintTable[SECRET_SHRINE_DINOLFOS_CHEST] = HintText::Exclude({Text{"a secret place contains", "", ""}});
    hintTable[SECRET_SHRINE_WIZZROBE_CHEST] = HintText::Exclude({Text{"a secret place contains", "", ""}});
    hintTable[SECRET_SHRINE_WART_CHEST] = HintText::Exclude({Text{"a secret place contains", "", ""}});
    hintTable[SECRET_SHRINE_GARO_CHEST] = HintText::Exclude({Text{"a secret place contains", "", ""}});
    hintTable[SECRET_SHRINE_FINAL_CHEST] = HintText::Exclude({Text{"a secret place contains", "", ""}});
//The Moon
    hintTable[THE_MOON_DEKU_TRIAL_BONUS] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_GORON_TRIAL_BONUS] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_ZORA_TRIAL_BONUS] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_LINK_TRIAL_BONUS] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_GARO_CHEST] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_IRON_KNUCKLE_CHEST] = HintText::Exclude({Text{"a masked child's game contains", "", ""}});
    hintTable[THE_MOON_MAJORA_CHILD] = HintText::Exclude({Text{"the lonely child rewards", "", ""}});
//Southern Swamp Skulltula House
    hintTable[SSH_MAIN_ROOM_NEAR_CEILING] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_WATER] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_UPPER_SOIL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_PILLAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_UPPER_PILLAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MAIN_ROOM_JAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MONUMENT_ROOM_TORCH] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MONUMENT_ROOM_ON_MONUMENT] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_MONUMENT_ROOM_LOWER_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_GOLD_ROOM_NEAR_CEILING] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_GOLD_ROOM_PILLAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_GOLD_ROOM_BEEHIVE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_GOLD_ROOM_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_JAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_POT_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_POT_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_BEHIND_VINES] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_BEEHIVE_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_POT_ROOM_BEEHIVE_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_TREE_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_TREE_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_TREE_3] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_GRASS_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_GRASS_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[SSH_TREE_ROOM_BEEHIVE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
//Oceanside spider House
    hintTable[OSH_ENTRANCE_LEFT_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_ENTRANCE_RIGHT_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_ENTRANCE_WEB] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_CABINET] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_CEILING_EDGE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_LIBRARY_BEHIND_PICTURE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_CEILING_EDGE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_CEILING_PLANK] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_JAR] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_WEBBED_HOLE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_WEBBED_POT] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_UPPER_POT] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_SECOND_ROOM_LOWER_POT] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_STORAGE_ROOM_CEILING_WEB] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_STORAGE_ROOM_BEHIND_CRATE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_STORAGE_ROOM_WALL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_STORAGE_ROOM_CRATE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_STORAGE_ROOM_BARREL] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_CEILING_EDGE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_1] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_2] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_3] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_BEHIND_PICTURE] = HintText::Exclude({Text{"a gold spider is", "", ""}});
    hintTable[OSH_COLORED_SKULLS_POT] = HintText::Exclude({Text{"a gold spider is", "", ""}});


  /*----------------------
  |   REGTION HINT TEXT  |
  ----------------------*/
    hintTable[N_CLOCK_TOWN] = HintText::Region({ Text{"N Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = HintText::Region({Text{"Clock Town Fairy Fountain", "", ""}});
    hintTable[CLOCK_TOWN_DEKU_PLAYGROUND] = HintText::Region({Text{"Deku Playground", "", ""}});
    hintTable[E_CLOCK_TOWN] = HintText::Region({Text{"E Clock Town", "", ""}});
    hintTable[STOCKPOTINN] = HintText::Region({Text{"Stock Pot Inn", "", ""}});
    hintTable[STOCKPOTINN_GUEST_ROOM] = HintText::Region({Text{"Stock Pot Inn", "", ""}});
    hintTable[STOCKPOTINN_STAFF_ROOM] = HintText::Region({Text{"Stock Pot Inn", "", ""}});
    hintTable[STOCKPOTINN_GRANDMA_ROOM] = HintText::Region({Text{"Stock Pot Inn", "", ""}});
    hintTable[CLOCK_TOWN_OBSERVATORY] = HintText::Region({Text{"Observatory", "", ""}});
    hintTable[CLOCK_TOWN_BAR] = HintText::Region({Text{"Milk Bar", "", ""}});
    hintTable[CLOCK_TOWN_HONEY_DARLING] = HintText::Region({Text{"E Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = HintText::Region({Text{"E Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_ARCHERY] = HintText::Region({Text{"E Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_MAYOR_HOUSE] = HintText::Region({Text{"E Clock Town", "", ""}});
    hintTable[W_CLOCK_TOWN] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_POSTMAN_HOUSE] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_LOTTERY] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_BOMB_SHOP] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_TRADING_POST] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[CLOCK_TOWN_CURIOSITY_SHOP] = HintText::Region({Text{"W Clock Town", "", ""}});
    hintTable[S_CLOCK_TOWN] = HintText::Region({Text{"S Clock Town", "", ""}});
    hintTable[CLOCK_TOWER] = HintText::Region({Text{"Clock Tower", "", ""}});
    hintTable[CLOCK_TOWER_ROOF] = HintText::Region({Text{"Clock Tower Roof", "", ""}});
    hintTable[LAUNDRY_POOL] = HintText::Region({Text{"Laundry Pool", "", ""}});
    hintTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = HintText::Region({Text{"Laundry Pool", "", ""}});
    hintTable[TERMINA_FIELD] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_OUTSIDE_OBSERVATORY] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_COW_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = HintText::Region({Text{"Termina Field", "", ""}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP] = HintText::Region({Text{"Road to Southern Swamp", "", ""}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = HintText::Region({Text{"Road to Southern Swamp", "", ""}});
    hintTable[ROAD_TO_SWAMP_GROTTO] = HintText::Region({Text{"Road to Southern Swamp", "", ""}});
    hintTable[SOUTHERN_SWAMP] = HintText::Region({Text{"Southern Swamp", "", ""}});
    hintTable[SWAMP_TOURIST_CENTER] = HintText::Region({Text{"Southern Swamp", "", ""}});
    hintTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = HintText::Region({Text{"Southern Swamp", "", ""}});
    hintTable[MYSTERY_WOODS] = HintText::Region({Text{"Mystery Woods", "", ""}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = HintText::Region({Text{"Mystery Woods", "", ""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = HintText::Region({Text{"Southern Swamp", "", ""}});
    hintTable[SOUTHERN_SWAMP_TOP] = HintText::Region({Text{"Southern Swamp", "", ""}});
    hintTable[DEKU_PALACE] = HintText::Region({Text{"Deku Palace", "", ""}});
    hintTable[DEKU_PALACE_INTERIOR] = HintText::Region({Text{"Deku Palace", "", ""}});
    hintTable[DEKU_PALACE_BEAN_GROTTO] = HintText::Region({Text{"Deku Palace", "", ""}});
    hintTable[DEKU_SHRINE] = HintText::Region({Text{"Deku Palace", "", ""}});
    hintTable[WOODFALL] = HintText::Region({Text{"Woodfall", "", ""}});
    hintTable[WOODFALL_FAIRY_FOUNTAIN] = HintText::Region({Text{"Woodfall Fairy Foutain", "", ""}});
    hintTable[PATH_TO_MOUNTAIN_VILLAGE] = HintText::Region({Text{"Path to Mountain Vilage", "", ""}});
    hintTable[MOUNTAIN_VILLAGE] = HintText::Region({Text{"Mountain Village", "", ""}});
    hintTable[GORON_GRAVEYARD] = HintText::Region({Text{"Goron Graveyard", "", ""}});
    hintTable[MOUNTAIN_SMITHY] = HintText::Region({Text{"Mountain Village", "", ""}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = HintText::Region({Text{"Mountain Village", "", ""}});
    hintTable[TWIN_ISLANDS] = HintText::Region({Text{"Twin Islands", "", ""}});
    hintTable[GORON_RACETRACK] = HintText::Region({Text{"Goron Racetrack", "", ""}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = HintText::Region({Text{"Twin Islands", "", ""}});
    hintTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = HintText::Region({Text{"Twin Islands", "", ""}});
    hintTable[GORON_VILLAGE] = HintText::Region({Text{"Goron Village", "", ""}});
    hintTable[GORON_VILLAGE_LENS_CAVE] = HintText::Region({Text{"Goron Village", "", ""}});
    hintTable[GORON_VILLAGE_INTERIOR] = HintText::Region({Text{"Goron Village", "", ""}});
    hintTable[GORON_VILLAGE_SHOP] = HintText::Region({Text{"Goron Village", "", ""}});
    hintTable[ROAD_TO_SNOWHEAD] = HintText::Region({Text{"Road to Snowhead", "", ""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO] = HintText::Region({Text{"Road to Snowhead", "", ""}});
    hintTable[SNOWHEAD] = HintText::Region({Text{"Snowhead", "", ""}});
    hintTable[SNOWHEAD_FAIRY_FOUNTAIN] = HintText::Region({Text{"Snowhead Fairy Fountain", "", ""}});
    hintTable[MILK_ROAD] = HintText::Region({Text{"Milk Road", "", ""}});
    hintTable[GORMAN_TRACK] = HintText::Region({Text{"Gorman Track", "", ""}});
    hintTable[ROMANI_RANCH] = HintText::Region({Text{"Romani Ranch", "", ""}});
    hintTable[DOGGY_RACETRACK] = HintText::Region({Text{"Romani Ranch", "", ""}});
    hintTable[CUCCO_SHACK] = HintText::Region({Text{"Romani Ranch", "", ""}});
    hintTable[ROMANI_RANCH_HOUSE] = HintText::Region({Text{"Romani Ranch", "", ""}});
    hintTable[ROMANI_RANCH_BARN] = HintText::Region({Text{"Romani Ranch", "", ""}});
    hintTable[GREAT_BAY_COAST] = HintText::Region({Text{"Great Bay Coast", "", ""}});
    hintTable[GREAT_BAY_COAST_MARINE_LAB] = HintText::Region({Text{"Great Bay Coast", "", ""}});
    hintTable[GREAT_BAY_COAST_GROTTO] = HintText::Region({Text{"Great Bay Coast", "", ""}});
    hintTable[GREAT_BAY_COAST_COW_GROTTO] = HintText::Region({Text{"Great Bay Coast", "", ""}});
    hintTable[FISHERMAN_HUT] = HintText::Region({Text{"Great Bay Coast", "", ""}});
    hintTable[PINNACLE_ROCK] = HintText::Region({Text{"Pinnacle Rock", "", ""}});
    hintTable[ZORA_CAPE] = HintText::Region({Text{"Zora Cape", "", ""}});
    hintTable[WATERFALL_RAPIDS] = HintText::Region({Text{"Zora Cape", "", ""}});
    hintTable[GREAT_BAY_FAIRY_FOUNTAIN] = HintText::Region({Text{"Zora Cape Fairy Fountain", "", ""}});
    hintTable[ZORA_CAPE_GROTTO] = HintText::Region({Text{"Zora Cape", "", ""}});
    hintTable[ZORA_HALL] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_EVANS_ROOM] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_LULUS_ROOM] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_JAPAS_ROOM] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_TIJOS_ROOM] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_SHOP] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ZORA_HALL_BACK_ENTRANCE] = HintText::Region({Text{"Zora Hall", "", ""}});
    hintTable[ROAD_TO_IKANA] = HintText::Region({Text{"Road to Ikana", "", ""}});
    hintTable[ROAD_TO_IKANA_GROTTO] = HintText::Region({Text{"Road to Ikana", "", ""}});
    hintTable[IKANA_GRAVEYARD] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_GROTTO] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_BATS_ROOM] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_TABLET_ROOM] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[DAMPES_HUT] = HintText::Region({Text{"Ikana Graveyard", "", ""}});
    hintTable[IKANA_CANYON] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[IKANA_CANYON_UPPER] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[IKANA_CANYON_CAVE] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[SAKONS_HIDEOUT] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[MUSIC_BOX_HOUSE] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[IKANA_CANYON_POE_HUT] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = HintText::Region({Text{"Ikana Canyon Fairy Foutain", "", ""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = HintText::Region({Text{"Ikana Canyon", "", ""}});
    hintTable[STONE_TOWER] = HintText::Region({Text{"Stone Tower", "", ""}});
    hintTable[INVERTED_STONE_TOWER] = HintText::Region({Text{"Stone Tower", "", ""}});

  /*---------------------
  |   JUNK HINT TEXT    |
  ---------------------*/
    hintTable[JUNK01] = HintText::Junk({Text{"That's no moon.", "", ""}});
    hintTable[JUNK02] = HintText::Junk({Text{"The moon is haunted.", "", ""}});
    hintTable[JUNK03] = HintText::Junk({Text{"Majora has sick dance moves.", "", ""}});
    hintTable[JUNK04] = HintText::Junk({Text{"Making hints is hard.", "", ""}});
    hintTable[JUNK05] = HintText::Junk({Text{"May the way of the Hero lead to the Triforce.", "", ""}});
    hintTable[JUNK06] = HintText::Junk({Text{"They say that the final item you're looking for can be found somewhere in Termina.", "", ""}});
    hintTable[JUNK07] = HintText::Junk({Text{"They say that 85 percent of statistics are made up", "", ""}});
    hintTable[JUNK08] = HintText::Junk({Text{"They say the golden dog is picked as the winner most often", "", ""}});
    hintTable[JUNK09] = HintText::Junk({Text{"Be patient young grasshopper", "", ""}});
    hintTable[JUNK10] = HintText::Junk({Text{"The Ikana King used to be quite handsome", "", ""}});
    hintTable[JUNK11] = HintText::Junk({Text{"If the Goron Elder is frozen how does he move each day", "", ""}});
    hintTable[JUNK12] = HintText::Junk({Text{"The Owl's feathers lead the way", "", ""}});
    hintTable[JUNK13] = HintText::Junk({Text{"The Happy Mask Salesman doesn't sleep", "", ""}});
    hintTable[JUNK14] = HintText::Junk({Text{"why do they call it oven when you of in the cold food of out hot eat the food", "", ""}});
    hintTable[JUNK15] = HintText::Junk({Text{"It seems Link has difficulties remembering music without the help of a fairy.", "", ""}});
    hintTable[JUNK16] = HintText::Junk({Text{"Pickle.", "", ""}});
    hintTable[JUNK17] = HintText::Junk({Text{"Why is it called The Legend of Zelda Majora's Mask when Zelda isn't here?", "", ""}});
    hintTable[JUNK18] = HintText::Junk({Text{"They say you can find the Star Fox cast in your mask inventory screen.", "", ""}});
    hintTable[JUNK19] = HintText::Junk({Text{"They say #L# is Real 2401.", "", ""}});
    hintTable[JUNK20] = HintText::Junk({Text{"They say #The Moon# blinks if you stare long enough", "", ""}});
    hintTable[JUNK21] = HintText::Junk({Text{"They say bunnies have a really good sense of time.", "", ""}});
    hintTable[JUNK22] = HintText::Junk({Text{"They say this game has a method of infinitely jumping.", "", ""}});
    hintTable[JUNK23] = HintText::Junk({Text{"According to all known laws of aviation there is no way a Zora should be able to fly.", "", ""}});
    hintTable[JUNK24] = HintText::Junk({Text{"Why is Zelda green?", "", ""}});
    hintTable[JUNK25] = HintText::Junk({Text{"Did you know for the first time in 23 years, in 2023 Waluigi didn't star in a game?", "", ""}});
    hintTable[JUNK26] = HintText::Junk({Text{"Here's a hint, @. Don't be bad.", "", ""}});
    hintTable[JUNK27] = HintText::Junk({Text{"They say this randomizer actually took longer to develop than the original Majora's Mask.", "", ""}});
    hintTable[JUNK28] = HintText::Junk({Text{"They say pirates are allergic to #bees#.", "", ""}});
    hintTable[JUNK29] = HintText::Junk({Text{"Ocean man, take me by the hand.", "", ""}});
    hintTable[JUNK30] = HintText::Junk({Text{"Special shoutouts to ennopp who plays piano during this cutscene", "", ""}});
    hintTable[JUNK31] = HintText::Junk({Text{"Did you know it's actually surprisingly easy to mod a 3DS?", "", ""}});
    hintTable[JUNK32] = HintText::Junk({Text{"Zora eggs are quite delicious.", "", ""}});
    hintTable[JUNK33] = HintText::Junk({Text{"Zabora and Gabora have gotten better at making swords that stay sharp.", "", ""}});
    hintTable[JUNK34] = HintText::Junk({Text{"They say Tacoman369 has never defeated Majora.", "", ""}});
    hintTable[JUNK35] = HintText::Junk({Text{"L2P @.", "", ""}});
    hintTable[JUNK36] = HintText::Junk({Text{"They say the #Majora's Mask 3D Randomizer# developers are cool people.", "", ""}});
    hintTable[JUNK37] = HintText::Junk({Text{"Also try #Ocarina of Time 3D Randomizer#!", "", ""}});
    hintTable[JUNK38] = HintText::Junk({Text{"The single rupee is a unique item.", "", ""}});
    hintTable[JUNK39] = HintText::Junk({Text{"Hey, listen!", "", ""}});
    hintTable[JUNK40] = HintText::Junk({Text{"They say even the Hero of Time can't help everyone.", "", ""}});
    hintTable[JUNK41] = HintText::Junk({Text{"The dirt around here tastes really good.", "", ""}});
    hintTable[JUNK42] = HintText::Junk({Text{"Talk to me again for the best hint.", "", ""}});
    hintTable[JUNK43] = HintText::Junk({Text{"They say Gorons discovered a method of space travel.", "", ""}});
    hintTable[JUNK44] = HintText::Junk({Text{"I AM ERROR", "", ""}});
    hintTable[JUNK45] = HintText::Junk({Text{"Real 3DS ZELDA players use motion controls.", "", ""}});
    hintTable[JUNK46] = HintText::Junk({Text{"Real ZELDA players use HOLD targeting.", "", ""}});
    hintTable[JUNK47] = HintText::Junk({Text{"They say items are random...", "", ""}});
    hintTable[JUNK48] = HintText::Junk({Text{"Dear Mario, please come to the castle. I've baked a cake for you. Yours truly, Princess Toadstool, Peach", "", ""}});
    hintTable[JUNK49] = HintText::Junk({Text{"They say the key to victory is beating the game...", "", ""}});
    hintTable[JUNK50] = HintText::Junk({Text{"They say the gold dog cheats.", "", ""}});
    hintTable[JUNK51] = HintText::Junk({Text{"They say @ drowned.", "", ""}});
    hintTable[JUNK52] = HintText::Junk({Text{"Goodbye then.", "", ""}});
    hintTable[JUNK53] = HintText::Junk({Text{"You've met with a terrible hint, haven't you?", "", ""}});
    hintTable[JUNK54] = HintText::Junk({Text{"I'm stoned. Get it?", "", ""}});
    hintTable[JUNK55] = HintText::Junk({Text{"One who doesn't have all the masks will not get a #special reward#", "", ""}});
    hintTable[JUNK56] = HintText::Junk({Text{"They say the #blue dog# will win a race some day...", "", ""}});
    hintTable[JUNK57] = HintText::Junk({Text{"Remember to check your 3DS battery level and save often.", "", ""}});
    hintTable[JUNK58] = HintText::Junk({Text{"Just be a rock.", "", ""}});
    hintTable[JUNK59] = HintText::Junk({Text{"I can't feel my legs!", "", ""}});
    hintTable[JUNK60] = HintText::Junk({Text{"What are you staring at?", "", ""}});
    hintTable[JUNK61] = HintText::Junk({Text{"Glitches are a pathway to many abilities some consider to be... Unnatural.", "", ""}});
    hintTable[JUNK62] = HintText::Junk({Text{"You ever just feel like smashing that $ button?", "", ""}});
    hintTable[JUNK63] = HintText::Junk({Text{"I think the Mask of Truth has it's uses!", "", ""}});
    hintTable[JUNK64] = HintText::Junk({Text{"There's a lot of eyes here, isn't there?", "", ""}});
    hintTable[JUNK65] = HintText::Junk({Text{"I think that #large object in the sky# hasn't moved in a few days.", "", ""}});
    hintTable[JUNK66] = HintText::Junk({Text{"Watch out for that #large object in the sky!#", "", ""}});
    hintTable[JUNK67] = HintText::Junk({Text{"#Tingle Tingle Kooloo Limpah!#", "", ""}});
    hintTable[JUNK68] = HintText::Junk({Text{"They say if you have three specific items, you can zoom across Termina.", "", ""}});
    hintTable[JUNK69] = HintText::Junk({Text{"They say the powder keg can remain fairly elusive.", "", ""}});
    hintTable[JUNK70] = HintText::Junk({Text{"It's pretty cold here, would you mind warming me up, @?", "", ""}});
    hintTable[JUNK71] = HintText::Junk({Text{"These hints can be quite useful. This is an exception.", "", ""}});
    hintTable[JUNK72] = HintText::Junk({Text{"Turns are more effective when you tilt the whole console.", "", ""}});
    hintTable[JUNK73] = HintText::Junk({Text{"You ever been in a cockpit before?", "", ""}});
    hintTable[JUNK74] = HintText::Junk({Text{"It's a secret to everybody", "", ""}});
    hintTable[JUNK75] = HintText::Junk({Text{"You found me!", "", ""}});
    hintTable[JUNK76] = HintText::Junk({Text{"I have it on my post-it note somewhere.", "", ""}});
    hintTable[JUNK77] = HintText::Junk({Text{"Follow the rainbow.", "", ""}});

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