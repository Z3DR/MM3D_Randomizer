/*eslint strict: ["error", "never"]*/
function generalCanGetCheck(checklist) {
    let total = 0, open = 0, canGet = 0;
    for (const key in checklist) {
        if (!checklist.hasOwnProperty(key)) continue;
        const c = checklist[key];
        if (!c.isLogic()) continue;          // not randomized: ignore
        total++;
        if (c.isOpened) { open++; continue; }
        if (c.isAvailable()) canGet++;
    }
    if (total === 0) return "hidden";        // nothing randomized here
    const remaining = total - open;
    if (remaining === 0) return "opened";
    if (canGet === remaining) return "available";
    if (canGet === 0) return "unavailable";
    return "possible";
}

function canPlay(song) {
    return (song && quests.Ocarina);
}

function Fighting(){
    return (items.Sword >= 1 || masks.GoronMask || masks.ZoraMask || items.GreatFairySword); 
}

function HasBottle() {
    return (items.RedPotion || items.GoldDust || items.Milk || items.ChateauRomani || items.MysteryMilk || (items.EmptyBottle >= 1));
}

function HasRangeAttack() {
    return ((masks.DekuMask && items.Magic >=1) || masks.ZoraMask || (items.Bow >=1) || items.Hookshot);
}

function HasExplosives() {
    return items.Bomb >= 1 || masks.BlastMask;
}

function CanUse(item) {
    if (item == items.LensOfTruth) { return (items.LensOfTruth && items.Magic >= 1); }
    else if (item == masks.GiantsMask) { return (masks.GiantsMask && items.Magic >= 1); }
    else if (item == items.FireArrow) { return (items.FireArrow && items.Magic >= 1 && items.Bow >= 1);}
    else if (item == items.IceArrow) { return (items.IceArrow && items.Magic >= 1 && items.Bow >= 1);}
    else if (item == items.LightArrow) { return (items.LightArrow && items.Magic >= 1 && items.Bow >= 1);}
    else { return item;}
}

function CanGetToDekuPalace() {
    return masks.DekuMask && (HasBottle() || HasRangeAttack());
}

function WoodfallClear() {
    return (items.Bow >= 1 && dungeons.SwampSmallKey >=1 && dungeons.SwampBigKey && Fighting() && masks.DekuMask && canPlay(quests.SonataOfAwakening));
}

function SnowheadClear() {
    return (items.Bow >= 1 && masks.GoronMask && dungeons.SnowSmallKey >= 3 && items.FireArrow && items.Magic >= 1 && HasExplosives() && canPlay(quests.GoronLullaby) && dungeons.SnowBigKey && Fighting() && items.LensOfTruth);
}

function BayClear() {
    return (items.Bow >= 1 && masks.ZoraMask && dungeons.OceanSmallKey >= 1 && dungeons.OceanBigKey && items.IceArrow && items.Magic >= 1 && canPlay(quests.NewWaveBossaNova) && Fighting() && canPlay(quests.EponasSong) && items.Hookshot);
}

function StoneClear() {
    return (EnterStoneTower() && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 4 && dungeons.StoneBigKey && CanUse(masks.GiantsMask));
}

function EnterWoodfallTemple() {
    return (canPlay(quests.SonataOfAwakening) && masks.DekuMask && HasRangeAttack() && Fighting());
}

function EnterSnowheadTemple() {
    return (canPlay(quests.GoronLullaby) && masks.GoronMask && CanUse(items.LensOfTruth));
}

function EnterGreatBayTemple() {
    return (canPlay(quests.EponasSong) && items.Hookshot && masks.ZoraMask && dungeons.ZoraEgg >= 7 && items.Magic >= 1);
}

function EnterIkana() {
    return (canPlay(quests.EponasSong) && (masks.GaroMask || masks.GibdoMask) && items.Hookshot && CanUse(items.IceArrow));
}

function EnterStoneTower() {
    return (EnterIkana() && masks.DekuMask && masks.ZoraMask && masks.GoronMask && canPlay(quests.ElegyOfEmptiness));
}

function EnterMoon() {
    return canPlay(quests.OathToOrder) && (RemainsCount() >= logic.moonrequirementslogic);
}

function RemainsCount() {
    return (dungeons.OdolwaRemains ? 1 : 0) + (dungeons.GohtRemains ? 1 : 0) + (dungeons.GyorgRemains ? 1 : 0) + (dungeons.TwinmoldRemains ? 1 : 0);
}

function CanFaceMajora() {
    return canPlay(quests.OathToOrder) && (RemainsCount() >= logic.majorarequirementslogic);
}


function TotalMasks(total) {
    var TotalMasks = 0;
    if (masks.KeatonMask)       {TotalMasks++;}
    if (masks.BunnyHood)        {TotalMasks++;}
    if (masks.PostmanHat)       {TotalMasks++;}
    if (masks.AllNightMask)     {TotalMasks++;}
    if (masks.BlastMask)        {TotalMasks++;}
    if (masks.StoneMask)        {TotalMasks++;}
    if (masks.GreatFairyMask)   {TotalMasks++;}
    if (masks.BremenMask)       {TotalMasks++;}
    if (masks.DonGeroMask)      {TotalMasks++;}
    if (masks.MaskOfScents)     {TotalMasks++;}
    if (masks.RomaniMask)       {TotalMasks++;}
    if (masks.TroupeLeaderMask) {TotalMasks++;}
    if (masks.KafeiMask)        {TotalMasks++;}
    if (masks.CouplesMask)      {TotalMasks++;}
    if (masks.MaskOfTruth)      {TotalMasks++;}
    if (masks.KamaroMask)       {TotalMasks++;}
    if (masks.GibdoMask)        {TotalMasks++;}
    if (masks.GaroMask)         {TotalMasks++;}
    if (masks.CaptainsHat)      {TotalMasks++;}
    if (masks.GiantsMask)        {TotalMasks++;}
    if (masks.FierceDeityMask)  {TotalMasks++;}
    
    if (TotalMasks >= total) {return true;}
    return false;
}

var areas = [
    {
        name: "North Clock Town",
        x: "50.0%",
        y: "45.0%",
        checklist: {
            'Keaton Quiz': { 
                isAvailable: function() { return masks.KeatonMask;}, 
                isLogic: function() { return logic.piecelogic;}, 
            },
            'Tree HP': { 
                isAvailable: function() { return logic.piecelogic;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Old Lady': { 
                isAvailable: function() { return Fighting();},
                isLogic: function() { return logic.maskslogic;},
            },
            'Tingle Clock Town Map': { 
                isAvailable: function() {return logic.tinglelogic;},
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Woodfall Map': { 
                isAvailable: function() {return logic.tinglelogic;},
                isLogic: function() { return logic.tinglelogic;},
            },
            'Postbox': { 
                isAvailable: function() {return masks.PostmanHat;},
                isLogic: function() { return logic.piecelogic;},
            },
            'Clock Town Fairy (Deku)': { 
                isAvailable: function() { return masks.DekuMask && dungeons.TownStrayFairy;},
                isLogic: function() { return logic.greatfairylogic;}, 
            },
            'Clock Town Fairy (Human)': { 
                isAvailable: function() { return dungeons.TownStrayFairy;},
                isLogic: function() { return logic.greatfairylogic;}, 
            },
            'Deku Playground Day 1': { 
                isAvailable: function() {return masks.DekuMask;},
                isLogic: function() { return logic.extraminigameslogic;},
            },
            'Deku Playground Day 2': { 
                isAvailable: function() {return masks.DekuMask;},
                isLogic: function() { return logic.extraminigameslogic;},
            },
            'Deku Playground Day 3': { 
                isAvailable: function() {return masks.DekuMask;},
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "East Clock Town",
        x: "53%",
        y: "50%",
        checklist: {
            'Chest': {
                isAvailable: function() {return true;},
                isLogic: function() {return true;},
            },
            'Postbox': {
                isAvailable: function() {return masks.PostmanHat;},
                isLogic: function() {return logic.piecelogic;},
            },
            'Postman Freedom': {
                isAvailable: function() {return quests.LetterToMama;},
                isLogic: function() {return logic.anjulogic;},
            },
            'Gorman at Bar': {
                isAvailable: function() {return masks.RomaniMask && masks.DekuMask && masks.GoronMask && masks.ZoraMask && quests.Ocarina;},
                isLogic: function() {return logic.piecelogic;},
            },
            'Aroma at Bar': {
                isAvailable: function() {return quests.LetterToMama && masks.KafeiMask;},
                isLogic: function() {return logic.maskslogic;},
            },
            'Milk Bar Milk Purchase': {
                isAvailable: function() {return true;},
                isLogic: function() {return logic.shopsanitylogic;},
            },
            'Milk Bar Chateau Purchase': {
                isAvailable: function() {return true;},
                isLogic: function() {return logic.shopsanitylogic;},
            },
            'Honey and Darling Day 1': {
                isAvailable: function() {return items.Bomb >=1;},
                isLogic: function() {return logic.extraminigameslogic;},
            },
            'Honey and Darling Day 2': {
                isAvailable: function() {return items.Bomb >=1;},
                isLogic: function() {return logic.extraminigameslogic;},
            },
            'Honey and Darling Day 3)': {
                isAvailable: function() {return ((items.Bow >= 1) && (items.Bomb >= 1));},
                isLogic: function() {return logic.piecelogic;},
            },
            'Treasure Chest Game (Goron)': {
                isAvailable: function() {return masks.GoronMask;},
                isLogic: function() {return logic.piecelogic;},
            },
            'Treasure Chest Game (Zora)': {
                isAvailable: function() {return masks.ZoraMask;},
                isLogic: function() {return logic.extraminigameslogic;},
            },
            'Treasure Chest Game (Deku)': {
                isAvailable: function() {return masks.DekuMask;},
                isLogic: function() {return logic.extraminigameslogic;},
            },
            'Treasure Chest Game (Human)': {
                isAvailable: function() {return true;},
                isLogic: function() {return logic.extraminigameslogic;},
            },
            'Archery 1': {
                isAvailable: function() {return items.Bow >=1;},
                isLogic: function() {return logic.maininvlogic;},
            },
            'Archery 2': {
                isAvailable: function() {return items.Bow >=1;},
                isLogic: function() {return logic.piecelogic;},
            },
            'Mayor Reward': {
                isAvailable: function() {return masks.CouplesMask;},
                isLogic: function() {return logic.piecelogic;},
            },
            'Aroma in Office': {
                isAvailable: function() {return true;},
                isLogic: function() {return logic.maskslogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "StockPotInn",
        x: "53%",
        y: "45%",
        checklist: {
            'Reservation': { 
                isAvailable: function() { return masks.GoronMask;},
                isLogic: function() { return logic.anjulogic;}, 
            },
            'Toilet Hand': { 
                isAvailable: function() { return (quests.LetterToMama || quests.LetterToKafei || quests.LandDeed || quests.SwampDeed || quests.MountainDeed || quests.OceanDeed);},
                isLogic: function() { return logic.piecelogic;},
            },
            'Guest Room Chest': { 
                isAvailable: function() { return quests.RoomKey;}, 
                isLogic: function() { return logic.anjulogic;},
            },
            'Staff Room Chest': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return true;},
            },
            'Midnight Meeting': { 
                isAvailable: function() { return masks.KafeiMask && (masks.DekuMask || quests.RoomKey);}, 
                isLogic: function() { return logic.anjulogic;},
            },
            'Anju and Kafei': { 
                isAvailable: function() { return masks.KafeiMask && quests.LetterToKafei && quests.PendantOfMemories && canPlay(quests.EponasSong) && (masks.GaroMask || masks.GibdoMask) && items.Hookshot && Fighting();}, 
                isLogic: function() { return logic.anjulogic;},
            },
            'Grandma Short Story': { 
                isAvailable: function() { return masks.AllNightMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Grandma Long Story': { 
                isAvailable: function() { return masks.AllNightMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "West Clock Town",
        x: "47%",
        y: "50%",
        checklist: {
            'Rosa Sisters': { 
                isAvailable: function() { return masks.KamaroMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Swordsman School': { 
                isAvailable: function() { return items.Sword >= 1;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Postman Game': { 
                isAvailable: function() { return masks.BunnyHood;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'All Night Mask': { 
                isAvailable: function() { return items.Wallet >= 3;}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Lottery Day 1': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Lottery Day 2': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Lottery Day 3': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Bomb Shop Item 1': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Bomb Shop Item 2': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Bomb Bag': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Big Bomb Bag': { 
                isAvailable: function() { return Fighting();}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 1': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 2': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 3': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 4': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 5': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 6': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 7': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Trading Post Item 8': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
        },
        isBeatable: function() {
           return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "South Clock Town",
        x: "50%",
        y: "55%",
        checklist: {
            'Scrub Trade': { 
                isAvailable: function() { return logic.scrubtradelogic && quests.MoonsTear;}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Scrub Purchase': { 
                isAvailable: function() { return quests.LandDeed && quests.MoonsTear;}, 
                isLogic: function() { return logic.scrubpurchaselogic;},
            },
            'Postbox': { 
                isAvailable: function() { return masks.PostmanHat;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Clock Tower HP': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Straw Roof Chest': { 
                isAvailable: function() { return items.Hookshot || (masks.DekuMask && quests.MoonsTear);}, 
                isLogic: function() { return true;},
            },
            'Final Day Chest': { 
                isAvailable: function() { return items.Hookshot || (masks.DekuMask && quests.MoonsTear);}, 
                isLogic: function() { return true;},
            },
            'Bank 1': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Bank 2': { 
                isAvailable: function() { return items.Wallet >=2;}, 
                isLogic: function() { return true;},
            },
            'Bank 3': { 
                isAvailable: function() { return items.Wallet >=3;}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Clock Tower",
        x: "50%",
        y: "50%",
        checklist: {
            'Song of Healing': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Deku Mask': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.transformmasklogic;},
            },
            'Bombers Notebook': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.notebooklogic;},
            },
            'Ocarina of Time': {
                isAvailable: function() { return HasRangeAttack();},
                isLogic: function() { return logic.ocarinalogic;},
            },
            'Song of Time': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.songtimelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Laundry Pool",
        x: "47%",
        y: "55%",
        checklist: {
            'Keaton Mask': { 
                isAvailable: function() { return quests.LetterToKafei;}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Letter to Mama': { 
                isAvailable: function() { return quests.LetterToKafei;}, 
                isLogic: function() { return logic.anjulogic;},
            },
            'Guru Guru': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Stray Fairy': {
                isAvailable: function() { return true;},
                isLogic: function() { return logic.townstraylogic;},
            },
            'Pendant of Memories': { 
                isAvailable: function() { return quests.LetterToKafei;}, 
                isLogic: function() { return logic.anjulogic;},
            },

        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Termina Field",
        x: "53%",
        y: "55%",
        checklist: {
            'Kamaro': { 
                isAvailable: function() { return canPlay(quests.SongOfHealing);}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Underwater Chest': { 
                isAvailable: function() { return masks.ZoraMask;}, 
                isLogic: function() { return true;},
            },
            'Grass Chest': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return true;},
            },
            'Stump Chest': { 
                isAvailable: function() { return items.Hookshot || (items.MagicBean && HasBottle());}, 
                isLogic: function() { return true;},
            },
            'Moons Tear': { 
                isAvailable: function() { return masks.DekuMask || (quests.BombersNotebook && HasRangeAttack());}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Peahat Grotto Chest': { 
                isAvailable: function() { return Fighting();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Dodongo Grotto Chest': { 
                isAvailable: function() { return Fighting();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'BioBaba Grotto HP': { 
                isAvailable: function() { return masks.ZoraMask && (items.Bomb >=1 || masks.GoronMask);}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Pillar Grotto Chest': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return true;},
            },
            'Grass Grotto Chest': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return true;},
            },
            'Business Scrub': { 
                isAvailable: function() { return items.Wallet >=2 && masks.DekuMask || (quests.BombersNotebook && HasRangeAttack());}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Colored Gossip Stones': { 
                isAvailable: function() { return (items.Bomb >=1 || masks.GoronMask) && ((quests.SonataOfAwakening && masks.DekuMask) || (quests.GoronLullaby && masks.GoronMask) || (quests.NewWaveBossaNova && masks.ZoraMask))  ;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Grotto Cow 1': { 
                isAvailable: function() { return items.Bomb >= 1 && HasBottle() && canPlay(quests.EponasSong);},
                isLogic: function() { return logic.cowlogic;},
            },
            'Grotto Cow 2': { 
                isAvailable: function() { return items.Bomb >= 1 && HasBottle() && canPlay(quests.EponasSong);}, 
                isLogic: function() { return logic.cowlogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Road to Southern Swamp",
        x: "50%",
        y: "60%",
        checklist: {
            'Tree HP': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Tingle Woodfall Map': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Snowhead Map': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Swamp Archery 1': { 
                isAvailable: function() { return items.Bow >= 1;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Swamp Archery 2': { 
                isAvailable: function() { return (items.Bow >=1);}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Grotto Chest': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Southern Swamp",
        x: "50%",
        y: "65%",
        checklist: {
            'Scrub Trade': { 
                isAvailable: function() { return quests.LandDeed;}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Scrub Purchase': { 
                isAvailable: function() { return masks.DekuMask;}, 
                isLogic: function() { return logic.scrubpurchaselogic;},
            },
            'Song of Soaring': { 
                isAvailable: function() { return quests.Ocarina;}, 
                isLogic: function() { return logic.soaringlogic;},
            },
            'Tourist Center Roof': { 
                isAvailable: function() { return masks.DekuMask && quests.LandDeed;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Koume': { 
                isAvailable: function() { return HasBottle();}, 
                isLogic: function() { return true;},
            },
            'Pictograph Winner': { 
                isAvailable: function() { return items.PictographBox;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Boat Archery': { 
                isAvailable: function() { return WoodfallClear() && HasBottle();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Kotake': { 
                isAvailable: function() { return true;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Mushroom Sale': { 
                isAvailable: function() { return HasBottle() && masks.MaskOfScents;}, 
                isLogic: function() { return true;},
            },
            'Spider House Grotto Chest': { 
                isAvailable: function() { return masks.DekuMask && (HasBottle() || (items.Bow >= 1) || masks.ZoraMask || items.Hookshot || WoodfallClear());}, 
                isLogic: function() { return true;},
            },
            'Potion Shop Item 1': {
                isAvailable: function() { return HasBottle();},
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Potion Shop Item 2': {
                isAvailable: function() { return HasBottle();},
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Potion Shop Item 3': {
                isAvailable: function() { return HasBottle() && masks.MaskOfScents;},
                isLogic: function() { return logic.shopsanitylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Deku Palace",
        x: "55%",
        y: "65%",
        checklist: {
            'West Garden HP': { 
                isAvailable: function() { return CanGetToDekuPalace();}, 
                isLogic: function() { return logic.piecelogic;},},
            'Imprisoned Monkey': { 
                isAvailable: function() { return CanGetToDekuPalace() && quests.Ocarina && items.MagicBean;}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Bean Seller': { 
                isAvailable: function() { return CanGetToDekuPalace();}, 
                isLogic: function() { return logic.beanslogic;},
            },
            'Bean Grotto Chest': { 
                isAvailable: function() { return CanGetToDekuPalace() && (items.Hookshot || HasBottle());}, 
                isLogic: function() { return true;},
            },
            'Butler Race': { 
                isAvailable: function() { return WoodfallClear() && HasBottle();}, 
                isLogic: function() { return logic.maskslogic;},
            },
        },
        isBeatable: function() {
          return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Woodfall",
        x: "50%",
        y: "70%",
        checklist: {
            'Entrance Chest': { 
                isAvailable: function() { return CanGetToDekuPalace();}, 
                isLogic: function() { return true;},
            },
            'Bridge Chest': { 
                isAvailable: function() { return CanGetToDekuPalace() && (Fighting() || HasRangeAttack());}, 
                isLogic: function() { return true;},
            },
            'Behind Owl Chest': { 
                isAvailable: function() { return CanGetToDekuPalace() && (Fighting() || HasRangeAttack());}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Mountain Village",
        x: "50%",
        y: "35%",
        checklist: {
            'Frog Choir': { 
                isAvailable: function() { return WoodfallClear() && SnowheadClear() && BayClear() && masks.DonGeroMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Hungry Goron': { 
                isAvailable: function() { return masks.GoronMask && items.Magic >= 1 && items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Waterfall Chest': { 
                isAvailable: function() { return SnowheadClear() && CanUse(items.LensOfTruth);}, 
                isLogic: function() { return true;},
            },
            'Darmani': { 
                isAvailable: function() { return CanUse(items.LensOfTruth) && canPlay(quests.SongOfHealing) && items.Bow >= 1 && HasExplosives();}, 
                isLogic: function() { return logic.transformmasklogic;},
            },
            'Smith Day 1': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && items.Wallet >=2 && items.Sword >= 1 && (CanUse(items.FireArrow) || SnowheadClear() || (HasBottle() && CanUse(items.LensOfTruth))) ;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Smith Day 2': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && items.GoldDust && items.Wallet >=2 && items.Sword >= 1 && ((CanUse(items.FireArrow)) || SnowheadClear() || (HasBottle() && CanUse(items.LensOfTruth)));}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Spring Water Grotto Chest': { 
                isAvailable: function() { return SnowheadClear();}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
           return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Twin Islands",
        x: "55%",
        y: "33%",
        checklist: {
            'Underwater Ramp Chest': { 
                isAvailable: function() { return SnowheadClear() && masks.ZoraMask;}, 
                isLogic: function() { return true;},
            },
            'Cave Chest': { 
                isAvailable: function() { return SnowheadClear() && masks.ZoraMask;}, 
                isLogic: function() { return true;},
            },
            'Lullaby Intro': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.GoronMask && (HasBottle() || CanUse(items.FireArrow));}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Tingle Snowhead Map': { 
                isAvailable: function() { return items.Bow >= 1 && HasExplosives();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Romani Ranch Map': { 
                isAvailable: function() { return items.Bow >= 1 && HasExplosives();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Goron Race': { 
                isAvailable: function() { return SnowheadClear();}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Racetrack Grotto Chest': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.MaskOfTruth && ((items.Hookshot && canPlay(quests.ScarecrowSong) || masks.GoronMask));}, 
                isLogic: function() { return true;},
            },
            'Hot Spring Water Grotto Chest': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && ((HasBottle() && CanUse(items.LensOfTruth)) || CanUse(items.FireArrow) || SnowheadClear());}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Goron Village",
        x: "60%",
        y: "25%",
        checklist: {
            'Powder Keg Challenge': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.GoronMask && (SnowheadClear() || CanUse(items.FireArrow));}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Scrub Purchase': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && items.Wallet >= 2 && masks.GoronMask && items.Bomb >= 2;}, 
                isLogic: function() { return logic.scrubpurchaselogic;},
            },
            'Scrub Trade': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.DekuMask && quests.SwampDeed;}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Ledge HP': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.DekuMask && quests.SwampDeed;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Lens Cave Chest': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && CanUse(items.LensOfTruth);}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Lens Cave Rock Chest': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return true;},
            },
            'Lens Cave Lens Chest': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return true;},
            },
            'Goron Lullaby': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives() && masks.GoronMask && ((HasBottle() && CanUse(items.LensOfTruth)) || CanUse(items.FireArrow));}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Goron Shop Item 1': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Goron Shop Item 2': { 
                isAvailable: function() { return items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Goron Shop Item 3': {
                isAvailable: function() { return items.Bow >=1 && HasExplosives();}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Milk Road",
        x: "43%",
        y: "55%",
        checklist: {
            'Tingle Milk Road Map': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Great Bay Map': { 
                isAvailable: function() { return HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Gorman Race': { 
                isAvailable: function() { return canPlay(quests.EponasSong);}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Mystery Milk': { 
                isAvailable: function() { return items.MysteryMilk && masks.TroupeLeaderMask;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Gorman Milk Buy': {
                isAvailable: function() { return HasBottle();},
                isLogic: function() { return logic.shopsanitylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Romani Ranch",
        x: "40%",
        y: "60%",
        checklist: {
            'Alien Defense': { 
                isAvailable: function() { return items.PowderKeg && masks.GoronMask && items.Bow >= 1;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Cremia Escort': { 
                isAvailable: function() { return items.PowderKeg && masks.GoronMask && items.Bow >= 1;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Romanis Game': { 
                isAvailable: function() { return items.PowderKeg && masks.GoronMask && items.Bow >= 1;}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Dog Race Winner': { 
                isAvailable: function() { return masks.MaskOfTruth;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Doggy Racetrack Chest': { 
                isAvailable: function() { return items.Hookshot;}, 
                isLogic: function() { return true;},
            },
            'Grogs Chickens': { 
                isAvailable: function() { return masks.BremenMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Barn Cow 1': { 
                isAvailable: function() { return HasBottle() && canPlay(quests.EponasSong) && items.PowderKeg && masks.GoronMask;}, 
                isLogic: function() { return logic.cowlogic;},
            },
            'Barn Cow 2': { 
                isAvailable: function() { return HasBottle() && canPlay(quests.EponasSong) && items.PowderKeg && masks.GoronMask;}, 
                isLogic: function() { return logic.cowlogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Great Bay Coast",
        x: "30%",
        y: "50%",
        checklist: {
            'Fisherman Game': { 
                isAvailable: function() { return BayClear();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Ledge HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && items.Hookshot && HasBottle() && items.MagicBean;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Mikau': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && canPlay(quests.SongOfHealing);}, 
                isLogic: function() { return logic.transformmasklogic;},
            },
            'Tingle Great Bay Map': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Stone Tower Map': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Baby Zoras': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && HasBottle() && dungeons.ZoraEgg >= 7;}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Lab Fish': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasBottle();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Grotto Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong);}, 
                isLogic: function() { return true;},
            },
            'Fisherman Photo': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.PictographBox;}, 
                isLogic: function() { return true;},
            },
            'Grotto Cow 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasBottle() && items.Hookshot;}, 
                isLogic: function() { return logic.cowlogic;},
            },
            'Grotto Cow 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasBottle() && items.Hookshot;}, 
                isLogic: function() { return logic.cowlogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: "Pinnacle Rock",
        x: "18%",
        y: "48%",
        checklist: {
            'Seahorse HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Upper Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Lower Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Zora Egg 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1 && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
            'Zora Egg 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1 && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
            'Zora Egg 3': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && dungeons.Seahorse && items.Magic >= 1 && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
        },
        isBeatable: function() {
           return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Zora Cape',
        x: "28%",
        y: "60%",
        checklist: {
            'Like Like HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Ledge Chest (No Tree)': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && items.Hookshot;}, 
                isLogic: function() { return true;},
            },
            'Ledge Chest (Tree)': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && items.Hookshot;}, 
                isLogic: function() { return true;},
            },
            'Underwater Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;},
                isLogic: function() { return true;},
            },
            'Beaver Race 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Hookshot && items.Magic >= 1;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Beaver Race 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Hookshot && items.Magic >= 1;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Grotto Chest': {
                isAvailable: function() { return canPlay(quests.EponasSong) && items.Hookshot && items.Magic >= 1 && (HasExplosives() || items.GoronMask);},
                isLogic: function() { return true;},
            },
            'Jars Minigame': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;},
                isLogic: function() { return logic.extracheckslogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Zora Hall',
        x: "25%",
        y: "59%",
        checklist: {
            'Evan HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Scrub Trade': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && quests.MountainDeed;}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Scrub Purchase': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;}, 
                isLogic: function() { return logic.scrubpurchaselogic;},
            },
            'Lulu Room HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && quests.MountainDeed;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Stage Lights': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask &&  CanUse(items.FireArrow);},
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Photo of Lulu (Bad)': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.PictographBox;},
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Photo of Lulu (Good)': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.PictographBox;},
                isLogic: function() { return logic.extracheckslogic;},
            },
            'Zora Shop Item 1': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;},
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Zora Shop Item 2': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;},
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Zora Shop Item 3': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask;},
                isLogic: function() { return logic.shopsanitylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Road To Ikana/Graveyard',
        x: "60%",
        y: "49%",
        checklist: {
            'Road to Ikana Pillar Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && items.Hookshot;}, 
                isLogic: function() { return true;},
            },
            'Road to Ikana Grotto Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.GoronMask;}, 
                isLogic: function() { return true;},
            },
            'Captain Keeta Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && canPlay(quests.SonataOfAwakening) && Fighting();}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Graveyard Grotto Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.MaskOfTruth;}, 
                isLogic: function() { return true;},
            },
            'Day 1 Grave Bats Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.CaptainsHat && Fighting();}, 
                isLogic: function() { return true;},
            },
            'Day 1 Grave Tablet': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.CaptainsHat && Fighting();}, 
                isLogic: function() { return logic.songslogic;},
            },
            'Day 2 Iron Knuckle Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.CaptainsHat && Fighting();}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Dampe Digging': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.CaptainsHat && Fighting();}, 
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Ikana Canyon',
        x: "70%",
        y: "48%",
        checklist: {
            'Ledge HP': { 
                isAvailable: function() { return EnterIkana() && quests.OceanDeed && masks.DekuMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Secret Shrine Grotto': { 
                isAvailable: function() { return EnterIkana() && masks.ZoraMask;}, 
                isLogic: function() { return true;},},

            'Scrub Trade': { 
                isAvailable: function() { return EnterIkana() && quests.OceanDeed;}, 
                isLogic: function() { return logic.scrubtradelogic;},
            },
            'Scrub Purchase': { 
                isAvailable: function() { return EnterIkana() && HasBottle() && items.Wallet >= 2;}, 
                isLogic: function() { return logic.shopsanitylogic;},
            },
            'Tingle Stone Tower Map': { 
                isAvailable: function() { return EnterIkana() && HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Tingle Clock Town Map': { 
                isAvailable: function() { return EnterIkana() && HasRangeAttack();}, 
                isLogic: function() { return logic.tinglelogic;},
            },
            'Pamelas Father': {
                isAvailable: function() { return EnterIkana() && quests.SongOfStorms && quests.SongOfHealing;},
                isLogic: function() { return logic.maskslogic;},
            },
            'Poe Hut HP': {
                isAvailable: function() { return EnterIkana() && Fighting() && items.Bow >= 1;},
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Secret Shrine',
        x: "70%",
        y: "40%",
        checklist: {
            'Dinolfos Chest': { 
                isAvailable: function() { return EnterIkana() && WoodfallClear() && CanUse(items.LightArrow);}, 
                isLogic: function() { return true;},
            },
            'Wizzrobe Chest': { 
                isAvailable: function() { return EnterIkana() && SnowheadClear() && CanUse(items.LightArrow);}, 
                isLogic: function() { return true;},
            },
            'Wart Chest': { 
                isAvailable: function() { return EnterIkana() && BayClear() && CanUse(items.LightArrow);}, 
                isLogic: function() { return true;},
            },
            'Garo Chest': { 
                isAvailable: function() { return EnterIkana() && StoneClear() && CanUse(items.LightArrow);}, 
                isLogic: function() { return true;},
            },
            'Final Chest': { 
                isAvailable: function() { return EnterIkana() && WoodfallClear() && SnowheadClear() && BayClear() && StoneClear() && CanUse(items.LightArrow);}, 
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Stone Tower',
        x: "80%",
        y: "42%",
        checklist: {
            'Left Inverted Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && items.MagicBean && (HasBottle() || canPlay(quests.SongOfStorms));}, 
                isLogic: function() { return true;},
            },
            'Center Inverted Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && items.MagicBean && (HasBottle() || canPlay(quests.SongOfStorms));}, 
                isLogic: function() { return true;},
            },
            'Right Inverted Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && items.MagicBean && (HasBottle() || canPlay(quests.SongOfStorms));}, 
                isLogic: function() { return true;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Woodfall Temple',
        x: "47%",
        y: "75%",
        checklist: {
            'Small Key Chest': { 
                isAvailable: function() { return EnterWoodfallTemple();}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Bow Chest': { 
                isAvailable: function() { return EnterWoodfallTemple() && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Boss Key Chest': { 
                isAvailable: function() { return EnterWoodfallTemple() && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.bigkeylogic;},
            },
            'Map Chest': { 
                isAvailable: function() { return EnterWoodfallTemple();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Compass Chest': { 
                isAvailable: function() { return EnterWoodfallTemple();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Heart Container': { 
                isAvailable: function() { return EnterWoodfallTemple() && dungeons.SwampSmallKey >= 1 && dungeons.SwampBigKey && items.Bow >= 1;}, 
                isLogic: function() { return logic.containerlogic;},
            },
            'Odolwa Remains': { 
                isAvailable: function() { return EnterWoodfallTemple() && dungeons.SwampSmallKey >= 1 && dungeons.SwampBigKey && items.Bow >= 1;}, 
                isLogic: function() { return logic.remainslogic;},
            },
            'Entrance Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Entrance Chest Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Main Room Bubble Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Main Room Jar Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Main Room Deku Baba Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Main Room Switch Stray Fairy': { 
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && (items.Hookshot || items.Bow >= 1);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Platform Room Beehive Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Bridge Room Beehive Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Bridge Room Skulltula Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Dark Room Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1 && (items.DekuStick || (items.Bow >= 1 && items.FireArrow));}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Dragonfly Room Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Lower Right Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Upper Left Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Upper Right Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Pillar Stray Fairy': {
                isAvailable: function() { return EnterWoodfallTemple() && masks.GreatFairyMask && dungeons.SwampSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Snowhead Temple',
        x: "46%",
        y: "19%",
        checklist: {
            'Bridge Room Frozen Chest': { 
                isAvailable: function() { return EnterSnowheadTemple() && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Map Chest': { 
                isAvailable: function() { return EnterSnowheadTemple();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Compass Chest': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Double Block Room Chest': { 
                isAvailable: function() { return EnterSnowheadTemple();}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Icicle Room Chest': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Fire Arrow Chest': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 2;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Boss Key Chest': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 3;}, 
                isLogic: function() { return logic.bigkeylogic;},
            },
            'Goht Remains': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 3 && dungeons.SnowBigKey && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.remainslogic;},
            },
            'Heart Container': { 
                isAvailable: function() { return EnterSnowheadTemple() && dungeons.SnowSmallKey >= 3 && dungeons.SnowBigKey && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.containerlogic;},
            },
            'Bridge Room Ledge Stray Fairy': { 
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Bridge Room Pillar Stray Fairy': { 
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack();}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Lower Map Room Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Upper Map Room Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Basement Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Compass Room Ice Puzzle Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && CanUse(items.FireArrow) && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Compass Room Crate': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Double Block Room Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && CanUse(items.FireArrow) && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Icicle Room Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && dungeons.SnowSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Switch Puzzle Ceiling Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && dungeons.SnowSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Main Room Wall Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && ((canPlay(quests.ScarecrowSong) && items.Hookshot) || dungeons.SnowSmallKey >= 3);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pillar Room Freezards Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Snow Room Stray Fairy': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && dungeons.SnowSmallKey >= 3;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Dinolfos Room Stray Fairy 1': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && Fighting() && dungeons.SnowSmallKey >= 3;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Dinolfos Room Stray Fairy 2': {
                isAvailable: function() { return EnterSnowheadTemple() && masks.GreatFairyMask && HasRangeAttack() && HasExplosives() && Fighting() && dungeons.SnowSmallKey >= 3;}, 
                isLogic: function() { return logic.straylogic;},
            },

        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Great Bay Temple',
        x: "10%",
        y: "55%",
        checklist: {
            'Map Chest': { 
                isAvailable: function() { return EnterGreatBayTemple();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Compass Chest': { 
                isAvailable: function() { return EnterGreatBayTemple();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Small Key Chest': { 
                isAvailable: function() { return EnterGreatBayTemple();}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Boss Key Chest': { 
                isAvailable: function() { return EnterGreatBayTemple() && CanUse(items.FireArrow) && dungeons.OceanSmallKey >= 1;}, 
                isLogic: function() { return logic.bigkeylogic;},
            },
            'Ice Arrow Chest': {
                isAvailable: function() { return EnterGreatBayTemple() && CanUse(items.FireArrow) && dungeons.OceanSmallKey >= 1;},
                isLogic: function() { return logic.maininvlogic;},
            },
            'Gyorg Remains': { 
                isAvailable: function() { return EnterGreatBayTemple() && CanUse(items.FireArrow) && CanUse(items.IceArrow) && dungeons.OceanSmallKey >= 1 && dungeons.OceanBigKey;}, 
                isLogic: function() { return logic.remainslogic;},
            },
            'Heart Container': { 
                isAvailable: function() { return EnterGreatBayTemple() && CanUse(items.FireArrow) && CanUse(items.IceArrow) && dungeons.OceanSmallKey >= 1 && dungeons.OceanBigKey;}, 
                isLogic: function() { return logic.containerlogic;},
            },
            'Entrance Torches Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Water Control Room Skulltula Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Water Control Room Underwater Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Whirlpool Jar Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Whirlpool Barrel Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Map Room Jar Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Bio Baba Chest Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Dexihand Jar Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Green Valve Room Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow);}, 
                isLogic: function() { return logic.straylogic;}, 
            },
            'Lower Waterwheel Room Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Upper Waterwheel Room Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Seesaw Room Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Seesaw Room Barrel Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Pre-Boss Room Underwater Stray Fairy': {
                isAvailable: function() { return EnterGreatBayTemple() && masks.GreatFairyMask && CanUse(items.IceArrow) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Stone Tower Temple',
        x: "84%",
        y: "42%",
        checklist: {
            'Map Chest': { 
                isAvailable: function() { return EnterStoneTower();}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Armos Room Chest': { 
                isAvailable: function() { return EnterStoneTower() && HasExplosives() && (items.Shield >= 2 || CanUse(items.LightArrow));}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Bridge Switch Chest': { 
                isAvailable: function() { return EnterStoneTower() && HasExplosives() && (items.Shield >= 2 || CanUse(items.LightArrow)) && dungeons.StoneSmallKey >= 1;}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Compass Chest': { 
                isAvailable: function() { return EnterStoneTower() && HasExplosives() && (items.Shield >= 2 || CanUse(items.LightArrow)) && dungeons.StoneSmallKey >= 1;}, 
                isLogic: function() { return logic.mapslogic;},
            },
            'Light Arrow Chest': { 
                isAvailable: function() { return EnterStoneTower() && HasExplosives() && (items.Shield >= 2 || CanUse(items.LightArrow)) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Inverted Updraft Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Death Armos Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 3;}, 
                isLogic: function() { return logic.smallkeylogic;},
            },
            'Big Key Chest': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 3;}, 
                isLogic: function() { return logic.bigkeylogic;},
            },
            'Twinmold Remains': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && (dungeons.StoneSmallKey >= 4) && dungeons.StoneBigKey && CanUse(masks.GiantsMask);}, 
                isLogic: function() { return logic.remainslogic;},
            },
            'Heart Container': { 
                isAvailable: function() { return EnterStoneTower() && CanUse(items.LightArrow) && (dungeons.StoneSmallKey >= 4) && dungeons.StoneBigKey && CanUse(masks.GiantsMask);},
                isLogic: function() { return logic.containerlogic;}, 
            },
            'Statue Eye Stray Fairy': { 
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Death Armos Switch Stray Fairy Chest': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 3;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Basement Ledge Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Bridge Crystal Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 1;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Underwater Chest Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Mirror Room Sun Block Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && (CanUse(items.LightArrow) || items.Shield >= 1) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Mirror Room Sun Switch Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && (CanUse(items.LightArrow) || items.Shield >= 1) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Lava Room Ledge Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Lava Room Fire Ring Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Thin Bridge Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 4;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Eyegore Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 2;}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Chest Infront of Boss Warp Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Updraft Room Frozen Eye Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Updraft Room Fire Ring Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow);}, 
                isLogic: function() { return logic.straylogic;},
            },
            'Wizzrobe Room Stray Fairy': {
                isAvailable: function() { return EnterStoneTower() && masks.GreatFairyMask && CanUse(items.LightArrow) && dungeons.StoneSmallKey >= 3;}, 
                isLogic: function() { return logic.straylogic;},
            },
            
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Pirate Fortress',
        x: "32%",
        y: "40%",
        checklist: {
            'Exterior Ledge Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Exterior Sand Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Exterior Corner Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Maze Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Cage Shallow Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Cage Deep Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Cage HP': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Interior Lower Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Hookshot && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Interior Upper Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && items.Hookshot && items.Magic >= 1;}, 
                isLogic: function() { return true;},
            },
            'Invisible Soldier': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && CanUse(items.LensOfTruth) && HasBottle();}, 
                isLogic: function() { return logic.maskslogic;},
            },
            'Hookshot Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Bow >= 1 && items.Magic >= 1;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Guard Room Chest': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Hookshot && items.Magic >= 1 && (HasRangeAttack() || masks.StoneMask);}, 
                isLogic: function() { return true;},
            },
            'Tank Chest': {
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Hookshot && items.Magic >= 1 && (HasRangeAttack() || masks.StoneMask);},
                isLogic: function() { return true;},
            },
            'Barrel Maze Zora Egg': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1 && items.Hookshot && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
            'Lava Room Zora Egg': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1 && items.Hookshot && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
            'Guard Room Zora Egg': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1 && items.Hookshot && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
            'Hookshot Room Zora Egg': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && masks.ZoraMask && masks.GoronMask && items.Magic >= 1 && items.Hookshot && HasBottle();}, 
                isLogic: function() { return logic.eggslogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Beneath The Well',
        x: "75%",
        y: "40%",
        checklist: {
            'Left Path Chest': { 
                isAvailable: function() { return EnterIkana() && HasBottle() && masks.GibdoMask && CanUse(items.LensOfTruth);}, 
                isLogic: function() { return true;},
            },
            'Right Path Chest': { 
                isAvailable: function() { return EnterIkana() && HasBottle() && masks.GibdoMask && CanUse(items.FireArrow);}, 
                isLogic: function() { return true;},
            },
            'Mirror Shield Chest': { 
                isAvailable: function() { return EnterIkana() && HasBottle() && masks.GibdoMask && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Cow': { 
                isAvailable: function() { return EnterIkana() && HasBottle() && masks.GibdoMask && items.DekuNut && items.MagicBean;}, 
                isLogic: function() { return logic.cowlogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Ikana Castle',
        x: "74%",
        y: "47%",
        checklist: {
            'Pillar HP': { 
                isAvailable: function() { return (canPlay(quests.EponasSong) && (masks.GaroMask || masks.GibdoMask) && items.Hookshot && (CanUse(items.IceArrow))) && ((HasBottle() && masks.GibdoMask && CanUse(items.FireArrow) && items.Shield >= 2) || CanUse(items.LightArrow)) && masks.DekuMask;}, 
                isLogic: function() { return logic.piecelogic;},
            },
            'Elegy of Emptiness': { 
                isAvailable: function() { return (canPlay(quests.EponasSong) && (masks.GaroMask || masks.GibdoMask) && items.Hookshot && (CanUse(items.IceArrow))) && ((HasBottle() && masks.GibdoMask && CanUse(items.FireArrow) && items.Shield >= 2) || CanUse(items.LightArrow)) && masks.DekuMask && items.PowderKeg && masks.GoronMask;}, 
                isLogic: function() { return logic.songslogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'The Moon',
        x: "20%",
        y: "20%",
        checklist: {
            'Deku Bonus HP': { 
                isAvailable: function() { return EnterMoon() && masks.DekuMask && TotalMasks(1) && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Goron Bonus HP': { 
                isAvailable: function() { return EnterMoon() && masks.GoronMask && TotalMasks(2) && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Zora Bonus HP': { 
                isAvailable: function() { return EnterMoon() && masks.ZoraMask && TotalMasks(3) && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Link Garo Chest': { 
                isAvailable: function() { return EnterMoon() && TotalMasks(4) && Fighting() && items.Hookshot && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Link Iron Knuckle Chest': { 
                isAvailable: function() { return EnterMoon() && TotalMasks(4) && Fighting() && items.Hookshot && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Link Bonus HP': { 
                isAvailable: function() { return EnterMoon() && TotalMasks(4) && Fighting() && items.Hookshot && items.Bombchu && items.Bow >= 1 && logic.moonitemlogic;}, 
                isLogic: function() { return logic.moonitemlogic;},
            },
            'Fierce Deity Mask': { 
                isAvailable: function() { return EnterMoon() && TotalMasks(20) && masks.GoronMask && masks.ZoraMask && masks.DekuMask && Fighting() && items.Hookshot && items.Bombchu && items.Bow >= 1 && logic.deitylogic;}, 
                isLogic: function() { return logic.deitylogic;},
            },
            'Majora': { 
                isAvailable: function() { return CanFaceMajora();}, 
                isLogic: function() { return true;},
            },
            
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Swamp Skulltula House',
        x: "47%",
        y: "67%",
        checklist: {
            'Main Room Water Spider': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Lower Left Soil': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting() && HasBottle();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Lower Right Soil': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting() && HasBottle();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Pillar': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Jar': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Upper Soil': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting() && HasBottle();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Upper Pillar': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Main Room Near Ceiling': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Monument Crate 1': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Monument Crate 2': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Monument Lower Wall': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Monument Torch': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Monument Spider': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Jar': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Pot 1': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Pot 2': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Behind Vines': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting() && (items.Sword >= 1 || items.GreatFairySword);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Wall': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Beehive 1': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Pot Room Beehive 2': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Gold Room Pillar': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Gold Room Beehive': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Gold Room Wall': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Gold Room Near Ceiling': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting() && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Tree 1': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Tree 2': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Tree 3': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Grass 1': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Grass 2': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();},
                isLogic: function() { return logic.skullslogic;},
            },
            'Tree Room Beehive': { 
                isAvailable: function() { return masks.DekuMask && HasRangeAttack() && Fighting();}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Mask of Truth': { 
                isAvailable: function() { return dungeons.SwampSkulltulas >= 30;}, 
                isLogic: function() { return logic.maskslogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },
    {
        name: 'Ocean Skulltula House',
        x: "33%",
        y: "55%",
        checklist: {
            'Entrance Left Wall': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Entrance Right Wall': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Entrance Web': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Ceiling Edge': {
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Ceiling Plank': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Jar': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Webbed Hole': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Webbed Pot': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Upper Pot': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Behind Skull 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Behind Skull 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Second Room Lower Pot': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Behind Picture': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Behind Cabinet': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library On Bookshelf': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Ceiling Edge': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Behind Bookcase 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Behind Bookcase 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Library Hole Behind Picture': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Ceiling Edge': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Chandelier 1': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);},
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Chandelier 2': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Chandelier 3': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Behind Picture': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Colored Skulls Pot': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Storage Web': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask) && CanUse(items.FireArrow);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Storage Crate': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Storage Wall': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Storage Barrel': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && items.Hookshot;}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Storage Behind Crate': { 
                isAvailable: function() { return canPlay(quests.EponasSong) && HasExplosives() && masks.GoronMask && (items.Hookshot || masks.ZoraMask);}, 
                isLogic: function() { return logic.skullslogic;},
            },
            'Wallet Upgrade': { 
                isAvailable: function() { return dungeons.OceanSkulltulas >= 30;}, 
                isLogic: function() { return logic.maininvlogic;},
            },
            'Colored Skulls Chest': { 
                isAvailable: function() {return canPlay(quests.EponasSong) && HasExplosives() && items.Hookshot && items.Bow >= 1 && masks.CaptainsHat;},
                isLogic: function() { return logic.piecelogic;},
            },
        },
        isBeatable: function() {
            return this.canGetCheck();
        },
        canGetCheck: function() {
            return generalCanGetCheck(this.checklist);
        },
    },

];

//define overworld Checks
var checks = [
    {
        name: 'Bombers Hideout Chest',
        x: "47%",
        y: "45%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (items.Bomb >=1 && quests.BombersNotebook){
                return "available";
            }
            else {return "unavailable"; }
        },
        isLogic: function() { return true;},
    },
    {
        name: 'Mystery Woods Grotto Chest',
        x: "53%",
        y: "60%",
        isAvailable: function() {
            return "available";
        },
        isLogic: function() { return true;},
    },
    {
        name: 'Woodfall Great Fairy',
        x: "52%",
        y: "75%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (dungeons.SwampStrayFairy >= 15) {
                return "available";
            }
            else {return "unavailable";}
        },
        isLogic: function() { return logic.greatfairylogic;},
    },
    {
        name: 'Road to Snowhead Grotto',
        x: "46%",
        y: "25%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (items.Bow >=1 && HasExplosives() && masks.GoronMask && masks.MaskOfTruth && items.Magic >= 1) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return true;},
    },
    {
        name: 'Road to Snowhead Pillar HP',
        x: "47%",
        y: "28%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (logic.piecelogic && items.Bow >=1 && HasExplosives() && masks.GoronMask && CanUse(items.LensOfTruth) && items.Hookshot && canPlay(quests.ScarecrowSong)) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return logic.piecelogic;},
    },
    {
        name: 'Snowhead Great Fairy',
        x: "49%",
        y: "21%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (dungeons.SnowStrayFairy >= 15) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return logic.greatfairylogic;},
    },
    {
        name: 'Great Bay Great Fairy',
        x: "25%",
        y: "64%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (dungeons.OceanStrayFairy >= 15) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return logic.greatfairylogic;},
    },
    {
        name: 'Ikana Great Fairy',
        x: "77%",
        y: "45%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (dungeons.StoneStrayFairy >= 15) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return logic.greatfairylogic;},
    },
    {
        name: 'Oath to Order',
        x: "50%",
        y: "85%",
        isAvailable: function() {
            if (!this.isLogic()) {
                return "hidden";
            }
            else if (WoodfallClear() || SnowheadClear() || BayClear() || StoneClear()) {
                return "available";
            }
            return "unavailable";
        },
        isLogic: function() { return logic.songslogic;},
    },
];