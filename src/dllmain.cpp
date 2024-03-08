#include "pch.h"

// Called by LostCodeLoader at game initialization time.
extern "C" __declspec(dllexport) void Init(const char* path)
{
    // Apply all defined patches from all of Spectrum's source files.
    lwapi::ApplyPatches();
}

// Called by Windows at DLL initialization time.
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

