#include "music.hpp"

#include <algorithm>
#include <vector>

#include "random.hpp"
#include "settings.hpp"

namespace Music {

  // When true, a track may only be replaced by one whose ENTIRE routing flag word matches.
  // Setting it false relaxes to the routing bits alone
  // (flags & 6), which widens every pool but leaves the undecoded bits -- 0x1, 0x8, 0x10, 0x20,
  // 0x40, 0x100, most likely loop/fade/priority.
  static constexpr bool kStrictFlagMatch = false;

  const std::array<u32, BGM_COUNT> seqFlagsMusic = {
      0x003, 0x001, 0x001, 0x008, 0x000, 0x000,
      0x001, 0x001, 0x002, 0x002, 0x000, 0x000,
      0x101, 0x000, 0x002, 0x000, 0x001, 0x001,
      0x000, 0x001, 0x000, 0x000, 0x000, 0x000,
      0x040, 0x010, 0x000, 0x008, 0x001, 0x000,
      0x000, 0x020, 0x002, 0x000, 0x002, 0x002,
      0x002, 0x008, 0x000, 0x000, 0x000, 0x000,
      0x000, 0x002, 0x000, 0x040, 0x000, 0x000,
      0x000, 0x000, 0x002, 0x002, 0x002, 0x002,
      0x010, 0x002, 0x008, 0x002, 0x000, 0x001,
      0x011, 0x002, 0x000, 0x000, 0x000, 0x000,
      0x000, 0x000, 0x020, 0x002, 0x020, 0x002,
      0x002, 0x002, 0x002, 0x002, 0x002, 0x002,
      0x002, 0x002, 0x000, 0x002, 0x002, 0x002,
      0x002, 0x008, 0x000, 0x000, 0x002, 0x002,
      0x000, 0x002, 0x002, 0x002, 0x002, 0x002,
      0x000, 0x002, 0x002, 0x002, 0x002, 0x001,
      0x001, 0x002, 0x002, 0x000, 0x000, 0x000,
      0x002, 0x002, 0x002, 0x001, 0x000, 0x004,
      0x000, 0x002, 0x000, 0x000, 0x000, 0x002,
      0x002, 0x002, 0x000, 0x000, 0x000, 0x000,
      0x000, 0x000, 0x011, 0x011, 0x011, 0x012,
      0x012, 0x011,
  };

  // Musical category. SEQ_NOSHUFFLE covers three kinds of track: placeholders and system music
  // (DUMMY_*, TITLE, FILE_SELECT, STANDBY, staff roll), anything synchronised to an on-screen
  // performance (the Milk Bar quartet, the Zora band jam, the frog choir, the Song of Soaring warp
  // cue), and anything the player reads as a gameplay signal rather than as music -- TIME_LIMIT
  // above all, which is how you know the final hours have started.
  // When in doubt, prefer SEQ_NOSHUFFLE: an unshuffled track is a missed
  // opportunity, a wrongly shuffled one can read as a bug.
  const std::array<SeqType, BGM_COUNT> seqTypesMusic = {
      /* 00 NA_BGM_DUMMY_NO_BGM      */ SEQ_NOSHUFFLE,
      /* 01 NA_BGM_NA_SEQUENCE       */ SEQ_NOSHUFFLE,
      /* 02 NA_BGM_FIELD             */ SEQ_BGM_WORLD,
      /* 03 NA_BGM_CHASE             */ SEQ_BGM_BATTLE,
      /* 04 NA_BGM_STALKID           */ SEQ_BGM_EVENT,
      /* 05 NA_BGM_CLOCK_TOWER       */ SEQ_BGM_WORLD,
      /* 06 NA_BGM_RUIN_DUNGEON_FRONT */ SEQ_BGM_WORLD,
      /* 07 NA_BGM_RUIN_DUNGEON_REVERSE */ SEQ_BGM_WORLD,
      /* 08 NA_BGM_FAILURE_0         */ SEQ_FANFARE,
      /* 09 NA_BGM_FAILURE_1         */ SEQ_FANFARE,
      /* 0A NA_BGM_OMENYA            */ SEQ_BGM_WORLD,
      /* 0B NA_BGM_DEMO_CURE         */ SEQ_BGM_EVENT,
      /* 0C NA_BGM_DAMP_AREA         */ SEQ_BGM_WORLD,
      /* 0D NA_BGM_UFO               */ SEQ_BGM_EVENT,
      /* 0E NA_BGM_JUNGLE_CREWS      */ SEQ_FANFARE,
      /* 0F NA_BGM_SHARP             */ SEQ_BGM_WORLD,
      /* 10 NA_BGM_SEA_AREA          */ SEQ_BGM_WORLD,
      /* 11 NA_BGM_IKANA_AREA        */ SEQ_BGM_WORLD,
      /* 12 NA_BGM_DEKU_KING         */ SEQ_BGM_WORLD,
      /* 13 NA_BGM_SNOW_AREA         */ SEQ_BGM_WORLD,
      /* 14 NA_BGM_PIRATE_AREA       */ SEQ_BGM_WORLD,
      /* 15 NA_BGM_DUMMY_21          */ SEQ_NOSHUFFLE,
      /* 16 NA_BGM_DUMMY_22          */ SEQ_NOSHUFFLE,
      /* 17 NA_BGM_DUMMY_23          */ SEQ_NOSHUFFLE,
      /* 18 NA_BGM_FILE_SELECT       */ SEQ_NOSHUFFLE,
      /* 19 NA_BGM_EVENT_CLEAR       */ SEQ_BGM_EVENT,
      /* 1A NA_BGM_ENEMY             */ SEQ_BGM_BATTLE,
      /* 1B NA_BGM_BOSS00            */ SEQ_BGM_BATTLE,
      /* 1C NA_BGM_JUNGLE_DUNGEON    */ SEQ_BGM_WORLD,
      /* 1D NA_BGM_MARKET            */ SEQ_BGM_WORLD,
      /* 1E NA_BGM_OPENING           */ SEQ_NOSHUFFLE,
      /* 1F NA_BGM_LINK_HOUSE        */ SEQ_BGM_WORLD,
      /* 20 NA_BGM_GAME_OVER         */ SEQ_FANFARE,
      /* 21 NA_BGM_BOSS_CLEAR        */ SEQ_FANFARE,
      /* 22 NA_BGM_ITEM_GET          */ SEQ_FANFARE,
      /* 23 NA_BGM_GATE_OPEN         */ SEQ_FANFARE,
      /* 24 NA_BGM_HEART_GET         */ SEQ_FANFARE,
      /* 25 NA_BGM_MINI_GAME_2       */ SEQ_BGM_WORLD,
      /* 26 NA_BGM_GORON_RACE        */ SEQ_BGM_WORLD,
      /* 27 NA_BGM_ORGEL_HOUSE       */ SEQ_BGM_WORLD,
      /* 28 NA_BGM_GODESS            */ SEQ_BGM_EVENT,
      /* 29 NA_BGM_HIME              */ SEQ_BGM_EVENT,
      /* 2A NA_BGM_SISTER_DANCER     */ SEQ_BGM_WORLD,
      /* 2B NA_BGM_OPEN_TRE_BOX      */ SEQ_FANFARE,
      /* 2C NA_BGM_DRUGSTORE         */ SEQ_BGM_WORLD,
      /* 2D NA_BGM_KYOJIN_ROOM       */ SEQ_BGM_EVENT,
      /* 2E NA_BGM_FUSHA             */ SEQ_BGM_WORLD,
      /* 2F NA_BGM_RONRON            */ SEQ_BGM_WORLD,
      /* 30 NA_BGM_GORON             */ SEQ_BGM_WORLD,
      /* 31 NA_BGM_MEETING           */ SEQ_BGM_EVENT,
      /* 32 NA_BGM_OCA_EPONA         */ SEQ_OCARINA,
      /* 33 NA_BGM_OCA_SUN           */ SEQ_OCARINA,
      /* 34 NA_BGM_OCA_TIME_NORMAL   */ SEQ_OCARINA,
      /* 35 NA_BGM_OCA_STORM         */ SEQ_OCARINA,
      /* 36 NA_BGM_ZORA              */ SEQ_BGM_WORLD,
      /* 37 NA_BGM_MASK_GET          */ SEQ_FANFARE,
      /* 38 NA_BGM_MIDDLE_BOSS       */ SEQ_BGM_BATTLE,
      /* 39 NA_BGM_S_ITEM_GET        */ SEQ_FANFARE,
      /* 3A NA_BGM_TENMONDAI         */ SEQ_BGM_WORLD,
      /* 3B NA_BGM_NORMAL_DUNGEON    */ SEQ_BGM_WORLD,
      /* 3C NA_BGM_MILK_BAR          */ SEQ_BGM_WORLD,
      /* 3D NA_BGM_APPEAR            */ SEQ_FANFARE,
      /* 3E NA_BGM_MAYOIMORI         */ SEQ_BGM_WORLD,
      /* 3F NA_BGM_GORON_GOAL        */ SEQ_FANFARE,
      /* 40 NA_BGM_HORSE             */ SEQ_BGM_WORLD,
      /* 41 NA_BGM_HORSE_GOAL        */ SEQ_FANFARE,
      /* 42 NA_BGM_INGO              */ SEQ_BGM_WORLD,
      /* 43 NA_BGM_KOTAKE_KOUME      */ SEQ_BGM_WORLD,
      /* 44 NA_BGM_SHOP              */ SEQ_BGM_WORLD,
      /* 45 NA_BGM_OWL               */ SEQ_BGM_EVENT,
      /* 46 NA_BGM_MINI_GAME         */ SEQ_BGM_WORLD,
      /* 47 NA_BGM_OCA_BIGWING       */ SEQ_OCARINA,
      /* 48 NA_BGM_OCA_CURE          */ SEQ_OCARINA,
      /* 49 NA_BGM_TIME_SPEED        */ SEQ_FANFARE,
      /* 4A NA_BGM_TIME_JUMP         */ SEQ_FANFARE,
      /* 4B NA_BGM_DEMO_AWAKING      */ SEQ_BGM_EVENT,
      /* 4C NA_BGM_DEMO_LULLABY      */ SEQ_BGM_EVENT,
      /* 4D NA_BGM_DEMO_TIDE         */ SEQ_BGM_EVENT,
      /* 4E NA_BGM_DEMO_SHELL        */ SEQ_BGM_EVENT,
      /* 4F NA_BGM_DEMO_PLEDGE       */ SEQ_BGM_EVENT,
      /* 50 NA_BGM_EXERCISE_HALL     */ SEQ_BGM_WORLD,
      /* 51 NA_BGM_DEMO_LULLABY_HALF */ SEQ_BGM_EVENT,
      /* 52 NA_BGM_OCA_YOUSEI        */ SEQ_OCARINA,
      /* 53 NA_BGM_FACEMASK          */ SEQ_BGM_EVENT,
      /* 54 NA_BGM_QUARTET           */ SEQ_NOSHUFFLE,
      /* 55 NA_BGM_WING_WARP         */ SEQ_NOSHUFFLE,
      /* 56 NA_BGM_MILK_BAR_DUMMY    */ SEQ_NOSHUFFLE,
      /* 57 NA_BGM_TIME_LIMIT        */ SEQ_NOSHUFFLE,
      /* 58 NA_BGM_MIKAU_LIFF        */ SEQ_BGM_EVENT,
      /* 59 NA_BGM_MIKAU_FIN         */ SEQ_BGM_EVENT,
      /* 5A NA_BGM_FROG_SONG         */ SEQ_NOSHUFFLE,
      /* 5B NA_BGM_OCA_AWAKING       */ SEQ_OCARINA,
      /* 5C NA_BGM_OCA_LULLABY       */ SEQ_OCARINA,
      /* 5D NA_BGM_OCA_TIDE          */ SEQ_OCARINA,
      /* 5E NA_BGM_OCA_SHELL         */ SEQ_OCARINA,
      /* 5F NA_BGM_OCA_PLEDGE        */ SEQ_OCARINA,
      /* 60 NA_BGM_LAST_DUNGEON      */ SEQ_BGM_WORLD,
      /* 61 NA_BGM_OCA_LULLABY_HALF  */ SEQ_OCARINA,
      /* 62 NA_BGM_OCA_SESSION       */ SEQ_NOSHUFFLE,
      /* 63 NA_BGM_DEMO_SESSION      */ SEQ_NOSHUFFLE,
      /* 64 NA_BGM_ALLPART_SESSION   */ SEQ_NOSHUFFLE,
      /* 65 NA_BGM_SILVER_DUNGEON    */ SEQ_BGM_WORLD,
      /* 66 NA_BGM_DEEPBLUE_DUNGEON  */ SEQ_BGM_WORLD,
      /* 67 NA_BGM_DEMO_TIDE_SAX     */ SEQ_BGM_EVENT,
      /* 68 NA_BGM_DEMO_TIDE_VOCAL   */ SEQ_BGM_EVENT,
      /* 69 NA_BGM_MUJURA_1          */ SEQ_BGM_BATTLE,
      /* 6A NA_BGM_MUJURA_2          */ SEQ_BGM_BATTLE,
      /* 6B NA_BGM_MUJURA_3          */ SEQ_BGM_BATTLE,
      /* 6C NA_BGM_BASS_PLAY         */ SEQ_NOSHUFFLE,
      /* 6D NA_BGM_DRUMS_PLAY        */ SEQ_NOSHUFFLE,
      /* 6E NA_BGM_PIANO_PLAY        */ SEQ_NOSHUFFLE,
      /* 6F NA_BGM_IKANA_CASTLE      */ SEQ_BGM_WORLD,
      /* 70 NA_BGM_GATHERING         */ SEQ_BGM_EVENT,
      /* 71 NA_BGM_CAMARO_DANCE      */ SEQ_NOSHUFFLE,
      /* 72 NA_BGM_DONKEY_CART       */ SEQ_BGM_WORLD,
      /* 73 NA_BGM_QUIZ              */ SEQ_FANFARE,
      /* 74 NA_BGM_END_DEMO          */ SEQ_NOSHUFFLE,
      /* 75 NA_BGM_OPENING_LOOP      */ SEQ_NOSHUFFLE,
      /* 76 NA_BGM_TITLE             */ SEQ_NOSHUFFLE,
      /* 77 NA_BGM_DUNGEON_APPEAR    */ SEQ_FANFARE,
      /* 78 NA_BGM_PURIFICATION_0    */ SEQ_FANFARE,
      /* 79 NA_BGM_PURIFICATION_1    */ SEQ_FANFARE,
      /* 7A NA_BGM_STANDBY           */ SEQ_NOSHUFFLE,
      /* 7B NA_BGM_INTO_THE_MOON     */ SEQ_BGM_EVENT,
      /* 7C NA_BGM_GOODBYE_GIANT     */ SEQ_BGM_EVENT,
      /* 7D NA_BGM_CHAT              */ SEQ_BGM_EVENT,
      /* 7E NA_BGM_MOON_VANISH       */ SEQ_BGM_EVENT,
      /* 7F NA_BGM_OCA_MUS           */ SEQ_NOSHUFFLE,
      /* 80 NA_BGM_DEMO_SE_SEQ_OLD   */ SEQ_NOSHUFFLE,
      /* 81 NA_BGM_FISHING1          */ SEQ_BGM_WORLD,
      /* 82 NA_BGM_STAFFROLL2        */ SEQ_NOSHUFFLE,
      /* 83 NA_BGM_M_BARQUARTET      */ SEQ_NOSHUFFLE,
      /* 84 NA_BGM_M_BARQUARTET_ALL  */ SEQ_NOSHUFFLE,
      /* 85 NA_BGM_ZORA_SESSION      */ SEQ_NOSHUFFLE,
  };

  std::array<u32, BGM_COUNT> seqOverridesMusic;

  void InitMusicRandomizer() {
    for (size_t i = 0; i < BGM_COUNT; i++) {
      seqOverridesMusic[i] = BGM_BASE + i;
    }
  }

  static u32 FlagKey(size_t index) {
    return kStrictFlagMatch ? seqFlagsMusic[index] : (seqFlagsMusic[index] & 0x6);
  }

  // Shuffles within (category, routing class) groups. Partitioning on the flags as well as the
  // category is what keeps a looping theme from landing where the game expects a one-shot: the
  // routing word decides which player a track goes to and how it is stopped, so tracks that differ
  // there are not interchangeable no matter how alike they sound.
  void ShuffleSequences(u8 typeMask) {
    std::vector<u32> keys;
    for (size_t i = 0; i < BGM_COUNT; i++) {
      if ((seqTypesMusic[i] & typeMask) == 0) {
        continue;
      }
      const u32 key = FlagKey(i);
      if (std::find(keys.begin(), keys.end(), key) == keys.end()) {
        keys.push_back(key);
      }
    }

    for (const u32 key : keys) {
      std::vector<size_t> slots;
      std::vector<u32> pool;
      for (size_t i = 0; i < BGM_COUNT; i++) {
        if ((seqTypesMusic[i] & typeMask) != 0 && FlagKey(i) == key) {
          slots.push_back(i);
          pool.push_back(seqOverridesMusic[i]);
        }
      }
      if (pool.size() < 2) {
        continue;
      }
      Shuffle(pool);
      for (size_t n = 0; n < slots.size(); n++) {
        seqOverridesMusic[slots[n]] = pool[n];
      }
    }
  }
}  // namespace Music
