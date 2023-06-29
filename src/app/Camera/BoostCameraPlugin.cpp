#include "pch.h"
#include "BoostCameraPlugin.h"
#include "app/MathUtility.h"
#include <Camera/Camera.h>
#include <System/UpdateInfo.h>
#include <csl/math/algorithm.h>
#include <csl/math/quaternion.h>
#include <sonicusa/system/Random.h>

using namespace app::fnd;
using namespace app::Object;
using namespace csl::math;
using namespace SonicUSA::System;

namespace app
{
namespace Camera
{
CBoostCameraPlugin::~CBoostCameraPlugin()
{
    ShutdownFSM();
}

CBoostCameraPlugin::CBoostCameraPlugin(CCamera* camera) :
    TTinyFsm<CBoostCameraPlugin, Event<CBoostCameraPlugin>>(&CBoostCameraPlugin::StateNoBoost),
    field_0x20(),
    field_0x30(0.0f),
    field_0x34(0.0f),
    field_0x38(0.0f),
    m_flags(),
    field_0x40(0.0f),
    field_0x44(0.0f),
    m_camera(camera)
{
    m_flags.reset();
}
    
void CBoostCameraPlugin::AddPlugin()
{
    InitFSM();

    field_0x20 = Vector3::Zero;

    const auto r = Random::Instance.genrand_int32();
    field_0x30 = (((r - 176.0f) * 0.1171875f) * 0.1f);

    field_0x34 = 0.0f;
    field_0x38 = 0.0f;
}

void CBoostCameraPlugin::Update(const SUpdateInfo& updateInfo)
{
    DispatchFSM(EventType::CreateUpdate(updateInfo.DeltaTime));
}

void CBoostCameraPlugin::BeginBoost()
{
    field_0x34 = 0;
    m_flags.set(0);
}

void CBoostCameraPlugin::EndBoost()
{
    m_flags.reset(0);
}

static Vector3 MTXMultVecSR(Matrix34& mtx, Vector3& src)
{
    return Vector3(
        src.GetX() * mtx.GetValue(0, 0) + src.GetY() * mtx.GetValue(0, 1) + src.GetZ() * mtx.GetValue(0, 2),
        src.GetX() * mtx.GetValue(1, 0) + src.GetY() * mtx.GetValue(1, 1) + src.GetZ() * mtx.GetValue(1, 2),
        src.GetX() * mtx.GetValue(2, 0) + src.GetY() * mtx.GetValue(2, 1) + src.GetZ() * mtx.GetValue(2, 2)
    );
}

void CBoostCameraPlugin::UpdateCameraShake(float param_1, float dt)
{
    field_0x30 -= dt;
    if (field_0x30 < 0.0f)
    {
        const auto rand1 = Random::Instance.genrand_int32(); // TODO: Seems unused?

        // TODO: Is this static_cast correct?
        // It Seems to round via combining rand1 with 0x43300000?
        const float dVar10 = (30.0f * 2.0f * (
            0.1171875f * (static_cast<float>(std::rint(rand1)) - 176.0f) - 0.5f));

        const auto rand2 = Random::Instance.genrand_int32();

        // TODO: Is this static_cast correct?
        // It Seems to round via combining rand2 with 0x43300000?
        const float dVar9 = (30.0f * 2.0f * (
            0.1171875f * (static_cast<float>(std::rint(rand2)) - 176.0f) - 0.5f));

        Vector3 VStack176(0.0f, 0.0f, 1.0f);
        Quaternion QStack160(VStack176, dVar9);
        Matrix34 MStack144(QStack160);
        Vector3 local_c8(0.0f, dVar10 * param_1, 0.0f);

        const auto VStack188 = MTXMultVecSR(MStack144, local_c8);
        field_0x20 = VStack188;

        const auto rand3 = Random::Instance.genrand_int32();
        field_0x30 = (0.5f * 0.1f * 2.0f * (
            0.1171875f * (static_cast<float>(std::rint(rand3)) - 176.0f) - 0.5f) +
            0.1f);
    }
    else
    {
        CMathUtility::ChangeValueGradually(field_0x20, Vector3::Zero, 1.0f, dt);
    }
}

void CBoostCameraPlugin::SetBoostCameraParam()
{
    m_camera->SetOffsetFovy((m_flags.test(2)) ? 0.0f : field_0x34);
    m_camera->AddCameraParam(field_0x20, field_0x20, 1.0f);
}

bool CBoostCameraPlugin::CheckBoost()
{
    return (m_flags.test(0) && !m_flags.test(1));
}

void CBoostCameraPlugin::ChangeState(EventFunc state)
{
    FSM_TRAN(state);
}

CBoostCameraPlugin::StateType CBoostCameraPlugin::StateNoBoost(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        CMathUtility::ChangeValueD1Gradually(field_0x38,
            field_0x34, 0.0f, 15.0f, 45.0f, 30.0f,
            e.getDeltaTime());

        field_0x34 += (field_0x38 * e.getDeltaTime());
        SetBoostCameraParam();

        if (CheckBoost())
        {
            ChangeState(&CBoostCameraPlugin::StateBoostBegin);
        }

        return nullptr;

    case SIGNAL_ENTER:
        field_0x20 = Vector3::Zero;
        return nullptr;
    }

    return FSM_TOP();
}

CBoostCameraPlugin::StateType CBoostCameraPlugin::StateBoostBegin(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        field_0x44 += e.getDeltaTime();
        CMathUtility::ChangeValueD1Gradually(field_0x38,
            field_0x34, 30.0f, 30.0f, 120.0f, 45.0f,
            e.getDeltaTime());

        field_0x34 += (field_0x38 * e.getDeltaTime());
        UpdateCameraShake(Min(1.0f, field_0x44 + field_0x44), e.getDeltaTime());
        SetBoostCameraParam();

        if (!CheckBoost())
        {
            ChangeState(&CBoostCameraPlugin::StateBoostEnd);
        }
        else
        {
            if (0.5f < field_0x44)
            {
                ChangeState(&CBoostCameraPlugin::StateBoosting);
            }
        }

        return nullptr;

    case SIGNAL_ENTER:
        field_0x38 = 120.0f;
        field_0x44 = 0.0f;
        return nullptr;
    }

    return FSM_TOP();
}

CBoostCameraPlugin::StateType CBoostCameraPlugin::StateBoosting(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        CMathUtility::ChangeValueD1Gradually(field_0x38,
            field_0x34, 15.0f, 15.0f, 45.0f, 30.0f,
            e.getDeltaTime());

        field_0x34 += (field_0x38 * e.getDeltaTime());
        UpdateCameraShake(1.0f, e.getDeltaTime());
        SetBoostCameraParam();

        if (!CheckBoost())
        {
            ChangeState(&CBoostCameraPlugin::StateBoostEnd);
        }

        return nullptr;

    case SIGNAL_ENTER:
        return nullptr;

    case SIGNAL_LEAVE:
        field_0x20 = Vector3::Zero;
        return nullptr;
    }

    return FSM_TOP();
}

CBoostCameraPlugin::StateType CBoostCameraPlugin::StateBoostEnd(const EventType& e)
{
    switch (e.getSignal())
    {
    case SIGNAL_UPDATE:
        field_0x44 += e.getDeltaTime();
        CMathUtility::ChangeValueGradually(field_0x34,
            0.0f, field_0x40, e.getDeltaTime());

        UpdateCameraShake(Max(0.0f, (1.0f - (field_0x44 / 0.5f))), e.getDeltaTime());
        SetBoostCameraParam();

        if (CheckBoost())
        {
            ChangeState(&CBoostCameraPlugin::StateBoostBegin);
        }
        else if (0.5f < field_0x44)
        {
            ChangeState(&CBoostCameraPlugin::StateNoBoost);
        }

        return nullptr;

    case SIGNAL_ENTER:
        field_0x44 = 0.0f;
        field_0x40 = std::abs(-field_0x34 / 0.5f);
        return nullptr;
    }

    return FSM_TOP();
}
} // Camera
} // app
