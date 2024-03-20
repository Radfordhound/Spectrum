#include "pch.h"
#include "PlayerStateUtilJump.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Base/PlayerState.h>
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace app
{
namespace Player
{
namespace StateUtil
{
int GetRequestStateForAir(CStateGOC& goc, int param_2)
{
    switch (param_2)
    {
    case 0:
        return FUN_8009157c(goc);

    case 1:
        return FUN_800916a4(goc);

    default:
        return PLAYER_STATE_NONE;
    }
}

int FUN_8009157c(CStateGOC& goc)
{
    if (!goc.IsOnGround())
    {
        return PLAYER_STATE_FALL;
    }

    if (goc.IsOutOfControl())
    {
        return PLAYER_STATE_NONE;
    }

    // TODO
    return PLAYER_STATE_NONE;
}

int FUN_800916a4(CStateGOC& goc)
{
    if (goc.IsOnGround())
    {
        if (false) // TODO
        {
            // TODO
            return -1;
        }
        else
        {
            const auto physics = goc.GetPhysics();
            if (physics->GetHorzVelocityLength() <= 10.0f)
            {
                return PLAYER_STATE_STAND_ROOT;
            }
            else
            {
                return PLAYER_STATE_RUN;
            }
        }
    }
    else
    {
        // TODO
        return -1;
    }
}

bool CheckChangeWallJump(CStateGOC& goc)
{
    // TODO
    return false;
}
} // StateUtil
} // Player
} // app
