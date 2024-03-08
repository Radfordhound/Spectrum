#include "pch.h"
#include "PlayerStatePhantomPuzzleStart.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace app
{
namespace Player
{
void CSpectrumStatePhantomPuzzleStart::OnEnter(CStateGOC& goc, int param_2)
{
    goc.ChangePosture<CPostureAir>();
    const auto physics = goc.GetPhysics();

    field_0x2c_spectrum = physics->m_position;
    field_0x28 = 0.0f;

    // TODO
    // TODO
}
} // Player
} // app
