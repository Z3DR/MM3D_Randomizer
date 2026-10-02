# Latest Nightly Changes

## Features

### New menu
- **Rewritten randomizer menu.** The app now draws its own interface instead of a text console:
  colored panels, a highlighted selection outline, and **toggle switches** for every On/Off setting.
  Settings with more than two choices still show as text. **A** now moves to the next option, the
  same as D-pad Right. Long location names fit on one line instead of wrapping.
- **New default settings.** These now start **On** (or *Random*): Shuffle Transformation, Heart
  Containers (*Random*), Fast Mask Transform, Fast Notebook, Fast Zora Swimming, Twinmold
  Restoration, all five cutscene skips (Happy Mask Salesman, Darmani, Mikau, Giants, Pirates), all
  four boss trial skips, Colored Small Keys, Colored Boss Keys and Show Postman Item. Saved presets
  and cached settings keep whatever they had.

### Locations
- **Shorter location names.** Location names now use the same region abbreviations everywhere
  (e.g. *Road to Snowhead Pillar* → *RS Pillar*), in the menus and the spoiler log.
- Alternate copies of a check (spring Goron Village, the cleared swamp, the moved Deku scrubs) are
  no longer listed in the **Exclude Locations** menu, since excluding them did nothing.

## Bug Fixes

### Item placement and logic
- **Shop prices are now part of logic.** With **Shopsanity**, an item could be placed behind a price
  the player's wallet couldn't cover yet, leaving the seed stuck. Logic now requires the Adult Wallet
  for prices over 99 and the Giant's Wallet for prices over 200, and shop prices are set before any
  item is placed.
- **Shopsanity places shop items with logic.** Items in shop slots are now placed by the logic fill
  instead of being dropped in at random.
- **Saving Koume needs a potion.** Logic only required a bottle to save Koume in the Woods of
  Mystery. It now requires a Red or Blue Potion: the Bottle with Red Potion, or a bottle and a Red
  or Blue Potion to buy or find. Blue Potion Refills can now be placed as required items.
- **Refills no longer count as bottles.** Milk, Chateau Romani refills and Green/Blue Potion and
  Fairy refills counted as owning a bottle in logic, even though without one they turn into a Green
  Rupee in game.
- **Generation no longer freezes.** Generating could hang at *Placing Items.* when a trade item or
  the Magic Bean Pack had no valid spot left early in the fill. It now retries instead.

### Spoiler log
- Fixed the in-game spoiler log printing **Error!** when the playthrough went through locations the
  in-game list hides (vanilla Skulltula tokens and stray fairies, alternate checks). Its playthrough
  also showed the wrong items after such a location; hidden locations are now left out cleanly.

### Custom Music
- The Milk Bar's regular background music can now be replaced, with a **stereo** file in
  *Area Themes/Milk Bar/*. The mono track is the Milk Bar **performance**, now in its own
  *Milk Bar Performance* folder.

### Items and songs
- Green and Blue Potions are only given when you have an empty bottle; otherwise you get a Green
  Rupee.
- Fixed the Goron Lullaby intro and full song being tracked incorrectly, which could give the wrong
  song or cause you to skip one.
- Talking to the Goron Elder no longer depends on the order the Goron Lullaby checks were done in;
  it now checks whether you've met the Goron Elder's son.
- Entering a shop no longer marks sword upgrades as received; the progressive sword is only
  recorded when you actually get a sword.

### Giants
- The giant's chamber after a boss now plays the right cutscene when bosses are beaten out of order:
  the first giant (who teaches Oath to Order) plays until Oath to Order is given, and the later
  giants after that. Freeing more than four giants no longer gives extra Oaths.

## Other Changes

- **D-pad Transformation Masks** description updated: Down A is no longer patched out when it's on.
