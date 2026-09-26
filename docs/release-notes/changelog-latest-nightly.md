# Latest Nightly Changes  

## Features

### Custom Music
- **Custom Music.** New cosmetic options **Custom Music** and **Custom Music Only**. Put `.bcstm` files in `/MM3DR/Custom Music/` on the SD card and the randomizer places them over the game's music when a seed is generated. The folder is created on first launch, with one folder per category (*Area Themes*, *Battle Themes*, *Event Themes*, *Fanfares*, *Ocarina Songs*) and one per track inside them. A song in a category folder can replace any track in that category; a song in a track's folder replaces only that track.
- Songs are checked before they are used, such as track channel count (for mono files).
- **Shop**, **Milk Bar**, **Swamp Cruise** and **Shooting Gallery** are mono in the game and take mono files. Every other track takes stereo files.
- **Custom Music Only** lets songs repeat so every track with a valid song gets one. With it off, each song is used at most once and the remaining tracks stay vanilla.
- Every generation writes `/MM3DR/Custom Music/custom_music_report.txt`, listing what was placed and why any song was rejected. The spoiler log lists the songs placed.
- Works alongside **Shuffle Music**. Turning Custom Music off and generating again restores the vanilla tracks. Files you placed in the game's `romfs` folder yourself are never touched.
- See the [FAQ](https://z3dr.github.io/MM3D_Randomizer/faq/) for how to make and install songs.

### Music and sound
- **Link's sounds in Shuffle Sound Effects.** New options **Shuffle Footsteps** and **Shuffle Link's Voice**, in the generator and the in-game Options menu. Footsteps, jumps, landings and moves such as the Deku spin shuffle among themselves, and Link's voice shuffles among his own lines, with each form keeping its own voice. They replace the old *Link Only* mode of Shuffle Sound Effects.
- **Categorical sound shuffle reworked.** Sounds now trade with ones of the same kind: cries, footsteps, attacks, doors, explosions, water and so on. The shuffle tables are built by the generator, so each seed has its own.
- **Shuffle Music reworked.** Tracks are grouped by what they are (area themes, battle themes, item fanfares, clear fanfares, ocarina songs, ...) and every shuffled track moves. Clock Town Day 1, 2 and 3 are now shuffled too. Both the music and sound effect tables are always generated, so these options can be switched on from the in-game menu even if they were off when the seed was made.

## Bug Fixes

### Item placement
- Fixed an item occasionally disappearing from the seed when **Shopsanity** and **Shuffle Main Inventory** were both on. The item was placed at the Curiosity Shop's Bomb Bag, which is then overwritten to match the Bomb Shop's Big Bomb Bag, so it never appeared in game or in the spoiler log.
- The in-game spoiler log now tracks Deku Merchant purchases and the Big Bomb Bag correctly where one check has more than one location.

### Music and sound
- **Fanfare modes.** The *Background Music* and *Fanfares* modes of Shuffle Music now know which tracks are fanfares from the generator, and the music hook moved to the point where the stream is
  actually played. The game still sees the original track, so Clock Town's day changes and "already playing" checks behave as vanilla.
- Stopping a shuffled sound now also stops the sound it was swapped for, fixing a crash caused by a sound outliving the object that played it. Held sounds (like Link sliding) keep playing correctly while shuffled.

### Ocarina
- Skipping a song replay with **Fast Ocarina Songs** no longer makes the next song fail with a red X.
- Song of Storms grows magic beans again when the replay is skipped.

### Crashes
- Fixed a crash at the Milk Bar with Shopsanity on.

### Controls
- **Down A** works again with D-pad transformation masks enabled.

## Other Changes
- The spoiler log no longer lists alternate copies of a check (spring Goron Village, the cleared swamp, the moved Deku scrubs), and no longer lists the Southern Swamp music statue when Song of Soaring isn't shuffled.
