#pragma once
#include "PlayerStatePhantomCommon.h"

namespace app
{
namespace Player
{
class CSpectrumStatePhantomPuzzleStart : public CSpectrumStatePhantomCommon
{
    float field_0x28_spectrum;
    csl::math::Vector3 field_0x2c_spectrum;
    unsigned char field_0x38_spectrum;
    unsigned int field_0x3c_spectrum;
    unsigned int field_0x40_spectrum;
    unsigned int field_0x44_spectrum;
    unsigned int field_0x48_spectrum;
    unsigned int field_0x4c_spectrum;

public:
    // Colors: 0x8021b9f0
    void OnEnter(CStateGOC& goc, int param_2);
};
} // Player
} // app
