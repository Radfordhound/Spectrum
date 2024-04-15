#include "pch.h"
#include "PlayerPostureCommon.h"
#include "Spectrum/Utility/MathUtility.h"

namespace Sonic
{
namespace Player
{
static const csl::math::Vector3 AXIS_UP = csl::math::Vector3(0.0f, 1.0f, 0.0f); // TODO: Move to another header

float CPostureCommon::MaxSlopeForUpdateMove(CPhysics& physics, bool isGrounded)
{
    if (!isGrounded)
    {
        const auto blackBoard = GetBlackBoard();
        return DEG_TO_RADF(60.0f); // TODO
    }
    else
    {
        return DEG_TO_RADF(
            (physics.IsLandEnableGroundToGravityWorldUp(physics.upDir)) ?
            60.0f : 90.0f
        );
    }
}

csl::math::Vector3 CPostureCommon::FUN_80047410(
    CPhysics& physics, const csl::math::Vector3& velocity)
{
    if (IsOnGround())
    {
        // TODO
        auto VStack_454 = physics.m_position;
        auto VStack_4a8 = (AXIS_UP * 10.0f);
        auto VStack_460 = physics.m_position + VStack_4a8;

        // TODO
    }

    return velocity;
}

void CPostureCommon::UpdateMoveSimplify(CPhysics& physics,
    float deltaTime, const csl::math::Vector3& velocity)
{
    const auto blackBoard = GetBlackBoard();

    if (false) // TODO: IgnoreCollision ?
    {
        physics.SetPosition(physics.m_position + (velocity * deltaTime));
        return;
    }

    // TODO

    const auto VStack_200 = physics.m_position;
    auto VStack_20c = physics.GetVelocity();
    const auto VStack_218 = physics.upDir;
    const auto QStack_228 = physics.m_rotation;
    const auto VStack_238 = VStack_200;
    auto VStack_244 = velocity;
    const auto VStack_250 = VStack_218;

    const auto collisionGOC = GetCollision();

    if (true) // TODO
    {
        VStack_244 = VStack_20c = FUN_80047410(physics, VStack_244);
    }

    auto VStack_25c = csl::math::Vector3::Zero;
    const auto VStack_268 = (true) ? // TODO
        csl::math::Vector3::Zero :
        csl::math::Vector3::Zero; // TODO: bro

    collisionGOC->collision.SetMaxSlope(
        MaxSlopeForUpdateMove(physics, IsOnGround()));

    // TODO
}

void CPostureCommon::UpdateDistanceToGround(CPhysics& physics)
{
    // TODO
}

void CPostureCommon::Calculate(CPhysics& physics, float deltaTime)
{
    if (Is2DMode() && GetPath(app::Player::PATH_TYPE_SV))
    {
        // TODO
    }
    else
    {
        CalculateFor3DCommon(physics, deltaTime);
    }
}

void CPostureCommon::CalculateFor3DCommon(CPhysics& physics, float deltaTime)
{
    UpdateMoveSimplify(physics, deltaTime, physics.GetVelocity());
    UpdateDistanceToGround(physics);
    // TODO
}

bool CPostureCommon::CheckReversedVelocityByHitWall(CPhysics& physics,
    const csl::math::Vector3& param_2, const csl::math::Vector3& param_3,
    const csl::math::Vector3& param_4, float deltaTime)
{
    // TODO
    return false;
}
} // Player
} // Sonic
