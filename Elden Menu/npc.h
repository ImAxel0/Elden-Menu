#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx12.h"
#include "ImGui/imgui_impl_win32.h"

#include <iostream>
#include <string>
#include "ModUtils.h"

using namespace ModUtils;

bool MirielPastorofVows = false;
bool PreceptorSeluvis = false;
bool MerchantKalé = false;
bool SorceressSellen = false;
bool WhiteFacedVarré = false;
bool AlexanderIronFist = false;
bool DeviousCommoner = false;
bool KennethHaight = false;
bool Fia = false;
bool Irina = false;
bool Edgar = false;
bool Latenna = false;
bool Yura = false;
bool Tophs = false;
bool JarBairn = false;
bool KnightBernahl = false;
bool Blackguard = false;
bool Millicent = false;
bool NepheliLoux = false;
bool GatekeeperGostoc = false;
bool Boc = false;
bool Gurranq = false;
bool Hyetta = false;
bool Patches = false;

byte* MirielPastorofVowsAddr{};
byte* PreceptorSeluvisAddr{};
byte* MerchantKaléAddr{};
byte* SorceressSellenAddr{};
byte* WhiteFacedVarréAddr{};
byte* AlexanderIronFistAddr{};
byte* DeviousCommonerAddr{};
byte* KennethHaightAddr{};
byte* FiaAddr{};
byte* IrinaAddr{};
byte* EdgarAddr{};
byte* LatennaAddr{};
byte* YuraAddr{};
byte* TophsAddr{};
byte* JarBairnAddr{};
byte* KnightBernahlAddr{};
byte* BlackguardAddr{};
byte* MillicentAddr{};
byte* NepheliLouxAddr{};
byte* GatekeeperGostocAddr{};
byte* BocAddr{};
byte* GurranqAddr{};
byte* HyettaAddr{};
byte* PatchesAddr{};

void refreshNPC(uintptr_t EventFlagManRealReal)
{
	MirielPastorofVowsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1D1 });
	PreceptorSeluvisAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1BD });
	MerchantKaléAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x24B });
	SorceressSellenAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1B0 });
	WhiteFacedVarréAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x18D });
	AlexanderIronFistAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1C9 });
	DeviousCommonerAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x197 });
	KennethHaightAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1BF });
	FiaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x203 });
	IrinaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1A6 });
	EdgarAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1A9 });
	LatennaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x200 });
	YuraAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1C4 });
	TophsAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1DB });
	JarBairnAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1DD });
	KnightBernahlAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1E5 });
	BlackguardAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x205 });
	MillicentAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x20A });
	NepheliLouxAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x20F });
	GatekeeperGostocAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x197 });
	BocAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1EC });
	GurranqAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1C7 });
	HyettaAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1A6 });
	PatchesAddr = (byte*)FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x1CC });
}

void reviveNPC()
{
	if (MirielPastorofVows) {
		*MirielPastorofVowsAddr = 132;
	}
	if (PreceptorSeluvis) {
		*PreceptorSeluvisAddr = 132;
	}
	if (MerchantKalé) {
		*MerchantKaléAddr = 8;
	}
	if (SorceressSellen) {
		*SorceressSellenAddr = 8;
	}
	if (WhiteFacedVarré) {
		*WhiteFacedVarréAddr = 24;
	}
	if (AlexanderIronFist) {
		*AlexanderIronFistAddr = 8;
	}
	if (DeviousCommoner) {
		*DeviousCommonerAddr = 40;
	}
	if (KennethHaight) {
		*KennethHaightAddr = 24;
	}
	if (Fia) {
		*FiaAddr = 132;
	}
	if (Patches) {
		*PatchesAddr = 132;
	}
	if (Irina) {
		*IrinaAddr = 8;
	}
	if (Edgar) {
		*EdgarAddr = 132;
	}
	if (Latenna) {
		*LatennaAddr = 8;
	}
	if (Yura) {
		*YuraAddr = 8;
	}
	if (Tophs) {
		*TophsAddr = 132;
	}
	if (JarBairn) {
		*JarBairnAddr = 8;
	}
	if (KnightBernahl) {
		*KnightBernahlAddr = 132;
	}
	if (Blackguard) {
		*BlackguardAddr = 8;
	}
	if (Millicent) {
		*MillicentAddr = 8;
	}
	if (NepheliLoux) {
		*NepheliLouxAddr = 8;
	}
	if (GatekeeperGostoc) {
		*GatekeeperGostocAddr = 8;
	}
	if (Boc) {
		*BocAddr = 8;
	}
	if (Gurranq) {
		*GurranqAddr = 132;
	}
	if (Hyetta) {
		*HyettaAddr = 8;
	}
}

void killNPC()
{
	if (MirielPastorofVows) {
		*MirielPastorofVowsAddr = 0;
	}
	if (PreceptorSeluvis) {
		*PreceptorSeluvisAddr = 0;
	}
	if (MerchantKalé) {
		*MerchantKaléAddr = 0;
	}
	if (SorceressSellen) {
		*SorceressSellenAddr = 0;
	}
	if (WhiteFacedVarré) {
		*WhiteFacedVarréAddr = 0;
	}
	if (AlexanderIronFist) {
		*AlexanderIronFistAddr = 0;
	}
	if (DeviousCommoner) {
		*DeviousCommonerAddr = 0;
	}
	if (KennethHaight) {
		*KennethHaightAddr = 0;
	}
	if (Fia) {
		*FiaAddr = 0;
	}
	if (Patches) {
		*PatchesAddr = 0;
	}
	if (Irina) {
		*IrinaAddr = 0;
	}
	if (Edgar) {
		*EdgarAddr = 0;
	}
	if (Latenna) {
		*LatennaAddr = 0;
	}
	if (Yura) {
		*YuraAddr = 0;
	}
	if (Tophs) {
		*TophsAddr = 0;
	}
	if (JarBairn) {
		*JarBairnAddr = 0;
	}
	if (KnightBernahl) {
		*KnightBernahlAddr = 0;
	}
	if (Blackguard) {
		*BlackguardAddr = 0;
	}
	if (Millicent) {
		*MillicentAddr = 0;
	}
	if (NepheliLoux) {
		*NepheliLouxAddr = 0;
	}
	if (GatekeeperGostoc) {
		*GatekeeperGostocAddr = 0;
	}
	if (Boc) {
		*BocAddr = 0;
	}
	if (Gurranq) {
		*GurranqAddr = 0;
	}
	if (Hyetta) {
		*HyettaAddr = 0;
	}
}

void NPCCheckUI()
{
	ImGui::Checkbox("Miriel, Pastor of Vows ", &MirielPastorofVows);
	ImGui::Checkbox("Preceptor Seluvis ", &PreceptorSeluvis);
	ImGui::Checkbox("Merchant Kale", &MerchantKalé);
	ImGui::Checkbox("Sorceress Sellen", &SorceressSellen);
	ImGui::Checkbox("White-Faced Varre", &WhiteFacedVarré);
	ImGui::Checkbox("Alexander Iron Fist ", &AlexanderIronFist);
	ImGui::Checkbox("Devious Commoner ", &DeviousCommoner);
	ImGui::Checkbox("Kenneth Haight", &KennethHaight);
	ImGui::Checkbox("Fia", &Fia);
	ImGui::Checkbox("Irina", &Irina);
	ImGui::Checkbox("Edgar", &Edgar);
	ImGui::Checkbox("Latenna", &Latenna);
	ImGui::Checkbox("Yura", &Yura);
	ImGui::Checkbox("Tophs", &Tophs);
	ImGui::Checkbox("Jar Bairn", &JarBairn);
	ImGui::Checkbox("Knight Bernahl", &KnightBernahl);
	ImGui::Checkbox("Blackguard", &Blackguard);
	ImGui::Checkbox("Millicent", &Millicent);
	ImGui::Checkbox("Nepheli Loux", &NepheliLoux);
	ImGui::Checkbox("Gatekeeper Gostoc", &GatekeeperGostoc);
	ImGui::Checkbox("Boc", &Boc);
	ImGui::Checkbox("Gurranq", &Gurranq);
	ImGui::Checkbox("Hyetta", &Hyetta);
	ImGui::Checkbox("Patches", &Patches);
}