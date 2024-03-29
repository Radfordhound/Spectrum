#include "pch.h"
#include "PlayerStateJump.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/State/PlayerStateUtil.h>
#include <Player/State/PlayerStateUtilSound.h>
#include <Player/State/PlayerStateUtilVisual.h> // TODO: REMOVE THIS
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace app
{
namespace Player
{
void CSpectrumStateJump::OnEnter(CStateGOC& goc, int param_2)
{
    // TODO
    goc.ChangePosture<CPostureAir>();
    goc.ChangeAnimation("JUMP_START", 0.2f);
    StateUtil::EnableHoming(goc, true);

    DoJump(goc);

    m_ballJumpTimer = 0.0f;
    GotoSeq(0);
    StateUtil::PlaySE(goc, "sn_jump");
}

void CSpectrumStateJump::OnLeave(CStateGOC& goc, int param_2)
{
    StateUtil::EnableHoming(goc, false);
}

bool CSpectrumStateJump::Step(CStateGOC& goc, float dt)
{
    const auto physics = goc.GetPhysics();
    m_ballJumpTimer += dt;

    switch (m_curSeq)
    {
    case 0:
        if (StateUtil::IsButtonUp(goc, game::INPUT_BUTTON_JUMP))
        {
            FUN_80097a04(goc);
            GotoSeq(1);
        }
        else if (SPECTRUM_PLAYER_PARAMETER_JUMP_BALL_TIMER <= m_ballJumpTimer)
        {
            // TODO

            goc.ChangeState(SPECTRUM_PLAYER_STATE_BALL_JUMP);
            return true;
        }

        break;

    case 1:
    {
        const auto& velocity = physics->GetVelocity();

        if (csl::math::Vector3Dot(physics->upDir, velocity) < 80.0f)
        {
            goc.PushAnimation("JUMP_TOP");
            GotoSeq(2);
        }

        break;
    }

    default:
        break;
    }

    return CheckChangeState(goc, true, false);
}
} // Player
} // app
