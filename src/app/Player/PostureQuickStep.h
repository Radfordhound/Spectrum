#pragma once
#include <Player/Posture/PlayerPostureCommon.h>
#include <csl/math/vector3.h>

namespace app
{
namespace Player
{
class CPostureQuickStep : public CPostureCommon
{
    csl::math::Vector3 field_0x10;
    csl::math::Vector3 field_0x1c;
    csl::math::Vector3 field_0x28;
    csl::math::Vector3 field_0x34;
    float field_0x40;
    float field_0x44;
    float field_0x48;
    unsigned int m_flags;

public:
    // Colors: 0x808f1ca0
    static const char* GroupID;

    // Colors: 0x80193498
    const char* GetGroupID();

    // Colors: 0x801928b0
    void Calculate(CPhysics& param_1, float param_2);

    // Colors: 0x80192888
    void OnEnter(CPhysics& param_1);

    // Colors: 0x8019289c
    void OnLeave(CPhysics& param_1);

    // Colors: 0x80192790
    bool ProcessMessage(CPhysics& physics, fnd::Message& msg);

    // TODO: Unknown virtual function 0x8004ac14 ?

    // Colors: 0x801927f8
    CPostureQuickStep();
};
} // Player
} // app
