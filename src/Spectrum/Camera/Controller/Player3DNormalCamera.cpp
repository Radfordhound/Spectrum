#include "pch.h"
#include "Spectrum/Camera/BoostCameraPlugin.h"
#include <Camera/Controller/Player3DNormalCamera.h>

namespace app
{
namespace Camera
{
MEMBER_HOOK(LWAPI_ASLR(0x004333F0), CPlayer3DNormalCamera,
    CPlayer3DNormalCamera_OnEnter_Hook, void,
    EnterEventArgs& name)
{
    // Add boost camera plugin to camera.
    if (m_boostCameraPlugin)
    {
        m_boostCameraPlugin->AddPlugin();
    }

    // Call the original function.
    CallOriginal(name);
}

//static constexpr auto CBoostCameraPlugin_BeginBoost_Ptr = &CBoostCameraPlugin::BeginBoost;
static const std::uintptr_t CPlayer3DNormalCamera_OnEnter_MidHook_RetAddress = LWAPI_ASLR(0x004334b1);

__declspec(naked) static void CPlayer3DNormalCamera_OnEnter_MidHook()
{
    __asm
    {
        cmp DWORD PTR [esi + 0xEC], 0
        je set_is_boosting

        mov ecx, DWORD PTR [esi + 0xEC]
        call CBoostCameraPlugin::BeginBoost

    set_is_boosting:
        //mov byte ptr [esi + 0xf0], 0x1 // TODO: WHY IN THE WORLD DOES THIS LINE SEEMINGLY GENERATE AN ILLEGAL INSTRUCTION EXCEPTION?!
        jmp DWORD PTR [CPlayer3DNormalCamera_OnEnter_MidHook_RetAddress]
    }
}

static void CPlayer3DNormalCamera_InstallHooks()
{
    // Write mid-function jumps.
    WriteJump(&CPlayer3DNormalCamera_OnEnter_MidHook,
        reinterpret_cast<void*>(LWAPI_ASLR(0x004334aa)));

    // Unprotect vtable.
    const vtable_ptr vtable(LWAPI_ASLR(0x00d5a694));
    vtable.Unprotect(16);

    // Install vtable hooks.
    vtable.InstallHook<CPlayer3DNormalCamera_OnEnter_Hook>(4);
}

LWAPI_DEFINE_PATCH(CPlayer3DNormalCamera_InstallHooks)
} // Camera
} // app
