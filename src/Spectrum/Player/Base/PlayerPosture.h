#pragma once
#include "Spectrum/Player/Base/PlayerPhysicalBehavior.h"
#include "Spectrum/Player/Parameter/PlayerParameter.h"
#include <Player/Base/PlayerPosture.h>

namespace Sonic
{
namespace Player
{
class CBasePosture : public app::fnd::ReferencedObject
{
OPENLW_PROTECTED
    app::Player::CPostureManager* m_postureManager;

public:
    static const char* GroupID;

    virtual const char* GetGroupID();

    virtual void Calculate(CPhysics& physics, float dt) = 0;

    virtual void OnEnter(CPhysics& physics);

    virtual void OnLeave(CPhysics& physics);

    virtual bool ProcessMessage(CPhysics& physics, app::fnd::Message& msg);

    virtual void SetupForChangeDimension(bool param_1, CPhysics& physics);

    CBasePosture();

    app::Player::CPlayer* GetOwner();

    const app::Player::CPlayer* GetOwner() const;

    app::Player::CBlackBoard* GetBlackBoard();

    const app::Player::CBlackBoard* GetBlackBoard() const;

    app::Player::CCollisionGOC* GetCollision();

    const app::Player::CCollisionGOC* GetCollision() const;

    bool Is2DMode() const;

    bool IsOnGround() const;

    bool IsOutOfControl() const;

    void* GetPath(app::Player::PathType type) const;

    float GetParameter(Param::Index paramIndex) const;
};
} // Player
} // Sonic
