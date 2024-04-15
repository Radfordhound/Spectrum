#include "pch.h"
#include "PlayerPosture.h"
#include <Player/Posture/PlayerPostureManager.h>
#include <Player/Base/Player.h>

namespace Sonic
{
namespace Player
{
const char* CBasePosture::GroupID = "CBasePosture";

const char* CBasePosture::GetGroupID()
{
    return GroupID;
}

void CBasePosture::OnEnter(CPhysics& physics)
{
}

void CBasePosture::OnLeave(CPhysics& physics)
{
}

bool CBasePosture::ProcessMessage(CPhysics& physics, app::fnd::Message& msg)
{
    return false;
}

void CBasePosture::SetupForChangeDimension(bool param_1, CPhysics& physics)
{
}

CBasePosture::CBasePosture()
    : m_postureManager(nullptr)
{
}

app::Player::CPlayer* CBasePosture::GetOwner()
{
    return m_postureManager->m_player;
}

const app::Player::CPlayer* CBasePosture::GetOwner() const
{
    return m_postureManager->m_player;
}

app::Player::CBlackBoard* CBasePosture::GetBlackBoard()
{
    return GetOwner()->m_blackBoard.get();
}

const app::Player::CBlackBoard* CBasePosture::GetBlackBoard() const
{
    return GetOwner()->m_blackBoard.get();
}

app::Player::CCollisionGOC* CBasePosture::GetCollision()
{
    return GetOwner()->GetPlayerGOC<app::Player::CCollisionGOC>();
}

const app::Player::CCollisionGOC* CBasePosture::GetCollision() const
{
    return GetOwner()->GetPlayerGOC<app::Player::CCollisionGOC>();
}

bool CBasePosture::Is2DMode() const
{
    // TODO: Implement CBlackBoard and replace this code !
    const auto is2DMode = (const bool*)(((std::uintptr_t)GetBlackBoard()) + 0x1C);
    return *is2DMode;
}

bool CBasePosture::IsOnGround() const
{
    return GetOwner()->m_physics->IsOnGround();
}

bool CBasePosture::IsOutOfControl() const
{
    // TODO: Implement CBlackBoard and replace this code !
    const auto flags3 = (const csl::ut::Bitset<unsigned int>*)(((std::uintptr_t)GetBlackBoard()) + 0x18);
    return flags3->test(0xE);
}

void* CBasePosture::GetPath(app::Player::PathType type) const
{
    // TODO
    return nullptr;
}

float CBasePosture::GetParameter(Param::Index paramIndex) const
{
    return TemporaryParameterGOCInstance.Get(paramIndex); // TODO
}
} // Player
} // Sonic
