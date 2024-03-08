#include "pch.h"
#include "PlayerStateJumpCommon.h"
#include "PlayerStateUtilJump.h"

namespace app
{
namespace Player
{
bool CSpectrumStateJumpCommon::FUN_80097790(CStateGOC& goc, bool param_2, bool param_3)
{
    const auto nextState = StateUtil::FUN_80091540(goc, 1);
    if (nextState == -1)
    {
        // TODO
        return false;
    }
    else
    {
        goc.ChangeState(nextState);
        return true;
    }
}
} // Player
} // app
