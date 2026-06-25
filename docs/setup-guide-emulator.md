# Emulator Setup Guide
This guide will walk you through the process of setting up the MM3D Randomizer on Emulator. This applies to any Citra-based Emulator, like Azahar which we will use as an example in this guide. If you get stuck or have questions about any part of this, please post your concerns in #setup-help. The latest version of Azahar can be found at the link in #resources . *Note: This guide is only intended for Citra-based emulators on Desktop. We do not guarantee that the randomizer will work on emulators for any other devices.*

### Version Notice:
Currently the randomizer works on both the North American and European versions of MM3D. We do not have plans to support other regions in the near future. North American digital copies are game ID `0004000000125500`, and European digital copies are game ID `0004000000125600`. We cannot direct you anywhere that hosts copyrighted game material for legal reasons, so you’ll have to perform that step on your own. This includes both publicly and in DMs, so don’t ask anyone to “DM you a link” either.


For brevity, this guide will focus on Azahar and the NA version of MM3D. The only difference for EU would be using the title ID `0004000000125600`.



## Installing the Randomizer Application
From the latest release page (or latest nightly for bleeding-edge features, but may have some instability) on GitHub (in [Resources](./resources.md#general-project-links)), download either the `.3dsx` or `.cia` application under the Assets tab. The only difference between these files is how you access them on Azahar, so you can choose either one. **You do not need both**. 

`.cia` applications can be installed onto Azahar. If you download `MM3D_Randomizer.cia`, go to `File->Install CIA` in Azahar and select `MM3D_Randomizer.cia`. It will then appear under the Installed Titles tab when you open Azahar.

`.3dsx` applications cannot be directly installed, but will need to be placed into a Azahar game directory. To set a game directory, double-click `Add New Application Directory in Azahar`, then browse for and select the folder that you have `MM3D_Randomizer.3dsx` in. The randomizer should now appear in Azahar under the folder you selected.

To update the randomizer to a newer version, download the newer version and either install the `.cia` again, or replace the older `.3dsx` file.




## Setting up a Randomizer Seed
Once you’ve downloaded/installed the randomizer application you can use it to create patches for randomizer playthroughs. When opening up the application in Azahar, you will be greeted by a text menu that you can use to select your playthrough settings. Descriptions for each setting can be viewed on the top screen as you navigate through the different menus. Use the **Game Settings Menu** to select your game version and then select that you’re playing on `Emulator`. If you accidentally select `3DS Console`, then MM3D is going to crash when you open it. Once you’re satisfied with your settings, select the `Generate Randomizer`. Generating a seed can take up to a few seconds. Once this is done, you can exit the application. The randomizer application generates the patch files where they would normally go on a 3DS SD card. The limited scope of directory access that the application has means you’ll have to move your patch files manually to play on Azahar.

*Moving the Patch Files*
Within Azahar, click on `File->Open Azahar Folder`. Within this folder, navigate to `\sdmc\luma\titles\0004000000125500\` and you should find the patch files `romfs`, `code.ips`, and `exheader.bin`. Copy `romfs`, `code.ips`, and `exheader.bin`, then click on `File->Open Azahar Folder` and navigate to `\load\mods\0004000000125500` and paste the copied files into this folder. If these folders do not exist for you, just create them. Additionally, if your game is viewable from the Azahar menu, you can right click on your game copy and choose `Open -> Mods Location` to get to this folder directly.



Now you can boot up MM3D to begin playing the randomizer. To verify that the patch files are working, make sure you see the green logo with the word ‘RANDOMIZER’ on the game’s title screen. We also recommend that you keep reading to understand how the randomizer works with your game and to answer any other questions you may have.

Attempting to use other cheats while using the randomizer may cause strange behavior to occur in game. If you're having problems in game and have cheats enabled, try disabling them first and see if the problems go away.

The seed generation hashes together both the seed you provide and the non-cosmetic settings you use for your playthrough. So if you want to recreate a playthrough you’ll have to match both the settings and the seed.



## Savefiles
This randomizer does not create a separate version of the game. The patch files created by the randomizer application will be applied over your game. This means that save files will be shared between the vanilla game and randomizer patches. If you want to backup your current save files, they are located at `\sdmc\Nintendo 3DS\00000000000000000000000000000000\00000000000000000000000000000000\title\00040000\00125500\data\00000001` if you click `File->Open Azahar Folder`. If your game title is viewable on the Citra menu, you can reach this folder by right-clicking your game in Citra and choosing `Open -> Save Data Location`.

When you want to start a new randomizer playthrough, you *must* create a new savefile while the randomizer is active as the randomizer will set values on your savefile during its creation. While the randomizer does not affect the data on vanilla created savefiles, playing a vanilla made file will still have many of the effects of your current seed, such as random item placements. If you want to play the vanilla game again, we recommend disabling the randomizer first.



## Disabling the Randomizer
To revert the game back to its original state, you simply need to delete or move the patch files from the mods folder that you pasted them to earlier.



## The Spoiler Log
If you set the `Generate Spoiler Log` option to `Yes`, a built-in spoiler log will appear within the randomizer menu in game. To access this menu, press Select (or whichever button you set to open the menu) and then use L or R to jump through the different screens until you find the Spoiler Log. To navigate the different spheres, use D-pad Left and D-pad Right. To navigate the items within a sphere, use D-pad Down and D-pad Up.



If you want to view the spoiler log in a text editor, click `File->Open Azahar Folder` then navigate to `sdmc/3ds/MM3DR/Spoiler_Logs`. The spoiler log will tell you the location of every item in the game, as well as one way to logically collect all the items necessary to beat the seed (this is known as the “playthrough”). The spoiler log’s filename will be the combination of your seed and hash put together. An example of a spoiler log filename is `1002470105 (Zora Mask, Mask of Truth, Ocarina, Pictograph Box, Bombchu)-spoilerlog.xml`.