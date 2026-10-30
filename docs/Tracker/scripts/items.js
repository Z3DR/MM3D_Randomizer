var defaultItemGrid = [
    [
        "Sword",
        "Shield",
        "Bow",
        "FireArrow",
        "IceArrow",
        "LightArrow",
    ],
    [
        "Magic",
        "Bomb",
        "Bombchu",
        "DekuStick",
        "DekuNut",
        "MagicBean",
    ],
    [
        "Wallet",
        "PowderKeg",
        "PictographBox",
        "LensOfTruth",
        "Hookshot",
        "GreatFairySword",
    ],
    [
        "RedPotion",
        "GoldDust",
        "Milk",
        "ChateauRomani",
        "MysteryMilk",
        "EmptyBottle",
    ],
];

var defaultMaskGrid = [
    [
        "PostmanHat",
        "AllNightMask",
        "BlastMask",
        "StoneMask",
        "GreatFairyMask",
        "DekuMask",
    ],
    [
        "KeatonMask",
        "BremenMask",
        "BunnyHood",
        "DonGeroMask",
        "MaskOfScents",
        "GoronMask",
    ],
    [
        "RomaniMask",
        "TroupeLeaderMask",
        "KafeiMask",
        "CouplesMask",
        "MaskOfTruth",
        "ZoraMask"
    ],
    [
        "KamaroMask",
        "GibdoMask",
        "GaroMask",
        "CaptainsHat",
        "GiantsMask",
        "FierceDeityMask",
    ],

];

var defaultDungeonGrid = [
    [
        "SwampSkulltulas",
        "OceanSkulltulas",
        "TownStrayFairy",
        "Seahorse",
        "ZoraEgg",
    ],
    [
        "SwampMap",
        "SwampCompass",
        "SwampSmallKey",
        "SwampBigKey",
        "SwampStrayFairy",
        "OdolwaRemains",
    ],
    [
        "SnowMap",
        "SnowCompass",
        "SnowSmallKey",
        "SnowBigKey",
        "SnowStrayFairy",
        "GohtRemains",
    ],
    [
        "OceanMap",
        "OceanCompass",
        "OceanSmallKey",
        "OceanBigKey",
        "OceanStrayFairy",
        "GyorgRemains",
    ],
    [
        "StoneMap",
        "StoneCompass",
        "StoneSmallKey",
        "StoneBigKey",
        "StoneStrayFairy",
        "TwinmoldRemains",
    ],
];

var defaultQuestGrid = [
    [
        "MoonsTear",
        "LandDeed",
        "SwampDeed",
        "MountainDeed",
        "OceanDeed",
    ],
    [
        "RoomKey",   
        "LetterToKafei",
        "PendantOfMemories",
        "LetterToMama",
        "HeartPieces",
        "HeartContainer",
    ],
    [
        "BombersNotebook",
        "NoteNumOne",
        "NoteNumTwo",
        "NoteNumThree",
        "NoteNumFour",
        "NoteNumFive",
    ],
    [
        "Ocarina",
        "SongOfTime",
        "SongOfHealing",
        "SongOfSoaring",
        "EponasSong",
        "SongOfStorms",
    ],
    [
        "SonataOfAwakening",
        "GoronLullaby",
        "NewWaveBossaNova",
        "ElegyOfEmptiness",
        "OathToOrder",
        "ScarecrowSong",
    ]
];

var baseItems = {
    Bow: 0,
    FireArrow: false,
    IceArrow: false,
    LightArrow: false,

    Bomb: 0,
    Bombchu: false,
    DekuStick: false,
    DekuNut: false,
    MagicBean: false,

    PowderKeg: false,
    PictographBox: false,
    LensOfTruth: false,
    Hookshot: false,
    GreatFairySword: false,

    RedPotion: false,
    GoldDust: false,
    Milk: false,
    ChateauRomani: false,
    MysteryMilk: false,
    EmptyBottle: 0,

    Sword: 0,
    Shield: 0,
    Magic: 0,
    Wallet: 0,

    blank: false,
};

var baseMasks = {
    PostmanHat: false,
    AllNightMask: false,
    BlastMask: false,
    StoneMask: false,
    GreatFairyMask: false,
    DekuMask: false,

    KeatonMask: false,
    BremenMask: false,
    BunnyHood: false,
    DonGeroMask: false,
    MaskOfScents: false,
    GoronMask: false,

    RomaniMask: false,
    TroupeLeaderMask: false,
    KafeiMask: false,
    CouplesMask: false,
    MaskOfTruth: false,
    ZoraMask: false,

    KamaroMask: false,
    GibdoMask: false,
    GaroMask: false,
    CaptainsHat: false,
    GiantsMask: false,
    FierceDeityMask: false,
    blank: false,
};

var baseDungeons = {
    SwampSkulltulas: 0,
    OceanSkulltulas: 0,
    TownStrayFairy: false,
    Seahorse: false,
    ZoraEgg: 0,
    
    SwampMap: false,
    SwampCompass: false,
    SwampSmallKey: 0,
    SwampBigKey: false,
    SwampStrayFairy: 0,
    OdolwaRemains: false,

    SnowMap: false,
    SnowCompass: false,
    SnowSmallKey: 0,
    SnowBigKey: false,
    SnowStrayFairy: 0,
    GohtRemains: false,

    OceanMap: false,
    OceanCompass: false,
    OceanSmallKey: 0,
    OceanBigKey: false,
    OceanStrayFairy: 0,
    GyorgRemains: false,

    StoneMap: false,
    StoneCompass: false,
    StoneSmallKey: 0,
    StoneBigKey: false,
    StoneStrayFairy: 0,
    TwinmoldRemains: false,

    blank: false,
};

var baseQuests = {
    MoonsTear: false,
    LandDeed: false,
    SwampDeed: false,
    MountainDeed: false,
    OceanDeed: false,

    RoomKey: false,
    LetterToKafei: false,
    PendantOfMemories: false,
    LetterToMama: false,
    HeartPieces: 0,
    HeartContainer: 0,

    BombersNotebook: false,
    NoteNumOne: 0,
    NoteNumTwo: 0,
    NoteNumThree: 0,
    NoteNumFour: 0,
    NoteNumFive: 0,

    Ocarina: false,
    SongOfTime: true,
    SongOfHealing: false,
    SongOfSoaring: false,
    EponasSong: false,
    SongOfStorms: false,
    
    SonataOfAwakening: false,
    GoronLullaby: false,
    NewWaveBossaNova: false,
    ElegyOfEmptiness: false,
    OathToOrder: false,
    ScarecrowSong: true,
    blank: false,
};

var itemsMin = {
    Bow: 0,
    Bomb: 0,
    EmptyBottle: 0,
    Wallet: 0,
    Sword: 0,
    Magic: 0,
    Shield: 0,
};

var dungeonMin = {
    ZoraEgg: 0,
    SwampSkulltulas: 0,
    OceanSkulltulas: 0,
    SwampStrayFairy: 0,
    SnowStrayFairy: 0,
    OceanStrayFairy: 0,
    StoneStrayFairy: 0,
    SwampSmallKey: 0,
    SnowSmallKey: 0,
    OceanSmallKey: 0,
    StoneSmallKey: 0,
};

var questMin = {
    HeartPieces: 0,
    HeartContainer: 0,
    NoteNumOne: 0,
    NoteNumTwo: 0,
    NoteNumThree: 0,
    NoteNumFour: 0,
    NoteNumFive: 0,
};

var itemsMax = {
    Bow: 3,
    Bomb: 3,
    EmptyBottle: 2,
    Wallet: 3,
    Sword: 3,
    Magic: 2,
    Shield: 2,
};

var dungeonMax = {
    ZoraEgg: 7,
    SwampSkulltulas: 30,
    OceanSkulltulas: 30,
    SwampStrayFairy: 15,
    SnowStrayFairy: 15,
    OceanStrayFairy: 15,
    StoneStrayFairy: 15,
    SwampSmallKey: 1,
    SnowSmallKey: 3,
    OceanSmallKey: 1,
    StoneSmallKey: 4,
};


var questMax = {
    HeartPieces: 52,
    HeartContainer: 4,
    NoteNumOne: 5,
    NoteNumTwo: 5,
    NoteNumThree: 5,
    NoteNumFour: 5,
    NoteNumFive: 5,
};

var items = Object.assign(baseItems);
var masks = Object.assign(baseMasks);
var dungeons = Object.assign(baseDungeons);
var quests = Object.assign(baseQuests);