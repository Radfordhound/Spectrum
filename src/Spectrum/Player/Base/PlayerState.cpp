#include "pch.h"
#include "PlayerState.h"
#include "Spectrum/Player/State/PlayerStateJump.h"
#include "Spectrum/Player/State/PlayerStateBallJump.h"
#include "Spectrum/Player/State/PlayerStatePhantomPuzzleStart.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h" // TODO
#include <Player/Base/PlayerState.h>
#include <Utility/StateManager.h>

namespace Sonic
{
namespace Player
{
float CStateGOC::GetParameter(unsigned int paramIndex) const
{
    return TemporaryParameterGOCInstance.Get(paramIndex); // TODO
}

CState* CStateGOC::GetState(const CState* goc, int stateID) const
{
    int curStateID = stateID;

    while (curStateID != PLAYER_STATE_NONE)
    {
        boost::intrusive_ptr<CState> state; // TODO

        if (stateID == curStateID)
        {
            return state.get();
        }

        // TODO
    }

    return nullptr;
}

void CState::Enter(CStateGOC& goc, int param_2)
{
    field_0x14.reset();
    m_curSeq = 0;
    m_nextSeq = -1;
    field_0x28 = 0.0f;
    OnEnter(goc, param_2);
}

void CState::Leave(CStateGOC& goc, int param_2)
{
    OnLeave(goc, param_2);
}

bool CState::Update(CStateGOC& goc, float dt)
{
    field_0x28 += dt;
    if (field_0x14.test(0))
    {
        m_alarmTimer -= dt;
        if (m_alarmTimer <= 0.0f)
        {
            field_0x14.reset(0);
            field_0x14.set(1);
        }
    }

    if (!field_0x14.test(2))
    {
        Transit(goc);

        if (m_nextSeq != -1)
        {
            m_curSeq = m_nextSeq;
            m_nextSeq = -1;
        }
    }
    else
    {
        m_sleepTimer -= dt;

        if (m_sleepTimer <= 0.0f)
        {
            field_0x14.reset(2);
        }
    }

    return Step(goc, dt);
}

void CState::GotoSeq(int nextSeq)
{
    m_nextSeq = nextSeq;
}

void CState::Sleep(float timeout, int nextSeq)
{
    field_0x14.set(2);
    m_sleepTimer = timeout;
    m_nextSeq = nextSeq;
}

void CState::SetAlarm(float param_1)
{
    m_alarmTimer = param_1;
    field_0x14.set(0);
    field_0x14.reset(1);
}

CState::CState()
    : m_curSeq(0)
    , m_nextSeq(-1)
    , field_0x28(0.0f)
    , m_alarmTimer(0.0f)
    , m_sleepTimer(0.0f)
{
}

// Auto-generate state descriptions for each new state.
static const app::ut::StateDesc<CStateGOC> NewStates[] =
{
#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName)\
    { #className, &app::ut::StateCreatorFuncTemplate<className>::Create },

#include "PlayerState.inl"
};

static constexpr int NewStateCount = static_cast<int>(sizeof(NewStates) / sizeof(*NewStates));

template<class NewStateType>
static void ReplaceStateCreateFunc(std::uintptr_t addr)
{
    using StateCreatorFunc = app::ut::StateDesc<CStateGOC>::StateCreatorFunc;

    auto& origStateCreator = *reinterpret_cast<StateCreatorFunc*>(addr);
    UnprotectMemory(origStateCreator);
    origStateCreator = &app::ut::StateCreatorFuncTemplate<NewStateType>::Create;
}

MEMBER_HOOK(LWAPI_ASLR(0x0085b620), CStateGOC,
    CStateGOC_RegisterCommonStates_Hook, void)
{
    // Replace some of the original Lost World player states.
    ReplaceStateCreateFunc<CStateJump>(LWAPI_ASLR(0x00fef6e4));

    // Call original function to register vanilla Lost World player states.
    CallOriginal();

    // Register new Spectrum player states.
    for (int i = 0; i < NewStateCount; ++i)
    {
        m_stateManager->RegisterState((SPECTRUM_LAST_VANILLA_STATE_ID + 1) + i,
            reinterpret_cast<const app::ut::StateDesc<app::Player::CStateGOC>*>(NewStates + i));
    }

    TemporaryParameterGOCInstance.SetupCommonParameter(); // TODO: Remove this temporary debug code
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
} // Sonic
