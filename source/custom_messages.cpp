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

    u32 offsetNaEn = 0, offsetNaFr = 0, offsetNaEs = 0, offsetEuEn = 0, offsetEuFr = 0, offsetEuEs = 0, offsetEuDe = 0, offsetEuIt = 0, offsetJpJp = 0;
    u32 offsetCol = 0, offsetIcon = 0, offsetDelay = 0;

    //If text exists and doesn't seem redundant, write it to patch and store its offset
    if (text.NaEnglish) offsetNaEn = offsetEuEn = pushText(text.NaEnglish);
    if (text.NaFrench  && (text.NaFrench  != text.NaEnglish)) offsetNaFr = offsetEuFr = pushText(text.NaFrench);
    if (text.NaSpanish && (text.NaSpanish != text.NaEnglish)) offsetNaEs = offsetEuEs = pushText(text.NaSpanish);
    if (text.EuGerman  && (text.EuGerman  != text.EuEnglish)) offsetEuDe = pushText(text.EuGerman);
    if (text.EuItalian && (text.EuItalian != text.EuEnglish)) offsetEuIt = pushText(text.EuItalian);
    //if (text.Japanese  && (text.Japanese  != text.NaEnglish)) offsetJpJp = pushText(text.Japanese);
    if (text.EuEnglish && (text.EuEnglish != text.NaEnglish)) offsetEuEn = pushText(text.EuEnglish);
    if (text.EuFrench  && (text.EuFrench  != text.NaFrench )) offsetEuFr = pushText(text.EuFrench);
    if (text.EuSpanish && (text.EuSpanish != text.NaSpanish)) offsetEuEs = pushText(text.EuSpanish);

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

    newEntry.offsets[0] =  offsetNaEn        | (offsetNaFr << 18);
    newEntry.offsets[1] = (offsetNaFr >> 14) | (offsetNaEs <<  4) | (offsetEuEn << 22);
    newEntry.offsets[2] = (offsetEuEn >> 10) | (offsetEuFr <<  8) | (offsetEuEs << 26);
    newEntry.offsets[3] = (offsetEuEs >>  6) | (offsetEuDe << 12) | (offsetEuIt << 30);
    newEntry.offsets[4] = (offsetEuIt >>  2) | (offsetJpJp << 16);
    newEntry.offsets[5] = (offsetJpJp >> 16) | (offsetCol  <<  2) | (offsetIcon << 12) | (offsetDelay << 22);

    messageEntries.insert(newEntry);
    // Duplicate moon trial hints to their alternate version
    if (textId > 0x2102 && textId < 0x2117) {
        newEntry.id -= 0x2F;
        messageEntries.insert(newEntry);
    }
}

void CreateMessageFromTextObject(u16 textId, u16 field_2, u32 field_4, u32 flags, const Text& text,
                   const std::vector<colType>& cols, const std::vector<iconType>& icons, const std::vector<u8>& delays,
                   u16 sfx, bool instant, bool repeatSfx) {
    CreateMessage(textId, field_2, field_4, flags,
                //      NaEnglish                     NaFrench                      NaSpanish
                  {text.GetNAEnglish().c_str(), text.GetNAFrench().c_str(), text.GetNASpanish().c_str(),
                // Remember to update these alongside Text class when adding languages
                //      EuGerman                      EuItalian                     Japanese
                text.GetEUREnglish().c_str(), text.GetEUREnglish().c_str(), // text.GetNAEnglish().c_str(),
                //      EuEnglish                     EuFrench                      EuSpanish
                text.GetEUREnglish().c_str(), text.GetEURFrench().c_str(), text.GetEURSpanish().c_str()
                }, cols, icons, delays, sfx, instant, repeatSfx);
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

    Text GITextIntroSKey =    {"You got a #small key# ",       "Vous obtenez une #petite clé# ",     "¡Has obtenido una #llave pequeña# "};
    Text GITextIntroMap =     {"You found the #dungeon map# ", "Vous obtenez la #carte du donjon# ", "¡Has encontrado el #mapa de la mazmorra# "};
    Text GITextIntroCompass = {"You got the #compass# ",       "Vous obtenez la #boussole# ",        "¡Has encontrado la #brújula# "};
    Text GITextIntroBKey =    {"You got the #boss key# ",      "Vous obtenez la #grande clé# ",      "¡Has obtenido la #gran llave# "};

    Text GITextDungeonWoodfall =   {"for #Woodfall Temple#!",    "du #temple de Boisé-les-Cascades#!",       "del templo del Bosque Catarata!",
                                    "",                          "du #temple de Bois-Cascade# !",            ""};
    Text GITextDungeonSnowhead =   {"for #Snowhead Temple#!",    "du #temple du Pic des neiges#!",           "del templo del Pico Nevado!",
                                    "",                          "du #temple du pic des Neiges# !",          ""};
    Text GITextDungeonGreatBay =   {"for #Great Bay Temple#!",   "du #temple de la Grande Baie#!",           "del templo de la Gran Bahía!",
                                    "",                          "du #temple de la Grande Baie# !",          ""};
    Text GITextDungeonStoneTower = {"for #Stone Tower Temple#!", "du #temple de la forteresse de pierre#!",  "del templo de la Torre de Piedra!",
                                    "",                          "du #temple de la forteresse de pierre# !", ""};

    Text GITextOutroSKey =    {
        " Use it to open a locked door in that temple.", " Utilisez-la pour ouvrir une porte de ce donjon.", ""
    };
    Text GITextOutroCompass = {
        " Now many of the dungeon's hidden things will appear on the map!", " Certains des secrets de ce donjon seront maintenant visibles sur la carte!",  "",
        "",                                                                 " Certains des secrets de ce donjon seront maintenant visibles sur la carte !", ""
    };
    Text GITextOutroBKey =    {
        " Now you can enter the chamber where the boss lurks!", " Vous pouvez maintenant pénétrer dans l'antre du boss!",  "",
        "",                                                     " Vous pouvez maintenant pénétrer dans l'antre du boss !", ""
    };

    // Small Keys
    // Woodfall
    CreateMessageFromTextObject(0x6133, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroSKey + GITextDungeonWoodfall + GITextOutroSKey,
        {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);
    // Snowhead
    CreateMessageFromTextObject(0x6134, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroSKey + GITextDungeonSnowhead + GITextOutroSKey,
        {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);
    // Great Bay
    CreateMessageFromTextObject(0x6135, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroSKey + GITextDungeonGreatBay + GITextOutroSKey,
        {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);
    // Stone Tower
    CreateMessageFromTextObject(0x6136, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroSKey + GITextDungeonStoneTower + GITextOutroSKey,
        {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Maps
    // Woodfall
    CreateMessageFromTextObject(0x6137, 0x003E, 0x3FFFFFFF, 0xFF0000,
        GITextIntroMap + GITextDungeonWoodfall,
        {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessageFromTextObject(0x6138, 0x003E, 0x3FFFFFFF, 0xFF0000,
        GITextIntroMap + GITextDungeonSnowhead,
        {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessageFromTextObject(0x6139, 0x003E, 0x3FFFFFFF, 0xFF0000,
        GITextIntroMap + GITextDungeonGreatBay,
        {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessageFromTextObject(0x613A, 0x003E, 0x3FFFFFFF, 0xFF0000,
        GITextIntroMap + GITextDungeonStoneTower,
        {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Compasses
    // Woodfall
    CreateMessageFromTextObject(0x613B, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroCompass + GITextDungeonWoodfall + GITextOutroCompass,
        {QM_GREEN, QM_GREEN}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessageFromTextObject(0x613C, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroCompass + GITextDungeonSnowhead + GITextOutroCompass,
        {QM_GREEN, QM_MAGENTA}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessageFromTextObject(0x613D, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroCompass + GITextDungeonGreatBay + GITextOutroCompass,
        {QM_GREEN, QM_CYAN}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessageFromTextObject(0x613E, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroCompass + GITextDungeonStoneTower + GITextOutroCompass,
        {QM_GREEN, QM_YELLOW}, {}, {}, 0x0, false, false);

    // Boss Keys
    // Woodfall
    CreateMessageFromTextObject(0x613F, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroBKey + GITextDungeonWoodfall + GITextOutroBKey,
        {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Snowhead
    CreateMessageFromTextObject(0x6140, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroBKey + GITextDungeonSnowhead + GITextOutroBKey,
        {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Great Bay
    CreateMessageFromTextObject(0x6141, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroBKey + GITextDungeonGreatBay + GITextOutroBKey,
        {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Stone Tower
    CreateMessageFromTextObject(0x6142, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        GITextIntroBKey + GITextDungeonStoneTower + GITextOutroBKey,
        {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Kokiri Sword
    CreateMessage(0x0037, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    {"You got the #Kokiri Sword!# The trusty sword you're familiar with. A treasure from Kokiri Forest.",
        // French
        "Vous obtenez l'#épée Kokiri#! Votre fidèle épée qui provient de le forêt Kokiri.",
    },
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    // Ice Trap
    CreateMessage(0x0012, 0xFFFF, 0x3FFFFFFF, 0xFF0000, 
    {"          #FOOL!#",
        // French
        "#IDIOT!#",
    },
    {QM_RED}, {}, {}, 0x0, false, false);

    //Swamp Skulltula Tokens
    CreateMessage(0x0052, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    {"You got a #Swamp Skulltula Token#! &You have collected #=SSH#.",
        // French
        "Vous obtenez l'#âme d'une skulltula d'or des marais#!&Vous en avez désormais #=SSH#.",
    },
    {QM_GREEN, QM_RED}, {}, {}, 0x0, false, false);

    //Ocean Skulltula Tokens
    CreateMessage(0x6143, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
    {"You got an #Ocean Skulltula Token#! &You have collected #=OSH#.",
        // French
        "Vous obtenez l'#âme d'une skulltula d'or de la côte#!&Vous en avez désormais #=OSH#.",
    },
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
