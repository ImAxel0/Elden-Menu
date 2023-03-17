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

using namespace ModUtils;

bool ShowMenu = false;
bool ImGui_Initialised = false;


std::vector<uint16_t> playerCamera = { 0x0F,0x86,MASKED,MASKED,MASKED,MASKED,0x0F,0x10,0x90 };
uintptr_t playerCameraAddr = SigScan(playerCamera);

std::vector<uint16_t> magic = { 0x89,0x87,MASKED,MASKED,MASKED,MASKED,0x48,0x8B,0x5C,0x24,0x50 };
uintptr_t magicAddr = SigScan(magic);

std::vector<uint16_t> WeaponsNoWeight = { 0x74, MASKED, 0xf3, 0x0f, 0x58, 0x70, MASKED, 0xff, 0xc7, 0x83, 0xff, MASKED, 0x7c, MASKED, 0x41, 0x8b, 0xfe };
uintptr_t WeaponsNoWeightAddr = SigScan(WeaponsNoWeight);
std::vector<uint16_t> ArmorNoWeight = { 0x74, MASKED, 0xf3, 0x0f, 0x58, 0x70, MASKED, 0xff, 0xc7, 0x83, 0xff, MASKED, 0x7c, MASKED, 0x41, 0x8b, 0xde };
uintptr_t ArmorNoWeightAddr = SigScan(ArmorNoWeight);

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

std::vector<uint16_t> speed = { 0xf3,0x0f,0x10,0x41,MASKED,0x48,0x8d,0x64,0x24,MASKED,0xff,0x64,0x24,MASKED,0xe9 };
uintptr_t playerSpeedAddr = SigScan(speed);

std::vector<uint16_t> vigor = { 0x8B, 0x7B, 0x3C, 0x48 };
uintptr_t vigorAddr = SigScan(vigor);

std::vector<uint16_t> level = { 0x8b,0x59,MASKED,0x3b,0x9f };
uintptr_t levelAddr = SigScan(level);

bool isOpen = true;
bool showAbout = false;
bool showStats = true;
bool showLevel = true;
bool getRune = true;
bool changedSpeed = true;

bool isInfMagic = false;
bool isNoWeight = false;
bool isNoStatsRequirement = false;
bool isFasterRespawn = false;
bool isNoRunes = false;

const char* playerSpeed[] = { "Default", "x2", "x3", "x5", "x10" };
static int playerSpeed_current = 0;
static int playerSpeed_old = playerSpeed_current;

int tab{ 0 };

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

	if (ShowMenu) {
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
		return true;
	}
	return CallWindowProc(Process::WndProc, hwnd, uMsg, wParam, lParam);
}

typedef BOOL(WINAPI* hk_SetCursorPos)(int, int);
hk_SetCursorPos origSetCursorPos = NULL;

BOOL WINAPI HOOK_SetCursorPos(int X, int Y)
{
	if (ShowMenu) {
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

HRESULT APIENTRY MJPresent(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags) {

	if (!ImGui_Initialised) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D12Device), (void**)&DirectX12Interface::Device))) {
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
			io.IniFilename = nullptr;
			io.LogFilename = nullptr;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
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

	if (GetAsyncKeyState('P') & 1) {

		ShowMenu = !ShowMenu;

		if (ShowMenu) {
			Replace(playerCameraAddr, { 0x0F, 0x86, 0xB2, MASKED, MASKED, MASKED }, { 0xE9, 0xB3, 0x00, 0x00, 0x00 });
		}
		else {
			Replace(playerCameraAddr, { 0xE9, 0xB3, 0x00, 0x00, 0x00 }, { 0x0F, 0x86, 0xB2, 0x00, 0x00, 0x00 });
		}
	}

	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = ShowMenu;

	if (ShowMenu == true) {

		ImGuiStyle* style = &ImGui::GetStyle();
		style->WindowTitleAlign = ImVec2(0.5, 0.5);
		style->Colors[ImGuiCol_TitleBgActive] = ImColor(244, 202, 33, 255);
		style->Colors[ImGuiCol_TitleBg] = ImColor(244, 202, 33, 255);
		style->Colors[ImGuiCol_Text] = ImColor(0, 0, 0, 255);
		style->Colors[ImGuiCol_Border] = ImColor(244, 202, 33, 255);
		ImGui::SetNextWindowSize(ImVec2(350, 550));
		style->Colors[ImGuiCol_ButtonHovered] = ImColor(100, 100, 100, 255);
		ImGui::Begin("ELDEN MENU", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar);

		style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);

		ImGui::BeginMenuBar();

		style->Colors[ImGuiCol_Button] = ImColor(60, 60, 60, 255);
		style->Colors[ImGuiCol_ButtonHovered] = ImColor(80, 80, 80, 255);

		if (ImGui::SmallButton("About"))
		{
			showAbout = !showAbout;
		}

		ImGui::EndMenuBar();

		if (tab == 0)
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);

			if (isInfMagic) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}

			if (ImGui::Button(ICON_FA_WAND_MAGIC_SPARKLES "  INFINITE MAGIC", ImVec2(332, NULL)))
			{
				isInfMagic = !isInfMagic;
				infMagic(isInfMagic, magicAddr);
			}

			if (isNoWeight) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}

			if (ImGui::Button(ICON_FA_WEIGHT_SCALE "  NO WEIGHT", ImVec2(332, NULL)))
			{
				isNoWeight = !isNoWeight;
				noWeight(isNoWeight, WeaponsNoWeightAddr, ArmorNoWeightAddr);
			}

			if (isNoStatsRequirement) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}

			if (ImGui::Button(ICON_FA_XMARK "  NO STATS REQUIREMENT", ImVec2(332, NULL)))
			{
				isNoStatsRequirement = !isNoStatsRequirement;
				noStatsRequirement(isNoStatsRequirement, magic_RvIntAddress, magic_DvIntAddress, weapons_RvStrAddress, weapons_DvStrAddress);
			}

			if (isFasterRespawn) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}

			if (ImGui::Button(ICON_FA_FORWARD_FAST "  FASTER RESPAWN", ImVec2(332, NULL)))
			{
				isFasterRespawn = !isFasterRespawn;
				fasterRespawn(isFasterRespawn, FasterRespawnAddr);
			}

			if (isNoRunes) {
				style->Colors[ImGuiCol_Button] = ImColor(0, 200, 0, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(0, 200, 0, 255);
			}
			else {
				style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255); style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			}

			if (ImGui::Button(ICON_FA_SACK_DOLLAR "  INFINITE RUNES", ImVec2(332, NULL)))
			{
				isNoRunes = !isNoRunes;
				noRunes(isNoRunes, runesAddr);
			}

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
				ImGui::InputInt("RUNES", runes);
			}

			style->Colors[ImGuiCol_Button] = ImColor(0, 70, 150);
			if (ImGui::Button("STATS CHANGER  " ICON_FA_ARROW_RIGHT, ImVec2(332, NULL)))
			{
				tab = 1;
			}

			style->Colors[ImGuiCol_ChildBg] = ImColor(25, 25, 25, 255);
			ImGui::BeginChild("##", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));

			ImGui::Combo("GAME SPEED", &playerSpeed_current, playerSpeed, 5);
			if (playerSpeed_old != playerSpeed_current)
			{

				if (changedSpeed)
				{
					PDETOUR_TRAMPOLINE lpTrampolineData = {};
					const auto lpGetValue = (LPVOID)((DWORD_PTR)playerSpeedAddr);

					DetourTransactionBegin();
					DetourUpdateThread(GetCurrentThread());
					DetourAttachEx((PVOID*)&lpGetValue, (PVOID)&speedAsm_func, &lpTrampolineData, nullptr, nullptr);
					DetourTransactionCommit();

					const auto lpDetourInfo = (DETOUR_INFO*)lpTrampolineData;
					speedBack = lpDetourInfo->pbRemain;
				}
				changedSpeed = false;

				playerSpeed_old = playerSpeed_current;
				if (playerSpeed_current == 0)
				{
					dwSpeed = 1;
				}
				else if (playerSpeed_current == 1)
				{
					dwSpeed = 2;
				}
				else if (playerSpeed_current == 2)
				{
					dwSpeed = 3;
				}
				else if (playerSpeed_current == 3)
				{
					dwSpeed = 5;
				}
				else if (playerSpeed_current == 4)
				{
					dwSpeed = 10;
				}
			}
			ImGui::EndChild();
		}
		if (tab == 1)
		{
			style->Colors[ImGuiCol_Button] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(60, 60, 60, 255);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(0, 180, 0, 255);
			style->ItemSpacing = ImVec2(NULL, 8);

			if (ImGui::Button(ICON_FA_ARROW_LEFT, ImVec2(332, NULL)))
			{
				tab = 0;
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
				ImGui::InputInt("LEVEL", level);
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
				ImGui::InputInt("VIGOR", vigor);

				int* mindAddr = vigor + 0x1;
				int* mind = (int*)mindAddr;
				ImGui::InputInt("MIND", mind);

				int* enduranceAddr = mind + 0x1;
				int* endurance = (int*)enduranceAddr;
				ImGui::InputInt("ENDURANCE", endurance);

				int* strengthAddr = endurance + 0x1;
				int* strength = (int*)strengthAddr;
				ImGui::InputInt("STRENGTH", strength);

				int* dexterityAddr = strength + 0x1;
				int* dexterity = (int*)dexterityAddr;
				ImGui::InputInt("DEXTERITY", dexterity);

				int* intelligenceAddr = dexterity + 0x1;
				int* intelligence = (int*)intelligenceAddr;
				ImGui::InputInt("INTELLIGENCE", intelligence);

				int* faithAddr = intelligence + 0x1;
				int* faith = (int*)faithAddr;
				ImGui::InputInt("FAITH", faith);

				int* arcaneAddr = faith + 0x1;
				int* arcane = (int*)arcaneAddr;
				ImGui::InputInt("ARCANE", arcane);
			}
		}

		if (showAbout)
		{
			ImGui::SetCursorPos(ImVec2(80, 160));
			style->Colors[ImGuiCol_ChildBg] = ImColor(36, 36, 36, 255);
			style->Colors[ImGuiCol_Border] = ImColor(244, 202, 33, 210);
			style->ChildBorderSize = 3.0f;
			ImGui::BeginChild("about", ImVec2(200, 70), true, ImGuiWindowFlags_NoCollapse);
			ImGui::SetCursorPos(ImVec2(155, 42));
			ImGui::Text("v0.1.0");
			ImGui::SetCursorPos(ImVec2(40, 23));
			ImGui::Text("Coded by ImAxel0");
			ImGui::EndChild();
			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		}

		ImGui::End();
		if (!isOpen)
		{
			ExitProcess(0);
		}
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

