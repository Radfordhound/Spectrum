#include "pch.h"
#include "BoostCameraPlugin.h"
#include <Camera/Camera.h>
#include <Camera/CameraController.h>
#include <Message/MessageCamera.h>
#include <Message/MessageGameObject3D.h>
#include <Player/State/PlayerStateUtil.h>
#include <System/GameDocument.h>
#include <System/LevelInfo.h>

#include <Message/MessageManager.h> // TODO: REMOVE THIS TEMPORARY LINE
#include <Player/Base/Player.h> // TODO: REMOVE THIS TEMPORARY LINE

using namespace app::xgame;

namespace app
{
namespace Camera
{
class CCameraExt : public CCamera
{
public:
    CBoostCameraPlugin* m_boostCameraPlugin;

    bool SendMessageImmToPlayer(fnd::Message& msg, unsigned int playerNo);

    void ProcMsgBeginBoost(xgame::MsgBeginBoost& param_1);

    void ProcMsgEndBoost(xgame::MsgEndBoost& param_1);

    static void WriteSize(std::uintptr_t address);
};

MEMBER_HOOK(LWAPI_ASLR(0x00418920), CCameraExt,
    CCameraExt_Constructor_Hook, CCameraExt*,
    const CCamera::SCinfo& info)
{
    CallOriginal(info);

    m_boostCameraPlugin = nullptr;
    return this;
}

DERIVED_MEMBER_HOOK(LWAPI_ASLR(0x00419240), 8, CCameraExt,
    CCameraExt_ProcessMessage_Hook, bool,
    fnd::Message& msg)
{
    switch (msg.id)
    {
    case MESSAGE_BEGIN_BOOST:
        ProcMsgBeginBoost(static_cast<MsgBeginBoost&>(msg));
        return true;

    case MESSAGE_END_BOOST:
        ProcMsgEndBoost(static_cast<MsgEndBoost&>(msg));
        return true;

    default:
        return CallOriginal(msg);
    }
}

// Colors: 0x8002ab98
DERIVED_MEMBER_HOOK(LWAPI_ASLR(0x00417d60), 8, CCameraExt,
    CCameraExt_Update_Hook, void,
    const fnd::SUpdateInfo& updateInfo)
{
    if (m_boostCameraPlugin)
    {
        bool is2DMode = false;
        MsgIs2DMode msg(is2DMode);
        SendMessageImmToPlayer(msg, 0);

        m_boostCameraPlugin->m_flags.Set(1, is2DMode);

        // TODO

        m_boostCameraPlugin->Update(updateInfo);
    }

    // TODO: The ordering of these calls is wrong; does this have any effect?
    CallOriginal(updateInfo);
}

// Colors: 0x8002a4c4
MEMBER_HOOK(LWAPI_ASLR(0x00419580), CCameraExt,
    CCameraExt_AddCallback_Hook, void,
    GameDocument* gameDoc)
{
    const auto levelInfo = m_owner->GetService<CLevelInfo>();
    m_isBattle = levelInfo->IsBattle();

    // TODO: REMOVE THIS TEMPORARY CODE!!!
    const auto playerID = levelInfo->GetPlayerID(0);
    const auto player = static_cast<Player::CPlayer*>(m_msgMgr->GetActor(playerID));

    if (player)
    {
        Player::StateUtil::AddRingNum(*player->GetStateGOC(), 100, true);
    }
    // ===================================

    if (!m_isBattle && m_cameraType != 3)
    {
        delete m_boostCameraPlugin;
        m_boostCameraPlugin = new CBoostCameraPlugin(this);
        m_boostCameraPlugin->AddRef();
    }

    if (m_boostCameraPlugin)
    {
        m_boostCameraPlugin->AddPlugin();
        m_boostCameraPlugin->m_flags.Set(1, m_cameraType == 1);
    }

    CallOriginal(gameDoc);
}

bool CCameraExt::SendMessageImmToPlayer(fnd::Message& msg, unsigned int playerNo)
{
    const auto levelInfo = m_owner->GetService<CLevelInfo>();
    const auto playerID = levelInfo->GetPlayerID(playerNo);
    return (playerID) ? SendMessageImm(playerID, msg) : false;
}

void CCameraExt::ProcMsgBeginBoost(MsgBeginBoost& msg)
{
    if (m_boostCameraPlugin)
    {
        m_boostCameraPlugin->BeginBoost();
    }

    for (auto it = field_0xD0.rbegin(); it != field_0xD0.rend(); ++it)
    {
        it->controller->BeginBoostCamera();
    }
}

void CCameraExt::ProcMsgEndBoost(MsgEndBoost& msg)
{
    if (m_boostCameraPlugin)
    {
        m_boostCameraPlugin->EndBoost();
    }

    for (auto it = field_0xD0.rbegin(); it != field_0xD0.rend(); ++it)
    {
        it->controller->EndBoostCamera();
    }
}

void CCameraExt::WriteSize(std::uintptr_t address)
{
    auto cameraSizePtr = reinterpret_cast<std::uintptr_t*>(address);
    UnprotectMemory(cameraSizePtr, sizeof(std::uintptr_t));
    *cameraSizePtr = sizeof(CCameraExt);
}

static void CCamera_InstallHooks()
{
    // Overwrite CCamera sizes, so the game allocates enough memory for CCameraExt.
    CCameraExt::WriteSize(LWAPI_ASLR(0x009157c5));
    CCameraExt::WriteSize(LWAPI_ASLR(0x009274f3));
    CCameraExt::WriteSize(LWAPI_ASLR(0x00928eef));
    CCameraExt::WriteSize(LWAPI_ASLR(0x0092b28a));
    CCameraExt::WriteSize(LWAPI_ASLR(0x0092b310));
    CCameraExt::WriteSize(LWAPI_ASLR(0x00931383));
    CCameraExt::WriteSize(LWAPI_ASLR(0x0093152a));
    CCameraExt::WriteSize(LWAPI_ASLR(0x009382c3));
    CCameraExt::WriteSize(LWAPI_ASLR(0x00939333));
    CCameraExt::WriteSize(LWAPI_ASLR(0x0093ec52));
    CCameraExt::WriteSize(LWAPI_ASLR(0x0093ee00));

    // Install hooks.
    InstallHook<CCameraExt_Constructor_Hook>();

    // Unprotect vtable1.
    const vtable_ptr vtable1(LWAPI_ASLR(0x00d590f0));
    vtable1.Unprotect(4);

    // Install vtable1 hooks.
    vtable1.InstallHook<CCameraExt_AddCallback_Hook>(1);

    // Unprotect vtable2.
    const vtable_ptr vtable2(LWAPI_ASLR(0x00d590d4));
    vtable2.Unprotect(6);

    // Install vtable2 hooks.
    vtable2.InstallHook<CCameraExt_ProcessMessage_Hook>(3);
    vtable2.InstallHook<CCameraExt_Update_Hook>(4);
}

LWAPI_DEFINE_PATCH(CCamera_InstallHooks)
} // Camera
} // app
