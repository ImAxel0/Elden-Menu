#include "ModUtils.h"

using namespace ModUtils;

void noStatsRequirement(bool x, uintptr_t magic_RvIntAddress, uintptr_t magic_DvIntAddress, uintptr_t weapons_RvStrAddress, uintptr_t weapons_DvStrAddress)
{
	if (magic_RvIntAddress != 0 && magic_DvIntAddress != 0 && weapons_RvStrAddress != 0 && weapons_DvStrAddress != 0)
	{
		if (x) {
			Replace(magic_RvIntAddress, { 0x74, 0x06 }, { 0xeb, 0x06 }); //intelligence rv patch			
			magic_RvIntAddress += 0x1d; //offset to faith from intelligence
			Replace(magic_RvIntAddress, { 0x74, 0x06 }, { 0xeb, 0x06 }); //faith rv patch			
			magic_RvIntAddress += 0x1d; //offset to arcane from faith
			Replace(magic_RvIntAddress, { 0x74, 0x06 }, { 0xeb, 0x06 }); //arcane rv patch

			Replace(magic_DvIntAddress, { 0x74, 0x05 }, { 0xeb, 0x05 });//intelligence dv patch		
			magic_DvIntAddress += 0x25; //offset to faith from intelligence
			Replace(magic_DvIntAddress, { 0x74, 0x05 }, { 0xeb, 0x05 }); //faith dv patch			
			magic_DvIntAddress += 0x25; //offset to arcane from faith
			Replace(magic_DvIntAddress, { 0x74, 0x05 }, { 0xeb, 0x05 }); //arcane dv patch

			Replace(weapons_RvStrAddress, { 0x74, 0x09 }, { 0xeb, 0x09 }); //strenght rv patch
			weapons_RvStrAddress += 0x37; //offset from strenght rv address to dexterity rv address
			Replace(weapons_RvStrAddress, { 0x74, 0x09 }, { 0xeb, 0x09 }); //dexterity rv patch
			weapons_RvStrAddress += 0x25; //offset from dex rv address to intelligence rv address
			Replace(weapons_RvStrAddress, { 0x74, 0x09 }, { 0xeb, 0x09 }); //intelligence rv patch
			weapons_RvStrAddress += 0x25; //offset from int rv address to faith rv address
			Replace(weapons_RvStrAddress, { 0x74, 0x07 }, { 0xeb, 0x07 }); //faith rv patch

			Replace(weapons_DvStrAddress, { 0x0f, 0x84 }, { 0x0f, 0x85 }); //strenght dv patch
			weapons_DvStrAddress += 0x3b; // offset from str display value address to dexterity display value address
			Replace(weapons_DvStrAddress, { 0x0f, 0x84 }, { 0x0f, 0x85 }); // dexterity dv patch
			weapons_DvStrAddress += 0x3b; // offset from dex display value address to intelligence display value address
			Replace(weapons_DvStrAddress, { 0x0f, 0x84 }, { 0x0f, 0x85 }); // intelligence dv patch
			weapons_DvStrAddress += 0x3b; // offset from int dv address to faith dv address
			Replace(weapons_DvStrAddress, { 0x0f, 0x84 }, { 0x0f, 0x85 });
			weapons_DvStrAddress += 0x3b; // offset from faith dv address to arcane dv address
			Replace(weapons_DvStrAddress, { 0x0f, 0x84 }, { 0x0f, 0x85 });
		}
		else {
			Replace(magic_RvIntAddress, { 0xeb, 0x06 }, { 0x74, 0x06 }); //intelligence rv patch			
			magic_RvIntAddress += 0x1d; //offset to faith from intelligence
			Replace(magic_RvIntAddress, { 0xeb, 0x06 }, { 0x74, 0x06 }); //faith rv patch			
			magic_RvIntAddress += 0x1d; //offset to arcane from faith
			Replace(magic_RvIntAddress, { 0xeb, 0x06 }, { 0x74, 0x06 }); //arcane rv patch

			Replace(magic_DvIntAddress, { 0xeb, 0x05 }, { 0x74, 0x05 });//intelligence dv patch		
			magic_DvIntAddress += 0x25; //offset to faith from intelligence
			Replace(magic_DvIntAddress, { 0xeb, 0x05 }, { 0x74, 0x05 }); //faith dv patch			
			magic_DvIntAddress += 0x25; //offset to arcane from faith
			Replace(magic_DvIntAddress, { 0xeb, 0x05 }, { 0x74, 0x05 }); //arcane dv patch

			Replace(weapons_RvStrAddress, { 0xeb, 0x09 }, { 0x74, 0x09 }); //strenght rv patch
			weapons_RvStrAddress += 0x37; //offset from strenght rv address to dexterity rv address
			Replace(weapons_RvStrAddress, { 0xeb, 0x09 }, { 0x74, 0x09 }); //dexterity rv patch
			weapons_RvStrAddress += 0x25; //offset from dex rv address to intelligence rv address
			Replace(weapons_RvStrAddress, { 0xeb, 0x09 }, { 0x74, 0x09 }); //intelligence rv patch
			weapons_RvStrAddress += 0x25; //offset from int rv address to faith rv address
			Replace(weapons_RvStrAddress, { 0xeb, 0x07 }, { 0x74, 0x07 }); //faith rv patch

			Replace(weapons_DvStrAddress, { 0x0f, 0x85 }, { 0x0f, 0x84 }); //strenght dv patch
			weapons_DvStrAddress += 0x3b; // offset from str display value address to dexterity display value address
			Replace(weapons_DvStrAddress, { 0x0f, 0x85 }, { 0x0f, 0x84 }); // dexterity dv patch
			weapons_DvStrAddress += 0x3b; // offset from dex display value address to intelligence display value address
			Replace(weapons_DvStrAddress, { 0x0f, 0x85 }, { 0x0f, 0x84 }); // intelligence dv patch
			weapons_DvStrAddress += 0x3b; // offset from int dv address to faith dv address
			Replace(weapons_DvStrAddress, { 0x0f, 0x85 }, { 0x0f, 0x84 });
			weapons_DvStrAddress += 0x3b; // offset from faith dv address to arcane dv address
			Replace(weapons_DvStrAddress, { 0x0f, 0x85 }, { 0x0f, 0x84 });
		}
	}
}

void fasterRespawn(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0x74 }, { 0xeb });
		}
		else {
			Replace(addr, { 0xeb }, { 0x74 });
		}
	}
}

void noRunes(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0x89, 0x41, 0x6C }, { 0x90, 0x90, 0x90 });
		}
		else {
			Replace(addr, { 0x90, 0x90, 0x90 }, { 0x89, 0x41, 0x6C });
		}
	}
}

void noStoneRequired(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0x74 }, { 0xeb });
		}
		else {
			Replace(addr, { 0xeb }, { 0x74 });
		}
	}
}

void multiJump_func(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0x00 }, { 0x92 });
		}
		else {
			Replace(addr, { 0x92 }, { 0x00 });
		}
	}
}

void invisibleToEnemy_func(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0x74, MASKED }, { 0x90, 0x90 });
		}
		else {
			Replace(addr, { 0x90, 0x90 }, { 0x74, 0x0c });
		}
	}
}

void hideCloth_func(bool x, uintptr_t addr)
{
	if (addr != 0)
	{
		if (x) {
			Replace(addr, { 0xF3, 0x41, 0x0F, 0x10, 0x08 }, { 0x90, 0x90, 0x90, 0x90, 0x90 });
		}
		else {
			Replace(addr, { 0x90, 0x90, 0x90, 0x90, 0x90 }, { 0xF3, 0x41, 0x0F, 0x10, 0x08 });
		}
	}
}

void pauseGame(bool x, uintptr_t pauseAddr)
{
	if (x) {
		Replace(pauseAddr + 0x6, { 0x00 }, { 0x01 });
	}
	else {
		Replace(pauseAddr + 0x6, { 0x01 }, { 0x00 });
	}
}

void mapInCombat(bool x, uintptr_t MapInCombat1Addr, uintptr_t MapInCombat2Addr)
{
	if (x) {
		Replace(MapInCombat1Addr, { MASKED, MASKED, MASKED, MASKED, MASKED }, { 0x48, 0x31, 0xC0, 0x90, 0x90 });
		Replace(MapInCombat2Addr, { 0x74 }, { 0xeb });
	}
	else {
		Replace(MapInCombat1Addr, { 0x48, 0x31, 0xC0, 0x90, 0x90 }, { 0xE8, 0xE4, 0x8E, 0x3A, 0x00 });
		Replace(MapInCombat2Addr, { 0xeb }, { 0x74 });
	}
}
