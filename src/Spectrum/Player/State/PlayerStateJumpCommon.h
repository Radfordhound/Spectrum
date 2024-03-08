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
    virtual bool FUN_80097790(CStateGOC& goc, bool param_2, bool param_3);
};
} // Player
} // app
