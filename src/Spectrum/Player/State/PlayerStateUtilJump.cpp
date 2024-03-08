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
int FUN_80091540(CStateGOC& goc, int param_2)
{
    switch (param_2)
    {
    case 0:
        return FUN_8009157c(goc);

    case 1:
        return FUN_800916a4(goc);

    default:
        return -1;
    }
}

int FUN_8009157c(CStateGOC& goc)
{
    if (goc.IsOnGround())
    {
        // TODO
        return -1;
    }
    else
    {
        return PLAYER_STATE_FALL;
    }
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
} // StateUtil
} // Player
} // app
