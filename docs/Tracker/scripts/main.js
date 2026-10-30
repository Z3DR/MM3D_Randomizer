"use strict";
/* Majora's Mask 3D Randomizer tracker: UI, state and persistence.
   Logic rules live in checks.js and read the globals items/masks/dungeons/quests and `logic`. */

const PREFIX = "mm3dtracker:";
let popup = null;               // pop-out window, while open
const popped = [];              // nodes moved into it, so they can be put back
// Elements that were moved to the pop-out are looked up there too
const $ = (id) => document.getElementById(id) ?? popup?.document.getElementById(id) ?? null;

// logic flag -> key used in saved data (old names kept so existing saves still load)
const LOGIC_KEYS = {
    // Major items
    maininvlogic: "maininv", maskslogic: "mask", transformmasklogic: "tmask", ocarinalogic: "ocashuffle", 
    piecelogic: "piece", songslogic: "songs", soaringlogic: "soaring", songtimelogic: "songtime", 
    skullslogic: "skulls", shopsanitylogic: "shopsanity", greatfairylogic: "gfairy",
    // Side items
    scrubtradelogic: "scrubtrade", anjulogic: "anju", tinglelogic: "tingle", notebooklogic: "notebook", 
    cowlogic: "cow", beanslogic: "beans", scrubpurchaselogic: "scrubpurchase", extraminigameslogic: "extraminigames",
    extracheckslogic: "extrachecks", moonitemlogic: "moonitem", deitylogic: "deity",
    // Dungeon items
    mapslogic: "mapscompass", smallkeylogic: "skey", bigkeylogic: "bkey", straylogic: "stray", townstraylogic: "townstray", 
    remainslogic: "bosses", containerlogic: "containers", moonrequirementslogic: "moonrequirements", majorarequirementslogic: "majorarequirements",
    // Miscellaneous
    eggslogic: "eggs", skipbombers: "skipnotebook"
};
// Flags driven by a <select> hold a number (bosses required, 1-4) instead of true/false
const SELECT_DEFAULTS = { moonrequirementslogic: 4, majorarequirementslogic: 4 };
const logic = Object.fromEntries(Object.keys(LOGIC_KEYS).map((k) => [k, k in SELECT_DEFAULTS ? SELECT_DEFAULTS[k] : false]));

const GRIDS = {
    item:    { el: "itemdiv",    layout: defaultItemGrid,    state: items,    min: itemsMin,   max: itemsMax },
    mask:    { el: "maskdiv",    layout: defaultMaskGrid,    state: masks,    min: {},         max: {} },
    dungeon: { el: "dungeondiv", layout: defaultDungeonGrid, state: dungeons, min: dungeonMin, max: dungeonMax },
    quest:   { el: "questdiv",   layout: defaultQuestGrid,   state: quests,   min: questMin,   max: questMax },
};
// Snapshot before any saved data is applied (items.js aliases base* and live objects)
const PRISTINE = Object.fromEntries(Object.entries(GRIDS).map(([k, g]) => [k, { ...g.state }]));

// Counters are drawn as a clean base picture plus overlaid text.
// Base picture for each counter (images/<file>.png); everything else keeps images/<Name><value>.png
const BASE_IMAGE = {
    Bow: "Bow0", Bomb: "Bomb0", EmptyBottle: "Bottle", ZoraEgg: "ZoraEgg", HeartContainer: "HeartContainer0", HeartPieces: "HeartPieces0",
    SwampSkulltulas: "SwampSkulltulas0", OceanSkulltulas: "OceanSkulltulas0",
    SwampStrayFairy: "SwampStrayFairy0", SnowStrayFairy: "SnowStrayFairy0",
    OceanStrayFairy: "OceanStrayFairy0", StoneStrayFairy: "StoneStrayFairy0",
    SwampSmallKey: "SwampSmallKey0", SnowSmallKey: "SnowSmallKey0",
    OceanSmallKey: "OceanSmallKey0", StoneSmallKey: "StoneSmallKey0",
};
// Upgrade tiers show their capacity instead of the tier number ("" = nothing at tier 0)
const TIER_TEXT = { Bow: ["", "30", "40", "50"], Bomb: ["", "20", "30", "40"] };
// Bomber's Notebook digits have no picture at all: the cell is drawn as a numbered button
const NOTE_NAME = /^NoteNum/;

const cells = [];
const checkEls = [];
const areaEls = [];
let submapItems = [];
let areaSelect = 0;

/* ---------- logic guard ----------
   A rule in checks.js that throws (typo, missing property...) used to abort updateMap() halfway,
   leaving the rest of the map stale. Every rule is wrapped once at startup so a broken rule only
   affects its own check (it is shown as unavailable) and is reported once in the console. */

const reportedLogicErrors = new Set();

function guardRule(owner, fnName, label, fallback) {
    const original = owner[fnName];
    if (typeof original !== "function") return;
    owner[fnName] = function (...args) {
        try {
            return original.apply(this, args);
        } catch (err) {
            const key = `${label}:${fnName}`;
            if (!reportedLogicErrors.has(key)) {
                reportedLogicErrors.add(key);
                console.error(`Logic error in ${fnName}() for "${label}":`, err);
            }
            return fallback;
        }
    };
}

function guardLogic() {
    // Overworld checks return a state string; area checks return a boolean
    checks.forEach((c) => {
        guardRule(c, "isAvailable", c.name, "unavailable");
        guardRule(c, "isLogic", c.name, true);
    });
    areas.forEach((a) => {
        guardRule(a, "canGetCheck", a.name, "unavailable");
        guardRule(a, "isBeatable", a.name, "unavailable");
        for (const [name, c] of Object.entries(a.checklist)) {
            guardRule(c, "isAvailable", `${a.name} / ${name}`, false);
            guardRule(c, "isLogic", `${a.name} / ${name}`, true);
        }
    });
}

/* ---------- persistence (localStorage, with one-time migration from old cookies) ---------- */

function readLegacyCookie(name) {
    const prefix = name + "=";
    for (const part of document.cookie.split(";")) {
        const c = part.trim();
        if (c.startsWith(prefix)) {
            try { return JSON.parse(c.slice(prefix.length)); } catch { return {}; }
        }
    }
    return {};
}

function readStore(name) {
    try {
        const stored = localStorage.getItem(PREFIX + name);
        if (stored !== null) return JSON.parse(stored) ?? {};
    } catch (err) {
        console.warn(`Could not read '${name}':`, err);
    }
    return readLegacyCookie(name);
}

function writeStore(name, obj) {
    try { localStorage.setItem(PREFIX + name, JSON.stringify(obj)); }
    catch (err) { console.warn(`Could not save '${name}':`, err); }
}

function serializeChecks() { return checks.map((c) => c.isOpened || false); }
function serializeAreaChecks() { return areas.map((a) => Object.values(a.checklist).map((c) => c.isOpened || false)); }

const savers = {
    settings: () => ({
        map: Number($("showmap").checked), iZoom: Number($("itemzoom").value),
        mZoom: Number($("mapzoom").value), mPos: Number($("mappositionbelow").checked),
    }),
    items: () => ({ obtainedItems: items, obtainedMasks: masks, obtainedDungeons: dungeons, obtainedQuests: quests }),
    checks: () => ({ checks: serializeChecks(), areaChecks: serializeAreaChecks() }),
    logic: () => Object.fromEntries(Object.entries(LOGIC_KEYS).map(([flag, key]) => [key, logic[flag]])),
};
const save = (name) => writeStore(name, savers[name]());

function loadState() {
    const saved = readStore("items");
    for (const [key, state] of [["obtainedItems", items], ["obtainedMasks", masks], ["obtainedDungeons", dungeons], ["obtainedQuests", quests]]) {
        for (const k in state) {
            if (typeof saved[key]?.[k] === typeof state[k]) state[k] = saved[key][k];
        }
    }
    const c = readStore("checks");
    if (Array.isArray(c.checks)) c.checks.forEach((v, i) => { if (checks[i]) checks[i].isOpened = !!v; });
    if (Array.isArray(c.areaChecks)) {
        areas.forEach((a, i) => Object.values(a.checklist).forEach((chk, j) => { chk.isOpened = !!c.areaChecks[i]?.[j]; }));
    }
    const l = readStore("logic");
    for (const [flag, key] of Object.entries(LOGIC_KEYS)) {
        if (flag in SELECT_DEFAULTS) {
            const n = Number(l[key]);
            logic[flag] = Number.isInteger(n) && n >= 1 && n <= 4 ? n : SELECT_DEFAULTS[flag];
        } else {
            logic[flag] = !!l[key];
        }
    }
}

/* ---------- item / mask / dungeon / quest grids ---------- */

const label = (name) => name.replace(/([a-z])([A-Z])/g, "$1 $2");

function renderCell(cell) {
    const { button, kind, name } = cell;
    const { state, max } = GRIDS[kind];
    const value = state[name];
    const isBool = typeof value === "boolean";
    const isNote = NOTE_NAME.test(name);
    const base = BASE_IMAGE[name];

    const text = isNote ? String(value) : base ? (TIER_TEXT[name]?.[value] ?? String(value)) : "";
    const image = isNote ? null : base ?? (isBool ? name : name + value);
    button.style.backgroundImage = image ? `url(images/${image}.png)` : "none";
    button.className = `cell ${!!value}${isNote ? " note" : ""}`;

    if (text) {
        if (!cell.count) {
            cell.count = document.createElement("span");
            cell.count.setAttribute("aria-hidden", "true");
            button.append(cell.count);
        }
        cell.count.className = isNote ? "notenum" : "count";
        cell.count.textContent = text;
        cell.count.classList.toggle("max", value >= max[name]);
    } else if (cell.count) {
        cell.count.remove();
        cell.count = null;
    }
    if (isBool) {
        button.setAttribute("aria-pressed", value);
        button.setAttribute("aria-label", label(name));
    } else {
        button.removeAttribute("aria-pressed");
        button.setAttribute("aria-label", `${label(name)}: ${text || value} (${value} of ${max[name]})`);
    }
    button.title = label(name);
}

function step(cell, direction) {
    const { state, min, max } = GRIDS[cell.kind];
    const value = state[cell.name];
    if (typeof value === "boolean") {
        state[cell.name] = !value;
    } else {
        const lo = min[cell.name] ?? 0;
        const next = value + direction;
        state[cell.name] = next > max[cell.name] ? lo : next < lo ? max[cell.name] : next;
    }
    renderCell(cell);
    updateMap();
    save("items");
}

function buildGrids() {
    for (const [kind, grid] of Object.entries(GRIDS)) {
        const root = $(grid.el);
        for (const names of grid.layout) {
            const row = document.createElement("div");
            row.className = "trackerrow";
            for (const name of names) {
                const button = document.createElement("button");
                button.type = "button";
                button.setAttribute("aria-keyshortcuts", "ArrowUp ArrowDown");
                const cell = { button, kind, name };
                button.addEventListener("click", () => step(cell, +1));          // Enter / Space / left click
                button.addEventListener("contextmenu", (e) => { e.preventDefault(); step(cell, -1); });
                button.addEventListener("keydown", (e) => {
                    if (e.key === "ArrowUp") { e.preventDefault(); step(cell, +1); }
                    else if (e.key === "ArrowDown") { e.preventDefault(); step(cell, -1); }
                });
                cells.push(cell);
                renderCell(cell);
                row.append(button);
            }
            root.append(row);
        }
    }
}

/* ---------- map ---------- */

function toggleOpened(check) {
    check.isOpened = !check.isOpened;
    updateMap();
    save("checks");
}

function makeTip(className, text) {
    const tip = document.createElement("span");
    tip.className = className;
    tip.textContent = text;
    tip.setAttribute("aria-hidden", "true");
    return tip;
}

function buildMap() {
    const mapimage = $("mapimage");
    checks.forEach((check) => {
        const b = document.createElement("button");
        b.type = "button";
        b.className = "mapspan check";
        b.style.left = check.x;
        b.style.top = check.y;
        b.append(makeTip("tooltip", check.name));
        b.addEventListener("click", () => toggleOpened(check));
        mapimage.append(b);
        checkEls.push(b);
    });
    areas.forEach((area, k) => {
        const b = document.createElement("button");
        b.type = "button";
        b.className = "mapspan area";
        b.style.left = area.x;
        b.style.top = area.y;
        const count = document.createElement("span");
        count.className = "checkCount";
        b.append(count, makeTip("tooltipgrey", area.name));
        b.addEventListener("click", () => selectArea(k));
        mapimage.append(b);
        areaEls.push(b);
    });
}

function selectArea(k) {
    areaSelect = k;
    areaEls.forEach((b, i) => b.classList.toggle("selected", i === k));
    $("submaparea").textContent = areas[k].name;
    const list = $("submaplist");
    list.replaceChildren();
    submapItems = Object.entries(areas[k].checklist).map(([name, check]) => {
        const li = document.createElement("li");
        const b = document.createElement("button");
        b.type = "button";
        b.textContent = name;
        b.addEventListener("click", () => toggleOpened(check));
        li.append(b);
        list.append(li);
        return { li, b, name, check };
    });
    updateSubmap();
}

function updateSubmap() {
    $("submaparea").className = "DC" + areas[areaSelect].isBeatable();
    for (const { li, b, name, check } of submapItems) {
        const [cls, text] = check.isOpened ? ["DCopened", "checked"]
            : !check.isLogic() ? ["DChidden", "not randomized"]
            : check.isAvailable() ? ["DCavailable", "available"]
            : ["DCunavailable", "unavailable"];
        li.className = cls;
        b.setAttribute("aria-label", `${name}: ${text}`);
    }
}

function setStat(id, value) {
    document.getElementById(id).textContent = value;
    const copy = popup && !popup.closed ? popup.document.getElementById(id) : null;
    if (copy) copy.textContent = value;
}

function updateMap() {
    let checked = 0, available = 0, remaining = 0;
    const tally = (check, isAvailable) => {
        if (!check.isLogic()) return;
        if (check.isOpened) checked++;
        else { remaining++; if (isAvailable) available++; }
    };

    checks.forEach((check, k) => {
        const state = check.isOpened ? "opened" : check.isAvailable();
        tally(check, state === "available");
        checkEls[k].className = `mapspan check ${state}`;
        checkEls[k].setAttribute("aria-label", `${check.name}: ${state}`);
    });
    areas.forEach((area, k) => {
        let count = 0;
        for (const check of Object.values(area.checklist)) {
            tally(check, check.isAvailable());
            if (!check.isOpened && check.isLogic() && check.isAvailable()) count++;
        }
        const el = areaEls[k];
        el.className = `mapspan area ${area.canGetCheck()}${k === areaSelect ? " selected" : ""}`;
        el.querySelector(".checkCount").textContent = count || "";
        el.setAttribute("aria-label", `${area.name}: ${count} available`);
    });
    setStat("statschecked", checked);
    setStat("statsavailable", available);
    setStat("statsremaining", remaining);
    updateSubmap();
}

/* ---------- pop-out window ---------- */

// The real grid and bar elements are moved (not copied) into the pop-out, so their
// click handlers and live updates keep working with no extra syncing.
function popOut() {
    if (popup && !popup.closed) { popup.focus(); return; }
    const win = window.open("", "mm3dtracker-items", "popup,width=800,height=720");
    if (!win) {
        alert("The pop-up was blocked. Allow pop-ups for this site and try again.");
        return;
    }
    const css = document.querySelector("link[rel=stylesheet]").href;
    win.document.open();
    win.document.write(`<!doctype html><html lang="en"><head><meta charset="utf-8">
        <title>MM3D Items</title><base href="${document.baseURI}">
        <link rel="stylesheet" href="${css}"></head><body class="popout"></body></html>`);
    win.document.close();
    popup = win;

    const wrap = win.document.createElement("div");
    wrap.className = "popoutitems";
    const move = (node, target) => {
        popped.push({ node, parent: node.parentNode, next: node.nextSibling });
        target.append(node);
    };
    ["itemdiv", "maskdiv", "dungeondiv", "questdiv"].forEach((id) => move($(id), wrap));
    win.document.body.append(wrap);
    // Stats are copied (the main page keeps its own bar); updateMap() writes to both
    win.document.body.append(document.querySelector(".mapbar").cloneNode(true));
    $("itemtable").hidden = true;
    win.addEventListener("pagehide", popIn);
}

function popIn() {
    while (popped.length) {
        const { node, parent, next } = popped.pop();
        parent.insertBefore(node, next);
    }
    $("itemtable").hidden = false;
    popup = null;
}

window.addEventListener("pagehide", () => popup?.close());

/* ---------- settings ---------- */

function applyZoom(input) {
    $(input.dataset.zoom).style.zoom = input.value / 100;
    $(input.dataset.zoom + "size").textContent = input.value + "%";
}

function applySettings(s) {
    $("showmap").checked = !!s.map;
    $("mapdiv").hidden = !s.map;
    $("itemzoom").value = s.iZoom;
    $("mapzoom").value = s.mZoom;
    applyZoom($("itemzoom"));
    applyZoom($("mapzoom"));
    $(s.mPos ? "mappositionbelow" : "mappositionside").checked = true;
    $("layoutdiv").classList.toggle("flexcontainer", !s.mPos);
}

function refreshAll() {
    cells.forEach(renderCell);
    updateMap();
}

function wire() {
    document.querySelectorAll("[data-logic]").forEach((box) => {
        const isSelect = box.tagName === "SELECT";
        if (isSelect) box.value = String(logic[box.dataset.logic]);
        else box.checked = logic[box.dataset.logic];
        box.addEventListener("change", () => {
            logic[box.dataset.logic] = isSelect ? Number(box.value) : box.checked;
            updateMap();
            save("logic");
        });
    });
    document.querySelectorAll("[data-zoom]").forEach((input) =>
        input.addEventListener("input", () => { applyZoom(input); save("settings"); }));
    $("showmap").addEventListener("change", (e) => { $("mapdiv").hidden = !e.target.checked; save("settings"); });
    document.querySelectorAll("[name=mapposition]").forEach((radio) =>
        radio.addEventListener("change", () => {
            $("layoutdiv").classList.toggle("flexcontainer", !$("mappositionbelow").checked);
            save("settings");
        }));

    const actions = {
        popout: popOut,
        resetlayout() {
            applySettings({ map: 1, iZoom: 100, mZoom: 100, mPos: 0 });
            save("settings");
        },
        resettracker() {
            checks.forEach((c) => delete c.isOpened);
            areas.forEach((a) => Object.values(a.checklist).forEach((c) => delete c.isOpened));
            for (const [kind, grid] of Object.entries(GRIDS)) Object.assign(grid.state, PRISTINE[kind]);
            refreshAll();
            save("items");
            save("checks");
        },
        resetlogic() {
            for (const flag in logic) logic[flag] = flag in SELECT_DEFAULTS ? SELECT_DEFAULTS[flag] : false;
            document.querySelectorAll("[data-logic]").forEach((box) => {
                if (box.tagName === "SELECT") box.value = String(logic[box.dataset.logic]);
                else box.checked = false;
            });
            updateMap();
            save("logic");
        },
    };
    document.querySelectorAll("[data-action]").forEach((b) =>
        b.addEventListener("click", () => actions[b.dataset.action]()));

    const button = $("settingsbutton");
    const panel = $("settings");
    const toggle = (open) => {
        panel.hidden = !open;
        button.textContent = open ? "Close" : "Options";
        button.setAttribute("aria-expanded", open);
    };
    button.addEventListener("click", () => toggle(panel.hidden));
    document.addEventListener("keydown", (e) => { if (e.key === "Escape" && !panel.hidden) { toggle(false); button.focus(); } });
}

function init() {
    guardLogic();
    loadState();
    buildGrids();
    buildMap();
    applySettings({ map: 1, iZoom: 100, mZoom: 100, mPos: 0, ...readStore("settings") });
    wire();
    selectArea(0);
    updateMap();
}

document.addEventListener("DOMContentLoaded", init);
