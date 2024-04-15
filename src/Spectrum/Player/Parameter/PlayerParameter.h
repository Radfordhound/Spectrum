#pragma once
#include <System/Component/Goc.h>
#include <Utility/Array.h>

namespace app
{
namespace Player
{
class CPlayer;
} // Player
} // app

namespace Sonic
{
namespace Player
{
namespace Param
{
namespace Type
{
enum EType__
{
    NORMAL,
    SV,
    // TODO: I believe there's 4 of these in total
};
} // Type

enum Index
{
    JUMP_BALL_TIMER = 0xC,
    PARAM_0xE = 0xE,
    JUMP_INITIAL = 0xF,
    JUMP_HOLD = 0x10,
    PARAM_0x11 = 0x11,
    PARAM_0x41 = 0x41,
};
} // Param

struct ParameterThing1
{
    unsigned int    index;
    float           value;
};

struct ParameterThing4
{
    const float*    curValue;
    const float*    values[4];

    ParameterThing4();
};

struct ParameterThing3
{
    ParameterThing4                 defaultValue;
    app::TArray<ParameterThing4>    paramThing4s;

    ParameterThing3();
};

struct ParameterThing5
{
    const ParameterThing1*  params;
    std::size_t             count;

    template<std::size_t ParamCount>
    ParameterThing5(const ParameterThing1(&params)[ParamCount])
        : params(params)
        , count(ParamCount)
    {
    }
};

struct ParameterThing2
{
    ParameterThing3*    m_paramThing3;

    // Colors: 0x8005cfb4
    float GetParamValue(unsigned int paramIndex) const;

    // Colors: 0x8005cd8c
    ParameterThing2();

    // Colors: 0x8005cfdc
    void FUN_8005cfdc(unsigned int paramIndex, const float* paramVal, int valIndex);

    // Colors: 0x8005d060
    void FUN_8005d060(unsigned int paramIndex, const float* paramVal, int valIndex);

    // Colors: 0x8005d0c0
    void FUN_8005d0c0(unsigned int paramIndex, const float* paramVal, int valIndex);

    // Colors: 0x8005d130
    void FUN_8005d130(const ParameterThing5& paramThing5, int valIndex);

    // Colors: 0x8005d1c8
    void FUN_8005d1c8(const ParameterThing5& paramThing5, int valIndex);

    // Colors: 0x8005d234
    void FUN_8005d234(const ParameterThing5& paramThing5, int valIndex);
};

struct ParameterThing6
{
    int                 index;
    ParameterThing5*    paramThing5;

    ParameterThing6();
};

// TODO: Uncomment the next line!
class CParameterGOC //: public app::CGOComponent
{
OPENLW_PRIVATE
    ParameterThing6             m_paramThing6s[4];
    app::Player::CPlayer*       m_player;
    Param::Type::EType__        m_curType;
    const ParameterThing5*      m_paramThing5;
    ParameterThing2*            m_paramThing2;
    unsigned char               field_0x44;

public:
    // Colors: 0x8005d424
    void SetupCommonParameter();

    // Colors: 0x8005d468
    float Get(unsigned int paramIndex) const;

    // Colors: 0x8005d470
    void ChangeParam(Param::Type::EType__ type);

    // Colors: 0x8005d5f4
    void FUN_8005d5f4(Param::Type::EType__ type, int param_2, int valIndex);

    // TODO

    CParameterGOC(app::Player::CPlayer& player);
};

extern CParameterGOC TemporaryParameterGOCInstance;
} // Player
} // Sonic
