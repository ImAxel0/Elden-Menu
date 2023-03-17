#pragma once 

#include <Windows.h>
#include <string>
#include <cstdarg>
#include <fileapi.h>
#include <Psapi.h>
#include <iostream>
#include <vector>
#include <xinput.h>
#include <sstream>
#include <map>
#include <chrono>
#include <TlHelp32.h>

#include "ini.h"

namespace ModUtils
{
	static std::string muModuleName = "";
	static HWND muWindow = NULL;
	static FILE* muLogFile = nullptr;
	static bool muLogOpened = false;
	static constexpr int MASKED = 0xffff;
	static constexpr unsigned char HK_NONE = 0x07;

	class Timer
	{
	public:
		Timer(unsigned int millis)
		{
			m_interval = millis;
		}

		bool Check()
		{
			auto now = std::chrono::system_clock::now();
			if (m_resetOnNextCheck)
			{
				m_lastExecutionTime = now;
				m_resetOnNextCheck = false;
				return false;
			}

			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastExecutionTime);
			if (diff.count() >= m_interval)
			{
				m_lastExecutionTime = now;
				return true;
			}

			return false;
		}

		void Reset()
		{
			m_resetOnNextCheck = true;
		}
	private:
		unsigned int m_interval = 0;
		bool m_resetOnNextCheck = true;
		std::chrono::system_clock::time_point m_lastExecutionTime;
	};

	// Gets the name of the .dll which the mod code is running in
	inline std::string GetModuleName(bool thisModule = true)
	{
		static char dummy = 'x';
		HMODULE module = NULL;

		if (thisModule)
		{
			GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, &dummy, &module);
		}

		char lpFilename[MAX_PATH];
		GetModuleFileNameA(module, lpFilename, sizeof(lpFilename));
		std::string moduleName = strrchr(lpFilename, '\\');
		moduleName = moduleName.substr(1, moduleName.length());

		if (thisModule)
		{
			moduleName.erase(moduleName.find(".dll"), moduleName.length());
		}

		return moduleName;
	}

	// Gets the path to the current mod relative to the game root folder
	inline std::string GetModuleFolderPath()
	{
		return std::string("mods\\" + GetModuleName(true));
	}

	// Logs both to std::out and to a log file simultaneously
	inline void Log(std::string msg, ...)
	{
		if (muModuleName == "")
		{
			muModuleName = GetModuleName(true);
		}

		if (muLogFile == nullptr && !muLogOpened)
		{
			CreateDirectoryA(std::string("mods\\" + muModuleName).c_str(), NULL);
			fopen_s(&muLogFile, std::string("mods\\" + muModuleName + "\\log.txt").c_str(), "w");
			muLogOpened = true;
		}

		va_list args;
		va_start(args, msg);
		vprintf(std::string(muModuleName + " > " + msg + "\n").c_str(), args);
		if (muLogFile != nullptr)
		{
			vfprintf(muLogFile, std::string(muModuleName + " > " + msg + "\n").c_str(), args);
			fflush(muLogFile);
		}
		va_end(args);
	}

	// The log should preferably be closed when code execution is finished.
	inline void CloseLog()
	{
		if (muLogFile != nullptr)
		{
			fclose(muLogFile);
			muLogFile = nullptr;
		}
	}

	// Shows a popup with a warningand logs that same warning.
	inline void RaiseError(std::string error)
	{
		if (muModuleName == "")
		{
			muModuleName = GetModuleName(true);
		}
		Log("Raised error: %s", error.c_str());
		//MessageBox(NULL, error.c_str(), muModuleName.c_str(), MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	}
	
	// Gets the base address of the game's memory.
	inline DWORD_PTR GetProcessBaseAddress(DWORD processId) // inline DWORD_PTR GetProcessBaseAddress(DWORD processId)
	{
		DWORD_PTR baseAddress = 0;
		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
		HMODULE* moduleArray = nullptr;
		LPBYTE moduleArrayBytes = 0;
		DWORD bytesRequired = 0;

		if (processHandle)
		{
			if (EnumProcessModules(processHandle, NULL, 0, &bytesRequired))
			{
				if (bytesRequired)
				{
					moduleArrayBytes = (LPBYTE)LocalAlloc(LPTR, bytesRequired);

					if (moduleArrayBytes)
					{
						unsigned int moduleCount;

						moduleCount = bytesRequired / sizeof(HMODULE);
						moduleArray = (HMODULE*)moduleArrayBytes;

						if (EnumProcessModules(processHandle, moduleArray, bytesRequired, &bytesRequired))
						{
							baseAddress = (DWORD_PTR)moduleArray[0];
						}

						LocalFree(moduleArrayBytes);
					}
				}
			}

			CloseHandle(processHandle);
		}

		return baseAddress;
	}

	// Scans the whole memory of the main process module for the given signature.
	inline uintptr_t SigScan(std::vector<uint16_t> pattern)
	{
		DWORD processId = GetCurrentProcessId();
		uintptr_t regionStart = GetProcessBaseAddress(processId);
		Log("Process name: %s", GetModuleName(false).c_str());
		Log("Process ID: %i", processId);
		Log("Process base address: 0x%llX", regionStart);

		std::string patternString = "";
		for (auto bytes : pattern)
		{
			std::stringstream stream;
			std::string byte = "";
			if (bytes == MASKED)
			{
				byte = "?";
			}
			else
			{
				stream << "0x" << std::hex << bytes;
				byte = stream.str();
			}
			patternString.append(byte + " ");
		}
		Log("Pattern: %s", patternString.c_str());

		size_t numRegionsChecked = 0;
		uintptr_t currentAddress = 0;
		while (numRegionsChecked < 10000)
		{
			MEMORY_BASIC_INFORMATION memoryInfo = { 0 };
			if (VirtualQuery((void*)regionStart, &memoryInfo, sizeof(MEMORY_BASIC_INFORMATION)) == 0)
			{
				DWORD error = GetLastError();
				if (error == ERROR_INVALID_PARAMETER)
				{
					Log("Reached end of scannable memory.");
				}
				else
				{
					Log("VirtualQuery failed, error code: %i.", error);
				}
				break;
			}
			regionStart = (uintptr_t)memoryInfo.BaseAddress;
			uintptr_t regionSize = (uintptr_t)memoryInfo.RegionSize;
			uintptr_t regionEnd = regionStart + regionSize;
			uintptr_t protection = (uintptr_t)memoryInfo.Protect;
			uintptr_t state = (uintptr_t)memoryInfo.State;

			bool readableMemory = (
				protection == PAGE_EXECUTE_READWRITE || 
				protection == PAGE_READWRITE || 
				protection == PAGE_READONLY || 
				protection == PAGE_WRITECOPY || 
				protection == PAGE_EXECUTE_WRITECOPY) 
				&& state == MEM_COMMIT;

			if (readableMemory)
			{
				Log("Checking region: %p", regionStart);
				currentAddress = regionStart;
				while (currentAddress < regionEnd - pattern.size())
				{
					for (size_t i = 0; i < pattern.size(); i++)
					{
						if (pattern[i] == MASKED)
						{
							currentAddress++;
							continue;
						} 
						else if (*(unsigned char*)currentAddress != (unsigned char)pattern[i])
						{
							currentAddress++;
							break;
						}
						else if (i == pattern.size() - 1)
						{
							uintptr_t signature = currentAddress - pattern.size() + 1;							
							Log("Found signature at %p", signature);
							return signature;
						}
						currentAddress++;
					}
				}
			}
			else
			{
				Log("Skipped region: %p", regionStart);
			}

			numRegionsChecked++;
			regionStart += memoryInfo.RegionSize;
		}

		Log("Stopped at: %p, num regions checked: %i", currentAddress, numRegionsChecked);
		RaiseError("Could not find signature!");
		return 0;
	}

	// Replaces the memory at a given address with newBytes. Performs memory comparison with originalBytes to stop unintended memory modification.
	inline bool Replace(uintptr_t address, std::vector<uint16_t> originalBytes, std::vector<uint8_t> newBytes)
	{
		std::vector<uint8_t> truncatedOriginalBytes;
		for (auto byte : originalBytes)
		{
			truncatedOriginalBytes.push_back((uint8_t)byte);
		}

		std::string bufferString = "";
		std::vector<uint8_t> buffer(originalBytes.size());
		memcpy(&buffer[0], (void*)address, buffer.size());
		for (size_t i = 0; i < buffer.size(); i++) 
		{
			std::stringstream stream;
			stream << "0x" << std::hex << (unsigned int)buffer[i];
			std::string byte = stream.str();
			bufferString.append(byte);
			if (originalBytes[i] == MASKED)
			{
				bufferString.append("?");
				buffer[i] = 0xff;
			}
			bufferString.append(" ");
		}
		Log("Bytes at address: %s", bufferString.c_str());

		std::string newBytesString = "";
		for (size_t i = 0; i < newBytes.size(); i++)
		{
			std::stringstream stream;
			stream << "0x" << std::hex << (unsigned int)newBytes[i];
			std::string byte = stream.str();
			newBytesString.append(byte + " ");
		}
		Log("New bytes: %s", newBytesString.c_str());

		if (memcmp(&buffer[0], &truncatedOriginalBytes[0], buffer.size()) == 0)
		{
			Log("Bytes match");
			memcpy((void*)address, &newBytes[0], newBytes.size());
			Log("Patch applied");
			return true;
		}
		else
		{
			RaiseError("Bytes do not match!");
		}
		return false;
	}

	// Winapi callback that receives all active window handles one by one.
	inline BOOL CALLBACK EnumWindowHandles(HWND hwnd, LPARAM lParam)
	{
		DWORD processId = NULL;
		GetWindowThreadProcessId(hwnd, &processId);
		if (processId == GetCurrentProcessId())
		{
			char buffer[100];
			GetWindowTextA(hwnd, buffer, 100);
			Log("Found window belonging to ER: %s", buffer);
			if (std::string(buffer).find("ELDEN RING") != std::string::npos)
			{
				Log("%s handle selected", buffer);
				muWindow = hwnd;
				return false;
			}
		}
		return true;
	}

	// Attempts different methods to get the main window handle.
	inline bool GetWindowHandle()
	{
		Log("Finding application window...");

		for (size_t i = 0; i < 10000; i++)
		{
			HWND hwnd = FindWindowExA(NULL, NULL, NULL, "ELDEN RING ");
			DWORD processId = 0;
			GetWindowThreadProcessId(hwnd, &processId);
			if (processId == GetCurrentProcessId())
			{
				muWindow = hwnd;
				Log("FindWindowExA: found window handle");
				break;
			}
			Sleep(1);
		}

		// Backup method
		if (muWindow == NULL)
		{
			Log("Enumerating windows...");
			for (size_t i = 0; i < 10000; i++)
			{
				EnumWindows(&EnumWindowHandles, NULL);
				if (muWindow != NULL)
				{
					break;
				}
				Sleep(1);
			}
		}

		return (muWindow == NULL) ? false : true;
	}

	// Checks if a hotkey or a combination of hotkeys is pressed.
	inline bool CheckHotkey(WORD key, WORD modifier = HK_NONE, bool checkController = false)
	{
		static std::vector<unsigned int> notReleasedKeys;
		static bool retrievedWindowHandle = false;

		if (!retrievedWindowHandle)
		{
			if (GetWindowHandle())
			{
				char buffer[100];
				GetWindowTextA(muWindow, buffer, 100);
				Log("Found application window: %s", buffer);
			}
			else
			{
				Log("Failed to get window handle, inputs will be detected globally");
			}
			retrievedWindowHandle = true;
		}

		if(muWindow != NULL && muWindow != GetForegroundWindow()) 
		{
			return false;
		}

		bool keyPressed = false;
		bool modifierPressed = false;

		if (checkController)
		{
			for (DWORD controllerIndex = 0; controllerIndex < XUSER_MAX_COUNT; controllerIndex++)
			{
				XINPUT_STATE state = { 0 };
				DWORD result = XInputGetState(controllerIndex, &state);
				if (result == ERROR_SUCCESS)
				{
					if (state.Gamepad.wButtons == key)
					{
						keyPressed = true;
					}
					else if (state.Gamepad.wButtons == modifier)
					{
						modifierPressed = true;
					}
					else if (state.Gamepad.wButtons == (key | modifier))
					{
						keyPressed = true;
						modifierPressed = true;
					}
				}
			}
		}
		else
		{
			keyPressed = GetAsyncKeyState(key) & 0x8000;
			modifierPressed = GetAsyncKeyState(modifier) & 0x8000;
		}

		if (key == HK_NONE)
		{
			return modifierPressed;
		}

		auto iterator = std::find(notReleasedKeys.begin(), notReleasedKeys.end(), key);
		bool keyNotReleased = iterator != notReleasedKeys.end();

		if (keyPressed && keyNotReleased)
		{
			return false;
		}

		if (!keyPressed)
		{
			if (keyNotReleased)
			{
				notReleasedKeys.erase(iterator);
			}
			return false;
		}

		if (modifier != HK_NONE && !modifierPressed)
		{
			return false;
		}

		Log("Key: %i, modifier: %i", keyPressed, modifierPressed);
		notReleasedKeys.push_back(key);
		return true;
	}

	// Disables or enables the memory protection in a given region. Remembers and restores the original memory protection type of the given addresses.
	inline void ToggleMemoryProtection(bool protectionEnabled, uintptr_t address, size_t size)
	{
		static std::map<uintptr_t, DWORD> protectionHistory;
		if (protectionEnabled && protectionHistory.find(address) != protectionHistory.end())
		{
			VirtualProtect((void*)address, size, protectionHistory[address], &protectionHistory[address]);
			protectionHistory.erase(address);
		}
		else if(!protectionEnabled && protectionHistory.find(address) == protectionHistory.end())
		{
			DWORD oldProtection = 0;
			VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, &oldProtection);
			protectionHistory[address] = oldProtection;
		}
	}

	// Copies memory after changing the permissions at both the source and destination so we don't get an access violation.
	inline void MemCopy(uintptr_t destination, uintptr_t source, size_t numBytes)
	{
		ToggleMemoryProtection(false, destination, numBytes);
		ToggleMemoryProtection(false, source, numBytes);
		memcpy((void*)destination, (void*)source, numBytes);
		ToggleMemoryProtection(true, source, numBytes);
		ToggleMemoryProtection(true, destination, numBytes);
	}

	// Simple wrapper around memset
	inline void MemSet(uintptr_t address, unsigned char byte, size_t numBytes)
	{
		ToggleMemoryProtection(false, address, numBytes);
		memset((void*)address, byte, numBytes);
		ToggleMemoryProtection(true, address, numBytes);
	}

	// Takes a 4-byte relative address and converts it to an absolute 8-byte address.
	inline uintptr_t RelativeToAbsoluteAddress(uintptr_t relativeAddressLocation)
	{
		uintptr_t absoluteAddress = 0;
		intptr_t relativeAddress = 0;
		MemCopy((uintptr_t)&relativeAddress, relativeAddressLocation, 4);
		absoluteAddress = relativeAddressLocation + 4 + relativeAddress;
		return absoluteAddress;
	}

	// Places a 14-byte absolutely addressed jump from A to B. Add extra clearance when the jump doesn't fit cleanly.
	inline void Hook(uintptr_t address, uintptr_t destination, size_t extraClearance = 0)
	{
		size_t clearance = 14 + extraClearance;
		MemSet(address, 0x90, clearance);
		*(uintptr_t*)address = 0x0000000025ff;
		MemCopy((address + 6), (uintptr_t)&destination, 8);
		Log("Created jump from %p to %p with a clearance of %i", address, destination, clearance);
	}
}