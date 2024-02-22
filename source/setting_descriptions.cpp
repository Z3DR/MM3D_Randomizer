#include "setting_descriptions.hpp"


/*------------------------------                                                           
|            LOGIC             |                            *SCREEN WIDTH*
------------------------------*/       /*--------------------------------------------------*/
string_view logicGlitchless           = "No glitches are required, but may require some\n" //
                                        "minor tricks. Add minor tricks to consider for\n" //
                                        "logic in Logical Tricks.";                        //
string_view logicGlitched             = "The glitches you enable at the set difficulty\n"  //
                                        "or below may be required.\n"                      //
                                        "\n"                                               //
                                        "In development, but still usable.";               //
string_view logicNoLogic              = "Maximize randomization, All locations are\n"      //
                                        "considered available. MAY BE IMPOSSIBLE TO BEAT.";//
string_view logicVanilla              = "For those who want to play the game normally but\n"
                                        "with the improvements of the randomizer. All\n"   //
                                        "locations will contain their vanilla items. This\n"
                                        "supercedes all item shuffle, logic, hint, and\n"  //
                                        "item pool settings. You can still use non-vanilla\n"
                                        "world settings such as entrance shuffle, \n"      //
                                        "but the game may require glitches to complete\n"  //
                                        "if you do.";                             //
/*------------------------------                                                           //
|   ALL LOCATIONS REACHABLE    |                                                           //
------------------------------*/                                                           //
string_view locationsReachableDesc    = "When this options is enabled, the randomizer will\n"
                                        "guarantee that every item is obtainable and every\n"
                                        "location is reachable. When disabled, only\n"     //
                                        "required items and locations to beat the game\n"  //
                                        "will be guaranteed reachable.";                   //
/*------------------------------                                                           //
|  DETAILED LOGIC EXPLANATIONS |                                                           //
------------------------------*/                                                           //
string_view ToggleLogicNoneDesc       = "These are not implemented yet come back soon!.";  //
string_view ToggleLogicNoviceDesc     = "These are not implemented yet come back soon!.";  //
string_view ToggleLogicIntermediateDesc="These are not implemented yet come back soon!.";  //
string_view ToggleLogicExpertDesc     = "These are not implemented yet come back soon!.";  //
/*------------------------------                                                           //
|     START WITH CONSUMABLES   |                                                           //
------------------------------*/                                                           //
string_view startWithConsumablesDesc  = "Start the game with maxed out Deku Nuts.";        //
                                                                                           //
                                                                                           //
/*------------------------------                                                           //
|     START WITH MAX RUPEES    |                                                           //
------------------------------*/                                                           //
string_view startWithMaxRupeesDesc    = "Start the game with a full wallet.\n"             //
                                        "Wallet upgrades will also fill the wallet.";      //
                                                                                           //
/*------------------------------                                                           //
|    DUNGEON RANDOMIZE         |                                                           //
------------------------------*/                                                           //
string_view dungeonRandomize          = "Randomize all Dungeon Settings";                  //
/*------------------------------                                                           //
|    SHUFFLE DUNGEON ENTRANCES |                                                           //
------------------------------*/                                                           //
string_view shuffleDungeonEntrancesDesc = "**OPTION CURRENTLY WIP**\n"                     //
                                        "Shuffles Dungeon Entrances amongst themselves";   //
/*------------------------------                                                           //
|      BOMBCHUS IN LOGIC       |                                                           //
------------------------------*/                                                           //
string_view bombchuInLogicDesc          = "**OPTION CURRENTLY WIP**\n"                     //
                                        "Adds Bombchus into logic (You may need to use \n" //
                                        "bombchus instead of bombs to reach locations.";   //
/*------------------------------                                                           //
|      ITEM DROP SETTINGS      |                                                           //
------------------------------*/                                                           //
string_view ammoDropDesc              = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enables or disables ammo drops";                  //
string_view heartDropDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enables or disables heart drops";                 //
/*------------------------------                                                           //
|    SHUFFLE CHESTS            |                                                           //
------------------------------*/                                                           //
string_view shuffleChestItemsVanilla  = "Sets Chest Items to Vanilla Locations"            //
                                        "Does not include Captain's Hat, Giants Mask or"   //
                                        "the two chests on the Moon";                      //
string_view shuffleChestItemsRandom   = "Adds Chest Items to the pool to be randomized"    //
                                        "Does not include Captain's Hat, Giants Mask or "  //
                                        "the two chests on the Moon";                      //
                                                                                           //
/*------------------------------                                                           //
|    SHUFFLE CHESTS            |                                                           //
------------------------------*/                                                           //
string_view shuffleBombersNotebookDesc = "Shuffle Bomber's Notebook.";                    //
/*------------------------------                                                           //
|    SHUFFLE MASKS             |                                                           //
------------------------------*/                                                           //
string_view shuffleMasksVanilla       = "Sets Masks to Vanilla Locations";                 //
                                                                                           //
string_view shuffleMasksRandom        = "Adds Masks to the pool to be randomized";         //
                                                                                           //
/*------------------------------                                                           //
|    SHUFFLE TRADE ITEMS       |                                                           //
------------------------------*/                                                           //
string_view shuffleTradeItemsDesc     = "Shuffle Anju & Kafei Quest Items\n"               //
                                        "Includes Both Letters, Room Key, Pendant and Both\n"//
                                        "Both Kafei Mask & Couples Mask";                  //
                                                                                           //   
/*------------------------------                                                           //
|    SHUFFLE TINGLE MAPS       |                                                           //
------------------------------*/                                                           //
string_view shuffleTingleMapsDesc     = "Shuffle Tingle Maps";                             //
                                                                                           //
                                                                                           //
/*------------------------------                                                           //
|    SHUFFLE HEART CONTAINERS  |                                                           //
------------------------------*/                                                           //
string_view shufflePiecesOfHeartDesc  = "Shuffle Piece of Hearts";                         //
                                                                                           //
string_view shuffleHeartContainersDesc= "Shuffle Heart Containers";                        //                                                                    
/*------------------------------                                                           //
|    ITEM POOL OPTIONS         |                                                           //
------------------------------*/                                                           //
string_view shuffleMainInventoryDesc  = "Shuffle Main Inventory Items\n"                   //
                                        "This includes 2 Swords, 3 Bow/Quivers, 3 BombBags,\n"
                                        "Powder Kegs, PictoBox, Lens of Truth, Hookshot, \n"
                                        "7 Bottles, Mirror Shield, 2 Wallets Upgrades, \n" //
                                        "Magic Beans and Fire, Ice, and Light Arrows";     //
                                                                                           //   
string_view shuffleTransformationDesc = "Shuffles Deku, Goron, and Zora Masks";            //
string_view shuffleFierceDeityDesc    = "Shuffles Fierce Deity Mask";                      //
string_view shuffleMoonItemsDesc      = "Shuffles Items from the Moon into the pool\n"     //
                                        "Includes 4 Pieces of Heart, and 2 junk items";    //
/*------------------------------                                                           //
|      MAPS AND COMPASSES      |                                                           //
------------------------------*/                                                           //
string_view mapCompassStartWith       = "Maps and Compasses are given to you from the\n"   //
                                        "start. This will add a small amount of money and\n"
                                        "refill items to the pool.";                       //
string_view mapCompassVanilla         = "Maps and Compasses will appear in their vanilla\n"//
                                        "locations.";                                      //
string_view mapCompassOwnDungeon =      "Maps and Compasses can only appear in their\n"    //
                                        "respective dungeon.";                             //
string_view mapCompassAnyDungeon      = "Maps and Compasses can only appear in a dungeon,\n"//
                                        "but not necessarily the dungeon they are for.";   //
string_view mapCompassOverworld       = "Maps and Compasses can only appear outside of\n"  //
                                        "dungeons.";                                       //
string_view mapCompassAnywhere        = "Maps and Compasses can appear anywhere in the\n"  //
                                        "world.";                                          //
/*------------------------------                                                           //
|         SMALL KEYS           |                                                           //
------------------------------*/                                                           //
string_view smallKeyStartWith         = "Small Keys are given to you from the start so you\n"
                                        "won't have to worry about locked doors. An easier\n"
                                        "mode.";                                           //
string_view smallKeyVanilla           = "Small Keys will appear in their vanilla locations.";//
string_view smallKeyOwnDungeon        = "Small Keys can only appear in their respective\n" //
                                        "dungeon. ";                                       //
string_view smallKeyAnyDungeon        = "Small Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view smallKeyOverworld         = "Small Keys can only appear outside of dungeons.\n"//
                                        "You may need to enter a dungeon multiple times to\n"
                                        "gain items to access the overworld locations with\n"
                                        "the keys required to finish a dungeon.";          //
string_view smallKeyAnywhere          = "Small Keys can appear anywhere in the world. A\n" //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|          BOSS KEYS           |                                                           //
------------------------------*/                                                           //
string_view bossKeyStartWith          = "Boss Keys are given to you from the start so you\n"
                                        "won't have to worry about boss doors. An easier\n"//
                                        "mode.";                                           //
string_view bossKeyVanilla            = "Boss Keys will appear in their vanilla locations.";//
string_view bossKeyOwnDungeon         = "Boss Keys can only appear in their respective\n"  //
                                        "dungeon.";                                        //
string_view bossKeyAnyDungeon         = "Boss Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view bossKeyOverworld          = "Boss Keys can only appear outside of dungeons.\n" //
                                        "You may need to enter a dungeon without the boss\n"
                                        "key to get items required to find the key in the\n"
                                        "overworld.";                                      //
string_view bossKeyAnywhere           = "Boss Keys can appear anywhere in the world. A\n"  //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|       STRAY FAIRIES          |                                                           //
------------------------------*/                                                           //
string_view fairyVanilla              = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Stray Fairies will appear in their \n"            //
                                        "vanilla locations.";                              //
string_view fairyStartWith            = "**OPTION CURRENTLY WIP**\n"                       // 
                                        "Stray Fairies are given to you from the start so \n"
                                        "won't have to worry about collecting them.\n"     //
                                        "An easier mode.";                                 //
string_view fairyOwnDungeon           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Stray Fairies can only appear in their respective\n"
                                        "dungeon.";                                        //
string_view fairyAnyDungeon           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Stray Fairies can only appear inside of any dungeon\n"
                                        "but won't necessarily be in the dungeon that they\n"
                                        "are supposed to be found in.";                    //
string_view fairyOverworld            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Stray Fairies can only appear outside of dungeons";
string_view fairyAnywhere             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Stray Fairies can appear anywhere in the world."; //
/*------------------------------                                                           //
|   SHUFFLE DUNGEON REWARDS    |                                                           //
------------------------------*/                                                           //
string_view shuffleRewardsEndOfDungeon = "**OPTION CURRENTLY WIP**\n"                      //
                                         "Boss Remains will be given as\n"                 //
                                         "rewards for beating dungeons.\n";                //
                                                                                           //
string_view shuffleRewardsAnyDungeon  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can only appear inside of dungeons.\n"; 
                                                                                           //
string_view shuffleRewardsOverworld   = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can only appear outside of dungeons.\n"; 
                                                                                           //
string_view shuffleRewardsAnywhere    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can appear anywhere.\n";             //  
                                                                                           //
/*------------------------------                                                           //
|      SHUFFLE MAGIC BEANS     |                                                           //
------------------------------*/                                                           //
string_view magicBeansDesc            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this adds a pack of 10 beans to the item\n"
                                        "pool and changes the Magic Bean Salesman to sell a"
                                        "random item at a price of 60 rupees.";            //
/*------------------------------                                                           //
|     SHUFFLE KOKIRI SWORD     |                                                           //
------------------------------*/                                                           //
string_view kokiriSwordDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this shuffles the Kokiri Sword into the\n"
                                        "item pool.\n"                                     //
                                        "\n"                                               //
                                        "This will leave you quite vulnerable without any\n"
                                        "way to attack until an item is found";            //
                                                                                           //
string_view shuffleStartShield       = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Shuffles your starting shield into the pool";      //
/*------------------------------                                                           //
| SHUFFLE GREAT FAIRY REWARDS  |                                                           //
------------------------------*/                                                           //
string_view shuffleGFVanilla          = "Great Fairy Rewards will be Vanilla";             //
string_view shuffleGFSelf             = "Great Fairy Rewards will be shuffled among \n"    //
                                        "other Great Fairy Locations";                     //
string_view shuffleGFAnywhere         = "Great Fairy Rewards can be anywhere";             //
/*------------------------------                                                           //
|       SHUFFLE MERCHANTS      |                                                           //
------------------------------*/                                                           //
string_view shuffleMerchantsDesc      = "Shuffles Deku Scrub Merchant Items into the Pool";//
/*------------------------------                                                           //
|       SKIP EPONA RACE        |                                                           //
------------------------------*/                                                           //
string_view skipEponaRaceDesc         = "*OPTION CURRENTLY WIP**\n"                        //
                                        "Skips the race to keep Epona";                    //
/*------------------------------                                                           //
|    RAZOR SWORD DURABILITY    |                                                           //
------------------------------*/                                                           //
string_view rsDurabilityVanilla       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Keeps the Razor Sword's Durability vanilla";      //
string_view rsDurabilityInf           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Makes the Razor Sword never break";               //
/*------------------------------                                                           //
|         TRIAL SKIPS          |                                                           //
------------------------------*/                                                           //
string_view odolwaTrialSkipDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Skips the Odolwa Trial on the Moon";              //
string_view gohtTrialSkipDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Skips the Gyorg Trial on the Moon";               //
string_view gyorgTrialSkipDesc        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Skips the Gyorg Trial on the Moon";               //
string_view twinmoldTrialSkipDesc     = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Skips the Twinmold Trial on the Moon";            //
/*------------------------------                                                           //
|   PROGRESSIVE GILDED SWORD   |                                                           //
------------------------------*/                                                           //
string_view progressiveGildedSwordDesc = "**OPTION CURRENTLY WIP**\n"                      //
                                        "Sets the Gilded Sword to progressive or not";     //
/*------------------------------                                                           //
|        STARTING SPIN         |                                                           //
------------------------------*/                                                           //
string_view startingSpinDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Sets the spin attack to be upgraded or not \n"    //
                                        "setting to vanilla adds the upgrade to the pool"; //
/*------------------------------                                                           //
|         SONG SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view songsSongLocations        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs will only appear at locations that normally\n"
                                        "teach songs.";                                    //
string_view songsDungeonRewards       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs appear at the end of dungeons. For major\n" //
                                        "dungeons, they will be at the boss heart container"
                                        "location. ";                                      //
string_view songsAllLocations         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs can appear in any location.";               //
                                                                                           //
string_view shuffleSoaringVanilla     = "Sets Song of Soaring to its Vanilla Location";    //
string_view shuffleSoaringRandom      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Randomizes Song of Soaring";                      //                                                                                                             
/*------------------------------                                                           //
|     GOSSIP STONE HINTS       |                                                           //
------------------------------*/                                                           //
string_view gossipStonesHintsDesc     = "Gossip Stones can be made to give hints about\n"  //
                                        "where items can be found.\n"                      //
                                        "Different settings can be chosen to decide which\n"
                                        "item is needed to speak to Gossip Stones. Choosing"
                                        "to stick with the Mask of Truth will make the\n"  //
                                        "hints very difficult to obtain.\n"                //
                                        "Hints for 'on the way of the hero' are locations\n"
                                        "that contain items that are required to beat the\n"
                                        "game.";                                           //
                                                                                           //
/*------------------------------                                                           //
|        CLEARER HINTS         |                                                           //
------------------------------*/                                                           //
string_view clearerHintsDesc          = "The hints provided by Gossip Stones will be very\n"
                                        "direct if this option is enabled.";               //    
/*------------------------------                                                           //
|      HINT DISTRIBUTION       |                                                           //
------------------------------*/                                                           //
string_view uselessHintsDesc          = "Only junk hints.";                                //
string_view balancedHintsDesc         = "Recommended hint spread.";                        //
string_view strongHintsDesc           = "More useful hints.";                              //
string_view veryStrongHintsDesc       = "Many powerful hints.";                            //
                                                                                           //
/*------------------------------                                                           //
|    CHANGE OVERWORLD SPIRTES  |                                                           //
------------------------------*/                                                           //
string_view changeOverworldItemsDesc  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes the appearance of of freestanding items\n"//
                                        "to match the contents of the randomized item.\n"  //
                                        "Items retain original appearance when set to off";//
/*------------------------------                                                           //
|        INGAME SPOILERS       |                                                           //
------------------------------*/                                                           //
string_view ingameSpoilersShowDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Every spoiler is shown.";                         //
string_view ingameSpoilersHideDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Hides the spheres page and only shows a\n"        //
                                        "location's item after it has been found.";        //
                                                                                           //
string_view genSpoilerLogDesc         = "Choose to Generate a Spoiler Log";                //
string_view compassShowWotHDesc       = "Getting a Dungeon's Compass will show if the\n"   //
                                        "Dungeon is WotH";                                 //
/*------------------------------                                                           //
|      MENU OPENING BUTTON     |                                                           //
------------------------------*/                                                           //
string_view menuButtonDesc            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Choose which button will bring up the Dungeon\n"  //
                                        "Information Menu. You can also use the menu to\n" //
                                        "buffer frame perfect inputs if you choose D-Pad"; //
                                                                                           //
                                                                                           //
/*------------------------------                                                           //
|    RANDOM TRAP DAMAGE TYPE   |                                                           //
------------------------------*/                                                           //
string_view randomTrapDmgDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All traps will be the base game ice trap";        //
                                                                                           //
string_view basicTrapDmgDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All alternative traps will cause a small damage\n"//
                                        "and no other negative effects";                   //
                                                                                           //
string_view advancedTrapDmgDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Some chest traps will burn your Deku Shield or\n" //
                                        "cause a lot of damage (with one-hit protection)"; //
                                                                                           //
/*------------------------------                                                           //
|          ITEM POOL           |                                                           //
------------------------------*/                                                           //
string_view itemPoolPlentiful         = "Extra major items are added to the pool.";        //
string_view itemPoolBalanced          = "Original item pool.";                             //
string_view itemPoolScarce            = "Some excess items are removed, including health\n"//
                                        "upgrades.";                                       //
string_view itemPoolMinimal           = "Most excess items are removed.";                  //
                                                                                           //
/*------------------------------                                                           //
|          ICE TRAPS           |                                                           //
------------------------------*/                                                           //
string_view iceTrapsOff               = "All Ice Traps are removed.\n"                     //
                                        "This is the same as Vanilla as the base game\n"   // 
                                        "Does not have any Ice Traps.";                    //
string_view iceTrapsExtra             = "Chance to add Ice Traps when junk items are\n"
                                        "added to the itempool.";                          //
string_view iceTrapsMayhem            = "All added junk items will be Ice Traps.";         //
string_view iceTrapsOnslaught         = "All junk items will be replaced by Ice Traps, even"
                                        "those in the base pool.";                         //
/*------------------------------                                                           //
|    REMOVE DOUBLE DEFENSE     |                                                           //
------------------------------*/                                                           //
string_view removeDDDesc              = "If set the double defense item will be removed\n" //
                                        "from the item pool for balanced and plentiful.";  //
                                                                                           //
/*------------------------------                                                           //
|     BLAST MASK COOLDOWN      |                                                           //
------------------------------*/                                                           //
string_view blastDefault              = "Sets the cooldown time on the blastmask to \n"    //
                                        "the default cooldown time of 10 seconds";         //
string_view blastInstant              = "Sets the cooldown time on the blastmask to \n"    //
                                        "have no cooldown time";                           //
string_view blastVeryShort            = "Sets the cooldown time on the blastmask to \n"    //
                                        "have an even shorter cooldown time of 3 seconds"; //
string_view blastShort                = "Sets the cooldown time on the blastmask to \n"    //
                                        "have a shorter cooldown time of 5 seconds";       //
string_view blastLong                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Sets the cooldown time on the blastmask to \n"    //
                                        "have a longer cooldown time of 15 seconds";       //
string_view blastVeryLong             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Sets the cooldown time on the blastmask to \n"    //
                                        "have an even longer cooldown time of 20 seconds"; //
/*------------------------------                                                           //
|   VARIOUS COMFORT SETTINGS   |                                                           //
------------------------------*/                                                           //
string_view skipMinigamePhasesDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Completing Town Archery or Swamp Archery \n"      //
                                        "on the first attempt will give\n"                 //
                                        "both rewards at once for that minigame."          //
                                        "Also skips the first beaver race.";               //
                                                                                           //
string_view fierceDeityAnywhereDesc   = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enables the use of the Fierce Deity Mask anywhere";//
                                                                                           //
 string_view underwaterOcarinaDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enables the use of the ocarina while underwater.";//
 string_view fastLabFishDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes Lab Fish to only need to be fed one fish";//
 string_view fastBankDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes the Bank reward thresholds from \n"       //
                                        "200/1000/5000 to 200/500/1000.\n"                 //
                                        "Also lowers max bank storage to 1000 total";      //
 string_view fastDogRaceDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Makes the Gold Dog always win when equipped with \n"
                                        "the Mask of Truth";                               //
 string_view goodDampeRNGDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes Dampe's ghost flames to have two on the \n"//
                                        "ground and one up the ladder.";                   //
 string_view increasePushSpeedDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Increases the speed of pushing most \n"           //
                                        "blocks and pushable objects";                     //
 string_view fastArrowSwitchDesc      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enables Cycling through arrow types by pressing R\n"//
                                        "with the bow equipped and an arrow drawn";        //
 string_view fastElegyStatuesDesc     = "Speeds up the animation of the elegy of emptiness\n"
                                        "statues spawning.";                               //
 string_view skipSongReplaysDesc      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "The automatic replay after you play a song will\n"//
                                        "be skipped.\n"                                    //
                                        "You can choose to keep the sfx anyway, but you\n" //
                                        "will have control of Link during it.";            //
/*------------------------------                                                           //
|        LINK'S POCKET         |                                                           //
------------------------------*/                                                           //
string_view linksPocketDefault =        "Link will start with the default inventory: \n"   //
                                        "Deku Mask, Ocarina of Time, Bombers Notebook, \n" //
                                        "Song of Healing, Kokiri Sword, and Heros Shield"; //
string_view linksPocketDungeonReward  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will start with a Dungeon Reward in his "    //
                                        "inventory.";                                      //
string_view linksPocketAdvancement    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will receive a random advancement item at the"
                                        "beginning of the playthrough.";                   //
string_view linksPocketAnything       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will receive a random item from the item pool"
                                        "at the beginning of the playthrough.";            //
string_view linksPocketNothing        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will start with a very useful green rupee."; //


/*------------------------------                                                           //
|         SHOPSANITY           |                                                           //
------------------------------*/                                                           //
string_view shopsOff                  = "All shop items will be the same as vanilla.";     //
string_view shopsZero                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops.";                                //
string_view shopsOne                  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "one non-vanilla shop item.";                      //
string_view shopsTwo                  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "two non-vanilla shop items.";                     //
string_view shopsThree                = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "three non-vanilla shop items.";                   //
string_view shopsFour                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "four non-vanilla shop items.";                    //
string_view shopsRandom               = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "1-4 non-vanilla shop items.";                     //
/*------------------------------                                                           //
|         TOKENSANITY          |                                                           //
------------------------------*/                                                           //
string_view tokensOff                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "GS locations will not be shuffled.";              //
string_view tokensDungeon             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "GS tokens will appear only in dungeons";          //
string_view tokensOverworld           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "This only shuffles the GS locations that are\n"   //
                                        "outside of dungeons.";                            //
string_view tokensAllTokens           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Effectively adds 60 new locations for items to\n"//
                                        "appear.";                                         //
                                                                                           //
/*------------------------------                                                           //
|        SCRUB SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view scrubsOff                 = "Deku Scrub Salesmen will not be randomized";      //
string_view scrubsAffordable          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be reduced to 10 rupees each";
string_view scrubsExpensive           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be their vanilla prices.\n";//
string_view scrubsRandomPrices        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be between 0-95 rupees. This"
                                        "will on average be very, very expensive overall.";//
/*------------------------------                                                           //
|         SHUFFLE COWS         |                                                           //
------------------------------*/                                                           //
string_view shuffleCowsDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this will let cows give you items upon\n"//
                                        "performing Epona's song in front of them. There\n"//
                                        "are 8 cows";                                      //
                                                                                           //
/*------------------------------                                                           //
|       SHUFFLE OCARINAS       |                                                           //
------------------------------*/                                                           //
string_view ocarinasDesc              = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this shuffles the Ocarina of Time into \n"//
                                        "the item pool."        					       //
                                        "\n"                                               //
                                        "This will require finding an Ocarina before being\n"
                                        "able to play songs. or restart the days";         //

/*------------------------------                                                           //
|        FREE SCARECROW        |                                                           //
------------------------------*/                                                           //
string_view freeScarecrowDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Pulling out the Ocarina near a spot at which\n"   //
                                        "Pierre can spawn will do so, without needing\n"   //
                                        "the song.";                                       //


/*------------------------------                                                           //
|       DAMAGE MULTIPLIER      |                                                           //
------------------------------*/                                                           //
string_view damageMultiDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes the amount of damage taken.\n"            //
                                        "\n"                                               //
                                        "If set to OHKO, Link will die in one hit.";       //

/*------------------------------                                                           //
|       CHEST ANIMATIONS       |                                                           //
------------------------------*/                                                           //
string_view chestAnimDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Choose if you want the slow animation to play\n"  //
                                        "if a chest contains a major item.\n";             //
                                                                                           //
/*------------------------------                                                           //
|     CHEST SIZE AND COLOR     |                                                           //
------------------------------*/                                                           //
string_view chestSizeDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "This option will change the appearance of all\n"  //
                                        "regular chests depending on their contents:\n"    //
                                        "Major Items    =    Big Gold Trimmed Chests\n"    //
                                        "Lesser Items   =    Small Gold Trimmed Chests\n"  //
                                        "Boss Keys      =    Big Fancy Chests\n"           //
                                        "Small Keys     =    Small Fancy Chests";          //
                                                                                           //



/*------------------------------                                                           //
|         COLORED KEYS         |                                                           //
------------------------------*/                                                           //
string_view coloredKeysDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "If set, small key models will be colored\n"       //
                                        "differently depending on which dungeon they can be"
                                        "used in. Forest Temple keys are green. Fire Temple"
                                        "keys are red. etc.";                              //
string_view coloredBossKeysDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "If set, boss key models will be colored\n"        //
                                        "differently depending on which dungeon they can be"
                                        "used in. The Forest Temple boss key is green. The "
                                        "Fire Temple boss key is red. etc.";               //
/*------------------------------                                                           //
|        SHUFFLE MUSIC         |                                                           //
------------------------------*/                                                           //
string_view musicRandoDesc           = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Randomize the music in the game";                  //
string_view shuffleBGMDesc           = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Randomize area background music";                  //
string_view fanfaresOffDesc          = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares are not shuffled.";                       //
string_view onlyFanfaresDesc         = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares and ocarina songs are shuffled in\n"      //
                                       "separate pools.";                                  //
string_view fanfaresOcarinaDesc      = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares and ocarina songs are shuffled together\n"//
                                       "in the same pool.";                                //
string_view shuffleOcaMusicDesc      = "**OPTION CURRENTLY WIP**\n"                        //
                                       "The music that plays back after you play an ocarina"
                                       "song is randomized";                               //
                                                                                           //
/*------------------------------                                                           //
|      RESTORATION OPTIONS     |                                                           //
------------------------------*/                                                           //
string_view fastZoraSwimDesc         = "Enables Fast Zora Swimming without magic.";        //
string_view ocarinaDiveDesc          = "Enables Ocarina Diving";                           //
string_view dpadMaskDesc             = "Enables using the 3 D-Pad buttons to use\n"        //
                                       "transformation masks. This option will also\n"     //
                                       "patch using Down A with Mask Storage.";            //
string_view dpadOcarinaDesc          = "Enables using D-Pad down to activate your\n"       //
                                       "ocarina.";                                         //
string_view dpadArrowDesc            = "Enables using D-Pad up to change your current\n"   //
                                       "arrow that is being used.";                        //
                                                                                           //
/*-------------------------------                                                          //
|   CUSTOM BUTTON MAPPING       |                                                          //
-------------------------------*/                                                          //
string_view customMapButtonDesc      = "Change the button to open the Map.\n"              //
                                       "Default is Touch Screen";                          //
string_view customItemsButtonDesc    = "Change the button to open the Items Menu\n"        //
                                       "Default is Touch Screen";                          //
string_view customMasksButtonDesc    = "Change the button to open the Masks Menu\n"        //
                                       "Default is Touch Screen";                          //
string_view customNotebookDesc       = "Change the button to open the Bomber's Notebook\n" //
                                       "Default is Start";                                 //
string_view ingameSpoilersButtonDesc = "Change the button to open the ingame Spoiler Log\n"//
                                       "Default is Select";                                //
/*-------------------------------                                                          //
|     BOMBERS MINIGAME SKIP     |                                                          //
-------------------------------*/                                                          //
string_view skipBombersMinigameDesc  = "Skip Bomber's Minigame to get the code.\n"         //
                                       "Sets the code to 12345.";                          //

/*------------------------------                                                                           //
|           GLITCHES           |                                                                           //
------------------------------*/                                                                           //
const std::vector<string_view> GlitchDifficulties{"Novice", "Intermediate", "Advanced", "Expert", "Hero"};

/*------------------------------                                                                           //
|       CUTSCENE OPTIONS       |                                                                           //
------------------------------*/  
string_view skipHMSCutsceneDesc     = "Skips the initial Happy Mask Salesman's cutscenes"; //
string_view skipDarmaniCutsceneDesc = "Skips the Song of Healing Cutscene for Darmani";    //
string_view skipMikauCutsceneDesc   = "Skips the Song of Healing Cutscene for Mikau";      //