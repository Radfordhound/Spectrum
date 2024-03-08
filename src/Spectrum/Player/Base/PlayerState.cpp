#include "pch.h"
#include "PlayerState.h"
#include "Spectrum/Player/State/PlayerStateBallJump.h"
#include <Player/Base/PlayerState.h>
#include <Utility/StateManager.h>

namespace app
{
namespace Player
{
// Auto-generate state descriptions for each new state.
static const ut::StateDesc<CStateGOC> NewStates[] =
{
#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName)\
    { #className, &ut::StateCreatorFuncTemplate<className>::Create },

#include "PlayerState.inl"
};

static constexpr int NewStateCount = static_cast<int>(sizeof(NewStates) / sizeof(*NewStates));

MEMBER_HOOK(LWAPI_ASLR(0x0085b620), CStateGOC,
    CStateGOC_RegisterCommonStates_Hook, void)
{
    // Call original function to register Lost World player states.
    CallOriginal();

    // Register new Spectrum player states.
    for (int i = 0; i < NewStateCount; ++i)
    {
        m_stateManager->RegisterState((SPECTRUM_LAST_VANILLA_STATE_ID + 1) + i, NewStates + i);
    }
}

static void CStateGOC_InstallHooks()
{
    // Overwrite max state size, so the game allocates enough memory for our extra states.
    auto& maxStateCount = *reinterpret_cast<unsigned char*>(LWAPI_ASLR(0x0085c339));
    UnprotectMemory(maxStateCount);
    maxStateCount = SPECTRUM_TOTAL_PLAYER_STATE_COUNT;

    // Install hooks.
    InstallHook<CStateGOC_RegisterCommonStates_Hook>();
}

LWAPI_DEFINE_PATCH(CStateGOC_InstallHooks)
} // Player
} // app
