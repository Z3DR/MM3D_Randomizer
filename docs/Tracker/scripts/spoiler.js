"use strict";
/* Reads a Majora's Mask 3D Randomizer spoiler log (XML) and works out:
   - which tracker logic switches to turn on (from <settings>)
   - which items the player starts with (from <starting-inventory> plus the starting sword/shield/ocarina settings)
   Pure functions, no DOM access, so it can be tested outside the browser. */

const SpoilerLog = (() => {
    // tracker logic flag <- spoiler log setting name
    const SWITCHES = {
        maininvlogic: "Shuffle Main Inventory", maskslogic: "Shuffle Masks", transformmasklogic: "Shuffle Transformation",
        ocarinalogic: "Start With Ocarina", piecelogic: "Shuffle Piece of Heart", songslogic: "Shuffle Songs",
        soaringlogic: "Shuffle Song of Soaring", songtimelogic: "Start With Song of Time", skullslogic: "Tokensanity",
        shopsanitylogic: "Shopsanity", greatfairylogic: "Shuffle Fairy Rewards", scrubtradelogic: "Shuffle Scrub Trades",
        anjulogic: "Shuffle Anju and Kafei", tinglelogic: "Shuffle Tingle Maps", notebooklogic: "Shuffle Notebook",
        cowlogic: "Shuffle Cows", beanslogic: "Shuffle Magic Beans", scrubpurchaselogic: "Shuffle Scrub Purchases",
        extraminigameslogic: "Extra Minigames", extracheckslogic: "Extra Checks", moonitemlogic: "Shuffle Moon Items",
        deitylogic: "Shuffle Fierce Deity", mapslogic: "Maps/Compasses", smallkeylogic: "Small Keys", bigkeylogic: "Boss Keys",
        straylogic: "Stray Fairies", townstraylogic: "Clock Town Stray Fairy", remainslogic: "Dungeon Rewards",
        containerlogic: "Heart Containers",
    };
    // <select> flags: "Vanilla" (or anything that is not 1-4) means all four
    const SELECTS = { moonrequirementslogic: "Moon Requirements", majorarequirementslogic: "Majora Requirements" };

    const DUNGEONS = { woodfall: "Swamp", snowhead: "Snow", greatbay: "Ocean", stonetower: "Stone" };
    const WALLET = { adult: 2, giant: 3 };   // tracker tiers: 1 child, 2 adult, 3 giant (see the Wallet checks in checks.js)
    const BOMB_BAG = { 20: 1, 30: 2, 40: 3 };
    const QUIVER = { 30: 1, 40: 2, 50: 3 };

    const decode = (s) => s.replace(/&apos;/g, "'").replace(/&quot;/g, '"').replace(/&lt;/g, "<").replace(/&gt;/g, ">").replace(/&amp;/g, "&");
    const isOn = (v) => v !== undefined && v !== "" && !/^(off|no|none|vanilla|disabled)$/i.test(v.trim());
    // "Don Gero's Mask" and "DonGeroMask" both become the same key (possessives and plural s are ignored)
    const norm = (s) => s.toLowerCase().replace(/['’]s\b/g, "").replace(/[^a-z0-9]/g, "").replace(/s/g, "");

    function readEntries(xml, tag) {
        const out = [];
        const re = new RegExp(`<${tag} name="([^"]*)"[^>]*>([^<]*)</${tag}>`, "g");
        for (let m; (m = re.exec(xml)); ) out.push([decode(m[1]), decode(m[2]).trim()]);
        return out;
    }

    /* targets: { items, masks, dungeons, quests }, each { state: <live object>, max: <max map> } */
    function parse(text, targets) {
        if (!/<spoiler-log[\s>]/.test(text)) throw new Error("This doesn't look like a spoiler log (no <spoiler-log> element).");
        const attr = (n) => (text.match(new RegExp(`<spoiler-log[^>]*\\s${n}="([^"]*)"`)) || [])[1] ?? "";

        const settings = new Map();
        const settingsXml = (text.match(/<settings>([\s\S]*?)<\/settings>/) || [])[1] ?? "";
        for (const [k, v] of readEntries(settingsXml, "setting")) if (!settings.has(k)) settings.set(k, v);   // first one wins

        const logic = {};
        for (const [flag, name] of Object.entries(SWITCHES)) if (settings.has(name)) logic[flag] = isOn(settings.get(name));
        for (const [flag, name] of Object.entries(SELECTS)) {
            const n = parseInt(settings.get(name), 10);
            if (settings.has(name)) logic[flag] = n >= 1 && n <= 4 ? n : 4;
        }

        const patch = { items: {}, masks: {}, dungeons: {}, quests: {} };
        const lookup = new Map();
        for (const [group, { state }] of Object.entries(targets))
            for (const key of Object.keys(state)) if (key !== "blank") lookup.set(norm(key), { group, key });

        const set = (group, key, value) => {
            patch[group][key] = typeof value === "boolean" ? value : Math.min(value, targets[group].max[key] ?? value);
        };
        const count = (v) => { const n = parseInt(v, 10); return Number.isNaN(n) ? (isOn(v) ? 1 : 0) : n; };

        // Starting sword / shield / ocarina / Song of Time come from settings, not the inventory list
        const tier = (name, table) => { const v = settings.get(name) ?? ""; for (const [re, n] of table) if (re.test(v)) return n; return 0; };
        if (settings.has("Starting Sword")) patch.items.Sword = tier("Starting Sword", [[/kokiri/i, 1], [/razor/i, 2], [/gilded/i, 3]]);
        if (settings.has("Starting Shield")) patch.items.Shield = tier("Starting Shield", [[/hero/i, 1], [/mirror/i, 2]]);
        if (settings.has("Start With Ocarina")) patch.quests.Ocarina = isOn(settings.get("Start With Ocarina"));
        if (settings.has("Start With Song of Time")) patch.quests.SongOfTime = isOn(settings.get("Start With Song of Time"));

        const unmatched = [];
        let startCount = 0;
        const inventory = (text.match(/<starting-inventory>([\s\S]*?)<\/starting-inventory>/) || [])[1] ?? "";
        for (const [name, value] of readEntries(inventory, "item")) {
            const n = norm(name);
            const dungeonWord = Object.keys(DUNGEONS).find((d) => n.startsWith(norm(d)));
            let done = true;

            if (/^bottle slot/i.test(name)) {
                const hit = lookup.get(norm(value));
                if (!hit) done = false;
                else if (hit.key === "EmptyBottle") set("items", "EmptyBottle", (patch.items.EmptyBottle ?? 0) + 1);
                else set(hit.group, hit.key, true);
            } else if (/^bomb bag/i.test(name)) {
                BOMB_BAG[parseInt(value.match(/\d+/), 10)] ? set("items", "Bomb", BOMB_BAG[parseInt(value.match(/\d+/), 10)]) : (done = false);
            } else if (/^bow/i.test(name)) {
                QUIVER[parseInt(value.match(/\d+/), 10)] ? set("items", "Bow", QUIVER[parseInt(value.match(/\d+/), 10)]) : (done = false);
            } else if (/^wallet/i.test(name)) {
                const w = /giant/i.test(value) ? WALLET.giant : /adult/i.test(value) ? WALLET.adult : 0;
                w ? set("items", "Wallet", w) : (done = false);
            } else if (/^magic/i.test(name)) {
                set("items", "Magic", /double|large/i.test(value) ? 2 : 1);
            } else if (/clock\s*town.*stray/i.test(name)) {
                isOn(value) || count(value) ? set("dungeons", "TownStrayFairy", true) : (done = false);
            } else if (dungeonWord && /stray/i.test(name)) {
                set("dungeons", `${DUNGEONS[dungeonWord]}StrayFairy`, count(value));
            } else if (dungeonWord && /(map|compass|boss key|small key)/i.test(name)) {
                const part = /map/i.test(name) ? "Map" : /compass/i.test(name) ? "Compass" : /boss/i.test(name) ? "BigKey" : "SmallKey";
                set("dungeons", `${DUNGEONS[dungeonWord]}${part}`, part === "SmallKey" ? count(value) : true);
            } else if (/(swamp|ocean).*skulltula/i.test(name)) {
                set("dungeons", /swamp/i.test(name) ? "SwampSkulltulas" : "OceanSkulltulas", count(value));
            } else if (/lullaby/i.test(name)) {
                set("quests", "GoronLullaby", /full/i.test(value) ? 2 : /intro/i.test(value) ? 1 : 0);
            } else {
                const hit = lookup.get(n);
                if (!hit) done = false;
                else if (typeof targets[hit.group].state[hit.key] === "number") set(hit.group, hit.key, count(value));
                else set(hit.group, hit.key, isOn(value) || count(value) > 0);
            }
            done ? startCount++ : unmatched.push(`${name}: ${value}`);
        }
        return { seed: attr("seed"), hash: attr("hash"), logic, patch, startCount, unmatched, settingCount: Object.keys(logic).length };
    }

    return { parse };
})();
