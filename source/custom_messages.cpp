#include "custom_messages.hpp"
#include "debug.hpp"

#include <set>

namespace CustomMessages {

class UnformattedMessageComp {
  public:
    bool operator()(const UnformattedMessage& lhs, const UnformattedMessage& rhs) const {
        return lhs.id < rhs.id;
    }
};

std::set<UnformattedMessage, UnformattedMessageComp> messageEntries;
std::vector<UnformattedMessage> arrangedMessageEntries;
std::vector<char> textData;
std::vector<char> colData;
std::vector<char> iconData;
std::vector<char> delayData;
u8 colParity, iconParity, delayParity;

u32 pushText(const char* data) {
    u32 offset = textData.size();
    for (u32 idx = 0; data[idx]; idx++)
        textData.push_back(data[idx]);
    textData.push_back(0);
    return offset;
}

void CreateMessage(u16 textId, u16 field_2, u32 field_4, u32 flags, const Language& text,
                   const std::vector<colType>& cols, const std::vector<iconType>& icons, const std::vector<u8>& delays,
                   u16 sfx, bool instant, bool repeatSfx) {
#ifdef ENABLE_DEBUG
    static std::vector<u16> usedTextIds;
    if (messageEntries.empty()) {
        usedTextIds.clear();
    }
    if (std::find(usedTextIds.begin(), usedTextIds.end(), textId) != usedTextIds.end()) {
        //CitraPrint("Multiple custom messages use text id " + std::to_string(textId));
        //printf("\x1b[31m\x1b[9;10H!!Text ID error!!         \x1b[37m");
    } else {
        usedTextIds.push_back(textId);
    }
#endif
    UnformattedMessage newEntry;

    newEntry.id = textId;
    newEntry.field_2 = field_2;
    newEntry.field_4 = field_4;
    newEntry.flags = flags;
    newEntry.sfxAndFlags = ((instant) ? 0x8000 : 0x0000) | ((repeatSfx) ? 0x4000 : 0x0000) | sfx;

    u32 offsetEn = 0, offsetFr = 0, offsetEs = 0, offsetDe = 0, offsetIt = 0, offsetNl = 0;
    u32 offsetCol = 0, offsetIcon = 0, offsetDelay = 0;

    if (text.English) offsetEn = pushText(text.English);
    if (text.French)  offsetFr = pushText(text.French);
    if (text.Spanish) offsetEs = pushText(text.Spanish);
    if (text.German)  offsetDe = pushText(text.German);
    if (text.Italian) offsetIt = pushText(text.Italian);
    if (text.Dutch)   offsetNl = pushText(text.Dutch);

    if (cols.size()) {
        offsetCol = colData.size() * 2 - colParity;
        char temp = (colParity) ? colData.back() : 0;
        if (colParity) colData.pop_back();
        for (auto& col: cols) {
            if (colParity)
                colData.push_back(temp | col);
            else
                temp = col << 4;
            colParity = 1 - colParity;
        }
        colData.push_back((colParity) ? (temp | 0x0F) : 0xF0);
        colParity = 1 - colParity;
    }

    if (icons.size()) {
        offsetIcon = (iconData.size() << 2) / 3 - ((iconParity == 3) ? 1 : 0);
        char temp = (iconParity) ? iconData.back() : 0;
        if (iconParity) iconData.pop_back();
        for (auto& icon: icons) {
            switch (iconParity) {
            case 0:
                temp = icon << 2;
                break;
            case 1:
                iconData.push_back(temp | (icon >> 4));
                temp = icon << 4;
                break;
            case 2:
                iconData.push_back(temp | (icon >> 2));
                temp = icon << 6;
                break;
            case 3:
                iconData.push_back(temp | icon);
                break;
            }
            iconParity = (iconParity + 1) % 4;
        }
        switch (iconParity) {
        case 0:
          iconData.push_back(0xFC);
          break;
        case 1:
          iconData.push_back(temp | 0x03);
          iconData.push_back(0xF0);
          break;
        case 2:
          iconData.push_back(temp | 0x0F);
          iconData.push_back(0xC0);
          break;
        case 3:
          iconData.push_back(temp | 0x3F);
          break;
        }
        iconParity = (iconParity + 1) % 4;
    }

    if (delays.size()) {
        offsetDelay = (delayData.size() << 2) / 3 - ((delayParity == 3) ? 1 : 0);
        char temp = (delayParity) ? delayData.back() : 0;
        if (delayParity) delayData.pop_back();
        for (auto& delay: delays) {
            switch (delayParity) {
            case 0:
                temp = delay << 2;
                break;
            case 1:
                delayData.push_back(temp | (delay >> 4));
                temp = delay << 4;
                break;
            case 2:
                delayData.push_back(temp | (delay >> 2));
                temp = delay << 6;
                break;
            case 3:
                delayData.push_back(temp | delay);
                break;
            }
            delayParity = (delayParity + 1) % 4;
        }
        switch (delayParity) {
        case 0:
          delayData.push_back(0xFC);
          break;
        case 1:
          delayData.push_back(temp | 0x03);
          delayData.push_back(0xF0);
          break;
        case 2:
          delayData.push_back(temp | 0x0F);
          delayData.push_back(0xC0);
          break;
        case 3:
          delayData.push_back(temp | 0x3F);
          break;
        }
        delayParity = (delayParity + 1) % 4;
    }

    newEntry.offsets[0] = offsetEn | (offsetFr << 18);
    newEntry.offsets[1] = (offsetFr >> 14) | (offsetEs << 4) | (offsetDe << 22);
    newEntry.offsets[2] = (offsetDe >> 10) | (offsetIt << 8) | (offsetNl << 26);
    newEntry.offsets[3] = (offsetNl >> 6) | (offsetCol << 12) | (offsetIcon << 22);
    newEntry.delayOffset= (u16)offsetDelay;

    messageEntries.insert(newEntry);
    // Duplicate moon trial hints to their alternate version
    if (textId > 0x2102 && textId < 0x2117) {
        newEntry.id -= 0x2F;
        messageEntries.insert(newEntry);
    }
}

void CreateBaselineCustomMessages() {
    messageEntries.clear();
    textData.clear();
    colData.clear();
    iconData.clear();
    delayData.clear();

    pushText("ERROR&&No message data");
    colData.push_back(0xF);
    iconData.push_back(0x3F);
    delayData.push_back(0x3F);
    colParity = iconParity = delayParity = 1;

    // Small Keys
    // Woodfall
    CreateMessage(0x6133, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got a #small key# for the #Woodfall Temple#! Use it to open a locked door in that temple."},
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);
    // Snowhead
    CreateMessage(0x6134, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got a #small key# for the #Snowhead Temple#! Use it to open a locked door in that temple."},
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);
    // Great Bay
    CreateMessage(0x6135, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got a #small key# for the #Great Bay Temple#! Use it to open a locked door in that temple."},
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);
    // Stone Tower
    CreateMessage(0x6136, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got a #small key# for the #Stone Tower Temple#! Use it to open a locked door in that temple."},
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Maps
    // Woodfall
    CreateMessage(0x6137, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    {"You found the #dungeon map# for the #Woodfall#!"},
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x6138, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    {"You found the #dungeon map# for the #Snowhead#!"},
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x6139, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    {"You found the #dungeon map# for the #Great Bay#!"},
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x613A, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    {"You found the #dungeon map# for the #Stone Tower#!"},
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Compasses
    // Woodfall
    CreateMessage(0x613B, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #compass# for the #Woodfall Temple#! Now many of the dungeon's hidden things will appear on the map!"},
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x613C, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #compass# for the #Snowhead Temple#! Now many of the dungeon's hidden things will appear on the map!"},
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x613D, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #compass# for the #Great Bay Temple#! Now many of the dungeon's hidden things will appear on the map!"},
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x613E, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #compass# for the #Stone Tower Temple#! Now many of the dungeon's hidden things will appear on the map!"},
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Boss Keys
    // Woodfall
    CreateMessage(0x613F, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #boss key# for the #Woodfall Temple#! Now you can enter the chamber where the boss lurks!"},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x6140, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #boss key# for the #Snowhead Temple#! Now you can enter the chamber where the boss lurks!"},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x6141, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #boss key# for the #Great Bay Temple#! Now you can enter the chamber where the boss lurks!"},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x6142, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #boss key# for the #Stone Tower Temple#! Now you can enter the chamber where the boss lurks!"},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Kokiri Sword
    CreateMessage(0x0037, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"You got the #Kokiri Sword!# The trusty sword you're familiar with. A treasure from Kokiri Forest."},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Ice Trap
    CreateMessage(0x0012, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"          #FOOL!#"},
    {QM_RED}, {}, {}, 0x0, false, false);

    //Swamp Skulltula Tokens
    CreateMessage(0x0052, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    {"You got a #Swamp Skulltula Token#! &You have collected #=SSH#."},
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    //Ocean Skulltula Tokens
    CreateMessage(0x6143, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    {"You got an #Ocean Skulltula Token#! &You have collected #=OSH#."},
    {QM_BLUE, QM_RED}, {}, {}, 0x0, false, false);

}

u32 NumMessages() {
    return messageEntries.size();
}

std::pair<const char*, u32> RawMessageData() {
    arrangedMessageEntries.assign(messageEntries.begin(), messageEntries.end());
    const char* data = (const char*)arrangedMessageEntries.data();
    u32 size         = arrangedMessageEntries.size() * sizeof(UnformattedMessage);
    return { data, size };
}

std::pair<const char*, u32> RawMessageTextData() {
    const char* data = (const char*)textData.data();
    u32 size         = textData.size();
    return { data, size };
}

std::pair<const char*, u32> RawMessageColData() {
    const char* data = (const char*)colData.data();
    u32 size         = colData.size();
    return { data, size };
}

std::pair<const char*, u32> RawMessageIconData() {
    const char* data = (const char*)iconData.data();
    u32 size         = iconData.size();
    return { data, size };
}

std::pair<const char*, u32> RawMessageDelayData() {
    const char* data = (const char*)delayData.data();
    u32 size         = delayData.size();
    return { data, size };
}

}
