#include "item_location.hpp"
#include "item_pool.hpp"
#include "shops.hpp"
#include "random.hpp"
#include "location_access.hpp"
#include "item.hpp"
#include "debug.hpp"

#include <math.h>
#include <map>
#include <vector>
#include <string>

using namespace Settings;

std::vector<ItemAndPrice> NonShopItems = {};

static std::array<std::array<Text, 3>, 0xD5> trickNameTable; //Table of trick ice trap names
bool initTrickNames = false; //indicates if trick ice trap names have been initialized yet

//Set vanilla shop item locations before potential randomization
void PlaceVanillaShopItems() {
    // Loop to place vanilla items in each location
    for (size_t i = 0; i < ShopLocationLists.size(); i++) {
        for (size_t j = 0; j < ShopLocationLists[i].size(); j++) {
            Location(ShopLocationLists[i][j])->PlaceVanillaItem();
        }
    }
}
// This table contains a cumulative probability for each possible shop price based on
//  a beta distribution with alpha = 1.5, beta = 2, and the result of the distribution, a float in [0.0, 1.0),
//  being multiplied by 60, cast to an integer, then multiplied by 5 to give a value in range [0, 495] in increments
//  of 5. Meaning the first value is the probability of 0, the next value is the probability of 0 plus the probability
//  of 5, etc.
// Probabilities generated using a python script with 1 billion trials, so should hopefully be pretty good
// Average price ~126
// ~38% chance of needing no wallet, ~45% chance of needing 1, ~17% chance of needing 2
static constexpr std::array<double, 60> ShopPriceProbability = {
    0.005326994, 0.014908518, 0.027114719, 0.041315285, 0.057136304, 0.074325887, 0.092667151, 0.112002061, 0.132198214,
    0.153125390, 0.174696150, 0.196810540, 0.219388148, 0.242361379, 0.265657012, 0.289205134, 0.312970402, 0.336877590,
    0.360881110, 0.384932772, 0.408976198, 0.432982176, 0.456902494, 0.480686053, 0.504313389, 0.527746488, 0.550938554,
    0.573856910, 0.596465330, 0.618736235, 0.640646600, 0.662162782, 0.683240432, 0.703859801, 0.724001242, 0.743631336,
    0.762722631, 0.781259986, 0.799198449, 0.816521905, 0.833208595, 0.849243398, 0.864579161, 0.879211177, 0.893112051,
    0.906263928, 0.918639420, 0.930222611, 0.940985829, 0.950914731, 0.959992180, 0.968187000, 0.975495390, 0.981884488,
    0.987344345, 0.991851853, 0.995389113, 0.997937921, 0.999481947, 1.000000000,
};

size_t GetNumberOfBins(int maxPrice, int stepSize) {
    if (maxPrice <= 0) {
        return 1;
    }

    double rawResult = floor((double)maxPrice / (double)stepSize) + 1.0;
    return (size_t)rawResult;
}

double GetFractionForOneBin(size_t numberOfBins) {
    return 1.0 / (double)numberOfBins;
}

double CalculateCumulativeDistributionFunction(double input) {
    return 2.5 * (1 - 0.6 * input) * pow(input, 1.5);
}

int GetShopPrice() {
    const int stepSize = 5;
    if (Settings::ShopsanityPrices.Value<u8>() == 1) /*Affordable*/ {
        // Affordable option is like affordable scrubs. All items cost 10 rupees.
        return 10;
    } else if (Settings::ShopsanityPrices.Value<u8>() == 0) /*Random*/ {
        // "Original" Shopsanity price behaviour. Using the precomputed probability values from the ShopPriceProbability
        // array.
        double random = RandomDouble(); // Randomly generated probability value
        for (size_t i = 0; i < ShopPriceProbability.size(); i++) {
            if (random < ShopPriceProbability[i]) {
                // The randomly generated value has surpassed the total probability up to this point, so this is the
                // generated price
                return i * stepSize; // i in range [0, 59], output in range [0, 295] in increments of 5
            }
        }
    }
    
    // Shopsanity price behaviour with caps for each wallet size. /*TO-DO?*/
    int maxPrice = 495;

    // switch (Settings::ShopsanityPrices.Value<u8>()) {
    //     case SHOPSANITY_PRICE_CHILD:
    //         maxPrice = 99;
    //         break;
    //     case SHOPSANITY_PRICE_ADULT:
    //         maxPrice = 200;
    //         break;
    //     case SHOPSANITY_PRICE_GIANT:
    //         maxPrice = 500;
    //         break;
    //     case SHOPSANITY_PRICE_TYCOON:
    //         maxPrice = 999;
    //         break;
    // }

    // Since there are a different amount of multiples of 5 rupees between the different settings we need to calculate
    // the amount of "bins" aka how many options are available.
    size_t numberOfBins = GetNumberOfBins(maxPrice, stepSize);

    // We then need to calculate how those bins relate to a fraction between 0.0 and 1.0 so we can use that to run
    // the distribution calculation.
    double fractionForOneBin = GetFractionForOneBin(numberOfBins);

    // The diceroll that gives us the randomness for choosing the price.
    double random = RandomDouble();

    // We loop through the amount of bins to look for the bin that the random double fits in with the Cumulative
    // Distribution Function
    for (size_t i = 0; i < numberOfBins; i++) {
        if (random < CalculateCumulativeDistributionFunction(fractionForOneBin * (i + 1))) {
            return i * stepSize; // We've found which bin it is in so we can multiply by stepSize so we then get the
                                 // resulting price.
        }
    }

    return -1; // Shouldn't happen
}

// Similar to above, beta distribution with alpha = 1, beta = 2,
//  multiplied by 20 instead of 60 to give values in rage [0, 95] in increments of 5
// Average price ~31
static constexpr std::array<double, 20> ScrubPriceProbability = {
    0.097500187, 0.190002748, 0.277509301, 0.360018376, 0.437522571, 0.510021715, 0.577520272,
    0.640029304, 0.697527584, 0.750024535, 0.797518749, 0.840011707, 0.877508776, 0.910010904,
    0.937504342, 0.960004661, 0.977502132, 0.989998967, 0.997500116, 1.000000000,
};
s16 GetRandomScrubPrice() {
    double random = RandomDouble();
    for (size_t i = 0; i < ScrubPriceProbability.size(); i++) {
        if (random < ScrubPriceProbability[i]) {
            return i * 5; // i in range [0, 19], output in range [0, 95] in increments of 5
        }
    }
    return -1;
}

// Initialize the trick names table with 3 potential options, Easy, Medium, and Hard in each language
void InitTrickNames() {
        //   NaEnglish                        NaFrench   NaSpanish  EuGerman   EuEnglish  EuFrench   EuSpanish
    trickNameTable[(u32)GetItemID::GI_GREAT_FAIRY_SWORD] = {
        Text{"Biggoron's Sword",              "",        "",        "", },
        Text{"Fairy Blade",                   "",        "",        "", },
        Text{"Rainbow Sword",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_SHIELD_HERO] = {
        Text{"Hylian Shield",                 "",        "",        "", },
        Text{"Shield of the Hero",            "",        "",        "", },
        Text{"Legendary Shield",              "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_STICKS_1] = {
        Text{"Deku Branch",                   "",        "",        "", },
        Text{"Stick",                         "",        "",        "", },
        Text{"Deku's Stick",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_TOWN_TITLE_DEED] = {
        Text{"Land Toilet Paper",             "",        "",        "", },
        Text{"Land Title Deer",               "",        "",        "", },
        Text{"Sand Title Deed",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_SWAMP_TITLE_DEED] = {
        Text{"Swamp Toilet paper",            "",        "",        "", },
        Text{"Swarm Title Deed",              "",        "",        "", },
        Text{"Swap Title Deed",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MOUNTAIN_TITLE_DEED] = {
        Text{"Mountain Toilet Paper",         "",        "",        "", },
        Text{"Mustard Title Deed",            "",        "",        "", },
        Text{"Mountain Title Deep",           "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_OCEAN_TITLE_DEED] = {
        Text{"Ocean Toilet Paper",            "",        "",        "", },
        Text{"Urchin Title Deed",             "",        "",        "", },
        Text{"Ocean Tile Deed",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBERS_NOTEBOOK] = {
        Text{"Bombers Calendar",              "",        "",        "", },
        Text{"Bomber Notes Book",             "",        "",        "", },
        Text{"Boomer's Notebook",             "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_ROOM_KEY] = {
        Text{"Knife Chamber Key",             "",        "",        "", },
        Text{"Inn Key",                       "",        "",        "", },
        Text{"Root Key",                      "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_LETTER_TO_KAFEI] = {
        Text{"Anju's Response Letter",        "",        "",        "", },
        Text{"Kafei's Letter",                "",        "",        "", },
        Text{"Letter for Kafei",              "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_PENDANT_OF_MEMORIES] = {
        Text{"Kafei's Pendant",               "",        "",        "", },
        Text{"Pendant of Gregory",            "",        "",        "", },
        Text{"Pendant of Memorable",          "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_LETTER_TO_MAMA] = {
        Text{"Priority Mail",                 "",        "",        "", },
        Text{"Letter to Mommy",               "",        "",        "", },
        Text{"Letter to Madame Aroma",        "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MOONS_TEAR] = {
        Text{"Moon's Sweat",                  "",        "",        "", },
        Text{"Moon's Tea",                    "",        "",        "", },
        Text{"Noon's Tear",                   "",        "",        "", },
    };
    trickNameTable[0x2C] = { /*Spin Attack*/
        Text{"Spinning Slash",                "",        "",        "", },
        Text{"Spit Attack",                   "",        "",        "", },
        Text{"Spin Attach",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_LENS_OF_TRUTH] = {
        Text{"Good Glasses (Half)",           "",        "",        "", },
        Text{"Lens of Dare",                  "",        "",        "", },
        Text{"Lens of True",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_FIRE_ARROW] = {
        Text{"Flaming Arrow",                 "",        "",        "", },
        Text{"Fired Arrow",                   "",        "",        "", },
        Text{"Ire Arrow",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_ICE_ARROW] = {
        Text{"Freezing Arrow",                "",        "",        "", },
        Text{"Ice Trap Arrow",                "",        "",        "", },
        Text{"Nice Arrow",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_LIGHT_ARROW] = {
        Text{"Silver Arrow",                  "",        "",        "", },
        Text{"Lite Arrow",                    "",        "",        "", },
        Text{"Might Arrow",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_HOOKSHOT] = {
        Text{"Grapling Hook",                 "",        "",        "", },
        Text{"Longshot",                      "",        "",        "", },
        Text{"Hookshort",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAGIC_BEAN] = {
        Text{"Peapod",                        "",        "",        "", },
        Text{"Tasty Beans",                   "",        "",        "", },
        Text{"Magic Beam",                    "",        "",        "", },
    };
    trickNameTable[0xB2] = { /*Double Defense*/
        Text{"Doubloon Defense",              "",        "",        "", },
        Text{"Double the Fence",              "",        "",        "", },
        Text{"Double Defenestrate",           "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_OCARINA_OF_TIME] = {
        Text{"Fairy Ocarina",                 "",        "",        "", },
        Text{"Flute",                         "",        "",        "", },
        Text{"Ocarina",                       "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_PICTOGRAPH_BOX] = {
        Text{"Camera",                        "",        "",        "", },
        Text{"Pictogaffe Box",                "",        "",        "", },
        Text{"Picograph Box",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_POWDER_KEG] = {
        Text{"Dangerous Barrel",              "",        "",        "", },
        Text{"Powder Peg",                    "",        "",        "", },
        Text{"Power Keg",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KEATON] = {
        Text{"Fox Mask",                      "",        "",        "", },
        Text{"Kafei's Mask",                  "",        "",        "", },
        Text{"Kitsune Mask",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BUNNY_HOOD] = {
        Text{"Rabbit Ears",                   "",        "",        "", },
        Text{"Bunny Mask",                    "",        "",        "", },
        Text{"Funny Hood",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GORON] = {
        Text{"Darmani Mask",                  "",        "",        "", },
        Text{"Goron Soul",                    "",        "",        "", },
        Text{"Gordon Mask",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ZORA] = {
        Text{"Mikau Mask",                    "",        "",        "", },
        Text{"Zora Soul",                     "",        "",        "", },
        Text{"Zora Mark",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_DEKU] = {
        Text{"Sad Tree Mask",                 "",        "",        "", },
        Text{"Deku Soul",                     "",        "",        "", },
        Text{"Deku Scrub Mask",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_POSTMANS] = {
        Text{"Deliveryman's Uniform",         "",        "",        "", },
        Text{"Postman's Hood",                "",        "",        "", },
        Text{"Portman's Hat",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ALL_NIGHT] = {
        Text{"Sleepless Mask",                "",        "",        "", },
        Text{"All Right Mask",                "",        "",        "", },
        Text{"All Might Mask",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BLAST] = {
        Text{"Big Sneeze Mask",               "",        "",        "", },
        Text{"Bat Mask",                      "",        "",        "", },
        Text{"Blast Mass",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_STONE] = {
        Text{"Dampé Mask",                    "",        "",        "", },
        Text{"Stealth Mask",                  "",        "",        "", },
        Text{"Stoat Mask",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GREAT_FAIRYS] = {
        Text{"Big Lady Mask",                 "",        "",        "", },
        Text{"Great Ferry's Mask",            "",        "",        "", },
        Text{"Great Fairly's Mask",           "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BREMEN] = {
        Text{"Flute Player's Mask",           "",        "",        "", },
        Text{"Falco Mask",                    "",        "",        "", },
        Text{"Broman Mask",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_DON_GEROS] = {
        Text{"Head Frog",                     "",        "",        "", },
        Text{"Don Ribbit's Mask",             "",        "",        "", },
        Text{"Don Kero's Mask",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_OF_SCENTS] = {
        Text{"Pigma Dengar Mask",             "",        "",        "", },
        Text{"Mask of Cents",                 "",        "",        "", },
        Text{"Mask of Sense",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ROMANIS] = {
        Text{"Moo Moo Mask",                  "",        "",        "", },
        Text{"Cow Mask",                      "",        "",        "", },
        Text{"Romania Mask",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_TROUPE_LEADERS] = {
        Text{"Crying Mario Mask",             "",        "",        "", },
        Text{"Circus Troupe Mask",            "",        "",        "", },
        Text{"Troop Leader's Mask",           "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KAFEIS] = {
        Text{"Shyguy Mask",                   "",        "",        "", },
        Text{"Café's Mask",                   "",        "",        "", },
        Text{"Kafai's Mask",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_COUPLES] = {
        Text{"Face Shield",                   "",        "",        "", },
        Text{"Coupled Mask",                  "",        "",        "", },
        Text{"Coupler's Mask",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KAMARAOS] = {
        Text{"Symbiotic Dancer",              "",        "",        "", },
        Text{"Kaepora's Mask",                "",        "",        "", },
        Text{"Kamamo's mask",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GIBDO] = {
        Text{"Paper Mâché Mask",              "",        "",        "", },
        Text{"Redead Mask",                   "",        "",        "", },
        Text{"Mummy's Mask",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GARO] = {
        Text{"Ninja Mask",                    "",        "",        "", },
        Text{"Garo Hood",                     "",        "",        "", },
        Text{"Gero's Mask",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_CAPTAINS_HAT] = {
        Text{"Spooky Mask",                   "",        "",        "", },
        Text{"Keeta Mask",                    "",        "",        "", },
        Text{"Captain Mask",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GIANTS] = {
        Text{"Growing Boy's Mask",            "",        "",        "", },
        Text{"Giant's Masked",                "",        "",        "", },
        Text{"Giant Mask",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_FIERCE_DEITY] = {
        Text{"Big Bad Deity Mask",            "",        "",        "", },
        Text{"Fear's Deity Mask",             "",        "",        "", },
        Text{"Fierce Ditty Mask",             "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MASK_OF_TRUTH] = {
        Text{"Sheikah Mask",                  "",        "",        "", },
        Text{"Mask of Troupe",                "",        "",        "", },
        Text{"Mask of Tooth",                 "",        "",        "", },
    };
    trickNameTable[0xBA] = { /*Fishing Pass*/
        Text{"Fishing Voucher",               "",        "",        "", },
        Text{"Finishing Pass",                "",        "",        "", },
        Text{"Fishing Bass",                  "",        "",        "", },
    };
    trickNameTable[0x44] = { /*Swamp Skulltula Token*/
        Text{"Smelly Gold Skull",             "",        "",        "", },
        Text{"Swamp Skullwalltula Token",     "",        "",        "", },
        Text{"Swamp Skulltula Toucan",        "",        "",        "", },
    };
    trickNameTable[0x6D] = { /*Ocean Skulltula Token*/
        Text{"Musty Gold Skull",              "",        "",        "", },
        Text{"Ocean Skullwalltula Token",     "",        "",        "", },
        Text{"Ocean Skulltula Toucan",        "",        "",        "", },
    };
    trickNameTable[0xBB] = { /*Clock Town Stray Fairy*/
        Text{"Castle Town Stray Fairy",       "",        "",        "", },
        Text{"Orange Stray Fairy",            "",        "",        "", },
        Text{"Clock City Stray Fairy",        "",        "",        "", },
    };
    trickNameTable[0xBC] = { /*Woodfall Stray Fairy*/
        Text{"Forest Temple Stray Fairy",     "",        "",        "", },
        Text{"Pink Stray Fairy",              "",        "",        "", },
        Text{"Woodfall Lost Fairy",           "",        "",        "", },
    };
    trickNameTable[0xBD] = { /*Snowhead Stray Fairy*/
        Text{"Ice Cavern Stray Fairy",        "",        "",        "", },
        Text{"Green Stray Fairy",             "",        "",        "", },
        Text{"Snowhead Lost fairy",           "",        "",        "", },
    };
    trickNameTable[0xBE] = { /*Great Bay Stray Fairy*/
        Text{"Water Temple Stray Fairy",      "",        "",        "", },
        Text{"Violet Stray Fairy",            "",        "",        "", },
        Text{"Great Bay Lost Fairy",          "",        "",        "", },
    };
    trickNameTable[0xBF] = { /*Stone Tower Stray Fairy*/
        Text{"Spirit Temple Stray Fairy",     "",        "",        "", },
        Text{"Yellow Stray Fairy",            "",        "",        "", },
        Text{"Stone Tower Lost Fairy",        "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_EMPTY] = {
        Text{"Empty Jar",                     "",        "",        "", },
        Text{"Bottle",                        "",        "",        "", },
        Text{"Emptied Bottle",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MILK] = {
        Text{"Lon Lon Milk",                  "",        "",        "", },
        Text{"Bottle with Mirth",             "",        "",        "", },
        Text{"Milky Bottle",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_POTION_RED] = {
        Text{"Ketchup Bottle",                "",        "",        "", },
        Text{"Health Potion",                 "",        "",        "", },
        Text{"Red Syrup",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_GOLD_DUST] = {
        Text{"Flower Pollen",                 "",        "",        "", },
        Text{"Good Dust",                     "",        "",        "", },
        Text{"Golden Dust",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_CHATEAU_ROMANI] = {
        Text{"Chartreuse Romani",             "",        "",        "", },
        Text{"Chaton Romani",                 "",        "",        "", },
        Text{"Chàteau Romani",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MYSTERY_MILK] = {
        Text{"Gorman Track Milk",             "",        "",        "", },
        Text{"Moldy Milk",                    "",        "",        "", },
        Text{"Mysterious Milk",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_DEKU_PRINCESS_FAIRY] = {
        Text{"Bottled Deku Figurine",         "",        "",        "", },
        Text{"Flower Princess",               "",        "",        "", },
        Text{"Deku Princes",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_POTION_GREEN] = {
        Text{"Spinach Soup",                  "",        "",        "", },
        Text{"Magic Potion",                  "",        "",        "", },
        Text{"Green Potent",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_POTION_BLUE] = {
        Text{"Magic Mushroom Juice",          "",        "",        "", },
        Text{"Blue Drink",                    "",        "",        "", },
        Text{"Indigo Potion",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_FAIRY] = {
        Text{"Extra Life",                    "",        "",        "", },
        Text{"Trapped Fairy",                 "",        "",        "", },
        Text{"Bottle with Ferry",             "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_BUG] = {
        Text{"Creepy Crawlies",               "",        "",        "", },
        Text{"Bottle with Insects",           "",        "",        "", },
        Text{"Bottle with Bug",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_FISH] = {
        Text{"Termina Loach",                 "",        "",        "", },
        Text{"Fishie",                        "",        "",        "", },
        Text{"Bottle with Fist",              "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_POE_TEXT] = {
        Text{"Small Ghost",                   "",        "",        "", },
        Text{"Bottle with Ghini",             "",        "",        "", },
        Text{"Bottle with Foe",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_BIG_POE] = {
        Text{"Big Ghost",                     "",        "",        "", },
        Text{"Bottle with Composer Brother",  "",        "",        "", },
        Text{"Bottle with Big Foe",           "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_SPRING_WATER] = {
        Text{"Potable Water",                 "",        "",        "", },
        Text{"Bottle of Fresh Water",         "",        "",        "", },
        Text{"Bottle with Sprig Water",       "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_HOT_SPRING_WATER] = {
        Text{"Warm Spring Water",             "",        "",        "", },
        Text{"Hot Sprint Water",              "",        "",        "", },
        Text{"Hot Spring Walter",             "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_ZORA_EGG] = {
        Text{"Bottle with Eel's Egg",         "",        "",        "", },
        Text{"Bottle with Lulu's Egg",        "",        "",        "", },
        Text{"Bottle with Zoran Egg",         "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MAGIC_MUSHROOM] = {
        Text{"Pungent Mushroom",              "",        "",        "", },
        Text{"Bottle with Much Room",         "",        "",        "", },
        Text{"Bottle without Mushroom",       "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_SEAHORSE] = {
        Text{"Sea Epona",                     "",        "",        "", },
        Text{"Seas Horse",                    "",        "",        "", },
        Text{"Seehorse",                      "",        "",        "", },
    };
    trickNameTable[0x53] = { /*Song of Time*/
        Text{"Zelda's Memory Song",           "",        "",        "", },
        Text{"Sun's Song",                    "",        "",        "", },
        Text{"Song of Tim",                   "",        "",        "", },
    };
    trickNameTable[0x73] = { /*Song of Storms*/
        Text{"Song of Bad Weather",           "",        "",        "", },
        Text{"Song of Thunder",               "",        "",        "", },
        Text{"Song of Storks",                "",        "",        "", },
    };
    trickNameTable[0x4B] = { /*Sonata of Awakening*/
        Text{"Morning Alarm Song",            "",        "",        "", },
        Text{"Song of Awakening",             "",        "",        "", },
        Text{"Sonata of Wakening",            "",        "",        "", },
    };
    trickNameTable[0x4E] = { /*New Wave Bossa Nova*/
        Text{"Ballad of the Wind Fish",       "",        "",        "", },
        Text{"Newave Bossanova",              "",        "",        "", },
        Text{"New Wavy Bossa Nova",           "",        "",        "", },
    };
    trickNameTable[0x4F] = { /*Elegy of Emptiness*/
        Text{"Elegy of Ben",                  "",        "",        "", },
        Text{"Melody of Emptiness",           "",        "",        "", },
        Text{"Elegy of Emptyness",            "",        "",        "", },
    };
    trickNameTable[0x51] = { /*Oath to Order*/
        Text{"Giant's Song",                  "",        "",        "", },
        Text{"Oar to Order",                  "",        "",        "", },
        Text{"Oath to Odour",                 "",        "",        "", },
    };
    trickNameTable[0x6C] = { /*Epona's Song*/
        Text{"Song of the Field",             "",        "",        "", },
        Text{"Epony's Song",                  "",        "",        "", },
        Text{"Epona Song",                    "",        "",        "", },
    };
    trickNameTable[0x54] = { /*Song of Healing*/
        Text{"Saria's Song",                  "",        "",        "", },
        Text{"Healing Lullaby",               "",        "",        "", },
        Text{"Song of Hearing",               "",        "",        "", },
    };
    trickNameTable[0x72] = { /*Song of Soaring*/
        Text{"Song of Fast travel",           "",        "",        "", },
        Text{"Prelude of Light",              "",        "",        "", },
        Text{"Song of Sorry",                 "",        "",        "", },
    };
    trickNameTable[0xAE] = { /*Woodfall Temple Map*/
        Text{"Forest Temple Map",             "",        "",        "", },
        Text{"Deku Temple Map",               "",        "",        "", },
        Text{"Goodfall Temple Map",           "",        "",        "", },
    };
    trickNameTable[0xAF] = { /*Snowhead Temple Map*/
        Text{"Ice Cavern Map",                "",        "",        "", },
        Text{"Snorehead Temple Map",          "",        "",        "", },
        Text{"Snowheap Temple Map",           "",        "",        "", },
    };
    trickNameTable[0xB0] = { /*Great Bay Temple Map*/
        Text{"Water Temple Map",              "",        "",        "", },
        Text{"Great Fish Temple Map",         "",        "",        "", },
        Text{"Great Ray Temple Map",          "",        "",        "", },
    };
    trickNameTable[0xB1] = { /*Stone Tower Temple Map*/
        Text{"Spirit Temple Map",             "",        "",        "", },
        Text{"Storm Shower Temple Map",       "",        "",        "", },
        Text{"Stoned Tower Temple Map",       "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_CLOCK_TOWN] = {
        Text{"Castle Town Map",               "",        "",        "", },
        Text{"Block Town Map",                "",        "",        "", },
        Text{"Clock Town Nap",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_WOODFALL] = {
        Text{"Faron Woods Map",               "",        "",        "", },
        Text{"WoodFool Map",                  "",        "",        "", },
        Text{"Woodfail Map",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_SNOWHEAD] = {
        Text{"Hebra Mountain Map",            "",        "",        "", },
        Text{"Snowpeak Map",                  "",        "",        "", },
        Text{"Showhead Map",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_GREAT_BAY] = {
        Text{"Great Sea Map",                 "",        "",        "", },
        Text{"Zora Bay Map",                  "",        "",        "", },
        Text{"Great Buy Map",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_STONE_TOWER] = {
        Text{"Clock Tower Map",               "",        "",        "", },
        Text{"Ikana Valley Map",              "",        "",        "", },
        Text{"Stone Power Map",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_ROMANI_RANCH] = {
        Text{"Lon Lon Ranch Map",             "",        "",        "", },
        Text{"Romani Ranch Radar",            "",        "",        "", },
        Text{"Romami Ranch Map",              "",        "",        "", },
    };
    trickNameTable[0xA7] = { /*Woodfall Temple Compass*/
        Text{"Forest Temple Compass",         "",        "",        "", },
        Text{"Waterfall Temple Compass",      "",        "",        "", },
        Text{"Woodfall Temple Compare",       "",        "",        "", },
    };
    trickNameTable[0xA8] = { /*Snowhead Temple Compass*/
        Text{"Ice Cavern Compass",            "",        "",        "", },
        Text{"Goron Temple Compass",          "",        "",        "", },
        Text{"Snomhead Temple Compass",       "",        "",        "", },
    };
    trickNameTable[0xAC] = { /*Great Bay Temple Compass*/
        Text{"Water Temple Compass",          "",        "",        "", },
        Text{"Pirate Temple Compass",         "",        "",        "", },
        Text{"Great Pay Temple Compass",      "",        "",        "", },
    };
    trickNameTable[0xAD] = { /*Stone Tower Temple Compass*/
        Text{"Spirit Temple Compass",         "",        "",        "", },
        Text{"Stone Tower Pimple Compass",    "",        "",        "", },
        Text{"Stone Towee Temple Compass",    "",        "",        "", },
    };
    trickNameTable[0xA3] = { /*Woodfall Temple Boss Key*/
        Text{"Forest Temple Boss Key",        "",        "",        "", },
        Text{"Swamp Temple Boss Key",         "",        "",        "", },
        Text{"Snowhead Temple Boss Keese",    "",        "",        "", },
    };
    trickNameTable[0xA4] = { /*Snowhead Temple Boss Key*/
        Text{"Ice Cavern Boss Key",           "",        "",        "", },
        Text{"Mountain Temple Boss Key",      "",        "",        "", },
        Text{"Snowhead Temple Toss Key",      "",        "",        "", },
    };
    trickNameTable[0xA5] = { /*Great Bay Temple Boss Key*/
        Text{"Water Temple Boss Key",         "",        "",        "", },
        Text{"Ocean Temple Boss Key",         "",        "",        "", },
        Text{"Grand Bay Temple Boss Key",     "",        "",        "", },
    };
    trickNameTable[0xA6] = { /*Stone Tower Temple Boss Key*/
        Text{"Spirit Temple Boss Key",        "",        "",        "", },
        Text{"Ikana Temple Boss Key",         "",        "",        "", },
        Text{"Stone Tower Temple Bass Key",   "",        "",        "", },
    };
    trickNameTable[0x76] = { /*Woodfall Temple Small Key*/
        Text{"Forest Temple Small Key",       "",        "",        "", },
        Text{"Woodfall Dungeon Small Key",    "",        "",        "", },
        Text{"Woodfell Temple Small Key",     "",        "",        "", },
    };
    trickNameTable[0x77] = { /*Snowhead Temple Small Key*/
        Text{"Ice Cavern Small Key",          "",        "",        "", },
        Text{"Snowhead Dungeon Small Key",    "",        "",        "", },
        Text{"Snowhead Temple Smell Key",     "",        "",        "", },
    };
    trickNameTable[0x90] = { /*Great Bay Temple Small Key*/
        Text{"Water Temple Small Key",        "",        "",        "", },
        Text{"Great Bay Dungeon Small Key",   "",        "",        "", },
        Text{"Grate Bay Temple Small Key",    "",        "",        "", },
    };
    trickNameTable[0xA2] = { /*Stone Tower Temple Small Key*/
        Text{"Spirit Temple Small Key",       "",        "",        "", },
        Text{"Stone Tower Dungeon Small Key", "",        "",        "", },
        Text{"Stone Tower Temper Small Key",  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_ODOLWAS_REMAINS] = {
        Text{"Odolwa Mask",                   "",        "",        "", },
        Text{"Odolwa Remainings",             "",        "",        "", },
        Text{"Owalda's Remains",              "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_GOHTS_REMAINS] = {
        Text{"Goht Mask",                     "",        "",        "", },
        Text{"Goat Remains",                  "",        "",        "", },
        Text{"Goth's Remains",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_GYORGS_REMAINS] = {
        Text{"Gyorg Mask",                    "",        "",        "", },
        Text{"George's Remains",              "",        "",        "", },
        Text{"Grog's Remains",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_TWINMOLDS_REMAINS] = {
        Text{"Twinmold Mask",                 "",        "",        "", },
        Text{"Twinbug's Remains",             "",        "",        "", },
        Text{"Twinmoid's Remains",            "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RECOVERY_HEART_SINGLE] = {
        Text{"Healing Heart",                 "",        "",        "", },
        Text{"Small Heart",                   "",        "",        "", },
        Text{"Heart",                         "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_GREEN] = {
        Text{"Green Rupoor",                  "",        "",        "", },
        Text{"Rupee",                         "",        "",        "", },
        Text{"Greg Rupee",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_BLUE] = {
        Text{"Blue Rupoor",                   "",        "",        "", },
        Text{"Blur Rupee",                    "",        "",        "", },
        Text{"Blue Rupy",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_RED] = {
        Text{"Red Rupoor",                    "",        "",        "", },
        Text{"Read Rupee",                    "",        "",        "", },
        Text{"Rupee (20)",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_PURPLE] = {
        Text{"Purple Rupoor",                 "",        "",        "", },
        Text{"Pink Rupee",                    "",        "",        "", },
        Text{"Purple Ruby",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_GOLD] = {
        Text{"Huge Rupoor",                   "",        "",        "", },
        Text{"Gold Rupee",                    "",        "",        "", },
        Text{"Hugh Rupee",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_SILVER] = {
        Text{"Silver Rupoor",                 "",        "",        "", },
        Text{"Shiny Rupee",                   "",        "",        "", },
        Text{"Sliver Rupee",                  "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_HEART_PIECE] = {
        Text{"Incomplete Health Upgrade",     "",        "",        "", },
        Text{"Hurt Piece",                    "",        "",        "", },
        Text{"Heart Peace",                   "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_HEART_CONTAINER] = {
        Text{"Extra Heart",                   "",        "",        "", },
        Text{"Hurt Container",                "",        "",        "", },
        Text{"Heart Contained",               "",        "",        "", },
    };
    trickNameTable[0x92] = { /*Milk*/
        Text{"Lactose Liquid",                "",        "",        "", },
        Text{"Mink",                          "",        "",        "", },
        Text{"Miik",                          "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_5] = {
        Text{"Cannonballs (5)",               "",        "",        "", },
        Text{"Orbs (5)",                      "",        "",        "", },
        Text{"Boom (5)",                      "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_10] = {
        Text{"Cannonballs (10)",              "",        "",        "", },
        Text{"Orbs (10)",                     "",        "",        "", },
        Text{"Boom (10)",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_20] = {
        Text{"Cannonballs (20)",              "",        "",        "", },
        Text{"Orbs (20)",                     "",        "",        "", },
        Text{"Boom (20)",                     "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHUS_5] = {
        Text{"Fake Bombchu (5)",              "",        "",        "", },
        Text{"Bombtschüss (5)",               "",        "",        "", },
        Text{"Bombshoes (5)",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHUS_10] = {
        Text{"Fake Bombchu (10)",             "",        "",        "", },
        Text{"Bombtschüss (10)",              "",        "",        "", },
        Text{"Bombshoes (10)",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHU_20] = {
        Text{"Fake Bombchu (20)",             "",        "",        "", },
        Text{"Bombtschüss (20)",              "",        "",        "", },
        Text{"Bombshoes (20)",                "",        "",        "", },
    };
    trickNameTable[0x1E] = { /*Arrows (10)*/
        Text{"Bolts (10)",                    "",        "",        "", },
        Text{"Errors (10)",                   "",        "",        "", },
        Text{"Arrows (0)",                    "",        "",        "", },
    };
    trickNameTable[0x1F] = { /*Arrows (30)*/
        Text{"Bolts (30)",                    "",        "",        "", },
        Text{"Errors (30)",                   "",        "",        "", },
        Text{"Arrows (Enough)",               "",        "",        "", },
    };
    trickNameTable[0x20] = { /*Arrows (40)*/
        Text{"Bolts (40)",                    "",        "",        "", },
        Text{"Errors (40)",                   "",        "",        "", },
        Text{"Arrows (Several)",              "",        "",        "", },
    };
    trickNameTable[0x21] = { /*Arrows (50)*/
        Text{"Bolts (50)",                    "",        "",        "", },
        Text{"Errors (50)",                   "",        "",        "", },
        Text{"Arrows (Plenty)",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_NUTS_5] = {
        Text{"Flashbangs (5)",                "",        "",        "", },
        Text{"Deku Seeds (5)",                "",        "",        "", },
        Text{"Deku Nest (5)",                 "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_NUTS_10] = {
        Text{"Flashbangs (10)",               "",        "",        "", },
        Text{"Deku Seeds (10)",               "",        "",        "", },
        Text{"Deku Nest (10)",                "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_ARROWS_MEDIUM] = { /*Arrows (10) again?*/
        Text{"Bolts (10)",                    "",        "",        "", },
        Text{"Errors (10)",                   "",        "",        "", },
        Text{"Arrows (0)",                    "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_ARROWS_LARGE] = { /*Arrows (30)*/
        Text{"Bolts (30)",                    "",        "",        "", },
        Text{"Errors (30)",                   "",        "",        "", },
        Text{"Arrows (Enough)",               "",        "",        "", },
    };
    trickNameTable[(u32)GetItemID::GI_FAIRY] = {
        Text{"Sprite",                        "",        "",        "", },
        Text{"Fairy Refill",                  "",        "",        "", },
        Text{"Fairie",                        "",        "",        "", },
    };
    trickNameTable[0x4A] = { /*Progressive Sword*/
        Text{"Progressive Knife",             "",        "",        "", },
        Text{"Progressive Blade",             "",        "",        "", },
        Text{"Progressive's Word",            "",        "",        "", },
    };
    trickNameTable[0x46] = { /*Progressive Bomb Bag*/
        Text{"Progressive Powder Pouch",      "",        "",        "", },
        Text{"Progressive Bombad",            "",        "",        "", },
        Text{"Progressive Bag of Bombs",      "",        "",        "", },
    };
    trickNameTable[0x47] = { /*Progressive Bow*/
        Text{"Progressive Slingshot",         "",        "",        "", },
        Text{"Progressive Crossbow",          "",        "",        "", },
        Text{"Pogessive Bow",                 "",        "",        "", },
    };
    trickNameTable[0x48] = { /*Progressive Wallet*/
        Text{"Progressive Piggybank",         "",        "",        "", },
        Text{"Progressive Coin Purse",        "",        "",        "", },
        Text{"Progressive Ballet",            "",        "",        "", },
    };
    trickNameTable[0x49] = { /*Progressive Magic*/
        Text{"Progressive Green Bar",         "",        "",        "", },
        Text{"Progressive Stamina",           "",        "",        "", },
        Text{"Progressive Maggie",            "",        "",        "", },
    };
    trickNameTable[0x45] = { /*Progressive Lullaby*/
        Text{"Progressive Sleepy Song",       "",        "",        "", },
        Text{"Progressive Lab Ally",          "",        "",        "", },
        Text{"Progressive Lullabye",          "",        "",        "", },
    };
}

// Generate a fake name for the ice trap based on the item it's displayed as
Text GetIceTrapName(u8 id) {
    // If the trick names table has not been initialized, do so
    if (!initTrickNames) {
        InitTrickNames();
        initTrickNames = true;
    }
    // Randomly get the easy, medium, or hard name for the given item id
    return RandomElement(trickNameTable[id]);
}

// Get shop index based on a given location
static std::map<std::string_view, int> ShopNameToNum = { { "Trading Post", 0 },         { "Bomb Shop", 1 },
                                                         { "Swamp Potion Shop", 2 }, { "Goron Village Shop", 3 },
                                                         { "Zora Hall Shop", 4 }, };
int GetShopIndex(LocationKey loc) {
    // Kind of hacky, but extract the shop and item position from the name
    const std::string& name(Location(loc)->GetName());
    int split = name.find(" Item ");
    std::string_view shop(name.c_str(), split);
    int pos     = std::stoi(name.substr(split + 6, 1)) - 1;
    int shopnum = ShopNameToNum[shop];
    return shopnum * 8 + pos;
}

// Without this transformed index, shop-related tables and arrays would need 64 entries- But only half of that is needed
// for shopsanity So we use this transformation to map only important indices to an array with 32 entries in the
// following manner: Shop index:  4  5  6  7 12 13 14 15 20 21 22 23... Transformed: 0  1  2  3  4  5  6  7  8  9
// 10 11... So we first divide the shop index by 4, then by 2 which basically tells us the index of the shop it's in,
// then multiply by 4 since there are 4 items per shop
// And finally we use a modulo by 4 to get the index within the "shop" of 4 items, and add
int TransformShopIndex(int index) {
    return 4 * ((index / 4) / 2) + index % 4;
}