# Latest Nightly Changes  

## Features

### Shopsanity
- **Shopsanity.** New setting *Off* / *On*. Shuffles 21 shop slots across five shops:

  | Shop | Slots | Vanilla stock |
  |---|---|---|
  | West Clock Town Trading Post | 8 | Red Potion, Green Potion, Hero's Shield, Bottle with Fairy, Deku Stick, 30 Arrows, 10 Deku Nuts, Magic Bean |
  | West Clock Town Bomb Shop | 4 | 10 Bombs, 10 Bombchu, Bomb Bag purchase, Big Bomb Bag purchase |
  | Southern Swamp Magic Hags' Potion Shop | 3 | Blue Potion, Green Potion, Red Potion |
  | Goron Village Shop | 3 | 10 Bombs, 10 Bombchu, Red Potion |
  | Zora Hall Shop | 3 | Hero's Shield, 10 Arrows, Red Potion |

  The **Milk Bar** (Milk and Chateau Romani, sold separately) and the **Gorman Track milk** purchase
  are shuffled in the same pass. The two Bomb Bag purchases also need **Shuffle Main Inventory** to
  be on. Tingle maps, scrub purchases and the Curiosity Shop's All-Night Mask keep their own
  settings.
- **Shared shelves.** Alternate versions of a shelf sell the same check, share its price and text,
  and sell out together: the Trading Post part-timer after 10pm, the Goron Shop in spring, and the
  stolen Bomb Bag Sakon fences at the Curiosity Shop (the Bomb Shop's Big Bomb Bag — buying either
  one retires both).
- **Shopsanity Prices.** *Random* or *Affordable*. *Random*


### Magic beans
- **Beansanity.** **Shuffle Magic Beans** is no longer hidden and can be turned on. It adds a
  **Magic Bean Pack** (a stack of 20 beans) to the item pool and turns the Deku Palace Bean Salesman
  into a randomized check costing 60 rupees.
  (`71011b5` (Shopsanity), mm3dr `7537273` (shopsanity))
- **The Bean Pack unlocks buying beans.** Logic requires the pack before any bean purchase counts,
  and the pack is never placed in a shop since you could not buy it there. The Trading Post's bean
  shelf refuses the sale until you have found beans.
  (`71011b5` (Shopsanity), mm3dr `e0991d3` (shopsanity))

### Music and sound
- **Music randomizer.** New cosmetic option **Shuffle Music**: *Off*, *Background Music*, *Fanfares* or *All*. The generator shuffles tracks within compatible groups (area, event, battle, fanfare and ocarina music) and the patch plays the shuffled track in place of the original. The same option is also available from the new in-game Options menu.
  ([MM3D_Randomizer#204](https://github.com/Z3DR/MM3D_Randomizer/pull/204), [mm3dr#190](https://github.com/Z3DR/mm3dr/pull/190))
- **Sound effect randomizer.** New in-game option **Shuffle Sound Effects**: *Off*, *Categorical* or *Chaos*.
  ([mm3dr#191](https://github.com/Z3DR/mm3dr/pull/191))
- **Mute toggles.** New in-game options **Mute Sound Effects** and **Mute Background Music**.
  ([mm3dr#189](https://github.com/Z3DR/mm3dr/pull/189))

### Ocarina
- **Fast Ocarina Songs.** New in-game option that skips the song replay after playing any ocarina song: *Don't Skip*, *Skip (No Audio)* or *Skip (Keep Audio)*. This replaces the old fast playback that only applied to Elegy of Emptiness and Song of Soaring.
  ([mm3dr#188](https://github.com/Z3DR/mm3dr/pull/188))

### Options
- **In-game Options menu.** New Options page on the ingame menu. It holds Fast Ocarina Songs, the mute toggles, Shuffle Music and Shuffle Sound Effects.
  ([mm3dr#188](https://github.com/Z3DR/mm3dr/pull/188))
- New **In-Game Options** menu in the generator. Lets you override the initial settings of new saves.
  (`9886b27`, mm3dr `82c0c77`)

### Quality of life
- **Pirates' cutscene skip.** Skips the cutscene played when heading to Great Bay Temple. *A generator option to toggle this still needs to be added.*
  ([mm3dr#181](https://github.com/Z3DR/mm3dr/pull/181))

### Ice traps
- **More ice trap disguises.** Ice traps can now look like masks (including transformation masks), trade items, Bomber's Notebook, Tingle maps, the Ocarina of Time, and Skulltula tokens.
  (`ec8f371` (Shopsanity))

## Bug Fixes

### Stray fairies
- Fairy chests are now overridden when the fairy inside holds a major item.
  ([mm3dr#178](https://github.com/Z3DR/mm3dr/pull/178))
- Chest flags now account for fairies.
  ([mm3dr#184](https://github.com/Z3DR/mm3dr/pull/184))
- Stray fairies are only counted in the stray fairy bits.
  ([mm3dr#185](https://github.com/Z3DR/mm3dr/pull/185))
- Fairies without a collider no longer give their item twice or show an overhead item.
  ([mm3dr#186](https://github.com/Z3DR/mm3dr/pull/186), [mm3dr#187](https://github.com/Z3DR/mm3dr/pull/187))
- Stray fairy item text now names the correct progressive item.
  ([mm3dr#183](https://github.com/Z3DR/mm3dr/pull/183))
- Added a 120-tick delay to item updates with stray fairies so the item is given properly.
  ([mm3dr#192](https://github.com/Z3DR/mm3dr/pull/192))

### Items
- Mystery Milk is removed correctly again; room key, letters and pendant are still kept.
  ([mm3dr#187](https://github.com/Z3DR/mm3dr/pull/187))
- Removed a bad instruction from the trade item hooks.
  (mm3dr `319b404`)
- Ice traps disguised as Double Defense and as songs now use the correct models.
- Kokiri Sword removed from Ice Trap disguises (redundant with Progressive Sword).
  (`ec8f371` (Shopsanity))

### Camera and movement
- Free camera no longer resets while swimming as Zora or rolling as Goron.
  ([mm3dr#177](https://github.com/Z3DR/mm3dr/pull/177))

### Tracker and text
- Great Bay is now marked as discovered on the spoiler menu when entered.
  ([mm3dr#179](https://github.com/Z3DR/mm3dr/pull/179))

## Other Changes

- **Custom text commands.** Added two-character commands: `>[1-5]` starts a choice, and `>>`, `><` and `<<` align the active line right, center and left.
  ([mm3dr#180](https://github.com/Z3DR/mm3dr/pull/180), [mm3dr#182](https://github.com/Z3DR/mm3dr/pull/182))
- The in-game tracker now labels "Inside Clock Tower" as "Clock Tower".
  (mm3dr `8f9f13e` (shopsanity))
- New ingame options are ready to have generator settings added.
  (mm3dr `34a5e15`)
