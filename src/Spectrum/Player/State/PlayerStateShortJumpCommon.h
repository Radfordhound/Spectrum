#pragma once
#include "PlayerStateJumpCommon.h"
#include <csl/math/vector3.h>

namespace app
{
namespace Player
{
class CSpectrumStateShortJumpCommon : public CSpectrumStateJumpCommon
{
protected:
    csl::math::Vector3 field_0x24_spectrum;

public:
    // Colors: 0x80097a04
    bool FUN_80097a04(CStateGOC& goc);

    // Colors: 0x8009793c
    void DoJump(CStateGOC& goc);
};
} // Player
} // app
