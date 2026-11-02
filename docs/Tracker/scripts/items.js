/* Tracker data: the item grids, how counters are drawn, and every logic option.
   Single source of truth: main.js (UI + saving) and spoiler.js (log import) both read from here.
   checks.js reads the live state objects below (items, masks, dungeons, quests) and `logic`. */

// One table per grid. "Name" is an on/off item; "Name:N" is a counter running 0..N.
var GRID_SPECS = {
    items: [
        ["Sword:3", "Shield:2", "Bow:3", "FireArrow", "IceArrow", "LightArrow"],
        ["Magic:2", "Bomb:3", "Bombchu", "DekuStick", "DekuNut", "MagicBean"],
        ["Wallet:3", "PowderKeg", "PictographBox", "LensOfTruth", "Hookshot", "GreatFairySword"],
        ["RedPotion", "GoldDust", "Milk", "ChateauRomani", "MysteryMilk", "EmptyBottle:2"],
    ],
    masks: [
        ["PostmanHat", "AllNightMask", "BlastMask", "StoneMask", "GreatFairyMask", "DekuMask"],
        ["KeatonMask", "BremenMask", "BunnyHood", "DonGeroMask", "MaskOfScents", "GoronMask"],
        ["RomaniMask", "TroupeLeaderMask", "KafeiMask", "CouplesMask", "MaskOfTruth", "ZoraMask"],
        ["KamaroMask", "GibdoMask", "GaroMask", "CaptainsHat", "GiantsMask", "FierceDeityMask"],
    ],
    dungeons: [
        ["SwampSkulltulas:30", "OceanSkulltulas:30", "TownStrayFairy", "Seahorse", "ZoraEgg:7"],
        ["SwampMap", "SwampCompass", "SwampSmallKey:1", "SwampBigKey", "SwampStrayFairy:15", "OdolwaRemains"],
        ["SnowMap", "SnowCompass", "SnowSmallKey:3", "SnowBigKey", "SnowStrayFairy:15", "GohtRemains"],
        ["OceanMap", "OceanCompass", "OceanSmallKey:1", "OceanBigKey", "OceanStrayFairy:15", "GyorgRemains"],
        ["StoneMap", "StoneCompass", "StoneSmallKey:4", "StoneBigKey", "StoneStrayFairy:15", "TwinmoldRemains"],
    ],
    quests: [
        ["MoonsTear", "LandDeed", "SwampDeed", "MountainDeed", "OceanDeed"],
        ["RoomKey", "LetterToKafei", "PendantOfMemories", "LetterToMama", "HeartPieces:52", "HeartContainer:4"],
        ["BombersNotebook", "NoteNumOne:5", "NoteNumTwo:5", "NoteNumThree:5", "NoteNumFour:5", "NoteNumFive:5"],
        ["Ocarina", "SongOfTime", "SongOfHealing", "SongOfSoaring", "EponasSong", "SongOfStorms"],
        ["SonataOfAwakening", "GoronLullaby:2", "NewWaveBossaNova", "ElegyOfEmptiness", "OathToOrder", "ScarecrowSong"],
    ],
};
// GoronLullaby: 0 none, 1 Intro, 2 Full

function buildGrid(rows) {
    const layout = [], state = {}, max = {};
    for (const row of rows) {
        layout.push(row.map((entry) => {
            const [name, limit] = entry.split(":");
            state[name] = limit ? 0 : false;
            if (limit) max[name] = Number(limit);
            return name;
        }));
    }
    return { layout, state, max };
}

var GRIDS_DATA = Object.fromEntries(Object.entries(GRID_SPECS).map(([k, rows]) => [k, buildGrid(rows)]));

// Live tracker state (checks.js reads these) and counter limits
var items = GRIDS_DATA.items.state,         itemsMax = GRIDS_DATA.items.max;
var masks = GRIDS_DATA.masks.state;
var dungeons = GRIDS_DATA.dungeons.state,   dungeonMax = GRIDS_DATA.dungeons.max;
var quests = GRIDS_DATA.quests.state,       questMax = GRIDS_DATA.quests.max;

/* How counters are drawn: a clean base picture (images/<file>.png) plus overlaid text.
   Items not listed here use images/<Name>.png (on/off) or images/<Name><value>.png (tiers). */
var BASE_IMAGE = {
    Bow: "Bow0", Bomb: "Bomb0", EmptyBottle: "Bottle", ZoraEgg: "ZoraEgg", HeartContainer: "HeartContainer0",
    HeartPieces: "HeartPieces0", GoronLullaby: "GoronLullaby",
    SwampSkulltulas: "SwampSkulltulas0", OceanSkulltulas: "OceanSkulltulas0",
    SwampStrayFairy: "SwampStrayFairy0", SnowStrayFairy: "SnowStrayFairy0",
    OceanStrayFairy: "OceanStrayFairy0", StoneStrayFairy: "StoneStrayFairy0",
    SwampSmallKey: "SwampSmallKey0", SnowSmallKey: "SnowSmallKey0",
    OceanSmallKey: "OceanSmallKey0", StoneSmallKey: "StoneSmallKey0",
};
// Upgrade tiers show their capacity instead of the tier number ("" = nothing at tier 0)
var TIER_TEXT = { Bow: ["", "30", "40", "50"], Bomb: ["", "20", "30", "40"], GoronLullaby: ["", "Intro", "Full"] };

/* Logic options. Key = flag read by checks.js (`logic.<flag>`).
   saved   = key in saved data (old names kept so existing saves still load)
   setting = name of the matching setting in the randomizer's spoiler log (none = not in the log)
   select  = drives a dropdown holding 1-4 (bosses required, default 4) instead of an on/off switch */
var LOGIC_OPTIONS = {
    // Major items
    maininvlogic: { saved: "maininv", setting: "Shuffle Main Inventory" },
    maskslogic: { saved: "mask", setting: "Shuffle Masks" },
    transformmasklogic: { saved: "tmask", setting: "Shuffle Transformation" },
    ocarinalogic: { saved: "ocashuffle", setting: "Start With Ocarina" },
    piecelogic: { saved: "piece", setting: "Shuffle Piece of Heart" },
    songslogic: { saved: "songs", setting: "Shuffle Songs" },
    soaringlogic: { saved: "soaring", setting: "Shuffle Song of Soaring" },
    songtimelogic: { saved: "songtime", setting: "Start With Song of Time" },
    skullslogic: { saved: "skulls", setting: "Tokensanity" },
    shopsanitylogic: { saved: "shopsanity", setting: "Shopsanity" },
    greatfairylogic: { saved: "gfairy", setting: "Shuffle Fairy Rewards" },
    // Side quest items
    scrubtradelogic: { saved: "scrubtrade", setting: "Shuffle Scrub Trades" },
    anjulogic: { saved: "anju", setting: "Shuffle Anju and Kafei" },
    tinglelogic: { saved: "tingle", setting: "Shuffle Tingle Maps" },
    notebooklogic: { saved: "notebook", setting: "Shuffle Notebook" },
    cowlogic: { saved: "cow", setting: "Shuffle Cows" },
    beanslogic: { saved: "beans", setting: "Shuffle Magic Beans" },
    scrubpurchaselogic: { saved: "scrubpurchase", setting: "Shuffle Scrub Purchases" },
    extraminigameslogic: { saved: "extraminigames", setting: "Extra Minigames" },
    extracheckslogic: { saved: "extrachecks", setting: "Extra Checks" },
    moonitemlogic: { saved: "moonitem", setting: "Shuffle Moon Items" },
    deitylogic: { saved: "deity", setting: "Shuffle Fierce Deity" },
    // Dungeon items
    mapslogic: { saved: "mapscompass", setting: "Maps/Compasses" },
    smallkeylogic: { saved: "skey", setting: "Small Keys" },
    bigkeylogic: { saved: "bkey", setting: "Boss Keys" },
    straylogic: { saved: "stray", setting: "Stray Fairies" },
    townstraylogic: { saved: "townstray", setting: "Clock Town Stray Fairy" },
    remainslogic: { saved: "bosses", setting: "Dungeon Rewards" },
    containerlogic: { saved: "containers", setting: "Heart Containers" },
    moonrequirementslogic: { saved: "moonrequirements", setting: "Moon Requirements", select: true },
    majorarequirementslogic: { saved: "majorarequirements", setting: "Majora Requirements", select: true },
    // Not in the spoiler log
    eggslogic: { saved: "eggs" },
    skipbombers: { saved: "skipnotebook" },
};
