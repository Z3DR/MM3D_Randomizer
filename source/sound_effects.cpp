#include "sound_effects.hpp"

#include <vector>

#include "random.hpp"

namespace SFX {

  const std::array<SfxType, SFX_COUNT> sfxTypes = {
#include "sound_effects_types.inc"
  };

  static rnd::SfxData sfxData;

  const rnd::SfxData& GetSfxData() {
    return sfxData;
  }


  template <typename Pred>
  static void ShufflePool(u16* table, Pred inPool) {
    std::vector<u16> ids;
    for (u16 i = 0; i < SFX_COUNT; i++) {
      if (inPool(sfxTypes[i])) {
        ids.push_back(i);
      }
    }
    if (ids.size() < 2) {
      return;
    }
    std::vector<u16> shuffled = ids;
    Derange(shuffled);
    for (size_t n = 0; n < ids.size(); n++) {
      table[ids[n]] = shuffled[n];
    }
  }

  static bool IsLinkFootstep(SfxType t) {
    return t >= SFX_LINK_WALK && t <= SFX_LINK_MOVE;
  }

  static constexpr u16 kLinkVoiceBase = 0x7F9;
  static constexpr u16 kLinkVoiceSets[] = {0x00, 0x20, 0x80, 0xA0, 0xC0, 0xE0};

  static void ShuffleLinkVoice(u16* table) {
    std::vector<u16> offsets;
    for (u16 offset = 0; offset < 0x20; offset++) {
      if (sfxTypes[kLinkVoiceBase + offset] == SFX_LINK_VOICE) {
        offsets.push_back(offset);
      }
    }
    std::vector<u16> shuffled = offsets;
    Derange(shuffled);
    for (const u16 set : kLinkVoiceSets) {
      for (size_t n = 0; n < offsets.size(); n++) {
        table[kLinkVoiceBase + set + offsets[n]] = kLinkVoiceBase + set + shuffled[n];
      }
    }
  }

  static void MarkSet(u32* set, u16 index) {
    set[index / 32] |= 1u << (index % 32);
  }

  void ShuffleSoundEffects() {
    sfxData = {};
    for (u8 type = 0; type < SFXTYPE_COUNT; type++) {
      ShufflePool(sfxData.categorical, [type](SfxType t) { return t == type; });
    }
    for (u8 type = SFX_LINK_WALK; type <= SFX_LINK_MOVE; type++) {
      ShufflePool(sfxData.categorical, [type](SfxType t) { return t == type; });
    }
    ShufflePool(sfxData.categorical, [](SfxType t) { return t == SFX_LINK_SLIDE; });
    ShuffleLinkVoice(sfxData.categorical);

    ShufflePool(sfxData.chaos, [](SfxType t) { return t < SFXTYPE_COUNT || t == SFX_NOCAT; });
    ShufflePool(sfxData.chaos, IsLinkFootstep);
    ShufflePool(sfxData.chaos, [](SfxType t) { return t == SFX_LINK_SLIDE; });
    ShuffleLinkVoice(sfxData.chaos);

    for (u16 i = 0; i < SFX_COUNT; i++) {
      if (IsLinkFootstep(sfxTypes[i]) || sfxTypes[i] == SFX_LINK_SLIDE) {
        MarkSet(sfxData.linkFootsteps, i);
      } else if (sfxTypes[i] == SFX_LINK_VOICE) {
        MarkSet(sfxData.linkVoice, i);
      }
      if (sfxTypes[i] == SFX_LINK_SLIDE) {
        MarkSet(sfxData.heldShuffled, i);
      }
    }
  }
}  // namespace SFX
