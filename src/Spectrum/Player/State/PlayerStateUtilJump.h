#pragma once

namespace app
{
namespace Player
{
class CStateGOC;

namespace StateUtil
{
// Colors: 0x80091540
int GetRequestStateForAir(CStateGOC& goc, int param_2);

// Colors: 0x8009157c
int FUN_8009157c(CStateGOC& goc);

// Colors: 0x800916a4
int FUN_800916a4(CStateGOC& goc);

// TODO: Move to another header?
// Colors: 0x800919cc
bool CheckChangeWallJump(CStateGOC& goc);
} // StateUtil
} // Player
} // app
