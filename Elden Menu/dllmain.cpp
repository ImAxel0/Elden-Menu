#include "DirectX12.h"
#include "DirectX12Demo.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx12.h"
#include "ImGui/imgui_impl_win32.h"

#include "ModUtils.h"
#include "functions.h"
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include "font.h"
#include "iconfont.h"
#include "Global.h"
#include "Detours/include/detours.h"
#include <xmmintrin.h>
#include <Xinput.h>
#include "ini.h"

#pragma comment (lib, "xinput")
#pragma comment (lib, "Shell32")
#pragma comment (lib, "version")

using namespace mINI;
using namespace ModUtils;

bool ShowMenu = false;
bool ImGui_Initialised = false;

std::vector<uint16_t> playerCamera = { 0x0F,0x86,MASKED,MASKED,MASKED,MASKED,0x0F,0x10,0x90 };
uintptr_t playerCameraAddr = SigScan(playerCamera);

std::vector<uint16_t> noWeight = { 0xff,0xc3,0x83,0xfb,MASKED,0x7c,MASKED,0x4c,0x8d,0x5c,0x24 };
uintptr_t noWeightAddr = SigScan(noWeight);

std::vector<uint16_t> mrv_int = { 0x74,MASKED,0x0f,0xb6,0x47,MASKED,0xeb,MASKED,0x8b,0xc6,0x0f,0xb6,0xc0,0x41,0x39,0x87,MASKED,MASKED,MASKED,MASKED,0x0f,0x8c,MASKED,MASKED,MASKED,MASKED,0x48,0x85,0xff,0x74,MASKED,0x0f,0xb6,0x47,MASKED,0xeb,MASKED,0x8b,0xc6,0x0f,0xb6,0xc0,0x41,0x39,0x87,MASKED,MASKED,MASKED,MASKED,0x0f,0x8c,MASKED,MASKED,MASKED,MASKED,0x48,0x85,0xff,0x74,MASKED,0x0f,0xb6,0x47 };
uintptr_t magic_RvIntAddress = SigScan(mrv_int);
std::vector<uint16_t> mdv_int = { 0x74,MASKED,0x44,0x0f,0xb6,0x68,MASKED,0x45,0x0f,0xb6,0xc5,0xba,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x48,0x8b,0x44,0x24,MASKED,0x48,0x85,0xc0,0x74,MASKED,0x44,0x0f,0xb6,0x68,MASKED,0x45,0x0f,0xb6,0xc5,0xba,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x48,0x8b,0x44,0x24 };
uintptr_t magic_DvIntAddress = SigScan(mdv_int);

std::vector<uint16_t> wrv_str = { 0x74,MASKED,0x0f,0xb6,0x80,MASKED,MASKED,MASKED,MASKED,0xeb,MASKED,0x8b,0xc3,0x0f,0xb6,0xc0 };
uintptr_t weapons_RvStrAddress = SigScan(wrv_str);
std::vector<uint16_t> wdv_str = { 0x0f,0x84,MASKED,MASKED,MASKED,MASKED,0x44,0x0f,0xb6,0x80,MASKED,MASKED,MASKED,MASKED,0x8b,0xd3,0xe8,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x4d,0x8b,0xc7,0x48,0x8d,0x55,MASKED,0x48,0x8b,0xcf,0xe8,MASKED,MASKED,MASKED,MASKED,0x48,0x8b,0x45,MASKED,0x49,0x8b,0xce,0x48,0x85,0xc0,0x0f,0x84,MASKED,MASKED,MASKED,MASKED,0x44,0x0f,0xb6,0x80,MASKED,MASKED,MASKED,MASKED,0x8b,0xd3,0xe8,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x4d,0x8b,0xc7,0x48,0x8d,0x55,MASKED,0x48,0x8b,0xcf,0xe8,MASKED,MASKED,MASKED,MASKED,0x48,0x8b,0x45,MASKED,0x49,0x8b,0xce,0x48,0x85,0xc0,0x0f,0x84,MASKED,MASKED,MASKED,MASKED,0x44,0x0f,0xb6,0x80,MASKED,MASKED,MASKED,MASKED,0x8b,0xd3,0xe8,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x4d,0x8b,0xc7,0x48,0x8d,0x55,MASKED,0x48,0x8b,0xcf,0xe8,MASKED,MASKED,MASKED,MASKED,0x48,0x8b,0x45,MASKED,0x49,0x8b,0xce,0x48,0x85,0xc0,0x0f,0x84,MASKED,MASKED,MASKED,MASKED,0x44,0x0f,0xb6,0x80,MASKED,MASKED,MASKED,MASKED,0x8b,0xd3,0xe8,MASKED,MASKED,MASKED,MASKED,0xe9,MASKED,MASKED,MASKED,MASKED,0x81,0xfb,MASKED,MASKED,MASKED,MASKED,0x75,MASKED,0x4d,0x8b,0xc7,0x48,0x8d,0x55,MASKED,0x48,0x8b,0xcf,0xe8,MASKED,MASKED,MASKED,MASKED,0x48,0x8b,0x45,MASKED,0x49,0x8b,0xce };
uintptr_t weapons_DvStrAddress = SigScan(wdv_str);

std::vector<uint16_t> FasterRespawn = { 0x74, MASKED, 0xf3, 0x0f, 0x10, 0x19 };
uintptr_t FasterRespawnAddr = SigScan(FasterRespawn);

std::vector<uint16_t> runes = { 0x89, 0x41, 0x6C, 0x41 };
uintptr_t runesAddr = SigScan(runes);

std::vector<uint16_t> vigor = { 0x8B, 0x7B, 0x3C, 0x48 };
uintptr_t vigorAddr = SigScan(vigor);

std::vector<uint16_t> level = { 0x8b,0x59,MASKED,0x3b,0x9f };
uintptr_t levelAddr = SigScan(level);

std::vector<uint16_t> Fov = { 0x80, 0xbb, MASKED, MASKED, MASKED, MASKED, 0x00, 0x44, MASKED, MASKED, 0xE0, 0xF3, 0x44, MASKED, MASKED, MASKED, MASKED, MASKED, MASKED, MASKED, 0x45 };
uintptr_t fovAddr = SigScan(Fov);

std::vector<uint16_t> noStoneRequirement = { 0x74,MASKED,0x41,0x0F,0xBE,0x40 };
uintptr_t noStoneRequirementAddr = SigScan(noStoneRequirement);

std::vector<uint16_t> multiJump = { 0x83,0xEC,MASKED,0x80,0xB9,0xD1,0x01,0x00,0x00,0x00,0x74,MASKED,0x48 };
uintptr_t multiJumpAddr = SigScan(multiJump);

std::vector<uint16_t> invisibleToEnemy = { 0x74,MASKED,0x44,0x88,0xb9,MASKED,MASKED,MASKED,MASKED,0xe9 };
uintptr_t invisibleToEnemyAddr = SigScan(invisibleToEnemy);

std::vector<uint16_t> runeMultiplier = { 0xf3,0x0f,0x59,0xc1,0xf3,0x0f,0x2c,0xf8,0x48,0x8b,0x8b };
uintptr_t runeMultiplierAddr = SigScan(runeMultiplier);

std::vector<uint16_t> playerHeight = { 0xf3,0x0f,0x10,0x8e,MASKED,MASKED,MASKED,MASKED,0x44,0x0f,0x28,0xd2 };
uintptr_t playerHeightAddr = SigScan(playerHeight);

std::vector<uint16_t> hideCloth = { 0xF3, 0x41, 0x0F, 0x10, 0x08, 0x0F, 0xC6 };
uintptr_t hideClothAddr = SigScan(hideCloth);

std::vector<uint16_t> GameDataMan = { 0x48,0x8B,0x05,MASKED,MASKED,MASKED,MASKED,0x48,0x85,0xC0,0x74,0x05,0x48,0x8B,0x40,0x58,0xC3,0xC3 }; // mov rax,[GameDataMan]
uintptr_t GameDataManAddr = SigScan(GameDataMan);

std::vector<uint16_t> WorldChrMan = { 0x48,0x8B,0x05,MASKED,MASKED,MASKED,MASKED,0x48,0x85,0xC0,0x74,0x0F,0x48,0x39,0x88 }; // mov rax,[WorldChrMan]
uintptr_t WorldChrManAddr = SigScan(WorldChrMan);

std::vector<uint16_t> EventFlagMan = { 0x48,0x8B,0x3D,MASKED,MASKED,MASKED,MASKED,0x48,0x85,0xFF,MASKED,MASKED,0x32,0xC0,0xE9 }; // mov rdi,[EventFlagMan] -> test rdi,rdi
uintptr_t EventFlagManAddr = SigScan(EventFlagMan);

std::vector<uint16_t> CHR_DBG_FLAGS = { 0x80,0x3D,MASKED,MASKED,MASKED,MASKED,0x00,0x0F,0x85,MASKED,MASKED,MASKED,MASKED,0x32,0xC0,0x48 }; // cmp byte ptr[CHR_DBG_FLAGS],00
uintptr_t CHR_DBG_FLAGSAddr = SigScan(CHR_DBG_FLAGS);

std::vector<uint16_t> showGraces = { 0x0F,0xB6,0x0D,MASKED,MASKED,MASKED,MASKED,0xE8,MASKED,MASKED,MASKED,MASKED,0x44,0x8B,0xE0 }; // movzx ecx,byte ptr [7FF6BE2A3D80]
uintptr_t showGracesAddr = SigScan(showGraces);

// to store the 4 op codes relatives to the corresponding address
int* CHR_DBG_4bytesAddr = (int*)(CHR_DBG_FLAGSAddr + (byte)0x2);
int* WorldChrMan_4bytesAddr = (int*)(WorldChrManAddr + (byte)0x3);
int* GameDataMan_4bytesAddr = (int*)(GameDataManAddr + (byte)0x3);
int* EventFlagMan_4bytesAddr = (int*)(EventFlagManAddr + (byte)0x3);
int* showGraces_4bytesAddr = (int*)(showGracesAddr + (byte)0x3);
// to read and store the 4 op codes as an address
uintptr_t CHR_DBG_FLAGSReal = readAddress(CHR_DBG_FLAGSAddr, *CHR_DBG_4bytesAddr, 7);
uintptr_t* WorldChrManReal = (uintptr_t*)readAddress(WorldChrManAddr, *WorldChrMan_4bytesAddr, 7);
uintptr_t WorldChrManRealReal{ 0 };
uintptr_t* GameDataManReal = (uintptr_t*)readAddress(GameDataManAddr, *GameDataMan_4bytesAddr, 7);
uintptr_t GameDataManRealReal{ 0 };
uintptr_t* EventFlagManReal = (uintptr_t*)readAddress(EventFlagManAddr, *EventFlagMan_4bytesAddr, 7);
uintptr_t EventFlagManRealReal{ 0 };
uintptr_t showGracesReal = readAddress(showGracesAddr, *showGraces_4bytesAddr, 7);

bool isOpen = true;
bool showModPage = false;
bool showAbout = false;
bool showTips = false;
bool showStats = true;
bool showLevel = true;
bool showSlotChanger = false;

bool getRune = true;
bool getRuneMultiplier = true;
bool getPlayerHeight = true;
bool getPlayerWidth = true;
bool getPlayerLength = true;
bool fovDetour = true;
bool key1 = false;
bool key2 = true;
bool currentlyPressed = false;
bool previouslyPressed = false;
bool proportionDeactivated = false;
bool mapsShowed = false;
bool gracesShown = false;

bool isGodMode = false;
bool isInfMagic = false;
bool isInfStamina = false;
bool isNoWeight = false;
bool isNoStatsRequirement = false;
bool isFasterRespawn = false;
bool isNoRunes = false;
bool isNoStoneRequired = false;
bool isMultiJump = false;
bool isInvisibleToEnemy = false;
bool isHideCloth = false;
bool isProportion = true;
bool isWalkInTheAir = false;
bool isUnlimitedArrow = false;
bool isOneHitKill = false;
bool isEnemiesDoNotAttack = false;
bool isUnlimitedConsumables = false;
bool isFreezeEnemies = false;

const char* playerSpeed[] = { "Default", "x2", "x3", "x5", "x10" };
static int playerSpeed_current = 0;
static int playerSpeed_old = playerSpeed_current;

const char* runeMoltiplicatore[] = { "Default (x1)", "x2", "x3", "x5", "x10" };
static int runeMultiplier_current = 0;
static int runeMultiplier_old = runeMultiplier_current;

std::string window = "window_home";

const auto lpGetValueNoWeight = (LPVOID)((DWORD_PTR)noWeightAddr);
const auto lpGetValueRuneMultiplier = (LPVOID)((DWORD_PTR)runeMultiplierAddr);

const auto lpGetValuePlayerHeight = (LPVOID)((DWORD_PTR)playerHeightAddr);
const auto lpGetValuePlayerWidth = (LPVOID)((DWORD_PTR)(playerHeightAddr - 0x4b));
const auto lpGetValuePlayerLength = (LPVOID)((DWORD_PTR)(playerHeightAddr + 0x0f));

const auto LocalPlayerOffset = 0x10ef8;

const char credits[] = "Thanks to TechieW for the ModUtils header\nThanks to Hexinton for the cheat table";

ImColor yellow = { 244, 202, 33 };
ImColor blue = { 12, 54, 124 };
ImColor green = { 48, 167, 24 };
ImColor pink = { 255, 0, 255 };
ImColor fuchsia = { 220, 10, 121 };
ImColor purple = { 128, 0, 128 };
ImColor red = { 255, 0, 0 };
ImColor cyan = { 0, 255, 255 };
ImColor black = { 0, 0, 0 };
ImColor white = { 255, 255, 255 };
ImColor* color = &cyan;

struct DETOUR_ALIGN
{
	BYTE    obTarget : 3;
	BYTE    obTrampoline : 5;
};

struct DETOUR_INFO
{
	BYTE            rbCode[30];     // target code + jmp to pbRemain.
	BYTE            cbCode;         // size of moved target code.
	BYTE            cbCodeBreak;    // padding to make debugging easier.
	BYTE            rbRestore[30];  // original target code.
	BYTE            cbRestore;      // size of original target code.
	BYTE            cbRestoreBreak; // padding to make debugging easier.
	DETOUR_ALIGN    rAlign[8];      // instruction alignment array.
	PBYTE           pbRemain;       // first instruction after moved code. [free list]
	PBYTE           pbDetour;       // first instruction of detour function.
	BYTE            rbCodeIn[8];    // jmp [pbDetour]
};

using lpGetValueFnc = INT64(*)();

namespace Process {
	DWORD ID;
	HANDLE Handle;
	HWND Hwnd;
	HMODULE Module;
	WNDPROC WndProc;
	int WindowWidth;
	int WindowHeight;
	LPCSTR Title;
	LPCSTR ClassName;
	LPCSTR Path;
	LPPOINT Point;
}

namespace DirectX12Interface {
	ID3D12Device* Device = nullptr;
	ID3D12DescriptorHeap* DescriptorHeapBackBuffers;
	ID3D12DescriptorHeap* DescriptorHeapImGuiRender;
	ID3D12GraphicsCommandList* CommandList;
	ID3D12CommandQueue* CommandQueue;

	struct _FrameContext {
		ID3D12CommandAllocator* CommandAllocator;
		ID3D12Resource* Resource;
		D3D12_CPU_DESCRIPTOR_HANDLE DescriptorHandle;
	};

	uintx_t BuffersCounts = -1;
	_FrameContext* FrameContext;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if ((ShowMenu && key1 && key2) || (!currentlyPressed && previouslyPressed)) {
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
		return true;
	}
	return CallWindowProc(Process::WndProc, hwnd, uMsg, wParam, lParam);	
}

typedef BOOL(WINAPI* hk_SetCursorPos)(int, int);
hk_SetCursorPos origSetCursorPos = NULL;

BOOL WINAPI HOOK_SetCursorPos(int X, int Y)
{
	if ((ShowMenu && key1 && key2) || (!currentlyPressed && previouslyPressed)) {
		return FALSE;
	}

	return origSetCursorPos(X, Y);
}

void InitCursorHook()
{
	if (MH_CreateHook(&SetCursorPos, &HOOK_SetCursorPos, reinterpret_cast<LPVOID*>(&origSetCursorPos)) != MH_OK)
	{
		std::cout << "Couldn't create hook for SetCursorPos." << '\n';
		return;
	}

	if (MH_EnableHook(&SetCursorPos) != MH_OK)
	{
		std::cout << "Couldn't enable SetCursorPos hook." << '\n';
	}
}

static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled(ICON_FA_QUESTION);
	if (ImGui::IsItemHovered(ImGuiHoveredFlags_None))
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

std::string gameVer;
DWORD openKey{0x50};
DWORD visualKey{0x11};
bool debugMode = false;

void ReadConfig()
{
	INIFile config(GetModuleFolderPath() + "\\config.ini");
	INIStructure ini;

	if (config.read(ini))
	{
		gameVer = (ini["Game version"].get("version"));
		openKey = std::stoi(ini["Open/close key"].get("key value"), nullptr, 16);
		visualKey = std::stoi(ini["Unlock visual key"].get("key value"), nullptr, 16);
		debugMode = std::stoi(ini["Debug mode"].get("value"));
	}
	else
	{
		ini["Game version"]["version"] = "1.09";
		ini["Open/close key"]["key value"] = std::stoi("0x50", nullptr, 16);
		ini["Unlock visual key"]["key value"] = std::stoi("0x11", nullptr, 16);
		ini["Debug mode"]["value"] = "0";
		config.write(ini, true);
	}
	if (debugMode) {
		AllocConsole();
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
}

HRESULT APIENTRY MJPresent(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags) {

	if (!ImGui_Initialised) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D12Device), (void**)&DirectX12Interface::Device))) {
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
			io.IniFilename = nullptr;
			io.LogFilename = nullptr;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
			io.Fonts->AddFontFromMemoryTTF(&OpenSans_Italic_ttf, 1, 20.0f);
			float baseFontSize = 13.0f;
			float iconFontSize = baseFontSize * 2.0f / 3.0f;
			static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
			ImFontConfig config;
			config.MergeMode = true;
			config.GlyphMinAdvanceX = 13.0f;
			static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
			io.Fonts->AddFontFromMemoryTTF(&icon_font_ttf, sizeof icon_font_ttf, 13.0f, &config, icon_ranges);

			DXGI_SWAP_CHAIN_DESC Desc;
			pSwapChain->GetDesc(&Desc);
			Desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
			Desc.OutputWindow = Process::Hwnd;
			Desc.Windowed = ((GetWindowLongPtr(Process::Hwnd, GWL_STYLE) & WS_POPUP) != 0) ? false : true;

			DirectX12Interface::BuffersCounts = Desc.BufferCount;
			DirectX12Interface::FrameContext = new DirectX12Interface::_FrameContext[DirectX12Interface::BuffersCounts];

			D3D12_DESCRIPTOR_HEAP_DESC DescriptorImGuiRender = {};
			DescriptorImGuiRender.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
			DescriptorImGuiRender.NumDescriptors = DirectX12Interface::BuffersCounts;
			DescriptorImGuiRender.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

			if (DirectX12Interface::Device->CreateDescriptorHeap(&DescriptorImGuiRender, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapImGuiRender)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			ID3D12CommandAllocator* Allocator;
			if (DirectX12Interface::Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&Allocator)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			for (size_t i = 0; i < DirectX12Interface::BuffersCounts; i++) {
				DirectX12Interface::FrameContext[i].CommandAllocator = Allocator;
			}

			if (DirectX12Interface::Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, Allocator, NULL, IID_PPV_ARGS(&DirectX12Interface::CommandList)) != S_OK ||
				DirectX12Interface::CommandList->Close() != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			D3D12_DESCRIPTOR_HEAP_DESC DescriptorBackBuffers;
			DescriptorBackBuffers.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
			DescriptorBackBuffers.NumDescriptors = DirectX12Interface::BuffersCounts;
			DescriptorBackBuffers.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
			DescriptorBackBuffers.NodeMask = 1;

			if (DirectX12Interface::Device->CreateDescriptorHeap(&DescriptorBackBuffers, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapBackBuffers)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			const auto RTVDescriptorSize = DirectX12Interface::Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
			D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle = DirectX12Interface::DescriptorHeapBackBuffers->GetCPUDescriptorHandleForHeapStart();

			for (size_t i = 0; i < DirectX12Interface::BuffersCounts; i++) {
				ID3D12Resource* pBackBuffer = nullptr;
				DirectX12Interface::FrameContext[i].DescriptorHandle = RTVHandle;
				pSwapChain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
				DirectX12Interface::Device->CreateRenderTargetView(pBackBuffer, nullptr, RTVHandle);
				DirectX12Interface::FrameContext[i].Resource = pBackBuffer;
				RTVHandle.ptr += RTVDescriptorSize;
			}

			ImGui_ImplWin32_Init(Process::Hwnd);
			ImGui_ImplDX12_Init(DirectX12Interface::Device, DirectX12Interface::BuffersCounts, DXGI_FORMAT_R8G8B8A8_UNORM, DirectX12Interface::DescriptorHeapImGuiRender, DirectX12Interface::DescriptorHeapImGuiRender->GetCPUDescriptorHandleForHeapStart(), DirectX12Interface::DescriptorHeapImGuiRender->GetGPUDescriptorHandleForHeapStart());
			ImGui_ImplDX12_CreateDeviceObjects();
			ImGui::GetIO().ImeWindowHandle = Process::Hwnd;
			Process::WndProc = (WNDPROC)SetWindowLongPtr(Process::Hwnd, GWLP_WNDPROC, (__int3264)(LONG_PTR)WndProc);
		}
		ImGui_Initialised = true;
	}

	if (DirectX12Interface::CommandQueue == nullptr)
		return oPresent(pSwapChain, SyncInterval, Flags);

	if (GetAsyncKeyState(openKey) & 1) {

		ShowMenu = !ShowMenu;

		if (ShowMenu) {
			Replace(playerCameraAddr, { 0x0F, 0x86, 0xB2, MASKED, MASKED, MASKED }, { 0xE9, 0xB3, 0x00, 0x00, 0x00 });
		}
		else {
			Replace(playerCameraAddr, { 0xE9, 0xB3, 0x00, 0x00, 0x00 }, { 0x0F, 0x86, 0xB2, 0x00, 0x00, 0x00 });
		}
	}

	XINPUT_STATE xinput_state;
	if (XInputGetState(0, &xinput_state) == ERROR_SUCCESS)
	{
		const XINPUT_GAMEPAD& gamepad = xinput_state.Gamepad;
		currentlyPressed = (gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && (gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB);
		
		if (!currentlyPressed && previouslyPressed) {
			ShowMenu = !ShowMenu;
		}
		previouslyPressed = currentlyPressed;
	}

	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = ShowMenu;

	WorldChrManRealReal = *WorldChrManReal;
	GameDataManRealReal = *GameDataManReal;
	EventFlagManRealReal = *EventFlagManReal;
	
	if (ShowMenu == true) {

		if (GetKeyState(visualKey) & 0x8000) {
			
			if (key2) {
				Replace(playerCameraAddr, { 0xE9, 0xB3, 0x00, 0x00, 0x00 }, { 0x0F, 0x86, 0xB2, 0x00, 0x00, 0x00 });
			}		
			ImGui::GetIO().MouseDrawCursor = false;
			key1 = false;
			key2 = false;
		}
		if (key1 && !key2) {

			key2 = true;
			Replace(playerCameraAddr, { 0x0F, 0x86, 0xB2, MASKED, MASKED, MASKED }, { 0xE9, 0xB3, 0x00, 0x00, 0x00 });
			ImGui::GetIO().WantCaptureMouse = true;
			ImGui::GetIO().MouseDrawCursor = true;
		}
		key1 = true;
		
		ImGuiStyle* style = &ImGui::GetStyle();
		style->WindowTitleAlign = ImVec2(0.5, 0.5);
		style->Colors[ImGuiCol_TitleBgActive] = *color;
		style->Colors[ImGuiCol_TitleBg] = *color;
		style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0, 255);
		if (color == &black || color == &purple || color == &blue) {
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		}			
		style->Colors[ImGuiCol_Border] = *color;
		ImGui::SetNextWindowSize(ImVec2(350, 550));
		style->Colors[ImGuiCol_ButtonHovered] = ImColor(100, 100, 100, 255);
		ImGui::Begin("ELDEN MENU", &isOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoScrollbar);

		style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);

		ImGui::BeginMenuBar();

		style->Colors[ImGuiCol_Button] = ImColor(60, 60, 60, 255);
		style->Colors[ImGuiCol_ButtonHovered] = ImColor(80, 80, 80, 255);
		style->ItemSpacing = ImVec2(8, NULL);

		if (ImGui::SmallButton("About"))
		{
			showAbout = !showAbout;
		}
		
		if (ImGui::SmallButton("Tips " ICON_FA_EXCLAMATION))
		{
			showTips = !showTips;
		}

		ImGui::EndMenuBar();

		if (window == "window_home")
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);
			
			if (isGodMode) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
			
			if (ImGui::Button(ICON_FA_HEART "  GOD MODE", ImVec2(332, NULL)))
			{
				isGodMode = !isGodMode;

				static byte* godMode = (byte*)CHR_DBG_FLAGSReal;
				if (isGodMode) {
					*godMode = 0x1;
				}
				else {
					*godMode = 0x0;
				}
			}
			ImGui::SameLine(); HelpMarker("Player can't die, HP bar will go down visually");

			if (isInfStamina) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_HAND_FIST"  INF STAMINA", ImVec2(332, NULL)))
			{
				isInfStamina = !isInfStamina;

				static byte* infStamina = (byte*)(CHR_DBG_FLAGSReal+(byte)0x4);
				if (isInfStamina) {
					*infStamina = 0x1;
				}
				else {
					*infStamina = 0x0;
				}
			}
			ImGui::SameLine(); HelpMarker("Unlimited stamina points");

			if (isInfMagic) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
			
			if (ImGui::Button(ICON_FA_WAND_MAGIC_SPARKLES "  INFINITE MAGIC", ImVec2(332, NULL)))
			{
				isInfMagic = !isInfMagic;

				static byte* infMagic = (byte*)(CHR_DBG_FLAGSReal + (byte)0x5);
				if (isInfMagic) {
					*infMagic = 0x1;
				}
				else {
					*infMagic = 0x0;
				}
			}
			ImGui::SameLine(); HelpMarker("No magic points consume");
			
			if (isNoWeight) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (noWeightAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
			
			if (ImGui::Button(ICON_FA_WEIGHT_SCALE "  NO WEIGHT", ImVec2(332, NULL)))
			{
				isNoWeight = !isNoWeight;

				if (isNoWeight)
				{
					PDETOUR_TRAMPOLINE lpTrampolineData = {};					

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourAttachEx((PVOID*)&lpGetValueNoWeight, (PVOID)&noWeightAsm_func, &lpTrampolineData, nullptr, nullptr);
					DetourTransactionCommit();
					const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
					noWeightBack = lpDetourInfo->pbRemain;
				}
				else if (!isNoWeight)
				{
					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourDetach(&(PVOID&)lpGetValueNoWeight, noWeightAsm_func);
					DetourTransactionCommit();
				}
			}
			ImGui::SameLine(); HelpMarker("Sets player weight to 0");
			
			if (isNoStatsRequirement) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (magic_RvIntAddress == 0 || magic_DvIntAddress == 0 || weapons_RvStrAddress == 0 || weapons_DvStrAddress == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
						
			if (ImGui::Button(ICON_FA_XMARK "  NO STATS REQUIREMENT", ImVec2(332, NULL)))
			{
				isNoStatsRequirement = !isNoStatsRequirement;
				noStatsRequirement(isNoStatsRequirement, magic_RvIntAddress, magic_DvIntAddress, weapons_RvStrAddress, weapons_DvStrAddress);
			}
			ImGui::SameLine(); HelpMarker("Removes stat requirements to use all magic and weapons abilities");

			if (isFasterRespawn) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (FasterRespawnAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_FORWARD_FAST "  FASTER RESPAWN", ImVec2(332, NULL)))
			{
				isFasterRespawn = !isFasterRespawn;
				fasterRespawn(isFasterRespawn, FasterRespawnAddr);
			}
			ImGui::SameLine(); HelpMarker("Makes player respawn faster after dying");

			if (isNoRunes) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (runesAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
					
			if (ImGui::Button(ICON_FA_SACK_DOLLAR "  INFINITE RUNES", ImVec2(332, NULL)))
			{
				isNoRunes = !isNoRunes;
				noRunes(isNoRunes, runesAddr);
			}
			ImGui::SameLine(); HelpMarker("Lock current runes (you won't get any rune if you pick up them");

			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_FrameBg] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_FrameBgHovered] = ImColor(60, 60, 60, 255);

			if (getRune)
			{
				std::vector<uint16_t> getRunes = { 0x41,0x8b,0x46,MASKED,0x89,0x86,MASKED,MASKED,MASKED,MASKED,0xb0 };
				uintptr_t getRunesAddr = SigScan(getRunes);

				Replace(getRunesAddr, { 0x41, 0x8b, 0x46, 0x6c, 0x89, 0x86, 0xf0, MASKED, MASKED, MASKED }, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
				PDETOUR_TRAMPOLINE lpTrampolineData = {};
				const auto lpGetValue = (LPVOID)((DWORD_PTR)getRunesAddr);

				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttachEx((PVOID*)&lpGetValue, (PVOID)&runeAsm_func, &lpTrampolineData, nullptr, nullptr);
				DetourTransactionCommit();

				const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
				runeBack = lpDetourInfo->pbRemain;
			}
			getRune = false;

			if (dwRuneAddr != 0)
			{
				int* runes = (int*)dwRuneAddr;
				ImGui::InputInt("RUNES", runes, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);
			}

			style->Colors[ImGuiCol_Button] = ImColor(0, 70, 150);
			if (ImGui::Button("MAGIC SLOT EDITOR  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				showSlotChanger = !showSlotChanger;
			}

			style->Colors[ImGuiCol_Button] = ImColor(0, 70, 150);
			if (ImGui::Button("STATS CHANGER  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				window = "window_stats";
			}

			if (ImGui::Button("MISC  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				window = "window_misc";
			}
			style->Colors[ImGuiCol_Button] = ImColor(24, 152, 255);
			if (ImGui::Button(ICON_FA_PAINTBRUSH "  THEMES  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				window = "window_themes";
			}

			style->Colors[ImGuiCol_ChildBg] = ImColor(25, 25, 25, 255);
			ImGui::BeginChild("##", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));

			ImGui::Combo("PLAYER SPEED", &playerSpeed_current, playerSpeed, 5);
			ImGui::SameLine(), HelpMarker("Changes player speed only\n\nPS: needs to be changed and re-inserted after a screen loading has occurred");
			if (playerSpeed_old != playerSpeed_current)
			{
				uintptr_t pSpeedAddr = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { LocalPlayerOffset, 0x00, 0x190, 0x28, 0x17c8 });
				float* pSpeed = (float*)pSpeedAddr;

				playerSpeed_old = playerSpeed_current;

				if (playerSpeed_current == 0)
				{
					*pSpeed = 1.0f;
				}
				else if (playerSpeed_current == 1)
				{
					*pSpeed = 2.0f;
					std::cout << "player speed: " << *pSpeed;
				}
				else if (playerSpeed_current == 2)
				{
					*pSpeed = 3.0f;
				}
				else if (playerSpeed_current == 3)
				{
					*pSpeed = 5.0f;
				}
				else if (playerSpeed_current == 4)
				{
					*pSpeed = 10.0f;
				}
			}

			if (fovDetour)
			{
				Replace(fovAddr, { 0x80, 0xbb, MASKED, MASKED, MASKED, MASKED, 0x00 }, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, });
				PDETOUR_TRAMPOLINE lpTrampolineData = {};
				const auto lpGetValue = (LPVOID)((DWORD_PTR)fovAddr);

				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttachEx((PVOID*)&lpGetValue, (PVOID)&fovAsm_func, &lpTrampolineData, nullptr, nullptr);
				DetourTransactionCommit();

				const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
				fovBack = lpDetourInfo->pbRemain;
			}
			fovDetour = false;
		
			if (fovAddr != 0)
			{
				fov = _mm_setr_ps(FieldOfView, 0.0f, 0.0f, 0.0f);
				ImGui::SliderFloat("FOV", &FieldOfView, 30.0f, 110.0f);
			}
			ImGui::EndChild();
		}
		if (window == "window_stats")
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);

			if (ImGui::Button(ICON_FA_ARROW_LEFT, ImVec2(332, NULL)))
			{
				window = "window_home";
			}

			if (showLevel)
			{
				Replace(levelAddr, { 0x8b, 0x59, MASKED, 0x3b, 0x9f, MASKED, MASKED, MASKED, MASKED }, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
				PDETOUR_TRAMPOLINE lpTrampolineData = {};
				const auto lpGetValue = (LPVOID)((DWORD_PTR)levelAddr);

				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttachEx((PVOID*)&lpGetValue, (PVOID)&levelAsm_func, &lpTrampolineData, nullptr, nullptr);
				DetourTransactionCommit();

				const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
				levelBack = lpDetourInfo->pbRemain;
			}
			showLevel = false;

			if (dwLevelAddr != 0)
			{
				int* level = (int*)dwLevelAddr;
				ImGui::InputInt("LEVEL", level, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);
			}

			if (showStats)
			{
				Replace(vigorAddr + 0x3, { 0x48, 0x85, 0xc9 }, { 0x90, 0x90, 0x90 });
				PDETOUR_TRAMPOLINE lpTrampolineData = {};
				const auto lpGetValue = (LPVOID)((DWORD_PTR)vigorAddr);

				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttachEx((PVOID*)&lpGetValue, (PVOID)&vigorAsm_func, &lpTrampolineData, nullptr, nullptr);
				DetourTransactionCommit();

				const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
				statsBack = lpDetourInfo->pbRemain;
			}
			showStats = false;

			if (dwVigorAddr != 0)
			{

				int* vigor = (int*)dwVigorAddr;
				ImGui::InputInt("VIGOR", vigor, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* mindAddr = vigor + 0x1;
				int* mind = (int*)mindAddr;
				ImGui::InputInt("MIND", mind, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* enduranceAddr = mind + 0x1;
				int* endurance = (int*)enduranceAddr;
				ImGui::InputInt("ENDURANCE", endurance, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* strengthAddr = endurance + 0x1;
				int* strength = (int*)strengthAddr;
				ImGui::InputInt("STRENGTH", strength, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* dexterityAddr = strength + 0x1;
				int* dexterity = (int*)dexterityAddr;
				ImGui::InputInt("DEXTERITY", dexterity, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* intelligenceAddr = dexterity + 0x1;
				int* intelligence = (int*)intelligenceAddr;
				ImGui::InputInt("INTELLIGENCE", intelligence, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* faithAddr = intelligence + 0x1;
				int* faith = (int*)faithAddr;
				ImGui::InputInt("FAITH", faith, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);

				int* arcaneAddr = faith + 0x1;
				int* arcane = (int*)arcaneAddr;
				ImGui::InputInt("ARCANE", arcane, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue);
			}
		}
		if (window == "window_misc")
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);

			if (ImGui::Button(ICON_FA_ARROW_LEFT, ImVec2(332, NULL)))
			{
				window = "window_home";
			}

			if (isNoStoneRequired) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (noStoneRequirementAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_DIAMOND "  NO STONES REQUIRED", ImVec2(332, NULL)))
			{
				isNoStoneRequired = !isNoStoneRequired;
				noStoneRequired(isNoStoneRequired, noStoneRequirementAddr);
			}
			ImGui::SameLine(); HelpMarker("No smithing stones required to upgrade weapons etc.");

			if (isMultiJump) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (multiJumpAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}
			
			if (ImGui::Button(ICON_FA_ARROW_UP "  CHARACTER MULTI JUMP", ImVec2(332, NULL)))
			{
				isMultiJump = !isMultiJump;
				multiJump_func(isMultiJump, (multiJumpAddr + 0x9));
			}
			ImGui::SameLine(); HelpMarker("Not fully functional, only works while the player isn't moving, press the jump key repeatedly to see");

			if (isInvisibleToEnemy) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (invisibleToEnemyAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_EYE "  INVISIBLE TO ENEMIES", ImVec2(332, NULL)))
			{
				isInvisibleToEnemy = !isInvisibleToEnemy;
				invisibleToEnemy_func(isInvisibleToEnemy, invisibleToEnemyAddr);
			}
			ImGui::SameLine(); HelpMarker("Enemies won't see you until you attack them (activate it before enemies have seen you)");

			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			if (ImGui::Button(ICON_FA_EYE_SLASH "  SHOW GRACES + MAP (not persistent)", ImVec2(332, NULL)))
			{
				if (!gracesShown) {
					static byte* gracesAddr = (byte*)showGracesReal;
					*gracesAddr = 0x1;
					gracesAddr = gracesAddr + 0x1;
					*gracesAddr = 0x1;
				}
				gracesShown = true;
			}
			ImGui::SameLine(); HelpMarker("Show all graces + map (not persistent after game reload)");

			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (EventFlagManRealReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_MAP "  UNLOCK ALL MAPS (persistent)", ImVec2(332, NULL)))
			{
				if (!mapsShowed) {
					uintptr_t mapsAddr = FindDMAAddy((uintptr_t)&EventFlagManRealReal, { 0x28, 0x5dc });
					byte* maps = (byte*)mapsAddr;

					for (int i{ 0 }; i < 10; i++) {

						if (i == 9) {
							maps = maps + 0x3;
							*maps = 0xff;
							break;
						}

						*maps = 0xff;
						maps = maps + 0x1;
						std::cout << "1";
					}
				}
				mapsShowed = true;
			}
			ImGui::SameLine(); HelpMarker("CHANGES ARE PERSISTENT!");

			if (isWalkInTheAir) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (WorldChrManRealReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_PERSON_WALKING "  WALK IN THE AIR", ImVec2(332, NULL)))
			{
				isWalkInTheAir = !isWalkInTheAir;

				uintptr_t airWalk = FindDMAAddy((uintptr_t)&WorldChrManRealReal, { LocalPlayerOffset, 0x00, 0x190, 0x68, 0x1d3 });
				byte* airwalk = (byte*)airWalk;
				
				if (isWalkInTheAir) {
					*airwalk = 0x1;
				}
				else {
					*airwalk = 0x0;
				}
				
			}
			ImGui::SameLine(); HelpMarker("It will start to work after you walk on a lower surface than the one you are at, if you jump while in the air the player gets stuck, so just disable it\n\nPS: this needs to be disabled and re-enabled after a loading screen occured");

			if (isUnlimitedArrow) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_ARROWS_DOWN_TO_LINE "  UNLIMITED ARROWS", ImVec2(332, NULL)))
			{
				isUnlimitedArrow = !isUnlimitedArrow;

				static byte* unlimitedArrow = (byte*)(CHR_DBG_FLAGSReal + (byte)0x6);
				if (isUnlimitedArrow) {
					*unlimitedArrow = 0x1;
				}
				else {
					*unlimitedArrow = 0x0;
				}
			}

			if (isUnlimitedConsumables) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_BOWL_FOOD "  UNLIMITED CONSUMABLES", ImVec2(332, NULL)))
			{
				isUnlimitedConsumables = !isUnlimitedConsumables;

				static byte* unlimitedConsumables = (byte*)(CHR_DBG_FLAGSReal + (byte)0x3);
				if (isUnlimitedConsumables) {
					*unlimitedConsumables = 0x1;
				}
				else {
					*unlimitedConsumables = 0x0;
				}
			}

			if (isOneHitKill) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button(ICON_FA_SKULL "  ONE HIT KILL", ImVec2(332, NULL)))
			{
				isOneHitKill = !isOneHitKill;

				static byte* oneHitKill = (byte*)(CHR_DBG_FLAGSReal + (byte)0x2);
				if (isOneHitKill) {
					*oneHitKill = 0x1;
				}
				else {
					*oneHitKill = 0x0;
				}
			}

			if (isEnemiesDoNotAttack) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button( "ENEMIES DON'T ATTACK", ImVec2(332, NULL)))
			{
				isEnemiesDoNotAttack = !isEnemiesDoNotAttack;

				static byte* enemiesDoNotAttack = (byte*)(CHR_DBG_FLAGSReal + (byte)0xd);
				if (isEnemiesDoNotAttack) {
					*enemiesDoNotAttack = 0x1;
				}
				else {
					*enemiesDoNotAttack = 0x0;
				}
			}
			ImGui::SameLine(); HelpMarker("Etities dont attack you");

			if (isFreezeEnemies) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (CHR_DBG_FLAGSReal == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button("FREEZE ENEMIES", ImVec2(332, NULL)))
			{
				isFreezeEnemies = !isFreezeEnemies;

				static byte* freezeEnemies = (byte*)(CHR_DBG_FLAGSReal + (byte)0xe);
				if (isFreezeEnemies) {
					*freezeEnemies = 0x1;
				}
				else {
					*freezeEnemies = 0x0;
				}
			}
			ImGui::SameLine(); HelpMarker("Enemies don't move");

			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			ImGui::Combo("Runes multiplier", &runeMultiplier_current, runeMoltiplicatore, 5);
			ImGui::SameLine(), HelpMarker("Multiplier of gathered runes");
			if (runeMultiplier_old != runeMultiplier_current)
			{
			
				if (getRuneMultiplier)
				{
					Replace(runeMultiplierAddr + 0x5, { 0x0F, 0x2C, 0xF8 }, { 0x90, 0x90, 0x90 });
					PDETOUR_TRAMPOLINE lpTrampolineData = {};

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourAttachEx((PVOID*)&lpGetValueRuneMultiplier, (PVOID)&runeMultiplierAsm_func , & lpTrampolineData, nullptr, nullptr);
					DetourTransactionCommit();

					const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
					runeMultiplierBack = lpDetourInfo->pbRemain;
				}
				getRuneMultiplier = false;

				runeMultiplier_old = runeMultiplier_current;
				if (runeMultiplier_current == 0)
				{
					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourDetach(&(PVOID&)lpGetValueRuneMultiplier, runeMultiplierAsm_func);
					DetourTransactionCommit();
					Replace(runeMultiplierAddr + 0x5, { 0x90, 0x90, 0x90 }, { 0x0F, 0x2C, 0xF8 });
					getRuneMultiplier = true;
				}
				else if (runeMultiplier_current == 1)
				{
					dwRuneMul = 2;
				}
				else if (runeMultiplier_current == 2)
				{
					dwRuneMul = 3;
				}
				else if (runeMultiplier_current == 3)
				{
					dwRuneMul = 5;
				}
				else if (runeMultiplier_current == 4)
				{
					dwRuneMul = 10;
				}
			}
			
			style->Colors[ImGuiCol_Button] = ImColor(0, 70, 150);
			if (ImGui::Button("ENTITIES PROPORTION  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				window = "window_proportion";
			}
		}

		if (window == "window_proportion")
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);

			if (ImGui::Button(ICON_FA_ARROW_LEFT, ImVec2(332, NULL)))
			{
				window = "window_misc";
			}

			if (getPlayerHeight)
			{
				Replace(playerHeightAddr + 0x5, { MASKED, MASKED, MASKED }, { 0x90, 0x90, 0x90 });
				PDETOUR_TRAMPOLINE lpTrampolineData = {};

				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttachEx((PVOID*)&lpGetValuePlayerHeight, (PVOID)&playerHeightAsm_func, &lpTrampolineData, nullptr, nullptr);
				DetourTransactionCommit();

				const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
				playerHeightBack = lpDetourInfo->pbRemain;

				if (getPlayerWidth)
				{
					Replace((playerHeightAddr - 0x4b + 0x5), { MASKED, MASKED, MASKED }, { 0x90, 0x90, 0x90 });
					PDETOUR_TRAMPOLINE lpTrampolineData = {};					

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourAttachEx((PVOID*)&lpGetValuePlayerWidth, (PVOID)&playerWidthAsm_func, &lpTrampolineData, nullptr, nullptr);
					DetourTransactionCommit();

					const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
					playerWidthBack = lpDetourInfo->pbRemain;
				}
				getPlayerWidth = false;

				if (getPlayerLength)
				{
					Replace((playerHeightAddr + 0x0f + 0x5), { MASKED, MASKED, MASKED }, { 0x90, 0x90, 0x90 });
					PDETOUR_TRAMPOLINE lpTrampolineData = {};

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourAttachEx((PVOID*)&lpGetValuePlayerLength, (PVOID)&playerLengthAsm_func, &lpTrampolineData, nullptr, nullptr);
					DetourTransactionCommit();

					const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
					playerLengthBack = lpDetourInfo->pbRemain;
				}
				getPlayerLength = false;
			}
			getPlayerHeight = false;

			if (playerHeightAddr != 0)
			{
				ImGui::Checkbox("Proportion changes on/off", &isProportion);

				if (isProportion) {

					if (proportionDeactivated) {
						getPlayerHeight = true;
						getPlayerWidth = true;
						getPlayerLength = true;
					}
					proportionDeactivated = false;

					playerHeight_m128 = _mm_setr_ps(pHeight, 0.0f, 0.0f, 0.0f);
					ImGui::SliderFloat("height", &pHeight, 0.2f, 3.0f);

					playerWidth_m128 = _mm_setr_ps(pWidth, 0.0f, 0.0f, 0.0f);
					ImGui::SliderFloat("width", &pWidth, 0.2f, 3.0f);

					playerLength_m128 = _mm_setr_ps(pLength, 0.0f, 0.0f, 0.0f);
					ImGui::SliderFloat("length", &pLength, 0.2f, 3.0f);

				}
				else if (!isProportion && !proportionDeactivated) {

					proportionDeactivated = true;

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourDetach(&(PVOID&)lpGetValuePlayerHeight, playerHeightAsm_func);
					DetourTransactionCommit();

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourDetach(&(PVOID&)lpGetValuePlayerWidth, playerWidthAsm_func);
					DetourTransactionCommit();

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourDetach(&(PVOID&)lpGetValuePlayerLength, playerLengthAsm_func);
					DetourTransactionCommit();			

					Replace(playerHeightAddr + 0x5, { MASKED, MASKED, MASKED }, { 0x02, 0x00, 0x00 });
					Replace((playerHeightAddr - 0x4b + 0x5), { MASKED, MASKED, MASKED }, { 0x02, 0x00, 0x00 });
					Replace((playerHeightAddr + 0x0f + 0x5), { MASKED, MASKED, MASKED }, { 0x02, 0x00, 0x00 });
				}
			}

			if (isHideCloth) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (hideClothAddr == 0) {
				style->Colors[ImGuiCol_Text] = ImColor(255, 0, 0);
			}

			if (ImGui::Button("HIDE CLOTH", ImVec2(332, NULL)))
			{
				isHideCloth = !isHideCloth;
				hideCloth_func(isHideCloth, hideClothAddr);
			}
			ImGui::SameLine(); HelpMarker("hide some clothes, useful with some proportions");
		}

		if (showSlotChanger)
		{
			static uintptr_t slot1Addr = FindDMAAddy((uintptr_t)&GameDataManRealReal, { 0x08, 0x518, 0x10 });
			static uintptr_t slot2Addr = slot1Addr + 0x8;
			static uintptr_t slot3Addr = slot2Addr + 0x8;
			static uintptr_t slot4Addr = slot3Addr + 0x8;
			static uintptr_t slot5Addr = slot4Addr + 0x8;
			static uintptr_t slot6Addr = slot5Addr + 0x8;
			static uintptr_t slot7Addr = slot6Addr + 0x8;
			static uintptr_t slot8Addr = slot7Addr + 0x8;
			static uintptr_t slot9Addr = slot8Addr + 0x8;
			static uintptr_t slot10Addr = slot9Addr + 0x8;
			static uintptr_t slot11Addr = slot10Addr + 0x8;
			static uintptr_t slot12Addr = slot11Addr + 0x8;
			static uintptr_t slot13Addr = slot12Addr + 0x8;
			static uintptr_t slot14Addr = slot13Addr + 0x8;

			//std::cout << "MAGIC SLOT 1: " << slot1Addr << '\n';
			static int* magic_slot1 = (int*)slot1Addr;
			static int* magic_slot2 = (int*)slot2Addr;
			static int* magic_slot3 = (int*)slot3Addr;
			static int* magic_slot4 = (int*)slot4Addr;
			static int* magic_slot5 = (int*)slot5Addr;
			static int* magic_slot6 = (int*)slot6Addr;
			static int* magic_slot7 = (int*)slot7Addr;
			static int* magic_slot8 = (int*)slot8Addr;
			static int* magic_slot9 = (int*)slot9Addr;
			static int* magic_slot10 = (int*)slot10Addr;
			static int* magic_slot11 = (int*)slot11Addr;
			static int* magic_slot12 = (int*)slot12Addr;
			static int* magic_slot13 = (int*)slot13Addr;
			static int* magic_slot14 = (int*)slot14Addr;
			//std::cout << "slo1 contain ID: " << *magic_slot1;

			ImGui::SetNextWindowSize(ImVec2(350, 580));
			style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0, 255);
			ImGui::Begin("MAGIC SLOT EDITOR", &showSlotChanger, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
			
			ImGui::Text("INFO ");
			ImGui::SameLine(); HelpMarker("Every magic has it's own ID, you can get it from the button below, than insert the one you want in a slot\n\nYou can even insert id's in slots you haven't still unlocked\n\nSlots which has -1 means they are unassigned or still locked\n\nMagic which occupies 2 slots still displays as one slot in this window");

			ImGui::InputInt("slot  1 magic ID", magic_slot1,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  2 magic ID", magic_slot2,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  3 magic ID", magic_slot3,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  4 magic ID", magic_slot4,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  5 magic ID", magic_slot5,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  6 magic ID", magic_slot6,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  7 magic ID", magic_slot7,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  8 magic ID", magic_slot8,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot  9 magic ID", magic_slot9,  NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot 10 magic ID", magic_slot10, NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot 11 magic ID", magic_slot11, NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot 12 magic ID", magic_slot12, NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot 13 magic ID", magic_slot13, NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::InputInt("slot 14 magic ID", magic_slot14, NULL, NULL, ImGuiInputTextFlags_EnterReturnsTrue);

			if (ImGui::Button("open magic ID's list")) {
				
				static std::string magicPath = (GetModuleFolderPath() + "\\Magic.txt");

				ShellExecute(NULL, "open", magicPath.c_str(), NULL, NULL, SW_SHOW);
			}

			ImGui::End();
		}

		if (window == "window_themes")
		{
			if (ImGui::Button(ICON_FA_ARROW_LEFT, ImVec2(332, NULL)))
			{
				window = "window_home";
			}

			style->Colors[ImGuiCol_Button] = ImColor(0, 0, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 0, 0, 255);
			if (ImGui::Button("BLACK", ImVec2(332, NULL)))
			{
				color = &black;
			}
			style->Colors[ImGuiCol_Button] = ImColor(255, 255, 255, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(255, 255, 255, 255);
			style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0);
			if (ImGui::Button("WHITE", ImVec2(332, NULL)))
			{
				color = &white;
			}
			style->Colors[ImGuiCol_Button] = ImColor(244, 202, 33, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(244, 202, 33, 255);
			if (ImGui::Button("YELLOW", ImVec2(332, NULL)))
			{
				color = &yellow;
			}
			style->Colors[ImGuiCol_Button] = ImColor(12, 54, 124, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(12, 54, 124, 255);
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (ImGui::Button("BLUE", ImVec2(332, NULL)))
			{
				color = &blue;
			}
			style->Colors[ImGuiCol_Button] = ImColor(48, 167, 24, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(48, 167, 24, 255);
			if (ImGui::Button("GREEN", ImVec2(332, NULL)))
			{
				color = &green;
			}
			style->Colors[ImGuiCol_Button] = ImColor(255, 0, 255, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(255, 0, 255, 255);
			style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0);
			if (ImGui::Button("PINK", ImVec2(332, NULL)))
			{
				color = &pink;
			}
			style->Colors[ImGuiCol_Button] = ImColor(220, 10, 121, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(220, 10, 121, 255);
			if (ImGui::Button("FUCHSIA", ImVec2(332, NULL)))
			{
				color = &fuchsia;
			}
			style->Colors[ImGuiCol_Button] = ImColor(128, 0, 128, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(128, 0, 128, 255);
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			if (ImGui::Button("PURPLE", ImVec2(332, NULL)))
			{
				color = &purple;
			}
			style->Colors[ImGuiCol_Button] = ImColor(255, 0, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(255, 0, 0, 255);
			style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0);
			if (ImGui::Button("RED", ImVec2(332, NULL)))
			{
				color = &red;
			}
			style->Colors[ImGuiCol_Button] = ImColor(0, 255, 255, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 255, 255, 255);
			if (ImGui::Button("CYAN", ImVec2(332, NULL)))
			{
				color = &cyan;
			}
		}

		if (showTips)
		{
			ImGui::SetCursorPos(ImVec2(8, 160));
			style->Colors[ImGuiCol_ChildBg] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_Border] = *color;
			style->ChildBorderSize = 3.0f;
			ImGui::BeginChild("tips", ImVec2(330, 70), true, ImGuiWindowFlags_NoCollapse);
			ImGui::Text("Hold 'ctrl' while the menu is open to unlock\nvisual movement");
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			showAbout = false;
			ImGui::EndChild();
		}

		if (showAbout)
		{
			ImGui::SetCursorPos(ImVec2(8, 160));
			style->Colors[ImGuiCol_ChildBg] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_Border] = *color;
			style->ChildBorderSize = 3.0f;
			ImGui::BeginChild("about", ImVec2(330, 140), true, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse); //ImGui::BeginChild("about", ImVec2(200, 70), true, ImGuiWindowFlags_NoCollapse);		
			ImGui::SetCursorPos(ImVec2(95, 20));
			ImGui::Text("Coded by ImAxel0");
			ImGui::Text(credits);
			ImGui::SetCursorPos(ImVec2(285, 110));
			ImGui::Text("v0.3.0");
			style->Colors[ImGuiCol_Text] = ImColor(49, 154, 236);
			ImGui::SetCursorPos(ImVec2(5, 110));
			ImGui::Selectable("Mod page", &showModPage, NULL, ImVec2(80, NULL));
			if (showModPage)
			{
				ShellExecute(NULL, "open", "https://www.nexusmods.com/eldenring/mods/3222", NULL, NULL, SW_SHOWDEFAULT);
				showModPage = false;
			}
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
			showTips = false;
			ImGui::EndChild();
		}

		if (!isOpen)
		{
			Replace(playerCameraAddr, { 0xE9, 0xB3, 0x00, 0x00, 0x00 }, { 0x0F, 0x86, 0xB2, 0x00, 0x00, 0x00 });
			ShowMenu = false;
			isOpen = true;
		}
		ImGui::End();
	}
	ImGui::EndFrame();

	DirectX12Interface::_FrameContext& CurrentFrameContext = DirectX12Interface::FrameContext[pSwapChain->GetCurrentBackBufferIndex()];
	CurrentFrameContext.CommandAllocator->Reset();

	D3D12_RESOURCE_BARRIER Barrier;
	Barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
	Barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	Barrier.Transition.pResource = CurrentFrameContext.Resource;
	Barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
	Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
	Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

	DirectX12Interface::CommandList->Reset(CurrentFrameContext.CommandAllocator, nullptr);
	DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
	DirectX12Interface::CommandList->OMSetRenderTargets(1, &CurrentFrameContext.DescriptorHandle, FALSE, nullptr);
	DirectX12Interface::CommandList->SetDescriptorHeaps(1, &DirectX12Interface::DescriptorHeapImGuiRender);

	ImGui::Render();
	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), DirectX12Interface::CommandList);
	Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
	Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
	DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
	DirectX12Interface::CommandList->Close();
	DirectX12Interface::CommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList* const*>(&DirectX12Interface::CommandList));
	return oPresent(pSwapChain, SyncInterval, Flags);
}

void MJExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists) {
	if (!DirectX12Interface::CommandQueue)
		DirectX12Interface::CommandQueue = queue;

	oExecuteCommandLists(queue, NumCommandLists, ppCommandLists);
}

void APIENTRY MJDrawInstanced(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation) {
	return oDrawInstanced(dCommandList, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
}

void APIENTRY MJDrawIndexedInstanced(ID3D12GraphicsCommandList* dCommandList, UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation) {
	return oDrawIndexedInstanced(dCommandList, IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
}

DWORD WINAPI MainThread(LPVOID lpParameter) {

	bool WindowFocus = false;
	while (WindowFocus == false) {
		DWORD ForegroundWindowProcessID;
		GetWindowThreadProcessId(GetForegroundWindow(), &ForegroundWindowProcessID);
		if (GetCurrentProcessId() == ForegroundWindowProcessID) {

			Process::ID = GetCurrentProcessId();
			Process::Handle = GetCurrentProcess();
			Process::Hwnd = GetForegroundWindow();

			RECT TempRect;
			GetWindowRect(Process::Hwnd, &TempRect);
			Process::WindowWidth = TempRect.right - TempRect.left;
			Process::WindowHeight = TempRect.bottom - TempRect.top;

			char TempTitle[MAX_PATH];
			GetWindowText(Process::Hwnd, TempTitle, sizeof(TempTitle));
			Process::Title = TempTitle;

			char TempClassName[MAX_PATH];
			GetClassName(Process::Hwnd, TempClassName, sizeof(TempClassName));
			Process::ClassName = TempClassName;

			char TempPath[MAX_PATH];
			GetModuleFileNameEx(Process::Handle, NULL, TempPath, sizeof(TempPath));
			Process::Path = TempPath;

			WindowFocus = true;
		}
	}
	bool InitHook = false;
	while (InitHook == false) {
		if (DirectX12::Init() == true) {
			ReadConfig();
			CreateHook(54, (void**)&oExecuteCommandLists, MJExecuteCommandLists);
			CreateHook(140, (void**)&oPresent, MJPresent);
			CreateHook(84, (void**)&oDrawInstanced, MJDrawInstanced);
			CreateHook(85, (void**)&oDrawIndexedInstanced, MJDrawIndexedInstanced);
			InitCursorHook();
			InitHook = true;
		}
	}
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		if (ChecktDirectXVersion(DirectXVersion.D3D12) == true) {
			Process::Module = hModule;
			CreateThread(0, 0, MainThread, 0, 0, 0);
		}
		break;
	case DLL_PROCESS_DETACH:
		FreeLibraryAndExitThread(hModule, TRUE);
		DisableAll();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}

