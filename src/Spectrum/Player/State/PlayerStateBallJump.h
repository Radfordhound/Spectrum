#pragma once
#include "PlayerStateShortJumpCommon.h"

namespace app
{
namespace Player
{
class CSpectrumStateBallJump : public CSpectrumStateJumpCommon
{
    unsigned char field_0x28;
    unsigned char field_0x29;
    float field_0x2c;

public:
    // Colors: TODO
    void OnEnter(CStateGOC& goc, int param_2);

    // Colors: TODO
    void OnLeave(CStateGOC& goc, int param_2);

    // Colors: 0x800983b8
    bool Step(CStateGOC& goc, float dt);
};
} // Player
} // app
