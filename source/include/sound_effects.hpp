#pragma once

#include <array>

#include "rnd/sfx.h"

namespace SFX {
  // What a sound is, for Categorical. SFX_NOCAT sounds only move under Chaos; SFX_NOSHUFFLE never moves.
  enum SfxType : u8 {
    SFX_FOOTSTEP,
    SFX_JUMP_LAND,
    SFX_ATTACK,
    SFX_DAMAGE,
    SFX_DEATH,
    SFX_CRY,
    SFX_NPC_VOICE,
    SFX_EXPLOSION,
    SFX_BREAK,
    SFX_OPEN,
    SFX_CLOSE,
    SFX_WATER,
    SFX_APPEAR,
    SFXTYPE_COUNT,
    // Link's own, each group shuffled only among itself so the in-game toggles can switch it off.
    SFX_LINK_WALK = 0x40,
    SFX_LINK_JUMP,
    SFX_LINK_LAND,
    SFX_LINK_SLIP,
    SFX_LINK_BOUND,
    SFX_LINK_CRAWL,
    SFX_LINK_MOVE,   // Deku spin, Goron punch, roll, ...: one-shot, with the footsteps
    SFX_LINK_VOICE,
    SFX_LINK_SLIDE,  // held floor slides, also with the footsteps but only among themselves
    SFX_NOCAT = 0xFE,
    SFX_NOSHUFFLE = 0xFF,
  };

  extern const std::array<SfxType, SFX_COUNT> sfxTypes;

  // Both mode tables are always filled, whatever the option is set to, because it can be changed in game.
  void ShuffleSoundEffects();
  const rnd::SfxData& GetSfxData();
}  // namespace SFX
