#pragma once

#include <array>

#include "rnd/music.h"

namespace Music {
  inline constexpr u8 kNoLink = 0xFF;

  struct StreamSlot {
    const char* file;         // vanilla name in romfs/sound/streaming/stream/; nullptr = not replaceable
    const char* displayName;  // folder name under /MM3DR/Custom Music/<category>/
    rnd::SeqType category;    // SEQ_NOSHUFFLE = never assigned directly
    bool loops;               // replacement's CSTM loop flag must equal this
    u8 linkedTo;              // kNoLink, or the slot whose song this file must mirror
    // Replacement's channel count must equal this. It is fixed per stream by JokerStreaming.bcsar
    // (allocChannelCount): a file with more channels than the archive reserves causes audio bugs and
    // crashes. Only Swamp Cruise, Milk Bar, Shop and Shooting Gallery are mono.
    u8 channels = 2;
  };

  extern const std::array<StreamSlot, BGM_COUNT> streamSlots;
  const char* CategoryFolder(rnd::SeqType category);  // "Area Themes", ... ; nullptr for NOSHUFFLE
}  // namespace Music
