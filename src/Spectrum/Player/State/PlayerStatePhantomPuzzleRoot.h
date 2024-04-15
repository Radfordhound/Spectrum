#pragma once
#include "PlayerStatePhantomCommon.h"

namespace Sonic
{
namespace Player
{
class CStatePhantomPuzzleRoot : public CStatePhantomCommon
{
public:
    // Colors: 0x8021b240
    void OnEnter(CStateGOC& goc, int param_2);
};
} // Player
} // Sonic
