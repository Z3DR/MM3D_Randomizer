# 3DS Setup Guide
This guide will walk you through the process of setting up the MM3D Randomizer on your 3DS console. Be sure to read this entire guide and not skip over any parts. If you get stuck or have questions about any step, please post your concerns in the [Discord](./resources.md#discord-link) under setup-help.

## Homebrew:
Playing this randomizer will require you to homebrew your 3DS. Here is the guide to do so: [3ds.hacks.guide](https://3ds.hacks.guide/). Be sure to install all the programs the guide tells you to install during the [Finalizing Setup](https://3ds.hacks.guide/finalizing-setup.html) section. Note that we may not be able to answer your questions if they relate to the homebrew guide itself.

If you’ve already homebrewed your 3DS in the past, be sure to update to the latest version of Luma3DS. Older versions can cause the randomizer to crash upon booting up the game. Here is the latest release of Luma3DS: <https://github.com/LumaTeam/Luma3DS/releases/latest> Replace the file `boot.firm` on your SD card with the one in the latest release.

For the randomizer to work, you’ll need to enable game patching in the Luma3DS menu. To reach this menu, hold the `SELECT` key while powering on your console. Navigate using the D-pad to the `Enable game patching` option and press A so that an `x` appears to the left of it. Then press START to save the setting and return to the home menu.

## Version Notice
Currently the randomizer may only work on the North American & European versions of MM3D. We do not have plans to support other regions in the near future, so you will have to obtain a North American or European version somehow. Even if your 3DS is from a different region, you’ll be able to play the North American Or European version since you homebrewed your console. North American digital copies are game ID `0004000000125500` and European is `0004000000125600` You can check your game ID using the Checkpoint application that you installed during the homebrew process. To check if your digital version of the game is the North American version, the ID shown by hovering over the game in Checkpoint should be `00125500` or `00125600`.

## Installing the Randomizer Application
Once you’ve successfully homebrewed your console, there are a number of different ways to install the randomizer application. With each of these methods, you’ll see a choice for either `MM3D_Randomizer.3dsx` or `MM3D_Randomizer.cia`. The only difference between these files is how you access them on your 3DS, so you can choose either one. You do not need both. 

`.cia` applications are installed directly to your home menu. If you download and install the .cia then it will appear as new software and you can select it directly from your home menu.

`.3dsx` applications are run through the homebrew launcher. If you download the .3dsx application, you’ll need to run the homebrew launcher and then select the randomizer from the list of programs.

### Method 1: FBI QR Code Scan
This method will require your 3DS to be connected to the internet. Open up the `FBI` application that you installed during the homebrew setup. Navigate down and select `Remote Install`. Then select `Scan QR Code`. Point your camera at one of the QR codes that are available on the latest official release of the randomizer (depending on which extension you want). If you scan the QR code for the `.cia`, the application will be directly installed to your home menu. If you scan the QR code for the `.3dsx`, the application will be downloaded to the folder /3ds/MM3D_Randomizer/ on your SD card. If you get an error that says `Failed to verify TLS certificate (60)` then you need to update `FBI` to the latest version.

### Method 2: Universal Updater
This method will require your 3DS to be connected to the internet. Open up the Universal Updater application that you installed during the homebrew setup. You will see the Universal-DB store at first, however the randomizer is not in this store. You will need to add the store it’s in. Tap the gear in the bottom left of the screen. Tap `Select Unistore`. Tap the plus button icon at the bottom of the screen. Tap the symbol at the bottom left of the screen and scan the QR code below OR Tap the keyboard symbol in the bottom left and enter this URL: https://phlexplexi.co/unistore. The unistore has the five most recent nightly builds available for download as well as the latest stable release. Select the one you wish to download and you will be given an option to download either the `.3dsx` or `.cia`. Select `Confirm` after making your decision and then the icon made of four arrows on the left of the bottom screen will begin to spin to indicate the download. Once it’s finished, you can exit Universal Updater.

### Method 3: Manual Installation
From the latest release page (in #resources ), download either the `.3dsx` or `.cia` application under the `Assets` tab. If you’re using the `.3dsx` application you’ll want to copy it to the `/3ds/` folder on the root of your SD card. If you’re using the `.cia` application you can put it anywhere on your SD card. To install the `.cia`, open up the `FBI` application that you installed during the homebrew setup. Select the `SD` option at the top and navigate to where your `MM3D_Randomizer.cia` file is saved. Press `A` to select the file and then select `Install and delete CIA`. You will then be able to select the randomizer application from the home menu.

## Updating the Randomizer
To update the randomizer to a newer version, just refollow the steps for whichever method you previously chose. Updating the randomizer application will not interfere with seeds that you have already generated.

## Setting up a Randomizer Seed
Once you’ve downloaded/installed the randomizer application you can use it to create patches for randomizer playthroughs. When opening up the application, you will be greeted by a text menu that you can use to select your playthrough settings. Descriptions for each setting can be viewed on the top screen as you navigate through the different menus. Use the `Game Settings` Menu to select your game version and that you’re playing on 3DS console. If you accidentally select `Emulator`, then MM3D is going to crash when you open it. Once you’re satisfied with your settings, select the `Generate Randomizer`. With maximum randomization, it can take up to 40s to finish generating a playthrough and write the necessary patch files. Once this is done, you can exit the application through the home menu and boot MM3D to begin playing the randomizer. To verify that the patch files are working, make sure you see the green logo with the word ‘RANDOMIZER’ on the game’s title screen. We also recommend that you keep reading to understand how the randomizer works with your game and to answer any other questions you may have.

*Please note that 1.1 games may take significantly longer to launch (~30-45 seconds depending on the SD Card) as the Randomizer needs to downgrade the game to 1.0 before applying the Randomizer patches.*

Attempting to use other cheats while using the randomizer may cause strange behavior to occur in game. If you're having problems in game and have cheats enabled, try disabling them first and see if the problems go away.

When a new seed is generated, the patch files of the new seed will overwrite the patch files of any previous seed that was created. If you want to save previous seeds, you'll need to copy and store their patch files somewhere else before generating new playthroughs. The patch files (`code.ips`, `exheader.bin`, and `romfs`) are located in the folder `/luma/titles/0004000000125500` on your SD card.

The seed generation hashes together both the seed you provide and the non-cosmetic settings you use for your playthrough. So if you want to recreate a playthrough you’ll have to match both the settings and the seed.

## Savefiles & Checkpoint

This randomizer does not create a separate version of the game. The patch files created by the randomizer application will be applied over your game thanks to the `Enable game patching` option you turned on earlier. This means that save files will be shared between the vanilla game and randomizer patches. If you want to backup your current save files, you can do so using the Checkpoint application that you installed during the homebrew setup. 

When you want to start a new randomizer playthrough, you must create a new savefile while the randomizer is active as the randomizer will set necessary flags on your savefile during its creation. While the randomizer does not affect the data on vanilla created savefiles, playing a vanilla made file will still have many of the effects of your current seed, such as random item placements. If you want to play the vanilla game again, we recommend disabling the randomizer first.

## Disabling the Randomizer
To revert the game back to its original state, you simply need to uncheck `Enable game patching` from the Luma3DS menu. Hold the SELECT key while powering on your 3DS. Navigate using the D-pad to the `Enable game patching` option and press A so that the `x` disappears to the left of it. While the patch files for the randomizer will still exist, they will no longer apply while `Enable game patching` is unchecked.

Alternatively you can delete the patch files themselves through a variety of means, such as using the FBI application you installed during the homebrew setup, or using another homebrew program such as FTPD. The patch files (`code.ips`, `exheader.bin`, and `romfs`) are located in the folder `/luma/titles/0004000000125500` on your SD card.

## The Spoiler Log
If you want to view the spoiler log on your computer, it’s generated within the `/3ds/MM3DR/Spoiler_Logs` folder of your SD card. This spoiler log will tell you the location of every item in the game, as well as one way to logically collect all the items necessary to beat the seed (this is known as the “playthrough”). The spoiler log’s filename will be the combination of your seed and hash put together. An example of a spoiler log filename is `1002470105 (Zora Mask, Mask of Truth, Ocarina, Pictograph Box, Bombchu)-spoilerlog.xml`.