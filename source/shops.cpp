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
    trickNameTable[(u32)GetItemID::GI_GREAT_FAIRY_SWORD] = { 
        Text{"Biggoron's Sword", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"Fairy Blade", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"Rainbow Sword", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_SHIELD_HERO] = {
        Text{"Hylian Shield", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"Shield of the Hero", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"Legendary Shield", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_STICKS_1] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_TOWN_TITLE_DEED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_SWAMP_TITLE_DEED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MOUNTAIN_TITLE_DEED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_OCEAN_TITLE_DEED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBERS_NOTEBOOK] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_ROOM_KEY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_LETTER_TO_KAFEI] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_PENDANT_OF_MEMORIES] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_LETTER_TO_MAMA] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MOONS_TEAR] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x2C] = { /*Spin Attack*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_LENS_OF_TRUTH] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_FIRE_ARROW] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_ICE_ARROW] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_LIGHT_ARROW] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_HOOKSHOT] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAGIC_BEAN] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xB2] = { /*Double Defense*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_OCARINA_OF_TIME] = {
        Text{"Fairy Ocarina", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_PICTOGRAPH_BOX] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_POWDER_KEG] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KEATON] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BUNNY_HOOD] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GORON] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ZORA] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_DEKU] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_POSTMANS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ALL_NIGHT] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BLAST] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_STONE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GREAT_FAIRYS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_BREMEN] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_DON_GEROS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_OF_SCENTS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_ROMANIS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_TROUPE_LEADERS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KAFEIS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_COUPLES] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_KAMARAOS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GIBDO] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GARO] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_CAPTAINS_HAT] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_GIANTS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_FIERCE_DEITY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MASK_OF_TRUTH] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBA] = { /*Fishing Pass*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x44] = { /*Swamp Skulltula Token*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x6D] = { /*Ocean Skulltula Token*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBB] = { /*Clock Town Stray Fairy*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBC] = { /*Woodfall Stray Fairy*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBD] = { /*Snowhead Stray Fairy*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBE] = { /*Great Bay Stray Fairy*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xBF] = { /*Stone Tower Stray Fairy*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_EMPTY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MILK] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_POTION_RED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_GOLD_DUST] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_CHATEAU_ROMANI] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MYSTERY_MILK] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_DEKU_PRINCESS_FAIRY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_POTION_GREEN] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_POTION_BLUE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_FAIRY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_BUG] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_FISH] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_POE_TEXT] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_BIG_POE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_SPRING_WATER] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_HOT_SPRING_WATER] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_ZORA_EGG] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_MAGIC_MUSHROOM] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOTTLE_SEAHORSE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x53] = { /*Song of Time*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x73] = { /*Song of Storms*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x4B] = { /*Sonata of Awakening*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x4E] = { /*New Wave Bossa Nova*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x4F] = { /*Elegy of Emptiness*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x51] = { /*Oath to Order*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x6C] = { /*Epona's Song*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xC2] = { /*Inverted Song of Time*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xC3] = { /*Song of Double Time*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x54] = { /*Song of Healing*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x72] = { /*Song of Soaring*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xAE] = { /*Woodfall Temple Map*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xAF] = { /*Snowhead Temple Map*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xB0] = { /*Great Bay Temple Map*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xB1] = { /*Stone Tower Temple Map*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_CLOCK_TOWN] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_WOODFALL] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_SNOWHEAD] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_GREAT_BAY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_STONE_TOWER] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_MAP_OF_ROMANI_RANCH] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA7] = { /*Woodfall Temple Compass*/
        Text{"Forest Temple Compass", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA8] = { /*Snowhead Temple Compass*/
        Text{"Ice Cavern Compass", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xAC] = { /*Great Bay Temple Compass*/
        Text{"Water Temple Compass", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xAD] = { /*Stone Tower Temple Compass*/
        Text{"Spirit Temple Compass", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA3] = { /*Woodfall Temple Boss Key*/
        Text{"Forest Temple Boss Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA4] = { /*Snowhead Temple Boss Key*/
        Text{"Ice Cavern Boss Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA5] = { /*Great Bay Temple Boss Key*/
        Text{"Water Temple Boss Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA6] = { /*Stone Tower Temple Boss Key*/
        Text{"Spirit Temple Boss Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x76] = { /*Woodfall Temple Small Key*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x77] = { /*Snowhead Temple Small Key*/
        Text{"Ice Cavern Small Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x90] = { /*Great Bay Temple Small Key*/
        Text{"Water Temple Small Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0xA2] = { /*Stone Tower Temple Small Key*/
        Text{"Spirit Temple Small Key", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_ODOLWAS_REMAINS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_GOHTS_REMAINS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_GYORGS_REMAINS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_TWINMOLDS_REMAINS] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RECOVERY_HEART_SINGLE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_GREEN] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_BLUE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_RED] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_PURPLE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_GOLD] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_RUPEE_SILVER] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_HEART_PIECE] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_HEART_CONTAINER] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x92] = { /*Milk*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_5] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_10] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBS_20] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHUS_5] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHUS_10] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_BOMBCHU_20] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x1E] = { /*Arrows (10)*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x1F] = { /*Arrows (30)*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x20] = { /*Arrows (40)*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x21] = { /*Arrows (50)*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_NUTS_5] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_NUTS_10] = { 
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_ARROWS_MEDIUM] = { /*Arrows (10) again?*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_ARROWS_LARGE] = { /*Arrows (30)*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[(u32)GetItemID::GI_FAIRY] = {
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x4A] = { /*Progressive Sword*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x46] = { /*Progressive Bomb Bag*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x47] = { /*Progressive Bow*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x48] = { /*Progressive Wallet*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x49] = { /*Progressive Magic*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
    };
    trickNameTable[0x45] = { /*Progressive Lullaby*/
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench", "NASpanish", "EUGerman", /*"Italian", "Japanese"*/ "EUEng", "EUFrench", "EUSpanish"},
        Text{"", "NAFrench","NASpanish","EUGerman", /*"Italian","Japanese",*/"EUEng","EUFrench","EUSpanish"}
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