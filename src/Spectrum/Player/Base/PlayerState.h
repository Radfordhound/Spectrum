#pragma once
#include <Player/Base/PlayerState.h>

namespace Sonic
{
namespace Player
{
enum EStateType
{
    PLAYER_STATE_NONE = -1, // TODO: Replace with Colors ID
    PLAYER_STATE_STAND_ROOT = 0x1, // TODO: Replace with Colors ID
    PLAYER_STATE_RUN = 0x3, // TODO: Replace with Colors ID
    PLAYER_STATE_JUMP = 0x5, // TODO: Replace with Colors ID
    PLAYER_STATE_DOUBLE_JUMP = 0x7, // TODO: Replace with Colors ID
    PLAYER_STATE_FALL = 0x12, // TODO: Replace with Colors ID

    SPECTRUM_LAST_VANILLA_STATE_ID = 0x82,

#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName) enumTypeName,
#include "PlayerState.inl"

    SPECTRUM_TOTAL_PLAYER_STATE_COUNT
};

class CState;

class CStateGOC : public app::Player::CStateGOC
{
public:
    float GetParameter(unsigned int paramIndex) const;

    CState* GetState(const CState* goc, int stateID) const;
};

class CState : public app::ut::StateBase<CStateGOC>
{
OPENLW_PROTECTED
    csl::ut::Bitset<unsigned int> field_0x14;
    int m_curSeq;
    int m_nextSeq;
    float m_alarmTimer;
    float m_sleepTimer;
    float field_0x28;

public:
    void Enter(CStateGOC& goc, int param_2);

    void Leave(CStateGOC& goc, int param_2);

    bool Update(CStateGOC& goc, float dt);

    virtual void OnEnter(CStateGOC& goc, int param_2)
    {
    }

    virtual void OnLeave(CStateGOC& goc, int param_2)
    {
    }

    virtual bool Transit(CStateGOC& goc)
    {
        return false;
    }

    virtual bool Step(CStateGOC& goc, float dt)
    {
        return false;
    }

    void GotoSeq(int param_1);

    void Sleep(float timeout, int nextSeq);

    void SetAlarm(float param_1);

    CState();
};
} // Player
} // Sonic
