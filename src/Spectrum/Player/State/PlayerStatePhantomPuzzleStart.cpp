#include "pch.h"
#include "PlayerStatePhantomPuzzleStart.h"
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace Sonic
{
namespace Player
{
void CStatePhantomPuzzleStart::OnEnter(CStateGOC& goc, int param_2)
{
    goc.ChangePosture<app::Player::CPostureAir>(); // TODO
    const auto physics = goc.GetPhysics();

    field_0x2c_spectrum = physics->m_position;
    field_0x28 = 0.0f;

    // TODO
}
} // Player
} // Sonic
