#include <string>
#include <array>
#include <vector>
#include <string_view>
#include <algorithm>
#include <3ds.h>
#include <cstdio>

#include "settings.hpp"
#include "logic.hpp"
#include "setting_descriptions.hpp"
#include "keys.hpp"

using namespace Settings;

namespace Logic {

	bool noVariable = false;
	//item logic
	bool Ocarina = false;
	bool KokiriSword = false;
	bool HasBottle = false;
	bool Bombchus = false;
	bool DekuStick = false;
	bool MagicBean = false;
	bool MagicBeanPack = false;
	bool LensOfTruth = false;
	bool Bow = false;
	bool HerosBow = false;
	bool FireArrows = false;
	bool IceArrows = false;
	bool LightArrows = false;
	bool Hookshot = false;
	bool Pictobox = false;
	bool PowderKeg = false;
	bool Seahorse = false;
	bool DekuPrincess = false;
	bool BigPoe = false;
	bool Mushroom = false;
	bool SpringWater = false;
	bool HotSpringWater = false;
	bool SpinAttack = false;
	bool Epona = false;
	bool WitchBottle = false;
	bool AlienBottle = false;
	bool GoronRaceBottle = false;
	bool BeaverRaceBottle = false;
	bool DampeBottle = false;
	bool ChateauBottle = false;
	bool MysteryMilkBottle = false;
	bool BombersNotebook = false;
	bool MirrorShield = false;
	bool HerosShield = false;
	bool RazorSword = false;
	bool GildedSword = false;
	//bool GretFairysMask = false;
	bool BombBag20 = false;
	bool TownBombBag = false;
	bool MountainBombBag = false;
	bool TownArcheryQuiver = false;
	bool SwampArcheryQuiver = false;
	bool Townwallet200 = false;
	bool OceanWallet500 = false;
	bool MagicPower = false;
	bool ExtendedMagicPower = false;
	bool GreatFairySword = false;
	bool StoneTowerMagicBean = false;
	bool SwampScrubMagicBean = false;
	bool AllZoraEggs = false;
	//mask logic
	bool DekuMask = false;
	bool GoronMask = false;
	bool ZoraMask = false;
	bool KeatonMask = false;
	bool BunnyHood = false;
	bool PostmansHat = false;
	bool AllNightMask = false;
	bool BlastMask = false;
	bool StoneMask = false;
	bool GreatFairyMask = false;
	bool BremenMask = false;
	bool DonGerosMask = false;
	bool MaskOfScents = false;
	bool RomanisMask = false;
	bool CircusLeadersMask = false;
	bool KafeisMask = false;
	bool CouplesMask = false;
	bool KamarosMask = false;
	bool GibdosMask = false;
	bool GarosMask = false;
	bool CaptainsHat = false;
	bool GiantsMask = false;
	bool FierceDietyMask = false;
	bool MaskOfTruth = false;
	bool OneMask = false;
	bool TwoMasks = false;
	bool ThreeMasks = false;
	bool FourMasks = false;
	bool AllMasks = false;
	//trade items logic
	bool LandTitle = false;
	bool SwampTitle = false;
	bool MountainTitle = false;
	bool OceanTitle = false;
	bool RoomKey = false;
	bool LetterKafei = false;
	bool PendantOfMemories = false;
	bool LetterMama = false;
	bool MoonsTear = false;
	//trade quest events
	bool LandTitleAccess = false;
	bool SwampTitleAccess = false;
	bool MountainTitleAccess = false;
	bool OceanTitleAccess = false;
	bool RoomKeyAccess = false;
	bool LetterKafeiAccess = false;
	bool PendantAccess = false;
	bool LetterMamaAccess = false;
	bool MoonsTearAccess = false;
	//Songs
	bool ScarecrowSong = false;
	bool SongOfStorms = false;
	bool SonataOfAwakening = false;
	bool SongOfHealing = false;
	bool LullabyIntro = false;
	bool GoronsLullaby = false;
	bool NewWaveBossaNova = false;
	bool ElegyOfEmptiness = false;
	bool OathToOrder = false;
	bool EponasSong = false;
	bool SongOfSoaring = false;
	//Remains
	bool OdolwaRemains = false;
	bool GohtRemains = false;
	bool GyorgRemains = false;
	bool TwinmoldRemains = false;
	//Progressive Items
	u8 ProgressiveBow = 0;
	u8 ProgressiveMagic = 0;
	u8 ProgressiveWallet = 0;
	u8 ProgressiveBombBag = 0;
	u8 ProgressiveSword = 0;
	//Keys
	u8 WoodfallTempleKeys = 0;
	u8 SnowheadTempleKeys = 0;
	u8 GreatBayTempleKeys = 0;
	u8 StoneTowerTempleKeys = 0;
	//Boss Keys
	bool BossKeyWoodfallTemple = false;
	bool BossKeySnowheadTemple = false;
	bool BossKeyGreatBayTemple = false;
	bool BossKeyStoneTowerTemple = false;
	//Skulltula Counts
	u8 SwampSkulltulaTokens = 0;
	u8 OceanSkulltulaTokens = 0;
	//Stray Fairies
	u8 WoodfallStrayFairies = 0;
	u8 SnowheadStrayFairies = 0;
	u8 GreatBayStrayFairies = 0;
	u8 StoneTowerStrayFairies = 0;
	//Drops & Bottle Contents Access
	bool DekuNutDrop = false;
	bool NutPot = false;
	bool NutCrate = false;
	bool DekuBabaNuts = false;
	bool DekuStickDrop = false;
	bool StickPot = false;
	bool DekuBabaSticks = false;
	bool BugsAccess = false;
	bool BugShrub = false;
	bool WanderingBugs = false;
	bool BugRock = false;
	bool FishAccess = false;
	bool FishGroup = false;
	bool LoneFish = false;
	bool BombchuDrop = false;
	bool BuyBombchus5 = false;
	bool BuyBombchus10 = false;
	bool BuyBombchus20 = false;
	bool Water = false;
	bool WaterAccess = false;
	bool HotSpringWaterAccess = false;
	//Helpers, Events, Locations
	bool MagicMeter = false;
	bool BombBag = false;
	bool Explosives = false;
	bool Scarecrow = false;
	bool Bombs = false;
	bool Nuts = false;
	bool Sticks = false;
	bool Bugs = false;
	bool Fish = false;
	bool HasBombchus = false;
	bool FoundBombchus = false;
	bool HasExplosives = false;
	bool CanBlastOrSmash = false;
	bool CanCutShrubs = false;
	bool CanDive = false;
	bool CanPlantBugs = false;
	bool CanRideEpona = false;
	bool CanPlantBean = false;
	bool CanOpenBombGrotto = false;
	bool CanOpenStormGrotto = false;
	bool HasFireSource = false;
	bool HasFireSourceWithTorch = false;
	bool HasShield = false;
	bool CanShield = false;
	bool IsItem = false;
	bool CanShootBubble = false;
	bool CanUseProjectile = false;
	bool Arrows = false;
	bool AnyBottle = false;
	bool AnySword = false;
	bool AnyBombBag = false;
	bool AnyMagicBean = false;
	bool WaterForBeans = false;
	bool TwoBottles = false;
	bool AnyWallet = false;
	bool LimitlessBeans = false;
	bool AnyShield = false;
	bool AnyHealingPotion = false;
	bool AnyRedPotion = false;
	bool AnyBluePotion = false;
	bool UseFireArrow = false;
	bool UseIceArrow = false;
	bool UseLightArrow = false;
	bool AnyBSword = false;
	//dungeon clears
	bool WoodfallClear = false;
	bool SnowheadClear = false;
	bool GreatBayClear = false;
	bool StoneTowerClear = false;
	//Locational Helpers
	bool PoisonSwampAccess = false;
	bool WoodfallTempleAccess = false;
	bool NorthAccess = false;
	bool SnowheadTempleAccess = false;
	bool EponaAccess = false;
	bool WestAccess = false;
	bool PiratesFortressAccess = false;
	bool GreatBayTempleAccess = false;
	bool EastAccess = false;
	bool IkanaCanyonAccess = false;
	bool StoneTowerTempleAcccess = false;
	bool InvertedStoneTowerTempleAccess = false;
	bool MoonAccess = false;
	bool OneWoodfallKey = false;
	bool OneSnowheadKey = false;
	bool TwoSnowheadKeys = false;
	bool OneGreatBayKey = false;
	bool OneStoneTowerKey = false;
	bool TwoStoneTowerKeys = false;
	bool ThreeStoneTowerKeys = false;
	bool SwampSpiderhouseTreeRoom = false;
	bool OceanSkulltulas = false;
	bool IkanaGraveyardAccess = false;
	bool FightTwinmold = false;
	bool PinnacleRockAccess = false;
	bool ExitOceanSpiderHouse = false;
	bool NightInnAccess = false;
	bool EnterSnowheadTemple = false;
	bool GBTReverseWaterDirection = false;
	bool Fighting = false;
	bool CrossPoisonWater = false;
	bool AccessToAllOceanSpiders = false;
	bool AccessToAllSwampSpiders = false;
	bool ClockTownStrayFairy = false;
	bool AllWoodfallStrays = false;
	bool AllSnowheadStrays = false;
	bool AllGreatBayStrays = false;
	bool AllStoneTowerStrays = false;
	bool AnyPaper = false;
	//Tricks
	bool DekuStickFighting = false;
	bool PoisonWaterAsZora = false;
	bool WFT2ndFloorSkip = false;
	bool TakeDamage = false;

	//NewHelpers
	bool SHSwitchPress = false;
	bool ReverseWaterFlow = false;
	bool RedSwitch = false;
	bool RedSwitch2 = false;
	bool GreenSwitch = false;
	bool GreenSwitch2 = false;
	bool GreenValve = false;
	bool PirateBees = false;
	bool MusicBoxOn = false;
	bool IkanaLightSwitch = false;
	bool IkanaCastleRoofHole = false;
	bool ArmosRoomLightHole = false;
	bool InvertedChestSpawn = false;
	bool EnterSakonHideout = false;
	bool SunMask = false;
	bool WatchMoonTearFall =false;
	bool OldLadySaved = false;
	bool DekuPrincessReturned = false;
	bool LaundryFrog = false;
	bool SwampFrog = false;
	bool WoodfallFrog = false;
	bool GreatBayFrog = false;
	bool ThinBridgeCrystalChest = false;

	bool CanGoToMoon = false;
	
	u8 ZoraEgg = 0;

	//placement tracking
	u8 AddedProgressiveBombBags = 0;
	u8 AddedProgressiveMagics = 0;
	u8 AddedProgressiveBows = 0;
	u8 AddedProgressiveWallets = 0;
	u8 SwampTokensInPool = 0;
	u8 OceanTokensInPool = 0;
	u8 WFStraysInPool = 0;
	u8 SHStraysInPool = 0;
	u8 STStraysInPool = 0;
	u8 PlacedMasks = 0;
	u8 PiecesOfHeart = 0;
	u8 HeartContainers = 0;
    
	bool CanPlay(bool song) {
		return Ocarina && song;
	}

	static bool IsMagicItem(ItemKey item) {
		return item == LENS_OF_TRUTH || 
		       item == GIANTS_MASK;
	}

	static bool IsMagicArrow(ItemKey item) {
		return item == FIRE_ARROWS ||
			item == ICE_ARROWS ||
			item == LIGHT_ARROWS;
	}
	static bool IsItemOrMask(ItemKey item) {
		return (item == KOKIRI_SWORD) ||
			(item == DEKU_STICK) ||
			(item == LENS_OF_TRUTH) ||
			(item == HEROS_BOW) ||
			(item == SCARECROW) ||
			(item == FIRE_ARROWS) ||
			(item == ICE_ARROWS) ||
			(item == LIGHT_ARROWS) ||
			(item == DEKU_STICK) ||
			(item == PICTOGRAPH_BOX) ||
			(item == POWDER_KEG) ||
			(item == DEKU_MASK) ||
			(item == GORON_MASK) ||
			(item == ZORA_MASK) ||
			(item == BLAST_MASK) ||
			(item == GREAT_FAIRYS_MASK) ||
			(item == POSTMANS_HAT) ||
			(item == ALL_NIGHT_MASK) ||
			(item == BREMEN_MASK) ||
			(item == DON_GEROS_MASK) ||
			(item == MASK_OF_SCENTS) ||
			(item == ROMANIS_MASK) ||
			(item == CIRCUS_LEADERS_MASK) ||
			(item == KAFEIS_MASK) ||
			(item == KAFEIS_MASK) ||
			(item == COUPLES_MASK) ||
			(item == GIBDOS_MASK) ||
			(item == GAROS_MASK) ||
			(item == CAPTAINS_HAT) ||
			(item == GIANTS_MASK) ||
			(item == FIERCE_DIETY_MASK) ||
			(item == MASK_OF_TRUTH);
	}
	static bool HasItem(ItemKey itemName) {
		return (itemName == KOKIRI_SWORD && KokiriSword) ||
			(itemName == LENS_OF_TRUTH && LensOfTruth) ||
			(itemName == HEROS_BOW && HerosBow) ||
			(itemName == DEKU_STICK && DekuStick)||
			(itemName == SCARECROW && Scarecrow) ||
			(itemName == FIRE_ARROWS && FireArrows) ||
			(itemName == ICE_ARROWS && IceArrows) ||
			(itemName == LIGHT_ARROWS && LightArrows) ||
			(itemName == DEKU_STICK && Sticks) ||
			(itemName == PICTOGRAPH_BOX && Pictobox) ||
			(itemName == POWDER_KEG && PowderKeg) ||
			(itemName == DEKU_MASK && DekuMask) ||
			(itemName == GORON_MASK && GoronMask) ||
			(itemName == ZORA_MASK && ZoraMask) ||
			(itemName == BLAST_MASK && BlastMask) ||
			(itemName == GREAT_FAIRYS_MASK && GreatFairyMask) ||
			(itemName == POSTMANS_HAT && PostmansHat) ||
			(itemName == ALL_NIGHT_MASK && AllNightMask) ||
			(itemName == BREMEN_MASK && BremenMask) ||
			(itemName == DON_GEROS_MASK && DonGerosMask) ||
			(itemName == MASK_OF_SCENTS && MaskOfScents) ||
			(itemName == ROMANIS_MASK && RomanisMask) ||
			(itemName == CIRCUS_LEADERS_MASK && CircusLeadersMask) ||
			(itemName == KAFEIS_MASK && KafeisMask) ||
			(itemName == KAMAROS_MASK && KamarosMask) ||
			(itemName == COUPLES_MASK && CouplesMask) ||
			(itemName == GIBDOS_MASK && GibdosMask) ||
			(itemName == GAROS_MASK && GarosMask) ||
			(itemName == CAPTAINS_HAT && CaptainsHat) ||
			(itemName == GIANTS_MASK && GiantsMask) ||
			(itemName == FIERCE_DIETY_MASK && FierceDietyMask) ||
			(itemName == MASK_OF_TRUTH && MaskOfTruth);
	}

	bool CanUse(ItemKey itemName) {
		return (IsMagicItem(itemName) && HasItem(itemName) && MagicMeter) ||
			(IsMagicArrow(itemName) && HasItem(itemName) && MagicMeter && Bow) ||
			(IsItemOrMask(itemName) && HasItem(itemName));
	}

	bool HasProjectile(ItemKey itemName) {
		return (IsItemOrMask(itemName) && HasItem(itemName) && Bow);
	}

	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount) {
		return (dungeonKeyCount >= requiredAmount);
	}

	bool ZoraEggCount(u8 currentEggCount, u8 requiredAmount) {
		return (currentEggCount >= requiredAmount);
	}

	bool StrayFairyCount(u8 strayFairyCount, u8 requiredAmount) {
		return (strayFairyCount >= requiredAmount);
	}

	bool SkulltulaCount(u8 currentSkulltulaCount, u8 requiredAmount) {
		return (currentSkulltulaCount >= requiredAmount);
	}

	bool TotalHeartContainers(u8 requiredAmount) {
		return (HeartContainers + (PiecesOfHeart/4) + 3 >= requiredAmount);
	}

	u8 TotalMaskCount() { 
		u8 TotalMasks = 0;
		if(KeatonMask){TotalMasks++;}
		if(BunnyHood){TotalMasks++;}
		if(PostmansHat){TotalMasks++;}
		if(AllNightMask){TotalMasks++;}
		if(BlastMask){TotalMasks++;}
		if(StoneMask){TotalMasks++;}
		if(GreatFairyMask){TotalMasks++;}
		if(BremenMask){TotalMasks++;}
		if(DonGerosMask){TotalMasks++;}
		if(MaskOfScents){TotalMasks++;}
		if(RomanisMask){TotalMasks++;}
		if(CircusLeadersMask){TotalMasks++;}
		if(KafeisMask){TotalMasks++;}
		if(CouplesMask){TotalMasks++;}
		if(KamarosMask){TotalMasks++;}
		if(GibdosMask){TotalMasks++;}
		if(GarosMask){TotalMasks++;}
		if(CaptainsHat){TotalMasks++;}
		if(GiantsMask){TotalMasks++;}
		if(MaskOfTruth){TotalMasks++;}
		return TotalMasks;
	}

	void UpdateHelpers() {
		//Drop Access
		DekuStickDrop = StickPot || DekuBabaSticks;
		DekuNutDrop = NutPot || NutCrate || DekuBabaNuts;
		BugsAccess = BugShrub || WanderingBugs || BugRock;
		FishAccess = LoneFish || FishGroup;
		WaterAccess = (SpringWater && AnyBottle) || CanPlay(SongOfStorms);
		HotSpringWaterAccess = HotSpringWater && AnyBottle;
		WaterForBeans = (AnyBottle && WaterAccess) || SongOfStorms;
		AnyMagicBean = (MagicBean || MagicBeanPack || LimitlessBeans);
		//refills
		Bombs = AnyBombBag;
		Nuts = DekuNutDrop;
		Sticks = DekuStickDrop || DekuStick;
		Bugs = HasBottle && BugsAccess;
		Fish = HasBottle && FishAccess;
		
		//Other Helpers
		CanBlastOrSmash = HasExplosives || GoronMask;
		CanDive = CanUse(ZORA_MASK);
		CanPlantBugs = HasBottle && BugsAccess;
		CanRideEpona = Epona && CanPlay(EponasSong);
		CanPlantBean = AnyMagicBean || MagicBeanPack;
		CanOpenStormGrotto = CanPlay(SongOfStorms);
		CanOpenBombGrotto = CanBlastOrSmash;
		DekuStickFighting = Sticks;
		HasFireSource = CanUse(FIRE_ARROWS);
		HasFireSourceWithTorch = Sticks;
		AnySword = GreatFairySword || AnyBSword;
		AnyBSword = KokiriSword || RazorSword || GildedSword || (ProgressiveSword >= 1);
		NightInnAccess = DekuMask || RoomKey;
		
		Fighting = GoronMask || ZoraMask || AnySword || DekuStickFighting;
		AnyShield = HerosShield|| MirrorShield;
		CanUseProjectile = HasExplosives || HerosBow || (ProgressiveBow >= 1);
		
		//Item Helpers
		AnyMagicBean = MagicBean || LimitlessBeans;
		AnyWallet = Townwallet200 || OceanWallet500 || (ProgressiveWallet >= 1);
		AnyBottle = WitchBottle || AlienBottle || BeaverRaceBottle || DampeBottle || GoronRaceBottle || ChateauBottle || MysteryMilkBottle || HasBottle;
		MagicMeter = (ProgressiveMagic >= 1) || MagicPower || ExtendedMagicPower;
		WaterForBeans = (AnyBottle && (SpringWater || HotSpringWater)) || SongOfStorms;
		Scarecrow = Hookshot && CanPlay(ScarecrowSong);
		AnyPaper = (LandTitle || SwampTitle || OceanTitle || MountainTitle || LetterKafei || LetterMama);
		
		//Bombs & Bombchus
		AnyBombBag = (ProgressiveBombBag >= 1) || BombBag20 || TownBombBag || MountainBombBag;
		Explosives = BlastMask || AnyBombBag;
		HasBombchus = (BuyBombchus5 || BuyBombchus10 || BuyBombchus20) && AnyBombBag;
		FoundBombchus = Bombchus;
		
		//Bow & Arrows
		Bow = (ProgressiveBow >= 1) || HerosBow;
		
		//Bottle Items
		AnyHealingPotion = AnyRedPotion || AnyBluePotion;
		AnyRedPotion = AnyBottle;
		AnyBluePotion = AnyBottle;
		TwoBottles = { (WitchBottle && AlienBottle) || (WitchBottle && BeaverRaceBottle) || (WitchBottle && DampeBottle) ||
					(WitchBottle && GoronRaceBottle) || (WitchBottle && ChateauBottle) || (AlienBottle && GoronRaceBottle) ||
					(AlienBottle && BeaverRaceBottle) || (AlienBottle && DampeBottle) || (AlienBottle && ChateauBottle) ||
					(GoronRaceBottle && BeaverRaceBottle) || (GoronRaceBottle && DampeBottle) || (GoronRaceBottle && ChateauBottle) ||
					(BeaverRaceBottle && DampeBottle) || (BeaverRaceBottle && ChateauBottle) || (DampeBottle && ChateauBottle) || 
					(WitchBottle && MysteryMilkBottle) || (AlienBottle && MysteryMilkBottle) || (BeaverRaceBottle && MysteryMilkBottle) || 
					(DampeBottle && MysteryMilkBottle) || (GoronRaceBottle && MysteryMilkBottle) || (ChateauBottle && MysteryMilkBottle)};
		
		//Tricks
		PoisonWaterAsZora = ZoraMask && TakeDamage;
		WFT2ndFloorSkip = Hookshot;
		//Mask helpers
		OneMask = (PostmansHat || AllNightMask || BlastMask || StoneMask || GreatFairyMask || KeatonMask || BremenMask || BunnyHood ||
			DonGerosMask || MaskOfScents || RomanisMask || CircusLeadersMask || KafeisMask || CouplesMask || MaskOfTruth || KamarosMask ||
			GibdosMask || GarosMask || CaptainsHat || GiantsMask);
		TwoMasks = false;
		ThreeMasks = false;
		FourMasks=false;
		AllMasks = (PostmansHat && AllNightMask && BlastMask && StoneMask && GreatFairyMask && KeatonMask && BremenMask && BunnyHood &&
				DonGerosMask && MaskOfScents && RomanisMask && CircusLeadersMask && KafeisMask && CouplesMask && MaskOfTruth && KamarosMask &&
				GibdosMask && GarosMask && CaptainsHat && GiantsMask);
	}

	bool EventsUpdated() {
		return false;
	}
	//Resets all logic to false
	void LogicReset() {
		  noVariable = false;
	//item logic
	  Ocarina = false;
	  KokiriSword = false;
	  HasBottle = false;
	  Bombchus = false;
	  DekuStick = false;
	  MagicBean = false;
	  MagicBeanPack = false;
	  LensOfTruth = false;
	  Bow = false;
	  HerosBow = false;
	  FireArrows = false;
	  IceArrows = false;
	  LightArrows = false;
	  Hookshot = false;
	  Pictobox = false;
	  PowderKeg = false;
	  Seahorse = false;
	  DekuPrincess = false;
	  BigPoe = false;
	  Mushroom = false;
	  SpringWater = false;
	  HotSpringWater = false;
	  SpinAttack = false;
	  Epona = false;
	  WitchBottle = false;
	  AlienBottle = false;
	  GoronRaceBottle = false;
	  BeaverRaceBottle = false;
	  DampeBottle = false;
	  ChateauBottle = false;
	  MysteryMilkBottle = false;
	  BombersNotebook = false;
	  MirrorShield = false;
	  HerosShield = false;
	  RazorSword = false;
	  GildedSword = false;
	//  GretFairysMask = false;
	  BombBag20 = false;
	  TownBombBag = false;
	  MountainBombBag = false;
	  TownArcheryQuiver = false;
	  SwampArcheryQuiver = false;
	  Townwallet200 = false;
	  OceanWallet500 = false;
	  MagicPower = false;
	  ExtendedMagicPower = false;
	  GreatFairySword = false;
	  StoneTowerMagicBean = false;
	  SwampScrubMagicBean = false;

	//mask logic
	  DekuMask = false;
	  GoronMask = false;
	  ZoraMask = false;
	  KeatonMask = false;
	  BunnyHood = false;
	  PostmansHat = false;
	  AllNightMask = false;
	  BlastMask = false;
	  StoneMask = false;
	  GreatFairyMask = false;
	  BremenMask = false;
	  DonGerosMask = false;
	  MaskOfScents = false;
	  RomanisMask = false;
	  CircusLeadersMask = false;
	  KafeisMask = false;
	  CouplesMask = false;
	  KamarosMask = false;
	  GibdosMask = false;
	  GarosMask = false;
	  CaptainsHat = false;
	  GiantsMask = false;
	  FierceDietyMask = false;
	  MaskOfTruth = false;
	  OneMask = false;
	  TwoMasks = false;
	  ThreeMasks = false;
	  FourMasks = false;
	  AllMasks = false;
	//trade items logic
	  LandTitle = false;
	  SwampTitle = false;
	  MountainTitle = false;
	  OceanTitle = false;
	  RoomKey = false;
	  LetterKafei = false;
	  PendantOfMemories = false;
	  LetterMama = false;
	  MoonsTear = false;
	//trade quest events
	  LandTitleAccess = false;
	  SwampTitleAccess = false;
	  MountainTitleAccess = false;
	  OceanTitleAccess = false;
	  RoomKeyAccess = false;
	  LetterKafeiAccess = false;
	  PendantAccess = false;
	  LetterMamaAccess = false;
	  MoonsTearAccess = false;
	//Songs
	  ScarecrowSong = false;
	  SongOfStorms = false;
	  SonataOfAwakening = false;
	  SongOfHealing = false;
	  LullabyIntro = false;
	  GoronsLullaby = false;
	  NewWaveBossaNova = false;
	  ElegyOfEmptiness = false;
	  OathToOrder = false;
	  EponasSong = false;
	  SongOfSoaring = false;
	//Remains
	  OdolwaRemains = false;
	  GohtRemains = false;
	  GyorgRemains = false;
	  TwinmoldRemains = false;
	  
	//Progressive Items
	ProgressiveBow = 0;
	ProgressiveMagic = 0;
	ProgressiveWallet = 0;
	ProgressiveBombBag = 0;
	ProgressiveSword = 0;
	//Keys
	 WoodfallTempleKeys = 0;
	 SnowheadTempleKeys = 0;
	 GreatBayTempleKeys = 0;
	 StoneTowerTempleKeys = 0;
	//Boss Keys
	  BossKeyWoodfallTemple = false;
	  BossKeySnowheadTemple = false;
	  BossKeyGreatBayTemple = false;
	  BossKeyStoneTowerTemple = false;
	//Skulltula Counts
	SwampSkulltulaTokens = 0;
	OceanSkulltulaTokens = 0;
	//Stray Fairies
	WoodfallStrayFairies = 0;
	SnowheadStrayFairies = 0;
	GreatBayStrayFairies = 0;
	StoneTowerStrayFairies = 0;
	//Drops & Bottle Contents Access
	  DekuNutDrop = false;
	  NutPot = false;
	  NutCrate = false;
	  DekuBabaNuts = false;
	  DekuStickDrop = false;
	  StickPot = false;
	  DekuBabaSticks = false;
	  BugsAccess = false;
	  BugShrub = false;
	  WanderingBugs = false;
	  BugRock = false;
	  FishAccess = false;
	  FishGroup = false;
	  LoneFish = false;
	  BombchuDrop = false;
	  BuyBombchus5 = false;
	  BuyBombchus10 = false;
	  BuyBombchus20 = false;
      Water = false;
	  WaterAccess = false;
	  HotSpringWaterAccess = false;
	//Helpers, Events, Locations
	  MagicMeter = false;
	  BombBag = false;
	  Explosives = false;
	  Scarecrow = false;
	  Bombs = false;
	  Nuts = false;
	  Sticks = false;
	  Bugs = false;
	  Fish = false;
	  HasBombchus = false;
	  FoundBombchus = false;
	  HasExplosives = false;
	  CanBlastOrSmash = false;
	  CanCutShrubs = false;
	  CanDive = false;
	  CanPlantBugs = false;
	  CanRideEpona = false;
	  CanPlantBean = false;
	  CanOpenBombGrotto = false;
	  CanOpenStormGrotto = false;
	  HasFireSource = false;
	  HasFireSourceWithTorch = false;
	  HasShield = false;
	  CanShield = false;
	  IsItem = false;
	  CanShootBubble = false;
	  CanUseProjectile = false;
	  Arrows = false;
	  AnyBottle = false;
	  AnySword = false;
	  AnyBombBag = false;
	  AnyMagicBean = false;
	  WaterForBeans = false;
	  TwoBottles = false;
	  AnyWallet = false;
	  LimitlessBeans = false;
	  AnyShield = false;
	  AnyHealingPotion = false;
	  AnyRedPotion = false;
	  AnyBluePotion = false;
	  UseFireArrow = false;
	  UseIceArrow = false;
	  UseLightArrow = false;
	  AnyBSword = false;
	  AllZoraEggs = false;
	//dungeon clears
	  WoodfallClear = false;
	  SnowheadClear = false;
	  GreatBayClear = false;
	  StoneTowerClear = false;
	//Locational Helpers
	  PoisonSwampAccess = false;
	  WoodfallTempleAccess = false;
	  NorthAccess = false;
	  SnowheadTempleAccess = false;
	  EponaAccess = false;
	  WestAccess = false;
	  PiratesFortressAccess = false;
	  GreatBayTempleAccess = false;
	  EastAccess = false;
	  IkanaCanyonAccess = false;
	  StoneTowerTempleAcccess = false;
	  InvertedStoneTowerTempleAccess = false;
	  MoonAccess = false;
	  OneWoodfallKey = false;
	  OneSnowheadKey = false;
	  TwoSnowheadKeys = false;
	  OneGreatBayKey = false;
	  OneStoneTowerKey = false;
	  TwoStoneTowerKeys = false;
	  ThreeStoneTowerKeys = false;
	  SwampSpiderhouseTreeRoom = false;
	  OceanSkulltulas = false;
	  IkanaGraveyardAccess = false;
	  FightTwinmold = false;
	  PinnacleRockAccess = false;
	  ExitOceanSpiderHouse = false;
	  NightInnAccess = false;
	  EnterSnowheadTemple = false;
	  GBTReverseWaterDirection = false;
	  Fighting = false;
	  CrossPoisonWater = false;
	  AccessToAllOceanSpiders = false;
	  AccessToAllSwampSpiders = false;
	  ClockTownStrayFairy = false;
	  AllWoodfallStrays = false;
	  AllSnowheadStrays = false;
	  AllGreatBayStrays = false;
	  AllStoneTowerStrays = false;
	  AnyPaper = false;
	//Tricks
	  DekuStickFighting = false;
	  PoisonWaterAsZora = false;
	  WFT2ndFloorSkip = false;
	  TakeDamage = false;

	//New Things
	SHSwitchPress = false;
	ReverseWaterFlow = false;
	RedSwitch = false;
	RedSwitch2 = false;
	GreenSwitch = false;
	GreenSwitch2 = false;
	GreenValve = false;
	PirateBees = false;
	MusicBoxOn = false;
	IkanaLightSwitch = false;
	IkanaCastleRoofHole = false;
	ArmosRoomLightHole = false;
	InvertedChestSpawn = false;
	EnterSakonHideout = false;
	SunMask = false;
	WatchMoonTearFall = false;
	OldLadySaved = false;
	DekuPrincessReturned = false;
	LaundryFrog = false;
	SwampFrog = false;
	WoodfallFrog = false;
	GreatBayFrog = false;
	ThinBridgeCrystalChest = false;

	
	ZoraEgg = 0;
	CanGoToMoon = false;
	//placement tracking
	AddedProgressiveBombBags = 0;
	AddedProgressiveMagics = 0;
	AddedProgressiveBows = 0;
	AddedProgressiveWallets = 0;
	SwampTokensInPool = 0;
	OceanTokensInPool = 0;
	WFStraysInPool = 0;
	SHStraysInPool = 0;
	STStraysInPool = 0;
	PlacedMasks = 0;
	PiecesOfHeart = 0;
	HeartContainers = 0;
	
	}
}

