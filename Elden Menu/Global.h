#pragma once

#include <Windows.h>
#include <xmmintrin.h>

extern "C" void vigorAsm_func();
extern "C" void runeAsm_func();
extern "C" void levelAsm_func();
extern "C" void fovAsm_func();
extern "C" void noWeightAsm_func();
extern "C" void runeMultiplierAsm_func();
extern "C" void playerHeightAsm_func();
extern "C" void playerWidthAsm_func();
extern "C" void playerLengthAsm_func();

extern "C" LPVOID statsBack;
extern "C" LPVOID runeBack;
extern "C" LPVOID levelBack;
extern "C" LPVOID fovBack;
extern "C" LPVOID noWeightBack;
extern "C" LPVOID runeMultiplierBack;
extern "C" LPVOID playerHeightBack;
extern "C" LPVOID playerWidthBack;
extern "C" LPVOID playerLengthBack;

extern "C" DWORD_PTR* dwVigorAddr;
extern "C" DWORD_PTR* dwRuneAddr;
extern "C" DWORD_PTR* dwLevelAddr;

extern "C" float FieldOfView;
extern "C" __m128 fov;
extern "C" float dwRuneMul;

extern "C" float pHeight;
extern "C" __m128 playerHeight_m128;
extern "C" float pWidth;
extern "C" __m128 playerWidth_m128;
extern "C" float pLength;
extern "C" __m128 playerLength_m128;