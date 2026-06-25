# MM3D_Randomizer

This is an item randomizer app for _The Legend of Zelda: Majora's Mask 3D_ for the Nintendo 3DS.

* [General Description](#general-description)
* [Installation](#installation)
  * [On 3DS Console with Luma3DS](#On-3DS-Console-with-Luma3DS)
  * [On Citra](#On-Citra)
  * [Save Files](#Save-Files)
  * [Getting Stuck](#getting-stuck)
* [Building](#building)
* [Reporting Bugs](#reporting-bugs)

## General Description

This program takes _The Legend of Zelda: Majora's Mask 3D_ and randomizes the locations of the items for a new, more dynamic play experience.

The program is based off of the following works:
- [OoT3D Randomizer](https://github.com/gamestabled/OoT3D_Randomizer) - This app was rewritten using the OoT3DR generator as base code and modified to suit the needs for MM3D.
- [MM3DR Base Patch](https://github.com/Phlexplexico/mm3dr) - This is where all the ARM patches and base code patches are grabbed from. Decomp is heavily based off of [Project Restoration](https://github.com/leoetlino/project-restoration/).
- [MM Rando](https://github.com/ZoeyZolotova/mm-rando) - Base logic rules were taken and updated for MM3D.

Proper logic is used to ensure every seed is possible to complete without the use of glitches and will be safe from the possibility of softlocks with any possible usage of keys in dungeons.

The randomizer will ensure a glitchless path through the seed will exist, but the randomizer will not prevent the use of glitches for those players who enjoy that sort of thing, though we offer no guarantees that all glitches will have identical behavior to the original game. Glitchless can still mean that clever or unintuitive strategies may be required involving the use of things like  the Hookshot or other items that may not have been as important in the original game.

Each major dungeon will earn you a random boss remains once completed. The particular dungeons where these can be found, as well as other relevant dungeon information and the current seed hash can be viewed by pressing SELECT, and using the L or R button to move between pages.

As a service to the player in this very long game, various tedious elements of the game have been removed or sped up, and more convenience tweaks are planned for the future. Some of these changes can be customized when creating your seed.

Please be sure to explore the many customizable settings which are available when using the app! There are many options which can alter the length or difficulty of each playthrough.

Want to discuss the randomizer with others? Join our [Discord server](https://discord.gg/73ZNdjbfFp)!


## Installation

Setup and installation can be found on our [documentation site](https://z3dr.github.io/MM3D_Randomizer/)

### Save Files
Right now, save files are shared between any playthroughs you create and the base game. This means that you are responsible for managing your own save files. If you are playing on a 3DS, check out [Checkpoint](https://github.com/FlagBrew/Checkpoint/releases), an easy-to-use homebrew save manager.


### Getting Stuck

With a game the size of _Majora's Mask 3D_, it's quite easy for players to get stuck in certain situations with no apparent path to progressing.
Before reporting an issue, please make sure to check out the [Discord server](https://discord.gg/73ZNdjbfFp) to see if that issue has been reported already.

You may also find a map tracker helpful, as these allow you to see all checks which are available with your current items, and check which ones you've gotten already although keep in mind these were designed for the original Majora's Mask Randomizer so there may be some slight discrepancies.

## Building

(If you are looking to play the randomizer, jump to [Installation](#installation), this section is for people interested in contributing or messing with the code)!

Install the 3DS packages from [devkitPro](https://devkitpro.org/wiki/Getting_Started)

A small portion of this project is done in python. If you decide to use the Msys2 console from devkitpro, you can install python using the command `pacman -S python` within Msys2.


In the root folder, use the script `./linux_build_rando.sh` to build `MM3D_Randomizer.3dsx` and `MM3D_Randomizer.cia`. Use ```make debug=1``` for extra debugging features, including extra items when starting a new file. In the case of problems, try using a `make clean`.
When making changes to any code in the `Z3DR/code` directory, you must use `make clean` before recompiling if you want your changes to be picked up. Please note that line 177 in `Makefile` may have to be commented out to avoid the build scripts from resetting the subrepo.  
For faster compilation using multiple threads, you can use `make -j4` (in this example, the `4` is the number of threads being used).

## Reporting Bugs

Let us know if you believe you have discovered a bug by posting in our Discord server, or by opening an issue. In the [Discord](https://discord.gg/EVvzb6varj), we have a list of currently known issues and fixes which are pending release, which we try to keep fairly up to date.
