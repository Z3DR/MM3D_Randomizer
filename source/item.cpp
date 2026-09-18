#include "item.hpp"

#include <array>
#include <string>
#include "logic.hpp"
#include "random.hpp"
#include "item_pool.hpp"
#include "settings.hpp"
#include "rnd/item_override.h"
#include "region.hpp"
#include "item_category.hpp"
#include "text.hpp"

using namespace rnd;

Item::Item(bool advancement_, bool reusable_, bool* logicVar_, Text name_, HintKey hintKey_, u32 getItemId_, ItemType type_, u16 price_)
    : 
    advancement(advancement_),
    reusable(reusable_),
    logicVar(logicVar_),
    name(std::move(name_)),
    hintKey(hintKey_),
    getItemId(getItemId_),
    type(type_), 
    price(price_) {}

Item::Item(bool advancement_, bool reusable_, u8* logicVar_, Text name_, HintKey hintKey_, u32 getItemId_, ItemType type_, u16 price_)
    :
    advancement(advancement_),
    reusable(reusable_),
    logicVar(logicVar_),
    name(std::move(name_)),
    hintKey(hintKey_),
    getItemId(getItemId_),
    type(type_),
    price(price_) {}

Item::~Item() = default;

void Item::ApplyEffect() {
    if (std::holds_alternative<bool*>(logicVar)) {
        *std::get<bool*>(logicVar) = true;
    } else {
        *std::get<u8*>(logicVar) += 1;
    }
    Logic::UpdateHelpers();
}

void Item::UndoEffect() {
    if (std::holds_alternative<bool*>(logicVar)) {
        *std::get<bool*>(logicVar) = false;
    } else {
        *std::get<u8*>(logicVar) -= 1;
    }
    Logic::UpdateHelpers();
}


ItemOverride_Value Item::Value() const {
    ItemOverride_Value val;
    val.all = 0;
    val.getItemId = getItemId;
    
    if (getItemId == 0x12) {
        val.looksLikeItemId = RandomElement(IceTrapModels);
    }
    //if (!Settings::ColoredBossKeys && (getItemId >= 0x95 && getItemId <= 0x9A)) { //Boss keys
    //    val.looksLikeItemId = (u32)GetItemID::GI_KEY_BOSS;
    //}
    //if (!Settings::ColoredKeys && (getItemId == 0x76 || getItemId == 0x77 || getItemId == 0x90 || getItemId == 0xA2)) { //Small keys
    //    val.looksLikeItemId = (u32)GetItemID::GI_KEY_SMALL;
    //}
    if (type == ITEMTYPE_SHOP) {
        // With the current shopsanity implementation, we need a way to detect
        // regular shop items. This method should have no unintended side effects
        // unless there was a multiworld with 256 players... so, it should be fine.
        val.player = 0xFF;
    }
    return val; 
    
}

