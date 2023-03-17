#pragma once

#include <Windows.h>

extern "C" void speedAsm_func();
extern "C" void vigorAsm_func();
extern "C" void runeAsm_func();
extern "C" void levelAsm_func();

extern "C" LPVOID speedBack;
extern "C" LPVOID statsBack;
extern "C" LPVOID runeBack;
extern "C" LPVOID levelBack;

extern "C" DWORD_PTR dwSpeed;
extern "C" DWORD_PTR* dwVigorAddr;
extern "C" DWORD_PTR* dwRuneAddr;
extern "C" DWORD_PTR* dwLevelAddr;