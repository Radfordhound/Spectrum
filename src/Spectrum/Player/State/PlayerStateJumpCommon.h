#pragma once
#include "PlayerStateBase.h"

namespace Sonic
{
namespace Player
{
class CStateJumpCommon : public CStateSonicBase
{
public:
    // Colors: 0x80097790
    virtual bool CheckChangeState(CStateGOC& goc, bool allowDoubleJump, bool param_3);
};
} // Player
} // Sonic
