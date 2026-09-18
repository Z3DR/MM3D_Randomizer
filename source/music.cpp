#include "music.hpp"

#include <algorithm>
#include <vector>

#include "random.hpp"

namespace Music {

  // The game's own per-slot flags (0x6A0DEC in code.bin), matching the decomp's sequence table:
  // 0x1 allows enemy music over the track, 0x2 plays it on the fanfare player over the area music,
  // 0x4 is Kamaro's dance, 0x8 restores the previous track afterwards, 0x10/0x20 resume a scene track
  // where it left off. The game reads them by the slot it asked for, not the track that ends up playing.
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

  // Names are the decomp's, with MM3D's leftover Ocarina of Time labels in brackets; the labels are
  // misleading (GATE_OPEN is a Clock Town Day 2 pointer, DUMMY_21-23 are Clock Town's three days).
  // `loops` is each vanilla stream's CSTM loop flag. Swapping a looping track into a one-shot slot is
  // what left the item fanfare playing Clock Town Day 2 forever.
  //
  // Left alone: anything synchronised to an on-screen performance or a song being taught, cutscene
  // and credits music, the final hours theme (a gameplay signal), and the four mono streams, which
  // break audio when anything else plays in their place.
  // clang-format off
  const std::array<MusicSlot, BGM_COUNT> musicSlots = {{
      /* 00 NA_BGM_GENERAL_SFX                 (NA_BGM_DUMMY_NO_BGM) -- general sfx */ {POOL_NONE, false},
      /* 01 NA_BGM_AMBIENCE                    (NA_BGM_NA_SEQUENCE) -- ambience */ {POOL_NONE, false},
      /* 02 NA_BGM_TERMINA_FIELD               (NA_BGM_FIELD) */ {POOL_AREA, true},
      /* 03 NA_BGM_CHASE                       (NA_BGM_CHASE) */ {POOL_BATTLE, true},
      /* 04 NA_BGM_MAJORAS_THEME               (NA_BGM_STALKID) */ {POOL_EVENT, true},
      /* 05 NA_BGM_CLOCK_TOWER                 (NA_BGM_CLOCK_TOWER) */ {POOL_AREA, true},
      /* 06 NA_BGM_STONE_TOWER_TEMPLE          (NA_BGM_RUIN_DUNGEON_FRONT) */ {POOL_AREA, true},
      /* 07 NA_BGM_INV_STONE_TOWER_TEMPLE      (NA_BGM_RUIN_DUNGEON_REVERSE) */ {POOL_AREA, true},
      /* 08 NA_BGM_FAILURE_0                   (NA_BGM_FAILURE_0) */ {POOL_FANFARE_EVENT, false},
      /* 09 NA_BGM_FAILURE_1                   (NA_BGM_FAILURE_1) */ {POOL_FANFARE_EVENT, false},
      /* 0A NA_BGM_HAPPY_MASK_SALESMAN         (NA_BGM_OMENYA) */ {POOL_AREA, true},
      /* 0B NA_BGM_SONG_OF_HEALING             (NA_BGM_DEMO_CURE) */ {POOL_EVENT, true},
      /* 0C NA_BGM_SWAMP_REGION                (NA_BGM_DAMP_AREA) */ {POOL_AREA, true},
      /* 0D NA_BGM_ALIEN_INVASION              (NA_BGM_UFO) */ {POOL_EVENT, true},
      /* 0E NA_BGM_SWAMP_CRUISE                (NA_BGM_JUNGLE_CREWS) -- mono */ {POOL_NONE, false},
      /* 0F NA_BGM_SHARPS_CURSE                (NA_BGM_SHARP) */ {POOL_AREA, true},
      /* 10 NA_BGM_GREAT_BAY_REGION            (NA_BGM_SEA_AREA) */ {POOL_AREA, true},
      /* 11 NA_BGM_IKANA_REGION                (NA_BGM_IKANA_AREA) */ {POOL_AREA, true},
      /* 12 NA_BGM_DEKU_PALACE                 (NA_BGM_DEKU_KING) */ {POOL_AREA, true},
      /* 13 NA_BGM_MOUNTAIN_REGION             (NA_BGM_SNOW_AREA) */ {POOL_AREA, true},
      /* 14 NA_BGM_PIRATES_FORTRESS            (NA_BGM_PIRATE_AREA) */ {POOL_AREA, true},
      /* 15 NA_BGM_CLOCK_TOWN_DAY_1            (NA_BGM_DUMMY_21) */ {POOL_AREA, true},
      /* 16 NA_BGM_CLOCK_TOWN_DAY_2            (NA_BGM_DUMMY_22) */ {POOL_AREA, true},
      /* 17 NA_BGM_CLOCK_TOWN_DAY_3            (NA_BGM_DUMMY_23) */ {POOL_AREA, true},
      /* 18 NA_BGM_FILE_SELECT                 (NA_BGM_FILE_SELECT) -- file select */ {POOL_NONE, true},
      /* 19 NA_BGM_CLEAR_EVENT                 (NA_BGM_EVENT_CLEAR) -- timed to the event */ {POOL_NONE, false},
      /* 1A NA_BGM_ENEMY                       (NA_BGM_ENEMY) -- replays its start when retriggered */ {POOL_NONE, true},
      /* 1B NA_BGM_BOSS                        (NA_BGM_BOSS00) */ {POOL_BATTLE, true},
      /* 1C NA_BGM_WOODFALL_TEMPLE             (NA_BGM_JUNGLE_DUNGEON) */ {POOL_AREA, true},
      /* 1D NA_BGM_CLOCK_TOWN_MAIN_SEQUENCE    (NA_BGM_MARKET) */ {POOL_AREA, true},
      /* 1E NA_BGM_OPENING                     (NA_BGM_OPENING) -- intro */ {POOL_NONE, false},
      /* 1F NA_BGM_INSIDE_A_HOUSE              (NA_BGM_LINK_HOUSE) */ {POOL_AREA, true},
      /* 20 NA_BGM_GAME_OVER                   (NA_BGM_GAME_OVER) */ {POOL_FANFARE_EVENT, false},
      /* 21 NA_BGM_CLEAR_BOSS                  (NA_BGM_BOSS_CLEAR) */ {POOL_FANFARE_GOAL, false},
      /* 22 NA_BGM_GET_ITEM                    (NA_BGM_ITEM_GET) */ {POOL_FANFARE_ITEM, false},
      /* 23 NA_BGM_CLOCK_TOWN_DAY_2_PTR        (NA_BGM_GATE_OPEN) -- unused pointer to Clock Town Day 2 */ {POOL_NONE, true},
      /* 24 NA_BGM_GET_HEART                   (NA_BGM_HEART_GET) */ {POOL_FANFARE_ITEM, false},
      /* 25 NA_BGM_TIMED_MINI_GAME             (NA_BGM_MINI_GAME_2) */ {POOL_AREA, true},
      /* 26 NA_BGM_GORON_RACE                  (NA_BGM_GORON_RACE) */ {POOL_AREA, true},
      /* 27 NA_BGM_MUSIC_BOX_HOUSE             (NA_BGM_ORGEL_HOUSE) */ {POOL_AREA, true},
      /* 28 NA_BGM_FAIRY_FOUNTAIN              (NA_BGM_GODESS) */ {POOL_EVENT, true},
      /* 29 NA_BGM_ZELDAS_LULLABY              (NA_BGM_HIME) */ {POOL_EVENT, true},
      /* 2A NA_BGM_ROSA_SISTERS                (NA_BGM_SISTER_DANCER) */ {POOL_AREA, true},
      /* 2B NA_BGM_OPEN_CHEST                  (NA_BGM_OPEN_TRE_BOX) */ {POOL_FANFARE_ITEM, false},
      /* 2C NA_BGM_MARINE_RESEARCH_LAB         (NA_BGM_DRUGSTORE) */ {POOL_AREA, true},
      /* 2D NA_BGM_GIANTS_THEME                (NA_BGM_KYOJIN_ROOM) */ {POOL_EVENT, true},
      /* 2E NA_BGM_SONG_OF_STORMS              (NA_BGM_FUSHA) */ {POOL_AREA, true},
      /* 2F NA_BGM_ROMANI_RANCH                (NA_BGM_RONRON) */ {POOL_AREA, true},
      /* 30 NA_BGM_GORON_VILLAGE               (NA_BGM_GORON) */ {POOL_AREA, true},
      /* 31 NA_BGM_MAYORS_OFFICE               (NA_BGM_MEETING) */ {POOL_EVENT, true},
      /* 32 NA_BGM_OCARINA_EPONA               (NA_BGM_OCA_EPONA) */ {POOL_OCARINA, false},
      /* 33 NA_BGM_OCARINA_SUNS                (NA_BGM_OCA_SUN) */ {POOL_OCARINA, false},
      /* 34 NA_BGM_OCARINA_TIME                (NA_BGM_OCA_TIME_NORMAL) */ {POOL_OCARINA, false},
      /* 35 NA_BGM_OCARINA_STORM               (NA_BGM_OCA_STORM) */ {POOL_OCARINA, false},
      /* 36 NA_BGM_ZORA_HALL                   (NA_BGM_ZORA) */ {POOL_AREA, true},
      /* 37 NA_BGM_GET_NEW_MASK                (NA_BGM_MASK_GET) */ {POOL_FANFARE_ITEM, false},
      /* 38 NA_BGM_MINI_BOSS                   (NA_BGM_MIDDLE_BOSS) */ {POOL_BATTLE, true},
      /* 39 NA_BGM_GET_SMALL_ITEM              (NA_BGM_S_ITEM_GET) */ {POOL_FANFARE_ITEM, false},
      /* 3A NA_BGM_ASTRAL_OBSERVATORY          (NA_BGM_TENMONDAI) */ {POOL_AREA, true},
      /* 3B NA_BGM_CAVERN                      (NA_BGM_NORMAL_DUNGEON) */ {POOL_AREA, true},
      /* 3C NA_BGM_MILK_BAR                    (NA_BGM_MILK_BAR) -- mono, performance */ {POOL_NONE, false},
      /* 3D NA_BGM_ZELDA_APPEAR                (NA_BGM_APPEAR) */ {POOL_FANFARE_EVENT, false},
      /* 3E NA_BGM_SARIAS_SONG                 (NA_BGM_MAYOIMORI) */ {POOL_AREA, true},
      /* 3F NA_BGM_GORON_GOAL                  (NA_BGM_GORON_GOAL) */ {POOL_FANFARE_GOAL, false},
      /* 40 NA_BGM_HORSE                       (NA_BGM_HORSE) */ {POOL_AREA, true},
      /* 41 NA_BGM_HORSE_GOAL                  (NA_BGM_HORSE_GOAL) */ {POOL_FANFARE_GOAL, false},
      /* 42 NA_BGM_INGO                        (NA_BGM_INGO) */ {POOL_AREA, true},
      /* 43 NA_BGM_KOTAKE_POTION_SHOP          (NA_BGM_KOTAKE_KOUME) */ {POOL_AREA, true},
      /* 44 NA_BGM_SHOP                        (NA_BGM_SHOP) -- mono */ {POOL_NONE, false},
      /* 45 NA_BGM_OWL                         (NA_BGM_OWL) */ {POOL_EVENT_SUB, true},
      /* 46 NA_BGM_SHOOTING_GALLERY            (NA_BGM_MINI_GAME) -- mono */ {POOL_NONE, false},
      /* 47 NA_BGM_OCARINA_SOARING             (NA_BGM_OCA_BIGWING) */ {POOL_OCARINA, false},
      /* 48 NA_BGM_OCARINA_HEALING             (NA_BGM_OCA_CURE) */ {POOL_OCARINA, false},
      /* 49 NA_BGM_INVERTED_SONG_OF_TIME       (NA_BGM_TIME_SPEED) */ {POOL_OCARINA, false},
      /* 4A NA_BGM_SONG_OF_DOUBLE_TIME         (NA_BGM_TIME_JUMP) */ {POOL_OCARINA, false},
      /* 4B NA_BGM_SONATA_OF_AWAKENING         (NA_BGM_DEMO_AWAKING) -- song taught on screen */ {POOL_NONE, false},
      /* 4C NA_BGM_GORON_LULLABY               (NA_BGM_DEMO_LULLABY) -- song taught on screen */ {POOL_NONE, false},
      /* 4D NA_BGM_NEW_WAVE_BOSSA_NOVA         (NA_BGM_DEMO_TIDE) -- song taught on screen */ {POOL_NONE, false},
      /* 4E NA_BGM_ELEGY_OF_EMPTINESS          (NA_BGM_DEMO_SHELL) -- song taught on screen */ {POOL_NONE, false},
      /* 4F NA_BGM_OATH_TO_ORDER               (NA_BGM_DEMO_PLEDGE) -- song taught on screen */ {POOL_NONE, false},
      /* 50 NA_BGM_SWORD_TRAINING_HALL         (NA_BGM_EXERCISE_HALL) */ {POOL_AREA, true},
      /* 51 NA_BGM_OCARINA_LULLABY_INTRO       (NA_BGM_DEMO_LULLABY_HALF) -- song taught on screen */ {POOL_NONE, false},
      /* 52 NA_BGM_LEARNED_NEW_SONG            (NA_BGM_OCA_YOUSEI) */ {POOL_FANFARE_ITEM, false},
      /* 53 NA_BGM_BREMEN_MARCH                (NA_BGM_FACEMASK) */ {POOL_EVENT_SUB, true},
      /* 54 NA_BGM_BALLAD_OF_THE_WIND_FISH     (NA_BGM_QUARTET) -- performance */ {POOL_NONE, false},
      /* 55 NA_BGM_SONG_OF_SOARING             (NA_BGM_WING_WARP) -- warp cue */ {POOL_NONE, false},
      /* 56 NA_BGM_MILK_BAR_DUPLICATE          (NA_BGM_MILK_BAR_DUMMY) -- pointer */ {POOL_NONE, true},
      /* 57 NA_BGM_FINAL_HOURS                 (NA_BGM_TIME_LIMIT) -- final hours signal */ {POOL_NONE, true},
      /* 58 NA_BGM_MIKAU_RIFF                  (NA_BGM_MIKAU_LIFF) -- performance */ {POOL_NONE, true},
      /* 59 NA_BGM_MIKAU_FINALE                (NA_BGM_MIKAU_FIN) -- performance */ {POOL_NONE, false},
      /* 5A NA_BGM_FROG_SONG                   (NA_BGM_FROG_SONG) -- performance */ {POOL_NONE, true},
      /* 5B NA_BGM_OCARINA_SONATA              (NA_BGM_OCA_AWAKING) */ {POOL_OCARINA, false},
      /* 5C NA_BGM_OCARINA_LULLABY             (NA_BGM_OCA_LULLABY) */ {POOL_OCARINA, false},
      /* 5D NA_BGM_OCARINA_NEW_WAVE            (NA_BGM_OCA_TIDE) */ {POOL_OCARINA, false},
      /* 5E NA_BGM_OCARINA_ELEGY               (NA_BGM_OCA_SHELL) */ {POOL_OCARINA, false},
      /* 5F NA_BGM_OCARINA_OATH                (NA_BGM_OCA_PLEDGE) */ {POOL_OCARINA, false},
      /* 60 NA_BGM_MAJORAS_LAIR                (NA_BGM_LAST_DUNGEON) */ {POOL_AREA, true},
      /* 61 NA_BGM_OCARINA_LULLABY_INTRO_PTR   (NA_BGM_OCA_LULLABY_HALF) */ {POOL_OCARINA, false},
      /* 62 NA_BGM_OCARINA_GUITAR_BASS_SESSION (NA_BGM_OCA_SESSION) -- performance */ {POOL_NONE, false},
      /* 63 NA_BGM_PIANO_SESSION               (NA_BGM_DEMO_SESSION) -- performance */ {POOL_NONE, false},
      /* 64 NA_BGM_INDIGO_GO_SESSION           (NA_BGM_ALLPART_SESSION) -- performance */ {POOL_NONE, false},
      /* 65 NA_BGM_SNOWHEAD_TEMPLE             (NA_BGM_SILVER_DUNGEON) */ {POOL_AREA, true},
      /* 66 NA_BGM_GREAT_BAY_TEMPLE            (NA_BGM_DEEPBLUE_DUNGEON) */ {POOL_AREA, true},
      /* 67 NA_BGM_NEW_WAVE_SAXOPHONE          (NA_BGM_DEMO_TIDE_SAX) -- performance */ {POOL_NONE, false},
      /* 68 NA_BGM_NEW_WAVE_VOCAL              (NA_BGM_DEMO_TIDE_VOCAL) -- performance */ {POOL_NONE, false},
      /* 69 NA_BGM_MAJORAS_WRATH               (NA_BGM_MUJURA_1) */ {POOL_BATTLE, true},
      /* 6A NA_BGM_MAJORAS_INCARNATION         (NA_BGM_MUJURA_2) */ {POOL_BATTLE, true},
      /* 6B NA_BGM_MAJORAS_MASK                (NA_BGM_MUJURA_3) */ {POOL_BATTLE, true},
      /* 6C NA_BGM_BASS_PLAY                   (NA_BGM_BASS_PLAY) -- performance */ {POOL_NONE, true},
      /* 6D NA_BGM_DRUMS_PLAY                  (NA_BGM_DRUMS_PLAY) -- performance */ {POOL_NONE, true},
      /* 6E NA_BGM_PIANO_PLAY                  (NA_BGM_PIANO_PLAY) -- performance */ {POOL_NONE, true},
      /* 6F NA_BGM_IKANA_CASTLE                (NA_BGM_IKANA_CASTLE) */ {POOL_AREA, true},
      /* 70 NA_BGM_GATHERING_GIANTS            (NA_BGM_GATHERING) -- cutscene */ {POOL_NONE, false},
      /* 71 NA_BGM_KAMARO_DANCE                (NA_BGM_CAMARO_DANCE) -- performance */ {POOL_NONE, true},
      /* 72 NA_BGM_CREMIA_CARRIAGE             (NA_BGM_DONKEY_CART) */ {POOL_AREA, true},
      /* 73 NA_BGM_KEATON_QUIZ                 (NA_BGM_QUIZ) */ {POOL_EVENT_SUB, true},
      /* 74 NA_BGM_END_CREDITS                 (NA_BGM_END_DEMO) -- credits */ {POOL_NONE, false},
      /* 75 NA_BGM_OPENING_LOOP                (NA_BGM_OPENING_LOOP) -- intro */ {POOL_NONE, true},
      /* 76 NA_BGM_TITLE_THEME                 (NA_BGM_TITLE) -- title */ {POOL_NONE, false},
      /* 77 NA_BGM_DUNGEON_APPEAR              (NA_BGM_DUNGEON_APPEAR) */ {POOL_FANFARE_EVENT, false},
      /* 78 NA_BGM_WOODFALL_CLEAR              (NA_BGM_PURIFICATION_0) */ {POOL_FANFARE_CLEAR, false},
      /* 79 NA_BGM_SNOWHEAD_CLEAR              (NA_BGM_PURIFICATION_1) */ {POOL_FANFARE_CLEAR, false},
      /* 7A NA_BGM_SEQ_122                     (NA_BGM_STANDBY) -- unused */ {POOL_NONE, false},
      /* 7B NA_BGM_INTO_THE_MOON               (NA_BGM_INTO_THE_MOON) */ {POOL_EVENT, true},
      /* 7C NA_BGM_GOODBYE_GIANT               (NA_BGM_GOODBYE_GIANT) -- cutscene */ {POOL_NONE, false},
      /* 7D NA_BGM_TATL_AND_TAEL               (NA_BGM_CHAT) */ {POOL_EVENT, true},
      /* 7E NA_BGM_MOONS_DESTRUCTION           (NA_BGM_MOON_VANISH) -- cutscene */ {POOL_NONE, false},
      /* 7F NA_BGM_END_CREDITS_SECOND_HALF     (NA_BGM_OCA_MUS) -- credits */ {POOL_NONE, false},
      /* 80 (3DS only)                         (NA_BGM_DEMO_SE_SEQ_OLD) -- unused */ {POOL_NONE, false},
      /* 81 (3DS only)                         (NA_BGM_FISHING1) */ {POOL_AREA, true},
      /* 82 (3DS only)                         (NA_BGM_STAFFROLL2) -- credits */ {POOL_NONE, false},
      /* 83 (3DS only)                         (NA_BGM_M_BARQUARTET) -- performance */ {POOL_NONE, false},
      /* 84 (3DS only)                         (NA_BGM_M_BARQUARTET_ALL) -- performance */ {POOL_NONE, false},
      /* 85 (3DS only)                         (NA_BGM_ZORA_SESSION) -- performance */ {POOL_NONE, false},
  }};
  // clang-format on

  std::array<u32, BGM_COUNT> seqOverridesMusic;
  std::array<u8, BGM_COUNT> seqFanfaresMusic;

  static bool IsFanfarePool(MusicPool pool) {
    return pool == POOL_FANFARE_ITEM || pool == POOL_FANFARE_EVENT || pool == POOL_FANFARE_CLEAR ||
           pool == POOL_FANFARE_GOAL || pool == POOL_OCARINA;
  }

  static u32 ShuffleKey(size_t index) {
    return (musicSlots[index].pool << 8) | (musicSlots[index].loops << 4) | (seqFlagsMusic[index] & 0x6);
  }

  void ShuffleSequences() {
    for (size_t i = 0; i < BGM_COUNT; i++) {
      seqOverridesMusic[i] = BGM_BASE + i;
      seqFanfaresMusic[i] = IsFanfarePool(musicSlots[i].pool) ? 1 : 0;
    }

    std::vector<u32> keys;
    for (size_t i = 0; i < BGM_COUNT; i++) {
      const u32 key = ShuffleKey(i);
      if (musicSlots[i].pool != POOL_NONE && std::find(keys.begin(), keys.end(), key) == keys.end()) {
        keys.push_back(key);
      }
    }

    for (const u32 key : keys) {
      std::vector<size_t> slots;
      std::vector<u32> pool;
      for (size_t i = 0; i < BGM_COUNT; i++) {
        if (musicSlots[i].pool != POOL_NONE && ShuffleKey(i) == key) {
          slots.push_back(i);
          pool.push_back(seqOverridesMusic[i]);
        }
      }
      if (pool.size() < 2) {
        continue;
      }
      Derange(pool);
      for (size_t n = 0; n < slots.size(); n++) {
        seqOverridesMusic[slots[n]] = pool[n];
      }
    }
  }
}  // namespace Music
