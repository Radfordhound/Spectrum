#pragma once
#include "PlayerStateShortJumpCommon.h"

namespace Sonic
{
namespace Player
{
class CStateJump : public CStateShortJumpCommon
{
    float m_ballJumpTimer;

public:
    // Colors: 0x80097b84
    void OnEnter(CStateGOC& goc, int param_2);

    // Colors: 0x80097c2c
    void OnLeave(CStateGOC& goc, int param_2);

    // Colors: 0x80097c38
    bool Step(CStateGOC& goc, float dt);
};
} // Player
} // Sonic
