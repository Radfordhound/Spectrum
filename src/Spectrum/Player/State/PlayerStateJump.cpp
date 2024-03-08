#include "pch.h"
#include <Player/State/PlayerStateJump.h>
#include "Spectrum/Player/Base/PlayerState.h"
#include <Player/Posture/PlayerPostureAir.h>
#include <Player/State/PlayerStateUtil.h>
#include <Player/State/PlayerStateUtilSound.h>
#include <Player/State/PlayerStateUtilVisual.h> // TODO: REMOVE THIS
#include <Player/Base/PlayerPhysicalBehavior.h>

namespace app
{
namespace Player
{
class CStateJumpExt : public CStateJump
{
public:
    void DoJump(CStateGOC& goc);

    bool FUN_80097790(CStateGOC& goc, bool param_2, bool param_3);
};

void CStateJumpExt::DoJump(CStateGOC& goc)
{
    const auto physics = goc.GetPhysics();
    const auto val1 = goc.GetParameter(0xe);

    auto aVStack44 = physics->CalcUpDirectionByVelocity(physics->m_upDir);
    // TODO
    physics->UpdateGravity(aVStack44, true);
    const auto VStack56 = (aVStack44 * val1);
    physics->AddVelocity(VStack56);
    //this->field_0x24 = VStack56; // TODO
    // TODO
    StateUtil::ResetOnGround(goc);
    // TODO
}

bool CStateJumpExt::FUN_80097790(CStateGOC& goc, bool param_2, bool param_3)
{
    // TODO
    return false;
}

MEMBER_HOOK(LWAPI_ASLR(0x008ac7c0), CStateJumpExt,
    CStateJump_OnEnter_Hook, void,
    CStateGOC& goc, int param_2)
{
    // TODO
    goc.ChangePosture<CPostureAir>();
    goc.ChangeAnimation("JUMP_START", 0.2f);
    StateUtil::EnableHoming(goc, true);

    DoJump(goc);

    field_0x30 = 0.0f;
    GotoSeq(0);
    StateUtil::PlaySE(goc, "sn_jump");
}

MEMBER_HOOK(LWAPI_ASLR(0x008ac8f0), CStateJumpExt,
    CStateJump_OnLeave_Hook, void,
    CStateGOC& goc, int param_2)
{
    StateUtil::EnableHoming(goc, false);
}

MEMBER_HOOK(LWAPI_ASLR(0x008ac960), CStateJumpExt,
    CStateJump_Step_Hook, bool,
    CStateGOC& goc, float dt)
{
    const auto physics = goc.GetPhysics();
    field_0x30 += dt;

    switch (m_curSeq)
    {
    case 0:
        if (StateUtil::IsButtonUp(goc, game::INPUT_BUTTON_JUMP))
        {
            // TODO
            GotoSeq(1);
        }
        else if (goc.GetParameter(0xb) <= field_0x30)
        {
            // TODO

            goc.ChangeState(SPECTRUM_PLAYER_STATE_BALL_JUMP);
            return true;
        }

        // TODO
        return true;

    case 1:
    {
        const auto& velocity = physics->GetVelocity();
        const auto fVar8 = DirectX::XMVectorGetX(DirectX::XMVector3Dot(physics->m_upDir.Data, velocity.Data)); // TODO

        if (fVar8 < 80.0f)
        {
            goc.PushAnimation("JUMP_TOP");
            GotoSeq(2);
        }

        // TODO
        return true;
    }

    default:
        return false;
    }
}

static void CStateJump_InstallHooks()
{
    // Unprotect vtable1.
    const vtable_ptr vtable1(LWAPI_ASLR(0x00dfca94));
    vtable1.Unprotect(17);

    // Install vtable1 hooks.
    // TODO: Figure out why installing an OnEnter hook sometimes causes a crash at 0x887276 when boosting/jumping very quickly as super sonic
    // TODO: Figure out why colliding with a wall while the jump ball is shown causes the game to attempt to execute random memory that isn't code??
    vtable1.InstallHook<CStateJump_OnEnter_Hook>(7);
    vtable1.InstallHook<CStateJump_OnLeave_Hook>(8);
    vtable1.InstallHook<CStateJump_Step_Hook>(10);
}

LWAPI_DEFINE_PATCH(CStateJump_InstallHooks)
} // Player
} // app
