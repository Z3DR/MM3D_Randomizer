#pragma once

#include <array>

#include "rnd/music.h"

namespace Music {
  // Which slots may trade tracks. A slot only ever takes a track from its own pool.
  enum MusicPool : u8 {
    POOL_NONE,           // never shuffled
    POOL_AREA,           // looping area and interior themes
    POOL_BATTLE,         // looping boss, mini-boss and chase themes
    POOL_EVENT,          // looping character and event themes
    POOL_EVENT_SUB,      // looping themes played over the area music: Owl, Bremen March, Keaton Quiz
    POOL_FANFARE_ITEM,   // item, heart, mask and new song jingles
    POOL_FANFARE_EVENT,  // short event jingles: failure, game over, temple appearing
    POOL_FANFARE_CLEAR,  // the long temple-cleared pieces
    POOL_FANFARE_GOAL,   // one-shots that replace the area music: boss clear, race goals
    POOL_OCARINA,        // ocarina song playback
  };

  struct MusicSlot {
    MusicPool pool;
    bool loops;  // the vanilla stream's loop flag; a pool never mixes looping and one-shot tracks
  };

  extern const std::array<MusicSlot, BGM_COUNT> musicSlots;

  extern const std::array<u32, BGM_COUNT> seqFlagsMusic;

  extern std::array<u32, BGM_COUNT> seqOverridesMusic;

  extern std::array<u8, BGM_COUNT> seqFanfaresMusic;

  void ShuffleSequences();
}  // namespace Music
