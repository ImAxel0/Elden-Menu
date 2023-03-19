#pragma once

#include <Windows.h>
#include <xmmintrin.h>

extern "C" void speedAsm_func();
extern "C" void vigorAsm_func();
extern "C" void runeAsm_func();
extern "C" void levelAsm_func();
extern "C" void fovAsm_func();
extern "C" void noWeightAsm_func();

extern "C" LPVOID speedBack;
extern "C" LPVOID statsBack;
extern "C" LPVOID runeBack;
extern "C" LPVOID levelBack;
extern "C" LPVOID fovBack;
extern "C" LPVOID noWeightBack;

extern "C" DWORD_PTR dwSpeed;
extern "C" DWORD_PTR* dwVigorAddr;
extern "C" DWORD_PTR* dwRuneAddr;
extern "C" DWORD_PTR* dwLevelAddr;
extern "C" float FieldOfView;
extern "C" __m128 fov;