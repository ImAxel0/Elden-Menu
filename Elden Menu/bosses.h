#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx12.h"
#include "ImGui/imgui_impl_win32.h"

#include <iostream>
#include <string>
#include "ModUtils.h"

// 0 = alive

using namespace ModUtils;

std::string bosses_window = "main";

// Limgrave
bool AlabasterLord_Limgrave = false;
bool BeastmanofFaramAzula_Limgrave = false;
bool BellBearingHunter_Limgrave = false;
bool BlackKnifeAssassin_Limgrave = false;
bool BloodhoundKnightDarriwil_Limgrave = false;
bool CrucibleKnight_Limgrave = false;
bool Deathbird_Limgrave = false;
bool Demi_HumanChiefs_Limgrave = false;
bool ErdtreeBurialWatchdog_Limgrave = false;
bool FlyingDragonAgheel_Limgrave = false;
bool GodricktheGrafted_Limgrave = false;
bool GraftedScion_Limgrave = false;
bool GraveWardenDuelist_Limgrave = false;
bool GuardianGolem_Limgrave = false;
bool MadPumpkinHead_Limgrave = false;
bool MargittheFellOmen_Limgrave = false;
bool NightCavalry_Limgrave = false;
bool Patches_Limgrave = false;
bool SoldierofGodrick_Limgrave = false;
bool StonediggerTroll_Limgrave = false;
bool TibiaMariner_Limgrave = false;
bool TreeSentinel_Limgrave = false;
bool UlceratedTreeSpirit_Limgrave = false;

byte* AlabasterLord_LimgraveAddr{};
byte* BeastmanofFaramAzula_LimgraveAddr{};
byte* BellBearingHunter_LimgraveAddr{};
byte* BlackKnifeAssassin_LimgraveAddr{};
byte* BloodhoundKnightDarriwil_LimgraveAddr{};
byte* CrucibleKnight_LimgraveAddr{};
byte* Deathbird_LimgraveAddr{};
byte* Demi_HumanChiefs_LimgraveAddr{};
byte* ErdtreeBurialWatchdog_LimgraveAddr{};
byte* FlyingDragonAgheel_LimgraveAddr{};
byte* GodricktheGrafted_LimgraveAddr{};
byte* GraftedScion_LimgraveAddr{};
byte* GraveWardenDuelist_LimgraveAddr{};
byte* GuardianGolem_LimgraveAddr{};
byte* MadPumpkinHead_LimgraveAddr{};
byte* MargittheFellOmen_LimgraveAddr{};
byte* NightCavalry_LimgraveAddr{};
byte* Patches_LimgraveAddr{};
byte* SoldierofGodrick_LimgraveAddr{};
byte* StonediggerTroll_LimgraveAddr{};
byte* TibiaMariner_LimgraveAddr{};
byte* TreeSentinel_LimgraveAddr{};
byte* UlceratedTreeSpirit_LimgraveAddr{};

//Weeping peninsula
bool AncientHeroofZamor_WeepingPeninsula = false;
bool CemeteryShade_WeepingPeninsula = false;
bool Deathbird_WeepingPeninsula = false;
bool ErdtreeAvatar_WeepingPeninsula = false;
bool ErdtreeBurialWatchdog_WeepingPeninsula = false;
bool LeonineMisbegotten_WeepingPeninsula = false;
bool MirandatheBlightedBloom_WeepingPeninsula = false;
bool NightCavalry_WeepingPeninsula = false;
bool Runebear_WeepingPeninsula = false;
bool ScalyMisbegotten_WeepingPeninsula = false;

byte* AncientHeroofZamor_WeepingPeninsulaAddr{};
byte* CemeteryShade_WeepingPeninsulaAddr{};
byte* Deathbird_WeepingPeninsulaAddr{};
byte* ErdtreeAvatar_WeepingPeninsulaAddr{};
byte* ErdtreeBurialWatchdog_WeepingPeninsulaAddr{};
byte* LeonineMisbegotten_WeepingPeninsulaAddr{};
byte* MirandatheBlightedBloom_WeepingPeninsulaAddr{};
byte* NightCavalry_WeepingPeninsulaAddr{};
byte* Runebear_WeepingPeninsulaAddr{};
byte* ScalyMisbegotten_WeepingPeninsulaAddr{};

// Liurnia of the Lakes
bool AdanThiefofFire_Liurnia = false;
bool AlectoBlackKnifeRingleader_Liurnia = false;
bool BellBearingHunter_Liurnia = false;
bool BlackKnifeAssassin_Liurnia = false;
bool BloodhoundKnight_Liurnia = false;
bool BolsCarianKnight_Liurnia = false;
bool CemeteryShade_Liurnia = false;
bool CleanrotKnight_Liurnia = false;
bool Crystalian_Liurnia = false;
bool CrystalianSpearAndCrystalianStaff_Liurnia = false;
bool DeathRiteBird_Liurnia = false;
bool Deathbird_Liurnia = false;
bool ErdtreeAvatarNortheast_Liurnia = false;
bool ErdtreeAvatarSouthwest_Liurnia = false;
bool ErdtreeBurialWatchdog_Liurnia = false;
bool GlintstoneDragonAdula_Liurnia = false;
bool GlintstoneDragonSmarag_Liurnia = false;
bool MagmaWyrmMakar_Liurnia = false;
bool NightCavalryNorth_Liurnia = false;
bool NightCavalrySouth_Liurnia = false;
bool Omenkiller_Liurnia = false;
bool OnyxLord_Liurnia = false;
bool RedWolfofRadagon_Liurnia = false;
bool RennalaQueenoftheFullMoon_Liurnia = false;
bool RoyalKnightLoretta_Liurnia = false;
bool RoyalRevenant_Liurnia = false;
bool SpiritcallerSnail_Liurnia = false;
bool TibiaMariner_Liurnia = false;

byte* AdanThiefofFire_LiurniaAddr{};
byte* AlectoBlackKnifeRingleader_LiurniaAddr{};
byte* BellBearingHunter_LiurniaAddr{};
byte* BlackKnifeAssassin_LiurniaAddr{};
byte* BloodhoundKnight_LiurniaAddr{};
byte* BolsCarianKnight_LiurniaAddr{};
byte* CemeteryShade_LiurniaAddr{};
byte* CleanrotKnight_LiurniaAddr{};
byte* Crystalian_LiurniaAddr{};
byte* CrystalianSpearAndCrystalianStaff_LiurniaAddr{};
byte* DeathRiteBird_LiurniaAddr{};
byte* Deathbird_LiurniaAddr{};
byte* ErdtreeAvatarNortheast_LiurniaAddr{};
byte* ErdtreeAvatarSouthwest_LiurniaAddr{};
byte* ErdtreeBurialWatchdog_LiurniaAddr{};
byte* GlintstoneDragonAdula_LiurniaAddr{};
byte* GlintstoneDragonSmarag_LiurniaAddr{};
byte* MagmaWyrmMakar_LiurniaAddr{};
byte* NightCavalryNorth_LiurniaAddr{};
byte* NightCavalrySouth_LiurniaAddr{};
byte* Omenkiller_LiurniaAddr{};
byte* OnyxLord_LiurniaAddr{};
byte* RedWolfofRadagon_LiurniaAddr{};
byte* RennalaQueenoftheFullMoon_LiurniaAddr{};
byte* RoyalKnightLoretta_LiurniaAddr{};
byte* RoyalRevenant_LiurniaAddr{};
byte* SpiritcallerSnail_LiurniaAddr{};
byte* TibiaMariner_LiurniaAddr{};

// Caelid
bool CemeteryShade_Caelid = false;
bool CommanderONeil_Caelid = false;
bool CrucibleKnightMisbegottenWarrior_Caelid = false;
bool DeathRiteBird_Caelid = false;
bool DecayingEkzykes_Caelid = false;
bool ElderDragonGreyoll_Caelid = false;
bool ErdtreeBurialWatchdogs_Caelid = false;
bool FallingstarBeast_Caelid = false;
bool FrenziedDuelist_Caelid = false;
bool MadPumpkinHeads_Caelid = false;
bool MagmaWyrm_Caelid = false;
bool NightCavalry_Caelid = false;
bool NoxSwordstressandNoxPriest_Caelid = false;
bool PutridAvatar_Caelid = false;
bool StarscourgeRadahn_Caelid = false;

byte* CemeteryShade_CaelidAddr{};
byte* CommanderONeil_CaelidAddr{};
byte* CrucibleKnightMisbegottenWarrior_CaelidAddr{};
byte* DeathRiteBird_CaelidAddr{};
byte* DecayingEkzykes_CaelidAddr{};
byte* ElderDragonGreyoll_CaelidAddr{};
byte* ErdtreeBurialWatchdogs_CaelidAddr{};
byte* FallingstarBeast_CaelidAddr{};
byte* FrenziedDuelist_CaelidAddr{};
byte* MadPumpkinHeads_CaelidAddr{};
byte* MagmaWyrm_CaelidAddr{};
byte* NightCavalry_CaelidAddr{};
byte* NoxSwordstressandNoxPriest_CaelidAddr{};
byte* PutridAvatar_CaelidAddr{};
byte* StarscourgeRadahn_CaelidAddr{};

// Dragonbarrow
bool BattlemageHugues_Dragonbarrow = false;
bool BeastmenofFaramAzula_Dragonbarrow = false;
bool BellBearingHunter_Dragonbarrow = false;
bool BlackBladeKindred_Dragonbarrow = false;
bool CleanrotKnights_Dragonbarrow = false;
bool FlyingDragonGreyll_Dragonbarrow = false;
bool GodskinApostle_Dragonbarrow = false;
bool NightCavalry_Dragonbarrow = false;
bool PutridAvatar_Dragonbarrow = false;
bool PutridCrystalians_Dragonbarrow = false;
bool PutridTreeSpirit_Dragonbarrow = false;

byte* BattlemageHugues_DragonbarrowAddr{};
byte* BeastmenofFaramAzula_DragonbarrowAddr{};
byte* BellBearingHunter_DragonbarrowAddr{};
byte* BlackBladeKindred_DragonbarrowAddr{};
byte* CleanrotKnights_DragonbarrowAddr{};
byte* FlyingDragonGreyll_DragonbarrowAddr{};
byte* GodskinApostle_DragonbarrowAddr{};
byte* NightCavalry_DragonbarrowAddr{};
byte* PutridAvatar_DragonbarrowAddr{};
byte* PutridCrystalians_DragonbarrowAddr{};
byte* PutridTreeSpirit_DragonbarrowAddr{};

// Altus Plateau
bool AncientDragonLansseax_Altus = false;
bool AncientHeroofZamor_Altus = false;
bool BlackKnifeAssassin1_Altus = false;
bool BlackKnifeAssassin2_Altus = false;
bool CrystalianSpearandCrystalianRingblade_Altus = false;
bool DemiHumanQueenGilika_Altus = false;
bool ElemeroftheBriar_Altus = false;
bool ErdtreeBurialWatchdog_Altus = false;
bool FallingstarBeast_Altus = false;
bool GodefroytheGrafted_Altus = false;
bool GodskinApostle_Altus = false;
bool NecromancerGarris_Altus = false;
bool NightCavalry_Altus = false;
bool OmenkillerandMirandatheBlightedBloom_Altus = false;
bool PerfumerTriciaandMisbegottenWarrior_Altus = false;
bool SanguineNoble_Altus = false;
bool StonediggerTroll_Altus = false;
bool TibiaMariner_Altus = false;
bool TreeSentinels_Altus = false;
bool Wormface_Altus = false;

byte* AncientDragonLansseax_AltusAddr{};
byte* AncientHeroofZamor_AltusAddr{};
byte* BlackKnifeAssassin1_AltusAddr{};
byte* BlackKnifeAssassin2_AltusAddr{};
byte* CrystalianSpearandCrystalianRingblade_AltusAddr{};
byte* DemiHumanQueenGilika_AltusAddr{};
byte* ElemeroftheBriar_AltusAddr{};
byte* ErdtreeBurialWatchdog_AltusAddr{};
byte* FallingstarBeast_AltusAddr{};
byte* GodefroytheGrafted_AltusAddr{};
byte* GodskinApostle_AltusAddr{};
byte* NecromancerGarris_AltusAddr{};
byte* NightCavalry_AltusAddr{};
byte* OmenkillerandMirandatheBlightedBloom_AltusAddr{};
byte* PerfumerTriciaandMisbegottenWarrior_AltusAddr{};
byte* SanguineNoble_AltusAddr{};
byte* StonediggerTroll_AltusAddr{};
byte* TibiaMariner_AltusAddr{};
byte* TreeSentinels_AltusAddr{};
byte* Wormface_AltusAddr{};

// Capital Outskirts
bool BellBearingHunter_Capital = false;
bool CrucibleKnightCrucibleKnightOrdovis_Capital = false;
bool Deathbird_Capital = false;
bool DraconicTreeSentinel_Capital = false;
bool FellTwins_Capital = false;
bool GraveWardenDuelist_Capital = false;
bool OnyxLord_Capital = false;

byte* BellBearingHunter_CapitalAddr{};
byte* CrucibleKnightCrucibleKnightOrdovis_CapitalAddr{};
byte* Deathbird_CapitalAddr{};
byte* DraconicTreeSentinel_CapitalAddr{};
byte* FellTwins_CapitalAddr{};
byte* GraveWardenDuelist_CapitalAddr{};
byte* OnyxLord_CapitalAddr{};

// Leyendell, Royal Capital
bool EsgarPriestofBlood_Layendell = false;
bool GodfreyFirstEldenLord_Layendell = false;
bool MohgtheOmen_Layendell = false;
bool MorgotttheOmenKing_Layendell = false;

byte* EsgarPriestofBlood_LayendellAddr{};
byte* GodfreyFirstEldenLord_LayendellAddr{};
byte* MohgtheOmen_LayendellAddr{};
byte* MorgotttheOmenKing_LayendellAddr{};

// Mt. Gelmir
bool AbductorVirgins_Gelmir = false;
bool DemiHumanQueenMaggie_Gelmir = false;
bool DemiHumanQueenMargot_Gelmir = false;
bool FullGrownFallingstarBeast_Gelmir = false;
bool GodDevouringSerpent_Rykard_Gelmir = false;
bool GodskinNoble_Gelmir = false;
bool KindredofRot_Gelmir = false;
bool MagmaWyrm_Gelmir = false;
bool RedWolfoftheChampion_Gelmir = false;
bool UlceratedTreeSpirit_Gelmir = false;

byte* AbductorVirgins_GelmirAddr{};
byte* DemiHumanQueenMaggie_GelmirAddr{};
byte* DemiHumanQueenMargot_GelmirAddr{};
byte* FullGrownFallingstarBeast_GelmirAddr{};
byte* GodDevouringSerpent_Rykard_GelmirAddr{};
byte* GodskinNoble_GelmirAddr{};
byte* KindredofRot_GelmirAddr{};
byte* MagmaWyrm_GelmirAddr{};
byte* RedWolfoftheChampion_GelmirAddr{};
byte* UlceratedTreeSpirit_GelmirAddr{};

// Mountaintops of the Giants
bool AncientHeroofZamor_Mountaintops = false;
bool BorealistheFreezingFog_Mountaintops = false;
bool CommanderNiall_Mountaintops = false;
bool DeathRiteBird_Mountaintops = false;
bool ErdtreeAvatar_Mountaintops = false;
bool FireGiant_Mountaintops = false;
bool GodskinApostleandGodskinNoble_Mountaintops = false;
bool UlceratedTreeSpirit_Mountaintops = false;
bool VykeKnightoftheRoundtable_Mountaintops = false;

byte* AncientHeroofZamor_MountaintopsAddr{};
byte* BorealistheFreezingFog_MountaintopsAddr{};
byte* CommanderNiall_MountaintopsAddr{};
byte* DeathRiteBird_MountaintopsAddr{};
byte* ErdtreeAvatar_MountaintopsAddr{};
byte* FireGiant_MountaintopsAddr{};
byte* GodskinApostleandGodskinNoble_MountaintopsAddr{};
byte* UlceratedTreeSpirit_MountaintopsAddr{};
byte* VykeKnightoftheRoundtable_MountaintopsAddr{};

// Crumbling Farum Azula
bool DragonlordPlacidusax_Azula = false;
bool GodskinDuo_Azula = false;
bool MalekiththeBlackBlade_Azula = false;

byte* DragonlordPlacidusax_AzulaAddr{};
byte* GodskinDuo_AzulaAddr{};
byte* MalekiththeBlackBlade_AzulaAddr{};

// Forbidden Lands
bool BlackBladeKindred_Forbidden = false;
bool NightCavalry_Forbidden = false;
bool StrayMimicTear_Forbidden = false;

byte* BlackBladeKindred_ForbiddenAddr{};
byte* NightCavalry_ForbiddenAddr{};
byte* StrayMimicTear_ForbiddenAddr{};

// Consecrated Snowfields
bool AstelStarsofDarkness_Snowfields = false;
bool DeathRiteBird_Snowfields = false;
bool GreatWyrmTheodorix_Snowfields = false;
bool MisbegottenCrusader_Snowfields = false;
bool NightCavalryDuo_Snowfields = false;
bool PutridAvatar_Snowfields = false;
bool PutridGraveWardenDuelist_Snowfields = false;

byte* AstelStarsofDarkness_SnowfieldsAddr{};
byte* DeathRiteBird_SnowfieldsAddr{};
byte* GreatWyrmTheodorix_SnowfieldsAddr{};
byte* MisbegottenCrusader_SnowfieldsAddr{};
byte* NightCavalryDuo_SnowfieldsAddr{};
byte* PutridAvatar_SnowfieldsAddr{};
byte* PutridGraveWardenDuelist_SnowfieldsAddr{};

// Miquella's Haligtree
bool LorettaKnightoftheHaligtree_Miquella = false;
bool MaleniaGoddessofRot_Miquella = false;

byte* LorettaKnightoftheHaligtree_MiquellaAddr{};
byte* MaleniaGoddessofRot_MiquellaAddr{};

// Siofra River
bool AncestorSpirit_Siofra = false;
bool DragonkinSoldier_Siofra = false;
bool MohgLordofBlood_Siofra = false;

byte* AncestorSpirit_SiofraAddr{};
byte* DragonkinSoldier_SiofraAddr{};
byte* MohgLordofBlood_SiofraAddr{};

// Ainsel River
bool DragonkinSoldierofNokstella_Ainsel = false;

byte* DragonkinSoldierofNokstella_AinselAddr{};

// Nokron Eternal City
bool MimicTear_Nokron = false;
bool RegalAncestorSpirit_Nokron = false;
bool ValiantGargoyles_Nokron = false;

byte* MimicTear_NokronAddr{};
byte* RegalAncestorSpirit_NokronAddr{};
byte* ValiantGargoyles_NokronAddr{};

// Deeproot Depths
bool CrucibleKnightSiluria_Deeproot = false;
bool FiaChampions_Deeproot = false;
bool LichdragonFortissax_Deeproot = false;

byte* CrucibleKnightSiluria_DeeprootAddr{};
byte* FiaChampions_DeeprootAddr{};
byte* LichdragonFortissax_DeeprootAddr{};

// Lake of Rot
bool AstelNaturalbornoftheVoid_LakeofRot = false;
bool DragonkinSoldier_LakeofRot = false;

byte* AstelNaturalbornoftheVoid_LakeofRotAddr{};
byte* DragonkinSoldier_LakeofRotAddr{};

// Leyendell, Ashen Capital
bool GodfreyFirstEldenLord_AshenCapital = false;
bool SirGideonOfnirtheAllKnowing_AshenCapital = false;

byte* GodfreyFirstEldenLord_AshenCapitalAddr{};
byte* SirGideonOfnirtheAllKnowing_AshenCapitalAddr{};

// Elden Throne
bool EldenBeast_EldenThrone = false;

byte* EldenBeast_EldenThroneAddr{};

void refreshBosses(uintptr_t EventFlagManRealReal)
{
	// I probably should have used a switch instead (ノv` *)

	if (bosses_window == "limgrave")
	{
		// Limgrave
		AlabasterLord_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x702D3 });	
		BeastmanofFaramAzula_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x170CC8 });
		BellBearingHunter_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA0E25 });
		BlackKnifeAssassin_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16AC1A });
		BloodhoundKnightDarriwil_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xB154E });
		CrucibleKnight_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA0AB4 });
		Deathbird_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA0E1F });
		Demi_HumanChiefs_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x174184 });
		ErdtreeBurialWatchdog_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16848D });
		FlyingDragonAgheel_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA9001 });
		GodricktheGrafted_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x151C33 });
		GraftedScion_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x152098 });
		GraveWardenDuelist_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x168D57 });
		GuardianGolem_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1745E9 });
		MadPumpkinHead_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xB18B9 });
		MargittheFellOmen_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x151C39 });
		NightCavalry_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA936C });
		Patches_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16FF99 });
		SoldierofGodrick_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15B608 });
		StonediggerTroll_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1787D4 });
		TibiaMariner_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xBABB2 });
		TreeSentinel_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA0749 });
		UlceratedTreeSpirit_LimgraveAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15B602 });
	}
	if (bosses_window == "Weeping Peninsula")
	{
		// Weeping Peninsula
		AncientHeroofZamor_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x9FD08 });
		CemeteryShade_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x167BC3 });
		Deathbird_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xB0B0D });
		ErdtreeAvatar_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA85C0 });
		ErdtreeBurialWatchdog_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x168028 });
		LeonineMisbegotten_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA7B7F });
		MirandatheBlightedBloom_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x170863 });
		NightCavalry_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xB0B13 });
		Runebear_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1703FE });
		ScalyMisbegotten_WeepingPeninsulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17836F });
	}
	if (bosses_window == "Liurnia of the Lakes")
	{
		AdanThiefofFire_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x7F580 });
		AlectoBlackKnifeRingleader_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x54D53 });
		BellBearingHunter_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x77DDF });
		BlackKnifeAssassin_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1691C2 });
		BloodhoundKnight_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x171592 });
		BolsCarianKnight_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x55794 });
		CemeteryShade_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1691BC });
		CleanrotKnight_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17112D });
		Crystalian_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x178C39 });
		CrystalianSpearAndCrystalianStaff_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1719F7 });
		DeathRiteBird_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x6F1BC });
		Deathbird_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x77033 });
		ErdtreeAvatarNortheast_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x80D6D });
		ErdtreeAvatarSouthwest_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x550BE });
		ErdtreeBurialWatchdog_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x169621 });
		GlintstoneDragonAdula_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x5D60B });
		GlintstoneDragonSmarag_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x5E04C });
		MagmaWyrmMakar_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15DD8F });
		NightCavalryNorth_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x158146 });
		NightCavalrySouth_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x8850E });
		Omenkiller_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x65EC3 });
		OnyxLord_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x702D3 });
		RedWolfofRadagon_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15814C });
		RennalaQueenoftheFullMoon_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x158146 });
		RoyalKnightLoretta_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x67A1B });
		RoyalRevenant_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x5EA8D });
		SpiritcallerSnail_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1688F2 });
		TibiaMariner_LiurniaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x88879 });
	}
	if (bosses_window == "Caelid")
	{
		CemeteryShade_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16BDAE });
		CommanderONeil_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDCB27 });
		CrucibleKnightMisbegottenWarrior_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xED5C1 });
		DeathRiteBird_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDC7C2 });
		DecayingEkzykes_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xD3F04 });
		ElderDragonGreyoll_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xE5AB5 });
		ErdtreeBurialWatchdogs_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16B949 });
		FallingstarBeast_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17A232 });
		FrenziedDuelist_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17577D });
		MadPumpkinHeads_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xD4945 });
		MagmaWyrm_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x179DCD });
		NightCavalry_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDC7BC });
		NoxSwordstressandNoxPriest_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDCE92 });
		PutridAvatar_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xCC08D });
		StarscourgeRadahn_CaelidAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1A1B02 });
	}
	if (bosses_window == "Dragonbarrow")
	{
		BattlemageHugues_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDCE98 });
		BeastmenofFaramAzula_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x172B8B });
		BellBearingHunter_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xD4CB0 });
		BlackBladeKindred_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xEEDAE });
		CleanrotKnights_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x175318 });
		FlyingDragonGreyll_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xF6F90 });
		GodskinApostle_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16310E });
		NightCavalry_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xF6F96 });
		PutridAvatar_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xEE36D });
		PutridCrystalians_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x172FF0 });
		PutridTreeSpirit_DragonbarrowAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16C213 });
	}
	if (bosses_window == "Altus Plateau")
	{
		AncientDragonLansseax_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x78EF6 });
		AncientHeroofZamor_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x169EEB });
		BlackKnifeAssassin1_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x174EB3 });
		BlackKnifeAssassin2_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x92C89 });
		CrystalianSpearandCrystalianRingblade_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x179968 });
		DemiHumanQueenGilika_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x817AE });
		ElemeroftheBriar_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x8AAA7 });
		ErdtreeBurialWatchdog_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x169A86 });
		FallingstarBeast_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x9AE6B });
		GodefroytheGrafted_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x89CFB });
		GodskinApostle_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA483A });
		NecromancerGarris_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x174EB9 });
		NightCavalry_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x8A066 });
		OmenkillerandMirandatheBlightedBloom_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x174A4E });
		PerfumerTriciaandMisbegottenWarrior_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16B07F });
		SanguineNoble_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x92FF4 });
		StonediggerTroll_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17909E });
		TibiaMariner_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x81B19 });
		TreeSentinels_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x9B1D6 });
		Wormface_AltusAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xA483A });
	}
	if (bosses_window == "Capital Outskirts")
	{
		BellBearingHunter_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xACA1C });
		CrucibleKnightCrucibleKnightOrdovis_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16A7B5 });
		Deathbird_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xB52D4 });
		DraconicTreeSentinel_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xBD821 });
		FellTwins_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x163579 });
		GraveWardenDuelist_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16B4E4 });
		OnyxLord_CapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x162CA9 });
	}
	if (bosses_window == "Leyendell, Royal Capital")
	{
		EsgarPriestofBlood_LayendellAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15D066 });
		GodfreyFirstEldenLord_LayendellAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x152DCD });
		MohgtheOmen_LayendellAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15D060 });
		MorgotttheOmenKing_LayendellAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x152DC7 });
	}
	if (bosses_window == "Mt. Gelmir")
	{
		AbductorVirgins_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x159BAB });
		DemiHumanQueenMaggie_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x795CC });
		DemiHumanQueenMargot_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x172726 });
		FullGrownFallingstarBeast_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x7107F });
		GodDevouringSerpent_Rykard_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x159BA4 });
		GodskinNoble_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x159BAA });
		KindredofRot_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x171E5C });
		MagmaWyrm_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x6845C });
		RedWolfoftheChampion_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16A350 });
		UlceratedTreeSpirit_GelmirAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x79938 });

	}
	if (bosses_window == "Mountaintops of the Giants")
	{
		AncientHeroofZamor_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16C678 });
		BorealistheFreezingFog_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1AA7A2 });
		CommanderNiall_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xF1D88 });
		DeathRiteBird_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xE94D0 });
		ErdtreeAvatar_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xFA2D5 });
		FireGiant_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1AAC07 });
		GodskinApostleandGodskinNoble_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x175BE2 });
		UlceratedTreeSpirit_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16CADD });
		VykeKnightoftheRoundtable_MountaintopsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x102B8D });
	}
	if (bosses_window == "Crumbling Farum Azula")
	{
		DragonlordPlacidusax_AzulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15741A });
		GodskinDuo_AzulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15741D });
		MalekiththeBlackBlade_AzulaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x157417 });
	}
	if (bosses_window == "Forbidden Lands")
	{
		BlackBladeKindred_ForbiddenAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xDFB01 });
		NightCavalry_ForbiddenAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xD6EDE });
		StrayMimicTear_ForbiddenAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16D3A7 });
	}
	if (bosses_window == "Consecrated Snowfields")
	{
		AstelStarsofDarkness_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17A697 });
		DeathRiteBird_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xD8360 });
		GreatWyrmTheodorix_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xE9165 });
		MisbegottenCrusader_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x173455 });
		NightCavalryDuo_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1ABD9B });
		PutridAvatar_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0xE94D6 });
		PutridGraveWardenDuelist_SnowfieldsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x16CF42 });
	}
	if (bosses_window == "Miquella's Haligtree")
	{
		LorettaKnightoftheHaligtree_MiquellaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x158E7B });
		//MaleniaGoddessofRot_MiquellaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x17A697 });
	}
	if (bosses_window == "Siofra River")
	{
		AncestorSpirit_SiofraAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x156B4D });
		DragonkinSoldier_SiofraAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1550F2 });
		MohgLordofBlood_SiofraAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x155E1E });
	}
	if (bosses_window == "Ainsel River")
	{
		DragonkinSoldierofNokstella_AinselAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x154C8A });
	}
	if (bosses_window == "Nokron Eternal City")
	{
		MimicTear_NokronAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1550F5 });
		RegalAncestorSpirit_NokronAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x156FB2 });
		ValiantGargoyles_NokronAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1550EF });
	}
	if (bosses_window == "Deeproot Depths")
	{
		CrucibleKnightSiluria_DeeprootAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x155520 });
		FiaChampions_DeeprootAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x155554 });
		LichdragonFortissax_DeeprootAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15555A });
	}
	if (bosses_window == "Lake of Rot")
	{
		AstelNaturalbornoftheVoid_LakeofRotAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1559B9 });
		DragonkinSoldier_LakeofRotAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x154C90 });
	}
	if (bosses_window == "Leyendell, Ashen Capital")
	{
		GodfreyFirstEldenLord_AshenCapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15322C });
		SirGideonOfnirtheAllKnowing_AshenCapitalAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x153232 });
	}
	if (bosses_window == "Elden Throne")
	{
		EldenBeast_EldenThroneAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x15C331 });
	}
}

void applyBosses(byte byte)
{
	if (bosses_window == "limgrave")
	{
		if (AlabasterLord_Limgrave) {
			*AlabasterLord_LimgraveAddr = byte;
		}
		if (BeastmanofFaramAzula_Limgrave) {
			*BeastmanofFaramAzula_LimgraveAddr = byte;
		}
		if (BellBearingHunter_Limgrave) {
			*BellBearingHunter_LimgraveAddr = byte;
		}
		if (BlackKnifeAssassin_Limgrave) {
			*BlackKnifeAssassin_LimgraveAddr = byte;
		}
		if (BloodhoundKnightDarriwil_Limgrave) {
			*BloodhoundKnightDarriwil_LimgraveAddr = byte;
		}
		if (CrucibleKnight_Limgrave) {
			*CrucibleKnight_LimgraveAddr = byte;
		}
		if (Deathbird_Limgrave) {
			*Deathbird_LimgraveAddr = byte;
		}
		if (Demi_HumanChiefs_Limgrave) {
			*Demi_HumanChiefs_LimgraveAddr = byte;
		}
		if (ErdtreeBurialWatchdog_Limgrave) {
			*ErdtreeBurialWatchdog_LimgraveAddr = byte;
		}
		if (FlyingDragonAgheel_Limgrave) {
			*FlyingDragonAgheel_LimgraveAddr = byte;
		}
		if (GodricktheGrafted_Limgrave) {
			*GodricktheGrafted_LimgraveAddr = byte;
		}
		if (GraftedScion_Limgrave) {
			*GraftedScion_LimgraveAddr = byte;
		}
		if (GraveWardenDuelist_Limgrave) {
			*GraveWardenDuelist_LimgraveAddr = byte;
		}
		if (GuardianGolem_Limgrave) {
			*GuardianGolem_LimgraveAddr = byte;
		}
		if (MadPumpkinHead_Limgrave) {
			*MadPumpkinHead_LimgraveAddr = byte;
		}
		if (MargittheFellOmen_Limgrave) {
			*MargittheFellOmen_LimgraveAddr = byte;
		}
		if (NightCavalry_Limgrave) {
			*NightCavalry_LimgraveAddr = byte;
		}
		if (Patches_Limgrave) {
			*Patches_LimgraveAddr = byte;
		}
		if (SoldierofGodrick_Limgrave) {
			*SoldierofGodrick_LimgraveAddr = byte;
		}
		if (StonediggerTroll_Limgrave) {
			*StonediggerTroll_LimgraveAddr = byte;
		}
		if (TibiaMariner_Limgrave) {
			*TibiaMariner_LimgraveAddr = byte;
		}
		if (TreeSentinel_Limgrave) {
			*TreeSentinel_LimgraveAddr = byte;
		}
		if (UlceratedTreeSpirit_Limgrave) {
			*UlceratedTreeSpirit_LimgraveAddr = byte;
		}
	}
	if (bosses_window == "Weeping Peninsula")
	{
		if (AncientHeroofZamor_WeepingPeninsula) {
			*AncientHeroofZamor_WeepingPeninsulaAddr = byte;
		}

		if (CemeteryShade_WeepingPeninsula) {
			*CemeteryShade_WeepingPeninsulaAddr = byte;
		}

		if (Deathbird_WeepingPeninsula) {
			*Deathbird_WeepingPeninsulaAddr = byte;
		}

		if (ErdtreeAvatar_WeepingPeninsula) {
			*ErdtreeAvatar_WeepingPeninsulaAddr = byte;
		}

		if (ErdtreeBurialWatchdog_WeepingPeninsula) {
			*ErdtreeBurialWatchdog_WeepingPeninsulaAddr = byte;
		}

		if (LeonineMisbegotten_WeepingPeninsula) {
			*LeonineMisbegotten_WeepingPeninsulaAddr = byte;
		}

		if (MirandatheBlightedBloom_WeepingPeninsula) {
			*MirandatheBlightedBloom_WeepingPeninsulaAddr = byte;
		}

		if (NightCavalry_WeepingPeninsula) {
			*NightCavalry_WeepingPeninsulaAddr = byte;
		}

		if (Runebear_WeepingPeninsula) {
			*Runebear_WeepingPeninsulaAddr = byte;
		}

		if (ScalyMisbegotten_WeepingPeninsula) {
			*ScalyMisbegotten_WeepingPeninsulaAddr = byte;
		}
	}
	if (bosses_window == "Liurnia of the Lakes")
	{
		if (AdanThiefofFire_Liurnia) {
			*AdanThiefofFire_LiurniaAddr = byte;
		}
		if (AlectoBlackKnifeRingleader_Liurnia) {
			*AlectoBlackKnifeRingleader_LiurniaAddr = byte;
		}
		if (BellBearingHunter_Liurnia) {
			*BellBearingHunter_LiurniaAddr = byte;
		}
		if (BlackKnifeAssassin_Liurnia) {
			*BlackKnifeAssassin_LiurniaAddr = byte;
		}
		if (BloodhoundKnight_Liurnia) {
			*BloodhoundKnight_LiurniaAddr = byte;
		}
		if (BolsCarianKnight_Liurnia) {
			*BolsCarianKnight_LiurniaAddr = byte;
		}
		if (CemeteryShade_Liurnia) {
			*CemeteryShade_LiurniaAddr = byte;
		}
		if (CleanrotKnight_Liurnia) {
			*CleanrotKnight_LiurniaAddr = byte;
		}
		if (Crystalian_Liurnia) {
			*Crystalian_LiurniaAddr = byte;
		}
		if (CrystalianSpearAndCrystalianStaff_Liurnia) {
			*CrystalianSpearAndCrystalianStaff_LiurniaAddr = byte;
		}
		if (DeathRiteBird_Liurnia) {
			*DeathRiteBird_LiurniaAddr = byte;
		}
		if (Deathbird_Liurnia) {
			*Deathbird_LiurniaAddr = byte;
		}
		if (ErdtreeAvatarNortheast_Liurnia) {
			*ErdtreeAvatarNortheast_LiurniaAddr = byte;
		}
		if (ErdtreeAvatarSouthwest_Liurnia) {
			*ErdtreeAvatarSouthwest_LiurniaAddr = byte;
		}
		if (ErdtreeBurialWatchdog_Liurnia) {
			*ErdtreeBurialWatchdog_LiurniaAddr = byte;
		}
		if (GlintstoneDragonAdula_Liurnia) {
			*GlintstoneDragonAdula_LiurniaAddr = byte;
		}
		if (GlintstoneDragonSmarag_Liurnia) {
			*GlintstoneDragonSmarag_LiurniaAddr = byte;
		}
		if (MagmaWyrmMakar_Liurnia) {
			*MagmaWyrmMakar_LiurniaAddr = byte;
		}
		if (NightCavalryNorth_Liurnia) {
			*NightCavalryNorth_LiurniaAddr = byte;
		}
		if (NightCavalrySouth_Liurnia) {
			*NightCavalrySouth_LiurniaAddr = byte;
		}
		if (Omenkiller_Liurnia) {
			*Omenkiller_LiurniaAddr = byte;
		}
		if (OnyxLord_Liurnia) {
			*OnyxLord_LiurniaAddr = byte;
		}
		if (RedWolfofRadagon_Liurnia) {
			*RedWolfofRadagon_LiurniaAddr = byte;
		}
		if (RennalaQueenoftheFullMoon_Liurnia) {
			*RennalaQueenoftheFullMoon_LiurniaAddr = byte;
		}
		if (RoyalKnightLoretta_Liurnia) {
			*RoyalKnightLoretta_LiurniaAddr = byte;
		}
		if (RoyalRevenant_Liurnia) {
			*RoyalRevenant_LiurniaAddr = byte;
		}
		if (SpiritcallerSnail_Liurnia) {
			*SpiritcallerSnail_LiurniaAddr = byte;
		}
		if (TibiaMariner_Liurnia) {
			*TibiaMariner_LiurniaAddr = byte;
		}
	}
	if (bosses_window == "Caelid")
	{
		if (CemeteryShade_Caelid) {
			*CemeteryShade_CaelidAddr = byte;
		}

		if (CommanderONeil_Caelid) {
			*CommanderONeil_CaelidAddr = byte;
		}

		if (CrucibleKnightMisbegottenWarrior_Caelid) {
			*CrucibleKnightMisbegottenWarrior_CaelidAddr = byte;
		}

		if (DeathRiteBird_Caelid) {
			*DeathRiteBird_CaelidAddr = byte;
		}

		if (DecayingEkzykes_Caelid) {
			*DecayingEkzykes_CaelidAddr = byte;
		}

		if (ElderDragonGreyoll_Caelid) {
			*ElderDragonGreyoll_CaelidAddr = byte;
		}

		if (ErdtreeBurialWatchdogs_Caelid) {
			*ErdtreeBurialWatchdogs_CaelidAddr = byte;
		}

		if (FallingstarBeast_Caelid) {
			*FallingstarBeast_CaelidAddr = byte;
		}

		if (FrenziedDuelist_Caelid) {
			*FrenziedDuelist_CaelidAddr = byte;
		}

		if (MadPumpkinHeads_Caelid) {
			*MadPumpkinHeads_CaelidAddr = byte;
		}

		if (MagmaWyrm_Caelid) {
			*MagmaWyrm_CaelidAddr = byte;
		}

		if (NightCavalry_Caelid) {
			*NightCavalry_CaelidAddr = byte;
		}

		if (NoxSwordstressandNoxPriest_Caelid) {
			*NoxSwordstressandNoxPriest_CaelidAddr = byte;
		}

		if (PutridAvatar_Caelid) {
			*PutridAvatar_CaelidAddr = byte;
		}

		if (StarscourgeRadahn_Caelid) {
			*StarscourgeRadahn_CaelidAddr = byte;
		}
	}
	if (bosses_window == "Dragonbarrow")
	{
		if (BattlemageHugues_Dragonbarrow) {
			*BattlemageHugues_DragonbarrowAddr = byte;
		}

		if (BeastmenofFaramAzula_Dragonbarrow) {
			*BeastmenofFaramAzula_DragonbarrowAddr = byte;
		}

		if (BellBearingHunter_Dragonbarrow) {
			*BellBearingHunter_DragonbarrowAddr = byte;
		}

		if (BlackBladeKindred_Dragonbarrow) {
			*BlackBladeKindred_DragonbarrowAddr = byte;
		}

		if (CleanrotKnights_Dragonbarrow) {
			*CleanrotKnights_DragonbarrowAddr = byte;
		}

		if (FlyingDragonGreyll_Dragonbarrow) {
			*FlyingDragonGreyll_DragonbarrowAddr = byte;
		}

		if (GodskinApostle_Dragonbarrow) {
			*GodskinApostle_DragonbarrowAddr = byte;
		}

		if (NightCavalry_Dragonbarrow) {
			*NightCavalry_DragonbarrowAddr = byte;
		}

		if (PutridAvatar_Dragonbarrow) {
			*PutridAvatar_DragonbarrowAddr = byte;
		}

		if (PutridCrystalians_Dragonbarrow) {
			*PutridCrystalians_DragonbarrowAddr = byte;
		}

		if (PutridTreeSpirit_Dragonbarrow) {
			*PutridTreeSpirit_DragonbarrowAddr = byte;
		}
	}
	if (bosses_window == "Altus Plateau")
	{
		if (AncientDragonLansseax_Altus) {
			*AncientDragonLansseax_AltusAddr = byte;
		}

		if (AncientHeroofZamor_Altus) {
			*AncientHeroofZamor_AltusAddr = byte;
		}

		if (BlackKnifeAssassin1_Altus) {
			*BlackKnifeAssassin1_AltusAddr = byte;
		}

		if (BlackKnifeAssassin2_Altus) {
			*BlackKnifeAssassin2_AltusAddr = byte;
		}

		if (CrystalianSpearandCrystalianRingblade_Altus) {
			*CrystalianSpearandCrystalianRingblade_AltusAddr = byte;
		}

		if (DemiHumanQueenGilika_Altus) {
			*DemiHumanQueenGilika_AltusAddr = byte;
		}

		if (ElemeroftheBriar_Altus) {
			*ElemeroftheBriar_AltusAddr = byte;
		}

		if (ErdtreeBurialWatchdog_Altus) {
			*ErdtreeBurialWatchdog_AltusAddr = byte;
		}

		if (FallingstarBeast_Altus) {
			*FallingstarBeast_AltusAddr = byte;
		}

		if (GodefroytheGrafted_Altus) {
			*GodefroytheGrafted_AltusAddr = byte;
		}

		if (GodskinApostle_Altus) {
			*GodskinApostle_AltusAddr = byte;
		}

		if (NecromancerGarris_Altus) {
			*NecromancerGarris_AltusAddr = byte;
		}

		if (NightCavalry_Altus) {
			*NightCavalry_AltusAddr = byte;
		}

		if (OmenkillerandMirandatheBlightedBloom_Altus) {
			*OmenkillerandMirandatheBlightedBloom_AltusAddr = byte;
		}

		if (PerfumerTriciaandMisbegottenWarrior_Altus) {
			*PerfumerTriciaandMisbegottenWarrior_AltusAddr = byte;
		}

		if (SanguineNoble_Altus) {
			*SanguineNoble_AltusAddr = byte;
		}

		if (StonediggerTroll_Altus) {
			*StonediggerTroll_AltusAddr = byte;
		}

		if (TibiaMariner_Altus) {
			*TibiaMariner_AltusAddr = byte;
		}

		if (TreeSentinels_Altus) {
			*TreeSentinels_AltusAddr = byte;
		}

		if (Wormface_Altus) {
			*Wormface_AltusAddr = byte;
		}
	}
	if (bosses_window == "Capital Outskirts")
	{
		if (BellBearingHunter_Capital) {
			*BellBearingHunter_CapitalAddr = byte;
		}

		if (CrucibleKnightCrucibleKnightOrdovis_Capital) {
			*CrucibleKnightCrucibleKnightOrdovis_CapitalAddr = byte;
		}

		if (Deathbird_Capital) {
			*Deathbird_CapitalAddr = byte;
		}

		if (DraconicTreeSentinel_Capital) {
			*DraconicTreeSentinel_CapitalAddr = byte;
		}

		if (FellTwins_Capital) {
			*FellTwins_CapitalAddr = byte;
		}

		if (GraveWardenDuelist_Capital) {
			*GraveWardenDuelist_CapitalAddr = byte;
		}

		if (OnyxLord_Capital) {
			*OnyxLord_CapitalAddr = byte;
		}
	}
	if (bosses_window == "Leyendell, Royal Capital")
	{
		if (EsgarPriestofBlood_Layendell) {
			*EsgarPriestofBlood_LayendellAddr = byte;
		}

		if (GodfreyFirstEldenLord_Layendell) {
			*GodfreyFirstEldenLord_LayendellAddr = byte;
		}

		if (MohgtheOmen_Layendell) {
			*MohgtheOmen_LayendellAddr = byte;
		}

		if (MorgotttheOmenKing_Layendell) {
			*MorgotttheOmenKing_LayendellAddr = byte;
		}
	}
	if (bosses_window == "Mt. Gelmir")
	{
		if (AbductorVirgins_Gelmir) {
			*AbductorVirgins_GelmirAddr = byte;
		}

		if (DemiHumanQueenMaggie_Gelmir) {
			*DemiHumanQueenMaggie_GelmirAddr = byte;
		}

		if (DemiHumanQueenMargot_Gelmir) {
			*DemiHumanQueenMargot_GelmirAddr = byte;
		}

		if (FullGrownFallingstarBeast_Gelmir) {
			*FullGrownFallingstarBeast_GelmirAddr = byte;
		}

		if (GodDevouringSerpent_Rykard_Gelmir) {
			*GodDevouringSerpent_Rykard_GelmirAddr = byte;
		}

		if (GodskinNoble_Gelmir) {
			*GodskinNoble_GelmirAddr = byte;
		}

		if (KindredofRot_Gelmir) {
			*KindredofRot_GelmirAddr = byte;
		}

		if (MagmaWyrm_Gelmir) {
			*MagmaWyrm_GelmirAddr = byte;
		}

		if (RedWolfoftheChampion_Gelmir) {
			*RedWolfoftheChampion_GelmirAddr = byte;
		}

		if (UlceratedTreeSpirit_Gelmir) {
			*UlceratedTreeSpirit_GelmirAddr = byte;
		}
	}
	if (bosses_window == "Mountaintops of the Giants")
	{
		if (AncientHeroofZamor_Mountaintops) {
			*AncientHeroofZamor_MountaintopsAddr = byte;
		}

		if (BorealistheFreezingFog_Mountaintops) {
			*BorealistheFreezingFog_MountaintopsAddr = byte;
		}

		if (CommanderNiall_Mountaintops) {
			*CommanderNiall_MountaintopsAddr = byte;
		}

		if (DeathRiteBird_Mountaintops) {
			*DeathRiteBird_MountaintopsAddr = byte;
		}

		if (ErdtreeAvatar_Mountaintops) {
			*ErdtreeAvatar_MountaintopsAddr = byte;
		}

		if (FireGiant_Mountaintops) {
			*FireGiant_MountaintopsAddr = byte;
		}

		if (GodskinApostleandGodskinNoble_Mountaintops) {
			*GodskinApostleandGodskinNoble_MountaintopsAddr = byte;
		}

		if (UlceratedTreeSpirit_Mountaintops) {
			*UlceratedTreeSpirit_MountaintopsAddr = byte;
		}

		if (VykeKnightoftheRoundtable_Mountaintops) {
			*VykeKnightoftheRoundtable_MountaintopsAddr = byte;
		}
	}
	if (bosses_window == "Crumbling Farum Azula")
	{
		if (DragonlordPlacidusax_Azula) {
			*DragonlordPlacidusax_AzulaAddr = byte;
		}

		if (GodskinDuo_Azula) {
			*GodskinDuo_AzulaAddr = byte;
		}

		if (MalekiththeBlackBlade_Azula) {
			*MalekiththeBlackBlade_AzulaAddr = byte;
		}
	}
	if (bosses_window == "Forbidden Lands")
	{
		if (BlackBladeKindred_Forbidden) {
			*BlackBladeKindred_ForbiddenAddr = byte;
		}

		if (NightCavalry_Forbidden) {
			*NightCavalry_ForbiddenAddr = byte;
		}

		if (StrayMimicTear_Forbidden) {
			*StrayMimicTear_ForbiddenAddr = byte;
		}
	}
	if (bosses_window == "Consecrated Snowfields")
	{
		if (AstelStarsofDarkness_Snowfields) {
			*AstelStarsofDarkness_SnowfieldsAddr = byte;
		}
		if (DeathRiteBird_Snowfields) {
			*DeathRiteBird_SnowfieldsAddr = byte;
		}
		if (GreatWyrmTheodorix_Snowfields) {
			*GreatWyrmTheodorix_SnowfieldsAddr = byte;
		}
		if (MisbegottenCrusader_Snowfields) {
			*MisbegottenCrusader_SnowfieldsAddr = byte;
		}
		if (NightCavalryDuo_Snowfields) {
			*NightCavalryDuo_SnowfieldsAddr = byte;
		}
		if (PutridAvatar_Snowfields) {
			*PutridAvatar_SnowfieldsAddr = byte;
		}
		if (PutridGraveWardenDuelist_Snowfields) {
			*PutridGraveWardenDuelist_SnowfieldsAddr = byte;
		}
	}
	if (bosses_window == "Miquella's Haligtree")
	{
		if (LorettaKnightoftheHaligtree_Miquella) {
			*LorettaKnightoftheHaligtree_MiquellaAddr = byte;
		}

		if (MaleniaGoddessofRot_Miquella) {
			*MaleniaGoddessofRot_MiquellaAddr = byte;
		}
	}
	if (bosses_window == "Siofra River")
	{
		if (AncestorSpirit_Siofra) {
			*AncestorSpirit_SiofraAddr = byte;
		}

		if (DragonkinSoldier_Siofra) {
			*DragonkinSoldier_SiofraAddr = byte;
		}

		if (MohgLordofBlood_Siofra) {
			*MohgLordofBlood_SiofraAddr = byte;
		}
	}
	if (bosses_window == "Ainsel River")
	{
		if (DragonkinSoldierofNokstella_Ainsel) {
			*DragonkinSoldierofNokstella_AinselAddr = byte;
		}
	}
	if (bosses_window == "Nokron Eternal City")
	{
		if (MimicTear_Nokron) {
			*MimicTear_NokronAddr = byte;
		}

		if (RegalAncestorSpirit_Nokron) {
			*RegalAncestorSpirit_NokronAddr = byte;
		}

		if (ValiantGargoyles_Nokron) {
			*ValiantGargoyles_NokronAddr = byte;
		}
	}
	if (bosses_window == "Deeproot Depths")
	{
		if (CrucibleKnightSiluria_Deeproot) {
			*CrucibleKnightSiluria_DeeprootAddr = byte;
		}

		if (FiaChampions_Deeproot) {
			*FiaChampions_DeeprootAddr = byte;
		}

		if (LichdragonFortissax_Deeproot) {
			*LichdragonFortissax_DeeprootAddr = byte;
		}
	}
	if (bosses_window == "Lake of Rot")
	{
		if (AstelNaturalbornoftheVoid_LakeofRot) {
			*AstelNaturalbornoftheVoid_LakeofRotAddr = byte;
		}

		if (DragonkinSoldier_LakeofRot) {
			*DragonkinSoldier_LakeofRotAddr = byte;
		}
	}
	if (bosses_window == "Leyendell, Ashen Capital")
	{
		if (GodfreyFirstEldenLord_AshenCapital) {
			*GodfreyFirstEldenLord_AshenCapitalAddr = byte;
		}

		if (SirGideonOfnirtheAllKnowing_AshenCapital) {
			*SirGideonOfnirtheAllKnowing_AshenCapitalAddr = byte;
		}
	}
	if (bosses_window == "Elden Throne")
	{
		if (EldenBeast_EldenThrone) {
			*EldenBeast_EldenThroneAddr = byte;
		}
	}
}

void bossesCheckUI()
{

	if (bosses_window == "main")
	{
		if (ImGui::Button("Limgrave  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "limgrave";
		}

		if (ImGui::Button("Weeping Peninsula  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Weeping Peninsula";
		}

		if (ImGui::Button("Liurnia of the Lakes  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Liurnia of the Lakes";
		}

		if (ImGui::Button("Caelid  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Caelid";
		}

		if (ImGui::Button("Dragonbarrow  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Dragonbarrow";
		}

		if (ImGui::Button("Altus Plateau  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Altus Plateau";
		}

		if (ImGui::Button("Capital Outskirts   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Capital Outskirts";
		}

		if (ImGui::Button("Leyendell, Royal Capital   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Leyendell, Royal Capital";
		}

		if (ImGui::Button("Mt. Gelmir   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Mt. Gelmir";
		}

		if (ImGui::Button("Mountaintops of the Giants   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Mountaintops of the Giants";
		}

		if (ImGui::Button("Crumbling Farum Azula   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Crumbling Farum Azula";
		}

		if (ImGui::Button("Forbidden Lands   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Forbidden Lands";
		}

		if (ImGui::Button("Consecrated Snowfields   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Consecrated Snowfields";
		}

		if (ImGui::Button("Miquella's Haligtree   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Miquella's Haligtree";
		}

		if (ImGui::Button("Siofra River   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Siofra River";
		}

		if (ImGui::Button("Ainsel River   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Ainsel River";
		}

		if (ImGui::Button("Nokron Eternal City   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Nokron Eternal City";
		}

		if (ImGui::Button("Deeproot Depths   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Deeproot Depths";
		}

		if (ImGui::Button("Lake of Rot   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Lake of Rot";
		}

		if (ImGui::Button("Leyendell, Ashen Capital   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Leyendell, Ashen Capital";
		}

		if (ImGui::Button("Elden Throne   " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "Elden Throne";
		}
	}

	if (bosses_window == "limgrave")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Limgrave
		ImGui::Checkbox("Alabaster Lord (Evergaol)", &AlabasterLord_Limgrave);
		ImGui::Checkbox("Beastman of Faram Azula (Groveside Cave)", &BeastmanofFaramAzula_Limgrave);
		ImGui::Checkbox("Bell Bearing Hunter (Warmaster's Shack)", &BellBearingHunter_Limgrave);
		ImGui::Checkbox("Black Knife Assassin (Deathtouched Catacombs)", &BlackKnifeAssassin_Limgrave);
		ImGui::Checkbox("Bloodhound Knight Darriwil (Forlorn Hound Evergaol)", &BloodhoundKnightDarriwil_Limgrave);
		ImGui::Checkbox("Crucible Knight (Stormhill Evergaol)", &CrucibleKnight_Limgrave);
		ImGui::Checkbox("Deathbird (Limgrave)", &Deathbird_Limgrave);
		ImGui::Checkbox("Demi-Human Chiefs (Coastal Cave)", &Demi_HumanChiefs_Limgrave);
		ImGui::Checkbox("Erdtree Burial Watchdog (Stormfront Catacombs)", &ErdtreeBurialWatchdog_Limgrave);
		ImGui::Checkbox("Flying Dragon Agheel (Limgrave)", &FlyingDragonAgheel_Limgrave);
		ImGui::Checkbox("Godrick the Grafted", &GodricktheGrafted_Limgrave);
		ImGui::Checkbox("Grafted Scion (Chapel of Anticipation)", &GraftedScion_Limgrave);
		ImGui::Checkbox("Grave Warden Duelist (Murkwater Catacombs)", &GraveWardenDuelist_Limgrave);
		ImGui::Checkbox("Guardian Golem (Highroad Cave)", &GuardianGolem_Limgrave);
		ImGui::Checkbox("Mad Pumpkin Head (Waypoint Ruins)", &MadPumpkinHead_Limgrave);
		ImGui::Checkbox("Margit the Fell Omen", &MargittheFellOmen_Limgrave);
		ImGui::Checkbox("Night's Cavalry (Limgrave)", &NightCavalry_Limgrave);
		ImGui::Checkbox("Patches (Murkwater Cave)", &Patches_Limgrave);
		ImGui::Checkbox("Soldier of Godrick", &SoldierofGodrick_Limgrave);
		ImGui::Checkbox("Stonedigger Troll (Limgrave Tunnels)", &StonediggerTroll_Limgrave);
		ImGui::Checkbox("Tibia Mariner (Summonwater Village)", &TibiaMariner_Limgrave);
		ImGui::Checkbox("Tree Sentinel (Limgrave)", &TreeSentinel_Limgrave);
		ImGui::Checkbox("Ulcerated Tree Spirit (Fringefolk Hero's Grave)", &UlceratedTreeSpirit_Limgrave);
	}
	if (bosses_window == "Weeping Peninsula")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Weeping Peninsula
		ImGui::Checkbox("Ancient Hero of Zamor (Weeping Evergaol)", &AncientHeroofZamor_WeepingPeninsula);
		ImGui::Checkbox("Cemetery Shade (Tombsward Catacombs)", &CemeteryShade_WeepingPeninsula);
		ImGui::Checkbox("Deathbird (Weeping Peninsula)", &Deathbird_WeepingPeninsula);
		ImGui::Checkbox("Erdtree Avatar", &ErdtreeAvatar_WeepingPeninsula);
		ImGui::Checkbox("Edtree Burial Watchdog (Impaler's Catacombs)", &ErdtreeBurialWatchdog_WeepingPeninsula);
		ImGui::Checkbox("Leonine Misbegotten (Morne Moangrave)", &LeonineMisbegotten_WeepingPeninsula);
		ImGui::Checkbox("Miranda the Blighted Bloom (Tombsward Cave)", &MirandatheBlightedBloom_WeepingPeninsula);
		ImGui::Checkbox("Night's Cavalry (Weeping Peninsula)", &NightCavalry_WeepingPeninsula);
		ImGui::Checkbox("Runebear (Earthbore Cave)", &Runebear_WeepingPeninsula);
		ImGui::Checkbox("Scaly Misbegotten (Morne Tunnels)", &ScalyMisbegotten_WeepingPeninsula);
	}
	if (bosses_window == "Liurnia of the Lakes")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Liurnia
		ImGui::Checkbox("Adan, Thief of Fire (Malefactor's Evergaol)", &AdanThiefofFire_Liurnia);
		ImGui::Checkbox("Alecto, Black Knife Ringleader (Ringleader's Evergaol)", &AlectoBlackKnifeRingleader_Liurnia);
		ImGui::Checkbox("Bell Bearing Hunter (Church of Vows)", &BellBearingHunter_Liurnia);
		ImGui::Checkbox("Black Knife Assassin (Black Knife Catacombs)", &BlackKnifeAssassin_Liurnia);
		ImGui::Checkbox("Bloodhound Knight (Lakeside Crystal Cave)", &BloodhoundKnight_Liurnia);
		ImGui::Checkbox("Bols, Carian Knight (Cuckoo's Evergaol)", &BolsCarianKnight_Liurnia);
		ImGui::Checkbox("Cemetery Shade (Black Knife Catacombs)", &CemeteryShade_Liurnia);
		ImGui::Checkbox("Cleanrot Knight (Stillwater Cave)", &CleanrotKnight_Liurnia);
		ImGui::Checkbox("Crystalian (Raya Lucaria Crystal Tunnel)", &Crystalian_Liurnia);
		ImGui::Checkbox("Crystalian Spear & Crystalian Staff (Academy Crystal Cave)", &CrystalianSpearAndCrystalianStaff_Liurnia);
		ImGui::Checkbox("Death Rite Bird (Liurnia North)", &DeathRiteBird_Liurnia);
		ImGui::Checkbox("Deathbird (Liurnia South)", &Deathbird_Liurnia);
		ImGui::Checkbox("Erdtree Avatar (Liurnia Northeast)", &ErdtreeAvatarNortheast_Liurnia);
		ImGui::Checkbox("Erdtree Avatar (Liurnia Southwest)", &ErdtreeAvatarSouthwest_Liurnia);
		ImGui::Checkbox("Erdtree Burial Watchdog (Cliffbottom Catacombs)", &ErdtreeBurialWatchdog_Liurnia);
		ImGui::Checkbox("Glintstone Dragon Adula (Moonlight Altar)", &GlintstoneDragonAdula_Liurnia);
		ImGui::Checkbox("Glintstone Dragon Smarag (Liurnia)", &GlintstoneDragonSmarag_Liurnia);
		ImGui::Checkbox("Magma Wyrm Makar (Ruin-Strewn Precipice)", &MagmaWyrmMakar_Liurnia);
		ImGui::Checkbox("Night's Cavalry (Liurnia North)", &NightCavalryNorth_Liurnia);
		ImGui::Checkbox("Night's Cavalry (Liurnia South)", &NightCavalrySouth_Liurnia);
		ImGui::Checkbox("Omenkiller (Village of the Albinaurics)", &Omenkiller_Liurnia);
		ImGui::Checkbox("Onyx Lord (Royal Grave Evergaol)", &OnyxLord_Liurnia);
		ImGui::Checkbox("Red Wolf of Radagon (Raya Lucaria)", &RedWolfofRadagon_Liurnia);
		ImGui::Checkbox("Rennala, Queen of the Full Moon", &RennalaQueenoftheFullMoon_Liurnia);
		ImGui::Checkbox("Royal Knight Loretta (Caria Manor)", &RoyalKnightLoretta_Liurnia);
		ImGui::Checkbox("Royal Revenant (Kingsrealm Ruins)", &RoyalRevenant_Liurnia);
		ImGui::Checkbox("Spiritcaller Snail (Road's End Catacombs)", &SpiritcallerSnail_Liurnia);
		ImGui::Checkbox("Tibia Mariner (East Liurnia)", &TibiaMariner_Liurnia);
	}
	if (bosses_window == "Caelid")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Caelid
		ImGui::Checkbox("Cemetery Shade (Caelid Catacombs)", &CemeteryShade_Caelid);
		ImGui::Checkbox("Commander O'Neil (Swamp of Aeonia)", &CommanderONeil_Caelid);
		ImGui::Checkbox("Crucible Knight & Misbegotten Warrior (Redmane Castle) ", &CrucibleKnightMisbegottenWarrior_Caelid);
		ImGui::Checkbox("Death Rite Bird (Caelid)", &DeathRiteBird_Caelid);
		ImGui::Checkbox("Decaying Ekzykes (Caelid)", &DecayingEkzykes_Caelid);
		ImGui::Checkbox("Elder Dragon Greyoll (can apparently spawn invisible)", &ElderDragonGreyoll_Caelid);
		ImGui::Checkbox("Erdtree Burial Watchdogs (Minor Erdtree Catacombs)", &ErdtreeBurialWatchdogs_Caelid);
		ImGui::Checkbox("Fallingstar Beast (Sellia Crystal Tunnel)", &FallingstarBeast_Caelid);
		ImGui::Checkbox("Frenzied Duelist (Gaol Cave)", &FrenziedDuelist_Caelid);
		ImGui::Checkbox("Mad Pumpkin Heads (Caelem Ruins)", &MadPumpkinHeads_Caelid);
		ImGui::Checkbox("Magma Wyrm (Gael Tunnel)", &MagmaWyrm_Caelid);
		ImGui::Checkbox("Night's Cavalry (Caelid)", &NightCavalry_Caelid);
		ImGui::Checkbox("Nox Swordstress and Nox Priest (Sellia, Town of Sorcery)", &NoxSwordstressandNoxPriest_Caelid);
		ImGui::Checkbox("Putrid Avatar (Caelid)", &PutridAvatar_Caelid);
		ImGui::Checkbox("Starscourge Radahn", &StarscourgeRadahn_Caelid);
	}
	if (bosses_window == "Dragonbarrow")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}
		
		// Dragonbarrow
		ImGui::Checkbox("Battlemage Hugues (Sellia Evergaol)", &BattlemageHugues_Dragonbarrow);
		ImGui::Checkbox("Beastmen of Faram Azula (Dragonbarrow Cave)", &BeastmenofFaramAzula_Dragonbarrow);
		ImGui::Checkbox("Bell Bearing Hunter (Isolated Merchant's Shack)", &BellBearingHunter_Dragonbarrow);
		ImGui::Checkbox("Black Blade Kindred (Bestial Sanctum)", &BlackBladeKindred_Dragonbarrow);
		ImGui::Checkbox("Cleanrot Knights (Stillwater Cave)", &CleanrotKnights_Dragonbarrow);
		ImGui::Checkbox("Flying Dragon Greyll (Greyoll's Dragonbarrow)", &FlyingDragonGreyll_Dragonbarrow);
		ImGui::Checkbox("Godskin Apostle (Divine Tower of Caelid)", &GodskinApostle_Dragonbarrow);
		ImGui::Checkbox("Night's Cavalry (Dragonbarrow)", &NightCavalry_Dragonbarrow);
		ImGui::Checkbox("Putrid Avatar (Dragonbarrow)", &PutridAvatar_Dragonbarrow);
		ImGui::Checkbox("Putrid Crystalians (Sellia Hideaway)", &PutridCrystalians_Dragonbarrow);
		ImGui::Checkbox("Putrid Tree Spirit (War-Dead Catacombs)", &PutridTreeSpirit_Dragonbarrow);
	}
	if (bosses_window == "Altus Plateau")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Altus Plateau
		ImGui::Checkbox("Ancient Dragon Lansseax (Altus Plateau)", &AncientDragonLansseax_Altus);
		ImGui::Checkbox("Ancient Hero of Zamor (Sainted Hero's Grave)", &AncientHeroofZamor_Altus);
		ImGui::Checkbox("Black Knife Assassin (Sage's Cave)", &BlackKnifeAssassin1_Altus);
		ImGui::Checkbox("Black Knife Assassin (Sainted Hero's Grave)", &BlackKnifeAssassin2_Altus);
		ImGui::Checkbox("Crystalian Spear and Crystalian Ringblade (Altus Tunnel)", &CrystalianSpearandCrystalianRingblade_Altus);
		ImGui::Checkbox("Demi-Human Queen Gilika (Lux Ruins)", &DemiHumanQueenGilika_Altus);
		ImGui::Checkbox("Elemer of the Briar (The Shaded Castle)", &ElemeroftheBriar_Altus);
		ImGui::Checkbox("Erdtree Burial Watchdog (Wyndham Catacombs)", &ErdtreeBurialWatchdog_Altus);
		ImGui::Checkbox("Fallingstar Beast (Altus Plateau)", &FallingstarBeast_Altus);
		ImGui::Checkbox("Godefroy the Grafted (Golden Lineage Evergaol)", &GodefroytheGrafted_Altus);
		ImGui::Checkbox("Godskin Apostle (Dominula, Windmill Village)", &GodskinApostle_Altus);
		ImGui::Checkbox("Necromancer Garris (Sage's Cave)", &NecromancerGarris_Altus);
		ImGui::Checkbox("Night's Cavalry (Altus Plateau)", &NightCavalry_Altus);
		ImGui::Checkbox("Omenkiller and Miranda the Blighted Bloom (Perfumer's Grotto)", &OmenkillerandMirandatheBlightedBloom_Altus);
		ImGui::Checkbox("Perfumer Tricia and Misbegotten Warrior (Unsightly Catacombs)", &PerfumerTriciaandMisbegottenWarrior_Altus);
		ImGui::Checkbox("Sanguine Noble (Writheblood Ruins)", &SanguineNoble_Altus);
		ImGui::Checkbox("Stonedigger Troll (Old Altus Tunnel)", &StonediggerTroll_Altus);
		ImGui::Checkbox("Tibia Mariner (Wyndham Ruins)", &TibiaMariner_Altus);
		ImGui::Checkbox("Tree Sentinels (Altus Plateau)", &TreeSentinels_Altus);
		ImGui::Checkbox("Wormface (Altus Plateau)", &Wormface_Altus);
	}
	if (bosses_window == "Capital Outskirts")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Capital Outskirts 
		ImGui::Checkbox("Bell Bearing Hunter (Hermit Merchant's Shack)", &BellBearingHunter_Capital);
		ImGui::Checkbox("Crucible Knight & Crucible Knight Ordovis (Auriza Hero Grave)", &CrucibleKnightCrucibleKnightOrdovis_Capital);
		ImGui::Checkbox("Deathbird (Warmaster's Shack)", &Deathbird_Capital);
		ImGui::Checkbox("Draconic Tree Sentinel (Capital Outskirts)", &DraconicTreeSentinel_Capital);
		ImGui::Checkbox("Fell Twins (Divine Tower of East Altus)", &FellTwins_Capital);
		ImGui::Checkbox("Grave Warden Duelist (Auriza Side Tomb)", &GraveWardenDuelist_Capital);
		ImGui::Checkbox("Onyx Lord (Sealed Tunnel)", &OnyxLord_Capital);
	}
	if (bosses_window == "Leyendell, Royal Capital")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Leyendell, Royal Capital
		ImGui::Checkbox("Esgar, Priest of Blood (Leyndell Catacombs)", &EsgarPriestofBlood_Layendell);
		ImGui::Checkbox("Godfrey, First Elden Lord (Golden Shade)", &GodfreyFirstEldenLord_Layendell);
		ImGui::Checkbox("Mohg, the Omen (Cathedral of the Forsaken)", &MohgtheOmen_Layendell);
		ImGui::Checkbox("Morgott, the Omen King", &MorgotttheOmenKing_Layendell);
	}
	if (bosses_window == "Mt. Gelmir")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Mt. Gelmir
		ImGui::Checkbox("Abductor Virgins (Mt. Gelmir)", &AbductorVirgins_Gelmir);
		ImGui::Checkbox("Demi-Human Queen Maggie (Hermit Village)", &DemiHumanQueenMaggie_Gelmir);
		ImGui::Checkbox("Demi-Human Queen Margot (Volano Cave)", &DemiHumanQueenMargot_Gelmir);
		ImGui::Checkbox("Full-Grown Fallingstar Beast (Ninth Mt. Gelmir Campsite)", &FullGrownFallingstarBeast_Gelmir);
		ImGui::Checkbox("God-Devouring Serpent / Rykard, Lord of Blasphemy", &GodDevouringSerpent_Rykard_Gelmir);
		ImGui::Checkbox("Godskin Noble (Temple of Eiglay)", &GodskinNoble_Gelmir);
		ImGui::Checkbox("Kindred of Rot (Seethewater Cave)", &KindredofRot_Gelmir);
		ImGui::Checkbox("Magma Wyrm (Mt. Gelmir)", &MagmaWyrm_Gelmir);
		ImGui::Checkbox("Red Wolf of the Champion (Gelmir Hero's Grave)", &RedWolfoftheChampion_Gelmir);
		ImGui::Checkbox("Ulcerated Tree Spirit (Mt. Gelmir)", &UlceratedTreeSpirit_Gelmir);
	}
	if (bosses_window == "Mountaintops of the Giants")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Mountaintops of the Giants
		ImGui::Checkbox("Ancient Hero of Zamor (Giant-Conquring Hero's Grave)", &AncientHeroofZamor_Mountaintops);
		ImGui::Checkbox("Borealis the Freezing Fog (Freezing Lake)", &BorealistheFreezingFog_Mountaintops);
		ImGui::Checkbox("Commander Niall (Castle Sol)", &CommanderNiall_Mountaintops);
		ImGui::Checkbox("Death Rite Bird (Mountaintops of the Giants)", &DeathRiteBird_Mountaintops);
		ImGui::Checkbox("Erdtree Avatar (Mountaintops of the Giants)", &ErdtreeAvatar_Mountaintops);
		ImGui::Checkbox("Fire Giant", &FireGiant_Mountaintops);
		ImGui::Checkbox("Godskin Apostle and Godskin Noble  (Spiritcaller Cave) Spiritcaller Snail", &GodskinApostleandGodskinNoble_Mountaintops);
		ImGui::Checkbox("Ulcerated Tree Spirit (Giants' Mountaintop Catacombs)", &UlceratedTreeSpirit_Mountaintops);
		ImGui::Checkbox("Vyke, Knight of the Roundtable (Lord Contender's Evergaol)", &VykeKnightoftheRoundtable_Mountaintops);
	}
	if (bosses_window == "Crumbling Farum Azula")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Crumbling Farum Azula
		ImGui::Checkbox("Dragonlord Placidusax", &DragonlordPlacidusax_Azula);
		ImGui::Checkbox("Godskin Duo", &GodskinDuo_Azula);
		ImGui::Checkbox("Malekith, the Black Blade", &MalekiththeBlackBlade_Azula);
	}
	if (bosses_window == "Forbidden Lands")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Forbidden Lands
		ImGui::Checkbox("Black Blade Kindred (Forbidden Lands)", &BlackBladeKindred_Forbidden);
		ImGui::Checkbox("Night's Cavalry (Forbidden Lands)", &NightCavalry_Forbidden);
		ImGui::Checkbox("Stray Mimic Tear (Hidden Path to the Haligtree)", &StrayMimicTear_Forbidden);
	}
	if (bosses_window == "Consecrated Snowfields")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Consecrated Snowfields
		ImGui::Checkbox("Astel, Stars of Darkness (Yelough Anix Tunnel)", &AstelStarsofDarkness_Snowfields);
		ImGui::Checkbox("Death Rite Bird (Consecrated Snowfield)", &DeathRiteBird_Snowfields);
		ImGui::Checkbox("Great Wyrm Theodorix (Consecrated Snowfield)", &GreatWyrmTheodorix_Snowfields);
		ImGui::Checkbox("Misbegotten Crusader (Cave of the Forlorn)", &MisbegottenCrusader_Snowfields);
		ImGui::Checkbox("Night's Cavalry Duo (Consecrated Snowfield)", &NightCavalryDuo_Snowfields);
		ImGui::Checkbox("Putrid Avatar (Snowfields)", &PutridAvatar_Snowfields);
		ImGui::Checkbox("Putrid Grave Warden Duelist (Consecrated Snowfield Catacombs)", &PutridGraveWardenDuelist_Snowfields);
	}
	if (bosses_window == "Miquella's Haligtree")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Miquella's Haligtree
		ImGui::Checkbox("Loretta, Knight of the Haligtree", &LorettaKnightoftheHaligtree_Miquella);
		//ImGui::Checkbox("Malenia, Goddess of Rot", &MaleniaGoddessofRot_Miquella);
	}
	if (bosses_window == "Siofra River")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Siofra River
		ImGui::Checkbox("Ancestor Spirit (Siofra River Bank)", &AncestorSpirit_Siofra);
		ImGui::Checkbox("Dragonkin Soldier (Siofra River Bank)", &DragonkinSoldier_Siofra);
		ImGui::Checkbox("Mohg, Lord of Blood", &MohgLordofBlood_Siofra);

	}
	if (bosses_window == "Ainsel River")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Ainsel River
		ImGui::Checkbox("Dragonkin Soldier of Nokstella (Ainsel River)", &DragonkinSoldierofNokstella_Ainsel);
	}
	if (bosses_window == "Nokron Eternal City")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Nokron Eternal City
		ImGui::Checkbox("Mimic Tear (Nokron, Eternal City)", &MimicTear_Nokron);
		ImGui::Checkbox("Regal Ancestor Spirit (Ancestral Woods)", &RegalAncestorSpirit_Nokron);
		ImGui::Checkbox("Valiant Gargoyles (Siofra Aqueduct)", &ValiantGargoyles_Nokron);
	}
	if (bosses_window == "Deeproot Depths")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Deeproot Depths
		ImGui::Checkbox("Crucible Knight Siluria", &CrucibleKnightSiluria_Deeproot);
		ImGui::Checkbox("Fia's Champions", &FiaChampions_Deeproot);
		ImGui::Checkbox("Lichdragon Fortissax", &LichdragonFortissax_Deeproot);
	}
	if (bosses_window == "Lake of Rot")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Lake of Rot
		ImGui::Checkbox("Astel, Naturalborn of the Void", &AstelNaturalbornoftheVoid_LakeofRot);
		ImGui::Checkbox("Dragonkin Soldier (Lake of Rot)", &DragonkinSoldier_LakeofRot);
	}
	if (bosses_window == "Leyendell, Ashen Capital")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Leyendell, Ashen Capital
		ImGui::Checkbox("Godfrey, First Elden Lord (Hoarah Loux)", &GodfreyFirstEldenLord_AshenCapital);
		ImGui::Checkbox("Sir Gideon Ofnir, the All-Knowing", &SirGideonOfnirtheAllKnowing_AshenCapital);
	}
	if (bosses_window == "Elden Throne")
	{
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			bosses_window = "main";
		}

		// Elden Throne
		ImGui::Checkbox("Radagon of the Golden Order / Elden Beast", &EldenBeast_EldenThrone);
	}
}

// this was a pain in the ass to make (　〇 □〇）