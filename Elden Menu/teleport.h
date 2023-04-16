#include <iostream>
#include <Windows.h>
#include <vector>
#include "ModUtils.h"
#include <string>

using namespace ModUtils;

std::string tele_window = "tele_main";

float x{};
float z{};
float y{};

uintptr_t xPtrTpAddr{};
uintptr_t zPtrTpAddr{};
uintptr_t yPtrTpAddr{};

float* xPtrTp{};
float* zPtrTp{};
float* yPtrTp{};

uintptr_t xGlobalPtrAddr{};
uintptr_t zGlobalPtrAddr{};
uintptr_t yGlobalPtrAddr{};

float* xGlobalPtr{};
float* zGlobalPtr{};
float* yGlobalPtr{};

float xNew{};
float zNew{};
float yNew{};

unsigned char testLocation[12] = { 0xF1, 0xF8, 0x72, 0x45, 0xC5, 0x82, 0xB0, 0x42, 0x19, 0x60, 0xDA, 0x45 };

unsigned char TheFirstStep[12] = { 0xE3, 0x47, 0x67, 0x45, 0x16, 0x31, 0xB5, 0x42, 0x05, 0xC7, 0xE5, 0x45 };
unsigned char ChurchOfElleh[12] = { 0xE4, 0x65, 0x66, 0x45, 0x00, 0x23, 0xB8, 0x42, 0x52, 0xCD, 0xE1, 0x45 };
unsigned char LimgraveColosseum[12] = { 0x26, 0x5D, 0x63, 0x45, 0xF7, 0x51, 0x4E, 0x43, 0x54, 0x44, 0xCA, 0x45 };
unsigned char TopOfLimgraveDivineTower[12] = { 0x51, 0xCF, 0x84, 0x45, 0x5C, 0xDB, 0xAE, 0x43, 0x9E, 0xF0, 0xC2, 0x45 };
unsigned char LimgraveCoast[12] = { 0x3E, 0xB7, 0x58, 0x45, 0x24, 0x12, 0x4A, 0x41, 0x7C, 0x5F, 0xDF, 0x45 };
unsigned char LimgraveCatacombsEntrance[12] = { 0xF9, 0xE1, 0x5A, 0x45, 0x95, 0x66, 0xE6, 0x42, 0x57, 0x89, 0xDC, 0x45 };
unsigned char Stormveil1stGate[12] = { 0x48, 0x88, 0x68, 0x45, 0x11, 0x5D, 0xDE, 0x42, 0x88, 0xB3, 0xD8, 0x45 };
unsigned char Stormveil2ndGateMargitEntrance[12] = { 0x0F, 0x29, 0x52, 0x45, 0x1A, 0xA0, 0x4A, 0xC1, 0xB6, 0x91, 0xD3, 0x45 };
unsigned char Stormveil3rdGate[12] = { 0x88, 0x51, 0x4A, 0x45, 0x7C, 0x8A, 0xA9, 0x41, 0x4F, 0x73, 0xD4, 0x45 };
unsigned char Stormveil4thGateGodrick[12] = { 0x4E, 0xB2, 0x43, 0x45, 0x0A, 0xC0, 0xA3, 0x42, 0x42, 0x1C, 0xCB, 0x45 };
unsigned char StormveilOut[12] = { 0xFB, 0xEC, 0x39, 0x45, 0x3E, 0x6C, 0xA9, 0x43, 0xCA, 0x2F, 0xC6, 0x45 };
unsigned char CathedralOfManusCeles[12] = { 0x3F, 0x70, 0xE1, 0x44, 0xEC, 0x7B, 0xC9, 0x43, 0xFC, 0xBF, 0xB4, 0x45 };
unsigned char TopOfLiurniaBelfries[12] = { 0x42, 0x3D, 0xB8, 0x44, 0xAA, 0x2E, 0xBE, 0x43, 0x23, 0x61, 0x8F, 0x45 };
unsigned char AcademyGateTown[12] = { 0x56, 0x57, 0x14, 0x45, 0x5E, 0xE2, 0x73, 0x43, 0xE3, 0x67, 0xA4, 0x45 };
unsigned char LiurniaDivineTowerEntrance[12] = { 0x65, 0x3C, 0x35, 0x45, 0xBF, 0x39, 0x6F, 0x43, 0x16, 0xA1, 0x9F, 0x45 };
unsigned char TopOfLiurniaDivineTower[12] = { 0x26, 0x5C, 0x51, 0x45, 0x65, 0xA4, 0x94, 0x43, 0x09, 0x3C, 0xA1, 0x45 };
unsigned char RennalaEntrance[12] = { 0x4C, 0x79, 0xEE, 0x44, 0x66, 0x15, 0x1A, 0x43, 0xE0, 0x6C, 0x97, 0x45 };
unsigned char RayaLucariaOuterGate[12] = { 0x99, 0xB1, 0x03, 0x45, 0xD4, 0xCB, 0xA0, 0x43, 0xD1, 0x8A, 0x87, 0x45 };
unsigned char CariaManorGate[12] = { 0x75, 0x26, 0xED, 0x44, 0xE5, 0x19, 0x9D, 0x43, 0x9C, 0xB0, 0x70, 0x45 };
unsigned char BackOfCariaManor[12] = { 0x26, 0x2A, 0xE9, 0x44, 0x4C, 0xA8, 0xD7, 0x43, 0x60, 0x0D, 0x5F, 0x45 };
unsigned char GrandLiftOfDectusEntrance[12] = { 0xE3, 0x14, 0x24, 0x45, 0xC7, 0x95, 0xB7, 0x43, 0x75, 0xF7, 0x6B, 0x45 };
unsigned char TopOfGrandLiftOfDectus[12] = { 0x2D, 0xBC, 0x2B, 0x45, 0x28, 0xC4, 0x3D, 0x44, 0x21, 0x30, 0x69, 0x45 };
unsigned char OuterCapital1stEntrance[12] = { 0x54, 0x97, 0x5E, 0x45, 0x47, 0xD1, 0x54, 0x44, 0xFF, 0xB0, 0x5A, 0x45 };
unsigned char OuterCapital2ndEntrance[12] = { 0x84, 0x5D, 0x71, 0x45, 0xA2, 0x27, 0x72, 0x44, 0x34, 0x1F, 0x38, 0x45 };
unsigned char LeyndellCapitalEntrance[12] = { 0x0C, 0xB9, 0x8C, 0x45, 0x7E, 0x21, 0x80, 0x44, 0xAC, 0xC4, 0x45, 0x45 };
unsigned char LeyndellMainStreet[12] = { 0x69, 0xD7, 0x88, 0x45, 0xA6, 0xF0, 0x35, 0xC2, 0x1A, 0x68, 0x59, 0x45 };
unsigned char DivineBridgeLeyndell[12] = { 0x32, 0x99, 0x7E, 0x45, 0x9E, 0x15, 0xE9, 0x41, 0xF0, 0xD1, 0x61, 0x45 };
unsigned char ErdtreeSanctuary[12] = { 0xF1, 0x55, 0x88, 0x45, 0x0B, 0x3D, 0xF8, 0x41, 0x2F, 0xB1, 0x67, 0x45 };
unsigned char EldenThrone[12] = { 0x98, 0xA4, 0x8D, 0x45, 0xA6, 0x3C, 0x82, 0x42, 0xE4, 0x6D, 0x69, 0x45 };
unsigned char SnowBeginning[12] = { 0x41, 0x5F, 0x9B, 0x45, 0x2A, 0xF4, 0x7A, 0x44, 0x06, 0xE0, 0x5A, 0x45 };
unsigned char GrandLiftRoldEntrance[12] = { 0xFD, 0x5E, 0xAB, 0x45, 0x31, 0xE0, 0x84, 0x44, 0xE0, 0xFF, 0x40, 0x45 };
unsigned char TopOfLiftRold[12] = { 0xE0, 0x5D, 0xAB, 0x45, 0xDC, 0xFD, 0xC3, 0x44, 0x28, 0x07, 0x38, 0x45 };
unsigned char SnowValleyRuins[12] = { 0x0E, 0x3F, 0xBE, 0x45, 0x9B, 0xCC, 0xC9, 0x44, 0x66, 0x03, 0x08, 0x45 };
unsigned char ConsecretedSnowfield[12] = { 0x15, 0xEE, 0xA8, 0x45, 0x58, 0x24, 0xA5, 0x44, 0xEC, 0x69, 0x28, 0x45 };
unsigned char LiturgicalTown[12] = { 0xA8, 0x2E, 0xA5, 0x45, 0xFC, 0xB7, 0xA0, 0x44, 0xBD, 0x0F, 0xF5, 0x44 };
unsigned char CastleSol[12] = { 0x55, 0x55, 0xBB, 0x45, 0xFF, 0x7C, 0xC7, 0x44, 0x59, 0xB1, 0xE7, 0x44 };
unsigned char FreezingLake[12] = { 0xB2, 0xCA, 0xC8, 0x45, 0xE1, 0x85, 0xCA, 0x44, 0x49, 0x0F, 0xEB, 0x44 };
unsigned char FallingBigHand[12] = { 0xA9, 0xC2, 0xC0, 0x45, 0x4C, 0xDD, 0xE0, 0x44, 0xC0, 0x91, 0x3A, 0x45 };
unsigned char GiantsChainbridge[12] = { 0xA8, 0x81, 0xCC, 0x45, 0x34, 0xB4, 0xEF, 0x44, 0xC1, 0x80, 0x3F, 0x45 };
unsigned char FarumAzulaBridge[12] = { 0xFC, 0x6E, 0x05, 0x46, 0x48, 0x77, 0x5E, 0xC2, 0x3D, 0x78, 0x88, 0x45 };
unsigned char FarumAzulaBalcony[12] = { 0x66, 0x4A, 0x03, 0x46, 0x00, 0xA7, 0x11, 0x42, 0x84, 0x31, 0x8E, 0x45 };
unsigned char AltusPlateauRoad[12] = { 0xB5, 0xA4, 0x15, 0x45, 0x19, 0x12, 0x24, 0x44, 0x09, 0xAA, 0x5C, 0x45 };
unsigned char AltusBrokenBridge[12] = { 0x2E, 0xE8, 0x4E, 0x45, 0x2F, 0x23, 0x4F, 0x44, 0x55, 0x93, 0x40, 0x45 };
unsigned char AltusCreepyWindmillVillage[12] = { 0xF7, 0x8D, 0x65, 0x45, 0xFF, 0x3E, 0x72, 0x44, 0xD1, 0xC4, 0x19, 0x45 };
unsigned char TopOfAltusEastDivineTower[12] = { 0x86, 0xC3, 0x9F, 0x45, 0x5D, 0x5B, 0xA5, 0x43, 0x17, 0xBD, 0x71, 0x45 };
unsigned char TopOfAltusWestDivineTower[12] = { 0xFA, 0x84, 0x73, 0x45, 0xAE, 0x0D, 0x7A, 0x44, 0xB7, 0x41, 0x7C, 0x45 };
unsigned char CaelidSanctum[12] = { 0x0A, 0x32, 0xBB, 0x45, 0xDE, 0x28, 0xAC, 0x43, 0x6A, 0x44, 0xAC, 0x45 };
unsigned char CaelidDragonBridge[12] = { 0xFE, 0x25, 0xC0, 0x45, 0x95, 0x1B, 0x79, 0x43, 0x4E, 0x85, 0xB3, 0x45 };
unsigned char TopOfCaelidDivineTower[12] = { 0x26, 0xE8, 0xAE, 0x45, 0xE1, 0x20, 0x10, 0x44, 0x19, 0x9F, 0xBD, 0x45 };
unsigned char CaelidColosseum[12] = { 0xDB, 0xCD, 0x9B, 0x45, 0x6C, 0xEA, 0x08, 0x43, 0x40, 0xA4, 0xB9, 0x45 };
unsigned char CaelidSwamp[12] = { 0xB4, 0x4C, 0xA5, 0x45, 0xD1, 0xC1, 0x80, 0x42, 0x19, 0xAC, 0xD4, 0x45 };
unsigned char RedmaneCastle[12] = { 0xFB, 0x88, 0xBE, 0x45, 0xAB, 0x87, 0xB7, 0x42, 0xF0, 0x09, 0xE3, 0x45 };
unsigned char AgheelLake[12] = { 0x13, 0x37, 0x71, 0x45, 0xBA, 0x1D, 0x87, 0x42, 0x6C, 0xD8, 0xE3, 0x45 };
unsigned char ToSouthBridge[12] = { 0xE3, 0xB1, 0x86, 0x45, 0x8D, 0x21, 0x3F, 0x42, 0xA2, 0x26, 0xF0, 0x45 };
unsigned char CastleMorneEntrance[12] = { 0x76, 0x90, 0x80, 0x45, 0xE7, 0x71, 0x9C, 0x40, 0x5B, 0x69, 0x05, 0x46 };
unsigned char BackOfCastleMorne[12] = { 0xD6, 0xA8, 0x77, 0x45, 0x6D, 0x3D, 0x2C, 0x41, 0x99, 0x75, 0x08, 0x46 };
unsigned char SouthWitchRuins[12] = { 0xF9, 0xCC, 0x5B, 0x45, 0xF4, 0xC4, 0x34, 0x41, 0x32, 0x85, 0xFD, 0x45 };
unsigned char ChurchDragonCommunion[12] = { 0x6F, 0x95, 0x54, 0x45, 0xA2, 0xEF, 0xD8, 0x41, 0xB4, 0xFB, 0xEC, 0x45 };
unsigned char VillageHanged[12] = { 0xAA, 0xFA, 0xDD, 0x44, 0xFB, 0xC3, 0x8C, 0x43, 0xA2, 0x05, 0xB7, 0x45 };
unsigned char RoundtableLockedRoom[12] = { 0xA0, 0xEB, 0x33, 0x45, 0x10, 0x6F, 0x02, 0xC2, 0xD2, 0x3A, 0xEE, 0x45 };
unsigned char CenterMap[12] = { 0xC8, 0xD4, 0x8B, 0x45, 0x1D, 0xF5, 0x91, 0x43, 0x2F, 0x79, 0x9F, 0x45 };
unsigned char InsideGoldenTree[12] = { 0xC4, 0x28, 0x94, 0x45, 0x1D, 0xF5, 0x91, 0x43, 0xE0, 0x18, 0x73, 0x45 };
unsigned char Haligtree1st[12] = { 0xAE, 0x58, 0xAF, 0x45, 0x31, 0xB5, 0x1A, 0x44, 0x90, 0xD1, 0xA5, 0x44 };
unsigned char Haligtree2nd[12] = { 0xE6, 0x27, 0xB1, 0x45, 0xCE, 0xBB, 0xFA, 0x43, 0x95, 0x2F, 0x8D, 0x44 };
unsigned char Haligtree3rd[12] = { 0x5E, 0xB3, 0xB1, 0x45, 0x60, 0xC3, 0x72, 0x42, 0x9D, 0xBF, 0x4F, 0x44 };

void teleport(uintptr_t WorldChrManRealReal, uintptr_t NetManImpRealReal, unsigned char& xzy)
{
	memcpy(&x, &xzy, sizeof(x));
	memcpy(&z, &xzy + 4, sizeof(z));
	memcpy(&y, &xzy + 8, sizeof(y));

	xPtrTpAddr = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { 0x10EF8, 0x0, 0x190, 0x68, 0x70 });
	xPtrTp = (float*)xPtrTpAddr;

	zPtrTpAddr = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { 0x10EF8, 0x0, 0x190, 0x68, 0x74 });
	zPtrTp = (float*)zPtrTpAddr;

	yPtrTpAddr = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { 0x10EF8, 0x0, 0x190, 0x68, 0x78 });
	yPtrTp = (float*)yPtrTpAddr;


	xGlobalPtrAddr = FindDMAAddy((uintptr_t)&NetManImpRealReal, { 0x80, 0xe0, 0x80, 0x20, 0x98, 0x28 });
	xGlobalPtr = (float*)xGlobalPtrAddr;

	zGlobalPtrAddr = FindDMAAddy((uintptr_t)&NetManImpRealReal, { 0x80, 0xe0, 0x80, 0x20, 0x98, 0x1c });
	zGlobalPtr = (float*)zGlobalPtrAddr;

	yGlobalPtrAddr = FindDMAAddy((uintptr_t)&NetManImpRealReal, { 0x80, 0xe0, 0x80, 0x20, 0x98, 0x2c });
	yGlobalPtr = (float*)yGlobalPtrAddr;

	xNew = x - (*xGlobalPtr - *xPtrTp);
	zNew = z - (*zGlobalPtr - *zPtrTp);
	yNew = (y - (*yGlobalPtr + *yPtrTp)) * -1;

	*xPtrTp = xNew;
	*zPtrTp = zNew + 1;
	*yPtrTp = yNew;

	uintptr_t noGravity = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { 0x10EF8, 0x00, 0x190, 0x68, 0x1d3 });
	byte* nogravity = (byte*)noGravity;
	*nogravity = 0x1;
}

void teleportButtonUI(uintptr_t WorldChrManRealReal, uintptr_t NetManImpRealReal)
{
	if (tele_window == "tele_main")
	{
		if (ImGui::Button("SOUTH  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "south";
		}

		if (ImGui::Button("NORTH  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "north";
		}
		/*
		if (ImGui::Button("EAST  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "east";
		}
		*/
		if (ImGui::Button("WEST  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "west";
		}

		if (ImGui::Button("SOUTH-EAST  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "southeast";
		}

		if (ImGui::Button("SOUTH-WEST  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "southwest";
		}

		if (ImGui::Button("NORTH-WEST  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "northwest";
		}

		if (ImGui::Button("MISC/FUNNY  " ICON_FA_ARROW_RIGHT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "misc/funny";
		}
	}

	if (tele_window == "southwest")
	{
		ImGui::Text("Southwest");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("The first step", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TheFirstStep);
		}

		if (ImGui::Button("Agheel lake", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *AgheelLake);
		}

		if (ImGui::Button("Church of Elleh", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *ChurchOfElleh);
		}

		if (ImGui::Button("Limgrave Colosseum", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LimgraveColosseum);
		}
		/*
		if (ImGui::Button("Top of Limgrave Divine Tower", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfLimgraveDivineTower);
		}
		*/
		if (ImGui::Button("Limgrave coast", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LimgraveCoast);
		}

		if (ImGui::Button("Limgrave catacombs entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LimgraveCatacombsEntrance);
		}

		if (ImGui::Button("Stormveil castle 1st gate", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Stormveil1stGate);
		}
		/*
		if (ImGui::Button("Stormveil 2nd gate (Margit entrance)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Stormveil2ndGateMargitEntrance);
		}

		if (ImGui::Button("Stormveil 3rd gate", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Stormveil3rdGate);
		}

		if (ImGui::Button("Stormveil 4th gate (Godrick)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Stormveil4thGateGodrick);
		}
		*/
		if (ImGui::Button("Stormveil castle back", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *StormveilOut);
		}

		if (ImGui::Button("To south bridge", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *ToSouthBridge);
		}

		if (ImGui::Button("Church of Dragon Communion", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *ChurchDragonCommunion);
		}
	}
	if (tele_window == "west")
	{
		ImGui::Text("West");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Cathedral of Manus Celes (Liurnia)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CathedralOfManusCeles);
		}

		if (ImGui::Button("Top of 4 Liurnia Belfries", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfLiurniaBelfries);
		}

		if (ImGui::Button("Academy gate town", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *AcademyGateTown);
		}

		if (ImGui::Button("Liurnia Divine tower entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LiurniaDivineTowerEntrance);
		}
		/*
		if (ImGui::Button("Top of Liurnia Divine tower", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfLiurniaDivineTower);
		}
		
		if (ImGui::Button("Rennala entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *RennalaEntrance);
		}
		*/
		if (ImGui::Button("Raya Lucaria outer gate", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *RayaLucariaOuterGate);
		}

		if (ImGui::Button("Caria Manor gate", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CariaManorGate);
		}

		if (ImGui::Button("Back of Caria Manor", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *BackOfCariaManor);
		}

		if (ImGui::Button("Grand Lift of Dectus entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *GrandLiftOfDectusEntrance);
		}

		if (ImGui::Button("Top of Grand Lift of Dectus", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfGrandLiftOfDectus);
		}

		if (ImGui::Button("Village of the hanged", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *VillageHanged);
		}
	}
	if (tele_window == "northwest")
	{
		ImGui::Text("Northwest");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Outer Capital 1st entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *OuterCapital1stEntrance);
		}

		if (ImGui::Button("Outer Capital 2nd entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *OuterCapital2ndEntrance);
		}

		if (ImGui::Button("Leyndell Capital entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LeyndellCapitalEntrance);
		}
		/*
		if (ImGui::Button("Leyndell main road", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LeyndellMainStreet);
		}
		
		if (ImGui::Button("Divine bridge (Leyndell)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *DivineBridgeLeyndell);
		}

		if (ImGui::Button("Erdtree sanctuary", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *ErdtreeSanctuary);
		}

		if (ImGui::Button("Elden Throne", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *EldenThrone);
		}
		*/
		if (ImGui::Button("Altus Plateau road start", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *AltusPlateauRoad);
		}

		if (ImGui::Button("Altus broken bridge", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *AltusBrokenBridge);
		}

		if (ImGui::Button("Altus creepy windmill village", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *AltusCreepyWindmillVillage);
		}
		/*
		if (ImGui::Button("Top of Altus East Divine tower", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfAltusEastDivineTower);
		}

		if (ImGui::Button("Top of Altus West Divine tower", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfAltusWestDivineTower);
		}
		*/
	}
	if (tele_window == "north")
	{
		ImGui::Text("North");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Snow beginning (Forbidden Lands)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *SnowBeginning);
		}

		if (ImGui::Button("Grand Lift of Rold entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *GrandLiftRoldEntrance);
		}

		if (ImGui::Button("Top of Lift of Rold", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfLiftRold);
		}

		if (ImGui::Button("Snow valley ruins", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *SnowValleyRuins);
		}

		if (ImGui::Button("Consecreted Snowfield", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *ConsecretedSnowfield);
		}

		if (ImGui::Button("Liturgical town", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *LiturgicalTown);
		}

		if (ImGui::Button("Castle Sol", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CastleSol);
		}

		if (ImGui::Button("Freezing lake", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *FreezingLake);
		}

		if (ImGui::Button("Falling Big Hand", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *FallingBigHand);
		}

		if (ImGui::Button("Forge of the Giants chainbridge", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *GiantsChainbridge);
		}
		/*
		if (ImGui::Button("Haligtree 1st place", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Haligtree1st);
		}

		if (ImGui::Button("Haligtree 2nd place", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Haligtree2nd);
		}

		if (ImGui::Button("Haligtree 3rd place", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *Haligtree3rd);
		}
		*/
	}
	if (tele_window == "east")
	{
		ImGui::Text("East");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Farum Azula bridge", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *FarumAzulaBridge);
		}

		if (ImGui::Button("Farum Azula balcony", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *FarumAzulaBalcony);
		}
	}
	if (tele_window == "southeast")
	{
		ImGui::Text("Southeast");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Caelid Sanctum", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CaelidSanctum);
		}

		if (ImGui::Button("Caelid Dragon bridge", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CaelidDragonBridge);
		}
		/*
		if (ImGui::Button("Top of Caelid Divine tower", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *TopOfCaelidDivineTower);
		}
		*/
		if (ImGui::Button("Caelid colosseum", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CaelidColosseum);
		}

		if (ImGui::Button("Caelid swamp", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CaelidSwamp);
		}

		if (ImGui::Button("Redmane castle (Radahn)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *RedmaneCastle);
		}
	}
	if (tele_window == "south")
	{
		ImGui::Text("South");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Castle Morne entrance", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CastleMorneEntrance);
		}

		if (ImGui::Button("Back of Castle Morne", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *BackOfCastleMorne);
		}

		if (ImGui::Button("South witch ruins", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *SouthWitchRuins);
		}
	}
	if (tele_window == "misc/funny")
	{
		ImGui::Text("South");
		if (ImGui::Button(ICON_FA_ARROW_LEFT_LONG, ImVec2(ImGui::GetContentRegionAvail().x, NULL))) {

			tele_window = "tele_main";
		}

		if (ImGui::Button("Roundtable locked room(use at roundtable)", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *RoundtableLockedRoom);
		}

		if (ImGui::Button("Center of the map?", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *CenterMap);
		}

		if (ImGui::Button("Inside Golden tree", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			teleport(WorldChrManRealReal, NetManImpRealReal, *InsideGoldenTree);
		}
	}
}