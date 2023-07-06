#pragma once
#include <Player/State/PlayerStateJump.h>

namespace app
{
namespace Player
{
class CStateBallJump : public CStateJumpCommon
{
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
