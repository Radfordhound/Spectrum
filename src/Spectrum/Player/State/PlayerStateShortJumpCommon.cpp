#include "pch.h"
#include "PlayerStateShortJumpCommon.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include <Player/Base/PlayerPhysicalBehavior.h>
#include <Player/State/PlayerStateUtil.h>

using namespace csl::math;

namespace Sonic
{
namespace Player
{
bool CStateShortJumpCommon::FUN_80097a04(CStateGOC& goc)
{
    const auto physics = goc.GetPhysics();
    Vector3 aVStack_30;

    if (field_0x24_spectrum.LengthSq() <= 0.000001f)
    {
        aVStack_30 = field_0x24_spectrum;
    }
    else
    {
        Vector3Normalize(field_0x24_spectrum, &aVStack_30);
    }

    const auto dVar4 = Vector3Dot(physics->GetVelocity(), aVStack_30);

    if (dVar4 <= 0.0f)
    {
        return false;
    }

    const float dVar5 = std::fmaxf(
        goc.GetParameter(Param::PARAM_0x11),
        0.3f * dVar4
    );

    physics->AddVelocity(aVStack_30 * (dVar5 - dVar4));
    return true;
}

void CStateShortJumpCommon::DoJump(CStateGOC& goc)
{
    const auto physics = goc.GetPhysics();

    physics->upDir = physics->groundInfo.groundNormal;

    auto aVStack44 = physics->CalcUpDirectionByVelocity(physics->upDir);
    physics->UpdateGravity(aVStack44, true);

    const auto VStack56 = (aVStack44 * goc.GetParameter(Param::JUMP_INITIAL));
    physics->AddVelocity(VStack56);

    field_0x24_spectrum = VStack56;
    app::Player::StateUtil::ResetOnGround(goc);

    // TODO
}
} // Player
} // Sonic
