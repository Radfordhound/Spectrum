#include "pch.h"
#include "PlayerPosture3DAir.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include "Spectrum/Utility/MathUtility.h"
#include <Player/Base/PlayerCollision.h>

namespace Sonic
{
namespace Player
{
const char* CPosture3DAir::GroupID = "CPosture3DAir";

const char* CPosture3DAir::GetGroupID()
{
    return GroupID;
}

void CPosture3DAir::Calculate(CPhysics& physics, float deltaTime)
{
    physics.ApplyExternalForceToMove(deltaTime, DEG_TO_RADF(0.0f));

    if (!IsOutOfControl())
    {
        UpdateInternalForce(physics, deltaTime);

        const auto velocity = physics.GetVelocity();
        const auto pos = physics.m_position;

        CalculateFor3DCommon(physics, deltaTime);

        m_spectrum_field_0x24 = CheckReversedVelocityByHitWall(
            physics, pos, velocity, physics.GetVelocity(), deltaTime);
    }
    else
    {
        CalculateFor3DCommon(physics, deltaTime);
        m_spectrum_field_0x24 = false;
    }
}

void CPosture3DAir::OnEnter(CPhysics& physics)
{
    SetInternalForceMode(physics, 0);
}

// TODO: Move this function to another file!
// Colors: 0x8004b0b4
csl::math::Vector3 FUN_8004b0b4(float param_1, float param_2, void* param_3,
    CPhysics& physics, const csl::math::Vector3& param_5, int param_6,
    int param_7, float param_8)
{
    // TODO
    return csl::math::Vector3(0.0f, 0.0f, 0.0f);
}

void CPosture3DAir::calcInternalForNormal(CPhysics& physics, float deltaTime)
{
    const auto VStack_44 = physics.m_inputForce;
    const auto blackBoard = GetBlackBoard();

    // TODO

    const float dVar4 = std::fmaxf(
        physics.GetHorzVelocityLength(),
        physics.GetMaxAirVelocity());

    auto VStack_50 = FUN_8004b0b4(deltaTime, dVar4, this, physics, VStack_44, 0, 0,
        GetParameter(Param::PARAM_0x41));
    // TODO
}

bool CPosture3DAir::FUN_80073980(CPhysics& physics)
{
    // TODO
    return false;
}

void CPosture3DAir::SetInternalForceMode(CPhysics& physics, int param_2)
{
    m_spectrum_field_0x10 = param_2;

    if (param_2 == 1)
    {
        m_spectrum_field_0x14 = physics.GetHorzVelocityDir();
        m_spectrum_field_0x20 = 0.0f;
    }
}

void CPosture3DAir::UpdateInternalForce(CPhysics& physics, float deltaTime)
{
    if (m_spectrum_field_0x10 == 0)
    {
        calcInternalForNormal(physics, deltaTime); // TODO

        if (true && // TODO
            0.1f < physics.GetHorzVelocityLength())
        {
            SetInternalForceMode(physics, 1);
        }
    }
    else if (m_spectrum_field_0x10 == 1 &&
        !FUN_80073980(physics))
    {
        SetInternalForceMode(physics, 0);
    }

    if (m_spectrum_field_0x24)
    {
        const auto collisionGOC = GetCollision();
        auto internalForce = physics.GetVelocity();

        for (unsigned int i = 0; i < collisionGOC->collision.GetSurfaceNum(); ++i)
        {
            const auto surfaceInfo = collisionGOC->collision.GetSurfaceInfo(i);

            if (csl::math::Vector3Dot(physics.upDir, surfaceInfo->field_0x0) <=
                std::cosf(DEG_TO_RADF(70.0f)))
            {
                const auto VStack96 = surfaceInfo->field_0x0;
                if (csl::math::Vector3Dot(internalForce, VStack96) < 0.0f)
                {
                    internalForce = (internalForce - (VStack96 *
                        csl::math::Vector3Dot(internalForce, VStack96)));

                    internalForce = (internalForce + (VStack96 * 0.1f));
                }
            }
        }

        physics.SetVelocity(internalForce);
    }
}

CPosture3DAir::CPosture3DAir() :
    m_spectrum_field_0x10(0),
    m_spectrum_field_0x14(0.0f, 0.0f, 0.0f),
    m_spectrum_field_0x20(0.0f),
    m_spectrum_field_0x24(false)
{
}

MEMBER_HOOK(LWAPI_ASLR(0x00868ea0), CPosture3DAir,
    CPosture3DAir___ct_Hook, CPosture3DAir*)
{
    return new (this) CPosture3DAir();
}

static void CPosture3DAir_InstallHooks()
{
    // Replace class size.
    const auto classSizePtr = reinterpret_cast<std::uint8_t*>(LWAPI_ASLR(0x0085a592));
    UnprotectMemory(*classSizePtr);

    *classSizePtr = sizeof(CPosture3DAir);

    // Install hooks.
    InstallHook<CPosture3DAir___ct_Hook>();
}

LWAPI_DEFINE_PATCH(CPosture3DAir_InstallHooks)
} // Player
} // Sonic
