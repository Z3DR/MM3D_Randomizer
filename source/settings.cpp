#include "settings.hpp"

#include <unistd.h>

#include "cosmetics.hpp"
#include "dungeon.hpp"
#include "fill.hpp"
#include "item_location.hpp"
//#include "music.hpp"
#include "random.hpp"
#include "version.hpp"
#include "setting_descriptions.hpp"
#include "system.hpp"
#include "keys.hpp"
//#include "../mm3dr/code/include/game/pad.h"

using namespace Cosmetics;
using namespace Dungeon;
using namespace rnd;
using namespace game::pad;
//using namespace Music;

namespace Settings {
  std::string seed;
  std::string version = RANDOMIZER_VERSION "-" COMMIT_NUMBER;
  std::array<u8, 5> hashIconIndexes;


  std::vector<std::string> bottleOptions = { "None", "Empty Bottle", "Red Potion", "Green Potion", "Blue Potion", "Fairy", "Deku Princess", "Milk", "Half Milk", "Fish", "Bugs", "Big Poe", "Spring Water", "Hot Spring Water", "Zora Egg", "Gold Dust", "Mushroom", "Seahorse", "Chateau Romani", "Mystery Milk", "Spoiled Mystery Milk" };
  std::vector<std::string> healthOptions = { "3 hearts",  "4 hearts",  "5 hearts",  "6 hearts",  "7 hearts",  "8 hearts",  "9 hearts", "10 hearts", "11 hearts", "12 hearts", "13 hearts", "14 hearts", "15 hearts", "16 hearts", "17 hearts", "18 hearts", "19 hearts", "20 hearts" };//,  "1 heart",   "2 hearts"}; // TODO: logic for lower health
  std::vector<std::string> buttonOptions = { "Default", "Start", "Select", "Start + Select", "L + Start", "L + Select", "R + Start", "R + Select", "L + ZL", "L + ZR", "R + ZL", "R + ZR", "ZL + ZR", "ZL + Start", "ZL + Select", "ZR + Start", "ZR + Select"};//L+R not included as its too easy to accidentally do in normal gameplay, can be added later

  //Function to avoid accidentally naming the options wrong, as logic.cpp requires these exact names
  std::vector<std::string> GlitchDifficultyOptions(u8 enabledDifficulties) {
      static constexpr std::array glitchDifficulties{ "Novice", "Intermediate", "Advanced", "Expert", "Hero" };

      std::vector<std::string> selectableDifficulties;
      selectableDifficulties.push_back("Disabled");
      for (size_t i = 0; i < glitchDifficulties.size(); i++) {
          if ((enabledDifficulties >> i) & 1) {
              selectableDifficulties.push_back(glitchDifficulties[i]);
          }
      }

      return selectableDifficulties;
  }
  //                                Setting name,              Options,                                                                     Setting Descriptions (assigned in setting_descriptions.cpp)                                                 Category (default: Setting),Default index (default: 0), Default hidden (default: false)
  Option LinksPocketItem = Option::U8("Link's Pocket", { "Dungeon Reward", "Advancement", "Anything", "Nothing" }, { linksPocketDungeonReward, linksPocketAdvancement, linksPocketAnything, linksPocketNothing });

  /*MAIN SETTINGS*/
  
  //Custom Button Mapping
  Option CustomMapButton      = Option::U8("Map",              { buttonOptions }, { customMapButtonDesc },      OptionCategory::Setting, 0);
  Option CustomItemsButton    = Option::U8("Items",            { buttonOptions }, { customItemsButtonDesc },    OptionCategory::Setting, 0);
  Option CustomMasksButton    = Option::U8("Masks",            { buttonOptions }, { customMasksButtonDesc },    OptionCategory::Setting, 0);
  Option CustomNotebookButton = Option::U8("Bombers Notebook", { buttonOptions }, { customNotebookDesc },       OptionCategory::Setting, 1);
  Option IngameSpoilersButton = Option::U8("Ingame Spoiler Log",{ buttonOptions }, { ingameSpoilersButtonDesc }, OptionCategory::Setting, 2);

  std::vector<Option *> customButtons = {
    &CustomMapButton,
    &CustomItemsButton,
    &CustomMasksButton,
    &CustomNotebookButton,
    &IngameSpoilersButton, 
  };
  
  //Mode/Logic Settings
  Option Logic = Option::U8("Logic", { "Glitchless", "No Logic", "Vanilla", "Glitched" }, { logicGlitchless, logicNoLogic, logicVanilla, logicGlitched },OptionCategory::Setting, (u8)LogicSetting::LOGIC_GLITCHLESS);
  Option LocationsReachable = Option::Bool("All Locations Reachable", { "Off", "On" }, { locationsReachableDesc }, OptionCategory::Setting, 1); //All Locations Reachable On
  std::vector<Option*> logicOptions = {
    &Logic,
    &LocationsReachable,
  };

  //Game Settings
  Option GenerateSpoilerLog   = Option::Bool("Generate Spoiler Log",   { "No", "Yes" },                                                         { genSpoilerLogDesc },                                                                        OptionCategory::Setting, 1); // On
  Option IngameSpoilers       = Option::Bool("Ingame Spoilers",        { "Hide", "Show" },                                                      { ingameSpoilersHideDesc, ingameSpoilersShowDesc });
  Option RegionSelect         = Option::Bool("Game Region",            { "NA", "EU" },                                                          { NARegionDesc, EURegionDesc });
  Option PlayOption           = Option::U8  ("Console/Emulator",       { "3DS", "Citra" },                                                      { "How will you Play?" });
  Option LanguageSelect       = Option::U8  ("  Language",             { "", "", "English", "Francais", "Espanol", "Deutsch", "Italiano", "" }, { LanguageDesc });
  Option Version              = Option::U8  ("Version",                { "1.0", "1.1" },                                                        { VersionDesc });
  std::vector<Option *> gameOptions = {
    &PlayOption,
    &Version,
    &GenerateSpoilerLog,
    &IngameSpoilers,
    &RegionSelect,
    &LanguageSelect,
  };
  //TODO MM3D LOGIC TRICKS
  //Function to make defining logic tricks easier to read
  //Option LogicTrick(std::string setting, std::string_view description) {
  //    return Option::Bool(setting, { "Disabled", "Enabled" }, { description });
  //};
  
  //Detailed Logic Tricks                               ---------------------
  Option ToggleAllTricks                  = Option::U8("All Tricks", {"None", "Novice", "Intermediate", "Expert"},  {ToggleLogicNoneDesc, ToggleLogicNoviceDesc, ToggleLogicIntermediateDesc, ToggleLogicExpertDesc},                                           OptionCategory::Toggle, 0);
  //Option LogicGrottosWithoutAgony         = LogicTrick(" Grotto Access\n   w/o Shard of Agony",       LogicGrottosWithoutAgonyDesc);
  std::vector<Option *> trickOptions = {
    &ToggleAllTricks
    //&LogicGrottosWithoutAgony,
   };
    /*To-Do Glitches*/
  Option FakeGlitch = Option::U8("Fake Glitch", { "Fake" }, { "This Is Here to not break things" });
  std::vector<Option *> glitchOptions = {
      &FakeGlitch,
  };

  //Starting Inventory Toggles
  Option StartingConsumables       = Option::Bool("Start with Consumables", { "No",               "Yes" },                                                     { startWithConsumablesDesc });
  Option StartingMaxRupees         = Option::Bool("Start with Max Rupees",  { "No",               "Yes" },                                                     { startWithMaxRupeesDesc });
  Option StartingInventoryToggle   = Option::U8("Inventory",                { "All Off",          "All On",           "Choose" },                              { "" });
  Option StartingNutCapacity       = Option::U8("  Deku Nuts",              { "None",             "20 Deku Nuts",     "30 Deku Nuts",     "40 Deku Nuts" },    { "" });
  Option StartingOcarina           = Option::U8("  Ocarina",                { "Ocarina of Time",  "Ocarina of Time" },                                         { "" }, OptionCategory::Toggle, 1);
  Option StartingBombBag           = Option::U8("  Bomb Bag",               { "None",             "Bomb Bag 20",      "Bomb Bag 30",      "Bomb Bag 40" },     { "" });
  Option StartingBombchus          = Option::U8("  Bombchus",               { "None",             "Bombchus" },                                                { "" });
  Option StartingHookshot          = Option::U8("  Hookshot",               { "None",             "Hookshot" },                                                { "" });
  Option StartingBow               = Option::U8("  Bow",                    { "None",             "Bow + Quiver 30",  "Bow + Quiver 40",  "Bow + Quiver 50" }, { "" });
  Option StartingFireArrows        = Option::U8("  Fire Arrow",             { "None",             "Fire Arrow" },                                              { "" });
  Option StartingIceArrows         = Option::U8("  Ice Arrow",              { "None",             "Ice Arrow" },                                               { "" });
  Option StartingLightArrows       = Option::U8("  Light Arrow",            { "None",             "Light Arrow" },                                             { "" });
  Option StartingLensOfTruth       = Option::U8("  Lens of Truth",          { "None",             "Lens of Truth" },                                           { "" });
  Option StartingMagicBean         = Option::U8("  Magic Beans",            { "None",             "Magic Beans" },                                             { "" });
  Option StartingBottle1           = Option::U8("  Bottle Slot 1",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle2           = Option::U8("  Bottle Slot 2",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle3           = Option::U8("  Bottle Slot 3",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle4           = Option::U8("  Bottle Slot 4",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle5           = Option::U8("  Bottle Slot 5",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle6           = Option::U8("  Bottle Slot 6",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingBottle7           = Option::U8("  Bottle Slot 7",          bottleOptions,                                                                     { "" }, OptionCategory::Setting, (u8)StartingBottleSetting::STARTINGBOTTLE_NONE);
  Option StartingSongsToggle       = Option::U8("Ocarina Songs",            { "All Off",          "All On",           "Choose" },                              { "" });
  Option StartingOathToOrder       = Option::U8("  Oath To Order",          { "None",             "Oath to Order" },                                           { "" });
  Option StartingEponasSong        = Option::U8("  Epona's Song",           { "None",             "Epona's Song" },                                            { "" });
  Option StartingSongOfStorms      = Option::U8("  Song of Storms",         { "None",             "Song of Storms" },                                          { "" });
  Option StartingSonataOfAwakening = Option::U8("  Sonata of Awakening",    { "None",             "Sonata of A." },                                            { "" });
  Option StartingGoronsLullaby     = Option::U8("  Gorons Lullaby",         { "None",             "Gorons Lullaby" },                                          { "" });
  Option StartingNewWaveBossaNova  = Option::U8("  New Wave Bossa Nova",    { "None",             "New Wave Bossa Nova" },                                     { "" });
  Option StartingElegyOfEmptiness  = Option::U8("  Elegy of Emptiness",     { "None",             "Elegy of Emptiness" },                                      { "" });
  Option StartingSongOfHealing     = Option::U8("  Song of Healing",        { "None",             "Song of Healing" },                                         { "" }, OptionCategory::Setting);
  Option StartingSongOfSoaring     = Option::U8("  Song of Soaring",        { "None",             "Song of Soaring" },                                         { "" });
  Option StartingUpgradesToggle    = Option::U8("Equipment & Upgrades",     { "All Off",          "All On",           "Choose" },                              { "" });
  Option StartingKokiriSword       = Option::U8("  Sword",                  { "Kokiri Sword",     "Razor Sword", "Gilded Sword", "None" },                     { "" }, OptionCategory::Setting, (u8)StartingSwordSetting::STARTINGSWORD_KOKIRI);//1U = StartingSwordSetting::STARTINGSWORD_KOKIRI
  Option StartingGreatFairySword   = Option::U8("  Great Fairy Sword",      { "None",             "G. F. S." },                                                { "" });
  Option StartingShield            = Option::U8("  Shield",                 { "Hero's Shield",    "Mirror Shield", "None" },                                   { "" }, OptionCategory::Setting, (u8)StartingSheildSetting::STARTINGSHIELD_HERO);//1U = StartingShieldSetting::STARTINGSHIELD_HERO
  Option StartingWallet            = Option::U8("  Wallet Upgrade",         { "None",             "Adult's Wallet",   "Giant's Wallet" ,  "Tycoon's Wallet" }, { "" }, OptionCategory::Setting, (u8)StartingWalletSetting::STARTINGWALLET_NONE);
  Option StartingHealth            = Option::U8("  Health",                 healthOptions,                                                                     { "" });
  Option StartingMagicMeter        = Option::U8("  Magic Meter",            { "None",             "Single Magic",     "Double Magic" },                        { "" });
  Option StartingDoubleDefense     = Option::U8("  Double Defense",         { "None",             "Double Defense" },                                          { "" });
  Option StartingQuestToggle       = Option::U8("Quest Items",              { "All Off",          "All On",           "Choose" },                              { "" });
  Option StartingOdolwaRemains     = Option::U8("  Odolwa's Remains",       { "None",             "Odolwa's R." },                                             { "" });
  Option StartingGohtRemains       = Option::U8("  Goht's Remains",         { "None",             "Goht's R." },                                               { "" });
  Option StartingGyorgRemains      = Option::U8("  Gyorg's Remains",        { "None",             "Gyorg's R." },                                              { "" });
  Option StartingTwinmoldRemains   = Option::U8("  Twinmold's Remains",     { "None",             "TwinMold's R." },                                           { "" });
  Option StartingSwampToken        = Option::U8("Swamp Skulltula Tokens",   {/*Options 0-30 defined in InitSettings()*/ },                                     { "" }, OptionCategory::Setting, 0, false);
  Option StartingOceanToken        = Option::U8("Ocean Skulltula Tokens",   {/*Options 0-30 defined in InitSettings()*/ },                                     { "" }, OptionCategory::Setting, 0, false);
  //Starting Masks 
  Option StartingMaskToggle        = Option::U8("Masks",                    { "All Off",          "All On",           "Choose" },                              { "" });
  Option StartingDekuMask          = Option::U8("  Deku Mask",              { "None",             "Deku M." },                                                 { "" });
  Option StartingGoronMask         = Option::U8("  Goron Mask",             { "None",             "Goron M." },                                                { "" });
  Option StartingZoraMask          = Option::U8("  Zora Mask",              { "None",             "Zora M." },                                                 { "" });
  Option StartingBunnyHood         = Option::U8("  Bunny Hood",             { "None",             "Bunny H." },                                                { "" });
  Option StartingKeatonMask        = Option::U8("  Keaton Mask",            { "None",             "Keaton M." },                                               { "" });
  Option StartingPostmanHat        = Option::U8("  Postman's Hat",          { "None",             "Postman's H." },                                            { "" });
  Option StartingAllNightMask      = Option::U8("  All-Night Mask",         { "None",             "All-Night M." },                                            { "" });
  Option StartingBlastMask         = Option::U8("  Blast Mask",             { "None",             "Blast M." },                                                { "" });
  Option StartingStoneMask         = Option::U8("  Stone Mask",             { "None",             "Stone M." },                                                { "" });
  Option StartingGreatFairyMask    = Option::U8("  Great Fairys Mask",      { "None",             "G.F M." },                                                  { "" });
  Option StartingBremenMask        = Option::U8("  Bremen Mask",            { "None",             "Bremen M." },                                               { "" });
  Option StartingDonGeroMask       = Option::U8("  Don Gero's Mask",        { "None",             "DonGero M." },                                              { "" });
  Option StartingMaskOfScents      = Option::U8("  Mask of Scents",         { "None",             "Scents M." },                                               { "" });
  Option StartingRomanisMask       = Option::U8("  Romani's Mask",          { "None",             "Romani M." },                                               { "" });
  Option StartingCircusLeaderMask  = Option::U8("  Circus Leader's Mask",   { "None",             "T.L M." },                                                  { "" });
  Option StartingKafeiMask         = Option::U8("  Kafei Mask",             { "None",             "Kafei M." },                                                { "" });
  Option StartingCouplesMask       = Option::U8("  Couples Mask",           { "None",             "Couples M." },                                              { "" });
  Option StartingKamarosMask       = Option::U8("  Kamaro's Mask",          { "None",             "Kamaros M." },                                              { "" });
  Option StartingGibdosMask        = Option::U8("  Gibdos Mask",            { "None",             "Gibdos M." },                                               { "" });
  Option StartingGaroMask          = Option::U8("  Garo Mask",              { "None",             "Garo M."},                                                  { "" });
  Option StartingCaptainsHat       = Option::U8("  Captain's Mask",         { "None",             "Captains M." },                                             { "" });
  Option StartingGiantsMask        = Option::U8("  Giants Mask",            { "None",             "Giants M." },                                               { "" });
  Option StartingFierceDeityMask   = Option::U8("  Fierce Deity Mask",      { "None",             "F.D M." },                                                  { "" });
  Option StartingMaskOfTruth       = Option::U8("  Mask of Truth",          { "None",             "Truth M." },                                                { "" });
  Option StartingStickCapacity     = Option::U8("  Stick Capacity",         { "None", "10 Sticks", "20 Sticks", "30 Sticks" },                                 { "" });
  Option StartingPictographBox     = Option::U8("  Pictograph Box",         { "None",             "PictoBox" },                                                { "" });
  Option StartingPowderKeg         = Option::U8("  Powder Keg",             { "None",             "Powder Keg" },                                              { "" });
  //Option StartingRazorSword = Option::U8(" Razor Sword", { "None", "R. Sword" }, { "" });
  //Option StartingGildedSword = Option::U8(" Gilded Sword", { "None", "G. Sword" }, { "" });
//  Option StartingInvertedSong = Option::U8("  Inverted Song of Time", { "None",             "I. Song of Time" }, { "" });
//  Option StartingDoubleSong = Option::U8("  Song of Double Time", { "None",             "Song of D. Time" }, { "" });
//  Option StartingSongOfTime = Option::U8("  Song of Time", { "None",             "Song of Time" }, { "" });
  
  std::vector<Option*> startingInventoryOptions = {
    &StartingConsumables,
    &StartingMaxRupees,
    &StartingInventoryToggle,
    &StartingStickCapacity,
    &StartingNutCapacity,
    &StartingOcarina,
    &StartingBombBag,
    &StartingBombchus,
    &StartingHookshot,
    &StartingBow,
    &StartingFireArrows,
    &StartingIceArrows,
    &StartingLightArrows,
    &StartingLensOfTruth,
    &StartingMagicBean,
    &StartingPictographBox,
    &StartingPowderKeg,
    &StartingGreatFairySword,
    &StartingBottle1,
    &StartingBottle2,
    &StartingBottle3,
    &StartingBottle4,
    &StartingBottle5,
    &StartingBottle6,
    &StartingBottle7,
    &StartingMaskToggle,
    &StartingDekuMask,
    &StartingGoronMask,
    &StartingZoraMask,
    &StartingBunnyHood,
    &StartingKeatonMask,
    &StartingPostmanHat,
    &StartingAllNightMask,
    &StartingBlastMask,
    &StartingStoneMask,
    &StartingGreatFairyMask,
    &StartingBremenMask,
    &StartingDonGeroMask,
    &StartingMaskOfScents,
    &StartingRomanisMask,
    &StartingCircusLeaderMask,
    &StartingKafeiMask,
    &StartingCouplesMask,
    &StartingKamarosMask,
    &StartingGibdosMask,
    &StartingGaroMask,
    &StartingCaptainsHat,
    &StartingGiantsMask,
    &StartingFierceDeityMask,
    &StartingMaskOfTruth,
    &StartingSongsToggle,
    &StartingOathToOrder,
    &StartingEponasSong,
    &StartingSongOfStorms,
    &StartingSonataOfAwakening,
    &StartingGoronsLullaby,
    &StartingNewWaveBossaNova,
    &StartingElegyOfEmptiness,
    &StartingSongOfHealing,
    &StartingSongOfSoaring,
    &StartingUpgradesToggle,
    &StartingKokiriSword,
    &StartingShield,
    &StartingWallet,
    &StartingHealth,
    &StartingMagicMeter,
    &StartingDoubleDefense,
    &StartingQuestToggle,
    &StartingOdolwaRemains,
    &StartingGohtRemains,
    &StartingGyorgRemains,
    &StartingTwinmoldRemains,
    //&StartingSwampToken,
    //&StartingOceanToken,
    
  };

  //Excluded Locations (Individual definitions made in ItemLocation class)
  std::vector<Option*> excludeLocationsOptions = {};

  //Overworld Shuffle Settings
  Option ShuffleMainInventory   = Option::Bool("Shuffle Starting Gear", {"Off", "On"},                                       {shuffleMainInventoryDesc},                                             OptionCategory::Toggle,   1);
  Option ShuffleKokiriSword     = Option::Bool("Shuffle Kokiri Sword",  {"Off", "On"},                                       {kokiriSwordDesc});
  Option ShuffleStartingShield  = Option::Bool("Starting Shield",       {"Off", "On"},                                       {shuffleStartShield});
  Option ShuffleMasks           = Option::Bool("Shuffle Masks",         {"Off", "On"},                                       {shuffleMasksVanilla, shuffleMasksRandom},                              OptionCategory::Toggle,   1);
  Option ShuffleTransformation  = Option::Bool("Shuffle Transformation",{"Off", "On"},                                       {shuffleTransformationDesc});
  Option ShufflePiecesOfHeart   = Option::Bool("Shuffle Piece of Heart",{"Off", "On"},                                       {shufflePiecesOfHeartDesc },                                            OptionCategory::Toggle,   1);
  Option ShuffleSongs           = Option::U8  ("Shuffle Songs",         {"Off", "Dungeon Rewards", "Anywhere"},              {songsSongLocations, songsDungeonRewards, songsAllLocations},           OptionCategory::Setting, (u8)SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS);
  Option ShuffleSoaring         = Option::Bool("Shuffle SoS",           {"Off", "On"},                                       {shuffleSoaringVanilla, shuffleSoaringRandom});
  Option Shopsanity             = Option::U8  ("Shopsanity",            {"Off", "0", "1", "2", "3", "4", "Random"},          {shopsOff, shopsZero, shopsOne, shopsTwo, shopsThree, shopsFour, shopsRandom});
  Option Tokensanity            = Option::Bool("Tokensanity",           {"Off", "On"},                                       {tokensOff, tokensAllTokens});
  Option Scrubsanity            = Option::U8  ("Shuffle Scrub Wares",   {"Off", "Affordable", "Expensive", "Random Prices"}, {scrubsOff, scrubsAffordable, scrubsExpensive, scrubsRandomPrices});
  Option ShuffleMerchants       = Option::Bool("Shuffle Scrub Trades",  {"Off", "On"},                                       {shuffleMerchantsDesc});
  Option ShuffleTradeItems      = Option::Bool("Shuffle Anju & Kafei",  {"Off", "On"},                                       {shuffleTradeItemsDesc});
  Option ShuffleGFRewards       = Option::U8  ("Shuffle Fairy Rewards", {"Off", "Great Fairies", "Anywhere" },               {shuffleGFVanilla, shuffleGFSelf, shuffleGFAnywhere},                   OptionCategory::Setting, (u8)GreatFairyRewardShuffleSetting::GFREWARDSHUFFLE_VANILLA);
  Option ShuffleCows            = Option::Bool("Shuffle Cows",          {"Off", "On"},                                       {shuffleCowsDesc});
  Option ShuffleOcarinas        = Option::Bool("Shuffle Ocarina",       {"Off", "On"},                                       {ocarinasDesc});
  Option ShuffleTingleMaps      = Option::Bool("Shuffle Tingle Maps",   {"Off", "On"},                                       {shuffleTingleMapsDesc});
  Option ShuffleMagicBeans      = Option::Bool("Shuffle Magic Beans",   {"Off", "On"},                                       {magicBeansDesc});
  Option ShuffleBombersNotebook = Option::Bool("Shuffle Notebook",      {"Off", "On"},                                       {shuffleBombersNotebookDesc});
  Option ShuffleMoonItems       = Option::Bool("Shuffle Moon Items",    {"Off", "On"},                                       {shuffleMoonItemsDesc});
  Option ShuffleFierceDeity     = Option::Bool("Shuffle Fierce Deity",  {"Off", "On"},                                       {shuffleFierceDeityDesc});
  std::vector<Option*> shuffleItemOptions = {
      &ShuffleMainInventory,
      //&ShuffleKokiriSword, --redundant
      //&ShuffleStartingShield, --redundant
      &ShuffleMasks,
      &ShuffleTransformation,
      &ShufflePiecesOfHeart,
      //&ShuffleSongs,
      //&ShuffleSoaring,
      //&Shopsanity,
      //&Tokensanity,
      &ShuffleMerchants,
      &ShuffleTradeItems,
      &ShuffleGFRewards,
      //&ShuffleCows,
      //&ShuffleOcarinas,
      &ShuffleTingleMaps,
      //&ShuffleMagicBeans,
      &ShuffleBombersNotebook,
      &ShuffleMoonItems,
      &ShuffleFierceDeity,
  };
  //Shuffle Dungeon Items
  Option RandomizeDungeon       = Option::U8("Randomize Settings", { "No","Yes"},                                                                      { dungeonRandomize},                                                                                                             OptionCategory::Toggle);
  Option MapsAndCompasses       = Option::U8("Maps/Compasses",     { "Vanilla", "Start With", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" }, { mapCompassVanilla, mapCompassStartWith, mapCompassOwnDungeon, mapCompassAnyDungeon, mapCompassOverworld, mapCompassAnywhere }, OptionCategory::Setting, (u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_VANILLA);
  Option Keysanity              = Option::U8("Small Keys",         { "Vanilla", "Start With", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" }, { smallKeyVanilla, smallKeyStartWith, smallKeyOwnDungeon, smallKeyAnyDungeon, smallKeyOverworld, smallKeyAnywhere },             OptionCategory::Setting, (u8)KeysanitySetting::KEYSANITY_VANILLA);
  Option BossKeysanity          = Option::U8("Boss Keys",          { "Vanilla", "Start With", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" }, { bossKeyVanilla, bossKeyStartWith, bossKeyOwnDungeon, bossKeyAnyDungeon, bossKeyOverworld, bossKeyAnywhere },                   OptionCategory::Setting, (u8)BossKeysanitySetting::BOSSKEYSANITY_VANILLA);
  Option StrayFairysanity       = Option::U8("Stray Fairies",      { "Vanilla", "Start With", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere" }, { fairyVanilla, fairyStartWith, fairyOwnDungeon, fairyAnyDungeon, fairyOverworld, fairyAnywhere },                               OptionCategory::Setting, (u8)StrayFairySanitySetting::STRAYFAIRYSANITY_VANILLA);
  Option ShuffleRewards         = Option::U8("Dungeon Rewards",    { "End of Dungeons", "Any Dungeon", "Overworld", "Anywhere" },                      { shuffleRewardsEndOfDungeon, shuffleRewardsAnyDungeon, shuffleRewardsOverworld, shuffleRewardsAnywhere });
  Option ShuffleHeartContainers = Option::Bool("Heart Containers", { "Vanilla", "Random"},                                                             { shuffleHeartContainersDesc });

  std::vector<Option*>dungeonSettingsOptions = {
    &RandomizeDungeon,
    &MapsAndCompasses,
    &Keysanity,
    &BossKeysanity,
    //&StrayFairysanity,
    //&ShuffleRewards,
    &ShuffleHeartContainers,
  };

  //Item Pool Settings 
  Option ItemPoolValue          = Option::U8  ("Item Pool",             {"Plentiful", "Balanced", "Scarce", "Minimal" },   {itemPoolPlentiful, itemPoolBalanced, itemPoolScarce, itemPoolMinimal }, OptionCategory::Setting, (u8)ItemPoolSetting::ITEMPOOL_BALANCED);
  Option RemoveDoubleDefense    = Option::Bool("Remove Double Defense", {"No", "Yes"},                                     {removeDDDesc});
  std::vector<Option*>itemPoolSettingsOptions = {
      &ItemPoolValue,
      &RemoveDoubleDefense,
  };

  Option GossipStoneHints     = Option::U8("Gossip Stone Hints",       { "No Hints", "Need Nothing", "Mask of Truth" },    { gossipStonesHintsDesc },                                                     OptionCategory::Setting, (u8)GossipStoneHintsSetting::HINTS_NEED_NOTHING);
  Option ClearerHints         = Option::Bool("  Clearer Hints",        { "Off", "On" },                                    { clearerHintsDesc });
  Option HintDistribution     = Option::U8("  Hint Distribution",      { "Useless", "Balanced", "Strong", "Very Strong" },  { uselessHintsDesc, balancedHintsDesc, strongHintsDesc, veryStrongHintsDesc }, OptionCategory::Setting, 1); // Balanced
  Option DamageMultiplier     = Option::U8("Damage Multiplier",        { "x1/2", "x1", "x2", "x4", "x8", "x16", "OHKO"},    {damageMultiDesc},                                                             OptionCategory::Setting,   (u8)DamageMultiplierSetting::DAMAGEMULTIPLIER_DEFAULT);
  Option ChestAnimations      = Option::Bool("Chest Animations",       { "Always Fast", "Match Contents"},                  {chestAnimDesc});
  Option ChestSize            = Option::Bool("Chest Size and Color",   { "Vanilla", "Match Contents"},                      {chestSizeDesc});
  Option ChangeOverworldItems = Option::Bool("Change Overworld Items", { "Vanilla", "Match Contents" },                     { changeOverworldItemsDesc });
  //Option MenuOpeningButton    = Option::U8("Open Info Menu with",      { "Select","Start","D-Pad Up","D-Pad Down","D-Pad Right","D-Pad Left", }, { menuButtonDesc });
  Option RandomTrapDmg        = Option::U8("Random Trap Damage",       { "Off", "Basic", "Advanced" },                      { randomTrapDmgDesc, basicTrapDmgDesc, advancedTrapDmgDesc });
  Option RsDurability         = Option::U8("Razor Sword Durability",   { "Vanilla", "Infinite" },                           { rsDurabilityVanilla, rsDurabilityInf});
  Option IceTrapValue         = Option::U8("Ice Traps",                { "Off", "Extra", "Mayhem", "Onslaught" },           { iceTrapsOff, iceTrapsExtra, iceTrapsMayhem, iceTrapsOnslaught }, OptionCategory::Setting, (u8)IceTrapSetting::ICETRAPS_OFF);
  Option CompassShowWoTH      = Option::Bool("Compasses Show WotH",    {"Off", "On"},                                       { compassShowWotHDesc});
  Option SkipBombersMinigame  = Option::Bool("Skip Bombers' Minigame", {"Off", "On"},                                       { skipBombersMinigameDesc});

  std::vector<Option*>otherSettingsOptions = {
      &IceTrapValue,
      &SkipBombersMinigame,
      //&RandomTrapDmg,
      &GossipStoneHints,
      &ClearerHints,
      &HintDistribution,
      &CompassShowWoTH,
      //&DamageMultiplier,
      //&ChestAnimations,
      &ChestSize,
      //&ChangeOverworldItems,
      //&MenuOpeningButton,
      //&RsDurability,
  };
  
  /*COMFORT*/

  Option BlastMaskCooldown      = Option::U8("Blast Mask Cooldown",        {"Default", "Short", "Very Short", "Instant"},                        { blastDefault, blastShort, blastVeryShort, blastInstant });
  Option UnderwaterOcarina      = Option::Bool("Underwater Ocarina",       { "No","Yes" },                                                       { underwaterOcarinaDesc },                                                         OptionCategory::Toggle);
  Option FierceDeityAnywhere    = Option::Bool("Fierce Deity Anywhere",    { "No","Yes" },                                                       { fierceDeityAnywhereDesc },                                                       OptionCategory::Toggle);
  Option ProgressiveGildedSword = Option::Bool("Progressive Gilded Sword", { "Off", "On" },                                                      { progressiveGildedSwordDesc });
  Option StartingSpin           = Option::Bool("Starting Spin",            { "Vanilla", "Upgraded" },                                            { startingSpinDesc });
  Option AmmoDrops              = Option::U8("Ammo Drops",                 { "Off", "On" },                                                      { ammoDropDesc });
  Option HeartDropRefills       = Option::U8("Heart Drops",                { "Off", "On" },                                                      { heartDropDesc });
  Option BombchusInLogic        = Option::U8("Bombchus In Logic",          { "Off", "On" },                                                      { bombchuInLogicDesc });

  std::vector<Option*> comfortOptions = {
     
     &BlastMaskCooldown,
     // &UnderwaterOcarina,
     // &FierceDeityAnywhere,
     //&ProgressiveGildedSword,
     // &StartingSpin,
     // &AmmoDrops,
     // &HeartDropRefills,
     //&BombchusInLogic,
  };
 
  //Restoration Settings
  Option SkipMinigamePhases  = Option::Bool("Minigames repetitions",  {"Don't Skip", "Skip"},                                {skipMinigamePhasesDesc});
  Option FastLabFish         = Option::Bool("Fast Lab Fish",          { "No", "Yes" },                                       { fastLabFishDesc });
  Option FastBank            = Option::Bool("Fast Bank Rewards",      { "No", "Yes" },                                       { fastBankDesc });
  Option FastDogRace         = Option::Bool("Fast Dog Race",          { "No", "Yes" },                                       { fastDogRaceDesc });
  Option GoodDampeRNG        = Option::Bool("Good Dampe RNG",         { "No", "Yes" },                                       { goodDampeRNGDesc });
  Option IncreasePushSpeed   = Option::Bool("Increased Push Speed",   { "No", "Yes" },                                       { increasePushSpeedDesc });
  Option FastArrowSwitch     = Option::Bool("Fast Arrow Switching",   { "No", "Yes" },                                       { fastArrowSwitchDesc });
  Option FastElegyStatues    = Option::Bool("Fast Elegy Statues",     { "No", "Yes" },                                       { fastElegyStatuesDesc });
  Option SkipSongReplays     = Option::U8("Skip Song Replays",        { "Don't Skip", "Skip (No SFX)", "Skip (Keep SFX)" },  {skipSongReplaysDesc});
  Option SkipEponaRace       = Option::Bool("Skip Epona Race",        { "No", "Yes" },                                       { skipEponaRaceDesc });
  Option OcarinaDive         = Option::Bool("Ocarina Dive",           { "No", "Yes" },                                       {ocarinaDiveDesc});
  Option FastZoraSwim        = Option::Bool("Fast Zora Swimming",     { "No", "Yes" },                                       {fastZoraSwimDesc});
  Option DpadTransform       = Option::Bool("DPad Transformation",    { "No", "Yes" },                                       {dpadMaskDesc});
  Option DpadOcarina         = Option::Bool("DPad Ocarina",           { "No", "Yes" },                                       {dpadOcarinaDesc});
  Option DpadArrows          = Option::Bool("Dpad Arrow Swap",        { "No", "Yes" },                                       {dpadArrowDesc});
  Option TwinmoldRestoration  = Option::Bool("Twinmold Restoration",   { "No", "Yes" },                                      {twinmoldRestorationDesc});

  std::vector<Option *> restorationOptions = {
    //&SkipMinigamePhases,
    //&FastLabFish,
    //&FastBank,
    //&FastDogRace,
    //&GoodDampeRNG,
    //&IncreasePushSpeed,
    //&FastArrowSwitch,
    &FastElegyStatues,
    &FastZoraSwim,
    &OcarinaDive,
    &DpadTransform,
    &DpadOcarina,
    &DpadArrows,
    &TwinmoldRestoration,
    //&SkipSongReplays,
  };

  //Cutscene Skips
  Option SkipHMSCutscenes     = Option::Bool("Skip HMS Cutscenes",  {"Don't Skip", "Skip"},     {skipHMSCutsceneDesc});
  Option SkipDarmaniCutscenes = Option::Bool("Skip Darmani Cutscenes",  {"Don't Skip", "Skip"}, {skipDarmaniCutsceneDesc});
  Option SkipMikauCutscenes   = Option::Bool("Skip Mikau Cutscenes",  {"Don't Skip", "Skip"},   {skipMikauCutsceneDesc});
  std::vector<Option *> cutsceneOptions = {
    &SkipHMSCutscenes,
    &SkipDarmaniCutscenes,
    &SkipMikauCutscenes
  };

  /*TRIAL SKIPS*/
  Option OdolwaTrialSkip = Option::Bool("Odolwa Trial Skip", { "Don't Skip", "Skip" }, { odolwaTrialSkipDesc });
  Option GohtTrialSkip = Option::Bool("Goht Trial Skip", { "Don't Skip", "Skip" }, { gohtTrialSkipDesc });
  Option GyorgTrialSkip = Option::Bool("Gyorg Trial Skip", { "Don't Skip", "Skip" }, { gyorgTrialSkipDesc });
  Option TwinmoldTrialSkip = Option::Bool("Twinmold Trial Skip", { "Don't Skip", "Skip" }, { twinmoldTrialSkipDesc });

  std::vector<Option *> trialSkipOptions = {
      &OdolwaTrialSkip,
      &GohtTrialSkip,
      &GyorgTrialSkip,
      &TwinmoldTrialSkip,
  };

  /*Entrance Randomizer Stuff*/
  Option ShuffleDungeonEntrances = Option::Bool("Shuffle Dungeon Entrances", { "Off", "On" }, { shuffleDungeonEntrancesDesc });

  /*COSMETICS*/

  static std::vector<std::string> tunicOptions = {
    std::string(RANDOM_CHOICE_STR),
    std::string(RANDOM_COLOR_STR),
    std::string(CUSTOM_COLOR_STR),
    "Kokiri Green",
    "Goron Red",
    "Zora Blue",
    "Black",
    "White",
    "Azure Blue",
    "Vivid Cyan",
    "Light Red",
    "Fuchsia",
    "Purple",
    "Majora Purple",
    "Twitch Purple",
    "Magenta",
    "Violet",
    "Persian Rose",
    "Dirty Yellow",
    "Blush Pink",
    "Hot Pink",
    "Rose Pink",
    "Orange",
    "Gray",
    "Yellow",
    "Silver",
    "Beige",
    "Teal",
    "Blood Red",
    "Blood Orange",
    "Royal Blue",
    "NES Green",
    "Dark Green",
    "Lumen",
  };
  static std::vector<std::string_view> cosmeticDescriptions = {
    RANDOM_CHOICE_DESC,
    RANDOM_COLOR_DESC,
    CUSTOM_COLOR_DESC,
    "This will only affect the color on Link's model.",
  };

  Option CustomTunicColors          = Option::Bool("Custom Tunic Colors",    {"Off", "On"},   {""},  OptionCategory::Cosmetic);
  Option ChildTunicColor = Option::U8("   Tunic Color", { tunicOptions }, cosmeticDescriptions, OptionCategory::Cosmetic, 3); // Kokiri Green
  std::string finalChildTunicColor      = ChildTunicColor.GetSelectedOptionText();

  Option ColoredKeys =     Option::Bool("Colored Small Keys", {"Off", "On"}, {coloredKeysDesc}, OptionCategory::Cosmetic);
  Option ColoredBossKeys = Option::Bool("Colored Boss Keys",  {"Off", "On"}, {coloredBossKeysDesc},  OptionCategory::Cosmetic);

  static std::vector<std::string> fanfareOptions = {"Off", "Only Fanfares", "Fanfares +\n                         Ocarina Music"};
  static std::vector<std::string_view> fanfareDescriptions = {fanfaresOffDesc, onlyFanfaresDesc, fanfaresOcarinaDesc};
  //TO-DO MUSIC RANDO
//  Option ShuffleMusic =    Option::Bool("Shuffle Music",           {"Off", "On"},    {musicRandoDesc},                                                                                                                                                          OptionCategory::Cosmetic,               0); // Off
//  Option ShuffleBGM =      Option::Bool("  Shuffle BGM",           {"Off", "On"},    {shuffleBGMDesc},                                                                                                                                                          OptionCategory::Cosmetic,               1); // On
//  Option ShuffleFanfares = Option::U8  ("  Shuffle Fanfares",      {fanfareOptions}, {fanfareDescriptions},                                                                                                                                                     OptionCategory::Cosmetic,               1); // Fanfares only
//  Option ShuffleOcaMusic = Option::Bool("  Shuffle Ocarina Music", {"Off", "On"},    {shuffleOcaMusicDesc},                                                                                                                                                     OptionCategory::Cosmetic,               1); // On
  
//TO-DO Heart Color, Magic Color, Tatl Color
  std::vector<Option *> cosmeticOptions = {
    &CustomTunicColors,
    &ChildTunicColor,
    &ColoredKeys,
    &ColoredBossKeys,
 //   &ShuffleMusic,
 //   &ShuffleBGM,
 //   &ShuffleFanfares,
 //   &ShuffleOcaMusic,
  };

 
  Menu loadSettingsPreset       = Menu::Action("Load Settings Preset",       LOAD_PRESET);
  Menu saveSettingsPreset       = Menu::Action("Save Settings Preset",       SAVE_PRESET);
  Menu deleteSettingsPreset     = Menu::Action("Delete Settings Preset",     DELETE_PRESET);
  Menu resetToDefaultSettings   = Menu::Action("Reset to Default Settings",  RESET_TO_DEFAULTS);

  std::vector<Menu *> settingsPresetItems = {
    &loadSettingsPreset,
    &saveSettingsPreset,
    &deleteSettingsPreset,
    &resetToDefaultSettings,
  };

  //Main Settings Options Submenu
  Menu logicSettings    = Menu::SubMenu("Logic Options",     &logicOptions);
  Menu tricks = Menu::SubMenu("Logical Tricks", &trickOptions, false);
  Menu startingInventory = Menu::SubMenu("Starting Inventory", &startingInventoryOptions, false);
  Menu excludeLocations = Menu::SubMenu("Exclude Locations", &excludeLocationsOptions, false);
  Menu glitchSettings   = Menu::SubMenu("Glitch Options",    &glitchOptions, false);
  Menu otherSettings = Menu::SubMenu("Other Settings", &otherSettingsOptions, false);
  Menu gameSettings = Menu::SubMenu("Game Settings", &gameOptions);
  
  std::vector<Menu *> detailLogicSettings = {
      //&logicSettings,
      //&tricks,
      &excludeLocations,
      //&glitchSettings,
  };
  

  //Menu mainSettings = Menu::SubMenu("Main Settings", &mainSettingsOptions);
  Menu comfort = Menu::SubMenu("Comfort Settings", &comfortOptions);
  Menu restorationSettings = Menu::SubMenu("Restoration Settings", &restorationOptions);
  Menu cutsceneSettings = Menu::SubMenu("Cutscene Settings", &cutsceneOptions);
  Menu settingsPresets          = Menu::SubMenu("Settings Presets",           &settingsPresetItems);
  Menu cosmetics                = Menu::SubMenu("Cosmetic Settings",          &cosmeticOptions);
  Menu generateRandomizer       = Menu::Action ("Generate Randomizer",        GENERATE_MODE);
  Menu shuffleItems             = Menu::SubMenu("Item Shuffle Settings",      &shuffleItemOptions);
  Menu shuffleDungeon           = Menu::SubMenu("Dungeon Settings",           &dungeonSettingsOptions);
  Menu itemPool                 = Menu::SubMenu("Item Pool Settings",         &itemPoolSettingsOptions);
  Menu detailLogic              = Menu::SubMenu("Detailed Logic Settings",    &detailLogicSettings);
  Menu customInputs             = Menu::SubMenu("Custom Button Mapping",      &customButtons);

  //adding a menu with no options crashes, might fix later
  std::vector<Menu *> mainMenu = {
    &logicSettings,
    &gameSettings,
    &shuffleItems,
    &shuffleDungeon,
    &itemPool,
    &startingInventory,
    &detailLogic,
    &comfort,
    &restorationSettings,
    &cutsceneSettings,
    &otherSettings,
    &customInputs,
    //&cosmetics,
    &settingsPresets,
    &generateRandomizer,
  };

  //declared here, set in fill.cpp
  u32 LinksPocketRewardBitMask = 0;
  std::array<u32, 9> rDungeonRewardOverrides{};

  //declared here, set in menu.cpp
  //u8 PlayOption;
  //u8 Version;

  //Fills and returns a SettingsContext struct.
  //This struct is written to the code.ips patch and allows the game
  //to read what settings the player selected to make in game decisions.
    rnd::SettingsContext FillContext() {
    rnd::SettingsContext ctx = {};
    ctx.hashIndexes[0] = hashIconIndexes[0];
    ctx.hashIndexes[1] = hashIconIndexes[1];
    ctx.hashIndexes[2] = hashIconIndexes[2];
    ctx.hashIndexes[3] = hashIconIndexes[3];
    ctx.hashIndexes[4] = hashIconIndexes[4];

    ctx.playOption = PlayOption.Value<u8>();

///things commented out below here need to be added or match up to SettingsContext in \mm3dr\code\include\rnd\settings.h
    ctx.logic                = Logic.Value<u8>();
    ctx.locationsReachable = (LocationsReachable) ? 1 : 0;
    ctx.linksPocketItem = LinksPocketItem.Value<u8>();

    ctx.shuffleSongs = ShuffleSongs.Value<u8>();
    //ctx.shuffleSoaring = (ShuffleSoaring) ? 1 : 0;
    ctx.shopsanity = Shopsanity.Value<u8>();
    ctx.tokensanity          = (Tokensanity) ? 1:0;
    //ctx.cowsanity = (ShuffleCows) ? 1 : 0;
    ctx.shuffleKokiriSword = (ShuffleKokiriSword) ? 1 : 0;
    ctx.shuffleStartingShield = (ShuffleStartingShield) ? 1 : 0;
    //ctx.shuffleTradeItems = (ShuffleTradeItems)?1:0;
    ctx.shuffleMerchants = (ShuffleMerchants) ? 1 : 0;
    //ctx.removeDoubleDefense = (RemoveDoubleDefense) ? 1 : 0;

    ctx.mapsAndCompasses = MapsAndCompasses.Value<u8>();
    ctx.keysanity = Keysanity.Value<u8>();
    ctx.bossKeysanity = BossKeysanity.Value<u8>();
    //ctx.strayFairysanity = StrayFairysanity.Value<u8>();
    ctx.shuffleRewards = ShuffleRewards.Value<u8>();
    //ctx.shuffleHeartContainers = (ShuffleHeartContainers) ? 1 : 0;

    ctx.itemPoolValue = ItemPoolValue.Value<u8>();
    //ctx.shuffleMainInventory = (ShuffleMainInventory) ? 1 : 0;
    //ctx.shuffleTransformation = (ShuffleTransformation) ? 1 : 0;
    //ctx.shuffleFierceDeity = (ShuffleFierceDeity) ? 1:0;
    //ctx.shuffleMasks = (ShuffleMasks) ? 1 : 0;
    ctx.shuffleGreatFairyRewards = ShuffleGFRewards.Value<u8>();
    //ctx.shufflePiecesOfHeart = (ShufflePiecesOfHeart) ? 1:0;

    ctx.iceTrapValue = IceTrapValue.Value<u8>();
    //ctx.randomTrapDmg = RandomTrapDmg.Value<u8>();
    ctx.maskOfTruthRequiredForGossip = GossipStoneHints.Value<u8>() == 1 ? 0 : 1;
    //ctx.clearHints = (ClearerHints) ? 1 : 0;
    //ctx.hintDistribution = HintDistribution.Value<u8>();
    ctx.damageMultiplier     = DamageMultiplier.Value<u8>();
    ctx.chestAnimations      = (ChestAnimations) ? 1 : 0;
    ctx.chestSize            = (ChestSize) ? 1 : 0;
    //ctx.changeOverworldItems = (ChangeOverworldItems) ? 1 : 0;
    ctx.ingameSpoilers = (IngameSpoilers) ? 1 : 0;
    //ctx.menuOpeningButton = MenuOpeningButton.Value<u8>();
    
    ctx.blastMaskCooldown = BlastMaskCooldown.Value<u8>();
    //ctx.underwaterOcarina = (UnderwaterOcarina) ? 1 : 0;
    //ctx.fierceDeityAnywhere = (FierceDeityAnywhere) ? 1 : 0;
    ctx.skipMinigamePhases = (SkipMinigamePhases) ? 1 : 0;
    ctx.skipEponaRace = (SkipEponaRace) ? 1 : 0;
    //ctx.fastLabFish = (FastLabFish) ? 1 : 0;
    //ctx.fastBank = (FastBank) ? 1 : 0;
    //ctx.fastDogRace = (FastDogRace) ? 1 : 0;
    //ctx.goodDampeRNG = (GoodDampeRNG) ? 1 : 0;
    //ctx.increasePushSpeed = (IncreasePushSpeed) ? 1 : 0;
    //ctx.fastArrowSwitch = (FastArrowSwitch) ? 1 : 0;
    //ctx.fastElegyStatues = (FastElegyStatues) ? 1 : 0;
    //ctx.skipSongReplays = SkipSongReplays.Value<u8>();
    ctx.startingSpinSettting = (StartingSpin) ? 1 : 0;
    ctx.ammoDrops = (AmmoDrops) ? 1 : 0;
    ctx.heartDropRefill = (HeartDropRefills) ? 1 : 0;

    ctx.odolwaTrialSkip = (OdolwaTrialSkip) ? 1 : 0;
    ctx.gohtTrialSkip = (GohtTrialSkip) ? 1 : 0;
    ctx.gyorgTrialSkip = (GyorgTrialSkip) ? 1 : 0;
    ctx.twinmoldTrialSkip = (TwinmoldTrialSkip) ? 1 : 0;

    ctx.shuffleDungeonEntrances = (ShuffleDungeonEntrances) ? 1 : 0;
    
    ctx.customTunicColors = (CustomTunicColors) ? 1 : 0;
    ctx.coloredKeys = (ColoredKeys) ? 1 : 0;
    ctx.coloredBossKeys = (ColoredBossKeys) ? 1 : 0;
    //ctx.shuffleMusic = (ShuffleMusic)?1:0;
    //ctx.shuffleBGM = (ShuffleBGM)?1:0;
    //ctx.shuffleFanfare = ShuffleFanfares.Value<u8>();
    //ctx.shuffleOcaMusic = (ShuffleOcaMusic)?1:0;
    
    //ctx.bombchusInLogic = (BombchusInLogic) ? 1 : 0;
    
    //ctx.scrubsanity          = Scrubsanity.Value<u8>();
    //ctx.shuffleMagicBeans = (ShuffleMagicBeans) ? 1 : 0;
    
    ctx.compassesShowWotH = (CompassShowWoTH) ? 1 : 0;
    ctx.skipBombersMinigame = (SkipBombersMinigame) ? 1 : 0;
    
    ctx.generateSpoilerLog = (GenerateSpoilerLog) ? 1 : 0;
  
    

    
    
    
    //ctx.progressiveGildedSword = (ProgressiveGildedSword) ? 1 : 0;
    

    //Starting Inventory
    ctx.startingConsumables = (StartingConsumables) ? 1 : 0;
    ctx.startingMaxRupees = (StartingMaxRupees) ? 1 : 0;
    ctx.startingNutCapacity = StartingNutCapacity.Value<u8>();
    ctx.startingStickCapacity = StartingStickCapacity.Value<u8>();
    ctx.startingOcarina = StartingOcarina.Value<u8>();
    ctx.startingBombBag = StartingBombBag.Value<u8>();
    ctx.startingBombchus = StartingBombchus.Value<u8>();
    ctx.startingHookshot = StartingHookshot.Value<u8>();
    ctx.startingHerosBow = StartingBow.Value<u8>();
    ctx.startingFireArrows = StartingFireArrows.Value<u8>();
    ctx.startingIceArrows = StartingIceArrows.Value<u8>();
    ctx.startingLightArrows = StartingLightArrows.Value<u8>();
    ctx.startingLensOfTruth = StartingLensOfTruth.Value<u8>();
    ctx.startingMagicBean = StartingMagicBean.Value<u8>();
    ctx.startingPowderKeg = StartingPowderKeg.Value<u8>();
    ctx.startingPictographBox = StartingPictographBox.Value<u8>();
    ctx.startingGreatFairySword = StartingGreatFairySword.Value<u8>();
    //parse starting bottles from index > itemID
    //ctx.startingBottle1 = StartingBottle1.Value<u8>();
    ctx.startingBottle1 = StartingBottleConvert(StartingBottle1.Value<u8>());
    //ctx.startingBottle2 = StartingBottle2.Value<u8>();
    ctx.startingBottle2 = StartingBottleConvert(StartingBottle2.Value<u8>());
    ctx.startingBottle3 = StartingBottleConvert(StartingBottle3.Value<u8>());
    ctx.startingBottle4 = StartingBottleConvert(StartingBottle4.Value<u8>());
    ctx.startingBottle5 = StartingBottleConvert(StartingBottle5.Value<u8>());
    ctx.startingBottle6 = StartingBottleConvert(StartingBottle6.Value<u8>());
    ctx.startingBottle7 = StartingBottleConvert(StartingBottle7.Value<u8>());
    //Songs
    ctx.startingOathToOrder = StartingOathToOrder.Value<u8>();
    ctx.startingEponasSong = StartingEponasSong.Value<u8>();
    ctx.startingSongOfStorms = StartingSongOfStorms.Value<u8>();
    ctx.startingSonataOfAwakening = StartingSonataOfAwakening.Value<u8>();
    ctx.startingGoronsLullaby = StartingGoronsLullaby.Value<u8>();
    ctx.startingNewWaveBossaNova = StartingNewWaveBossaNova.Value<u8>();
    ctx.startingElegyOfEmptiness = StartingElegyOfEmptiness.Value<u8>();
    ctx.startingSongOfSoaring = StartingSongOfSoaring.Value<u8>();
    ctx.startingSongOfHealing = StartingSongOfHealing.Value<u8>();
    //Upgrades
    ctx.startingKokiriSword = StartingKokiriSword.Value<u8>();
    ctx.startingShield = StartingShield.Value<u8>();
    //ctx.startingRazorSword = StartingRazorSword.Value<u8>();
    //ctx.startingGildedSword = StartingGildedSword.Value<u8>();
    ctx.startingMagicMeter = StartingMagicMeter.Value<u8>();
    ctx.startingDoubleDefense = StartingDoubleDefense.Value<u8>();
    ctx.startingHealth        = (StartingHealth.Value<u8>() + 2) % 20 + 1;
    ctx.startingWallet       = StartingWallet.Value<u8>();
    //BossRemains
    ctx.startingOdolwaRemains = StartingOdolwaRemains.Value<u8>();
    ctx.startingGohtRemains = StartingGohtRemains.Value<u8>();
    ctx.startingGyorgRemains = StartingGyorgRemains.Value<u8>();
    ctx.startingTwinmoldRemains = StartingTwinmoldRemains.Value<u8>();
    //Tokens
    ctx.startingSwampTokens = StartingSwampToken.Value<u8>();
    ctx.startingOceanTokens = StartingOceanToken.Value<u8>();
    //Masks
    ctx.startingDekuMask = StartingDekuMask.Value<u8>();
    ctx.startingGoronMask = StartingGoronMask.Value<u8>();
    ctx.startingZoraMask = StartingZoraMask.Value<u8>();
    ctx.startingBunnyHood = StartingBunnyHood.Value<u8>();
    ctx.startingKeatonMask = StartingKeatonMask.Value<u8>();
    ctx.startingPostmanHat = StartingPostmanHat.Value<u8>();
    ctx.startingAllNightMask = StartingAllNightMask.Value<u8>();
    ctx.startingBlastMask = StartingBlastMask.Value<u8>();
    ctx.startingStoneMask = StartingStoneMask.Value<u8>();
    ctx.startingGreatFairyMask = StartingGreatFairyMask.Value<u8>();
    ctx.startingBremenMask = StartingBremenMask.Value<u8>();
    ctx.startingDonGerosMask = StartingDonGeroMask.Value<u8>();
    ctx.startingMaskOfScents = StartingMaskOfScents.Value<u8>();
    ctx.startingRomanisMask = StartingRomanisMask.Value<u8>();
    ctx.startingCircusLeadersMask = StartingCircusLeaderMask.Value<u8>();
    ctx.startingKafeiMask = StartingKafeiMask.Value<u8>();
    ctx.startingCouplesMask = StartingCouplesMask.Value<u8>();
    ctx.startingKamarosMask = StartingKamarosMask.Value<u8>();
    ctx.startingGibdosMask = StartingGibdosMask.Value<u8>();
    ctx.startingGaroMask = StartingGaroMask.Value<u8>();
    ctx.startingCaptainsHat = StartingCaptainsHat.Value<u8>();
    ctx.startingGiantsMask = StartingGiantsMask.Value<u8>();
    ctx.startingFierceDeityMask = StartingFierceDeityMask.Value<u8>();
    ctx.startingMaskOfTruth = StartingMaskOfTruth.Value<u8>();

    //Restoration Features
    ctx.enableFastZoraSwim = (FastZoraSwim) ? 1 : 0;
    ctx.enableOcarinaDiving = (OcarinaDive) ? 1 : 0;
    ctx.enableFastElegyStatues = (FastElegyStatues) ? 1 : 0;
    ctx.enableFastMaskTransform = (DpadTransform) ? 1 : 0;
    ctx.enableFastOcarina = (DpadOcarina) ? 1 : 0;
    ctx.enableFastArrowSwap = (DpadArrows) ? 1 : 0;
    ctx.twinmoldRestoration = (TwinmoldRestoration) ? 1 : 0;

    //Cutscene Skips
    ctx.skipHMSCutscenes = (SkipHMSCutscenes) ? 1 : 0;
    ctx.skipDarmaniCutscene = (SkipDarmaniCutscenes) ? 1 : 0;
    ctx.skipMikauCutscene = (SkipMikauCutscenes) ? 1 : 0;
    
    //CustomButtons
    CitraPrint("Adding Custom Inputs to SettingsContext");
    ctx.customMapButton = CustomButtonConvert(CustomMapButton.Value<u8>());
    ctx.customItemButton = CustomButtonConvert(CustomItemsButton.Value<u8>());
    ctx.customMaskButton = CustomButtonConvert(CustomMasksButton.Value<u8>());
  
    //If CustomNotebookButton is Default set it to Start
    if (CustomNotebookButton.Value<u8>() == u8(0)) {
      ctx.customNotebookButton = u32(Button::Start);
    }
    else {//otherwise run normal conversion
      ctx.customNotebookButton = CustomButtonConvert(CustomNotebookButton.Value<u8>());
    }
    
    //If IngameSpoilersButton is Default set it to Select
    if (IngameSpoilersButton.Value<u8>() == u8(0)) {
      ctx.customIngameSpoilerButton = u32(Button::Select);
    }
    else {//otherwise run normal conversion
      ctx.customIngameSpoilerButton = CustomButtonConvert(IngameSpoilersButton.Value<u8>()); 
    }

    //TODO: 
    /*ctx.toggleAllTricks = ToggleAllTricks.Value<u8>();
    //ctx.logicGrottosWithoutAgony = LogicGrottosWithoutAgony.Value<u8>();

    
    ctx.randomizeDungeon = (RandomizeDungeon) ? 1 : 0;
    ctx.strayFairysanity     = StrayFairysanity.Value<u8>();
    //    ctx.shuffleCows          = (ShuffleCows) ? 1 : 0;
    //    ctx.shuffleOcarinas      = (ShuffleOcarinas) ? 1 : 0;
    
    */
    return ctx;
  }
  
  u8 StartingBottleConvert(u8 startingBottle) {
      u8 startingBottleValue = 0;

      if (startingBottle == u8(1)) {
        startingBottleValue = 0x12;//Empty Bottle
      }
      else if (startingBottle == u8(2)) {
        startingBottleValue = 0x13;//Red Potion
      }
      else if (startingBottle == u8(3)) {
        startingBottleValue = 0x14;//Green Potion
      }
      else if (startingBottle == u8(4)) {
        startingBottleValue = 0x15;//Blue Potion
      }
      else if (startingBottle == u8(5)) {
        startingBottleValue = 0x16;//Fairy
      }
      else if (startingBottle == u8(6)) {
        startingBottleValue = 0x17;//Deku Princess
      }
      else if (startingBottle == u8(7)) {
        startingBottleValue = 0x18;//Milk
      }
      else if (startingBottle == u8(8)) {
        startingBottleValue = 0x19;//Half Milk
      }
      else if (startingBottle == u8(9)) {
        startingBottleValue = 0x1a;//Fish
      }
      else if (startingBottle == u8(10)) {
        startingBottleValue = 0x1b;//Bugs
      }
      else if (startingBottle == u8(11)) {
        startingBottleValue = 0x1e;//Big Poe
      }
      else if (startingBottle == u8(12)) {
        startingBottleValue = 0x1f;//Spring Water
      }
      else if (startingBottle == u8(13)) {
        startingBottleValue = 0x20;//Hot Spring Water
      }
      else if (startingBottle == u8(14)) {
        startingBottleValue = 0x21;//Zora Egg
      }
      else if (startingBottle == u8(15)) {
        startingBottleValue = 0x22;//Gold Dust
      }
      else if (startingBottle == u8(16)) {
        startingBottleValue = 0x23;//Mushroom
      }
      else if (startingBottle == u8(17)) {
        startingBottleValue = 0x24;//Seahorse
      }
      else if (startingBottle == u8(18)) {
        startingBottleValue = 0x25;//Chateau Romani
      }
      else if (startingBottle == u8(19)) {
        startingBottleValue = 0x26;//Mystery Milk
      }
      else if (startingBottle == u8(20)) {
        startingBottleValue = 0x27;//Spoiled Mystery Milk
      }

      return startingBottleValue;
  }
  
  u32 customButtonValue;
  u32 CustomButtonConvert(u8 customButton)
  {
    CitraPrint("Converting Custom Inputs");
    
    if (customButton == u8(0)) {//Default
      customButtonValue = 0;
    } 
    else if (customButton == u8(1)) {//Start
      customButtonValue = u32(Button::Start);
    } 
    else if (customButton == u8(2)) {//Select
      customButtonValue = u32(Button::Select);
    } 
    else if (customButton == u8(3)) {//Start + Select
      customButtonValue = u32(Button::Start) + u32(Button::Select);
    } 
    else if (customButton == u8(4)) {//L + Start 
      customButtonValue = u32(Button::L) + u32(Button::Start);
    } 
    else if (customButton == u8(5)) {//L + Select
      customButtonValue = u32(Button::L) + u32(Button::Select);
    } 
    else if (customButton == u8(6)) {//R + Start
      customButtonValue = u32(Button::R) + u32(Button::Start);
    } 
    else if (customButton == u8(7)) {//R + Select
      customButtonValue = u32(Button::R) + u32(Button::Select);
    } 
    else if (customButton == u8(8)) {//L + ZL
      customButtonValue = u32(Button::L) + u32(Button::ZL);
    } 
    else if (customButton == u8(9)) {//L + ZR
      customButtonValue = u32(Button::L) + u32(Button::ZR);
    } 
    else if (customButton == u8(10)) {//R + ZL
      customButtonValue = u32(Button::R) + u32(Button::ZL);
    } 
    else if (customButton == u8(11)) {//R + ZR
      customButtonValue = u32(Button::R) + u32(Button::ZR);
    } 
    else if (customButton == u8(12)) {//ZL + ZR
      customButtonValue = u32(Button::ZL) + u32(Button::ZR);
    } 
    else if (customButton == u8(13)) {//ZL + Start
      customButtonValue = u32(Button::ZL) + u32(Button::Start);
    } 
    else if (customButton == u8(14)) {//ZL + Select
      customButtonValue = u32(Button::ZL) + u32(Button::Select);
    } 
    else if (customButton == u8(15)) {//ZR + Start
      customButtonValue = u32(Button::ZR) + u32(Button::Start);
    } 
    else if (customButton == u8(16)) {//ZR + Select
      customButtonValue = u32(Button::ZR) + u32(Button::Select);
    }     

    return customButtonValue;
  }

  //Set default cosmetics where the default is not the first option
  static void SetDefaultCosmetics() {
    for (auto op : cosmeticOptions) {
      op->SetToDefault();
    }
  }

  //One-time initialization
  void InitSettings() {
    //Set up token options
    //TODO: Create new 'number range' option type so this isn't necessary
    std::vector<std::string> StokenOptions;
    StokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      StokenOptions.push_back(std::to_string(i));
    }
    std::vector<std::string> OtokenOptions;
    OtokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      OtokenOptions.push_back(std::to_string(i));
    }
	StartingSwampToken.SetOptions(StokenOptions);
    StartingOceanToken.SetOptions(OtokenOptions);
    
    //Create Location Exclude settings
    AddExcludedOptions();

    SetDefaultSettings();
  }

  //Set default settings for all settings
  void SetDefaultSettings() {
      
      for (auto op : comfortOptions) {
          op->SetToDefault();
      }
      for (auto op : restorationOptions) {
          op->SetToDefault();
      }
    for (auto op : cutsceneOptions) {
        op->SetToDefault();
    }
      for (auto op : cosmeticOptions) {
          op->SetToDefault();
      }
    for (auto op : excludeLocationsOptions) {
      op->SetToDefault();
    }
    for (auto op : startingInventoryOptions) {
      op->SetToDefault();
    }
    for (auto op : logicOptions) {
      op->SetToDefault();
    }
    for (auto op : trickOptions) {
     op->SetToDefault();
    }
    for (auto op : glitchOptions) {
      op->SetToDefault();
    }
    for (auto op : shuffleItemOptions) {
        op->SetToDefault();
    }
    for (auto op : otherSettingsOptions) {
        op->SetToDefault();
    }
    for (auto op : dungeonSettingsOptions) {
      op->SetToDefault();
    }

    for (auto op : itemPoolSettingsOptions) {
      op->SetToDefault();
    }

      for (auto loc : allLocations) {
      Location(loc)->GetExcludedOption()->SetToDefault();
    }

    for (auto op : customButtons) {
      op->SetToDefault();
    }
    //Don't let users exclude these locations
    //TODO: Make sure the defaults are set appropriately for these?
	//Also TODO: make sure some checks cant be skpped?
//    Location(HC_ZELDAS_LETTER)->GetExcludedOption()->Hide();
//    Location(MARKET_BOMBCHU_BOWLING_BOMBCHUS)->GetExcludedOption()->Hide();
    //Location(GANON)->GetExcludedOption()->Hide();

    SetDefaultCosmetics();
  }
  
  //Include and Lock the desired locations
  static void IncludeAndHide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->SetSelectedIndex((u8)ExcludeLocationSetting::INCLUDE);
      Location(loc)->GetExcludedOption()->Hide();
   }
  }

  //Unlock the desired locations
  static void Unhide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->Unhide();
    }
  }
  

  //Used for Starting Inventory options, enables/disables the options or expands/collapses each category based on their index number
  void CollapseCategory(Option startingInventorySections, int startNum, int endNum) {
    for(int i = startNum; i < endNum ;++i){
      switch(startingInventorySections.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          if (startingInventorySections.GetName() == "Equipment & Upgrades") {
            startingInventoryOptions[i]->SetSelectedIndex((startingInventoryOptions[i]->GetOptionCount())-2);
          } else {
            startingInventoryOptions[i]->SetSelectedIndex((startingInventoryOptions[i]->GetOptionCount())-1);
          }
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }
  }

  //This function will hide certain locations from the Excluded Locations
  //menu if the player's current settings would require non-junk to be placed
  //at those locations. Excluded locations will have junk placed at them.
  
  static void ResolveExcludedLocationConflicts() {

      //For now, just always hide shop locations, as not sure how to handle hiding them-
      //1-4 should always be hidden, while the others should be settings dependent, but random shopsanity makes that more complicated...
      //Excluded shop locations are also wonky
      std::vector<LocationKey> shopLocations = GetLocations(everyPossibleLocation, Category::cShop);
      IncludeAndHide(shopLocations);

      //Force include song locations
     std::vector<LocationKey> songLocations = GetLocations(everyPossibleLocation, Category::cSong);
      //Unhide all song locations, then lock necessary ones
      //Unhide(songLocations);

      //if (ShuffleSongs.Is((u8)SongShuffleSetting::SONGSHUFFLE_SONG_LOCATIONS)) {
      //    IncludeAndHide(songLocations);
     // }
      //else if (ShuffleSongs.Is((u8)SongShuffleSetting::SONGSHUFFLE_DUNGEON_REWARDS)) {
          IncludeAndHide(songLocations);
      //}
     
     //Force Include Dungeon Rewards
     std::vector<LocationKey> DungeonRewards = GetLocations(everyPossibleLocation, Category::cDungeonReward);
     //if (ShuffleRewards.Is((u8)RewardShuffleSetting::REWARDSHUFFLE_END_OF_DUNGEON)) {
         IncludeAndHide(DungeonRewards);
     //}
     //else {
     //    Unhide(DungeonRewards);
     //}
     //Force hide Ocarina
     IncludeAndHide({CLOCK_TOWER_OCARINA_OF_TIME});

     //Force hide Deku Princess
     IncludeAndHide({WOODFALL_TEMPLE_DEKU_PRINCESS});
     
      //Force Include Vanilla Skulltula locations
      std::vector<LocationKey> SwampSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cSwampSkulltula);
      std::vector<LocationKey> OceanSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cOceanSkulltula);
      if(!Tokensanity) {
        IncludeAndHide(SwampSkulltulaLocations);
        IncludeAndHide(OceanSkulltulaLocations);
      }
      else {
        Unhide(SwampSkulltulaLocations);
        Unhide(OceanSkulltulaLocations);
      }
      /*if (Tokensanity.IsNot(TOKENSANITY_ALL_TOKENS)) {
          if (Tokensanity.Is(TOKENSANITY_OVERWORLD)) {
              //filter overworld skulls so we're just left with dungeons
              FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1) {return Location(loc1)->GetScene() >= 0x0A;});
              FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2) {return Location(loc2)->GetScene() >= 0x0A;});
          }
          else if (Tokensanity.Is(TOKENSANITY_DUNGEONS)) {
              //filter dungeon skulls so we're just left with overworld
              FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1) {return Location(loc1)->GetScene() < 0x0A;});
              FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2) {return Location(loc2)->GetScene() < 0x0A;});
          }
          IncludeAndHide(SwampSkulltulaLocations);
          IncludeAndHide(OceanSkulltulaLocations);
      }*/
      
      //Force Include scrubs if Scrubsanity is Off
      std::vector<LocationKey> scrubLocations = GetLocations(everyPossibleLocation, Category::cDekuScrub);
      if (!Scrubsanity) { //.Is(OFF)
          IncludeAndHide(scrubLocations);
      }
      else {
          Unhide(scrubLocations);
      }

      //Force include Cows if Shuffle Cows is Off
      std::vector<LocationKey> cowLocations = GetLocations(everyPossibleLocation, Category::cCow);
      if (ShuffleCows) {
          Unhide(cowLocations);
      }
      else {
          IncludeAndHide(cowLocations);
      }

      //Force Include Anju & Kafei Items
      std::vector<LocationKey> kafeiLocations = GetLocations(everyPossibleLocation, Category::cAnjuAndKafei);
      if (ShuffleTradeItems) {
        Unhide(kafeiLocations);
      }
      else {
        IncludeAndHide(kafeiLocations);
      }

      //Force include Deku Trade Items
      std::vector<LocationKey> dekuLocations = GetLocations(everyPossibleLocation, Category::cTradeItem);
      if (ShuffleMerchants) {
        Unhide(dekuLocations);
      }
      else {
        IncludeAndHide(dekuLocations);
      }

      //Force include Tingle Maps
      std::vector<LocationKey> tingleLocations = GetLocations(everyPossibleLocation, Category::cTingleMap);
      if (ShuffleTingleMaps) {
        Unhide(tingleLocations);
      }
      else {
        IncludeAndHide(tingleLocations);
      }

      //Force Include Bombers Notebook
      std::vector<LocationKey> notebookLocation = GetLocations(everyPossibleLocation, Category::cNotebook);
      if (ShuffleBombersNotebook) {
        Unhide(notebookLocation);
      }
      else {
        IncludeAndHide(notebookLocation);
      }

      //Force Include Zora Eggs
      std::vector<LocationKey> eggLocations = GetLocations(everyPossibleLocation, Category::cZoraEgg);
      IncludeAndHide(eggLocations);
      
      //Hide alternate check locations
      std::vector<LocationKey> altLocations = GetLocations(everyPossibleLocation, Category::cAlternateCheck);
      IncludeAndHide(altLocations);

      //Force Include Great Fairy
      std::vector<LocationKey> gfLocations = GetLocations(everyPossibleLocation, Category::cFairyFountain);
      if (ShuffleGFRewards.Is((u8)GreatFairyRewardShuffleSetting::GFREWARDSHUFFLE_ANYWHERE)){
        Unhide(gfLocations);
      }
      else {
        IncludeAndHide(gfLocations);
      }

      //Force Include Main Inventory
      std::vector<LocationKey> maininventoryLocations = GetLocations(everyPossibleLocation, Category::cMainInventory);
      if (ShuffleMainInventory) {
        Unhide(maininventoryLocations);
      }
      else {
        IncludeAndHide(maininventoryLocations);
      }

      //Force include Masks
      std::vector<LocationKey> maskLocations = GetLocations(everyPossibleLocation, Category::cVanillaMask);
      if (ShuffleMasks) {
        Unhide(maskLocations);
      }
      else {
        IncludeAndHide(maskLocations);
      }

      //Force include Transformation Masks
      std::vector<LocationKey> transformLocations = GetLocations(everyPossibleLocation, Category::cTransformMask);
      if (ShuffleTransformation) {
        Unhide(transformLocations);
      }
      else {
        IncludeAndHide(transformLocations);
      }

      //Force include Piece of Heart
      std::vector<LocationKey> heartPieceLocations = GetLocations(everyPossibleLocation, Category::cVanillaHeartPiece);
      if (ShufflePiecesOfHeart) {
        Unhide(heartPieceLocations);
      }
      else {
        IncludeAndHide(heartPieceLocations);
      }

      //Force include Fierce Deity
      std::vector<LocationKey> fdmLocation = GetLocations(everyPossibleLocation, Category::cFDM);
      if (ShuffleFierceDeity) {
        Unhide(fdmLocation);
      }
      else {
        IncludeAndHide(fdmLocation);
      }

      //Force include Moon Items
      std::vector<LocationKey> moonItemLocations = GetLocations(everyPossibleLocation, Category::cMoonItems);
      if (ShuffleMoonItems) {
        Unhide(moonItemLocations);
      }
      else {
        IncludeAndHide(moonItemLocations);
      }

      //Force include Magic Bean salesman if Shuffle Magic Beans is off
      if (ShuffleMagicBeans) {
          Unhide({ DEKU_PALACE_BEAN_SELLER });
      }
      else {
          IncludeAndHide({ DEKU_PALACE_BEAN_SELLER });
      }

      //Force include Map and Compass Chests when Vanilla
      std::vector<LocationKey> mapChests = GetLocations(everyPossibleLocation, Category::cVanillaMap);
      std::vector<LocationKey> compassChests = GetLocations(everyPossibleLocation, Category::cVanillaCompass);
      if (MapsAndCompasses.Is((u8)MapsAndCompassesSetting::MAPSANDCOMPASSES_VANILLA)) {
          IncludeAndHide(mapChests);
          IncludeAndHide(compassChests);
      }
      else {
          Unhide(mapChests);
          Unhide(compassChests);
      }
      
      //Force include Vanilla Small Key Locations (except gerudo Fortress) on Vanilla Keys
      std::vector<LocationKey> smallKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaSmallKey);
      if (Keysanity.Is((u8)KeysanitySetting::KEYSANITY_VANILLA)) {
          IncludeAndHide(smallKeyChests);
      }
      else {
          Unhide(smallKeyChests);
      }

      //Force include Boss Key Chests if Boss Keys are Vanilla
      std::vector<LocationKey> bossKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaBossKey);
      if (BossKeysanity.Is((u8)BossKeysanitySetting::BOSSKEYSANITY_VANILLA)) {
          IncludeAndHide(bossKeyChests);
      }
      else {
          Unhide(bossKeyChests);
      }

      //Forcce include Boss Heart Containers if Heart Containers are Vanilla
      std::vector<LocationKey> heartContainers = GetLocations(everyPossibleLocation, Category::cBossHeart);
      if (!ShuffleHeartContainers) {
        IncludeAndHide(heartContainers);
      }
      else {
        Unhide(heartContainers);
      }

      //Force include Stray Fairies if Stray Fairy Sanity is Vanilla
      std::vector<LocationKey> strayFairies = GetLocations(everyPossibleLocation, Category::cVanillaStrayFairy);
      if (!StrayFairysanity) {
        IncludeAndHide(strayFairies);
      }
      else {
        Unhide(strayFairies);
      }
      
  }

  //Hide certain settings if they aren't relevant or Lock settings if they
  //can't be changed due to another setting that was chosen. (i.e. Closed Forest
  //will force Starting Age to Child).
  void ForceChange(u32 kDown, Option* currentSetting) {

      //Lock Shuffle Heart Pieces if the item pool is set to Plentiful, since heart piece locations are used to extra items
      if (ItemPoolValue.Is(ItemPoolSetting::ITEMPOOL_PLENTIFUL)) {
        ShufflePiecesOfHeart.SetSelectedIndex(1);
        ShufflePiecesOfHeart.Lock();
      } else {
        ShufflePiecesOfHeart.Unlock();
      }

    //Groups the item categories; bottles are handled separately because the proper item is Empty Bottle (1)
      CollapseCategory(StartingInventoryToggle, 3, 25);
      CollapseCategory(StartingMaskToggle, 26, 50);
      CollapseCategory(StartingSongsToggle, 51, 60);
      CollapseCategory(StartingUpgradesToggle, 61, 67);
      CollapseCategory(StartingQuestToggle, 68, 72);
    for(int i = 18; i < 25 ;++i) {
      switch(StartingInventoryToggle.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(1);
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }

   

    //Only hide the options for now, select them later in UpdateSettings()
    //RandomizeAllSettings();
      

    //Force Link's Pocket Item to be a dungeon reward if Shuffle Rewards is end of dungeons
   /* if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
      LinksPocketItem.Lock();
      LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      if (RandomizeShuffle) {
        //Even if it is supposed to be locked, still hide it to keep the surprise
        LinksPocketItem.Unlock();
        LinksPocketItem.Hide();
      }
    } else {
      LinksPocketItem.Unlock();
    }*/

    //Only show hint options if hints are enabled
    /*if (GossipStoneHints.Is(HINTS_NO_HINTS)) {
      ClearerHints.Hide();
      HintDistribution.Hide();
    } else {
      ClearerHints.Unhide();
      HintDistribution.Unhide();
    }*/

    if (RemoveDoubleDefense) {
      StartingDoubleDefense.SetSelectedIndex(0);
      StartingDoubleDefense.Lock();
    } else {
      StartingDoubleDefense.Unlock();
    }


    //Tunic Colors
    if (CustomTunicColors) {
      ChildTunicColor.Unhide();
      
    } else {
      ChildTunicColor.Hide();
      ChildTunicColor.SetSelectedIndex(3);  //Kokiri Green
     }

    // Music
//    if (ShuffleMusic) {
//      ShuffleBGM.Unhide();
//      ShuffleFanfares.Unhide();
//      if(ShuffleFanfares.Is(2)) // Fanfares + ocarina
//        ShuffleOcaMusic.Hide();
//      else
//        ShuffleOcaMusic.Unhide();
//    } else {
//      ShuffleBGM.Hide();
//      ShuffleFanfares.Hide();
//      ShuffleOcaMusic.Hide();
//    }

    // Playing on console and selected game region does not match console region
    if (!PlayOption && ((!RegionSelect && SystemInfo_GetRegion() != CFG_REGION_USA) || (RegionSelect && SystemInfo_GetRegion() != CFG_REGION_EUR))) {
        LanguageSelect.Unhide();

        if (LanguageSelect.Is(LANGUAGE_NONE)) {
            switch(SystemInfo_GetLanguage()) {
                case CFG_LANGUAGE_FR:
                    LanguageSelect.SetSelectedIndex(LANGUAGE_FRENCH);
                    break;
                case CFG_LANGUAGE_ES:
                    LanguageSelect.SetSelectedIndex(LANGUAGE_SPANISH);
                    break;
                case CFG_LANGUAGE_DE:
                    LanguageSelect.SetSelectedIndex(LANGUAGE_GERMAN);
                    break;
                case CFG_LANGUAGE_IT:
                    LanguageSelect.SetSelectedIndex(LANGUAGE_ITALIAN);
                    break;
                default:
                    LanguageSelect.SetSelectedIndex(LANGUAGE_ENGLISH);
            }
        }

        if (LanguageSelect.Value<u8>() < LANGUAGE_ENGLISH) {
            LanguageSelect.SetSelectedIndex((RegionSelect) ? LANGUAGE_ITALIAN : LANGUAGE_SPANISH);
        }

        if (LanguageSelect.Value<u8>() > ((RegionSelect) ? LANGUAGE_ITALIAN : LANGUAGE_SPANISH)) {
            LanguageSelect.SetSelectedIndex(LANGUAGE_ENGLISH);
        }
    } else {
        LanguageSelect.Hide();
        LanguageSelect.SetSelectedIndex(LANGUAGE_NONE);
    }

    ResolveExcludedLocationConflicts();
  }


  // Randomizes all settings in a category if chosen
  // Hides all relevant options
  void RandomizeAllSettings(const bool selectOptions /*= false*/) {
  /*
    // Open Settings
    if (RandomizeOpen) {
      // Skip RandomizeOpen Option
      for (size_t i = 1; i < openOptions.size(); i++) {
        //hide options
        openOptions[i]->Hide();

        //randomize options
        if (selectOptions) {
          openOptions[i]->SetSelectedIndex(Random(0,openOptions[i]->GetOptionCount()));
        }
      }
      
    }
    else {
      for (size_t i = 1; i < openOptions.size(); i++) {
        openOptions[i]->Unhide();
      }
    }

   
    // Shuffle Settings
    if (RandomizeShuffle) {
      // Still displays if previously locked
      LinksPocketItem.Unlock();
      // Skip RandomizeShuffle Option
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleOptions[i]->SetSelectedIndex(Random(0,shuffleOptions[i]->GetOptionCount()));
        }
      }
      // Double check that this is the case in case of randomization on init
      if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
        LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      }
    }
    else {
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Unhide();
      }
    }

    // Dungeon Shuffle Settings
    if (RandomizeDungeon) {
      // Skip RandomizeDungeon Option
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleDungeonItemOptions[i]->SetSelectedIndex(Random(0,shuffleDungeonItemOptions[i]->GetOptionCount()));
        }
      }
    }
    else {
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Unhide();
      }
    }

    //resolve any settings that need to change
    if (selectOptions) {
      ForceChange(0, nullptr);
    }*/
  }

  //eventual settings
  bool ShuffleInteriorEntrances         = false;
  bool ShuffleSpecialIndoorEntrances    = false;

  template <typename colorsArray>
  static void ChooseFinalColor(const Option& cosmeticOption, std::string& colorStr, const colorsArray& colors) {
    if (cosmeticOption.Is(CUSTOM_COLOR)) {
      colorStr = GetCustomColor(cosmeticOption.GetSelectedOptionText());
    } else if (cosmeticOption.Is(RANDOM_CHOICE)) {
      colorStr = colors[rand() % colors.size()]; //use default rand to not interfere with seed
    } else if (cosmeticOption.Is(RANDOM_COLOR)) {
      colorStr = RandomColor();
    } else {
      colorStr = colors[cosmeticOption.GetSelectedOptionIndex() - NON_COLOR_COUNT];
    }
  }

  //Function to update cosmetics options depending on choices
  /*static void UpdateCosmetics() {

    ChooseFinalColor(ChildTunicColor, finalChildTunicColor, tunicColors);
    }
  */
  //Function to set flags depending on settings
  void UpdateSettings() {

    //RandomizeAllSettings(true); //now select any random options instead of just hiding them

    //shuffle the dungeons 
   /* auto dungeons = dungeonList;
    if (SetDungeonTypes) {
        u8 dungeonCount = 0;
        for (size_t i = 0; i < dungeons.size(); i++) {
            dungeonOptions[i]->Value<u8>());
        }
    }*/
	//UpdateCosmetics();

    //If vanilla logic, we want to set all settings which unnecessarily modify vanilla behavior to off
    if (Logic.Is((u8)LogicSetting::LOGIC_VANILLA)) {
      ShuffleSongs.SetSelectedIndex(0);
      ShuffleSoaring.SetSelectedIndex(0);
      Shopsanity.SetSelectedIndex(0);
      Tokensanity.SetSelectedIndex(0);
      ShuffleCows.SetSelectedIndex(0);
      ShuffleTradeItems.SetSelectedIndex(0);
      ShuffleMerchants.SetSelectedIndex(0);
      RemoveDoubleDefense.SetSelectedIndex(0);
      ShuffleMagicBeans.SetSelectedIndex(0);
      Keysanity.SetSelectedIndex(0);
      MapsAndCompasses.SetSelectedIndex(0);
      BossKeysanity.SetSelectedIndex(0);
      StrayFairysanity.SetSelectedIndex(0);
      ShuffleRewards.SetSelectedIndex(0);
      ShuffleHeartContainers.SetSelectedIndex(0);
      ShuffleMainInventory.SetSelectedIndex(0);
      ShuffleTransformation.SetSelectedIndex(0);
      ShuffleFierceDeity.SetSelectedIndex(0);
      ShuffleMasks.SetSelectedIndex(0);
      ShuffleGFRewards.SetSelectedIndex(0);
      ShufflePiecesOfHeart.SetSelectedIndex(0);
      ShuffleMoonItems.SetSelectedIndex(0);
      GossipStoneHints.SetSelectedIndex(0);
    }
    /*
    InitMusicRandomizer();
    if (ShuffleMusic) {
      if (ShuffleBGM) {
        ShuffleSequences(SeqType::SEQ_BGM);
      }

      if (ShuffleFanfares.Is(2)) {
        ShuffleSequences(SeqType::SEQ_FANFARE | SeqType::SEQ_OCARINA);
      } else {
        if (ShuffleFanfares.Is(1)) {
          ShuffleSequences(SeqType::SEQ_FANFARE);
        }

        if (ShuffleOcaMusic) {
          ShuffleSequences(SeqType::SEQ_OCARINA);
        }
      }
    }*/
  }
  
  //If this is an option menu, return th options
  //Else, recursively call each sub menu of this sub menu
  const std::vector<Menu*> GetMenusRecursive(Menu* menu) {
    std::vector<Menu*> menus;
    if (menu->mode == OPTION_SUB_MENU) {
      menus.push_back(menu);
    } else if (menu->mode == SUB_MENU) {
        for (Menu* subMenu : *menu->itemsList) {
          std::vector<Menu*> foundMenus = GetMenusRecursive(subMenu);
          menus.insert(menus.end(), foundMenus.begin(), foundMenus.end());
        }
    }
    return menus;
  }

  //Recursively look through each menu from the main menu to get all settings
  const std::vector<Menu*> GetAllMenus() {
    std::vector<Menu*> allMenus;
    for (Menu* menu : Settings::mainMenu) {
      std::vector<Menu*> foundMenus = GetMenusRecursive(menu);
      allMenus.insert(allMenus.end(), foundMenus.begin(), foundMenus.end());
    }
    return allMenus;
  }

 //we dont want users to select the same values for multiple inputs, so check if any of the selected options match
 //multiple options can be index 0 or Default as this won't cause issues in game.
  bool CheckCustomButtons() {
    CitraPrint("Checking Custom Buttons in function");
    u8 mapButtonValue = CustomMapButton.Value<u8>();
    u8 itemButtonValue = CustomItemsButton.Value<u8>();
    u8 maskButtonValue = CustomMasksButton.Value<u8>();
    u8 notebookButtonValue = CustomNotebookButton.Value<u8>();
    u8 spoilerButtonValue = IngameSpoilersButton.Value<u8>();

    //If an option is not set to Default (0) then check if it matches any other selections
    //If it does match return false unless the value it's matching is Default (0)
    if (mapButtonValue != 0)
    {
      if (mapButtonValue == itemButtonValue && itemButtonValue != 0) {
       return false;
      } 
      if (mapButtonValue == maskButtonValue && maskButtonValue != 0) {
        return false;
      } 
      //if notebook button is not default make sure they dont match && if notebook button IS default then make sure map button isnt Start
      if (mapButtonValue == notebookButtonValue && notebookButtonValue != 0) {
        return false;
      }
      if (mapButtonValue == 1 && notebookButtonValue == 0) {
        return false;
      }
      //If spoiler button is not default make sure they dont match & if spoiler button IS default then make sure map button isnt Select
      if (mapButtonValue == spoilerButtonValue && spoilerButtonValue != 0) {
        return false;
      }
      if (mapButtonValue == 2 && spoilerButtonValue == 0 ) {
            return false;
        }
    }
    
    if (itemButtonValue != 0)
    {
      if (itemButtonValue == mapButtonValue && mapButtonValue != 0) {
        return false;
      } 
      if (itemButtonValue == maskButtonValue && maskButtonValue != 0) {
        return false;
      }
      //if notebook button is not default make sure they dont match && if notebook button IS default then make sure map button isnt Start
      if (itemButtonValue == notebookButtonValue && notebookButtonValue != 0) {
       return false;
      }
      if (itemButtonValue == 1 && notebookButtonValue == 0) {
        return false;
      }
      //If spoiler button is not default make sure they dont match & if spoiler button IS default then make sure map button isnt Select
      if (itemButtonValue == spoilerButtonValue && spoilerButtonValue != 0) {
        return false;
      }
      if (itemButtonValue == 2 && spoilerButtonValue == 0) {
        return false;
      }
    }

    if (maskButtonValue != 0)
    {
      if (maskButtonValue == mapButtonValue && mapButtonValue != 0) {
        return false;
      }
      if (maskButtonValue == itemButtonValue && itemButtonValue != 0) {
        return false;
      }
      //if notebook button is not default make sure they dont match && if notebook button IS default then make sure map button isnt Start
      if (maskButtonValue == notebookButtonValue && notebookButtonValue != 0) {
        return false;
      }
      if (maskButtonValue == 1 && notebookButtonValue == 0) {
        return false;
      }
      //If spoiler button is not default make sure they dont match & if spoiler button IS default then make sure map button isnt Select
      if (maskButtonValue == spoilerButtonValue && spoilerButtonValue != 0) {
        return false;
      }
      if (maskButtonValue == 2 && notebookButtonValue == 0) {
        return false;
      }
    }

    if (notebookButtonValue != 0)
    {
      if (notebookButtonValue == mapButtonValue && mapButtonValue != 0) {
        return false;
      }
      if (notebookButtonValue == itemButtonValue && itemButtonValue != 0) {
        return false;
      }
      if (notebookButtonValue == maskButtonValue && maskButtonValue != 0) {
        return false;
      }
      if (notebookButtonValue == spoilerButtonValue && spoilerButtonValue != 0) {
        return false;
      }
      //If notebook button is not default make sure it its not Select to cover default spoilerButton
      if (notebookButtonValue == 2 && spoilerButtonValue == 0) {
        return false;
      }
    }

    if (spoilerButtonValue != 0)
    {
      if (spoilerButtonValue == mapButtonValue && mapButtonValue != 0) {
        return false;
      }
      if (spoilerButtonValue == itemButtonValue && itemButtonValue != 0) {
        return false;
      }
      if (spoilerButtonValue == maskButtonValue && maskButtonValue != 0) {
        return false;
      }
      if (spoilerButtonValue == notebookButtonValue && notebookButtonValue != 0) {
        return false;
      }
      //If spoiler button is not default make sure its not Start to cover default NotebookButton
      if (spoilerButtonValue == 1 && notebookButtonValue == 0) {
        return false;
      }
    }
    //if none of the buttons match return true.
      return true;
  }

  
} // namespace Settings