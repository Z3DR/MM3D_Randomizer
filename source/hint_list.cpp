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
    //Item Hint Text 
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
	/*
	hintTable[SWAMP_SKULLTULA_TOKEN1] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN2] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN3] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN4] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN5] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN6] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN7] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN8] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN9] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN10] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN12] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN13] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN14] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN15] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN16] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN17] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN18] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN19] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN20] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN21] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN22] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN23] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN24] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN25] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN26] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN27] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN28] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN29] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[SWAMP_SKULLTULA_TOKEN30] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	*/
	hintTable[OCEANSIDE_SKULLTULA_TOKEN] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	/*
	hintTable[OCEANSIDE_SKULLTULA_TOKEN1] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN2] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN3] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN4] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN5] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN6] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN7] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN8] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN9] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN10] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN11] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN12] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN13] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN14] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN15] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN16] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN17] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN18] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN19] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN20] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN21] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN22] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN23] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN24] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN25] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN26] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN27] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN28] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN29] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	hintTable[OCEANSIDE_SKULLTULA_TOKEN30] = HintText::Item({ Text{"a golden token", "a golden token", "a golden token"} });
	*/
	//Stray Fairies
	hintTable[CT_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[WF_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	/*
	hintTable[WF_STRAY_FAIRY1] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY2] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY3] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY4] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY5] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY6] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY7] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY8] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY9] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY10] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY11] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY12] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY13] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY14] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	hintTable[WF_STRAY_FAIRY15] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost faiy"} });
	*/
	hintTable[SH_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	/*
	hintTable[SH_STRAY_FAIRY1] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY2] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY3] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY4] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY5] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY6] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY7] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY8] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY9] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY10] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY11] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY12] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY13] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY14] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[SH_STRAY_FAIRY15] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	*/
	hintTable[GBT_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	/*
	hintTable[GBT_STRAY_FAIRY1] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY2] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY3] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY4] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY5] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY6] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY7] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY8] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY9] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY10] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY11] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY12] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY13] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY14] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[GBT_STRAY_FAIRY15] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	*/
	hintTable[ST_STRAY_FAIRY] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	/*
	hintTable[ST_STRAY_FAIRY1] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY2] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY3] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY4] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY5] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY6] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY7] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY8] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY9] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY10] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY11] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY12] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY13] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY14] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	hintTable[ST_STRAY_FAIRY15] = HintText::Item({ Text{"a lost fairy", "a lost fairy", "a lost fairy"} });
	*/
	//PROGRESSIVE ITEMS (unused currently)
	//	PROGRESSIVE_SWORD,
	//	PROGRESSIVE_BOMB_BAG,
	//	PROGRESSIVE_BOW,
	//	PROGRESSIVE_WALLET,
	//	PROGRESSIVE_MAGIC_METER,
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
	/*
	hintTable[PIECE_OF_HEART1] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART2] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART3] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART4] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART5] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART6] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART7] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART8] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART9] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART10] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART11] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART12] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART13] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART14] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART15] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART16] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART17] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART18] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART19] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART20] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART21] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART22] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART23] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART24] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART25] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART26] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART27] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART28] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART29] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART30] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	hintTable[PIECE_OF_HEART31] = HintText::Item({ Text{"a segment of health", "a segment of health", "a segment of health"} });
	*/
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