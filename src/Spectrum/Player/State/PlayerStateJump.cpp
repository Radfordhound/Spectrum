#include "pch.h"
#include "PlayerStateJump.h"
#include "PlayerStateUtil.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/State/PlayerStateUtil.h>
#include <Player/State/PlayerStateUtilSound.h>
#include <Player/State/PlayerStateUtilVisual.h> // TODO: REMOVE THIS
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace Sonic
{
namespace Player
{
void CStateJump::OnEnter(CStateGOC& goc, int param_2)
{
    StateUtil::RequestWaterGravityChange(goc);
    goc.ChangePosture<app::Player::CPostureAir>(); // TODO
    goc.ChangeAnimation("JUMP_START", 0.2f);
    app::Player::StateUtil::EnableHoming(goc, true);

    DoJump(goc);

    m_ballJumpTimer = 0.0f;
    GotoSeq(0);
    app::Player::StateUtil::PlaySE(goc, "sn_jump");
}

void CStateJump::OnLeave(CStateGOC& goc, int param_2)
{
    app::Player::StateUtil::EnableHoming(goc, false);
}

bool CStateJump::Step(CStateGOC& goc, float dt)
{
    const auto physics = goc.GetPhysics();
    m_ballJumpTimer += dt;

    switch (m_curSeq)
    {
    case 0:
        if (app::Player::StateUtil::IsButtonUp(goc, app::game::INPUT_BUTTON_JUMP))
        {
            FUN_80097a04(goc);
            GotoSeq(1);
        }
        else if (m_ballJumpTimer >= goc.GetParameter(Param::JUMP_BALL_TIMER))
        {
            // TODO

            goc.ChangeState(PLAYER_STATE_BALL_JUMP);
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
} // Sonic
