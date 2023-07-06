#include "pch.h"
#include "PlayerPostureQuickStep.h"
#include <Player/Posture/PlayerPostureMoveManager.h>
#include <Player/Posture/PlayerPostureFactory.h>

namespace app
{
namespace Player
{
MEMBER_HOOK(LWAPI_ASLR(0x00859360), CPostureMoveManager,
    CPostureMoveManager_RegisterCommonPosture_Hook, void)
{
    // Call the original function.
    CallOriginal();
    
    // Register new postures.
    RegisterFactory(new (m_allocator) TPostureFactory<CPostureQuickStep>());
}

static void CPostureMoveManager_InstallHooks()
{
    InstallHook<CPostureMoveManager_RegisterCommonPosture_Hook>();
}

LWAPI_DEFINE_PATCH(CPostureMoveManager_InstallHooks)
} // Player
} // app
