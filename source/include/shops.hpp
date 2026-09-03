#pragma once
#include "item.hpp"
#include "item_location.hpp"

#include <vector>
#include <array>
#include <string>

struct ItemAndPrice {
    Text Name;
    int price;
    bool Repurchaseable;
};

extern void PlaceVanillaShopItems();
extern int GetShopPrice();
extern s16 GetRandomScrubPrice();
extern Text GetIceTrapName(u8 id);
extern int GetShopIndex(LocationKey loc);
extern int TransformShopIndex(int index);

extern std::vector<ItemAndPrice> NonShopItems;