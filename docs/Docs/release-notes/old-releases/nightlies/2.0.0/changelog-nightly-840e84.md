# Nightly 840E84

## Features
- Adds locations for all Treasure Shop Game forms, Deku Playground days 1 & 2, Lottery Days 1-3, Zora Hall Stage Lights, Zora Hall Bad and Good Photos of Lulu, Honey and Darling 1-3 day rewards, and Zora Jar minigame.
- Adds new setting called Extra Checks to contain all extra checks that are not minigames
- Adjusts Spoiler Log to not show extra checks/minigame checks if they are not enabled
- Speeds up the boat ride in Southern Swamp for the trip to Deku Palace
- Archery Minigames will now reward both prizes if the requirements for both rewards are met the on the first attempt
- Shop items now show in the ingame spoiler log in Gray upon entering the shop for the first time 
- In game spoiler toggle to either enable or disable the spoiler log.

## Bug Fixes
- Spoiler Log generation now includes options to generate ingame spoilers but not the external XML file
- Hides WCT Bomb Shop Goron from ingame log as its not randomized
- Reorders the Settings Context to match the order that settings are created for menus
- Removed items from the settings context that were commented out and or did not need to be sent over or were now unused
- Remove all instances of Repeatability or Reusability as they are no longer needed with the newest changes to item overrides. The only exceptions to the new Item Overrides are Gold Dust, Seahorse, and Mystery Milk which on the off chance they end up on a check that does not re give them can be reobtained from their vanilla location after obtaining the randomized item once
- Item Overrides have been reworked so that -nearly- all locations will now re give the original check if the item is no longer in your inventory
- Settings Context and other code in app files have been cleaned up
- Collecting multiple stray fairies at once should now allow sequential get items, so no get items get overridden.
- Toilet hand doesn't give repeat rewards.

[Previous Nightly](./changelog-nightly-9e9333.md)
[Next Nightly](../../../changelog-latest-nightly.md)  