# Latest Stable Release Changes (v1.4.5)

## Features
- Adds ability to start with a custom amount of Swamp or Ocean Skulltula Tokens
- Adds Fierce Deity Anywhere toggle to `Comfort Settings` Menu
  - Note: Softlocks and crashes may still occur with FDA
- Adds Damage Multiplier to `Other Settings` Menu ( 1/2x, 1x, 2x, 4x, 6x, 8x, OHKO)
- Adds hints on the Clock Tower Door for Boss Remains (And Ocarina if shuffled).
- Edits Starting Inventory settings to allow starting without Ocarina of Time
  - In Starting Inventory > Main Inventory change Ocarina to `None` to start without an Ocarina
  - Default settings always start with Ocarina. 
  - Starting without Ocarina has it logically placed in a location obtainable in one cycle and without requiring an Ocarina. 
  - Starting without an Ocarina adds the vanilla Ocarina location on the Clock Tower Rooftop as a randomized location. This also adds the Ocarina of Time location to the `Excluded Locations` list 
  - When starting without an Ocarina, [due to Song Shuffle (Songsanity) not being included yet] Song of Time is already learned and does not need to be learned on the Clock Tower Rooftop on day 3
  - Note: The model for the Ocarina when dropped by Skull Kid is not changed but it will be correct on pick up

## Fixes
- A crash during No Logic generation and turning on Tokensanity has been fixed
- The model drawing system has been re-written to allow for better scalability.
- Boss remain items now draw properly
- The Fish HP in the Marine Lab now draws properly
- Overhead items during song of healing cutscenes load properly
- The moon tear will now show which item it is in its case.
- An odd race condition has been fixed so that free standing items should no longer freeze the game in an infinite loop.
- Minor improvements to the custom text and hint system
- Removes the WIP tag from FDA, TokenSanity, Ocarina Shuffle, Damage Multiplier, and Chest Size.
- Adds description to Starting Ocarina explaining setting it to NONE starts without ocarina
