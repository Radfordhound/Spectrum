#pragma once
#include <Player/State/PlayerStateJump.h>
#include <Utility/StateDesc.h>

namespace app
{
namespace Player
{
class CStateBallJump : public CStateJumpCommon
{
public:
    static const ut::StateDesc<CStateGOC> StateDesc;

    // Colors: TODO
    void OnEnter(CStateGOC& goc, int param_2);

    // Colors: TODO
    void OnLeave(CStateGOC& goc, int param_2);

    // Colors: 0x800983b8
    bool Step(CStateGOC& goc, float dt);
};
} // Player
} // app
