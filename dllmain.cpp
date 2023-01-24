// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "entitylist.h"

DWORD WINAPI main_thread(LPVOID)
{
	using AddListenerEntity_t = void(__thiscall*)(void* thisptr, void* entitylist);
	const auto AddListenerEntity = reinterpret_cast<AddListenerEntity_t>(find_pattern(L"client", "55 8B EC 8B 91 ? ? ? ? 33 C0 56 57 8D B9 ? ? ? ? 85 D2 7E ? 8B 0F 8B 75 ? 8D 64 24 ? 39 31 74 ? 40 83 C1 ? 3B C2 7C ? 8D 45 ? 8B CF 50 E8 ? ? ? ? 5F 5E 5D C2 ? ? 85 C0"));
	AddListenerEntity(**reinterpret_cast<std::byte***>(find_pattern(L"client", "A1 ? ? ? ? 66 8B 80") + 1), &entitylist);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE, const DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		if (const HANDLE thread = CreateThread(nullptr, 0, main_thread, nullptr, 0, nullptr))
		{
			CloseHandle(thread);
		}
	}

	return TRUE;
}

