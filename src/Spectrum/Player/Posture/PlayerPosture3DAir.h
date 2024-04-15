#pragma once
#include "PlayerPostureCommon.h"
#include <csl/math/vector3.h>

namespace Sonic
{
namespace Player
{
class CPosture3DAir : public CPostureCommon
{
    int                     m_spectrum_field_0x10;
    csl::math::Vector3      m_spectrum_field_0x14;
    float                   m_spectrum_field_0x20;
    bool                    m_spectrum_field_0x24;

public:
    // Colors: 0x808f1694
    static const char* GroupID;

    // Colors: 0x800740c4
    const char* GetGroupID();

    // Colors: 0x8007346c
    void Calculate(CPhysics& physics, float param_2) override;

    // Colors: 0x80073464
    void OnEnter(CPhysics& physics);

    // TODO: Unknown virtual function 0x8004ac14 ?

    // Colors: 0x800737a8
    virtual void calcInternalForNormal(CPhysics& physics, float deltaTime);

    // Colors: 0x80073980
    bool FUN_80073980(CPhysics& physics);

    // Colors: 0x80073758
    void SetInternalForceMode(CPhysics& physics, int param_2);

    // Colors: 0x80073568
    void UpdateInternalForce(CPhysics& physics, float deltaTime);

    // Colors: 0x800733fc
    CPosture3DAir();
};
} // Player
} // Sonic
