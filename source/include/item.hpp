#pragma once

#include <3ds.h>
#include <string>
#include <variant>

#include "keys.hpp"
#include "hint_list.hpp"
#include "settings.hpp"
#include "region.hpp"
#include "item_category.hpp"
#include "rnd/item_override.h"

using namespace std;
using namespace rnd;

//union ItemOverride_Value;

enum ItemType {
    ITEMTYPE_ITEM,
    ITEMTYPE_MAP,
    ITEMTYPE_COMPASS,
    ITEMTYPE_BOSSKEY,
    ITEMTYPE_SMALLKEY,
    ITEMTYPE_TOKEN,
    ITEMTYPE_MASK,
    ITEMTYPE_EVENT,
    ITEMTYPE_DROP,
    ITEMTYPE_REFILL,
    ITEMTYPE_SONG,
    ITEMTYPE_SHOP,
    ITEMTYPE_DUNGEONREWARD,
    ITEMTYPE_STRAYFAIRY,
    ITEMTYPE_QUEST,
    ITEMTYPE_TRADE,
    ITEMTYPE_GFAIRY,
};

class Item {
public:
    Item() = default;
    Item(bool advancement_, bool* logicVar_, Text name_, HintKey hintKey_, u32 getItemId_, ItemType type_, u16 price_ = 0);
    Item(bool advancement_, u8* logicVar_,   Text name_, HintKey hintKey_, u32 getItemId_, ItemType type_, u16 price_ = 0);
    ~Item();

    void ApplyEffect();
    void UndoEffect();

    union ItemOverride_Value Value() const;

    bool IsAdvancement() const {
        return advancement;
    }

    const Text& GetName() const {
        return name;
    }

    ItemType GetItemType() const {
        return type;
    }
   
    const HintKey GetHintKey() const {
        return hintKey;
    }
    const HintText& GetHint() const {
        return Hint(hintKey);
    }
    u32 GetItemId() const {
        return (u32)getItemId;
    }
    
    u16 GetPrice() const {
        return price;
    }

    void SetPrice(u16 price_) {
        price = price_;
    }
    void SetAsPlaythrough() {
        playthrough = true;
    }

    bool IsPlaythrough() const {
        return playthrough;
    }
    bool IsMajorItem() const {
        return IsAdvancement();
    }
    bool IsBottleItem() const {
        return getItemId == 0x5A || //Empty Bottle
            getItemId == 0x60 || //Bottle with Milk
            getItemId == 0x5B || //Red Potion
            getItemId == 0x69 || //Gold Dust
            getItemId == 0x6F|| //Chateau Romani
            getItemId == 0x5F || //Deku Princess
            getItemId == 0x5E || //Fairy
            getItemId == 0x63 || //Bugs
            getItemId == 0x65 || //Poe
            getItemId == 0x66 || //Big Poe
            getItemId == 0x67 || //Spring Water
            getItemId == 0x68 || //Hot Spring Water
            getItemId == 0x69 || //Zora Egg
            getItemId == 0x6B;   //Mushroom

    } 

  //  Item(bool advancement_, int startAdd_, bool* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey_, int getItemId_, ItemCategory itemCat_, LocationCategory locCat_);
  //  Item(bool advancement_, int startAdd_, u8* logicVar_, Text name_, string locationName_, Region region_, HintKey hintKey, int getItemId_, ItemCategory itemCat_, LocationCategory locCat_);

private:
    bool advancement;
    std::variant<bool*, u8*> logicVar;
    Text name;
    HintKey hintKey;
    u32 getItemId;
    ItemType type;
    bool playthrough = false;
    int price;
};
