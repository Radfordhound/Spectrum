#include "pch.h"
#include "PlayerStateBallJump.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/State/PlayerStateUtil.h>
#include <Player/State/PlayerStateUtilSound.h>
#include <Player/State/PlayerStateUtilVisual.h>
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace app
{
namespace Player
{
void CSpectrumStateBallJump::OnEnter(CStateGOC& goc, int param_2)
{
    // TODO
    goc.ChangePosture<CPostureAir>();
    // TODO

    goc.ChangeAnimation("JUMP_BALL", 0.2f); // TODO: This is wrapped in an if statement!

    StateUtil::EnableHoming(goc, true);
    StateUtil::SetDrawJumpBall(goc, true);

    // TODO

    field_0x2c_spectrum = 0.0f;

    // TODO

    StateUtil::PlaySE(goc, "sn_spin");
    field_0x24_spectrum = 0.0f;
    field_0x28_spectrum = 1;
}

void CSpectrumStateBallJump::OnLeave(CStateGOC& goc, int param_2)
{
    // TODO
    StateUtil::EnableHoming(goc, false);
    StateUtil::SetDrawJumpBall(goc, false);
    // TODO
}

bool CSpectrumStateBallJump::Step(CStateGOC& goc, float dt)
{
    field_0x24_spectrum += dt;

    // TODO

    FUN_80098500(goc, dt);

    if (!CheckChangeState(goc, field_0x29_spectrum, false) &&
        StateUtil::IsButtonUp(goc, game::INPUT_BUTTON_JUMP))
    {
        const auto physics = goc.GetPhysics();
        const auto& velocity = physics->GetVelocity();

        const auto fVar10 = DirectX::XMVectorGetX(DirectX::XMVector3Dot(velocity.Data, physics->m_upDir.Data)); // TODO
        if (fVar10 < -100.0f || (fVar10 < 0.0f && 1.5f < field_0x28))
        {
            // TODO
            goc.ChangeState(PLAYER_STATE_FALL);
        }
    }

    return false;
}

void CSpectrumStateBallJump::FUN_80098500(CStateGOC& goc, float dt)
{
    if (field_0x28_spectrum != 0)
    {
        if (StateUtil::IsButtonUp(goc, game::INPUT_BUTTON_JUMP))
        {
            field_0x28_spectrum = 0;
        }
        else
        {
            if (field_0x24_spectrum <= SPECTRUM_PLAYER_PARAMETER_0E)
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

void CSpectrumStateBallJump::FUN_800985a8(CStateGOC& goc, float dt)
{
    const auto physics = goc.GetPhysics();
    auto aVStack48 = physics->CalcUpDirectionByVelocity(physics->m_upDir);
    auto VStack72 = ((aVStack48 * SPECTRUM_PLAYER_PARAMETER_JUMP_HOLD) * dt);
    physics->AddVelocity(VStack72);
}
} // Player
} // app
