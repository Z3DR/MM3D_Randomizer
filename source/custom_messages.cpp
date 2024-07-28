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

// Pack data less than 8 bits long into a char array without wasting bits
void packData(u8 size, u8 idx, char* data, u8 unpacked) {
  for (u8 i = size; i--;) {
    if (unpacked & 1)
      data[(idx * size + i) / 8] |= 0x80 >> ((idx * size + i) % 8);
    else
      data[(idx * size + i) / 8] &= ~(0x80 >> ((idx * size + i) % 8));
    unpacked >>= 1;
  }
}

std::set<UnformattedMessage, UnformattedMessageComp> messageEntries;
std::vector<UnformattedMessage> arrangedMessageEntries;

void CreateMessage(u16 textId, u16 field_2, u32 field_4, u32 flags, const char* NAEnglishText,
                   const std::vector<colType>& cols, const std::vector<iconType>& icons, const std::vector<u16>& delays,
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
    std::strcpy(newEntry.text, NAEnglishText);
    for (u16 idx = 0; idx < std::min(8, (int)cols.size()); idx++)
        packData(4, idx, newEntry.cols, cols.at(idx));
    for (u16 idx = 0; idx < std::min(8, (int)icons.size()); idx++)
        packData(6, idx, newEntry.icons, icons.at(idx));
    for (u16 idx = 0; idx < std::min(8, (int)delays.size()); idx++)
        packData(6, idx, newEntry.delays, delays.at(idx));
    newEntry.sfxAndFlags = ((instant) ? 0x8000 : 0x0000) | ((repeatSfx) ? 0x4000 : 0x0000) | sfx;

    messageEntries.insert(newEntry);
}

void CreateBaselineCustomMessages() {
    // Small Keys
    // Woodfall
    CreateMessage(0x6133, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got a #small key# for the #Woodfall Temple#! Use it to open a locked door in that temple.",
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);
    // Snowhead
    CreateMessage(0x6134, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got a #small key# for the #Snowhead Temple#! Use it to open a locked door in that temple.",
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);
    // Great Bay
    CreateMessage(0x6135, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got a #small key# for the #Great Bay Temple#! Use it to open a locked door in that temple.",
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);
    // Stone Tower
    CreateMessage(0x6136, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got a #small key# for the #Stone Tower Temple#! Use it to open a locked door in that temple.",
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Maps
    // Woodfall
    CreateMessage(0x6137, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    "You found the #dungeon map# for the #Woodfall#!",
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x6138, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    "You found the #dungeon map# for the #Snowhead#!",
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x6139, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    "You found the #dungeon map# for the #Great Bay#!",
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x613A, 0x003E, 0x3FFFFFFF, 0xFF0000, 
    "You found the #dungeon map# for the #Stone Tower#!",
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Compasses
    // Woodfall
    CreateMessage(0x613B, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #compass# for the #Woodfall Temple#! Now many of the dungeon's hidden things will appear on the map!",
    {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x613C, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #compass# for the #Snowhead Temple#! Now many of the dungeon's hidden things will appear on the map!",
    {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x613D, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #compass# for the #Great Bay Temple#! Now many of the dungeon's hidden things will appear on the map!",
    {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x613E, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #compass# for the #Stone Tower Temple#! Now many of the dungeon's hidden things will appear on the map!",
    {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Boss Keys
    // Woodfall
    CreateMessage(0x613F, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #boss key# for the #Woodfall Temple#! Now you can enter the chamber where the boss lurks!",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessage(0x6140, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #boss key# for the #Snowhead Temple#! Now you can enter the chamber where the boss lurks!",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessage(0x6141, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #boss key# for the #Great Bay Temple#! Now you can enter the chamber where the boss lurks!",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessage(0x6142, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #boss key# for the #Stone Tower Temple#! Now you can enter the chamber where the boss lurks!",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Kokiri Sword
    CreateMessage(0x0037, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "You got the #Kokiri Sword!# The trusty sword you're familiar with. A treasure from Kokiri Forest.",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Ice Trap
    CreateMessage(0x0012, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    "          #FOOL!#",
    {QM_RED}, {}, {}, 0x0, false, false);

    //Swamp Skulltula Tokens
    CreateMessage(0x0052, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    "You got a #Swamp Skulltula Token#! You have collected #=SSH#.",
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    //Ocean Skulltula Tokens
    CreateMessage(0x6143, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    "You got a #Ocean Skulltula Token#! You have collected #=OSH#.",
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

}
