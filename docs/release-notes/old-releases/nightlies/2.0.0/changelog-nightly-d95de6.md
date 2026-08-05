# Latest Nightly Changes  

## Features
- Fairysanity
  - 61 new additional checks (all 4 dungeons, plus clock town stray fairy) can now be included in item shuffling.
- Include Cowsanity
  - There are 7 new additional checks (2 grottos, and Romani Ranch Barn) that are now included in the item shuffle.
  - The requirements are still an empty bottle, and Epona's Song.
- Included hint system overrides for default text
  - Things like Beaver Race and the Bank Reward will now notify you of the item it can potentially give.
- Adjust bank reward values to 200-500-1000 for ease of use.
  - Note: If you go over the amount for a reward (e.g. depositing 500 rupees as your first reward), you will need to withdraw under the second reward (down to 499 rupees) and then deposit to the second reward to claim the second banker reward.
- Add Song of Time hint to clock tower door if it is shuffled.


## Fixes
- Adjust byte/nibble alignment in text storage as it was causing issues with colouring the first text.
- Refactor multi-area checks internally so they are easier to maintain (Thanks Nessy!)
- Add some hardcoded text continues for specific messages to avoid softlocks.
- Adjust moon child to specifically check for custom messages to avoid having an automatic A button press (fix the hacky fix).