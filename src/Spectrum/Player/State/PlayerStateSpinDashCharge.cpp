#include "pch.h"
#include <Message/MessageCamera.h>
#include <Player/Base/PlayerState.h>

namespace app
{
namespace Player
{
//class CPostureSpinDash // TODO: Inheritance
//{
//    // TODO: Data Members
//
//public:
//    inline static FUNCTION_PTR(void, __thiscall, ms_fpSetFirstVelocity, ASLR(0x00886f30), CPostureSpinDash*, CPhysics&, float);
//    inline static FUNCTION_PTR(void, __thiscall, ms_fpSetKeepMaxSpeed, ASLR(0x008869e0), CPostureSpinDash*, bool);
//
//    void SetFirstVelocity(CPhysics& phy, float firstVelocity)
//    {
//        return ms_fpSetFirstVelocity(this, phy, firstVelocity);
//    }
//
//    void SetKeepMaxSpeed(bool val)
//    {
//        return ms_fpSetKeepMaxSpeed(this, val);
//    }
//};

struct StateSpinDashSS // TODO: Add this properly to LWBindings!!!
{
    // Wii U: TODO, PC: 0x008c5370
    virtual void OnEnter(app::Player::CStateGOC& goc, int param_2);

    // Wii U: TODO, PC: 0x008c4820
    virtual void OnLeave(app::Player::CStateGOC& goc, int param_2);
};

struct StateSpinDashCharge // TODO: Add this properly to LWBindings!!!
{
    // Wii U: TODO, PC: 0x008c4a40
    virtual void OnEnter(app::Player::CStateGOC& goc, int param_2);

    // Wii U: TODO, PC: 0x008c4b90
    virtual void OnLeave(app::Player::CStateGOC& goc, int param_2);
};

MEMBER_HOOK(LWAPI_ASLR(0x008c5370), StateSpinDashSS,
    StateSpinDashSS_OnEnter_Hook, void,
    CStateGOC& goc, int param_2)
{
    CallOriginal(goc, param_2);

    xgame::MsgBeginBoost msg;
    goc.SendMessageImmToCamera(msg);

    //StateUtil::StartSpinDash(goc);

    //CPostureManager* postMgr = goc.GetPostureManager();
    //CPostureSpinDash* post = static_cast<CPostureSpinDash*>(
    //    postMgr->ChangePosture(*(const char**)ASLR(0x00fb2250)));

    //fnd::Message msg = fnd::Message(0x800d);
    //goc.SendMessageImmToCamera(msg);

    //if (post)
    //{
    //    CPhysics* phy = goc.GetPhysics();
    //    //*((BoostData**)((unsigned char*)phy + 0x373C)) = nullptr;
    //    post->SetFirstVelocity(*phy, 2.5f);
    //    post->SetKeepMaxSpeed(true);
    //    // TODO
    //}
}

MEMBER_HOOK(LWAPI_ASLR(0x008c4820), StateSpinDashSS,
    StateSpinDashSS_OnLeave_Hook, void,
    CStateGOC& goc, int param_2)
{
    CallOriginal(goc, param_2);

    xgame::MsgEndBoost msg;
    goc.SendMessageImmToCamera(msg);

    //StateUtil::EndSpinDash(goc);
}

static void StateSpinDashSS_InstallHooks()
{
    // Unprotect vtable.
    const vtable_ptr vtable(LWAPI_ASLR(0x00dff1d4));
    vtable.Unprotect(17);

    // Install vtable hooks.
    vtable.InstallHook<StateSpinDashSS_OnEnter_Hook>(7);
    vtable.InstallHook<StateSpinDashSS_OnLeave_Hook>(8);
}

LWAPI_DEFINE_PATCH(StateSpinDashSS_InstallHooks)
} // Player
} // app
