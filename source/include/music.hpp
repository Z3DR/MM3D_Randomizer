#pragma once

#include <array>

#include "rnd/music.h"

namespace Music {
  using rnd::SeqType;

  extern const std::array<SeqType, BGM_COUNT> seqTypesMusic;

  extern const std::array<u32, BGM_COUNT> seqFlagsMusic;

  // What actually gets written to rBgmOverrides. Full StreamIds, never raw indices.
  extern std::array<u32, BGM_COUNT> seqOverridesMusic;

  void InitMusicRandomizer();
  void ShuffleSequences(u8 typeMask);
}  // namespace Music
