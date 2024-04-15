#pragma once
#include "PlayerStateShortJumpCommon.h"

namespace Sonic
{
namespace Player
{
class CStateBallJump : public CStateJumpCommon
{
    float field_0x24_spectrum;
    unsigned char field_0x28_spectrum;
    bool field_0x29_spectrum;
    float field_0x2c_spectrum;

public:
    // Colors: 0x800981f4
    void OnEnter(CStateGOC& goc, int param_2);

    // Colors: 0x8009833c
    void OnLeave(CStateGOC& goc, int param_2);

    // Colors: 0x800983b8
    bool Step(CStateGOC& goc, float dt);

    // Colors: 0x80098500
    void FUN_80098500(CStateGOC& goc, float dt);

    // Colors: 0x800985a8
    void FUN_800985a8(CStateGOC& goc, float dt);
};
} // Player
} // Sonic
