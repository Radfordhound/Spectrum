#include "pch.h"
#include "PlayerStateJumpCommon.h"
#include "PlayerStateUtilJump.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/State/PlayerStateUtil.h>

namespace Sonic
{
namespace Player
{
bool CStateJumpCommon::CheckChangeState(CStateGOC& goc, bool allowDoubleJump, bool param_3)
{
    const auto nextState = StateUtil::GetRequestStateForAir(goc, 1);
    if (nextState == -1)
    {
        if (!StateUtil::CheckChangeWallJump(goc))
        {
            if (!allowDoubleJump || !app::Player::StateUtil::IsEnableDoubleJump(goc, false))
            {
                return false;
            }
            else if (param_3)
            {
                goc.ChangeStateAlways(PLAYER_STATE_DOUBLE_JUMP);
            }
            else
            {
                goc.ChangeState(PLAYER_STATE_DOUBLE_JUMP);
            }
        }
    }
    else
    {
        goc.ChangeState(nextState);
    }

    return true;
}
} // Player
} // Sonic
