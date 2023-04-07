#include "Global.h"
#include <xmmintrin.h>

LPVOID statsBack = nullptr;
LPVOID runeBack = nullptr;
LPVOID levelBack = nullptr;
LPVOID fovBack = nullptr;
LPVOID noWeightBack = nullptr;
LPVOID runeMultiplierBack = nullptr;
LPVOID playerHeightBack = nullptr;
LPVOID playerWidthBack = nullptr;
LPVOID playerLengthBack = nullptr;

DWORD_PTR* dwVigorAddr = nullptr;
DWORD_PTR* dwRuneAddr = nullptr;
DWORD_PTR* dwLevelAddr = nullptr;

float FieldOfView = 48.0f;
__m128 fov = _mm_setr_ps(48.0f, 0.0f, 0.0f, 0.0f);
float dwRuneMul = 2.0f;

float pHeight = 1.0f;
__m128 playerHeight_m128 = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
float pWidth = 1.0f;
__m128 playerWidth_m128 = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
float pLength = 1.0f;
__m128 playerLength_m128 = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);