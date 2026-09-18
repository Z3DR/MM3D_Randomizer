# Prints source/sound_effects_types.inc, the per-id shuffle type table used by source/sound_effects.cpp.
#
# Usage: python3 scripts/gen_sfx_types.py <mm3dr>/code/include/game/sound.h <mm decomp root> \
#            > source/sound_effects_types.inc
#
# The ids and names come from mm3dr's EffectId enum. The names are Ocarina of Time leftovers, so they say
# little on their own; the MM decomp (github.com/zeldaret/mm) is used to decide what each sound is and
# how the game plays it. A sound is only shuffled when all of these hold:
#   - it is an enemy, environment or NPC voice sound. Link's own sounds are not shuffled with these: the
#     player, item and ocarina banks, his six voice sets, and anything the decomp's player code plays.
#     Two groups of his are the exception, each shuffled only among itself so the in-game Shuffle
#     Footsteps and Shuffle Link's Voice toggles can turn them off cleanly: his footsteps, jumps,
#     landings, moves and slides (SFX_LINK_*), and his voice (SFX_LINK_VOICE, see LINK_VOICE_OFFSETS).
#   - the decomp plays it somewhere. Unused ids may be silent or missing on 3DS, and a used sound mapped
#     onto one would vanish. MM3D-only sounds have no decomp name and are left alone for the same reason.
#   - it is a one-shot. `- SFX_FLAG` in the decomp marks a sound replayed every frame by its owner (the
#     carpenters' EV_MAKE_TURRET is one); swapping one of those for a one-shot corrupted the heap on
#     area change. Sounds handed to the timer, frequency, volume or channel-io helpers are held back too.
#   - it is not a gameplay signal such as the Clock Tower bells or the bank's rupee count.
# What passes is typed from its name. Categorical shuffles within a type; Chaos shuffles every type
# and SFX_NOCAT together. SFX_NOSHUFFLE never moves in either mode.
import glob
import os
import re
import sys

SFX_COUNT = 0xA36

# Checked in order; the first rule whose pattern matches any part of the name wins.
TYPE_RULES = [
    ("SFX_NPC_VOICE", r"^NA_SE_VO_"),
    ("SFX_DEATH", r"_(DEAD|DEATH|DIE|EXTINCT|FADEAWAY)(\d|_|$)"),
    ("SFX_DAMAGE", r"_(DAMAGE|DAMM)(\d|_|$)"),
    ("SFX_EXPLOSION", r"(EXPLOSION|EXPLSION|EXPLOSUIN)"),
    ("SFX_BREAK", r"_(BROKEN|BREAK|CRUSH|BREAK_IMPACT)(\d|_|$)"),
    ("SFX_CRY", r"_(CRY|VOICE|LAUGH|ROAR|SHOUT|SCREAM|WARAU|GROAN|UNARI|SNORE|SOB|NEIGH|BARK|ANG_BARK|WHINE|"
                r"GREET|SURPRISE|SURPRISED|ANGER|SIGH|JOY|SMILE|CALL|REACTION|CRYING|WEAKENED)(\d|_|$)"),
    ("SFX_ATTACK", r"_(ATTACK|BITE|PUNCH|KICK|SWING|THROW|SHOT|SHOOT|SWORD|SCYTHE|SLASH|CUT|LASH|BLOW|AIM|"
                   r"SWING_AXE|FIRE|MAGIC|SPIT)(\d|_|$)"),
    ("SFX_OPEN", r"_(OPEN|UNLOCK)(\d|_|$)"),
    ("SFX_CLOSE", r"_(CLOSE|STOP)(\d|_|$)"),
    ("SFX_WATER", r"(WATER|SPLASH|DIVE|WATERDROP)"),
    ("SFX_JUMP_LAND", r"_(JUMP|LAND|FALL|BOUND|ONGND|SINK|LEAP|DOWN)(\d|_|$)"),
    ("SFX_FOOTSTEP", r"_(WALK|RUN|DASH|FOOTSTEP|STEP|SWIM|FLY|FLUTTER|ROLL|SKIP|CRAWL|MOVE)(\d|_|$)"),
    ("SFX_APPEAR", r"_(APPEAR|VANISH|DISAPPEAR|WARP|FLASH|TRANSFORM|HIDE)(\d|_|$)"),
]

# Sounds the player reads as a signal rather than as noise.
SIGNALS = {
    "NA_SE_EV_CLOCK_TOWER_BELL",
    "NA_SE_EV_SIGNAL_BIGBELL",
    "NA_SE_EV_BIGBELL",
    "NA_SE_EV_FAIVE_LUPY_COUNT",
    "NA_SE_EV_UNSKILLFUL_OCARINA",
    "NA_SE_EV_TRE_BOX_APPEAR",
    "NA_SE_EV_CHICK_SONG",
    "NA_SE_VO_NAVY_CALL",
}

# Helpers that play a sound held, on a timer, or with its pitch, volume or channel io driven by the caller.
SPECIAL_CALL = re.compile(r"\b\w*(Flagged|EachFrame|Freq|Timer|VolumeTransition|ChannelIO|ScriptIO|WaterWheel|"
                          r"SwordCharge|Underwater|Metal|Ambience|Centered)\w*\s*\(")

# Link's movement sounds, one per floor surface, from the player bank's first block. Past 0xC6 the names are
# wrong: the decomp's channel names show PL_JUMP_METAL and PL_WALK_WALL are really Song of Soaring sounds.
LINK_FOOTSTEP = re.compile(r"^NA_SE_PL_(WALK|JUMP|LAND|SLIP|BOUND|CRAWL)(_(GROUND|SAND|CONCRETE|DIRT|WATER[012]|MAGMA|"
                           r"GRASS|IRON|LADDER|GLASS|METAL1|SNOW|ICE|WOOD))?$")
LINK_FOOTSTEP_END = 0xC6

# Moves of Link's that make a whoosh rather than a footstep, one or two per form. They go with the footsteps
# toggle but only trade among themselves. The decomp's channel names match these names, unlike
# PL_GORON_TO_BALL, which is really the transformation cutscene's sound.
LINK_MOVES = {
    "NA_SE_PL_DEKUNUTS_ATTACK",  # Deku spin
    "NA_SE_PL_GORON_PUNCH",
    "NA_SE_PL_GORON_BALLJUMP",
    "NA_SE_PL_ZORA_SWIM_DASH",
    "NA_SE_PL_ZORA_SWIM_ROLL",
    "NA_SE_PL_ROLL",
    "NA_SE_PL_SKIP",
}

# The floor slide the game replays every frame while Link slides or Deku spins. Held, so these only ever trade
# with each other; the patch's held-sound guard is told to leave them shuffled.
LINK_SLIDE = re.compile(r"^NA_SE_PL_SLIP(_(SAND|CONCRETE|DIRT|WATER[012]|MAGMA|GRASS|IRON|LADDER|GLASS|ICE))?_LEVEL$")

# Offsets into each voice set that the decomp's player code plays one-shot. The rest are held
# (TAKEN_AWAY, DRINK), cutscene-only (DEMO_DAMAGE) or never played, so they may be silent for some forms.
LINK_VOICE_OFFSETS = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F,
                      0x11, 0x14, 0x16, 0x18, 0x19, 0x1A}

# Link's voice: six 0x20-entry sets from VO_LI_SWORD_N (0x7F9). The offsets are the voice field (+0xF8) of
# the player form table at 0x68D988 -- Fierce Deity 0x00, Human 0x20, Deku 0x80, Zora 0xA0, Goron 0xC0 --
# plus the 0xE0 that emitFormSpecificSoundForPlayer uses for mask 0x13. Most read VO_DUMMY_* or VO_NAVY_*.
LINK_VOICE_BASE = 0x7F9
LINK_VOICE_SETS = (0x00, 0x20, 0x80, 0xA0, 0xC0, 0xE0)
LINK_VOICE = {LINK_VOICE_BASE + offset + i for offset in LINK_VOICE_SETS for i in range(0x20)}


def read_names(sound_h):
    src = open(sound_h).read()
    body = src[src.index("enum class EffectId"):]
    body = body[:body.index("};")]
    return {int(value, 16) - 0x01000000: name for name, value in re.findall(r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", body)}


def scan_decomp(root):
    used, held, special, player = set(), set(), set(), set()
    for path in glob.glob(os.path.join(root, "src", "**", "*.c"), recursive=True):
        text = open(path, errors="ignore").read()
        found = set(re.findall(r"\b(NA_SE_\w+)\b", text))
        used |= found
        held |= set(re.findall(r"(NA_SE_\w+)\s*-\s*SFX_FLAG", text))
        for statement in text.split(";"):
            if SPECIAL_CALL.search(statement):
                special |= set(re.findall(r"\b(NA_SE_\w+)\b", statement))
        if "ovl_player_actor" in path or os.path.basename(path).startswith("z_player"):
            player |= found
    return used, held, special, player


def classify(index, name, used, held, special, player):
    if name is None:
        return "SFX_NOSHUFFLE", "unnamed"
    footstep = LINK_FOOTSTEP.match(name)
    if footstep and index < LINK_FOOTSTEP_END:
        return "SFX_LINK_" + footstep.group(1), None
    if name in LINK_MOVES:
        return "SFX_LINK_MOVE", None
    if LINK_SLIDE.match(name):
        return "SFX_LINK_SLIDE", None
    if index in LINK_VOICE:
        offset = (index - LINK_VOICE_BASE) % 0x20
        return ("SFX_LINK_VOICE", None) if offset in LINK_VOICE_OFFSETS else ("SFX_NOSHUFFLE", "Link")
    bank = re.match(r"NA_SE_([A-Z0-9]+)_", name)
    bank = bank.group(1) if bank else None
    if bank not in ("EN", "EV", "VO", "NE"):
        return "SFX_NOSHUFFLE", "bank"
    if name.startswith(("NA_SE_VO_LI_", "NA_SE_VO_LK_")) or name in player:
        return "SFX_NOSHUFFLE", "Link"
    if name not in used:
        return "SFX_NOSHUFFLE", "unused"
    if name in held or "LEVEL" in name:
        return "SFX_NOSHUFFLE", "held"
    if name in special:
        return "SFX_NOSHUFFLE", "special"
    if name in SIGNALS:
        return "SFX_NOSHUFFLE", "signal"
    if "DEMO" in name:
        return "SFX_NOCAT", None  # timed to a cutscene
    for sfx_type, pattern in TYPE_RULES:
        if re.search(pattern, name):
            return sfx_type, None
    return "SFX_NOCAT", None


def main():
    names = read_names(sys.argv[1])
    used, held, special, player = scan_decomp(sys.argv[2])
    print("// Generated by scripts/gen_sfx_types.py; see there for the rules. Hand edits are fine, but rerunning")
    print("// the script overwrites them.")
    for index in range(SFX_COUNT):
        name = names.get(index)
        sfx_type, why = classify(index, name, used, held, special, player)
        note = f" ({why})" if why else ""
        print(f"/* {index:03X} {name or '-'}{note} */ {sfx_type},")


main()
