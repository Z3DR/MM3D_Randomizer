#include "hint_list.hpp"
//#include "custom_messages.hpp"

#include <array>

//using namespace CustomMessages;

static std::array<HintText, KEY_ENUM_MAX> hintTable;

void HintTable_Init() {
   /*--------------------------
    |       GENERAL TEXT       |
    ---------------------------*/

    hintTable[NONE]            = HintText::Exclude({Text{"No Hint",                     "**FRENCH**", "**SPANISH**"}});
    hintTable[PREFIX]          = HintText::Exclude({Text{"They say that ",              "Selon moi, ",                  "Según dicen, "}});
    hintTable[WAY_OF_THE_HERO] = HintText::Exclude({Text{" is on the way of the hero.", " est sur le chemin du héros.", " conduce a la senda del héroe."}});
    hintTable[PLUNDERING]      = HintText::Exclude({Text{"plundering ",                 "explorer ",                    "inspeccionar "}});
    hintTable[FOOLISH]         = HintText::Exclude({Text{" is a foolish choice.",       " est futile.",                 " no es una sabia decisión."}});
    hintTable[CAN_BE_FOUND_AT] = HintText::Exclude({Text{"can be found at",             "se trouve dans",               "aguarda en"}});
    hintTable[HOARDS]          = HintText::Exclude({Text{"hoards",                      "recèle",                       "acapara"}});


    //hintTable[ITEM] = HintText::Item({Text{"English", "French", "Spanish"}});
    /*-------------------------
	|        ITEM HINTS       |
	--------------------------*/

    hintTable[KOKIRI_SWORD] = HintText::Item({
            //obscure
            Text{"a forest blade", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Kokiri Sword", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[RAZOR_SWORD]  = HintText::Item({
            //obscure
            Text{"a sharp blade", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Razor Sword", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GILDED_SWORD] = HintText::Item({
            //obscure
            Text{"a very sharp blade", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Gilded Sword", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GREAT_FAIRYS_SWORD] = HintText::Item({
            //obscure
            Text{"A powerful fairy blade", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Fairy's Sword", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[HEROS_SHIELD] = HintText::Item({
            //obscure
            Text{"a basic shield", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Hero's Shield", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MIRROR_SHIELD] = HintText::Item({
            //obscure
            Text{"a reflective shield", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Mirror Shield", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[DEKU_STICK] = HintText::Item({
            //obscure
            Text{"a flammable weapon", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Deku Stick", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[LAND_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Land Title Deed", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SWAMP_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Swamp Title Deed", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MOUNTAIN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Mountain Title Deed", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[OCEAN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Ocean Title Deed", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOMBERS_NOTEBOOK] = HintText::Item({
            //obscure
            Text{"a handy notepad", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Bombers' Notebook", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ROOM_KEY] = HintText::Item({
            //obscure
            Text{"a hotel door opener", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Room Key", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[LETTER_KAFEI] = HintText::Item({
            //obscure
            Text{"a lover's letter", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Letter to Kafei", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PENDANT_MEMORIES] = HintText::Item({
            //obscure
            Text{"a cherished necklace", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Pendant of Memories", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[LETTER_MAMA] = HintText::Item({
            //obscure
            Text{"A special delivery", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Letter to Mama", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MOONS_TEAR] = HintText::Item({
            //obscure
            Text{"a lunar teardrop", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Moon's Tear", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SPIN_ATTACK] = HintText::Item({
            //obscure
            Text{"a magic attack", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the mastered Spin Attack", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[LENS_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a lie detector", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Lens of Truth", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[HEROS_BOW] = HintText::Item({
            //obscure
            Text{"a bow", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Hero's Bow", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[FIRE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of fire", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Fire Arrow", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ICE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of ice", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Ice Arrow", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[LIGHT_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of light", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Light Arrow", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[HOOKSHOT] = HintText::Item({
            //obscure
            Text{"a chain and grapple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Hookshot", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MAGIC_BEAN] = HintText::Item({
            //obscure
            Text{"a plant seed", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Magic Bean", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MAGIC_BEAN_PACK] = HintText::Item({
            //obscure
            Text{"multiple plant seeds", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a pack of Magic Beans", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[DOUBLE_DEFENSE] = HintText::Item({
            //obscure
            Text{"magical defence", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Double Defense", "**FRENCH**", "**SPANISH**"}
    );
        hintTable[OCARINA_OF_TIME] = HintText::Item({
            //obscure
            Text{"a musical instrument", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Ocarina of Time", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PICTOGRAPH_BOX] = HintText::Item({
            //obscure
            Text{"a capture device", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Picto Box", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[POWDER_KEG] = HintText::Item({
            //obscure
            Text{"an explosive barrel", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Powder Keg", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[KEATON_MASK] = HintText::Item({
            //obscure
            Text{"a popular mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Keaton Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BUNNY_HOOD] = HintText::Item({
            //obscure
            Text{"the ears of the wild", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Bunny Hood", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GORON_MASK] = HintText::Item({
            //obscure
            Text{"a mountain spirit", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Goron Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ZORA_MASK] = HintText::Item({
            //obscure
            Text{"an ocean spirit", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Zora Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[DEKU_MASK] = HintText::Item({
            //obscure
            Text{"a forest spirit", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Deku Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[POSTMANS_HAT] = HintText::Item({
            //obscure
            Text{"a hard worker's hat", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Postman's Hat", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ALL_NIGHT_MASK] = HintText::Item({
            //obscure
            Text{"insomnia", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the All-Night Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BLAST_MASK] = HintText::Item({
            //obscure
            Text{"a dangerous mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Blast Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[STONE_MASK] = HintText::Item({
            //obscure
            Text{"inconspicousness", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GREAT_FAIRYS_MASK] = HintText::Item({
            //obscure
            Text{"a friend of fairies", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Fairy's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BREMEN_MASK] = HintText::Item({
            //obscure
            Text{"a bird's mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Bremen Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[DON_GEROS_MASK] = HintText::Item({
            //obscure
            Text{"a conductor's mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Don Gero's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MASK_OF_SCENTS] = HintText::Item({
            //obscure
            Text{"a pig's mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Mask of Scents", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ROMANIS_MASK] = HintText::Item({
            //obscure
            Text{"a cow's mask", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Romani's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[CIRCUS_LEADERS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of sadness", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Troupe Leader's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[KAFEIS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of a missing one", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Kafei's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[COUPLES_MASK] = HintText::Item({
            //obscure
            Text{"the mark of a couple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Couple's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[KAMAROS_MASK] = HintText::Item({
            //obscure
            Text{"dance moves", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Kamaro's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GIBDOS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of monsters", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Gibdo Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GAROS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of spies", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Garo's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[CAPTAINS_HAT] = HintText::Item({
            //obscure
            Text{"a commanding presence", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Captain's Hat", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GIANTS_MASK] = HintText::Item({
            //obscure
            Text{"a growth spur", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Giant's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[FIERCE_DEITY_MASK] = HintText::Item({
            //obscure
            Text{"the wrath of a god", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Fierce Deity's Mask", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[MASK_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a piercing gaze", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Mask of Truth", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[FISHING_PASS] = HintText::Item({
            //obscure
            Text{"a fishing pass", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Fishing Pass", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ICE_TRAP] = HintText::Item({
            //obscure
            Text{"a frosty surprise", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Ice Trap", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a zora egg", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Zora Egg", "**FRENCH**", "**SPANISH**"}
    );
    //SKULLTULA TOKENS
	hintTable[SWAMP_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Swamp Skulltula Token", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[OCEANSIDE_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Oceanside Skulltula Token", "**FRENCH**", "**SPANISH**"}
    );
	
	//Stray Fairies
	hintTable[CT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Clock Town Stray Fairy", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[WF_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Woodfall Stray Fairy", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SH_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Snowhead Stray Fairy", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GBT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Great Bay Stray Fairy", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ST_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Stone Tower Stray Fairy", "**FRENCH**", "**SPANISH**"}
    );
	//PROGRESSIVE ITEMS (unused currently)
	hintTable[PROGRESSIVE_SWORD] = HintText::Item({
            //obscure
            Text{"a progressive sword", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a progressive sword", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PROGRESSIVE_BOMB_BAG] = HintText::Item({
            //obscure
            Text{"a progressive bomb bag", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a progressive bomb bag", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PROGRESSIVE_BOW] = HintText::Item({
            //obscure
            Text{"a progressive bow", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a progressive quiver", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PROGRESSIVE_WALLET] = HintText::Item({
            //obscure
            Text{"a progressive wallet", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a progressive wallet", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[PROGRESSIVE_MAGIC_METER] = HintText::Item({
            //obscure
            Text{"progressive magic meter", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a progressive magic power", "**FRENCH**", "**SPANISH**"}
    );
	//	PROGRESSIVE_BOMBCHUS,

	//BOTTLE ITEMS
	hintTable[EMPTY_BOTTLE] = HintText::Item({
            //obscure
            Text{"a glass container", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Empty Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[EMPTY_BOTTLE1] = HintText::Item({
            //obscure
            Text{"a glass container", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Empty Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[EMPTY_BOTTLE2] = HintText::Item({
            //obscure
            Text{"a glass container", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"an Empty Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_MILK] = HintText::Item({
            //obscure
            Text{"a dairy product", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Milk Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_RED_POTION] = HintText::Item({
            //obscure
            Text{"a vessel of health", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Red Potion Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_GREEN_POTION] = HintText::Item({
            //obscure
            Text{"a magic potion", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Green Potion Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_BLUE_POTION] = HintText::Item({
            //obscure
            Text{"a blue drink", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Blue Potion Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_FAIRY] = HintText::Item({
            //obscure
            Text{"a fairy", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Fairy Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_FISH] = HintText::Item({
            //obscure
            Text{"something fresh", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Fish Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[CHATEAU_ROMANI] = HintText::Item({
            //obscure
            Text{"an adult beverage", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Chateau Romani Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_BUGS] = HintText::Item({
            //obscure
            Text{"an insect", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Bug Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_POE] = HintText::Item({
            //obscure
            Text{"a captured spirit", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Poe Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_BIG_POE] = HintText::Item({
            //obscure
            Text{"a large captured spirit", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Big Poe Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_HOT_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a hot liquid", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Hot Spring Water Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a fresh drink", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Spring Water Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[DEKU_PRINCESS] = HintText::Item({
            //obscure
            Text{"a princess", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Deku Princess Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GOLD_DUST] = HintText::Item({
            //obscure
            Text{"a gleaming powder", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Gold Dust Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a lost child", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Zora Egg Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SEAHORSE] = HintText::Item({
            //obscure
            Text{"a sea creature", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Seahorse Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_MUSHROOM] = HintText::Item({
            //obscure
            Text{"a strange fungus", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Magic Mushroom Bottle", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[BOTTLE_WITH_MYSTERY_MILK] = HintText::Item({
            //obscure
            Text{"a strange drink", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Mystery Milk Bottle", "**FRENCH**", "**SPANISH**"}
    );
		//UPGRADABLE ITEMS
	hintTable[LARGE_QUIVER]         = HintText::Item({Text{"a ranged weapon", "**FRENCH**", "**SPANISH**"}});
	hintTable[LARGEST_QUIVER]       = HintText::Item({Text{"a ranged weapon", "**FRENCH**", "**SPANISH**"}});
	hintTable[BOMB_BAG]             = HintText::Item({Text{"a vessel of explosives", "**FRENCH**", "**SPANISH**"}});
	hintTable[BIG_BOMB_BAG]         = HintText::Item({Text{"a vessel of explosives", "**FRENCH**", "**SPANISH**"}});
	hintTable[BIGGEST_BOMB_BAG]     = HintText::Item({Text{"a vessel of explosives", "**FRENCH**", "**SPANISH**"}});
	hintTable[ADULT_WALLET]         = HintText::Item({Text{"a coin purse", "**FRENCH**", "**SPANISH**"}});
	hintTable[GIANT_WALLET]         = HintText::Item({Text{"a coin purse", "**FRENCH**", "**SPANISH**"}});
	hintTable[MAGIC_POWER]          = HintText::Item({Text{"magic power", "**FRENCH**", "**SPANISH**"}});
	hintTable[EXTENDED_MAGIC_POWER] = HintText::Item({Text{"magic power", "**FRENCH**", "**SPANISH**"}});
		//SONGS
	//hintTable[SONG_OF_TIME] = HintText::Item({Text{"song of time", "**FRENCH**", "**SPANISH**"}});
	hintTable[SONG_OF_STORMS] = HintText::Item({
            //obscure
            Text{"stormy weather", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Song of Storms", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SONG_OF_HEALING] = HintText::Item({
            //obscure
            Text{"a soothing melody", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Song of Healing", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SONG_OF_SOARING] = HintText::Item({
            //obscure
            Text{"white wings", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Song of Soaring", "**FRENCH**", "**SPANISH**"}
    );
	//hintTable[SONG_OF_DOUBLE_TIME] = HintText::Item({Text{"double time", "**FRENCH**", "**SPANISH**"}});
	//hintTable[INVERTED_SONG_OF_TIME] = HintText::Item({Text{"slowed time", "**FRENCH**", "**SPANISH**"}});
	hintTable[EPONAS_SONG] = HintText::Item({
            //obscure
            Text{"a horses song", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Epona's Song", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SONATA_OF_AWAKENING] = HintText::Item({
            //obscure
            Text{"a royal song", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Sonata of Awakening", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[LULLABY_INTRO] =  HintText::Item({
            //obscure
            Text{"a sleepy melody intro", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Lullaby Intro", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GORONS_LULLABY] = HintText::Item({
            //obscure
            Text{"a sleepy melody", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Goron's Lullaby", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[NEW_WAVE_BOSSA_NOVA] = HintText::Item({
            //obscure
            Text{"a song of newborns", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the New Wave Bossa Nova", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ELEGY_OF_EMPTINESS] = HintText::Item({
            //obscure
            Text{"empty shells", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Elegy of Emptiness", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[OATH_TO_ORDER] = HintText::Item({
            //obscure
            Text{"a song of giants", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Oath to Order", "**FRENCH**", "**SPANISH**"}
    );
		//PIECES OF HEART
	hintTable[PIECE_OF_HEART] = HintText::Item({
            //obscure
            Text{"a segment of health", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Piece of Heart", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[HEART_CONTAINER] = HintText::Item({
            //obscure
            Text{"a new heart", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Heart Container", "**FRENCH**", "**SPANISH**"}
    );
	//MAPS
	//hintTable[MAP] = HintText::Item({Text{"a paper guide", "**FRENCH**", "**SPANISH**"}});
	hintTable[WOODFALL_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Temple Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SNOWHEAD_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Temple Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GBT_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Temple Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[STONE_TOWER_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Temple Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[CLOCK_TOWN_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Clock Town Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[WOODFALL_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SNOWHEAD_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GREAT_BAY_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[STONE_TOWER_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Map", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[ROMANI_RANCH_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Romani Ranch Map", "**FRENCH**", "**SPANISH**"}
    );
		//COMPASSES
	//hintTable[COMPASS] = HintText::Item({Text{"a magnetic needle", "**FRENCH**", "**SPANISH**"}});
	hintTable[WOODFALL_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Temple Compass", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SNOWHEAD_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Temple Compass", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GBT_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Temple Compass", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[STONE_TOWER_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Temple Compass", "**FRENCH**", "**SPANISH**"}
    );
		//BOSSKEYS
	//hintTable[BOSS_KEY] = HintText::Item({Text{"an important key", "**FRENCH**", "**SPANISH**"}});
	hintTable[WOODFALL_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Temple Boss Key", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[SNOWHEAD_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Temple Boss Key", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GBT_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Temple Boss Key", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[STONE_TOWER_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Temple Boss Key", "**FRENCH**", "**SPANISH**"}
    );
		//SMALLKEYS
	//hintTable[SMALL_KEY] = HintText::Item({Text{"a useful key", "**FRENCH**", "**SPANISH**"}});
	hintTable[WOODFALL_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"swampy small key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Temple Small Key", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[SNOWHEAD_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"icy small key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Temple Small Key", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[GBT_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"ocean small key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Temple Small Key", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[STONE_TOWER_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"rocky small key", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Temple Small Key", "**FRENCH**", "**SPANISH**"}
    );
        //DUNGEON REWARDS
	hintTable[ODOLWAS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Odolwa's Remains", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GOHTS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Goht's Remains", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[GYORGS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Gyorg's Remains", "**FRENCH**", "**SPANISH**"}
    );
	hintTable[TWINMOLDS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Twinmold's Remains", "**FRENCH**", "**SPANISH**"}
    );
    
    /*-----------------------
    |    REFILL ITEMS       |
    -----------------------*/
    hintTable[RECOVERY_HEART] = HintText::Item({
            //obscure
            Text{"Recovery Heart", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Recovery Heart", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[GREEN_RUPEE] = HintText::Item({
            //obscure
            Text{"Green rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Green Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BLUE_RUPEE] = HintText::Item({
            //obscure
            Text{"Blue rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Blue Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[RED_RUPEE] = HintText::Item({
            //obscure
            Text{"Red rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Red Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[PURPLE_RUPEE] = HintText::Item({
            //obscure
            Text{"Purple rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Purple Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[SILVER_RUPEE] = HintText::Item({
            //obscure
            Text{"Silver rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Silver Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[HUGE_RUPEE] = HintText::Item({
            //obscure
            Text{"Huge rupee", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Huge Rupee", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[DEKU_NUTS_5] = HintText::Item({
            //obscure
            Text{"5 nuts", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Deku Nuts (5 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[DEKU_NUTS_10] = HintText::Item({
            //obscure
            Text{"10 nuts", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Deku Nuts (10 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBS_5] = HintText::Item({
            //obscure
            Text{"5 explosive orbs", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombs (5 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBS_10] = HintText::Item({
            //obscure
            Text{"10 explosive orbs", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombs (10 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBS_20] = HintText::Item({
            //obscure
            Text{"20 explosive orbs", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombs (20 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBCHU_5] = HintText::Item({
            //obscure
            Text{"5 explosive mice", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombchu (5 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBCHU_10] = HintText::Item({
            //obscure
            Text{"10 explosive mice", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombchu (10 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBCHU_20] = HintText::Item({
            //obscure
            Text{"20 explosive mice", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Bombchu (20 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[ARROWS_10] = HintText::Item({
            //obscure
            Text{"10 projectile sticks", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Arrow (10 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[ARROWS_30] = HintText::Item({
            //obscure
            Text{"30 projectile sticks", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Arrow (30 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[ARROWS_40] = HintText::Item({
            //obscure
            Text{"40 projectile sticks", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Arrow (40 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[ARROWS_50] = HintText::Item({
            //obscure
            Text{"50 projectile sticks", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Arrow (50 pieces)", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BLUE_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Blue Potion Refill", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"some Blue Potion", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[GREEN_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Green Potion Refill", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"some Green Potion", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[RED_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Red Potion Refill", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"some Red Potion", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[BOMBCHU_DROP] = HintText::Item({
            //obscure
            Text{"explosive mice", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"some Bombchu", "**FRENCH**", "**SPANISH**"}
    );
    hintTable[DEKU_STICK_1] = HintText::Item({
            //obscure
            Text{"1 stick", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"a Deku Stick", "**FRENCH**", "**SPANISH**"}
    );
	
    /*----------------
    |   SHOP ITEMS   |
    ----------------*/
    hintTable[BUY_ARROWS_10]        = HintText::Item({Text{"Buy 10 Arrows", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_ARROWS_30]        = HintText::Item({Text{"Buy 30 Arrows", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_BLUE_POTION]      = HintText::Item({Text{"Buy Blue Potion", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_BOMBCHU_10]       = HintText::Item({Text{"Buy 10 Bombchu", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_BOMBS_10]         = HintText::Item({Text{"Buy 10 Bombs", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_DEKU_NUT_10]      = HintText::Item({Text{"Buy 10 Deku Nuts", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_DEKU_STICK_1]     = HintText::Item({Text{"Buy 1 Deku Stick", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_FAIRYS_SPIRIT]    = HintText::Item({Text{"Buy Fairy", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_GREEN_POTION]     = HintText::Item({Text{"Buy Green Potion", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_HEROS_SHIELD]     = HintText::Item({Text{"Buy Hero Shield", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_MAGIC_BEAN]       = HintText::Item({Text{"Buy Magic Bean", "**FRENCH**", "**SPANISH**"}});
    hintTable[BUY_RED_POTION]       = HintText::Item({Text{"Buy Red Potion", "**FRENCH**", "**SPANISH**"}});

    /*-----------------------
	|  SOMETIMES HINT TEXT  |
	-----------------------*/
	// Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({
            Text{"A Musical Instrument", "**FRENCH**", "**SPANISH**"}});
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({
            Text{"a forest curse removed rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({
            Text{"a masked man's melody teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({
            Text{"a masked man's gift rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({
            Text{"a new file yields", "**FRENCH**", "**SPANISH**"}});
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({
            Text{"a new file yields", "**FRENCH**", "**SPANISH**"}});
  //PRE_CLOCK_TOWN_CHEST,
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({
            Text{"a gorging merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({
            Text{"the home of scrubs contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({
            Text{"the royal servant rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a merchant's cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({
            Text{"a false imprisonment teaches", "**FRENCH**", "**SPANISH**"}});
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({
            Text{"an important lady rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({
            Text{"a town activity rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({
            Text{"a town activity rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({
            Text{"a town leader rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({
            Text{"a lovers game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({
            Text{"a treasure game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({
            Text{"a delivery person rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({
            Text{"a miserable leader rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({
            Text{"an important lady rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({
            Text{"a secret hideout contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({
            Text{"a shop roof contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            Text{"a correspondence box contains", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_MILK_BAR_MILK] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({
            Text{"an upset stomach cure rewards", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({
            Text{"a large goron rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({
            Text{"a northern merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({
            Text{"a lonely peak contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({
            Text{"a northern merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({
            Text{"a cold ledge contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING] = HintText::Sometimes({
            Text{"a large goron rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE_SPRING] = HintText::Sometimes({
            Text{"a northern merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE_SPRING] = HintText::Sometimes({
            Text{"a northern merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_LEDGE_SPRING] = HintText::Sometimes({
            Text{"a cold ledge contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({
            Text{"a lonely child teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({
            Text{"a lonely peak contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({
            Text{"a lonely peak contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_SHOP_ITEM_1] = HintText::Sometimes({
            Text{"a goron shop sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_SHOP_ITEM_2] = HintText::Sometimes({
            Text{"a goron shop sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_SHOP_ITEM_3] = HintText::Sometimes({
            Text{"a goron shop sells", "**FRENCH**", "**SPANISH**"}});
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({
            Text{"a new ocean home owner rewards", "**FRENCH**", "**SPANISH**"}});
  //hintTable[GBC_OCEAN_SPIDER_DAY2] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[GBC_OCEAN_SPIDER_DAY3] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({
            Text{"an ocean game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({
            Text{"the colored masks contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({
            Text{"feeding the fish rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_LEDGE] = HintText::Sometimes({
            Text{"an ocean ledge contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_MIKAU] = HintText::Sometimes({
            Text{"a healed spirit rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_BABY_ZORAS]  = HintText::Sometimes({
            Text{"the pirates' loot teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({
            Text{"an ocean cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({
            Text{"a fisherman rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
//Ikana Canyon
    hintTable[IKANA_CANYON_GREAT_FAIRY] = HintText::Sometimes({
            Text{"the fairy of kindness rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_POE_HUT_HP] = HintText::Sometimes({
            Text{"a game of ghosts rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_LEDGE] = HintText::Sometimes({
            Text{"a canyon ledge contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_PAMELAS_FATHER] = HintText::Sometimes({
            Text{"a lost father rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a waterfall cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_SCRUB_TRADE] = HintText::Sometimes({
            Text{"an eastern merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_SCRUB_PURCHASE] = HintText::Sometimes({
            Text{"an eastern merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_IKANA_CANYON_ST] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_IKANA_CANYON_CT] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
//Ikana Graveyard
    hintTable[IKANA_GRAVEYARD_DAMPE_DIGGING] = HintText::Sometimes({
            Text{"a fearful basement contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST] = HintText::Sometimes({
            Text{"a hollow ground contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST] = HintText::Sometimes({
            Text{"a skeletal leader rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET] = HintText::Sometimes({
            Text{"a hollow ground teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS] = HintText::Sometimes({
            Text{"a cloud of bats contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a circled cave contains", "**FRENCH**", "**SPANISH**"}});
//Laundry Pool
    hintTable[LAUNDRY_POOL_KAFEI] = HintText::Sometimes({
            Text{"a posted letter rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE] = HintText::Sometimes({
            Text{"a shady dealer rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO] = HintText::Sometimes({
            Text{"a shady dealer rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL_GURU_GURU] = HintText::Sometimes({
            Text{"a musician gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL_SF] = HintText::Sometimes({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
//Milk Road
    hintTable[MILK_ROAD_GORMAN_RACE] = HintText::Sometimes({
            Text{"a sporting event rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[MILK_ROAD_GORMAN_MILK_BUY] = HintText::Sometimes({
            Text{"a dodgy seller sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[MILK_ROAD_KEATON_QUIZ] = HintText::Sometimes({
            Text{"a mysterious fox rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_MILK_ROAD_RR] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_MILK_ROAD_GB] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
//Mountain Village
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE] = HintText::Sometimes({
            Text{"a moutain smith crafts", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO] = HintText::Sometimes({
            Text{"a mountain smith crafts", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_FROG_CHOIR] = HintText::Sometimes({
            Text{"a frog choir rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_KEATON_QUIZ] = HintText::Sometimes({
            Text{"a mysterious fox rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_DARMANI] = HintText::Sometimes({
            Text{"a mountain spirit rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_HUNGRY_GORON] = HintText::Sometimes({
            Text{"a hungry goron rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_WATERFALL_CHEST] = HintText::Sometimes({
            Text{"a springtime waterfall contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a springtime cave contains", "**FRENCH**", "**SPANISH**"}});
//N Clock Town
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU] = HintText::Sometimes({
            Text{"the fairy of magic rewards", "**FRENCH**", "**SPANISH**"}});
  //hintTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}}); doesn't give an item in 3d
    hintTable[N_CLOCK_TOWN_KEATON_QUIZ] = HintText::Sometimes({
            Text{"a mysterious fox rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS] = HintText::Sometimes({
            Text{"a game for scrubs rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[N_CLOCK_TOWN_TREE] = HintText::Sometimes({
            Text{"a town playground contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[N_CLOCK_TOWN_OLD_LADY] = HintText::Sometimes({
            Text{"an old lady's struggle rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN] = HintText::Sometimes({
            Text{"the fairy of magi rewardsc", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_N_CLOCK_TOWN_CT] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_N_CLOCK_TOWN_WF] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[N_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            Text{"a correspondence box contains", "**FRENCH**", "**SPANISH**"}});
  //hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY] = HintText::Sometimes({Text{"a game for scrubs", "**FRENCH**", "**SPANISH**"}});
//Road to Snowhead
    hintTable[ROAD_TO_SNOWHEAD_PILLAR] = HintText::Sometimes({
            Text{"a cold platform contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a snowy cave contains", "**FRENCH**", "**SPANISH**"}});
//Pinnacle Rock
    hintTable[PINNACLE_ROCK_SEAHORSES] = HintText::Sometimes({
            Text{"a fishy reunion rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK_UPPER_CHEST] = HintText::Sometimes({
            Text{"a marine trench contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK_LOWER_CHEST] = HintText::Sometimes({
            Text{"a marine trench contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG1] = HintText::Sometimes({
            Text{"in a marine trench rests", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG2] = HintText::Sometimes({
            Text{"in a marine trench rests", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG3] = HintText::Sometimes({
            Text{"in a marine trench rests", "**FRENCH**", "**SPANISH**"}});
//Road to Ikana
    hintTable[ROAD_TO_IKANA_PILLAR_CHEST] = HintText::Sometimes({
            Text{"a high chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_IKANA_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a blocked cave contains", "**FRENCH**", "**SPANISH**"}});
//Road to Southern Swamp
    hintTable[ROAD_TO_SS_ARCHERY_1] = HintText::Sometimes({
            Text{"a swamp game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SS_ARCHERY_2] = HintText::Sometimes({
            Text{"a swamp game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SS_TREE] = HintText::Sometimes({
            Text{"a batty tree contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SWAMP_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a southern cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_ROAD_TO_SS_WF] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_ROAD_TO_SS_SH] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
//Romani Ranch
    hintTable[ROMANI_RANCH_ALIEN_DEFENSE] = HintText::Sometimes({
            Text{"a ranch invasion rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_DOG_RACE] = HintText::Sometimes({
            Text{"a sporting event rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_GROG] = HintText::Sometimes({
            Text{"a chicken lover rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_CREMIA_ESCORT] = HintText::Sometimes({
            Text{"an older sister rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_ROMANIS_GAME] = HintText::Sometimes({
            Text{"an equine reunion teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_COW_1] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_COW_2] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_COW_3] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[DOGGY_RACETRACK_ROOF_CHEST] = HintText::Sometimes({
            Text{"a day at the races contains", "**FRENCH**", "**SPANISH**"}});
//S Clock Town
    hintTable[S_CLOCK_TOWN_SCRUB_TRADE] = HintText::Sometimes({
            Text{"a town merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            Text{"a correspondence box contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE] = HintText::Sometimes({
            Text{"the tower doors contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST] = HintText::Sometimes({
            Text{"a straw roof contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_FINAL_DAY_CHEST] = HintText::Sometimes({
            Text{"a carnival tower contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_1] = HintText::Sometimes({
            Text{"a keeper of wealth rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_2] = HintText::Sometimes({
            Text{"interest rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_3] = HintText::Sometimes({
            Text{"being rich rewards", "**FRENCH**", "**SPANISH**"}});
//Snowhead
    hintTable[SNOWHEAD_GREAT_FAIRY] = HintText::Sometimes({
            Text{"the fairy of power rewards", "**FRENCH**", "**SPANISH**"}});
//Southern Swamp
    hintTable[SOUTHERN_SWAMP_KOUME] = HintText::Sometimes({
            Text{"a witch rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE] = HintText::Sometimes({
            Text{"a sleeping witch rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS] = HintText::Sometimes({
            Text{"a witch rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE] = HintText::Sometimes({
            Text{"a southern merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER] = HintText::Sometimes({
            Text{"a swamp game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_BOAT_ARCHERY] = HintText::Sometimes({
            Text{"a swamp game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF] = HintText::Sometimes({
            Text{"a tourist center contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a swampy cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD] = HintText::Sometimes({
            Text{"a swamp spider man rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a mystery cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE] = HintText::Sometimes({
            Text{"a sleeping witch rewards", "**FRENCH**", "**SPANISH**"}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
  //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE] = HintText::Sometimes({
            Text{"a southern merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE_CLEAR] = HintText::Sometimes({
            Text{"a southern merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE_CLEAR] = HintText::Sometimes({
            Text{"a southern merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF_CLEAR] = HintText::Sometimes({
            Text{"a tourist center contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[POTION_SHOP_ITEM_1] = HintText::Sometimes({
            Text{"a potion maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[POTION_SHOP_ITEM_2] = HintText::Sometimes({
            Text{"a potion maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[POTION_SHOP_ITEM_3] = HintText::Sometimes({
            Text{"a potion maker sells", "**FRENCH**", "**SPANISH**"}});
//Stock Pot Inn
    hintTable[STOCKPOTINN_RESERVATION] = HintText::Sometimes({
            Text{"checking-in rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_MIDNIGHT_MEETING] = HintText::Sometimes({
            Text{"a late meeting rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_TOILET_HAND] = HintText::Sometimes({
            Text{"a strange palm rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_GRANDMA_SHORT_STORY] = HintText::Sometimes({
            Text{"an old lady rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_GRANDMA_LONG_STORY] = HintText::Sometimes({
            Text{"an old lady rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_ANJU_AND_KAFEI] = HintText::Sometimes({
            Text{"a lovers' reunion rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_STAFF_ROOM_CHEST] = HintText::Sometimes({
            Text{"an employee room contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_GUEST_ROOM_CHEST] = HintText::Sometimes({
            Text{"a guest bedroom contains", "**FRENCH**", "**SPANISH**"}});
//Stone Tower
    hintTable[STONE_TOWER_INVERTED_RIGHT_CHEST] = HintText::Sometimes({
            Text{"a sky below contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_INVERTED_CENTER_CHEST] = HintText::Sometimes({
            Text{"a sky below contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_INVERTED_LEFT_CHEST] = HintText::Sometimes({
            Text{"a sky below contains", "**FRENCH**", "**SPANISH**"}});
//Termina Field
    hintTable[TERMINA_FIELD_MOONS_TEAR] = HintText::Sometimes({
            Text{"a falling star contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES] = HintText::Sometimes({
            Text{"mysterious stones reward", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB] = HintText::Sometimes({
            Text{"a hidden merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a hollow ground contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a hollow ground contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE] = HintText::Sometimes({
            Text{"a beehive contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_KAMARO] = HintText::Sometimes({
            Text{"a dancer rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a hollow pillar contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a grassy cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_UNDERWATER_CHEST] = HintText::Sometimes({
            Text{"a sunken chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GRASS_CHEST] = HintText::Sometimes({
            Text{"a grassy chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_STUMP_CHEST] = HintText::Sometimes({
            Text{"a tree chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GROTTO_COW1] = HintText::Sometimes({
            Text{"a lost creature gives", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GROTTO_COW2] = HintText::Sometimes({
            Text{"a lost creature gibes", "**FRENCH**", "**SPANISH**"}});
//Twin Islands
    hintTable[HOT_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a steamy grotto contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_GORON_RACE] = HintText::Sometimes({
            Text{"a sporting event rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a hidden cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST] = HintText::Sometimes({
            Text{"a spring treasure contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_CAVE_CHEST] = HintText::Sometimes({
            Text{"a sunken springtime treasure contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_LULLABY_INTRO] = HintText::Sometimes({
            Text{"a goron elder teaches", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_TWIN_ISLANDS_SH] = HintText::Sometimes({
            Text{"a map maker sells ", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_TWIN_ISLANDS_RR] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_TWIN_ISLANDS_SH_SPRING] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TINGLE_TWIN_ISLANDS_RR_SPRING] = HintText::Sometimes({
            Text{"a map maker sells", "**FRENCH**", "**SPANISH**"}});
//W Clock Town
    hintTable[W_CLOCK_TOWN_BOMB_BAG_BUY] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_POSTMANS_GAME] = HintText::Sometimes({
            Text{"a delivery person rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_ROSA_SISTERS] = HintText::Sometimes({
            Text{"traveling sisters reward", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Sometimes({
            Text{"a town game rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY] = HintText::Sometimes({
            Text{"a shady town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_BOMB_SHOP_GORON] = HintText::Sometimes({
            Text{"a town goron merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN_CURIOSITY_BOMB_BAG] = HintText::Sometimes({
            Text{"a shady town merchant sells", "**FRENCH**", "**SPANISH**"}});
  //hintTable[W_CLOCK_TOWN_LOTTERY] = HintText::Sometimes({Text{"**ENGLISH**", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_1] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_2] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_3] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_4] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_5] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_6] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_7] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[TRADING_POST_ITEM_8] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[BOMB_SHOP_ITEM_1] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[BOMB_SHOP_ITEM_2] = HintText::Sometimes({
            Text{"a town merchant sells", "**FRENCH**", "**SPANISH**"}});
  //hintTable[BOMB_SHOP_ITEM_3] = HintText::Sometimes({Text{"a town merchant", "**FRENCH**", "**SPANISH**"}});
//Woodfall
    hintTable[WOODFALL_BRIDGE_CHEST] = HintText::Sometimes({
            Text{"a swamp chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_BEHIND_OWL_CHEST] = HintText::Sometimes({
            Text{"a swamp chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ENTRANCE_TO_WOODFALL_CHEST] = HintText::Sometimes({
            Text{"a swamp chest contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_GREAT_FAIRY] = HintText::Sometimes({
            Text{"the fairy of wisdom rewards", "**FRENCH**", "**SPANISH**"}});
//Zora Cape
    hintTable[ZORA_CAPE_GREAT_FAIRY] = HintText::Sometimes({
            Text{"the fairy of courage rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_BEAVER_RACE_1] = HintText::Sometimes({
            Text{"a river dweller rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_BEAVER_RACE_2] = HintText::Sometimes({
            Text{"a river dweller rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_LIKE_LIKE] = HintText::Sometimes({
            Text{"a shield eater contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_LEDGE_NO_TREE] = HintText::Sometimes({
            Text{"a high place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_LEDGE_WITH_TREE] = HintText::Sometimes({
            Text{"a high place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_GROTTO_CHEST] = HintText::Sometimes({
            Text{"a beach cave contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_UNDERWATER_CHEST] = HintText::Sometimes({
            Text{"a sunken chest contains ", "**FRENCH**", "**SPANISH**"}});
//Zora Hall
    hintTable[ZORA_HALL_SCRUB_TRADE] = HintText::Sometimes({
            Text{"a western merchant trades", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_EVAN] = HintText::Sometimes({
            Text{"a musician rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_LULU_ROOM_LEDGE] = HintText::Sometimes({
            Text{"the singer's room contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_SCRUB_PURCHASE] = HintText::Sometimes({
            Text{"a western merchant sells", "**FRENCH**", "**SPANISH**"}});
  //hintTable[ZORA_HALL_STAGE_LIGHTS] = HintText::Sometimes({Text{"a fan", "**FRENCH**", "**SPANISH**"}});
  //hintTable[ZORA_HALL_BAD_PHOTO_LULU] = HintText::Sometimes({Text{"a fan", "**FRENCH**", "**SPANISH**"}});
  //hintTable[ZORA_HALL_GOOD_PHOTO_LULU] = HintText::Sometimes({Text{"a fan", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_SHOP_ITEM_1] = HintText::Sometimes({
            Text{"a zora merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_SHOP_ITEM_2] = HintText::Sometimes({
            Text{"a zora merchant sells", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_SHOP_ITEM_3] = HintText::Sometimes({
            Text{"a zora merchant sells", "**FRENCH**", "**SPANISH**"}});
  
  /*-------------------------
  |  DUNGEON LOCATION TEXT  |
  -------------------------*/

    hintTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST] = HintText::Exclude({
            Text{"the sleeping temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_TEMPLE_MAP_CHEST] = HintText::Exclude({
            Text{"the sleeping temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            Text{"the sleeping temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            Text{"the sleeping temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST] = HintText::Exclude({
            Text{"the sleeping temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_TEMPLE_DEKU_PRINCESS] = HintText::Exclude({
            Text{"the sleeping temple rewards", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_ENTRANCE_FAIRY] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_ENTRANCE_PLATFORM] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_MAIN_ROOM_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_MAIN_ROOM_SWITCH] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_DEKU_BABA] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_DRAGONFLY_ROOM_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_SKULLTULA] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_DARK_ROOM] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_JAR_FAIRY] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_BRIDGE_ROOM_BEEHIVE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[WF_SF_PLATFORM_ROOM_BEEHIVE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ODOLWA_HEART_CONTAINER] = HintText::Exclude({
            Text{"a masked evil contains", "**FRENCH**", "**SPANISH**"}});	
//Snowhead Temple
    hintTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_MAP_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST] = HintText::Exclude({
            Text{"an icy temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_SNOW_ROOM_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_CEILING_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_DINOLFOS_1] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_DINOLFOS_2] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_MAP_ROOM_FAIRY] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_MAP_ROOM_LEDGE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_BASEMENT] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_TWIN_BLOCK] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_ICICLE_ROOM_WALL] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_MAIN_ROOM_WALL] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_PILLAR_FREEZARDS] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_ICE_PUZZLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SH_SF_CRATE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GOHT_HEART_CONTAINER] = HintText::Exclude({
            Text{"a masked evil contains", "**FRENCH**", "**SPANISH**"}});
//Great bay Temple
    hintTable[GBT_ICE_ARROW_CHEST] = HintText::Exclude({
            Text{"the murky watered temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_MAP_CHEST] = HintText::Exclude({
            Text{"the murky watered temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_COMPASS_CHEST] = HintText::Exclude({
            Text{"the murky watered temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_BOSS_KEY_CHEST] = HintText::Exclude({
            Text{"the murky watered temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SMALL_KEY_CHEST] = HintText::Exclude({
            Text{"the murky watered temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_SKULLTULA] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_LOWER] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_UPPER] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_GREEN_VALVE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_SEESAW_ROOM] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_ENTRANCE_TORCHES] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_BIO_BABAS] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_UNDERWATER_BARREL] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_WHIRLPOOL_BARREL] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_WHIRLPOOL_JAR] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_DEXIHANDS_JAR] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_LEDGE_JAR] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[GYORG_HEART_CONTAINER] = HintText::Exclude({
            Text{"a masked evil contains", "**FRENCH**", "**SPANISH**"}});
//Stone Tower Temple
    hintTable[STONE_TOWER_TEMPLE_MAP_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST] = HintText::Exclude({
            Text{"a rocky temple contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_MIRROR_SUN_BLOCK] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_LAVA_ROOM_LEDGE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_LAVA_ROOM_FIRE_RING] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_EYEGORE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_UPDRAFT_FIRE_RING] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_MIRROR_SUN_SWITCH] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_BOSS_WARP] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_WIZZROBE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_DEATH_ARMOS] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_UPDRAFT_FROZEN_EYE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_THIN_BRIDGE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_BASEMENT_LEDGE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_STATUE_EYE] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_UNDERWATER] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[ST_SF_BRIDGE_CRYSTAL] = HintText::Exclude({
            Text{"a lost fairy is", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWINMOLD_HEART_CONTAINER] = HintText::Exclude({
            Text{"a masked evil contains", "**FRENCH**", "**SPANISH**"}});
//Pirate Fortress
    hintTable[PF_INTERIOR_HOOKSHOT_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_LOWER_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_UPPER_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_TANK_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_GUARD_ROOM_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_CAGE_ROOM_SHALLOW_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_CAGE_ROOM_DEEP_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_MAZE_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_SEWER_CAGE] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_EXTERIOR_LOG_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_EXTERIOR_SAND_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_EXTERIOR_CORNER_CHEST] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_INVISIBLE_SOLDIER] = HintText::Exclude({
            Text{"the home of pirates contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_HOOKSHOT_ROOM_ZORA_EGG] = HintText::Exclude({
            Text{"in the home of pirates rests", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_GUARD_ROOM_ZORA_EGG] = HintText::Exclude({
            Text{"in the home of pirates rests", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_BARREL_MAZE_ZORA_EGG] = HintText::Exclude({
            Text{"in the home of pirates rests", "**FRENCH**", "**SPANISH**"}});
    hintTable[PF_INT_LAVA_ROOM_ZORA_EGG] = HintText::Exclude({
            Text{"in the home of pirates rests", "**FRENCH**", "**SPANISH**"}});
//Beneath the Well
    hintTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST] = HintText::Exclude({
            Text{"a frightful exchange contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WELL_LEFT_PATH_CHEST] = HintText::Exclude({
            Text{"a frightful exchange contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[WELL_RIGHT_PATH_CHEST] = HintText::Exclude({
            Text{"a frightful exchange contains", "**FRENCH**", "**SPANISH**"}});  
    hintTable[BENEATH_THE_WELL_COW] = HintText::Exclude({
            Text{"a lost creature contains", "**FRENCH**", "**SPANISH**"}});
//Ikana Castle
    hintTable[IKANA_CASTLE_PILLAR] = HintText::Exclude({
            Text{"a fiery pilar contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CASTLE_IKANA_KING] = HintText::Exclude({
            Text{"a fallen king teaches", "**FRENCH**", "**SPANISH**"}});
//Secret Shrine 
    hintTable[SECRET_SHRINE_DINOLFOS_CHEST] = HintText::Exclude({
            Text{"a secret place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SECRET_SHRINE_WIZZROBE_CHEST] = HintText::Exclude({
            Text{"a secret place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SECRET_SHRINE_WART_CHEST] = HintText::Exclude({
            Text{"a secret place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SECRET_SHRINE_GARO_CHEST] = HintText::Exclude({
            Text{"a secret place contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[SECRET_SHRINE_FINAL_CHEST] = HintText::Exclude({
            Text{"a secret place contains", "**FRENCH**", "**SPANISH**"}});
//The Moon
    hintTable[THE_MOON_DEKU_TRIAL_BONUS] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_GORON_TRIAL_BONUS] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_ZORA_TRIAL_BONUS] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_LINK_TRIAL_BONUS] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_GARO_CHEST] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_IRON_KNUCKLE_CHEST] = HintText::Exclude({
            Text{"a masked child's game contains", "**FRENCH**", "**SPANISH**"}});
    hintTable[THE_MOON_MAJORA_CHILD] = HintText::Exclude({
            Text{"the lonely child rewards", "**FRENCH**", "**SPANISH**"}});
//Southern Swamp Skulltula House
    hintTable[SSH_MAIN_ROOM_NEAR_CEILING] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_WATER] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_UPPER_SOIL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_PILLAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_UPPER_PILLAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MAIN_ROOM_JAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MONUMENT_ROOM_TORCH] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MONUMENT_ROOM_ON_MONUMENT] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_MONUMENT_ROOM_LOWER_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_GOLD_ROOM_NEAR_CEILING] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_GOLD_ROOM_PILLAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_GOLD_ROOM_BEEHIVE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_GOLD_ROOM_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_JAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_POT_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_POT_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_BEHIND_VINES] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_BEEHIVE_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_POT_ROOM_BEEHIVE_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_TREE_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_TREE_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_TREE_3] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_GRASS_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_GRASS_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[SSH_TREE_ROOM_BEEHIVE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
//Oceanside spider House
    hintTable[OSH_ENTRANCE_LEFT_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_ENTRANCE_RIGHT_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_ENTRANCE_WEB] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_CABINET] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_CEILING_EDGE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_LIBRARY_BEHIND_PICTURE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_CEILING_EDGE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_CEILING_PLANK] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_JAR] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_WEBBED_HOLE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_WEBBED_POT] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_UPPER_POT] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_SECOND_ROOM_LOWER_POT] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_STORAGE_ROOM_CEILING_WEB] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_STORAGE_ROOM_BEHIND_CRATE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_STORAGE_ROOM_WALL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_STORAGE_ROOM_CRATE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_STORAGE_ROOM_BARREL] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_CEILING_EDGE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_1] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_2] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_3] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_BEHIND_PICTURE] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});
    hintTable[OSH_COLORED_SKULLS_POT] = HintText::Exclude({
            Text{"a gold spider is", "**FRENCH**", "**SPANISH**"}});


  /*----------------------
  |   REGTION HINT TEXT  |
  ----------------------*/
    hintTable[N_CLOCK_TOWN] = HintText::Region({ Text{"N Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = HintText::Region({Text{"Clock Town Fairy Fountain", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_DEKU_PLAYGROUND] = HintText::Region({Text{"Deku Playground", "**FRENCH**", "**SPANISH**"}});
    hintTable[E_CLOCK_TOWN] = HintText::Region({Text{"E Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN] = HintText::Region({Text{"Stock Pot Inn", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_GUEST_ROOM] = HintText::Region({Text{"Stock Pot Inn", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_STAFF_ROOM] = HintText::Region({Text{"Stock Pot Inn", "**FRENCH**", "**SPANISH**"}});
    hintTable[STOCKPOTINN_GRANDMA_ROOM] = HintText::Region({Text{"Stock Pot Inn", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_OBSERVATORY] = HintText::Region({Text{"Observatory", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_BAR] = HintText::Region({Text{"Milk Bar", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_HONEY_DARLING] = HintText::Region({Text{"E Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = HintText::Region({Text{"E Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_ARCHERY] = HintText::Region({Text{"E Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_MAYOR_HOUSE] = HintText::Region({Text{"E Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[W_CLOCK_TOWN] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_POSTMAN_HOUSE] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_LOTTERY] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_BOMB_SHOP] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_TRADING_POST] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWN_CURIOSITY_SHOP] = HintText::Region({Text{"W Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[S_CLOCK_TOWN] = HintText::Region({Text{"S Clock Town", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWER] = HintText::Region({Text{"Clock Tower", "**FRENCH**", "**SPANISH**"}});
    hintTable[CLOCK_TOWER_ROOF] = HintText::Region({Text{"Clock Tower Roof", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL] = HintText::Region({Text{"Laundry Pool", "**FRENCH**", "**SPANISH**"}});
    hintTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = HintText::Region({Text{"Laundry Pool", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_COW_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = HintText::Region({Text{"Termina Field", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP] = HintText::Region({Text{"Road to Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = HintText::Region({Text{"Road to Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SWAMP_GROTTO] = HintText::Region({Text{"Road to Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP] = HintText::Region({Text{"Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[SWAMP_TOURIST_CENTER] = HintText::Region({Text{"Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = HintText::Region({Text{"Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[MYSTERY_WOODS] = HintText::Region({Text{"Mystery Woods", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = HintText::Region({Text{"Mystery Woods", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = HintText::Region({Text{"Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[SOUTHERN_SWAMP_TOP] = HintText::Region({Text{"Southern Swamp", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE] = HintText::Region({Text{"Deku Palace", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_INTERIOR] = HintText::Region({Text{"Deku Palace", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO] = HintText::Region({Text{"Deku Palace", "**FRENCH**", "**SPANISH**"}});
    hintTable[DEKU_SHRINE] = HintText::Region({Text{"Deku Palace", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL] = HintText::Region({Text{"Woodfall", "**FRENCH**", "**SPANISH**"}});
    hintTable[WOODFALL_FAIRY_FOUNTAIN] = HintText::Region({Text{"Woodfall Fairy Foutain", "**FRENCH**", "**SPANISH**"}});
    hintTable[PATH_TO_MOUNTAIN_VILLAGE] = HintText::Region({Text{"Path to Mountain Vilage", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE] = HintText::Region({Text{"Mountain Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_GRAVEYARD] = HintText::Region({Text{"Goron Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_SMITHY] = HintText::Region({Text{"Mountain Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = HintText::Region({Text{"Mountain Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS] = HintText::Region({Text{"Twin Islands", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_RACETRACK] = HintText::Region({Text{"Goron Racetrack", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = HintText::Region({Text{"Twin Islands", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = HintText::Region({Text{"Twin Islands", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE] = HintText::Region({Text{"Goron Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_LENS_CAVE] = HintText::Region({Text{"Goron Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_INTERIOR] = HintText::Region({Text{"Goron Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORON_VILLAGE_SHOP] = HintText::Region({Text{"Goron Village", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SNOWHEAD] = HintText::Region({Text{"Road to Snowhead", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO] = HintText::Region({Text{"Road to Snowhead", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD] = HintText::Region({Text{"Snowhead", "**FRENCH**", "**SPANISH**"}});
    hintTable[SNOWHEAD_FAIRY_FOUNTAIN] = HintText::Region({Text{"Snowhead Fairy Fountain", "**FRENCH**", "**SPANISH**"}});
    hintTable[MILK_ROAD] = HintText::Region({Text{"Milk Road", "**FRENCH**", "**SPANISH**"}});
    hintTable[GORMAN_TRACK] = HintText::Region({Text{"Gorman Track", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH] = HintText::Region({Text{"Romani Ranch", "**FRENCH**", "**SPANISH**"}});
    hintTable[DOGGY_RACETRACK] = HintText::Region({Text{"Romani Ranch", "**FRENCH**", "**SPANISH**"}});
    hintTable[CUCCO_SHACK] = HintText::Region({Text{"Romani Ranch", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_HOUSE] = HintText::Region({Text{"Romani Ranch", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROMANI_RANCH_BARN] = HintText::Region({Text{"Romani Ranch", "**FRENCH**", "**SPANISH**"}});
    hintTable[GREAT_BAY_COAST] = HintText::Region({Text{"Great Bay Coast", "**FRENCH**", "**SPANISH**"}});
    hintTable[GREAT_BAY_COAST_MARINE_LAB] = HintText::Region({Text{"Great Bay Coast", "**FRENCH**", "**SPANISH**"}});
    hintTable[GREAT_BAY_COAST_GROTTO] = HintText::Region({Text{"Great Bay Coast", "**FRENCH**", "**SPANISH**"}});
    hintTable[GREAT_BAY_COAST_COW_GROTTO] = HintText::Region({Text{"Great Bay Coast", "**FRENCH**", "**SPANISH**"}});
    hintTable[FISHERMAN_HUT] = HintText::Region({Text{"Great Bay Coast", "**FRENCH**", "**SPANISH**"}});
    hintTable[PINNACLE_ROCK] = HintText::Region({Text{"Pinnacle Rock", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE] = HintText::Region({Text{"Zora Cape", "**FRENCH**", "**SPANISH**"}});
    hintTable[WATERFALL_RAPIDS] = HintText::Region({Text{"Zora Cape", "**FRENCH**", "**SPANISH**"}});
    hintTable[GREAT_BAY_FAIRY_FOUNTAIN] = HintText::Region({Text{"Zora Cape Fairy Fountain", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_CAPE_GROTTO] = HintText::Region({Text{"Zora Cape", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_EVANS_ROOM] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_LULUS_ROOM] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_JAPAS_ROOM] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_TIJOS_ROOM] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_SHOP] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ZORA_HALL_BACK_ENTRANCE] = HintText::Region({Text{"Zora Hall", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_IKANA] = HintText::Region({Text{"Road to Ikana", "**FRENCH**", "**SPANISH**"}});
    hintTable[ROAD_TO_IKANA_GROTTO] = HintText::Region({Text{"Road to Ikana", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_GROTTO] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_BATS_ROOM] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_TABLET_ROOM] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[DAMPES_HUT] = HintText::Region({Text{"Ikana Graveyard", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_UPPER] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_CAVE] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[SAKONS_HIDEOUT] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[MUSIC_BOX_HOUSE] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_POE_HUT] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = HintText::Region({Text{"Ikana Canyon Fairy Foutain", "**FRENCH**", "**SPANISH**"}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = HintText::Region({Text{"Ikana Canyon", "**FRENCH**", "**SPANISH**"}});
    hintTable[STONE_TOWER] = HintText::Region({Text{"Stone Tower", "**FRENCH**", "**SPANISH**"}});
    hintTable[INVERTED_STONE_TOWER] = HintText::Region({Text{"Stone Tower", "**FRENCH**", "**SPANISH**"}});


  /*---------------------
  |   JUNK HINT TEXT    |
  ---------------------*/
    hintTable[JUNK01] = HintText::Junk({Text{"That's no moon.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK02] = HintText::Junk({Text{"The moon is haunted.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK03] = HintText::Junk({Text{"Majora has sick dance moves.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK04] = HintText::Junk({Text{"Making hints is hard.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK05] = HintText::Junk({Text{"May the way of the Hero lead to the Triforce.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK06] = HintText::Junk({Text{"They say that the final item you're looking for can be found somewhere in Termina.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK07] = HintText::Junk({Text{"They say that 85 percent of statistics are made up", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK08] = HintText::Junk({Text{"They say the golden dog is picked as the winner most often", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK09] = HintText::Junk({Text{"Be patient young grasshopper", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK10] = HintText::Junk({Text{"The Ikana King used to be quite handsome", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK11] = HintText::Junk({Text{"If the Goron Elder is frozen how does he move each day", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK12] = HintText::Junk({Text{"The Owl's feathers lead the way", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK13] = HintText::Junk({Text{"The Happy Mask Salesman doesn't sleep", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK14] = HintText::Junk({Text{"why do they call it oven when you of in the cold food of out hot eat the food", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK15] = HintText::Junk({Text{"It seems Link has difficulties remembering music without the help of a fairy.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK16] = HintText::Junk({Text{"Pickle.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK17] = HintText::Junk({Text{"Why is it called The Legend of Zelda Majora's Mask when Zelda isn't here?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK18] = HintText::Junk({Text{"They say you can find the Star Fox cast in your mask inventory screen.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK19] = HintText::Junk({Text{"They say #L# is Real 2401.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK20] = HintText::Junk({Text{"They say #The Moon# blinks if you stare long enough", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK21] = HintText::Junk({Text{"They say bunnies have a really good sense of time.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK22] = HintText::Junk({Text{"They say this game has a method of infinitely jumping.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK23] = HintText::Junk({Text{"According to all known laws of aviation there is no way a Zora should be able to fly.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK24] = HintText::Junk({Text{"Why is Zelda green?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK25] = HintText::Junk({Text{"Did you know for the first time in 23 years, in 2023 Waluigi didn't star in a game?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK26] = HintText::Junk({Text{"Here's a hint, @. Don't be bad.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK27] = HintText::Junk({Text{"They say this randomizer actually took longer to develop than the original Majora's Mask.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK28] = HintText::Junk({Text{"They say pirates are allergic to #bees#.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK29] = HintText::Junk({Text{"Ocean man, take me by the hand.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK30] = HintText::Junk({Text{"Special shoutouts to ennopp who plays piano during this cutscene", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK31] = HintText::Junk({Text{"Did you know it's actually surprisingly easy to mod a 3DS?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK32] = HintText::Junk({Text{"Zora eggs are quite delicious.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK33] = HintText::Junk({Text{"Zabora and Gabora have gotten better at making swords that stay sharp.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK34] = HintText::Junk({Text{"They say Tacoman369 has never defeated Majora.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK35] = HintText::Junk({Text{"L2P @.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK36] = HintText::Junk({Text{"They say the #Majora's Mask 3D Randomizer# developers are cool people.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK37] = HintText::Junk({Text{"Also try #Ocarina of Time 3D Randomizer#!", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK38] = HintText::Junk({Text{"The single rupee is a unique item.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK39] = HintText::Junk({Text{"Hey, listen!", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK40] = HintText::Junk({Text{"They say even the Hero of Time can't help everyone.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK41] = HintText::Junk({Text{"The dirt around here tastes really good.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK42] = HintText::Junk({Text{"Talk to me again for the best hint.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK43] = HintText::Junk({Text{"They say Gorons discovered a method of space travel.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK44] = HintText::Junk({Text{"I AM ERROR", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK45] = HintText::Junk({Text{"Real 3DS ZELDA players use motion controls.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK46] = HintText::Junk({Text{"Real ZELDA players use HOLD targeting.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK47] = HintText::Junk({Text{"They say items are random...", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK48] = HintText::Junk({Text{"Dear Mario, please come to the castle. I've baked a cake for you. Yours truly, Princess Toadstool, Peach", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK49] = HintText::Junk({Text{"They say the key to victory is beating the game...", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK50] = HintText::Junk({Text{"They say the gold dog cheats.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK51] = HintText::Junk({Text{"They say @ drowned.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK52] = HintText::Junk({Text{"Goodbye then.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK53] = HintText::Junk({Text{"You've met with a terrible hint, haven't you?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK54] = HintText::Junk({Text{"I'm stoned. Get it?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK55] = HintText::Junk({Text{"One who doesn't have all the masks will not get a #special reward#", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK56] = HintText::Junk({Text{"They say the #blue dog# will win a race some day...", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK57] = HintText::Junk({Text{"Remember to check your 3DS battery level and save often.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK58] = HintText::Junk({Text{"Just be a rock.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK59] = HintText::Junk({Text{"I can't feel my legs!", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK60] = HintText::Junk({Text{"What are you staring at?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK61] = HintText::Junk({Text{"Glitches are a pathway to many abilities some consider to be... Unnatural.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK62] = HintText::Junk({Text{"You ever just feel like smashing that $ button?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK63] = HintText::Junk({Text{"I think the Mask of Truth has it's uses!", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK64] = HintText::Junk({Text{"There's a lot of eyes here, isn't there?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK65] = HintText::Junk({Text{"I think that #large object in the sky# hasn't moved in a few days.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK66] = HintText::Junk({Text{"Watch out for that #large object in the sky!#", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK67] = HintText::Junk({Text{"#Tingle Tingle Kooloo Limpah!#", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK68] = HintText::Junk({Text{"They say if you have three specific items, you can zoom across Termina.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK69] = HintText::Junk({Text{"They say the powder keg can remain fairly elusive.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK70] = HintText::Junk({Text{"It's pretty cold here, would you mind warming me up, @?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK71] = HintText::Junk({Text{"These hints can be quite useful. This is an exception.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK72] = HintText::Junk({Text{"Turns are more effective when you tilt the whole console.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK73] = HintText::Junk({Text{"You ever been in a cockpit before?", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK74] = HintText::Junk({Text{"It's a secret to everybody", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK75] = HintText::Junk({Text{"You found me!", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK76] = HintText::Junk({Text{"I have it on my post-it note somewhere.", "**FRENCH**", "**SPANISH**"}});
    hintTable[JUNK77] = HintText::Junk({Text{"Follow the rainbow.", "**FRENCH**", "**SPANISH**"}});

  /*------------------------
  |   DUNGEON HINT TEXT    |
  ------------------------*/

    hintTable[WOODFALL_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the sleeping temple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Woodfall Temple", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[SNOWHEAD_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"an icy temple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Snowhead Temple", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[GREAT_BAY_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the murky watered temple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Great Bay Temple", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[STONE_TOWER_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"a rocky temple", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Stone Tower Temple", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[PIRATE_FORTRESS] = HintText::DungeonName({
            //obscure
            Text{"the home of pirates", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Pirates' Fortress", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[BENEATH_THE_WELL] = HintText::DungeonName({
            //obscure
            Text{"an empty watering hole", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"Beneath the Well", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[IKANA_CASTLE]  = HintText::DungeonName({
            //obscure
            Text{"a fallen castle", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Ancient Castle of Ikana", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[SECRET_SHRINE] = HintText::DungeonName({
            //obscure
            Text{"a mini boss run area", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Secret Shrine", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[SSH] = HintText::DungeonName({
            //obscure
            Text{"a home to muddy spiders", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Swamp Spider House", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[OSH] = HintText::DungeonName({
            //obscure
            Text{"a home To swimming spiders", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Ocean Spider House", "**FRENCH**", "**SPANISH**"}    
    );
    hintTable[THE_MOON] = HintText::DungeonName({
            //obscure
            Text{"a dungeon out of this world", "**FRENCH**", "**SPANISH**"}
        },
            //clear
            Text{"the Moon", "**FRENCH**", "**SPANISH**"}    
    );

  /*-----------------------
  |    BOSS HINT TEXT     |
  -----------------------*/
    hintTable[ODOLWA] = HintText::Boss({Text{"a masked jungle warrior holds", "**FRENCH**", "**SPANISH**"}});
    hintTable[GOHT] = HintText::Boss({Text{"a masked mechanical monster holds", "**FRENCH**", "**SPANISH**"}});
    hintTable[GYORG] = HintText::Boss({Text{"a gargantuan masked fish holds", "**FRENCH**", "**SPANISH**"}});
    hintTable[TWINMOLD] = HintText::Boss({Text{"a giant masked insect holds", "**FRENCH**", "**SPANISH**"}});
    hintTable[MAJORA] = HintText::Boss({Text{"a cursed mask holds", "**FRENCH**", "**SPANISH**"}});

  
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