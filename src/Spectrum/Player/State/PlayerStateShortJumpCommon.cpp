#include "pch.h"
#include "PlayerStateShortJumpCommon.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include <Player/Base/PlayerPhysicalBehavior.h>
#include <Player/State/PlayerStateUtil.h>

namespace app
{
namespace Player
{
void CSpectrumStateShortJumpCommon::DoJump(CStateGOC& goc)
{
    const auto physics = goc.GetPhysics();
    //const auto val1 = goc.GetParameter(0xe);
    const auto val1 = SPECTRUM_PLAYER_PARAMETER_JUMP_INITIAL;

    // TODO
    auto aVStack44 = physics->CalcUpDirectionByVelocity(physics->m_upDir);
    physics->UpdateGravity(aVStack44, true);
    const auto VStack56 = (aVStack44 * val1);
    physics->AddVelocity(VStack56);
    field_0x24_spectrum = VStack56;
    StateUtil::ResetOnGround(goc);
    // TODO
}
} // Player
} // app
