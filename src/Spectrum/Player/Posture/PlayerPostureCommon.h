#pragma once
#include "Spectrum/Player/Base/PlayerPosture.h"

namespace Sonic
{
namespace Player
{
class CPostureCommon : public CBasePosture
{
public:
    // Colors: 0x8004739c
    float MaxSlopeForUpdateMove(CPhysics& physics, bool isGrounded);

    // Colors: 0x80047410
    csl::math::Vector3 FUN_80047410(CPhysics& physics, const csl::math::Vector3& velocity);

    // Colors: 0x80047984
    void UpdateMoveSimplify(CPhysics& physics, float deltaTime, const csl::math::Vector3& velocity);

    // Colors: 0x80048f38
    void UpdateDistanceToGround(CPhysics& physics);

    // Colors: 0x8004ba68
    void Calculate(CPhysics& physics, float deltaTime);

    // Colors: 0x8004bae8
    void CalculateFor3DCommon(CPhysics& physics, float deltaTime);

    bool CheckReversedVelocityByHitWall(CPhysics& physics, const csl::math::Vector3& param_2,
        const csl::math::Vector3& param_3, const csl::math::Vector3& param_4, float deltaTime);
};
} // Player
} // Sonic
