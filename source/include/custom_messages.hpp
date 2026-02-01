#pragma once

#include "rnd/custom_messages.h"

#include <vector>

namespace CustomMessages {

typedef struct {
    const char* English;
    const char* French;
    const char* Spanish;
    const char* German;
    const char* Italian;
    const char* Dutch;
} Language;
void CreateMessage(u16 textId, u16 field_2, u32 field_4, u32 flags, const Language& text,
                   const std::vector<colType>& cols, const std::vector<iconType>& icons, const std::vector<u8>& delays,
                   u16 sfx, bool instant, bool repeatSfx);

u32 NumMessages();

void CreateBaselineCustomMessages();

std::pair<const char*, u32> RawMessageData();
std::pair<const char*, u32> RawMessageTextData();
std::pair<const char*, u32> RawMessageColData();
std::pair<const char*, u32> RawMessageIconData();
std::pair<const char*, u32> RawMessageDelayData();

}
