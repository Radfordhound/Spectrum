#pragma once
#include <Player/State/PlayerStateBase.h>

namespace app
{
namespace Player
{
class CSpectrumStateJumpCommon : public CStateSonicBase
{
public:
    // Colors: 0x80097790
    virtual bool CheckChangeState(CStateGOC& goc, bool allowDoubleJump, bool param_3);
};
} // Player
} // app
