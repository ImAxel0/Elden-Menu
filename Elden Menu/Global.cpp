#include "Global.h"
#include <xmmintrin.h>

LPVOID speedBack = nullptr;
LPVOID statsBack = nullptr;
LPVOID runeBack = nullptr;
LPVOID levelBack = nullptr;
LPVOID fovBack = nullptr;
LPVOID noWeightBack = nullptr;

DWORD_PTR dwSpeed = 1;
DWORD_PTR* dwVigorAddr = nullptr;
DWORD_PTR* dwRuneAddr = nullptr;
DWORD_PTR* dwLevelAddr = nullptr;
float FieldOfView = 48.0f;
__m128 fov = _mm_setr_ps(48.0f, 0.0f, 0.0f, 0.0f);