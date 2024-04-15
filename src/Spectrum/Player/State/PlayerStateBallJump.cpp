#include "pch.h"
#include "PlayerStateBallJump.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/State/PlayerStateUtil.h>
#include <Player/State/PlayerStateUtilSound.h>
#include <Player/State/PlayerStateUtilVisual.h>
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace Sonic
{
namespace Player
{
void CStateBallJump::OnEnter(CStateGOC& goc, int param_2)
{
    // TODO
    goc.ChangePosture<app::Player::CPostureAir>(); // TODO
    // TODO

    goc.ChangeAnimation("JUMP_BALL", 0.2f); // TODO: This is wrapped in an if statement!

    app::Player::StateUtil::EnableHoming(goc, true);
    app::Player::StateUtil::SetDrawJumpBall(goc, true);
    goc.ChangeBodyCollision(app::Player::BODY_COLLISION_TYPE_BALL);

    // TODO

    field_0x29_spectrum = true; // TODO!
    field_0x2c_spectrum = 0.0f;

    // TODO

    app::Player::StateUtil::PlaySE(goc, "sn_spin");
    field_0x24_spectrum = 0.0f;
    field_0x28_spectrum = 1;
}

void CStateBallJump::OnLeave(CStateGOC& goc, int param_2)
{
    // TODO
    app::Player::StateUtil::EnableHoming(goc, false);
    app::Player::StateUtil::SetDrawJumpBall(goc, false);
    // TODO
    goc.ChangeBodyCollision(app::Player::BODY_COLLISION_TYPE_NORMAL);
}

bool CStateBallJump::Step(CStateGOC& goc, float dt)
{
    field_0x24_spectrum += dt;

    // TODO

    FUN_80098500(goc, dt);

    if (!CheckChangeState(goc, field_0x29_spectrum, false) &&
        app::Player::StateUtil::IsButtonUp(goc, app::game::INPUT_BUTTON_JUMP))
    {
        const auto physics = goc.GetPhysics();
        const auto& velocity = physics->GetVelocity();

        const auto fVar10 = csl::math::Vector3Dot(velocity, physics->upDir);
        if (fVar10 < -100.0f || (fVar10 < 0.0f && 1.5f < field_0x28))
        {
            // TODO
            goc.ChangeState(PLAYER_STATE_FALL);
        }
    }

    return true;
}

void CStateBallJump::FUN_80098500(CStateGOC& goc, float dt)
{
    if (field_0x28_spectrum != 0)
    {
        if (app::Player::StateUtil::IsButtonUp(goc, app::game::INPUT_BUTTON_JUMP))
        {
            field_0x28_spectrum = 0;
        }
        else
        {
            if (field_0x24_spectrum <= goc.GetParameter(Param::PARAM_0xE))
            {
                FUN_800985a8(goc, dt);
            }
            else
            {
                field_0x28_spectrum = 0;
            }
        }
    }
}

void CStateBallJump::FUN_800985a8(CStateGOC& goc, float dt)
{
    const auto physics = goc.GetPhysics();
    auto aVStack48 = physics->CalcUpDirectionByVelocity(physics->upDir);
    auto VStack72 = ((aVStack48 * goc.GetParameter(Param::JUMP_HOLD)) * dt);
    physics->AddVelocity(VStack72);
}
} // Player
} // Sonic
