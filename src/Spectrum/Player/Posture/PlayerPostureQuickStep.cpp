#include "pch.h"
#include "PlayerPostureQuickStep.h"
#include <Message/Message.h>
#include <Player/Base/PlayerPhysicalBehavior.h> // TODO: Remove this
#include <Player/Base/Player.h> // TODO: Remove this
#include <Player/Base/PlayerState.h> // TODO: Remove this

namespace app
{
namespace Player
{
// TODO: Move this to another header
enum EColorsPlayerMessageID
{
    MESSAGE_PL_POSTURE_SET_PLUGIN_FORCE_PATH = 0x5088,
};

const char* CPostureQuickStep::GroupID = "CPostureQuickStep";

const char* CPostureQuickStep::GetGroupID()
{
    return GroupID;
}

void CPostureQuickStep::Calculate(CPhysics& param_1, float param_2)
{
    // TODO
}

void CPostureQuickStep::OnEnter(CPhysics& physics)
{
    field_0x40 = 0.0f;
    m_flags = 0;
}

void CPostureQuickStep::OnLeave(CPhysics& physics)
{
    // TODO
}

bool CPostureQuickStep::ProcessMessage(CPhysics& physics, fnd::Message& msg)
{
    switch (msg.id)
    {
    // TODO
    //case MESSAGE_PL_SET_POSTURE_NO_PATH_MOVE:

    case MESSAGE_PL_POSTURE_SET_PLUGIN_FORCE_PATH:
        m_flags |= 2;
        return true;

    default:
        return false;
    }
}

CPostureQuickStep::CPostureQuickStep() :
    field_0x10(csl::math::Vector3::Zero),
    field_0x1c(csl::math::Vector3::Zero),
    field_0x28(csl::math::Vector3::Zero),
    field_0x34(csl::math::Vector3::Zero),
    field_0x40(0.0f),
    field_0x44(0.0f),
    field_0x48(0.0f),
    m_flags(0) {}
} // Player
} // app
