# Latest Stable Release Changes (v1.5.0)

## Features
- Addition of Songsanity settings to Item Shuffle menu. This includes 3 options, Vanilla (OFF) , Song Locations (Songs only are placed where a song could be learned in vanilla), Anywhere (as it says)  
  - Song of Soaring and Song of Time have been separated from base Songsanity for convenience as not everyone will want those two options in particular shuffled every time.
- Included custom ocarina colours for songsanity
- Added Starting Inventory Options for Progressive Lullaby and Song of Time
- Added Setting for Chest Animations (Always Fast or Match Contents)
- Added Setting for Coloured Keys (Small Keys only for now)  - green for Woodfall, white for Snowhead, blue for Great Bay, and orange for Stone Tower.
- Added Setting to Show postman reward on the postman when he is wearing the hat
- Added Setting to skip the cutscene of the Giants catching The Moon
- Added Settings to adjust amount of Boss Remains needed to enter The Moon and to Battle Majora
  - Adds additional hint to Clock Tower Door hints to show amount of masks needed to enter the Moon
  - Adds hint to Majora Child in The Moon for amount of masks needed for the Final Boss
- Adjusts Item Shuffle menu to separate items based on impact to the item pool
  - Dungeon settings, Item Pool Settings, and Starting Inventory menus were also moved into the new Item Shuffle menu so all item related settings are under one menu.
  - Adds descriptions for and changes the name of the Sword/Shield/Ocarina settings in the Item Shuffle Menu to better describe what those settings do
- Added SoT requirement to enter the moon (guarantees ability to exit, talk to the save statue if you do not have Song of Time).
  - Leaving the moon without meeting victory requirements (missing SoT or missing required number of masks) by talking to the save statue will now reset the cycle instead of returning you to Clock Town at the current time. 
- Adjusted Logic so that Song of Time and Ocarina are now obtainable within the first cycle.
- Improved cutscene skip for Giant's Cutscene on Clock Tower roof to instantly teleport you after playing Oath.
- Added new models for ice traps when songsanity is enabled.
- Added Progressive Lullaby instead of shuffling Goron Lullaby Intro and full lullaby.

## Changes:
- The list of available locations for both Ocarina and Song of Time to be placed in when shuffled has been adjusted 
  - This list has been added to the FAQ⁠ in the Official Discord Server for convenience, or on this website. (Also can be found with the !noocarina command!)
- Due to Songsanity implementation the Oath to Order check in the spoiler log now only shows under Woodfall Temple (It will still be obtained at the end of first dungeon completion)
- Added regional languagues to text class (translators are welcome to contribute!)
- Directory migration for presets and logs. They now exist in `/MM3DR/Presets` and `/MM3DR/Spoiler_Logs` respectively
- Spoiler log stylesheets now included (thanks OoT3DR!)
- New Spanish and French Hint Translations (thanks @Pizza!)
  - If you want to contribute translations for various hints, please do so [here](https://docs.google.com/spreadsheets/d/1nlaWNs1z6BcvNOSEezVvMwKVphiU00Ou7yxNP6J_Wy4/edit?gid=1832269070#gid=1832269070)
- Adjust how versions are represented in the app and patch side
- Removes forced Green Rupees on Deku Mask and Bombers Notebook locations when starting with Song of Healing (no longer needed as the SoH cutscene will always play and give a reward now that songsanity is implemented)
- Hides the new Upright Death Armos Room Chest from the Spoiler Log as it exists only for the override to be created for no logic runs.
- Adjusted Ocean Side Skulltula's to properly account for the first skulltula to avoid repeat items.
- Adjust boat house NPC to give rewards only for best photo, and only once
- Update temple flags to ensure that only doors remain open while the rest dungeon resets (this does not include fairies as they are tracked separately and will not respawn on collection).


## Fixes:
- Adjusts Clock Tower Ocarina of Time requirements to require a projectile to obtain (previously required nothing on accident),
- Adjusts Fill algorithm to place Song of Time (if shuffled) in limited locations.,
- Resolves occasional crash or error during spoiler log generation,
- Fixed Moon hint stones - Previously only overwrote the hint given when you already obtained the item that stone hints to, now it overrides both messages! Special thanks to Pizza1398 for this!,
- Keys Found counter in in-game spoiler log should no longer turn green early Special thanks to Pizza1398 for this!,
- Custom message colours should no longer be jumbled (thanks @Pizza!),
- Change the tatl sound for clock tower door,
- Stray fairies no longer respawn over cycle resets if you have obtained them.
- Chests containing stray fairies will no longer spawn fairies if you have collected them.
- Giants will only render in the final cutscene for the remains you have collected.
- On Day 2 and 3 after beating Gyorg, Mikau will now let you soothe his soul.
- Observatory model overrides are working as intended and will show you what item will fall from the Moon's Tear.
- Fixed handling some mask logic with the Observatory Man and talking while in Goron form.
- Spoiler menu keys will no longer count multiples if they appear in a multi-location check (i.e. Postbox or Kotake, thanks Nessy!)
- Skulltula's that contain small keys will no longer give you a Woodfall small key as a little treat.
- Hint text for Giant's Mask had its spelling adjusted.
- Adjusted Skulltula Tokens to be always repeatable if the item has been removed from your inventory.
- Adjusted Marine Lab HP check to ensure that the item is still overridden properly given its behaviour.
- Fix Odolwa's get item from chest having a different tune and sparkle effects
- Fix Chests so the now only show sparkle on decorative chests
- Fixes vanilla item for WFT Map Chest
- Added override for the upside down chest in the Armos Room (For No Logic - it contains the same item as the upright version)
