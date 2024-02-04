 #include "item_location.hpp"

#include "dungeon.hpp"
#include "settings.hpp"
#include "spoiler_log.hpp"
//#include "shops.hpp"
#include "debug.hpp"
#include "keys.hpp"
#include "fill.hpp"
using namespace std;
using namespace rnd;
//Location definitions
static std::array<ItemLocation, KEY_ENUM_MAX> locationTable;

void LocationTable_Init() {
 locationTable[NONE]                                               = ItemLocation::Base       (0x00, 0x00, false, "Invalid Location",                                         NONE,                                           NONE,                         {},                                                                                                                        SpoilerCollectionCheck::None(),             SpoilerCollectionCheckGroup::GROUP_NO_GROUP);
 //LocationTable                                                   itemlocation::type         scene, flag, Repeatable, name                                                   hint key (hint_list.cpp)                        vanilla item                  categories                                                                                                                 collection check 376                        Collection Check Group                                                                                                
    
 //Happy Mask Salesman - Starting Items
 locationTable[HMS_SONG_OF_HEALING]                                = ItemLocation::Base       (0x63, 0x54, false, "Song of Healing",                                          HMS_SONG_OF_HEALING,                            SONG_OF_HEALING,              {Category::cClockTower, Category::cDayOne, Category::cSong},                                                               SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP);
 locationTable[CLOCK_TOWER_OCARINA_OF_TIME]                        = ItemLocation::Base       (0x19, 0x4C, false, "Ocarina of Time",                                          CLOCK_TOWER_OCARINA_OF_TIME,                    OCARINA_OF_TIME,              {Category::cClockTower, Category::cDayThree},                                                                              SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
 locationTable[HMS_DEKU_MASK]                                      = ItemLocation::Base       (0x63, 0x78, false, "Deku Mask",                                                HMS_DEKU_MASK,                                  DEKU_MASK,                    {Category::cClockTower, Category::cTransformMask},                                                                         SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
 locationTable[HMS_BOMBERS_NOTEBOOK]                               = ItemLocation::Base       (0x63, 0x50, false, "Bombers Notebook",                                         HMS_BOMBERS_NOTEBOOK,                           BOMBERS_NOTEBOOK,             {Category::cClockTower, Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
 locationTable[HMS_STARTING_SWORD]                                 = ItemLocation::Base       (0x00, 0x37, false, "Starting Sword",                                           HMS_STARTING_SWORD,                             PROGRESSIVE_SWORD,            {Category::cClockTower},                                                                                                   SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
 locationTable[HMS_STARTING_SHIELD]                                = ItemLocation::Base       (0x00, 0x32, false, "Starting Shield",                                          HMS_STARTING_SHIELD,                            HEROS_SHIELD,                 {Category::cClockTower},                                                                                                   SpoilerCollectionCheck::ItemGetInf(6),      SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
  
 //Deku Palace
 locationTable[DEKU_PALACE_BEAN_SELLER]                            = ItemLocation::Base       (0x07, 0x35, true,  "DP Bean Seller",                                           DEKU_PALACE_BEAN_SELLER,                        MAGIC_BEAN,                   {Category::cDekuPalace,Category::cWoodfall,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE );
 locationTable[DEKU_PALACE_WEST_GARDEN]                            = ItemLocation::Collectable(0x2B, 0x00, false, "DP West Garden",                                           DEKU_PALACE_WEST_GARDEN,                        PIECE_OF_HEART,               {Category::cDekuPalace,Category::cWoodfall, Category::cFreestandingItems, Category::cVanillaHeartPiece,Category::cDayOne},                                             SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE );
 locationTable[DEKU_PALACE_BUTLER_RACE]                            = ItemLocation::Base       (0x52, 0x8E, false, "DP Butler Race",                                           DEKU_PALACE_BUTLER_RACE,                        MASK_OF_SCENTS,               {Category::cDekuPalace,Category::cWoodfall, Category::cVanillaMask,Category::cDayOne},                                     SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE );
 locationTable[DEKU_PALACE_IMPRISONED_MONKEY]                      = ItemLocation::Base       (0x3E, 0x4B, false, "DP Imprisoned Monkey",                                     DEKU_PALACE_IMPRISONED_MONKEY,                  SONATA_OF_AWAKENING,          {Category::cDekuPalace,Category::cSong,Category::cWoodfall,Category::cDayOne},                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE );
 locationTable[DEKU_PALACE_BEAN_GROTTO_CHEST]                      = ItemLocation::Chest      (0x07, 0x05, true,  "DP Bean Grotto Chest",                                     DEKU_PALACE_BEAN_GROTTO_CHEST,                  RED_RUPEE,                    {Category::cDekuPalace,Category::cGrotto,Category::cWoodfall,Category::cChest,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DEKU_PALACE);
 
 //East Clock Town
 locationTable[E_CLOCK_TOWN_AROMA_IN_BAR]                          = ItemLocation::Base       (0x15, 0x6F, false, "ECT Milk Bar Madame Aroma",                                E_CLOCK_TOWN_AROMA_IN_BAR,                      CHATEAU_ROMANI,               {Category::cEastClockTown, Category::cDayThree},                                                                           SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_ARCHERY_1]                             = ItemLocation::Base       (0x20, 0x47, false,  "ECT Archery #1",                                           E_CLOCK_TOWN_ARCHERY_1,                         PROGRESSIVE_BOW,              {Category::cEastClockTown, Category::cMinigame,Category::cDayOne },                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_MAYOR]                                 = ItemLocation::Base       (0x12, 0x0C, false, "ECT Mayor Reward",                                         E_CLOCK_TOWN_MAYOR,                             PIECE_OF_HEART,               {Category::cEastClockTown, Category::cVanillaHeartPiece ,Category::cDayOne},                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_ARCHERY_2]                             = ItemLocation::Base       (0x20, 0x0C, false,  "ECT Archery #2",                                           E_CLOCK_TOWN_ARCHERY_2,                         PIECE_OF_HEART,               {Category::cEastClockTown, Category::cMinigame , Category::cVanillaHeartPiece,Category::cDayOne},                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS]                   = ItemLocation::Base       (0x11, 0x0C, false,  "ECT Honey and Darling 3 Days",                             E_CLOCK_TOWN_HONEY_DARLING_3DAYS,               PIECE_OF_HEART,               {Category::cEastClockTown, Category::cMinigame , Category::cVanillaHeartPiece,Category::cDayThree},                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON]             = ItemLocation::Chest      (0x17, 0x00, true,  "ECT Treasure Chest Game (Goron)",                          E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON,         PIECE_OF_HEART,               {Category::cEastClockTown, Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_POSTMAN_FREEDOM]                       = ItemLocation::Base       (0x6C, 0x84, true,  "ECT Postman's Freedom",                                    E_CLOCK_TOWN_POSTMAN_FREEDOM,                   POSTMANS_HAT,                 {Category::cEastClockTown, Category::cVanillaMask,Category::cDayThree},                                                    SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_GORMAN]                                = ItemLocation::Base       (0x15, 0x83, false, "ECT Milk Bar Gorman",                                      E_CLOCK_TOWN_GORMAN,                            CIRCUS_LEADERS_MASK,          {Category::cEastClockTown, Category::cVanillaMask,Category::cDayOne},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_AROMA_IN_OFFICE]                       = ItemLocation::Base       (0x12, 0x8F, false, "ECT Mayor's Office Madame Aroma",                          E_CLOCK_TOWN_AROMA_IN_OFFICE,                   KAFEIS_MASK,                  {Category::cEastClockTown, Category::cVanillaMask,Category::cDayOne},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[BOMBERS_HIDEOUT_CHEST]                              = ItemLocation::Chest      (0x29, 0x00, true,  "Bombers' Hideout Chest",                                   BOMBERS_HIDEOUT_CHEST,                          SILVER_RUPEE,                 {Category::cEastClockTown,Category::cChest,Category::cDayOne },                                                                                                        SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_CHEST]                                 = ItemLocation::Chest      (0x6C, 0x0A, true,  "ECT Chest",                                                E_CLOCK_TOWN_CHEST,                             SILVER_RUPEE,                 {Category::cEastClockTown,Category::cChest ,Category::cDayOne},                                                                                                        SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU]                      = ItemLocation::Base       (0x12, 0x00, true, "Milk Bar Chateau Buy",                                      E_CLOCK_TOWN_MILK_BAR_CHATEAU,                  CHATEAU_ROMANI,               {Category::cEastClockTown},                                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_MILK_BAR_MILK]                         = ItemLocation::Base       (0x12, 0x00, true, "Milk Bar Milk Buy",                                         E_CLOCK_TOWN_MILK_BAR_MILK,                     MILK,                         {Category::cEastClockTown},                                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY]                 = ItemLocation::Base       (0x11, 0x00, true, "Honey and Darling Any Day",                                 E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY,             PURPLE_RUPEE,                 {Category::cEClockTown,Category::cMinigame},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN]             = ItemLocation::Base       (0x17, 0x00, true, "Treasure Chest Game (Human)",                               E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN          PURPLE_RUPEE,                 {Category::cEClockTown,Category::cMinigame,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA]              = ItemLocation::Base       (0x17, 0x00, true, "Treasure Chest Game (Zora)",                                E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA,          RED_RUPEE,                    {Category::cEClockTown,Category::cMinigame ,Category::cDayOne},                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 //locationTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU]              = ItemLocation::Base       (0x17, 0x00, true, "Treasure Chest Game (Deku)",                                E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU,          DEKU_NUTS_10,                 {Category::cEClockTown,Category::cMinigame,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 locationTable[E_CLOCK_TOWN_POSTBOX]                               = ItemLocation::Base       (0x6C, 0xBA, false, "ECT Postbox",                                              E_CLOCK_TOWN_POSTBOX,                           PIECE_OF_HEART,               {Category::cEastClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_E_CLOCK_TOWN );
 
 //Goron Village
 locationTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE]                 = ItemLocation::Base       (0x4D, 0x34, false, "GV Powder Keg Challenge",                                  GORON_VILLAGE_POWDER_KEG_CHALLENGE,             POWDER_KEG,                   {Category::cGoronVillage,Category::cDayOne},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_SCRUB_PURCHASE]                       = ItemLocation::Base       (0x4D, 0x1D, false, "GV Scrub Purchase",                                        GORON_VILLAGE_SCRUB_PURCHASE,                   PROGRESSIVE_BOMB_BAG,         {Category::cGoronVillage, Category::cDekuScrub,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST]                  = ItemLocation::Chest      (0x07, 0x01, true,  "GV Lens of Truth Chest",                                   GORON_VILLAGE_LENS_OF_TRUTH_CHEST,              LENS_OF_TRUTH,                {Category::cGoronVillage,Category::cChest,Category::cDayOne },                                                                                                         SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_SCRUB_TRADE]                          = ItemLocation::Base       (0x4D, 0x99, true,  "GV Deku Scrub Merchant Trade",                             GORON_VILLAGE_SCRUB_TRADE,                      MOUNTAIN_TITLE,               {Category::cGoronVillage, Category::cDekuScrub,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_LEDGE]                                = ItemLocation::Collectable(0x4D, 0x00, false, "GV Piece of Heart",                                        GORON_VILLAGE_LEDGE,                            PIECE_OF_HEART,               {Category::cGoronVillage, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                             SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_GORON_LULLABY]                        = ItemLocation::Base       (0x32, 0x4D, false, "GV Goron Lullaby",                                         GORON_VILLAGE_GORON_LULLABY,                    GORONS_LULLABY,               {Category::cGoronVillage, Category::cSong,Category::cDayOne},                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[LENS_CAVE_RED_RUPEE]                                = ItemLocation::Chest      (0x07, 0x03, true,  "GV Lens Cave Invisible Chest",                             LENS_CAVE_RED_RUPEE,                            RED_RUPEE,                    {Category::cGoronVillage,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[LENS_CAVE_PURPLE_RUPEE]                             = ItemLocation::Chest      (0x07, 0x06, true,  "GV Lens Cave Rock Chest",                                  LENS_CAVE_PURPLE_RUPEE,                         PURPLE_RUPEE,                 {Category::cGoronVillage,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING]          = ItemLocation::Base       (0x48, 0x34, false, "GV Powder Keg Challenge (Spring)",                         GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING,      POWDER_KEG,                   {Category::cGoronVillage,Category::cDayOne},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_SCRUB_PURCHASE_SPRING]                = ItemLocation::Base       (0x48, 0x1D, false, "GV Scrub Purchase (Spring)",                               GORON_VILLAGE_SCRUB_PURCHASE_SPRING,            PROGRESSIVE_BOMB_BAG,         {Category::cGoronVillage, Category::cDekuScrub,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_SCRUB_TRADE_SPRING]                   = ItemLocation::Base       (0x48, 0x99, true,  "GV Deku Scrub Merchant Trade (Spring)",                    GORON_VILLAGE_SCRUB_TRADE_SPRING,               MOUNTAIN_TITLE,               {Category::cGoronVillage, Category::cDekuScrub,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
 locationTable[GORON_VILLAGE_LEDGE_SPRING]                         = ItemLocation::Collectable(0x48, 0x00, false, "GV Piece of Heart (Spring)",                               GORON_VILLAGE_LEDGE_SPRING,                     PIECE_OF_HEART,               {Category::cGoronVillage, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                             SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE );
   
 //Great Bay Coast
 locationTable[GBC_OCEAN_SPIDER_DAY1]                              = ItemLocation::Base       (0x28, 0x48, false, "OSH Day 1 Reward",                                         GBC_OCEAN_SPIDER_DAY1,                          PROGRESSIVE_WALLET,           {Category::cGreatBayCoast ,Category::cDayOne},                                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 //locationTable[GBC_OCEAN_SPIDER_DAY2]                              = ItemLocation::Base       (0x28, 0x00, true,  "OSH Day 2 Reward",                                         GBC_OCEAN_SPIDER_DAY2,                          PURPLE_RUPEE,                 {Category::cGreatBayCoast ,Category::cDayTwo},                                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 //locationTable[GBC_OCEAN_SPIDER_DAY3]                              = ItemLocation::Base       (0x28, 0x00, true,  "OSH Day 3 Reward",                                         GBC_OCEAN_SPIDER_DAY3,                          RED_RUPEE,                    {Category::cGreatBayCoast,Category::cDayThree},                                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_FISHERMAN_GAME]                                 = ItemLocation::Base       (0x37, 0x06, false, "GBC Fisherman's Game",                                     GBC_FISHERMAN_GAME,                             PIECE_OF_HEART,               {Category::cGreatBayCoast, Category::cMinigame,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_OCEAN_SPIDER_CHEST]                             = ItemLocation::Chest      (0x28, 0x00, false, "OSH Chest",                                                GBC_OCEAN_SPIDER_CHEST,                         PIECE_OF_HEART,               {Category::cGreatBayCoast, Category::cVanillaHeartPiece ,Category::cDayOne,Category::cChest},                                                                          SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_LAB_FISH]                                       = ItemLocation::Collectable(0x2F, 0x00, false, "GBC Marine Lab Fish HP",                                   GBC_LAB_FISH,                                   PIECE_OF_HEART,               {Category::cGreatBayCoast, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                            SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_LEDGE]                                          = ItemLocation::Collectable(0x37, 0x00, false, "GBC Ledge",                                                GBC_LEDGE,                                      PIECE_OF_HEART,               {Category::cGreatBayCoast, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                            SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_MIKAU]                                          = ItemLocation::Base       (0x37, 0x7A, false, "GBC Mikau",                                                GBC_MIKAU,                                      ZORA_MASK,                    {Category::cGreatBayCoast, Category::cTransformMask,Category::cDayOne},                                                    SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_BABY_ZORAS]                                     = ItemLocation::Base       (0x2F, 0x4E, false, "GBC Marine Lab Baby Zoras",                                GBC_BABY_ZORAS,                                 NEW_WAVE_BOSSA_NOVA,          {Category::cGreatBayCoast, Category::cSong,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_GROTTO_CHEST]                                   = ItemLocation::Chest      (0x07, 0x17, true,  "GBC Grotto Chest",                                         GREAT_BAY_COAST_GROTTO,                         RED_RUPEE,                    {Category::cGreatBayCoast,Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
 locationTable[GBC_FISHERMAN_PHOTO]                                = ItemLocation::Base       (0x3C, 0x95, false,  "GBC Fisherman Photo",                                      GBC_FISHERMAN_PHOTO,                            SEAHORSE,                     {Category::cGreatBayCoast,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST );
    
 //Ikana Canyon
 locationTable[IKANA_CANYON_GREAT_FAIRY]                           = ItemLocation::Base       (0x26, 0x3B, false, "IC Great Fairy",                                           IKANA_CANYON_GREAT_FAIRY,                       GREAT_FAIRYS_SWORD,           {Category::cIkanaCanyon,Category::cDayOne, Category::cFairyFountain},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_POE_HUT_HP]                            = ItemLocation::Base       (0x51, 0x0C, false, "IC Poe Hut",                                               IKANA_CANYON_POE_HUT_HP,                        PIECE_OF_HEART,               {Category::cIkanaCanyon, Category::cVanillaHeartPiece,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_LEDGE]                                 = ItemLocation::Collectable(0x13, 0x00, false, "IC Ledge",                                                 IKANA_CANYON_LEDGE,                             PIECE_OF_HEART,               {Category::cIkanaCanyon, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_PAMELAS_FATHER]                        = ItemLocation::Base       (0x55, 0x87, false, "IC Pamela's Father",                                       IKANA_CANYON_PAMELAS_FATHER,                    GIBDOS_MASK,                  {Category::cIkanaCanyon, Category::cVanillaMask,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST]            = ItemLocation::Chest      (0x07, 0x14, true,  "IC Secret Shrine Grotto",                                  IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST,        BOMBCHU_5,                    {Category::cIkanaCanyon, Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_SCRUB_TRADE]                           = ItemLocation::Base       (0x13, 0x07, true,  "IC Deku Scrub Merchant Trade",                             IKANA_CANYON_SCRUB_TRADE,                       HUGE_RUPEE,                   {Category::cIkanaCanyon, Category::cDekuScrub,Category::cDayOne},                                                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[IKANA_CANYON_SCRUB_PURCHASE]                        = ItemLocation::Base       (0x13, 0x5D, true,  "IC Deku Scrub Merchant Purchase",                          IKANA_CANYON_SCRUB_PURCHASE,                    BLUE_POTION_REFILL,           {Category::cIkanaCanyon, Category::cDekuScrub,Category::cDayOne},                                                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 
 //Ikana Graveyard
 locationTable[IKANA_GRAVEYARD_DAMPE_DIGGING]                      = ItemLocation::Chest      (0x30, 0x10, false, "IG Dampe Digging",                                         IKANA_GRAVEYARD_DAMPE_DIGGING,                  PIECE_OF_HEART,               {Category::cIkanaGraveyard, Category::cMinigame,Category::cDayOne},                                                                                                    SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 locationTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST]                 = ItemLocation::Chest      (0x0C, 0x00, false, "IG Iron Knuckle Chest",                                    IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST,             PIECE_OF_HEART,               {Category::cIkanaGraveyard, Category::cVanillaHeartPiece, Category::cChest, Category::cDayTwo},                                                                        SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 locationTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST]                = ItemLocation::Chest      (0x43, 0x00, false, "IG Captain Keeta's Chest",                                 IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST,            CAPTAINS_HAT,                 {Category::cIkanaGraveyard, Category::cVanillaMask,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 locationTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET]               = ItemLocation::Base       (0x0C, 0x73, false, "IG Day 1 Grave Tablet",                                    IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET,           SONG_OF_STORMS,               {Category::cIkanaGraveyard, Category::cSong,Category::cDayOne},                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 locationTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS]                 = ItemLocation::Chest      (0x0C, 0x03, true,  "IG Day 1 Grave Bats",                                      IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS,             PURPLE_RUPEE,                 {Category::cIkanaGraveyard,Category::cChest ,Category::cDayOne},                                                                                                       SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 locationTable[IKANA_GRAVEYARD_GROTTO_CHEST]                       = ItemLocation::Chest      (0x07, 0x18, true,  "IG Grotto",                                                IKANA_GRAVEYARD_GROTTO_CHEST,                   BOMBCHU_5,                    {Category::cIkanaGraveyard, Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                    SpoilerCollectionCheckGroup::GROUP_IKANA_GRAVEYARD );
 
 //Laundry Pool
 locationTable[LAUNDRY_POOL_KAFEI]                                 = ItemLocation::Base       (0x0D, 0xAB, true,  "LP Kafei's Pendant",                                       LAUNDRY_POOL_KAFEI,                             PENDANT_MEMORIES,             {Category::cLaundryPool,Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL );
 locationTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE]                = ItemLocation::Base       (0x0D, 0x80, false, "LP Curiosity Shop Man 1",                                  LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE,            KEATON_MASK,                  {Category::cLaundryPool, Category::cVanillaMask,Category::cDayThree},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL );
 locationTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO]                = ItemLocation::Base       (0x0D, 0xA1, true,  "LP Curiosity Shop Man 2",                                  LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO,            LETTER_MAMA,                  {Category::cLaundryPool,Category::cDayThree},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL );
 locationTable[LAUNDRY_POOL_GURU_GURU]                             = ItemLocation::Base       (0x70, 0x8C, false, "LP Guru Guru",                                             LAUNDRY_POOL_GURU_GURU,                         BREMEN_MASK,                  {Category::cLaundryPool, Category::cVanillaMask,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL );
 
 //Milk Road 
 locationTable[MILK_ROAD_GORMAN_RACE]                              = ItemLocation::Base       (0x6A, 0x81, false, "MR Gorman Track Race",                                     MILK_ROAD_GORMAN_RACE,                          GAROS_MASK,                   {Category::cMilkRoad, Category::cMinigame, Category::cVanillaMask,Category::cDayOne},                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD );
 locationTable[MILK_ROAD_GORMAN_MILK_BUY]                          = ItemLocation::Base       (0x6A, 0x92, true,  "MR Gorman Track Milk Purchase",                            MILK_ROAD_GORMAN_MILK_BUY,                      MILK,                         {Category::cMilkRoad,Category::cDayOne},                                                                                   SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD );
 locationTable[GORMAN_TRACK_MYSTERY_MILK_QUEST]                    = ItemLocation::Base       (0x6A, 0x70, false, "MR Gorman's Mystery Milk Quest",                           GORMAN_TRACK_MYSTERY_MILK_QUEST,                BOTTLE_WITH_MYSTERY_MILK,     {Category::cMilkRoad,Category::cDayTwo},                                                                                   SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD );
 locationTable[MILK_ROAD_KEATON_QUIZ]                              = ItemLocation::Base       (0x22, 0x01, false, "MR Keaton Quiz",                                           MILK_ROAD_KEATON_QUIZ,                          PIECE_OF_HEART,               {Category::cMilkRoad, Category::cDayOne},                                                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD );

 //Mountain Village
 locationTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE]                     = ItemLocation::Base       (0x2C, 0x38, false, "MV Smith Day 1",                                           MOUNTAIN_VILLAGE_SMITH_DAY_ONE,                 RAZOR_SWORD,                  {Category::cMountainVillage,Category::cDayOne},                                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO]                     = ItemLocation::Base       (0x2C, 0x39, false, "MV Smith Day 2",                                           MOUNTAIN_VILLAGE_SMITH_DAY_TWO,                 GILDED_SWORD,                 {Category::cMountainVillage,Category::cDayTwo},                                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_VILLAGE_FROG_CHOIR]                        = ItemLocation::Base       (0x5A, 0x0C, false, "MV Frog Choir",                                            MOUNTAIN_VILLAGE_FROG_CHOIR,                    PIECE_OF_HEART,               {Category::cMountainVillage, Category::cVanillaHeartPiece,Category::cDayOne},                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_VILLAGE_DARMANI]                           = ItemLocation::Base       (0x4E, 0x79, false, "MV Graveyard Darmani",                                     MOUNTAIN_VILLAGE_DARMANI,                       GORON_MASK,                   {Category::cMountainVillage, Category::cTransformMask,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_VILLAGE_HUNGRY_GORON]                      = ItemLocation::Base       (0x50, 0x88, false, "MV Hungry Goron",                                          MOUNTAIN_VILLAGE_HUNGRY_GORON,                  DON_GEROS_MASK,               {Category::cMountainVillage, Category::cVanillaMask,Category::cDayOne},                                                    SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_WATERFALL_CHEST]                           = ItemLocation::Chest      (0x5A, 0x00, true,  "MV Waterfall Chest",                                       MOUNTAIN_WATERFALL_CHEST,                       RED_RUPEE,                    {Category::cMountainVillage,Category::cChest,Category::cDayOne },                                                                                                      SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 locationTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST]         = ItemLocation::Chest      (0x07, 0x1B, true,  "MV Spring Water Grotto",                                   MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST,     RED_RUPEE,                    {Category::cMountainVillage, Category::cGrotto,Category::cChest,Category::cDayOne },                                                                                   SpoilerCollectionCheckGroup::GROUP_MOUNTAIN_VILLAGE );
 
 //N Clock Town
 locationTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU]                      = ItemLocation::Base       (0x26, 0x0E, false, "NCT Great Fairy (Deku)",                                   N_CLOCK_TOWN_GREAT_FAIRY_DEKU,                  PROGRESSIVE_MAGIC_METER,      {Category::cNorthClockTown, Category::cFairyFountain,Category::cDayOne},                                                   SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 //locationTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK]                     = ItemLocation::Base       (0x6E, 0x50, true,  "NCT Bombers Hide n Seek",                                  N_CLOCK_TOWN_BOMBERS_HIDE_SEEK,                 BOMBERS_NOTEBOOK,             {Category::cNorthClockTown,Category::cDayOne},                                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_KEATON_QUIZ]                           = ItemLocation::Base       (0x6E, 0x01, false, "NCT Keaton Quiz",                                          N_CLOCK_TOWN_KEATON_QUIZ,                       PIECE_OF_HEART,               {Category::cNorthClockTown, Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS]                 = ItemLocation::Base       (0x1E, 0x0C, false, "NCT Deku Playground 3 Days Reward",                        N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS,             PIECE_OF_HEART,               {Category::cNorthClockTown, Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayThree},                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_TREE]                                  = ItemLocation::Collectable(0x6E, 0x00, false, "NCT Tree",                                                 N_CLOCK_TOWN_TREE,                              PIECE_OF_HEART,               {Category::cNorthClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_OLD_LADY]                              = ItemLocation::Base       (0x6E, 0x8D, false, "NCT Old Lady",                                             N_CLOCK_TOWN_OLD_LADY,                          BLAST_MASK,                   {Category::cNorthClockTown, Category::cVanillaMask,Category::cDayOne},                                                     SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN]                     = ItemLocation::Base       (0x26, 0x86, false, "NCT Great Fairy (Human)",                                  N_CLOCK_TOWN_GREAT_FAIRY_HUMAN,                 GREAT_FAIRYS_MASK,            {Category::cNorthClockTown, Category::cFairyFountain, Category::cVanillaMask,Category::cDayOne},                           SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 //locationTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY]                  = ItemLocation::Base       (0x1E, 0x00, true,  "NCT Deku Playground Any Day Reward",                       N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY,              PURPLE_RUPEE,                 {Category::cNClockTown, Category::cMinigame},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 locationTable[N_CLOCK_TOWN_POSTBOX]                               = ItemLocation::Base       (0x6E, 0xBA, false, "NCT Postbox",                                              N_CLOCK_TOWN_POSTBOX,                           PIECE_OF_HEART,               {Category::cNorthClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN );
 
 //Path to Snowhead
 locationTable[ROAD_TO_SNOWHEAD_PILLAR]                            = ItemLocation::Collectable(0x5B, 0x00, false, "Road to Snowhead Pillar",                                  ROAD_TO_SNOWHEAD_PILLAR,                        PIECE_OF_HEART,               {Category::cPathToSnowhead, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_SNOWHEAD );
 locationTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST]                      = ItemLocation::Chest      (0x07, 0x13, true,  "Road to Snowhead Grotto",                                  ROAD_TO_SNOWHEAD_GROTTO_CHEST,                  RED_RUPEE,                    {Category::cPathToSnowhead,Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                     SpoilerCollectionCheckGroup::GROUP_SNOWHEAD );
 
 //Pinnacle Rock
 locationTable[PINNACLE_ROCK_SEAHORSES]                            = ItemLocation::Base       (0x25, 0x0C, false, "PR Seahorses",                                             PINNACLE_ROCK_SEAHORSES,                        PIECE_OF_HEART,               {Category::cPinnacleRock, Category::cVanillaHeartPiece,Category::cDayOne},                                                 SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );
 locationTable[PINNACLE_ROCK_UPPER_CHEST]                          = ItemLocation::Chest      (0x25, 0x02, true,  "PR Upper Chest",                                           PINNACLE_ROCK_UPPER_CHEST,                      RED_RUPEE,                    {Category::cPinnacleRock,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );
 locationTable[PINNACLE_ROCK_LOWER_CHEST]                          = ItemLocation::Chest      (0x25, 0x01, true,  "PR Lower Chest",                                           PINNACLE_ROCK_LOWER_CHEST,                      RED_RUPEE,                    {Category::cPinnacleRock,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );
 locationTable[PINNACLE_ROCK_ZORA_EGG1]                            = ItemLocation::Collectable(0x25, 0x69, true,  "PR Zora Egg 1",                                            PINNACLE_ROCK_ZORA_EGG1,                        ZORA_EGG,                     {Category::cPinnacleRock, Category::cBottleCatch,Category::cDayOne},                                                                                                   SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );
 locationTable[PINNACLE_ROCK_ZORA_EGG2]                            = ItemLocation::Collectable(0x25, 0x69, true,  "PR Zora Egg 2",                                            PINNACLE_ROCK_ZORA_EGG2,                        ZORA_EGG,                     {Category::cPinnacleRock, Category::cBottleCatch,Category::cDayOne},                                                                                                   SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );
 locationTable[PINNACLE_ROCK_ZORA_EGG3]                            = ItemLocation::Collectable(0x25, 0x69, true,  "PR Zora Egg 3",                                            PINNACLE_ROCK_ZORA_EGG3,                        ZORA_EGG,                     {Category::cPinnacleRock, Category::cBottleCatch,Category::cDayOne},                                                                                                   SpoilerCollectionCheckGroup::GROUP_PINNACLE_ROCK );

 //Road to Ikana
 locationTable[ROAD_TO_IKANA_PILLAR_CHEST]                         = ItemLocation::Chest      (0x53, 0x00, true,  "Road to Ikana Pillar Chest",                               ROAD_TO_IKANA_PILLAR_CHEST,                     RED_RUPEE,                    {Category::cRoadToIkana,Category::cChest ,Category::cDayOne},                                                                                                          SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
 locationTable[ROAD_TO_IKANA_GROTTO_CHEST]                         = ItemLocation::Chest      (0x07, 0x16, true,  "Road to Ikana Grotto",                                     ROAD_TO_IKANA_GROTTO_CHEST,                     BOMBCHU_5,                    {Category::cRoadToIkana,Category::cGrotto,Category::cDayOne},                                                                                                          SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON );
  
 //Road to Southern Swamp
 locationTable[ROAD_TO_SS_ARCHERY_1]                               = ItemLocation::Base       (0x24, 0x47, false,  "Road to Southern Swamp Archery 1",                         ROAD_TO_SS_ARCHERY_1,                           PROGRESSIVE_BOW,              {Category::cRoadToSouthernSwamp,Category::cMinigame,Category::cDayOne},                                                    SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[ROAD_TO_SS_ARCHERY_2]                               = ItemLocation::Base       (0x24, 0x0C, false,  "Road to Southern Swamp Archery 2",                         ROAD_TO_SS_ARCHERY_2,                           PIECE_OF_HEART,               {Category::cRoadToSouthernSwamp,Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[ROAD_TO_SS_TREE]                                    = ItemLocation::Collectable(0x40, 0x00, false, "Road to Southern Swamp Tree",                              ROAD_TO_SS_TREE,                                PIECE_OF_HEART,               {Category::cRoadToSouthernSwamp, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[ROAD_TO_SWAMP_GROTTO_CHEST]                         = ItemLocation::Chest      (0x07, 0x1E, true,  "Road to Southern Swamp Grotto",                            ROAD_TO_SWAMP_GROTTO_CHEST,                     RED_RUPEE,                    {Category::cRoadToSouthernSwamp,Category::cGrotto, Category::cChest,Category::cDayOne},                                                                                SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 
 //Romani Ranch
 locationTable[ROMANI_RANCH_ALIEN_DEFENSE]                         = ItemLocation::Base       (0x35, 0x60, true,  "RR Alien Defense",                                         ROMANI_RANCH_ALIEN_DEFENSE,                     BOTTLE_WITH_MILK,             {Category::cRomaniRanch,Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 locationTable[ROMANI_RANCH_DOG_RACE]                              = ItemLocation::Base       (0x41, 0x0C, false,  "RR Dog Race",                                              ROMANI_RANCH_DOG_RACE,                         PIECE_OF_HEART,               {Category::cRomaniRanch,Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 locationTable[ROMANI_RANCH_GROG]                                  = ItemLocation::Base       (0x42, 0x7F, false, "RR Grog",                                                  ROMANI_RANCH_GROG,                              BUNNY_HOOD,                   {Category::cRomaniRanch, Category::cVanillaMask,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 locationTable[ROMANI_RANCH_CREMIA_ESCORT]                         = ItemLocation::Base       (0x2D, 0x82, true,  "RR Cremia Escort",                                         ROMANI_RANCH_CREMIA_ESCORT,                     ROMANIS_MASK,                 {Category::cRomaniRanch, Category::cVanillaMask,Category::cDayTwo},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 locationTable[ROMANI_RANCH_ROMANIS_GAME]                          = ItemLocation::Base       (0x35, 0x6C, false, "RR Romani's Game",                                         ROMANI_RANCH_ROMANIS_GAME,                      EPONAS_SONG,                  {Category::cRomaniRanch,Category::cSong,Category::cDayOne},                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 locationTable[DOGGY_RACETRACK_ROOF_CHEST]                         = ItemLocation::Chest      (0x41, 0x00, true,  "RR Doggy Racetrack Roof Chest",                            DOGGY_RACETRACK_ROOF_CHEST,                     PURPLE_RUPEE,                 {Category::cRomaniRanch,Category::cChest,Category::cDayOne},                                                                                                           SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH );
 
 //S Clock Town
 locationTable[S_CLOCK_TOWN_SCRUB_TRADE]                           = ItemLocation::Base       (0x6F, 0x97, true,  "SCT Scrub Trade",                                          S_CLOCK_TOWN_SCRUB_TRADE,                       LAND_TITLE,                   {Category::cSouthClockTown,Category::cDekuScrub,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_POSTBOX]                               = ItemLocation::Base       (0x6F, 0xBA, false, "SCT Postbox",                                              S_CLOCK_TOWN_POSTBOX,                           PIECE_OF_HEART,               {Category::cSouthClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE]                  = ItemLocation::Collectable(0x6F, 0x00, false, "SCT Clock Tower Entrance",                                 S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE,              PIECE_OF_HEART,               {Category::cSouthClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST]                      = ItemLocation::Chest      (0x6F, 0x00, true,  "SCT Straw Roof Chest",                                     S_CLOCK_TOWN_STRAW_ROOF_CHEST,                  RED_RUPEE,                    {Category::cSouthClockTown,Category::cChest ,Category::cDayOne},                                                                                                       SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_FINAL_DAY_CHEST]                       = ItemLocation::Chest      (0x6F, 0x01, true,  "SCT Final Day Chest",                                      S_CLOCK_TOWN_FINAL_DAY_CHEST,                   PURPLE_RUPEE,                 {Category::cSouthClockTown,Category::cChest ,Category::cDayThree},                                                                                                     SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_BANK_REWARD_1]                         = ItemLocation::Base       (0x6F, 0x48, false, "SCT Bank Reward 1",                                        S_CLOCK_TOWN_BANK_REWARD_1,                     PROGRESSIVE_WALLET,           {Category::cSouthClockTown,Category::cDayOne},                                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_BANK_REWARD_2]                         = ItemLocation::Base       (0x6F, 0x02, false, "SCT Bank Reward 2",                                        S_CLOCK_TOWN_BANK_REWARD_2,                     BLUE_RUPEE,                   {Category::cSouthClockTown,Category::cDayOne},                                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 locationTable[S_CLOCK_TOWN_BANK_REWARD_3]                         = ItemLocation::Base       (0x6F, 0x0C, false, "SCT Bank Reward 3",                                        S_CLOCK_TOWN_BANK_REWARD_3,                     PIECE_OF_HEART,               {Category::cSouthClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_S_CLOCK_TOWN );
 
 //Snowhead
 locationTable[SNOWHEAD_GREAT_FAIRY]                               = ItemLocation::Base       (0x26, 0x2B, false, "SH Great Fairy",                                           SNOWHEAD_GREAT_FAIRY,                           PROGRESSIVE_MAGIC_METER,      {Category::cSnowhead, Category::cFairyFountain,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SNOWHEAD );
 
 //Southern Swamp
 locationTable[SOUTHERN_SWAMP_KOUME]                               = ItemLocation::Base       (0x57, 0x43, false, "SS Koume",                                                 SOUTHERN_SWAMP_KOUME,                           PICTOGRAPH_BOX,               {Category::cSouthernSwamp,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_KOTAKE]                              = ItemLocation::Base       (0x0A, 0x59, false,  "SS Kotake",                                                SOUTHERN_SWAMP_KOTAKE,                          BOTTLE_WITH_RED_POTION,       {Category::cSouthernSwamp,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS]                     = ItemLocation::Base       (0x64, 0x59, false,  "SS Mystery Woods Kotake",                                  SOUTHERN_SWAMP_KOTAKE_IN_WOODS,                 BOTTLE_WITH_RED_POTION,       {Category::cSouthernSwamp,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_SCRUB_TRADE]                         = ItemLocation::Base       (0x45, 0x98, true,  "SS Deku Scrub Merchant Trade",                             SOUTHERN_SWAMP_SCRUB_TRADE,                     SWAMP_TITLE,                  {Category::cSouthernSwamp, Category::cDekuScrub,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER]                   = ItemLocation::Base       (0x57, 0xBA, false, "SS Pictograph Contest Winner",                             SOUTHERN_SWAMP_PICTOGRAPH_WINNER,               PIECE_OF_HEART,               {Category::cSouthernSwamp, Category::cVanillaHeartPiece,Category::cDayOne},                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_BOAT_ARCHERY]                        = ItemLocation::Base       (0x57, 0x5A, false, "SS Boat Archery",                                          SOUTHERN_SWAMP_BOAT_ARCHERY,                    EMPTY_BOTTLE2,                {Category::cSouthernSwamp, Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                           SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SWAMP_TOURIST_CENTER_ROOF]                          = ItemLocation::Collectable(0x45, 0x00, false, "SS Tourist Center Roof",                                   SWAMP_TOURIST_CENTER_ROOF,                      PIECE_OF_HEART,               {Category::cSouthernSwamp, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                            SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD]                 = ItemLocation::Base       (0x27, 0x8A, false, "SSH Reward",                                               SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD,             MASK_OF_TRUTH,                {Category::cSouthernSwamp, Category::cVanillaMask,Category::cDayOne},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_MUSIC_STATUE]                        = ItemLocation::Base       (0x45, 0x72, false, "SS Music Statue",                                          SOUTHERN_SWAMP_MUSIC_STATUE,                    SONG_OF_SOARING,              {Category::cSouthernSwamp, Category::cSong,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST]      = ItemLocation::Chest      (0x07, 0x1D, true,  "SS Near Spider House Grotto",                              SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST,  RED_RUPEE,                    {Category::cSouthernSwamp,Category::cGrotto,Category::cChest,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST]          = ItemLocation::Chest      (0x07, 0x1C, true,  "SS Mystery Woods Grotto",                                  SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST,      PURPLE_RUPEE,                 {Category::cSouthernSwamp, Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                     SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE]                = ItemLocation::Base       (0x0A, 0x5D, true,  "SS Kotake Mushroom Sale",                                  SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE,            RED_RUPEE,                    {Category::cSouthernSwamp,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 //locationTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD]                 = ItemLocation::Base       (0x0A, 0x00, true,  "SS Pictograph Standard",                                   SOUTHERN_SWAMP_PICTOGRAPH_STANDARD,             BLUE_RUPEE,                   {Category::cSouthernSwamp, Category::cMinigame},                                                                           SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 //locationTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD]                     = ItemLocation::Base       (0x0A, 0x00, true,  "SS Pictograph Good",                                       SOUTHERN_SWAMP_PICTOGRAPH_GOOD,                 RED_RUPEE,                    {Category::cSouthernSwamp,Category::cMinigame},                                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );
 locationTable[SOUTHERN_SWAMP_SCRUB_PURCHASE]                      = ItemLocation::Base       (0x45, 0x35, true,  "SS Deku Scrub Merchant Purchase",                          SOUTHERN_SWAMP_SCRUB_PURCHASE,                  MAGIC_BEAN,                   {Category::cSouthernSwamp, Category::cDekuScrub,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP );

 //Stock Pot Inn
 locationTable[STOCKPOTINN_RESERVATION]                            = ItemLocation::Base       (0x61, 0xA0, true,  "SPI Reservation",                                          STOCKPOTINN_RESERVATION,                        ROOM_KEY,                     {Category::cStockPotInn,Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_MIDNIGHT_MEETING]                       = ItemLocation::Base       (0x61, 0xAA, true,  "SPI Midnight Meeting",                                     STOCKPOTINN_MIDNIGHT_MEETING,                   LETTER_KAFEI,                 {Category::cStockPotInn,Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_TOILET_HAND]                            = ItemLocation::Base       (0x61, 0x01, false,  "SPI Toilet Hand",                                          STOCKPOTINN_TOILET_HAND,                        PIECE_OF_HEART,               {Category::cStockPotInn, Category::cVanillaHeartPiece,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_GRANDMA_SHORT_STORY]                    = ItemLocation::Base       (0x61, 0x0C, false,  "SPI Grandma Short Story",                                  STOCKPOTINN_GRANDMA_SHORT_STORY,                PIECE_OF_HEART,               {Category::cStockPotInn, Category::cVanillaHeartPiece,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_GRANDMA_LONG_STORY]                     = ItemLocation::Base       (0x61, 0xBA, false,  "SPI Grandma Long Story",                                   STOCKPOTINN_GRANDMA_LONG_STORY,                 PIECE_OF_HEART,               {Category::cStockPotInn, Category::cVanillaHeartPiece,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_ANJU_AND_KAFEI]                         = ItemLocation::Base       (0x61, 0x85, false,  "SPI Anju And Kafei",                                       STOCKPOTINN_ANJU_AND_KAFEI,                     COUPLES_MASK,                 {Category::cStockPotInn, Category::cVanillaMask,Category::cDayThree},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_STAFF_ROOM_CHEST]                       = ItemLocation::Chest      (0x61, 0x01, true,  "SPI Staff Room Chest",                                     STOCKPOTINN_STAFF_ROOM_CHEST,                   SILVER_RUPEE,                 {Category::cStockPotInn,Category::cChest ,Category::cDayThree},                                                                                                        SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 locationTable[STOCKPOTINN_GUEST_ROOM_CHEST]                       = ItemLocation::Chest      (0x61, 0x00, true,  "SPI Guest Room Chest",                                     STOCKPOTINN_GUEST_ROOM_CHEST,                   SILVER_RUPEE,                 {Category::cStockPotInn,Category::cChest ,Category::cDayOne},                                                                                                          SpoilerCollectionCheckGroup::GROUP_STOCKPOTINN );
 
 //Stone Tower
 locationTable[STONE_TOWER_INVERTED_RIGHT_CHEST]                   = ItemLocation::Chest      (0x59, 0x1D, true,  "IST Right Chest",                                          STONE_TOWER_INVERTED_RIGHT_CHEST,               SILVER_RUPEE,                 {Category::cStoneTower,Category::cChest,Category::cDayOne},                                                                                                            SpoilerCollectionCheckGroup::GROUP_STONE_TOWER );
 locationTable[STONE_TOWER_INVERTED_CENTER_CHEST]                  = ItemLocation::Chest      (0x59, 0x1E, true,  "IST Center Chest",                                         STONE_TOWER_INVERTED_CENTER_CHEST,              BOMBCHU_10,                   {Category::cStoneTower,Category::cChest,Category::cDayOne},                                                                                                            SpoilerCollectionCheckGroup::GROUP_STONE_TOWER );
 locationTable[STONE_TOWER_INVERTED_LEFT_CHEST]                    = ItemLocation::Chest      (0x59, 0x1F, true,  "IST Left Chest",                                           STONE_TOWER_INVERTED_LEFT_CHEST,                MAGIC_BEAN,                   {Category::cStoneTower,Category::cChest,Category::cDayOne},                                                                                                            SpoilerCollectionCheckGroup::GROUP_STONE_TOWER );
 
 //Termina Field
 locationTable[TERMINA_FIELD_MOONS_TEAR]                           = ItemLocation::Base       (0x2D, 0x96, true,  "TF Moon's Tear",                                           TERMINA_FIELD_MOONS_TEAR,                       MOONS_TEAR,                   {Category::cTerminaField,Category::cDayOne},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_GOSSIP_STONES]                        = ItemLocation::Base       (0x07, 0x0C, false, "TF Gossip Stones",                                         TERMINA_FIELD_GOSSIP_STONES,                    PIECE_OF_HEART,               {Category::cTerminaField,Category::cGrotto, Category::cVanillaHeartPiece,Category::cDayOne},                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_BUSINESS_SCRUB]                       = ItemLocation::Base       (0x07, 0x01, false, "TF Business Scrub",                                        TERMINA_FIELD_BUSINESS_SCRUB,                   PIECE_OF_HEART,               {Category::cTerminaField,Category::cGrotto,Category::cDekuScrub, Category::cVanillaHeartPiece,Category::cDayOne},          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST]                  = ItemLocation::Chest      (0x07, 0x04, true,  "TF Peahat Grotto Chest",                                   TERMINA_FIELD_PEAHAT_GROTTO_CHEST,              PIECE_OF_HEART,               {Category::cTerminaField,Category::cGrotto, Category::cVanillaHeartPiece,Category::cDayOne},                                                                           SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST]                 = ItemLocation::Chest      (0x07, 0x00, true,  "TF Dodongo Grotto Chest",                                  TERMINA_FIELD_DODONGO_GROTTO_CHEST,             PIECE_OF_HEART,               {Category::cTerminaField,Category::cGrotto, Category::cVanillaHeartPiece, Category::cChest, Category::cDayOne},                                                        SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE]              = ItemLocation::Collectable(0x07, 0x00, false, "TF Bio Baba Grotto HP",                                    TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE,          PIECE_OF_HEART,               {Category::cTerminaField,Category::cGrotto, Category::cVanillaHeartPiece, Category::cChest, Category::cDayOne},                                                        SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_KAMARO]                               = ItemLocation::Base       (0x2D, 0x89, false, "TF Kamaro",                                                TERMINA_FIELD_KAMARO,                           KAMAROS_MASK,                 {Category::cTerminaField, Category::cVanillaMask,Category::cDayOne},                                                       SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST]                  = ItemLocation::Chest      (0x07, 0x1A, true,  "TF Pillar Grotto Chest",                                   TERMINA_FIELD_PILLAR_GROTTO_CHEST,              BOMBCHU_5,                    {Category::cTerminaField,Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_GRASS_GROTTO_CHEST]                   = ItemLocation::Chest      (0x07, 0x1F, true,  "TF Grass Grotto Chest",                                    TERMINA_FIELD_GRASS_GROTTO_CHEST,               RED_RUPEE,                    {Category::cTerminaField,Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_UNDERWATER_CHEST]                     = ItemLocation::Chest      (0x2D, 0x00, true,  "TF Underwater Chest",                                      TERMINA_FIELD_UNDERWATER_CHEST,                 RED_RUPEE,                    {Category::cTerminaField,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_GRASS_CHEST]                          = ItemLocation::Chest      (0x2D, 0x01, true,  "TF Grass Chest",                                           TERMINA_FIELD_GRASS_CHEST,                      RED_RUPEE,                    {Category::cTerminaField,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 locationTable[TERMINA_FIELD_STUMP_CHEST]                          = ItemLocation::Chest      (0x2D, 0x02, true,  "TF Stump Chest",                                           TERMINA_FIELD_STUMP_CHEST,                      RED_RUPEE,                    {Category::cTerminaField,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD );
 
 //Twin Islands
 locationTable[HOT_SPRING_WATER_GROTTO_CHEST]                      = ItemLocation::Chest      (0x07, 0x02, true,  "TI Hot Spring Water Grotto Chest",                         HOT_SPRING_WATER_GROTTO_CHEST,                  RED_RUPEE,                    {Category::cTwinIslands, Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 locationTable[TWIN_ISLANDS_GORON_RACE]                            = ItemLocation::Base       (0x6B, 0x6A, true,  "TI Goron Racetrack Race",                                  TWIN_ISLANDS_GORON_RACE,                        GOLD_DUST,                    {Category::cTwinIslands,Category::cDayOne},                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 locationTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST]          = ItemLocation::Chest      (0x07, 0x19, true,  "TI Goron Racetrack Grotto",                                TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST,      BOMBCHU_5,                    {Category::cTwinIslands, Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                       SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 locationTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST]                 = ItemLocation::Chest      (0x5E, 0x06, true,  "TI Underwater Ramp Chest",                                 TWIN_ISLANDS_UNDERWATER_RAMP_CHEST,             PIECE_OF_HEART,               {Category::cTwinIslands, Category::cVanillaHeartPiece, Category::cChest, Category::cDayOne},                                                                           SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 locationTable[TWIN_ISLANDS_CAVE_CHEST]                            = ItemLocation::Chest      (0x5E, 0x00, true,  "TI Cave Chest",                                            TWIN_ISLANDS_CAVE_CHEST,                        RED_RUPEE,                    {Category::cTwinIslands,Category::cChest ,Category::cDayOne},                                                                                                          SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 locationTable[TWIN_ISLANDS_LULLABY_INTRO]                         = ItemLocation::Base       (0x5D, 0x00, false, "TI Lullaby Intro",                                         TWIN_ISLANDS_LULLABY_INTRO,                     LULLABY_INTRO,                {Category::cTwinIslands, Category::cSong, Category::cDayOne},                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS );
 //W Clock Town
 locationTable[W_CLOCK_TOWN_BOMB_BAG_BUY]                          = ItemLocation::Base       (0x0D, 0x1B, false, "WCT Bomb Bag Purchase",                                    W_CLOCK_TOWN_BOMB_BAG_BUY,                      PROGRESSIVE_BOMB_BAG,         {Category::cWestClockTown,Category::cDayOne},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY]                      = ItemLocation::Base       (0x0D, 0x1C, false, "WCT Big Bomb Bag Purchase",                                W_CLOCK_TOWN_BIG_BOMB_BAG_BUY,                  PROGRESSIVE_BOMB_BAG,         {Category::cWestClockTown,Category::cDayTwo},                                                                              SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_POSTMANS_GAME]                         = ItemLocation::Base       (0x2E, 0x0C, false,  "WCT Postman's Game",                                       W_CLOCK_TOWN_POSTMANS_GAME,                     PIECE_OF_HEART,               {Category::cWestClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_ROSA_SISTERS]                          = ItemLocation::Base       (0x6D, 0x0C, false,  "WCT Rosa Sisters",                                         W_CLOCK_TOWN_ROSA_SISTERS,                      PIECE_OF_HEART,               {Category::cWestClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL]                     = ItemLocation::Base       (0x54, 0x0C, false,  "WCT Swordsman's School",                                   W_CLOCK_TOWN_SWORDSMANS_SCHOOL,                 PIECE_OF_HEART,               {Category::cWestClockTown, Category::cVanillaHeartPiece,Category::cDayOne},                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY]                    = ItemLocation::Base       (0x0D, 0x7E, false,  "WCT All-Night Mask Purchase",                              W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY,                ALL_NIGHT_MASK,               {Category::cWestClockTown, Category::cVanillaMask,Category::cDayThree},                                                    SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 //locationTable[W_CLOCK_TOWN_LOTTERY]                               = ItemLocation::Base       (0x39, 0x00, true,  "WCT Lottery",                                              W_CLOCK_TOWN_LOTTERY,                           PURPLE_RUPEE,                 {Category::cWestClockTown},                                                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 locationTable[W_CLOCK_TOWN_BOMB_SHOP_GORON]                       = ItemLocation::Base       (0x0D, 0x34, true,  "WCT Bomb Shop Goron",                                      W_CLOCK_TOWN_BOMB_SHOP_GORON,                   POWDER_KEG,                   {Category::cWestClockTown, Category::cMerchant,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN );
 
 //Woodfall
 locationTable[WOODFALL_BRIDGE_CHEST]                              = ItemLocation::Chest      (0x46, 0x01, true,  "WF Bridge Chest",                                          WOODFALL_BRIDGE_CHEST,                          PIECE_OF_HEART,               {Category::cWoodfall, Category::cVanillaHeartPiece, Category::cChest, Category::cDayOne},                                                                              SpoilerCollectionCheckGroup::GROUP_WOODFALL );
 locationTable[WOODFALL_BEHIND_OWL_CHEST]                          = ItemLocation::Chest      (0x46, 0x02, true,  "WF Behind Owl Chest",                                      WOODFALL_BEHIND_OWL_CHEST,                      BLUE_RUPEE,                   {Category::cWoodfall,Category::cChest ,Category::cDayOne},                                                                                                             SpoilerCollectionCheckGroup::GROUP_WOODFALL );
 locationTable[ENTRANCE_TO_WOODFALL_CHEST]                         = ItemLocation::Chest      (0x46, 0x00, true,  "WF Entrance to Woodfall Chest",                            ENTRANCE_TO_WOODFALL_CHEST,                     RED_RUPEE,                    {Category::cWoodfall,Category::cChest ,Category::cDayOne},                                                                                                             SpoilerCollectionCheckGroup::GROUP_WOODFALL );
 locationTable[WOODFALL_GREAT_FAIRY]                               = ItemLocation::Base       (0x26, 0x2C, false, "WF Great Fairy",                                           WOODFALL_GREAT_FAIRY,                           SPIN_ATTACK,                  {Category::cWoodfall, Category::cFairyFountain,Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_WOODFALL );
 
 //Zora Cape
 locationTable[ZORA_CAPE_GREAT_FAIRY]                              = ItemLocation::Base       (0x26, 0xB2, false, "ZC Great Fairy",                                           ZORA_CAPE_GREAT_FAIRY,                          DOUBLE_DEFENSE,               {Category::cZoraCape,Category::cFairyFountain,Category::cDayOne},                                                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_BEAVER_RACE_1]                            = ItemLocation::Base       (0x4A, 0x5A, false,  "ZC Beaver Race 1",                                         ZORA_CAPE_BEAVER_RACE_1,                        EMPTY_BOTTLE1,                {Category::cZoraCape,Category::cMinigame,Category::cDayOne},                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_BEAVER_RACE_2]                            = ItemLocation::Base       (0x4A, 0x0C, false,  "ZC Beaver Race 2",                                         ZORA_CAPE_BEAVER_RACE_2,                        PIECE_OF_HEART,               {Category::cZoraCape,Category::cMinigame, Category::cVanillaHeartPiece,Category::cDayOne},                                 SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_LIKE_LIKE]                                = ItemLocation::Collectable(0x38, 0x00, false, "ZC Like Like HP",                                          ZORA_CAPE_LIKE_LIKE,                            PIECE_OF_HEART,               {Category::cZoraCape, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_LEDGE_NO_TREE]                            = ItemLocation::Chest      (0x38, 0x01, true,  "ZC Ledge Without Tree Chest",                              ZORA_CAPE_LEDGE_NO_TREE,                        RED_RUPEE,                    {Category::cZoraCape,Category::cChest ,Category::cDayOne},                                                                                                             SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_LEDGE_WITH_TREE]                          = ItemLocation::Chest      (0x38, 0x02, true,  "ZC Ledge With Tree Chest",                                 ZORA_CAPE_LEDGE_WITH_TREE,                      RED_RUPEE,                    {Category::cZoraCape,Category::cChest ,Category::cDayOne},                                                                                                             SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_GROTTO_CHEST]                             = ItemLocation::Chest      (0x07, 0x15, true,  "ZC Grotto Chest",                                          ZORA_CAPE_GROTTO_CHEST,                         BOMBCHU_5,                    {Category::cZoraCape,Category::cGrotto,Category::cChest ,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 locationTable[ZORA_CAPE_UNDERWATER_CHEST]                         = ItemLocation::Chest      (0x38, 0x00, true,  "ZC Underwater Chest",                                      ZORA_CAPE_UNDERWATER_CHEST,                     PURPLE_RUPEE,                 {Category::cZoraCape,Category::cChest ,Category::cDayOne},                                                                                                             SpoilerCollectionCheckGroup::GROUP_ZORA_CAPE );
 
 //Zora Hall
 locationTable[ZORA_HALL_SCRUB_TRADE]                              = ItemLocation::Base       (0x4C, 0x9A, true,  "ZH Deku Scrub Merchant Trade",                             ZORA_HALL_SCRUB_TRADE,                          OCEAN_TITLE,                  {Category::cZoraHall, Category::cDekuScrub,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 locationTable[ZORA_HALL_EVAN]                                     = ItemLocation::Base       (0x4C, 0x0C, false, "ZH Deku Evan",                                             ZORA_HALL_EVAN,                                 PIECE_OF_HEART,               {Category::cZoraHall, Category::cVanillaHeartPiece,Category::cDayOne},                                                     SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 locationTable[ZORA_HALL_LULU_ROOM_LEDGE]                          = ItemLocation::Collectable(0x4C, 0x00, false, "ZH Lulu's Room Ledge",                                     ZORA_HALL_LULU_ROOM_LEDGE,                      PIECE_OF_HEART,               {Category::cZoraHall, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 locationTable[ZORA_HALL_SCRUB_PURCHASE]                           = ItemLocation::Base       (0x4C, 0x5C, true,  "ZH Deku Scrub Merchant Purchase",                          ZORA_HALL_SCRUB_PURCHASE,                       GREEN_POTION_REFILL,          {Category::cZoraHall, Category::cDekuScrub,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 //locationTable[ZORA_HALL_STAGE_LIGHTS]                             = ItemLocation::Base       (0x33, 0x00, true, "ZH Stage Lights",                                           ZORA_HALL_STAGE_LIGHTS,                         BLUE_RUPEE,                   {Category::cZoraHall},                                                                                                     SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 //locationTable[ZORA_HALL_BAD_PHOTO_LULU]                           = ItemLocation::Base       (0x4C, 0x00, true, "ZH Bad Photograph of Lulu",                                 ZORA_HALL_SCRUB_TRADE,                          BLUE_RUPEE,                   {Category::cZoraHall, Category::cDekuScrub},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 //locationTable[ZORA_HALL_GOOD_PHOTO_LULU]                          = ItemLocation::Base       (0x4C, 0x00, true, "ZH Good Photograph of Lulu",                                ZORA_HALL_SCRUB_TRADE,                          BLUE_RUPEE,                   {Category::cZoraHall, Category::cDekuScrub},                                                                               SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_ZORA_HALL );
 
 
 /*-------------------
       --- DUNGEONS --
      -------------------*/
 

 //Woodfall Temple
 locationTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST]                    = ItemLocation::Chest      (0x1B, 0x1B, true,  "Woodfall Temple Hero's Bow Chest",                         WOODFALL_TEMPLE_HEROS_BOW_CHEST,                PROGRESSIVE_BOW,              {Category::cWoodfall, Category::cWoodfallTemple,Category::cChest ,Category::cDayOne},                                                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WOODFALL_TEMPLE_MAP_CHEST]                          = ItemLocation::Chest      (0x1B, 0x1D, true,  "Woodfall Temple Map Chest",                                WOODFALL_TEMPLE_MAP_CHEST,                      WOODFALL_MAP,                 {Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaMap,Category::cDayOne},                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WOODFALL_TEMPLE_COMPASS_CHEST]                      = ItemLocation::Chest      (0x1B, 0x1C, true,  "Woodfall Temple Compass Chest",                            WOODFALL_TEMPLE_COMPASS_CHEST,                  WOODFALL_TEMPLE_COMPASS,      {Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaCompass,Category::cDayOne},                                                                          SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST]                     = ItemLocation::Chest      (0x1B, 0x1E, true,  "Woodfall Temple Boss Key Chest",                           WOODFALL_TEMPLE_BOSS_KEY_CHEST,                 WOODFALL_TEMPLE_BOSS_KEY,     {Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaBossKey,Category::cDayOne},                                                                          SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST]                    = ItemLocation::Chest      (0x1B, 0x01, true,  "Woodfall Temple Small Key Chest",                          WOODFALL_TEMPLE_SMALL_KEY_CHEST,                WOODFALL_TEMPLE_SMALL_KEY,    {Category::cWoodfall, Category::cWoodfallTemple,Category::cVanillaSmallKey,Category::cDayOne},                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[GIANTS_OATH_TO_ORDER]                               = ItemLocation::Base       (0x69, 0x51, false, "Oath to Order",                                            GIANTS_OATH_TO_ORDER,                           OATH_TO_ORDER,                {Category::cWoodfall, Category::cWoodfallTemple, Category::cSong,Category::cDayOne},                                       SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WOODFALL_TEMPLE_DEKU_PRINCESS]                      = ItemLocation::Base       (0x1B, 0x5F, true,  "Deku Princess",                                            WOODFALL_TEMPLE_DEKU_PRINCESS,                  DEKU_PRINCESS,                {Category::cWoodfall, Category::cWoodfallTemple, Category::cBottleCatch,Category::cDayOne},                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );

 //Snowhead Temple
 locationTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST]                   = ItemLocation::Chest      (0x21, 0x1B, true,  "Snowhead Temple Fire Arrow Chest",                         SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST,               FIRE_ARROWS,                  {Category::cSnowhead, Category::cSnowheadTemple,Category::cChest ,Category::cDayOne},                                                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_MAP_CHEST]                          = ItemLocation::Chest      (0x21, 0x1D, true,  "Snowhead Temple Map Chest",                                SNOWHEAD_TEMPLE_MAP_CHEST,                      SNOWHEAD_TEMPLE_MAP,          {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaMap,Category::cDayOne},                                                                             SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_COMPASS_CHEST]                      = ItemLocation::Chest      (0x21, 0x1C, true,  "Snowhead Temple Compass Chest",                            SNOWHEAD_TEMPLE_COMPASS_CHEST,                  SNOWHEAD_TEMPLE_COMPASS,      {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaCompass,Category::cDayOne},                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST]                     = ItemLocation::Chest      (0x21, 0x1E, true,  "Snowhead Temple Boss Key Chest",                           SNOWHEAD_TEMPLE_BOSS_KEY_CHEST,                 SNOWHEAD_TEMPLE_BOSS_KEY,     {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaBossKey,Category::cDayOne},                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST]                   = ItemLocation::Chest      (0x21, 0x03, true,  "Snowhead Temple Block Room Chest",                         SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST,               SNOWHEAD_TEMPLE_SMALL_KEY,    {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST]                  = ItemLocation::Chest      (0x21, 0x04, true,  "Snowhead Temple Icicle Room Chest",                        SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST,              SNOWHEAD_TEMPLE_SMALL_KEY,    {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST]                  = ItemLocation::Chest      (0x21, 0x01, true,  "Snowhead Temple Bridge Room Chest",                        SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST,              SNOWHEAD_TEMPLE_SMALL_KEY,    {Category::cSnowhead, Category::cSnowheadTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 
 //Great Bay Temple
 locationTable[GBT_ICE_ARROW_CHEST]                                = ItemLocation::Chest      (0x49, 0x1B, true,  "Great Bay Temple Ice Arrow Chest",                         GBT_ICE_ARROW_CHEST,                            ICE_ARROWS,                   {Category::cGreatBayTemple,Category::cChest,Category::cDayOne},                                                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY ); 
 locationTable[GBT_MAP_CHEST]                                      = ItemLocation::Chest      (0x49, 0x1D, true,  "Great Bay Temple Map Chest",                               GBT_MAP_CHEST,                                  GBT_MAP,                      {Category::cGreatBayTemple, Category::cVanillaMap,Category::cDayOne},                                                                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_COMPASS_CHEST]                                  = ItemLocation::Chest      (0x49, 0x1C, true,  "Great Bay Temple Compass Chest",                           GBT_COMPASS_CHEST,                              GBT_COMPASS,                  {Category::cGreatBayTemple, Category::cVanillaCompass,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_BOSS_KEY_CHEST]                                 = ItemLocation::Chest      (0x49, 0x1E, true,  "Great Bay Temple Boss Key Chest",                          GBT_BOSS_KEY_CHEST,                             GBT_BOSS_KEY,                 {Category::cGreatBayTemple, Category::cVanillaBossKey,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SMALL_KEY_CHEST]                                = ItemLocation::Chest      (0x49, 0x01, true,  "Great Bay Temple Small Key Chest",                         GBT_SMALL_KEY_CHEST,                            GBT_SMALL_KEY,                {Category::cGreatBayTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                                             SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 
 //Stone Tower Temple
 locationTable[STONE_TOWER_TEMPLE_MAP_CHEST]                       = ItemLocation::Chest      (0x16, 0x1D, true,  "Stone Tower Temple Map Chest",                             STONE_TOWER_TEMPLE_MAP_CHEST,                   STONE_TOWER_TEMPLE_MAP,       {Category::cStoneTowerTemple, Category::cVanillaMap,Category::cDayOne},                                                                                                SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_COMPASS_CHEST]                   = ItemLocation::Chest      (0x16, 0x1C, true,  "Stone Tower Temple Compass Chest",                         STONE_TOWER_TEMPLE_COMPASS_CHEST,               STONE_TOWER_TEMPLE_COMPASS,   {Category::cStoneTowerTemple, Category::cVanillaCompass,Category::cDayOne},                                                                                            SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST]                  = ItemLocation::Chest      (0x18, 0x1E, true,  "Stone Tower Temple Boss Key Chest",                        STONE_TOWER_TEMPLE_BOSS_KEY_CHEST,              STONE_TOWER_TEMPLE_BOSS_KEY,  {Category::cStoneTowerTemple, Category::cVanillaBossKey,Category::cDayOne},                                                                                            SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST]                = ItemLocation::Chest      (0x16, 0x02, true,  "Stone Tower Temple Armos Room Chest",                      STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST,            STONE_TOWER_TEMPLE_SMALL_KEY, {Category::cStoneTowerTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST]             = ItemLocation::Chest      (0x16, 0x01, true,  "Stone Tower Temple Bridge Switch Chest",                   STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST,         STONE_TOWER_TEMPLE_SMALL_KEY, {Category::cStoneTowerTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST]              = ItemLocation::Chest      (0x18, 0x04, true,  "Stone Tower Temple Updraft Room Chest",                    STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST,          STONE_TOWER_TEMPLE_SMALL_KEY, {Category::cStoneTowerTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST]          = ItemLocation::Chest      (0x18, 0x05, true,  "Stone Tower Temple Death Armos Room Chest",                STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST,      STONE_TOWER_TEMPLE_SMALL_KEY, {Category::cStoneTowerTemple, Category::cVanillaSmallKey,Category::cDayOne},                                                                                           SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST]               = ItemLocation::Chest      (0x16, 0x1B, true,  "Stone Tower Temple Light Arrow Chest",                     STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST,           LIGHT_ARROWS,                 {Category::cStoneTowerTemple,Category::cChest ,Category::cDayOne},                                                                                                     SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST]               = ItemLocation::Chest      (0x36, 0x00, false,  "Stone Tower Temple Giant's Mask Chest",                    STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST,           GIANTS_MASK,                  {Category::cStoneTowerTemple,Category::cChest, Category::cVanillaMask ,Category::cDayOne},                                                                             SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 
 //Pirate Fortress 
 locationTable[PF_INTERIOR_HOOKSHOT_CHEST]                         = ItemLocation::Chest      (0x23, 0x02, true,  "Pirate's Fortress Int Hookshot Chest",                     PF_INTERIOR_HOOKSHOT_CHEST,                     HOOKSHOT,                     {Category::cPiratesFortressInterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_LOWER_CHEST]                                 = ItemLocation::Chest      (0x14, 0x00, true,  "Pirate's Fortress Int Lower Chest",                        PF_INT_LOWER_CHEST,                             RED_RUPEE,                    {Category::cPiratesFortressInterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_UPPER_CHEST]                                 = ItemLocation::Chest      (0x14, 0x01, true,  "Pirate's Fortress Int Upper Chest",                        PF_INT_UPPER_CHEST,                             RED_RUPEE,                    {Category::cPiratesFortressInterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_TANK_CHEST]                                  = ItemLocation::Chest      (0x23, 0x00, true,  "Pirate's Fortress Int Tank Chest",                         PF_INT_TANK_CHEST,                              RED_RUPEE,                    {Category::cPiratesFortressInterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_GUARD_ROOM_CHEST]                            = ItemLocation::Chest      (0x23, 0x03, true,  "Pirate's Fortress Int Guard Room Chest",                   PF_INT_GUARD_ROOM_CHEST,                        SILVER_RUPEE,                 {Category::cPiratesFortressInterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_CAGE_ROOM_SHALLOW_CHEST]                         = ItemLocation::Chest      (0x23, 0x04, true,  "Pirate's Fortress Sewer Cage Room Shallow Chest",          PF_CAGE_ROOM_SHALLOW_CHEST,                     RED_RUPEE,                    {Category::cPiratesFortressSewer,Category::cChest ,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_CAGE_ROOM_DEEP_CHEST]                            = ItemLocation::Chest      (0x23, 0x06, true,  "Pirate's Fortress Sewer Cage Room Deep Chest",             PF_CAGE_ROOM_DEEP_CHEST,                        BLUE_RUPEE,                   {Category::cPiratesFortressSewer,Category::cChest ,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_MAZE_CHEST]                                      = ItemLocation::Chest      (0x23, 0x01, true,  "Pirate's Fortress Sewer Maze Chest",                       PF_MAZE_CHEST,                                  RED_RUPEE,                    {Category::cPiratesFortressSewer,Category::cChest ,Category::cDayOne},                                                                                                 SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_SEWER_CAGE]                                      = ItemLocation::Collectable(0x23, 0x00, false, "Pirate's Fortress Sewer Cage",                             PF_SEWER_CAGE,                                  PIECE_OF_HEART,               {Category::cPiratesFortressSewer, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                     SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_EXTERIOR_LOG_CHEST]                              = ItemLocation::Chest      (0x3B, 0x00, true,  "Pirate's Fortress Ext Log Chest",                          PF_EXTERIOR_LOG_CHEST,                          RED_RUPEE,                    {Category::cPiratesFortressExterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_EXTERIOR_SAND_CHEST]                             = ItemLocation::Chest      (0x3B, 0x01, true,  "Pirate's Fortress Ext Sand Chest",                         PF_EXTERIOR_SAND_CHEST,                         RED_RUPEE,                    {Category::cPiratesFortressExterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_EXTERIOR_CORNER_CHEST]                           = ItemLocation::Chest      (0x3B, 0x02, true,  "Pirate's Fortress Ext Corner Chest",                       PF_EXTERIOR_CORNER_CHEST,                       RED_RUPEE,                    {Category::cPiratesFortressExterior,Category::cChest ,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_INVISIBLE_SOLDIER]                           = ItemLocation::Base       (0x14, 0x8B, false,  "Pirate's Fortress Int Invisible Soldier",                  PF_INT_INVISIBLE_SOLDIER,                       STONE_MASK,                   {Category::cPiratesFortressInterior, Category::cVanillaMask,Category::cDayOne},                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_HOOKSHOT_ROOM_ZORA_EGG]                      = ItemLocation::Collectable(0x23, 0x69, true,  "Pirate's Fortress Int Hookshot Room Zora Egg",             PF_INT_HOOKSHOT_ROOM_ZORA_EGG,                  ZORA_EGG,                     {Category::cPiratesFortressInterior, Category::cBottleCatch,Category::cDayOne},                                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_GUARD_ROOM_ZORA_EGG]                         = ItemLocation::Collectable(0x23, 0x69, true,  "Pirate's Fortress Int Guard Room Zora Egg",                PF_INT_GUARD_ROOM_ZORA_EGG,                     ZORA_EGG,                     {Category::cPiratesFortressInterior, Category::cBottleCatch,Category::cDayOne},                                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_BARREL_MAZE_ZORA_EGG]                        = ItemLocation::Collectable(0x23, 0x69, true,  "Pirate's Fortress Int Barrel Maze Zora Egg",               PF_INT_BARREL_MAZE_ZORA_EGG,                    ZORA_EGG,                     {Category::cPiratesFortressInterior, Category::cBottleCatch,Category::cDayOne},                                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );
 locationTable[PF_INT_LAVA_ROOM_ZORA_EGG]                          = ItemLocation::Collectable(0x23, 0x69, true,  "Pirate's Fortress Int Lava Room Zora Egg",                 PF_INT_LAVA_ROOM_ZORA_EGG,                      ZORA_EGG,                     {Category::cPiratesFortressInterior, Category::cBottleCatch,Category::cDayOne},                                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_PIRATE_FORTRESS );


 //Beneath The Well
 locationTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST]               = ItemLocation::Chest      (0x4B, 0x1B, true,  "Beneath the Well Mirror Shield Chest" ,                    BENEATH_THE_WELL_MIRROR_SHIELD_CHEST,           MIRROR_SHIELD,                {Category::cBeneathTheWell,Category::cChest ,Category::cDayOne},                                                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL );
 locationTable[WELL_LEFT_PATH_CHEST]                               = ItemLocation::Chest      (0x4B, 0x02, true,  "Beneath the Well Left Path Chest" ,                        WELL_LEFT_PATH_CHEST,                           PURPLE_RUPEE,                 {Category::cBeneathTheWell,Category::cChest ,Category::cDayOne},                                                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL );
 locationTable[WELL_RIGHT_PATH_CHEST]                              = ItemLocation::Chest      (0x4B, 0x01, true,  "Beneath the Well Right Path Chest",                        WELL_RIGHT_PATH_CHEST,                          PURPLE_RUPEE,                 {Category::cBeneathTheWell,Category::cChest ,Category::cDayOne},                                                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL );
 
 //Ikana Castle
 locationTable[IKANA_CASTLE_PILLAR]                                = ItemLocation::Collectable(0x1D, 0x00, false, "Ikana Castle Pillar",                                      IKANA_CASTLE_PILLAR,                            PIECE_OF_HEART,               {Category::cIkanaCastle, Category::cVanillaHeartPiece,Category::cDayOne},                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_IKANA_CASTLE );
 locationTable[IKANA_CASTLE_IKANA_KING]                            = ItemLocation::Base       (0x56, 0x4F, false, "Ikana Castle Ikana King",                                  IKANA_CASTLE_IKANA_KING,                        ELEGY_OF_EMPTINESS,           {Category::cIkanaCastle,Category::cSong,Category::cDayOne},                                                                SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_IKANA_CASTLE );
 
 //Secret Shrine
 locationTable[SECRET_SHRINE_DINOLFOS_CHEST]                       = ItemLocation::Chest      (0x60, 0x00, true,  "Secret Shrine Dinolfos Chest",                             SECRET_SHRINE_DINOLFOS_CHEST,                   SILVER_RUPEE,                 {Category::cSecretShrine,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SECRET_SHRINE );
 locationTable[SECRET_SHRINE_WIZZROBE_CHEST]                       = ItemLocation::Chest      (0x60, 0x01, true,  "Secret Shrine Wizzrobe Chest",                             SECRET_SHRINE_WIZZROBE_CHEST,                   SILVER_RUPEE,                 {Category::cSecretShrine,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SECRET_SHRINE );
 locationTable[SECRET_SHRINE_WART_CHEST]                           = ItemLocation::Chest      (0x60, 0x02, true,  "Secret Shrine Wart Chest",                                 SECRET_SHRINE_WART_CHEST,                       SILVER_RUPEE,                 {Category::cSecretShrine,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SECRET_SHRINE );
 locationTable[SECRET_SHRINE_GARO_CHEST]                           = ItemLocation::Chest      (0x60, 0x03, true,  "Secret Shrine Garo Chest",                                 SECRET_SHRINE_GARO_CHEST,                       SILVER_RUPEE,                 {Category::cSecretShrine,Category::cChest ,Category::cDayOne},                                                                                                         SpoilerCollectionCheckGroup::GROUP_DUNGEON_SECRET_SHRINE );
 locationTable[SECRET_SHRINE_FINAL_CHEST]                          = ItemLocation::Chest      (0x60, 0x0A, true,  "Secret Shrine Final Chest",                                SECRET_SHRINE_FINAL_CHEST,                      PIECE_OF_HEART,               {Category::cSecretShrine, Category::cVanillaHeartPiece, Category::cChest, Category::cDayOne},                                                                          SpoilerCollectionCheckGroup::GROUP_DUNGEON_SECRET_SHRINE );
 
 //The Moon
 locationTable[THE_MOON_DEKU_TRIAL_BONUS]                          = ItemLocation::Collectable(0x2A, 0x00, false, "The Moon Deku Trial Bonus",                                THE_MOON_DEKU_TRIAL_BONUS,                      PIECE_OF_HEART,               {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_GORON_TRIAL_BONUS]                         = ItemLocation::Collectable(0x3F, 0x00, false, "The Moon Goron Trial Bonus",                               THE_MOON_GORON_TRIAL_BONUS,                     PIECE_OF_HEART,               {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_ZORA_TRIAL_BONUS]                          = ItemLocation::Collectable(0x47, 0x00, false, "The Moon Zora Trial Bonus",                                THE_MOON_ZORA_TRIAL_BONUS,                      PIECE_OF_HEART,               {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_LINK_TRIAL_BONUS]                          = ItemLocation::Collectable(0x66, 0x00, false, "The Moon Link Trial Bonus",                                THE_MOON_LINK_TRIAL_BONUS,                      PIECE_OF_HEART,               {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_GARO_CHEST]                                = ItemLocation::Chest      (0x66, 0x01, true,  "The Moon Garo Chest",                                      THE_MOON_GARO_CHEST,                            ARROWS_30,                    {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_IRON_KNUCKLE_CHEST]                        = ItemLocation::Chest      (0x67, 0x02, true,  "The Moon Iron Knuckle Chest",                              THE_MOON_IRON_KNUCKLE_CHEST,                    BOMBCHU_10,                   {Category::cTheMoon,Category::cDayThree},                                                                                                                              SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 locationTable[THE_MOON_MAJORA_CHILD]                              = ItemLocation::Base       (0x67, 0x7B, false, "The Moon Majora Child",                                    THE_MOON_MAJORA_CHILD,                          FIERCE_DIETY_MASK,            {Category::cTheMoon,Category::cDayThree},                                                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );
 
 /*-------------------------------
     --- BOSSES ---
   -------------------------------*/

 locationTable[LINKS_POCKET]                                       = ItemLocation::Base       (0x63, 0x00, false, "Link's Pocket",                                            LINKS_POCKET,                                   NONE,                         {},                                                                                                                        SpoilerCollectionCheck::AlwaysCollected(),  SpoilerCollectionCheckGroup::GROUP_NO_GROUP );
 locationTable[ODOLWA]                                             = ItemLocation::Reward     (0x1F, 0x2D, false, "Woodfall Temple Odolwa's Remains",                         ODOLWAS_REMAINS,                                ODOLWAS_REMAINS,              {},                                                                                                                        SpoilerCollectionCheck::EventChkInf(0),     SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[GOHT]                                               = ItemLocation::Reward     (0x44, 0x2F, false, "Snowhead Temple Goht's Remains",                           GOHTS_REMAINS,                                  GOHTS_REMAINS,                {},                                                                                                                        SpoilerCollectionCheck::EventChkInf(0),     SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[GYORG]                                              = ItemLocation::Reward     (0x5F, 0x30, false, "Great Bay Temple Gyorg's Remains",                         GYORGS_REMAINS,                                 GYORGS_REMAINS,               {},                                                                                                                        SpoilerCollectionCheck::EventChkInf(0),     SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[TWINMOLD]                                           = ItemLocation::Reward     (0x36, 0x31, false, "Stone Tower Temple Twinmold's Remains",                    TWINMOLDS_REMAINS,                              TWINMOLDS_REMAINS,            {},                                                                                                                        SpoilerCollectionCheck::EventChkInf(0),     SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[MAJORA]                                             = ItemLocation::Reward     (0x0B, 0x00, false, "Majora",                                                   MAJORA,                                         MAJORAS_MASK,                 {},                                                                                                                        SpoilerCollectionCheck::None(),             SpoilerCollectionCheckGroup::GROUP_DUNGEON_THE_MOON );

 /*-------------------------------
       --- GOLD SKULLTULA TOKENS ---
      -------------------------------*/
 
 //Southern Swamp Skulltla House
 locationTable[SSH_MAIN_ROOM_NEAR_CEILING]                         = ItemLocation::SGSToken   (0x27, 0x44, true,  "SSH Main Room Near Ceiling",                               SSH_MAIN_ROOM_NEAR_CEILING,                     SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_WATER]                                = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Water",                                      SSH_MAIN_ROOM_WATER,                            SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL]                      = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Lower Left Soil",                            SSH_MAIN_ROOM_LOWER_LEFT_SOIL,                  SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL]                     = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Lower Right Soil",                           SSH_MAIN_ROOM_LOWER_RIGHT_SOIL,                 SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_UPPER_SOIL]                           = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Upper Soil",                                 SSH_MAIN_ROOM_UPPER_SOIL,                       SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_PILLAR]                               = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Pillar",                                     SSH_MAIN_ROOM_PILLAR,                           SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_UPPER_PILLAR]                         = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Upper Pillar",                               SSH_MAIN_ROOM_UPPER_PILLAR,                     SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MAIN_ROOM_JAR]                                  = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Main Room Jar",                                        SSH_MAIN_ROOM_JAR,                              SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MONUMENT_ROOM_CRATE_1]                          = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Monument Room Crate 1",                                SSH_MONUMENT_ROOM_CRATE_1,                      SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MONUMENT_ROOM_CRATE_2]                          = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Monument Room Crate 2",                                SSH_MONUMENT_ROOM_CRATE_2,                      SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MONUMENT_ROOM_TORCH]                            = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Monument Room Torch",                                  SSH_MONUMENT_ROOM_TORCH,                        SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MONUMENT_ROOM_ON_MONUMENT]                      = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Monument Room On Monument",                            SSH_MONUMENT_ROOM_ON_MONUMENT,                  SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_MONUMENT_ROOM_LOWER_WALL]                       = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Monument Room Lower Wall",                             SSH_MONUMENT_ROOM_LOWER_WALL,                   SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_GOLD_ROOM_NEAR_CEILING]                         = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Gold Room Near Ceiling",                               SSH_GOLD_ROOM_NEAR_CEILING,                     SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_GOLD_ROOM_PILLAR]                               = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Gold Room Pillar",                                     SSH_GOLD_ROOM_PILLAR,                           SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_GOLD_ROOM_BEEHIVE]                              = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Gold Room Beehive",                                    SSH_GOLD_ROOM_BEEHIVE,                          SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_GOLD_ROOM_WALL]                                 = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Gold Room Wall",                                       SSH_GOLD_ROOM_WALL,                             SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_JAR]                                   = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Jar",                                         SSH_POT_ROOM_JAR,                               SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_POT_1]                                 = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Pot 1",                                       SSH_POT_ROOM_POT_1,                             SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_POT_2]                                 = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Pot 2",                                       SSH_POT_ROOM_POT_2,                             SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_BEHIND_VINES]                          = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Behind Vines",                                SSH_POT_ROOM_BEHIND_VINES,                      SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_WALL]                                  = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Wall",                                        SSH_POT_ROOM_WALL,                              SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_BEEHIVE_1]                             = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Beehive 1",                                   SSH_POT_ROOM_BEEHIVE_1,                         SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_POT_ROOM_BEEHIVE_2]                             = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Pot Room Beehive 2",                                   SSH_POT_ROOM_BEEHIVE_2,                         SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_TREE_1]                               = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Tree 1",                                     SSH_TREE_ROOM_TREE_1,                           SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_TREE_2]                               = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Tree 2",                                     SSH_TREE_ROOM_TREE_2,                           SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_TREE_3]                               = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Tree 3",                                     SSH_TREE_ROOM_TREE_3,                           SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_GRASS_1]                              = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Grass 1",                                    SSH_TREE_ROOM_GRASS_1,                          SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_GRASS_2]                              = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Grass 2",                                    SSH_TREE_ROOM_GRASS_2,                          SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 locationTable[SSH_TREE_ROOM_BEEHIVE]                              = ItemLocation::SGSToken   (0x27, 0x00, true,  "SSH Tree Room Beehive",                                    SSH_TREE_ROOM_BEEHIVE,                          SWAMP_SKULLTULA_TOKEN,        {Category::cSouthernSwamp, Category::cSwampSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_SWAMP_SKULLTULA_HOUSE);
 
 //Oceanside Spider House
 locationTable[OSH_ENTRANCE_LEFT_WALL]                             = ItemLocation::OGSToken   (0x28, 0x6D, true,  "OSH Entrance Left Wall",                                   OSH_ENTRANCE_LEFT_WALL,                         OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_ENTRANCE_RIGHT_WALL]                            = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Entrance Right Wall",                                  OSH_ENTRANCE_RIGHT_WALL,                        OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_ENTRANCE_WEB]                                   = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Entrance Web",                                         OSH_ENTRANCE_WEB,                               OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library Hole Behind Picture",                          OSH_LIBRARY_HOLE_BEHIND_PICTURE,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_HOLE_BEHIND_CABINET]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library Hole Behind Cabinet",                          OSH_LIBRARY_HOLE_BEHIND_CABINET,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library On Corner Bookshelf",                          OSH_LIBRARY_ON_CORNER_BOOKSHELF,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_CEILING_EDGE]                           = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library Ceiling Edge",                                 OSH_LIBRARY_CEILING_EDGE,                       OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_BEHIND_BOOKCASE_1]                      = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library Behind Bookcase 1",                            OSH_LIBRARY_BEHIND_BOOKCASE_1,                  OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_BEHIND_BOOKCASE_2]                      = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library Behind Bookacse 2",                            OSH_LIBRARY_BEHIND_BOOKCASE_2,                  OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_LIBRARY_BEHIND_PICTURE]                         = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Library  Behind Picture",                              OSH_LIBRARY_BEHIND_PICTURE,                     OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_CEILING_EDGE]                       = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Ceiling Edge",                             OSH_SECOND_ROOM_CEILING_EDGE,                   OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_CEILING_PLANK]                      = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Ceiling Plank",                            OSH_SECOND_ROOM_CEILING_PLANK,                  OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_JAR]                                = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Jar",                                      OSH_SECOND_ROOM_JAR,                            OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_WEBBED_HOLE]                        = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Webbed Hole",                              OSH_SECOND_ROOM_WEBBED_HOLE,                    OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_WEBBED_POT]                         = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Webbed Pot",                               OSH_SECOND_ROOM_WEBBED_POT,                     OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_UPPER_POT]                          = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Upper Pot",                                OSH_SECOND_ROOM_UPPER_POT,                      OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_BEHIND_SKULL_1]                     = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Behind Skull 1",                           OSH_SECOND_ROOM_BEHIND_SKULL_1,                 OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_BEHIND_SKULL_2]                     = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Behind Skull 2",                           OSH_SECOND_ROOM_BEHIND_SKULL_2,                 OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_SECOND_ROOM_LOWER_POT]                          = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Second Room Lower Pot",                                OSH_SECOND_ROOM_LOWER_POT,                      OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_STORAGE_ROOM_CEILING_WEB]                       = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Storage Room Ceiling Web",                             OSH_STORAGE_ROOM_CEILING_WEB,                   OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_STORAGE_ROOM_BEHIND_CRATE]                      = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Storage Room Behind Crate",                            OSH_STORAGE_ROOM_BEHIND_CRATE,                  OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_STORAGE_ROOM_WALL]                              = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Storage Room Wall",                                    OSH_STORAGE_ROOM_WALL,                          OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_STORAGE_ROOM_CRATE]                             = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Storage Room Crate",                                   OSH_STORAGE_ROOM_CRATE,                         OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_STORAGE_ROOM_BARREL]                            = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Storage Room Barrel",                                  OSH_STORAGE_ROOM_BARREL,                        OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_CEILING_EDGE]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Ceiling Edge",                          OSH_COLORED_SKULLS_CEILING_EDGE,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_CHANDELIER_1]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Chandelier 1",                          OSH_COLORED_SKULLS_CHANDELIER_1,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_CHANDELIER_2]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Chandelier 2",                          OSH_COLORED_SKULLS_CHANDELIER_2,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_CHANDELIER_3]                    = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Chandelier 3",                          OSH_COLORED_SKULLS_CHANDELIER_3,                OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_BEHIND_PICTURE]                  = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Behind Picture",                        OSH_COLORED_SKULLS_BEHIND_PICTURE,              OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 locationTable[OSH_COLORED_SKULLS_POT]                             = ItemLocation::OGSToken   (0x28, 0x00, true,  "OSH Colored Skulls Pot",                                   OSH_COLORED_SKULLS_POT,                         OCEANSIDE_SKULLTULA_TOKEN,    {Category::cGreatBayCoast, Category::cOceanSkulltula,Category::cDayOne},                                                                                               SpoilerCollectionCheckGroup::GROUP_OCEAN_SKULLTULA_HOUSE);
 
    /*--------------------------------
   --Stray Fairies---
   -------------------------------*/
 
 //Clock Town Stray Fairy
 locationTable[LAUNDRY_POOL_SF]                                    = ItemLocation::StrayFairy (0x70, 0x00, true,  "Laundry Pool SF",                                          CT_STRAY_FAIRY,                                 CT_STRAY_FAIRY,               {Category::cLaundryPool, Category::cVanillaStrayFairy, Category::cCTStray,Category::cDayOne},                                                                          SpoilerCollectionCheckGroup::GROUP_LAUNDRY_POOL);
 
 
 //Woodfall Stray Faries
 locationTable[WF_SF_ENTRANCE_FAIRY]                               = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Entrance",                              WF_SF_ENTRANCE_FAIRY,                           WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_ENTRANCE_PLATFORM]                            = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Entrance Platform",                     WF_SF_ENTRANCE_PLATFORM,                        WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_MAIN_ROOM_BUBBLE]                             = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Main Room Bubble",                      WF_SF_MAIN_ROOM_BUBBLE,                         WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_MAIN_ROOM_SWITCH]                             = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Main Room Switch",                      WF_SF_MAIN_ROOM_SWITCH,                         WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE]                  = ItemLocation::StrayFairy (0xB1, 0x00, true,  "Woodfall Temple SF Pre-Boss Lower Right Bubble",           WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE,              WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE]                  = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Pre-Boss Upper Left Bubble",            WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE,              WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE]                   = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Pre-Boss Upper Right Bubble",           WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE,               WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE]                       = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Pre-Boss Pillar Bubble",                WF_SF_PRE_BOSS_PILLAR_BUBBLE,                   WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_DEKU_BABA]                                    = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Deku Baba",                             WF_SF_DEKU_BABA,                                WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_DRAGONFLY_ROOM_BUBBLE]                        = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Dragonfly Room Bubble",                 WF_SF_DRAGONFLY_ROOM_BUBBLE,                    WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_SKULLTULA]                                    = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Skulltula",                             WF_SF_SKULLTULA,                                WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_DARK_ROOM]                                    = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Dark Room",                             WF_SF_DARK_ROOM,                                WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_JAR_FAIRY]                                    = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Jar Fairy",                             WF_SF_JAR_FAIRY,                                WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_BRIDGE_ROOM_BEEHIVE]                          = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Bridge Room Beehive",                   WF_SF_BRIDGE_ROOM_BEEHIVE,                      WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[WF_SF_PLATFORM_ROOM_BEEHIVE]                        = ItemLocation::StrayFairy (0x1B, 0x00, true,  "Woodfall Temple SF Platform Room Beehive",                 WF_SF_PLATFORM_ROOM_BEEHIVE,                    WF_STRAY_FAIRY,               {Category::cWoodfall, Category::cWoodfallTemple, Category::cWFStray, Category::cVanillaStrayFairy,Category::cDayOne},                                                  SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 
 //Snowhead Stray Faries
 locationTable[SH_SF_SNOW_ROOM_BUBBLE]                             = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Snow Room Bubble",                      SH_SF_SNOW_ROOM_BUBBLE,                         SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_CEILING_BUBBLE]                               = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Ceiling Bubble",                        SH_SF_CEILING_BUBBLE,                           SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_DINOLFOS_1]                                   = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Dinolfos 1",                            SH_SF_DINOLFOS_1,                               SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_DINOLFOS_2]                                   = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Dinolfos 2",                            SH_SF_DINOLFOS_2,                               SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE]                     = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Bridge Room Ledge Bubble",              SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE,                 SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE]                    = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Bridge Room Pillar Bubble",             SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE,                SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_MAP_ROOM_FAIRY]                               = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Map Room Fairy",                        SH_SF_MAP_ROOM_FAIRY,                           SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_MAP_ROOM_LEDGE]                               = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Map Room Ledge",                        SH_SF_MAP_ROOM_LEDGE,                           SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_BASEMENT]                                     = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Basement",                              SH_SF_BASEMENT,                                 SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_TWIN_BLOCK]                                   = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Twin Block",                            SH_SF_TWIN_BLOCK,                               SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_ICICLE_ROOM_WALL]                             = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Icicle Room Wall",                      SH_SF_ICICLE_ROOM_WALL,                         SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_MAIN_ROOM_WALL]                               = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Main Room Wall",                        SH_SF_MAIN_ROOM_WALL,                           SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_PILLAR_FREEZARDS]                             = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Pillar Freezards",                      SH_SF_PILLAR_FREEZARDS,                         SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_ICE_PUZZLE]                                   = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Ice Puzzle",                            SH_SF_ICE_PUZZLE,                               SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[SH_SF_CRATE]                                        = ItemLocation::StrayFairy (0x21, 0x00, true,  "Snowhead Temple SF Crate",                                 SH_SF_CRATE,                                    SH_STRAY_FAIRY,               {Category::cSnowheadTemple, Category::cVanillaStrayFairy,Category::cSHStray,Category::cDayOne},                                                                        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 
 //Great Bay Stray Fairies
 locationTable[GBT_SF_SKULLTULA]                                   = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Skulltula",                            GBT_SF_SKULLTULA,                               GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE]             = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Water Control Room Underwater Bubble", GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE,         GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_WATERWHEEL_ROOM_LOWER]                       = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Waterwheel Room Lower",                GBT_SF_WATERWHEEL_ROOM_LOWER,                   GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_WATERWHEEL_ROOM_UPPER]                       = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Waterwheel Room Upper",                GBT_SF_WATERWHEEL_ROOM_UPPER,                   GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_GREEN_VALVE]                                 = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Green Valve",                          GBT_SF_GREEN_VALVE,                             GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_SEESAW_ROOM]                                 = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Seesaw Room",                          GBT_SF_SEESAW_ROOM,                             GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_ENTRANCE_TORCHES]                            = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Entrance Torches",                     GBT_SF_ENTRANCE_TORCHES,                        GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_BIO_BABAS]                                   = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Bio Babas",                            GBT_SF_BIO_BABAS,                               GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_UNDERWATER_BARREL]                           = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Underwater Barrel",                    GBT_SF_UNDERWATER_BARREL,                       GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_WHIRLPOOL_JAR]                               = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Whirlpool Jar",                        GBT_SF_WHIRLPOOL_JAR,                           GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_WHIRLPOOL_BARREL]                            = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Whirlpool Barrel",                     GBT_SF_WHIRLPOOL_BARREL,                        GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_DEXIHANDS_JAR]                               = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Dexihands Jar",                        GBT_SF_DEXIHANDS_JAR,                           GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_LEDGE_JAR]                                   = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Ledge Jar",                            GBT_SF_LEDGE_JAR,                               GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE]                        = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Pre-Boss Room Bubble",                 GBT_SF_PRE_BOSS_ROOM_BUBBLE,                    GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE]             = ItemLocation::StrayFairy (0x49, 0x00, true,  "Great Bay Temple SF Pre-Boss Room Underwater Bubble",      GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE,         GBT_STRAY_FAIRY,              {Category::cGreatBayTemple, Category::cVanillaStrayFairy,Category::cGBTStray,Category::cDayOne},                                                                       SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 
 //Stone Tower Temple Stray Fairies 
 locationTable[ST_SF_MIRROR_SUN_BLOCK]                             = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Mirror Sun Block",                   ST_SF_MIRROR_SUN_BLOCK,                         ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_LAVA_ROOM_LEDGE]                              = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Lava Room Ledge",                    ST_SF_LAVA_ROOM_LEDGE,                          ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_LAVA_ROOM_FIRE_RING]                          = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Lava Room Fire Ring",                ST_SF_LAVA_ROOM_FIRE_RING,                      ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_EYEGORE]                                      = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Eyegore",                            ST_SF_EYEGORE,                                  ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_UPDRAFT_FIRE_RING]                            = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Updraft Fire Ring",                  ST_SF_UPDRAFT_FIRE_RING,                        ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_MIRROR_SUN_SWITCH]                            = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Mirror Sun Switch",                  ST_SF_MIRROR_SUN_SWITCH,                        ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_BOSS_WARP]                                    = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Boss Warp",                          ST_SF_BOSS_WARP,                                ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_WIZZROBE]                                     = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Wizzrobe",                           ST_SF_WIZZROBE,                                 ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_DEATH_ARMOS]                                  = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Death Armos",                        ST_SF_DEATH_ARMOS,                              ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_UPDRAFT_FROZEN_EYE]                           = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Updraft Frozen Eye",                 ST_SF_UPDRAFT_FROZEN_EYE,                       ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_THIN_BRIDGE]                                  = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Thin Bridge",                        ST_SF_THIN_BRIDGE,                              ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_BASEMENT_LEDGE]                               = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Basement Ledge",                     ST_SF_BASEMENT_LEDGE,                           ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_STATUE_EYE]                                   = ItemLocation::StrayFairy (0x16, 0x00, true,  "Stone Tower Temple SF Statue Eye",                         ST_SF_STATUE_EYE,                               ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_UNDERWATER]                                   = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Underwater",                         ST_SF_UNDERWATER,                               ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 locationTable[ST_SF_BRIDGE_CRYSTAL]                               = ItemLocation::StrayFairy (0x18, 0x00, true,  "Stone Tower Temple SF Bridge Crystal",                     ST_SF_BRIDGE_CRYSTAL,                           ST_STRAY_FAIRY,               {Category::cStoneTowerTemple, Category::cVanillaStrayFairy,Category::cSTStray,Category::cDayOne},                                                                      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 
    /*-------------------------------
          ---HEART CONTAINERS ---
      -------------------------------*/
 locationTable[ODOLWA_HEART_CONTAINER]                             = ItemLocation::Base       (0x1F, 0x00, false, "Woodfall Temple Odolwa Heart Container",                   ODOLWA_HEART_CONTAINER,                         HEART_CONTAINER,              {Category::cWoodfall, Category::cWoodfallTemple,Category::cBossHeart, Category::cDungeonReward,Category::cDayOne},         SpoilerCollectionCheck::Collectable(0x00,0x00),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_WOODFALL_TEMPLE );
 locationTable[GOHT_HEART_CONTAINER]                               = ItemLocation::Base       (0x44, 0x00, false, "Snowhead Temple Goht Heart Container",                     GOHT_HEART_CONTAINER,                           HEART_CONTAINER,              {Category::cSnowhead, Category::cSnowheadTemple, Category::cBossHeart, Category::cDungeonReward,Category::cDayOne},        SpoilerCollectionCheck::Collectable(0x00,0x00),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_SNOWHEAD_TEMPLE );
 locationTable[GYORG_HEART_CONTAINER]                              = ItemLocation::Base       (0x5F, 0x00, false, "Great Bay Temple Gyorg Heart Container",                   GYORG_HEART_CONTAINER,                          HEART_CONTAINER,              {Category::cZoraCape, Category::cGreatBayTemple, Category::cBossHeart, Category::cDungeonReward,Category::cDayOne},        SpoilerCollectionCheck::Collectable(0x00,0x00),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_GREAT_BAY );
 locationTable[TWINMOLD_HEART_CONTAINER]                           = ItemLocation::Base       (0x36, 0x00, false, "Stone Tower Temple Twinmold Heart Container",              TWINMOLD_HEART_CONTAINER,                       HEART_CONTAINER,              {Category::cStoneTower, Category::cStoneTowerTemple,Category::cBossHeart, Category::cDungeonReward,Category::cDayOne},     SpoilerCollectionCheck::Collectable(0x00,0x00),      SpoilerCollectionCheckGroup::GROUP_DUNGEON_STONE_TOWER );
 
    /*-------------------------------
               --- COWS ---
      -------------------------------*/
 
 locationTable[GBC_GROTTO_COW1]                                    = ItemLocation::Base       (0x07, 0x92, true,  "GBC Cow 1",                                                GBC_GROTTO_COW1,                                MILK,                         {Category::cGreatBayCoast,Category::cCow, Category::cGrotto,Category::cDayOne},                                            SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST);
 locationTable[GBC_GROTTO_COW2]                                    = ItemLocation::Base       (0x07, 0x92, true,  "GBC Cow 2",                                                GBC_GROTTO_COW2,                                MILK,                         {Category::cGreatBayCoast,Category::cCow, Category::cGrotto,Category::cDayOne},                                            SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST);
 locationTable[ROMANI_RANCH_COW_1]                                 = ItemLocation::Base       (0x35, 0x92, true,  "RR Cow 1",                                                 ROMANI_RANCH_COW_1,                             MILK,                         {Category::cRomaniRanch, Category::cCow,Category::cDayOne},                                                                SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
 locationTable[ROMANI_RANCH_COW_2]                                 = ItemLocation::Base       (0x35, 0x92, true,  "RR Cow 2",                                                 ROMANI_RANCH_COW_2,                             MILK,                         {Category::cRomaniRanch, Category::cCow,Category::cDayOne},                                                                SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
 locationTable[ROMANI_RANCH_COW_3]                                 = ItemLocation::Base       (0x35, 0x92, true,  "RR Cow 3",                                                 ROMANI_RANCH_COW_3,                             MILK,                         {Category::cRomaniRanch, Category::cCow,Category::cDayOne},                                                                SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_ROMANI_RANCH);
 locationTable[TERMINA_FIELD_GROTTO_COW1]                          = ItemLocation::Base       (0x07, 0x92, true,  "TF Grotto Cow 1",                                          TERMINA_FIELD_GROTTO_COW1,                      MILK,                         {Category::cTerminaField,Category::cCow, Category::cGrotto,Category::cDayOne},                                             SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
 locationTable[TERMINA_FIELD_GROTTO_COW2]                          = ItemLocation::Base       (0x07, 0x92, true,  "TF Grotto Cow 2",                                          TERMINA_FIELD_GROTTO_COW2,                      MILK,                         {Category::cTerminaField,Category::cCow, Category::cGrotto,Category::cDayOne},                                             SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_TERMINA_FIELD);
 locationTable[BENEATH_THE_WELL_COW]                               = ItemLocation::Base       (0x4B, 0x92, true,  "Beneath the Well Cow",                                     BENEATH_THE_WELL_COW,                           MILK,                         {Category::cBeneathTheWell,Category::cCow,Category::cDayOne},                                                              SpoilerCollectionCheck::Cow(0x00,0x00),     SpoilerCollectionCheckGroup::GROUP_DUNGEON_BENEATH_THE_WELL );
 
 /*-------------------------------
             --- TINGLE MAPS ---
      -------------------------------*/

 locationTable[TINGLE_N_CLOCK_TOWN_CT]                             = ItemLocation::Base       (0x6E, 0xB4, false, "NCT Tingle Clock Town Map Buy",                            TINGLE_N_CLOCK_TOWN_CT,                         CLOCK_TOWN_MAP,               {Category::cNorthClockTown, Category::cTingleMap,Category::cDayOne},                                                       SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
 locationTable[TINGLE_N_CLOCK_TOWN_WF]                             = ItemLocation::Base       (0x6E, 0xB5, false, "NCT Tingle Woodfall Map Buy",                              TINGLE_N_CLOCK_TOWN_WF,                         WOODFALL_MAP,                 {Category::cNorthClockTown, Category::cTingleMap, Category::cDayOne},                                                      SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_N_CLOCK_TOWN);
 
 locationTable[TINGLE_ROAD_TO_SS_WF]                               = ItemLocation::Base       (0x40, 0xB5, false, "Road To Southern Swamp Tingle Woodfall Map Buy",           TINGLE_ROAD_TO_SS_WF,                           WOODFALL_MAP,                 {Category::cRoadToSouthernSwamp, Category::cTingleMap,Category::cDayOne},                                                  SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
 locationTable[TINGLE_ROAD_TO_SS_SH]                               = ItemLocation::Base       (0x40, 0xB6, false, "Road to Southern Swamp Tingle Snowhead Map Buy",           TINGLE_ROAD_TO_SS_SH,                           SNOWHEAD_MAP,                 {Category::cRoadToSouthernSwamp, Category::cTingleMap, Category::cDayOne},                                                 SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
 
 locationTable[TINGLE_TWIN_ISLANDS_SH]                             = ItemLocation::Base       (0x5D, 0xB6, false, "TI Tingle Snowhead Map Buy",                               TINGLE_TWIN_ISLANDS_SH,                         SNOWHEAD_MAP,                 {Category::cTwinIslands, Category::cTingleMap,Category::cDayOne},                                                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
 locationTable[TINGLE_TWIN_ISLANDS_RR]                             = ItemLocation::Base       (0x5D, 0xB7, false, "TI Tingle Romani Ranch Buy",                               TINGLE_TWIN_ISLANDS_RR,                         ROMANI_RANCH_MAP,             {Category::cTwinIslands, Category::cTingleMap, Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
 locationTable[TINGLE_TWIN_ISLANDS_SH_SPRING]                      = ItemLocation::Base       (0x5E, 0xB6, false, "TI Tingle Snowhead Map Buy (Spring)",                      TINGLE_TWIN_ISLANDS_SH_SPRING,                  SNOWHEAD_MAP,                 {Category::cTwinIslands, Category::cTingleMap, Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);
 locationTable[TINGLE_TWIN_ISLANDS_RR_SPRING]                      = ItemLocation::Base       (0x5E, 0xB7, false, "TI Tingle Romani Ranch Map Buy (Spring)",                  TINGLE_TWIN_ISLANDS_RR_SPRING,                  ROMANI_RANCH_MAP,             {Category::cTwinIslands, Category::cTingleMap, Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_TWIN_ISLANDS);

 locationTable[TINGLE_MILK_ROAD_RR]                                = ItemLocation::Base       (0x22, 0xB7, false, "MR Tingle Romani Ranch Map Buy",                           TINGLE_MILK_ROAD_RR,                            ROMANI_RANCH_MAP,             {Category::cMilkRoad, Category::cTingleMap,Category::cDayOne},                                                             SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD);
 locationTable[TINGLE_MILK_ROAD_GB]                                = ItemLocation::Base       (0x22, 0xB8, false, "MR Tingle Great Bay Map Buy",                              TINGLE_MILK_ROAD_GB,                            GREAT_BAY_MAP,                {Category::cMilkRoad, Category::cTingleMap, Category::cDayOne},                                                            SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_MILK_ROAD);
 
 locationTable[TINGLE_GBC_GB]                                      = ItemLocation::Base       (0x37, 0xB8, false, "GBC Tingle Great Bay Map Buy",                             TINGLE_GBC_GB,                                  GREAT_BAY_MAP,                {Category::cGreatBayCoast, Category::cTingleMap,Category::cDayOne},                                                        SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST);
 locationTable[TINGLE_GBC_ST]                                      = ItemLocation::Base       (0x37, 0xB9, false, "GBC Tingle Stone Tower Map Buy",                           TINGLE_GBC_ST,                                  STONE_TOWER_MAP,              {Category::cGreatBayCoast, Category::cTingleMap, Category::cDayOne},                                                       SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_GREAT_BAY_COAST);
 
 locationTable[TINGLE_IKANA_CANYON_ST]                             = ItemLocation::Base       (0x13, 0xB9, false, "IC Tingle Stone Tower Map Buy",                            TINGLE_IKANA_CANYON_ST,                         STONE_TOWER_MAP,              {Category::cIkanaCanyon, Category::cTingleMap,Category::cDayOne},                                                          SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
 locationTable[TINGLE_IKANA_CANYON_CT]                             = ItemLocation::Base       (0x13, 0xB4, false, "IC Tingle Clock Town Map Buy",                             TINGLE_IKANA_CANYON_CT,                         CLOCK_TOWN_MAP,               {Category::cIkanaCanyon, Category::cTingleMap, Category::cDayOne},                                                         SpoilerCollectionCheck::ItemGetInf(0),      SpoilerCollectionCheckGroup::GROUP_IKANA_CANYON);
    
 /*-------------------------------           
           --- TRADING POST ---                
      1     2               5     6          ------------------------
                                        OR          --SHOP--
      3     4               7     8              1     2    3
      -------------------------------        -----------------------*/
 
 locationTable[TRADING_POST_ITEM_1]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 1",                                      TRADING_POST_ITEM_1,                            BUY_RED_POTION,               {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 0),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_2]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 2",                                      TRADING_POST_ITEM_2,                            BUY_GREEN_POTION,             {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 1),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_3]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 3",                                      TRADING_POST_ITEM_3,                            BUY_HEROS_SHIELD,             {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 2),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_4]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 4",                                      TRADING_POST_ITEM_4,                            BUY_FAIRYS_SPIRIT,            {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 3),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN); 
 locationTable[TRADING_POST_ITEM_5]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 5",                                      TRADING_POST_ITEM_5,                            BUY_DEKU_STICK_1,             {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 4),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_6]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 6",                                      TRADING_POST_ITEM_6,                            BUY_ARROWS_30,                {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 5),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_7]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 7",                                      TRADING_POST_ITEM_7,                            BUY_DEKU_NUT_10,              {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 6),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[TRADING_POST_ITEM_8]                                = ItemLocation::Base       (0x34,0x00, true,   "Trading Post Item 8",                                      TRADING_POST_ITEM_8,                            BUY_MAGIC_BEAN,               {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x34, 7),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
   
 locationTable[BOMB_SHOP_ITEM_1]                                   = ItemLocation::Base       (0x68,0x00, true,   "Bomb Shop Item 1",                                         BOMB_SHOP_ITEM_1,                               BOMBS_10,                     {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x68, 0),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 locationTable[BOMB_SHOP_ITEM_2]                                   = ItemLocation::Base       (0x68,0x00, true,   "Bomb Shop Item 2",                                         BOMB_SHOP_ITEM_2,                               BOMBCHU_10,                   {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x68, 1),  SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
 //locationTable[BOMB_SHOP_ITEM_3]                                   = ItemLocation::Base(0x68,0x00, true, "Bomb Shop Item 3",                                                  BOMB_SHOP_ITEM_3,                               BOMBS_20,                     {Category::cEastClockTown,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x00, 0), SpoilerCollectionCheckGroup::GROUP_W_CLOCK_TOWN);
   
 locationTable[POTION_SHOP_ITEM_1]                                 = ItemLocation::Base       (0x0A,0x00, true,   "Potion Shop Item 1",                                       POTION_SHOP_ITEM_1,                             BLUE_POTION_REFILL,           {Category::cSouthernSwamp,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x0A, 0),  SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
 locationTable[POTION_SHOP_ITEM_2]                                 = ItemLocation::Base       (0x0A,0x00, true,   "Potion Shop Item 2",                                       POTION_SHOP_ITEM_2,                             GREEN_POTION_REFILL,          {Category::cSouthernSwamp,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x0A, 1),  SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
 locationTable[POTION_SHOP_ITEM_3]                                 = ItemLocation::Base       (0x0A,0x00, true,   "Potion Shop Item 3",                                       POTION_SHOP_ITEM_3,                             RED_POTION_REFILL,            {Category::cSouthernSwamp,Category::cShop,Category::cDayOne},                                                              SpoilerCollectionCheck::ShopItem(0x0A, 2),  SpoilerCollectionCheckGroup::GROUP_SOUTHERN_SWAMP);
 
 locationTable[GORON_SHOP_ITEM_1]                                  = ItemLocation::Base       (0x3D,0x00, true,   "Goron Shop Item 1",                                        GORON_SHOP_ITEM_1,                              BOMBS_10,                     {Category::cGoronVillage,Category::cShop,Category::cDayOne},                                                               SpoilerCollectionCheck::ShopItem(0x3D, 0),  SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
 locationTable[GORON_SHOP_ITEM_2]                                  = ItemLocation::Base       (0x3D,0x00, true,   "Goron Shop Item 2",                                        GORON_SHOP_ITEM_2,                              ARROWS_10,                    {Category::cGoronVillage,Category::cShop,Category::cDayOne},                                                               SpoilerCollectionCheck::ShopItem(0x3D, 1),  SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
 locationTable[GORON_SHOP_ITEM_3]                                  = ItemLocation::Base       (0x3D,0x00, true,   "Goron Shop Item 3",                                        GORON_SHOP_ITEM_3,                              RED_POTION_REFILL,            {Category::cGoronVillage,Category::cShop,Category::cDayOne},                                                               SpoilerCollectionCheck::ShopItem(0x3D, 2),  SpoilerCollectionCheckGroup::GROUP_GORON_VILLAGE);
   
 locationTable[ZORA_SHOP_ITEM_1]                                   = ItemLocation::Base       (0x4C,0x00, true,   "Zora Shop Item 1",                                         ZORA_SHOP_ITEM_1,                               HEROS_SHIELD,                 {Category::cZoraHall,Category::cShop,Category::cDayOne},                                                                   SpoilerCollectionCheck::ShopItem(0x4C, 0),  SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
 locationTable[ZORA_SHOP_ITEM_2]                                   = ItemLocation::Base       (0x4C,0x00, true,   "Zora Shop Item 2",                                         ZORA_SHOP_ITEM_2,                               ARROWS_10,                    {Category::cZoraHall,Category::cShop,Category::cDayOne},                                                                   SpoilerCollectionCheck::ShopItem(0x4C, 1),  SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
 locationTable[ZORA_SHOP_ITEM_3]                                   = ItemLocation::Base       (0x4C,0x00, true,   "Zora Shop Item 3",                                         ZORA_SHOP_ITEM_3,                               RED_POTION_REFILL,            {Category::cZoraHall,Category::cShop,Category::cDayOne},                                                                   SpoilerCollectionCheck::ShopItem(0x4C, 2),  SpoilerCollectionCheckGroup::GROUP_ZORA_HALL);
   
  

    /*-------------------------------
          --- GOSSIP STONES ---
      -------------------------------*/
    // These are not actual locations, but are filler spots used for hint reachability. - OoT Randomizer
    //                                                                                        flag + 0x400 = message ID
locationTable[TF_MILK_ROAD_TREE_GOSSIP]                            = ItemLocation::HintStone  (0x00,0x20b0, true, "TF Near Milk Road Tree Gossip Stone",         {});
locationTable[TF_IKANA_SNOWHEAD_GOSSIP]                            = ItemLocation::HintStone  (0x00,0x20bb, true, "TF Between Ikana And Snowhead Gossip Stone",  {});
locationTable[TF_OBSERVATORY_GOSSIP]                               = ItemLocation::HintStone  (0x00,0x20c1, true, "TF Behind Observatory Gossip Stone",          {});
locationTable[TF_TOP_SNOWHEAD_GOSSIP]                              = ItemLocation::HintStone  (0x00,0x20b9, true, "TF Top Snowhead Area Gossip Stone",           {});
locationTable[TF_LOWER_SNOWHEAD_GOSSIP]                            = ItemLocation::HintStone  (0x00,0x20ba, true, "TF Lower Snowhead Area Gossip Stone",         {});
locationTable[TF_NEAR_GRASS_CHEST_GOSSIP]                          = ItemLocation::HintStone  (0x00,0x20b0, true, "TF Near Grass Chest Gossip Stone",            {});
locationTable[TF_FOUR_STONE_GROTTO_1]                              = ItemLocation::HintStone  (0x00,0x20f3, true, "TF Four Gossip Stone Grotto 1",               {});
locationTable[TF_FOUR_STONE_GROTTO_2]                              = ItemLocation::HintStone  (0x00,0x20f7, true, "TF Four Gossip Stone Grotto 2",               {});
locationTable[TF_FOUR_STONE_GROTTO_3]                              = ItemLocation::HintStone  (0x00,0x20f8, true, "TF Four Gossip Stone Grotto 3",               {});
locationTable[TF_FOUR_STONE_GROTTO_4]                              = ItemLocation::HintStone  (0x00,0x20f9, true, "TF Four Gossip Stone Grotto 4",               {});
locationTable[ROAD_TO_SS_GOSSIP]                                   = ItemLocation::HintStone  (0x00,0x20c0, true, "Road to SS Gossip Stone",                     {});
locationTable[SS_GOSSIP]                                           = ItemLocation::HintStone  (0x00,0x20b1, true, "SS Gossip Stone",                             {});
locationTable[SSH_GOSSIP]                                          = ItemLocation::HintStone  (0x00,0x20c7, true, "SSH Gossip Stone",                            {});
locationTable[PATH_TO_MV_GOSSIP]                                   = ItemLocation::HintStone  (0x00,0x20b3, true, "Path to MV Gossip Stone",                     {});
locationTable[MV_NEAR_FROGS_GOSSIP]                                = ItemLocation::HintStone  (0x00,0x20b2, true, "MV Near Frogs Gossip Stone (Spring)",         {});
locationTable[MV_NEAR_GROTTO_GOSSIP]                               = ItemLocation::HintStone  (0x00,0x20c6, true, "MV Near Grotto Gossip Stone (Spring)",        {});
locationTable[GBC_BENEATH_COW_GROTTO_GOSSIP]                       = ItemLocation::HintStone  (0x00,0x20bf, true, "GBC Beneath Cow Grotto Gossip Stone",         {});
locationTable[GBC_OUTSIDE_FORTRESS_GOSSIP]                         = ItemLocation::HintStone  (0x00,0x20b5, true, "GBC Outside Fortres Gates Gossip Stone",      {});
locationTable[ZC_GOSSIP]                                           = ItemLocation::HintStone  (0x00,0x20b4, true, "ZC Gossip Stone",                             {});
locationTable[MR_GOSSIP]                                           = ItemLocation::HintStone  (0x00,0x20be, true, "MR Gossip Stone",                             {});
locationTable[RR_ENTRANCE_GOSSIP]                                  = ItemLocation::HintStone  (0x00,0x20c4, true, "RR Entrance Gossip Stone",                    {});
locationTable[RR_BARN_GOSSIP]                                      = ItemLocation::HintStone  (0x00,0x20bc, true, "RR Barn Gossip Stone",                        {});
locationTable[RR_FIELD_GOSSIP]                                     = ItemLocation::HintStone  (0x00,0x20bd, true, "RR Field Gossip Stone",                       {});
locationTable[DOGGY_RACETRACK_GOSSIP]                              = ItemLocation::HintStone  (0x00,0x20c3, true, "Doggy Racetrack Gossip Stone",                {});
locationTable[CUCCO_SHACK_GOSSIP]                                  = ItemLocation::HintStone  (0x00,0x20c2, true, "Cucco Shack Gossip Stone",                    {});
locationTable[IC_DOCK_GOSSIP]                                      = ItemLocation::HintStone  (0x00,0x20b6, true, "IC Dock Gossip Stone",                        {});
locationTable[IC_SAKON_GOSSIP]                                     = ItemLocation::HintStone  (0x00,0x20c5, true, "IC Across from Sakon's Hideout Gossip Stone", {});
locationTable[IC_SPIRIT_HOUSE_GOSSIP]                              = ItemLocation::HintStone  (0x00,0x20b7, true, "IC Above Spirit House Gossip Stone",          {});
locationTable[MOON_DEKU_GOSSIP_1]                                  = ItemLocation::HintStone  (0x00,0x2109, true, "Moon Deku Trial Gossip Stone 1",              {});
locationTable[MOON_DEKU_GOSSIP_2]                                  = ItemLocation::HintStone  (0x00,0x2108, true, "Moon Deku Trial Gossip Stone 2",              {});
locationTable[MOON_DEKU_GOSSIP_3]                                  = ItemLocation::HintStone  (0x00,0x210b, true, "Moon Deku Trial Gossip Stone 3",              {});
locationTable[MOON_DEKU_GOSSIP_4]                                  = ItemLocation::HintStone  (0x00,0x210a, true, "Moon Deku Trial Gossip Stone 4",              {});
locationTable[MOON_DEKU_GOSSIP_5]                                  = ItemLocation::HintStone  (0x00,0x210c, true, "Moon Deku Trial Gossip Stone 5",              {});
locationTable[MOON_GORON_GOSSIP_1]                                 = ItemLocation::HintStone  (0x00,0x2110, true, "Moon Goron Trial Gossip Stone 1",             {});
locationTable[MOON_GORON_GOSSIP_2]                                 = ItemLocation::HintStone  (0x00,0x2111, true, "Moon Goron Trial Gossip Stone 2",             {});
locationTable[MOON_GORON_GOSSIP_3]                                 = ItemLocation::HintStone  (0x00,0x210e, true, "Moon Goron Trial Gossip Stone 3",             {});
locationTable[MOON_GORON_GOSSIP_4]                                 = ItemLocation::HintStone  (0x00,0x210f, true, "Moon Goron Trial Gossip Stone 4",             {});
locationTable[MOON_GORON_GOSSIP_5]                                 = ItemLocation::HintStone  (0x00,0x210d, true, "Moon Goron Trial Gossip Stone 5",             {});
locationTable[MOON_ZORA_GOSSIP_1]                                  = ItemLocation::HintStone  (0x00,0x2112, true, "Moon Zora Trial Gossip Stone 1",              {});
locationTable[MOON_ZORA_GOSSIP_2]                                  = ItemLocation::HintStone  (0x00,0x2113, true, "Moon Zora Trial Gossip Stone 2",              {});
locationTable[MOON_ZORA_GOSSIP_3]                                  = ItemLocation::HintStone  (0x00,0x2114, true, "Moon Zora Trial Gossip Stone 3",              {});
locationTable[MOON_ZORA_GOSSIP_4]                                  = ItemLocation::HintStone  (0x00,0x2116, true, "Moon Zora Trial Gossip Stone 4",              {});
locationTable[MOON_ZORA_GOSSIP_5]                                  = ItemLocation::HintStone  (0x00,0x2115, true, "Moon Zora Trial Gossip Stone 5",              {});
locationTable[MOON_LINK_GOSSIP_1]                                  = ItemLocation::HintStone  (0x00,0x2103, true, "Moon Link Trial Gossip Stone 1",              {});
locationTable[MOON_LINK_GOSSIP_2]                                  = ItemLocation::HintStone  (0x00,0x2104, true, "Moon Link Trial Gossip Stone 2",              {});
locationTable[MOON_LINK_GOSSIP_3]                                  = ItemLocation::HintStone  (0x00,0x2105, true, "Moon Link Trial Gossip Stone 3",              {});
locationTable[MOON_LINK_GOSSIP_4]                                  = ItemLocation::HintStone  (0x00,0x2106, true, "Moon Link Trial Gossip Stone 4",              {});
locationTable[MOON_LINK_GOSSIP_5]                                  = ItemLocation::HintStone  (0x00,0x2107, true, "Moon Link Trial Gossip Stone 5",              {});


    /*-------------------------------
            --- CUTSCENES ---
      -------------------------------*/
/*TODO--CUTSCENE SKIPS FOR MM3D - EXAMPLES FROM OOT3D BELOW

    locationTable[TOT_LIGHT_ARROWS_CUTSCENE]                     = ItemLocation::Delayed(0xFF, 0x01, true, "ToT Light Arrow Cutscene",                       TOT_LIGHT_ARROWS_CUTSCENE,   LIGHT_ARROWS,              {Category::cTempleOfTime, Category::cMarket},                                                                     EventChkInf(0xC4),               GROUP_HYRULE_CASTLE);
    locationTable[LW_GIFT_FROM_SARIA]                            = ItemLocation::Delayed(0xFF, 0x02, true, "LW Gift From Saria",                             LW_GIFT_FROM_SARIA,          PROGRESSIVE_OCARINA,       {Category::cLostWoods, Category::cForest},                                                                        EventChkInf(0xC1),               GROUP_LOST_WOODS);
    locationTable[ZF_GREAT_FAIRY_REWARD]                         = ItemLocation::Delayed(0xFF, 0x10, true, "ZF Great Fairy Reward",                          ZF_GREAT_FAIRY_REWARD,       FARORES_WIND,              {Category::cZorasFountain, Category::cFairies},                                                                   ItemGetInf(16),                  GROUP_ZORAS_DOMAIN);
    locationTable[HC_GREAT_FAIRY_REWARD]                         = ItemLocation::Delayed(0xFF, 0x11, true, "HC Great Fairy Reward",                          HC_GREAT_FAIRY_REWARD,       DINS_FIRE,                 {Category::cHyruleCastle, Category::cMarket, Category::cFairies},                                                 ItemGetInf(17),                  GROUP_HYRULE_CASTLE);
    locationTable[COLOSSUS_GREAT_FAIRY_REWARD]                   = ItemLocation::Delayed(0xFF, 0x12, true, "Colossus Great Fairy Reward",                    COLOSSUS_GREAT_FAIRY_REWARD, NAYRUS_LOVE,               {Category::cDesertColossus, Category::cFairies},                                                                  ItemGetInf(18),                  GROUP_GERUDO_VALLEY);
    locationTable[DMT_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x13, true, "DMT Great Fairy Reward",                         DMT_GREAT_FAIRY_REWARD,      PROGRESSIVE_MAGIC_METER,   {Category::cDeathMountainTrail, Category::cDeathMountain, Category::cFairies},                                    Chest(0x3B, 0x00),               GROUP_DEATH_MOUNTAIN);
    locationTable[DMC_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x14, true, "DMC Great Fairy Reward",                         DMC_GREAT_FAIRY_REWARD,      PROGRESSIVE_MAGIC_METER,   {Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFairies},                                   Chest(0x3B, 0x01),               GROUP_DEATH_MOUNTAIN);
    locationTable[OGC_GREAT_FAIRY_REWARD]                        = ItemLocation::Delayed(0xFF, 0x15, true, "OGC Great Fairy Reward",                         OGC_GREAT_FAIRY_REWARD,      DOUBLE_DEFENSE,            {Category::cOutsideGanonsCastle, Category::cFairies},                                                             Chest(0x3B, 0x02),               GROUP_DUNGEON_GANONS_CASTLE);
                                                                                                                                                                                                               
    locationTable[SHEIK_IN_FOREST]                               = ItemLocation::Delayed(0xFF, 0x20, true, "Sheik in Forest",                                SHEIK_IN_FOREST,             MINUET_OF_FOREST,          {Category::cSacredForestMeadow, Category::cForest, Category::cSong},                                             EventChkInf(0x50),               GROUP_LOST_WOODS);
    locationTable[SHEIK_IN_CRATER]                               = ItemLocation::Delayed(0xFF, 0x21, true, "Sheik in Crater",                                SHEIK_IN_CRATER,             BOLERO_OF_FIRE,            {Category::cDeathMountainCrater, Category::cDeathMountain, Category::cSong},                                     EventChkInf(0x51),               GROUP_DEATH_MOUNTAIN);
    locationTable[SHEIK_IN_ICE_CAVERN]                           = ItemLocation::Delayed(0xFF, 0x22, true, "Sheik in Ice Cavern",                            SHEIK_IN_ICE_CAVERN,         SERENADE_OF_WATER,         {Category::cIceCavern, Category::cSong, Category::cSongDungeonReward},                                            EventChkInf(0x52),               GROUP_ZORAS_DOMAIN);
    locationTable[SHEIK_AT_COLOSSUS]                             = ItemLocation::Delayed(0xFF, 0x23, true, "Sheik at Colossus",                              SHEIK_AT_COLOSSUS,           REQUIEM_OF_SPIRIT,         {Category::cDesertColossus, Category::cSong},                                                                    EventChkInf(0xAC),               GROUP_GERUDO_VALLEY);
    locationTable[SHEIK_IN_KAKARIKO]                             = ItemLocation::Delayed(0xFF, 0x24, true, "Sheik in Kakariko",                              SHEIK_IN_KAKARIKO,           NOCTURNE_OF_SHADOW,        {Category::cKakarikoVillage, Category::cKakariko, Category::cSong},                                              EventChkInf(0xAA),               GROUP_KAKARIKO);
    locationTable[SHEIK_AT_TEMPLE]                               = ItemLocation::Delayed(0xFF, 0x25, true, "Sheik at Temple",                                SHEIK_AT_TEMPLE,             PRELUDE_OF_LIGHT,          {Category::cTempleOfTime, Category::cMarket, Category::cSong},                                                   EventChkInf(0x55),               GROUP_HYRULE_CASTLE);
    locationTable[SONG_FROM_IMPA]                                = ItemLocation::Delayed(0xFF, 0x26, true, "Song from Impa",                                 SONG_FROM_IMPA,              ZELDAS_LULLABY,            {Category::cHyruleCastle, Category::cMarket, Category::cSong, Category::cSongDungeonReward},                      EventChkInf(0x59),               GROUP_HYRULE_CASTLE);
    locationTable[SONG_FROM_MALON]                               = ItemLocation::Delayed(0xFF, 0x27, true, "Song from Malon",                                SONG_FROM_MALON,             EPONAS_SONG,               {Category::cLonLonRanch, Category::cSong},                                                                       EventChkInf(0x58),               GROUP_LON_LON_RANCH);
    locationTable[SONG_FROM_SARIA]                               = ItemLocation::Delayed(0xFF, 0x28, true, "Song from Saria",                                SONG_FROM_SARIA,             SARIAS_SONG,               {Category::cSacredForestMeadow, Category::cForest, Category::cSong},                                             EventChkInf(0x57),               GROUP_LOST_WOODS);
    locationTable[SONG_FROM_COMPOSERS_GRAVE]                     = ItemLocation::Delayed(0xFF, 0x29, true, "Song from Composers Grave",                      SONG_FROM_COMPOSERS_GRAVE,   SUNS_SONG,                 {Category::cGraveyard, Category::cKakariko, Category::cSong},                                                    EventChkInf(0x5A),               GROUP_KAKARIKO);
    locationTable[SONG_FROM_OCARINA_OF_TIME]                     = ItemLocation::Delayed(0xFF, 0x2A, true, "Song from Ocarina of Time",                      SONG_FROM_OCARINA_OF_TIME,   SONG_OF_TIME,              {Category::cHyruleField, Category::cSong, Category::cNeedSpiritualStones},                                       EventChkInf(0xA9),               GROUP_HYRULE_FIELD);
    locationTable[SONG_FROM_WINDMILL]                            = ItemLocation::Delayed(0xFF, 0x2B, true, "Song from Windmill",                             SONG_FROM_WINDMILL,          SONG_OF_STORMS,            {Category::cKakarikoVillage, Category::cKakariko, Category::cSong},                                              EventChkInf(0x5B),               GROUP_KAKARIKO);
*/
}

/* TODO-- SHOP VECTORS FOR ASSIGNING ITEMS TO SHOP PLACEMENTS */
std::vector<LocationKey> TP_ShopLocations = {
  TRADING_POST_ITEM_1,
  TRADING_POST_ITEM_2,
  TRADING_POST_ITEM_3,
  TRADING_POST_ITEM_4,
  TRADING_POST_ITEM_5,
  TRADING_POST_ITEM_6,
  TRADING_POST_ITEM_7,
  TRADING_POST_ITEM_8,
};

std::vector<LocationKey> BS_ShopLocations = {
 BOMB_SHOP_ITEM_1,
 BOMB_SHOP_ITEM_2,
 //BOMB_SHOP_ITEM_3,
 W_CLOCK_TOWN_BOMB_BAG_BUY,
 W_CLOCK_TOWN_BIG_BOMB_BAG_BUY,
};

std::vector<LocationKey> SS_ShopLocations = {
 POTION_SHOP_ITEM_1,
 POTION_SHOP_ITEM_2,
 POTION_SHOP_ITEM_3,
};

std::vector<LocationKey> GV_ShopLocations = {
 GORON_SHOP_ITEM_1,
 GORON_SHOP_ITEM_2,
 GORON_SHOP_ITEM_3,
};
std::vector<LocationKey> ZH_ShopLocations = {
 ZORA_SHOP_ITEM_1,
 ZORA_SHOP_ITEM_2,
 ZORA_SHOP_ITEM_3,
};
std::vector<LocationKey> TingleMapLocations = {
 TINGLE_N_CLOCK_TOWN_CT,
 TINGLE_ROAD_TO_SS_WF,
 TINGLE_TWIN_ISLANDS_SH,
 TINGLE_GBC_GB,
 TINGLE_MILK_ROAD_RR,
 TINGLE_IKANA_CANYON_ST,
};
//List of shop location lists, used for shop shuffle
std::vector<std::vector<LocationKey>> ShopLocationLists = {
  TP_ShopLocations,
  BS_ShopLocations,
  SS_ShopLocations,
  GV_ShopLocations,
  ZH_ShopLocations,
  TingleMapLocations,
};

//List of gossip stone locations for hints
std::vector<LocationKey> gossipStoneLocations = {
  TF_MILK_ROAD_TREE_GOSSIP,
  TF_IKANA_SNOWHEAD_GOSSIP,
  TF_OBSERVATORY_GOSSIP,
  TF_TOP_SNOWHEAD_GOSSIP,
  TF_LOWER_SNOWHEAD_GOSSIP,
  TF_NEAR_GRASS_CHEST_GOSSIP,
  TF_FOUR_STONE_GROTTO_1,
  TF_FOUR_STONE_GROTTO_2,
  TF_FOUR_STONE_GROTTO_3,
  TF_FOUR_STONE_GROTTO_4,
  ROAD_TO_SS_GOSSIP,
  SS_GOSSIP,
  SSH_GOSSIP,
  PATH_TO_MV_GOSSIP,
  MV_NEAR_FROGS_GOSSIP,
  MV_NEAR_GROTTO_GOSSIP,
  GBC_BENEATH_COW_GROTTO_GOSSIP,
  GBC_OUTSIDE_FORTRESS_GOSSIP,
  ZC_GOSSIP,
  MR_GOSSIP,
  RR_ENTRANCE_GOSSIP,
  RR_FIELD_GOSSIP,
  RR_BARN_GOSSIP,
  DOGGY_RACETRACK_GOSSIP,
  CUCCO_SHACK_GOSSIP,
  IC_DOCK_GOSSIP,
  IC_SAKON_GOSSIP,
  IC_SPIRIT_HOUSE_GOSSIP,
  MOON_DEKU_GOSSIP_1,
  MOON_DEKU_GOSSIP_2,
  MOON_DEKU_GOSSIP_3,
  MOON_DEKU_GOSSIP_4,
  MOON_DEKU_GOSSIP_5,
  MOON_GORON_GOSSIP_1,
  MOON_GORON_GOSSIP_2,
  MOON_GORON_GOSSIP_3,
  MOON_GORON_GOSSIP_4,
  MOON_GORON_GOSSIP_5,
  MOON_ZORA_GOSSIP_1,
  MOON_ZORA_GOSSIP_2,
  MOON_ZORA_GOSSIP_3,
  MOON_ZORA_GOSSIP_4,
  MOON_ZORA_GOSSIP_5,
  MOON_LINK_GOSSIP_1,
  MOON_LINK_GOSSIP_2,
  MOON_LINK_GOSSIP_3,
  MOON_LINK_GOSSIP_4,
  MOON_LINK_GOSSIP_5,
};

std::vector<LocationKey> dungeonRewardLocations = {
  //Bosses
  ODOLWA,
  GOHT, 
  GYORG,
  TWINMOLD,
  //MAJORA,
  //LINKS_POCKET,
};
std::vector<LocationKey> overworldLocations = {
 // Clock Tower
  CLOCK_TOWER_OCARINA_OF_TIME,
  HMS_DEKU_MASK,
  HMS_SONG_OF_HEALING,
  HMS_BOMBERS_NOTEBOOK,
  HMS_STARTING_SWORD,
  HMS_STARTING_SHIELD,
  //PRE_CLOCK_TOWN_CHEST,
//Deku Palace
  DEKU_PALACE_BEAN_SELLER,
  DEKU_PALACE_WEST_GARDEN,
  DEKU_PALACE_BUTLER_RACE,
  DEKU_PALACE_BEAN_GROTTO_CHEST,
  DEKU_PALACE_IMPRISONED_MONKEY,
//East Clock Town
  E_CLOCK_TOWN_AROMA_IN_BAR,
  E_CLOCK_TOWN_ARCHERY_1,
  E_CLOCK_TOWN_ARCHERY_2,
  E_CLOCK_TOWN_MAYOR,
  E_CLOCK_TOWN_HONEY_DARLING_3DAYS,
  E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON,
  E_CLOCK_TOWN_POSTMAN_FREEDOM,
  E_CLOCK_TOWN_GORMAN,
  E_CLOCK_TOWN_AROMA_IN_OFFICE,
  BOMBERS_HIDEOUT_CHEST,
  E_CLOCK_TOWN_CHEST,
  E_CLOCK_TOWN_POSTBOX,
  //E_CLOCK_TOWN_MILK_BAR_CHATEAU,
  //E_CLOCK_TOWN_MILK_BAR_MILK,
  GORMAN_TRACK_MYSTERY_MILK_QUEST,
  //E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA,
  //E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU,
//Goron Village
  GORON_VILLAGE_POWDER_KEG_CHALLENGE,
  GORON_VILLAGE_SCRUB_PURCHASE,
  GORON_VILLAGE_LENS_OF_TRUTH_CHEST,
  GORON_VILLAGE_SCRUB_TRADE,
  GORON_VILLAGE_LEDGE,
  GORON_VILLAGE_GORON_LULLABY,
  LENS_CAVE_RED_RUPEE,
  LENS_CAVE_PURPLE_RUPEE,
  GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING,
  GORON_VILLAGE_SCRUB_PURCHASE_SPRING,
  GORON_VILLAGE_SCRUB_TRADE_SPRING,
  GORON_VILLAGE_LEDGE_SPRING,
  GORON_SHOP_ITEM_1,
  GORON_SHOP_ITEM_2,
  GORON_SHOP_ITEM_3,
//Great Bay Coast
  //GBC_OCEAN_SPIDER_DAY1,--Handled in Dungeon.cpp
  //GBC_OCEAN_SPIDER_DAY2,
  //GBC_OCEAN_SPIDER_DAY3,
  GBC_FISHERMAN_GAME,
  //GBC_OCEAN_SPIDER_CHEST,--Handled in Dungeon.cpp
  GBC_LAB_FISH,
  GBC_LEDGE,
  GBC_MIKAU,
  GBC_BABY_ZORAS,
  GBC_GROTTO_CHEST,
  GBC_GROTTO_COW1,
  GBC_GROTTO_COW2,
  GBC_FISHERMAN_PHOTO,
  TINGLE_GBC_GB,
  TINGLE_GBC_ST,
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
  TWIN_ISLANDS_LULLABY_INTRO,
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

};

ItemLocation* Location(LocationKey locKey) {
    return &(locationTable[locKey]);
}

std::vector<LocationKey> allLocations = {};
std::vector<LocationKey> everyPossibleLocation = {};

//set of overrides to write to the patch
std::set<ItemOverride, ItemOverride_Compare> overrides = {};

std::vector<std::vector<LocationKey>> playthroughLocations;
std::vector<LocationKey> wothLocations;
bool playthroughBeatable = false;
bool allLocationsReachable = false;
bool showItemProgress = false;

u16 itemsPlaced = 0;

void AddLocation(LocationKey loc, std::vector<LocationKey>* destination = &allLocations) {
  destination->push_back(loc);
}

template <typename Container>
void AddLocations(const Container& locations, std::vector<LocationKey>* destination = &allLocations) {
  destination->insert(destination->end(), std::cbegin(locations), std::cend(locations));
}

void GenerateLocationPool() {

  allLocations.clear();
  //AddLocation(LINKS_POCKET);
  AddLocations(overworldLocations);
  for (auto dungeon : Dungeon::dungeonList) {
    AddLocations(dungeon->GetDungeonLocations());
  } 
}

void PlaceItemInLocation(LocationKey locKey, ItemKey item, bool applyEffectImmediately/* = false*/) {
  auto loc = Location(locKey);
  PlacementLog_Msg("\n");
  PlacementLog_Msg(ItemTable(item).GetName().GetEnglish());
  PlacementLog_Msg(" placed at ");
  PlacementLog_Msg(loc->GetName());
  PlacementLog_Msg("\n\n");
  
  if (applyEffectImmediately || Settings::Logic.Is(LogicSetting::LOGIC_NONE) || Settings::Logic.Is(LogicSetting::LOGIC_VANILLA)) {
    ItemTable(item).ApplyEffect();
  }

  itemsPlaced++;
  if (showItemProgress) {
    double completion = (double) itemsPlaced / (double)(allLocations.size() + dungeonRewardLocations.size());
    printf("\x1b[8;10HPlacing Items.");
    if (completion > 0.25) printf(".");
    if (completion > 0.50) printf(".");
  }

  //If we're placing a non-shop item in a shop location, we want to record it for custom messages
 /* if (ItemTable(item).GetItemType() != ITEMTYPE_SHOP && loc->IsCategory(Category::cShop)) {
    int index = TransformShopIndex(GetShopIndex(locKey));
    NonShopItems[index].Name = ItemTable(item).GetName();
    NonShopItems[index].Repurchaseable = ItemTable(item).GetItemType() == ITEMTYPE_REFILL || ItemTable(item).GetHintKey() == PROGRESSIVE_BOMBCHUS;
  }*/

  loc->SetPlacedItem(item);
}

std::vector<LocationKey> GetLocations(const std::vector<LocationKey>& locationPool, Category categoryInclude, Category categoryExclude /*= Category::cNull*/ ) {
  std::vector<LocationKey> locationsInCategory;
  for (LocationKey locKey : locationPool) {
    if (Location(locKey)->IsCategory(categoryInclude) && !Location(locKey)->IsCategory(categoryExclude)) {
      locationsInCategory.push_back(locKey);
    }
  }
  return locationsInCategory;
}

void LocationReset() {
/*for (LocationKey il : allLocations) {
    Location(il)->RemoveFromPool();
  }

  for (LocationKey il : dungeonRewardLocations) {
    Location(il)->RemoveFromPool();
  }

  for (LocationKey il : gossipStoneLocations) {
    Location(il)->RemoveFromPool();
  }*/

  // Something's still missing from allLocations, IDK what though and this fixes it
  for (LocationKey il = LINKS_POCKET; il <= OSH_COLORED_SKULLS_POT; il++) {
    Location(il)->RemoveFromPool();
  }

  //Location(GANONDORF_HINT)->RemoveFromPool();
}

void ItemReset() {
  for (LocationKey il : allLocations) {
    Location(il)->ResetVariables();
  }

  for (LocationKey il : dungeonRewardLocations) {
    Location(il)->ResetVariables();
  }

  itemsPlaced = 0;
}

void HintReset() {
  for (LocationKey il : gossipStoneLocations) {
    Location(il)->ResetVariables();
  }
}

//Fills everyPossibleLocation and creates an exclusion option for each location.
//everyPossibleLocation is used in the menu to lock/hide excluding locations
void AddExcludedOptions() {
  AddLocations(overworldLocations, &everyPossibleLocation);
 
  for (auto dungeon : Dungeon::dungeonList) {
    AddLocations(dungeon->GetEveryLocation(), &everyPossibleLocation);
  }
  
  for (LocationKey il: everyPossibleLocation) {
    Location(il)->AddExcludeOption();
  }
}

void CreateItemOverrides() {
  PlacementLog_Msg("NOW CREATING OVERRIDES\n\n");
 
 //Duplicate day 1 reward onto day 2/3 location
 auto loc6 = Location(SOUTHERN_SWAMP_KOTAKE);
 PlaceItemInLocation(SOUTHERN_SWAMP_KOTAKE_IN_WOODS, loc6->GetPlacedItemKey());
 //cover all postbox locations
 auto loc7 = Location(S_CLOCK_TOWN_POSTBOX);
 PlaceItemInLocation(N_CLOCK_TOWN_POSTBOX, loc7->GetPlacedItemKey());
 PlaceItemInLocation(E_CLOCK_TOWN_POSTBOX, loc7->GetPlacedItemKey());
 //Duplicate Tingle Maps so each map buy is the same in both locaations
 auto loc8 = Location(TINGLE_N_CLOCK_TOWN_CT); //get clocktown map item
 auto loc9 = Location(TINGLE_ROAD_TO_SS_WF); //get swamp map item
 auto loc10 = Location(TINGLE_TWIN_ISLANDS_SH); //get snowhead map item
 auto loc11 = Location(TINGLE_MILK_ROAD_RR); //get ranch map item
 auto loc12 = Location(TINGLE_GBC_GB); //get great bay map item
 auto loc13 = Location(TINGLE_IKANA_CANYON_ST); //get stone tower map item
 PlaceItemInLocation(TINGLE_N_CLOCK_TOWN_WF, loc9->GetPlacedItemKey());//copy woodfall map into clocktown 
 PlaceItemInLocation(TINGLE_ROAD_TO_SS_SH, loc10->GetPlacedItemKey());//copy snowhead map into swamp
 PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR, loc11->GetPlacedItemKey());//copy ranch map into snowhead
 PlaceItemInLocation(TINGLE_TWIN_ISLANDS_SH_SPRING, loc10->GetPlacedItemKey());//copy snowhead map into snowhead spring location
 PlaceItemInLocation(TINGLE_TWIN_ISLANDS_RR_SPRING, loc11->GetPlacedItemKey());//copy ranch map into snowhead spring location
 PlaceItemInLocation(TINGLE_MILK_ROAD_GB, loc12->GetPlacedItemKey());//copy great bay map into ranch
 PlaceItemInLocation(TINGLE_GBC_ST, loc13->GetPlacedItemKey());//copy stone tower map into great bay
 PlaceItemInLocation(TINGLE_IKANA_CANYON_CT, loc8->GetPlacedItemKey()); //copy clocktown into stone tower
 //Keaton Quiz
 auto loc14 = Location(N_CLOCK_TOWN_KEATON_QUIZ);
 PlaceItemInLocation(MILK_ROAD_KEATON_QUIZ, loc14->GetPlacedItemKey());//copy NCT keaton quiz item to milk road
 //Spring time Goron Village
 auto loc15 = Location(GORON_VILLAGE_POWDER_KEG_CHALLENGE);
 auto loc16 = Location(GORON_VILLAGE_SCRUB_PURCHASE);
 auto loc17 = Location(GORON_VILLAGE_SCRUB_TRADE);
 auto loc18 = Location(GORON_VILLAGE_LEDGE);
 PlaceItemInLocation(GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING, loc15->GetPlacedItemKey());
 PlaceItemInLocation(GORON_VILLAGE_SCRUB_PURCHASE_SPRING, loc16->GetPlacedItemKey());
 PlaceItemInLocation(GORON_VILLAGE_SCRUB_TRADE_SPRING, loc17->GetPlacedItemKey());
 PlaceItemInLocation(GORON_VILLAGE_LEDGE_SPRING, loc18->GetPlacedItemKey());

  for (LocationKey locKey : allLocations) {
    auto loc = Location(locKey);
    ItemOverride_Value val = ItemTable(loc->GetPlacedItemKey()).Value();
    //If this is an ice trap in a shop, change the name based on what the model will look like
    //if (loc->GetPlacedItemKey() == ICE_TRAP && loc->IsCategory(Category::cShop)) {
      //NonShopItems[TransformShopIndex(GetShopIndex(locKey))].Name = GetIceTrapName(val.looksLikeItemId);
    //}
    overrides.insert({
      .key = loc->Key(),
      .value = val,
    });
 //PlacementLog_Msg("\tLoc's Scene: ");
 //PlacementLog_Msg(std::to_string(loc->GetScene()));
    PlacementLog_Msg("\tScene: ");
    PlacementLog_Msg(std::to_string(loc->Key().scene));
    PlacementLog_Msg("\tType: ");
    PlacementLog_Msg(std::to_string((u8)loc->Key().type));
 //PlacementLog_Msg("\tLoc's Flag: ");
 //PlacementLog_Msg(std::to_string(loc->GetFlag()));
    PlacementLog_Msg("\tFlag:  ");
    PlacementLog_Msg(std::to_string(loc->Key().flag));
    PlacementLog_Msg("\t");
    PlacementLog_Msg(loc->GetName());
    PlacementLog_Msg(": ");
    PlacementLog_Msg(loc->GetPlacedItemName().GetEnglish());
    PlacementLog_Msg("\n");
  }
  PlacementLog_Msg("Overrides Created: ");
  CitraPrint("Overrides Created");
  PlacementLog_Msg(std::to_string(overrides.size()));
}
