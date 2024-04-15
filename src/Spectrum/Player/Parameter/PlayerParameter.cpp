#pragma once
#include "pch.h"
#include "PlayerParameter.h"

namespace Sonic
{
namespace Player
{
float DegreesToRadians(float deg) // TODO
{
    return deg * (3.1415927f / 180.0f);
}

// Colors: 0x8075b4f0
static const ParameterThing1 ParameterThing1_ARRAY_8075b4f0[0x28] =
{
    { 0x0, 350.0f },
    { 0x1, 0.85f },
    { 0x2, 2.0f },
    { 0x3, 0.1f },
    { 0x4, DegreesToRadians(10000.0f) },
    { 0x5, DegreesToRadians(15.0f) },
    { 0x6, DegreesToRadians(0.0f) },
    { 0x7, 0.4f },
    { 0x9, 300.0f },
    { 0x8, 100.0f },
    { 0xB, 150.0f },
    { 0xA, 50.0f },
    { Param::JUMP_BALL_TIMER, 0.12f },
    { Param::PARAM_0xE, 0.28999999f },
    { Param::JUMP_INITIAL, 125.4f },
    { Param::JUMP_HOLD, 327.0f },
    { Param::PARAM_0x11, 54.899998f },
    { 0x12, 175.0f },
    { 0x13, 150.0f },
    { 0x14, 50.0f },

    // TODO
};

// Colors: 0x8075b630
static const ParameterThing1 ParameterThing1_ARRAY_8075b630[80] =
{
    { 0x2A, 1450.0f },
    { 0x2B, 600.0f },
    { 0x2C, 700.0f },
    { 0x2D, 250.0f },
    { 0x2E, 150.0f },
    { 0x2F, 300.0f },
    { 0x30, 0.0f },
    { 0x31, 500.0f },
    { 0x32, 150.0f },
    { 0x33, 600.0f },
    { 0x34, 840.0f },
    { 0x35, 1500.0f },
    { 0x36, 30.0f },
    { 0x37, 200.0f },
    { 0x38, 400.0f },
    { 0x39, 720.0f },
    { 0x3A, 360.0f },
    { 0x3B, 80.0f },
    { 0x3C, 40.0f },
    { 0x3D, 2000.0f },
    { 0x3E, 1000.0f },
    { 0x3F, 100.0f },
    { 0x40, 1300.0f },
    { 0x41, 1.0f },
    { 0x42, 0.2f },
    { 0x43, 0.4f },
    { 0x44, 150.0f },
    { 0x45, 200.0f },
    { 0x46, 150.0f },
    { 0x47, 400.0f },
    { 0x48, 1000.0f },
    { 0x49, 160.0f },
    { 0x4A, 800.0f },
    { 0x4B, 350.0f },
    { 0x4C, 50.0f },
    { 0x4D, 150.0f },
    { 0x4E, 670.0f },
    { 0x4F, 40.0f },
    { 0x50, 22.0f },
    { 0x51, 11.0f },
    { 0x52, 11.0f },
    { 0x53, 60.0f },
    { 0x54, 30.0f },
    { 0x55, 45.0f },
    { 0x56, 200.0f },
    { 0x56, 250.0f },
    { 0x58, DegreesToRadians(720.0f) },
    { 0x59, DegreesToRadians(90.0f) },
    { 0x5A, DegreesToRadians(960.0f) },
    { 0x5B, 38.0f },
    { 0x5C, 38.0f },
    { 0x5D, 375.0f },
    { 0x5E, 200.0f },
    { 0x5F, 1.5f },
    { 0x60, 3.0f },
    { 0x61, 0.5f },
    { 0x62, 0.5f },
    { 0x63, 1.0f },
    { 0x64, 100.0f },
    { 0x65, 350.0f },
    { 0x66, 30.0f },
    { 0x67, 350.0f },
    { 0x68, 600.0f },
    { 0x69, 50.0f },
    { 0x6A, 1.0f },
    { 0x6B, 700.0f },
    { 0x6C, 0.1f },
    { 0x6D, 180.0f },
    { 0x6E, 85.0f },
    { 0x6F, 1.0f },
    { 0x70, 5.0f },
    { 0x71, 200.0f },
    { 0x72, 150.0f },
    { 0x73, 100.0f },
    { 0x74, 300.0f },
    { 0x26, 80.0f },
    { 0x75, 700.0f },
    { 0x76, 2500.0f },
    { 0x77, 2000.0f },
    { 0x78, 100.0f }
};

// Colors: 0x8075b8b0
static const ParameterThing1 ParameterThing1_ARRAY_8075b8b0[69] =
{
    // TODO
};

// Colors: 0x8075bc00
static const ParameterThing1 ParameterThing1_ARRAY_8075bc00[83] =
{
    // TODO
};

// Colors: 0x8075be98
static const ParameterThing1 ParameterThing1_ARRAY_8075be98[72] =
{
    // TODO
};

// Colors: 0x808f1608
static const ParameterThing5 ParameterThing5_808f1608 = ParameterThing1_ARRAY_8075b4f0;

// Colors: 0x808f1610
static const ParameterThing5 ParameterThing5_808f1610 = ParameterThing1_ARRAY_8075b630;

// Colors: 0x808f1618
static const ParameterThing5 ParameterThing5_808f1618 = ParameterThing1_ARRAY_8075b8b0;

// Colors: 0x808f1630
static const ParameterThing5 ParameterThing5_808f1630 = ParameterThing1_ARRAY_8075bc00;

// Colors: 0x808f1638
static const ParameterThing5 ParameterThing5_808f1638 = ParameterThing1_ARRAY_8075be98;

ParameterThing4::ParameterThing4()
    : curValue(nullptr)
    , values()
{
}

ParameterThing3::ParameterThing3()
    : paramThing4s(127, defaultValue)
{
}

float ParameterThing2::GetParamValue(unsigned int paramIndex) const
{
    const float* val = m_paramThing3->paramThing4s[paramIndex].curValue;
    return (val) ? *val : 0.0f;
}

ParameterThing2::ParameterThing2() 
    : m_paramThing3(new ParameterThing3())
{
}

void ParameterThing2::FUN_8005cfdc(unsigned int paramIndex, const float* paramVal, int valIndex)
{
    if (paramIndex < m_paramThing3->paramThing4s.size())
    {
        ParameterThing4 local_28;
        local_28.values[valIndex] = paramVal;
        local_28.curValue = paramVal;

        m_paramThing3->paramThing4s[paramIndex] = local_28;
    }
}

void ParameterThing2::FUN_8005d060(unsigned int paramIndex, const float* paramVal, int valIndex)
{
    if (m_paramThing3->paramThing4s.size() <= paramIndex)
    {
        return;
    }

    const auto it = (m_paramThing3->paramThing4s.begin() + paramIndex);
    it->values[valIndex] = paramVal;

    // Update current value.
    for (unsigned int i = 4; i != 0; --i)
    {
        const auto val = it->values[i - 1];
        if (val)
        {
            it->curValue = val;
            return;
        }
    }

    it->curValue = nullptr;
}

void ParameterThing2::FUN_8005d0c0(unsigned int paramIndex, const float* paramVal, int valIndex)
{
    if (m_paramThing3->paramThing4s.size() <= paramIndex)
    {
        return;
    }

    const auto it = (m_paramThing3->paramThing4s.begin() + paramIndex);
    if (it->values[valIndex] != paramVal)
    {
        return;
    }

    // Unset the specified value.
    it->values[valIndex] = nullptr;

    // Update current value.
    for (unsigned int i = 4; i != 0; --i)
    {
        const auto val = it->values[i - 1];
        if (val)
        {
            it->curValue = val;
            return;
        }
    }

    it->curValue = nullptr;
}

void ParameterThing2::FUN_8005d130(const ParameterThing5& paramThing5, int valIndex)
{
    for (std::size_t i = 0; i < paramThing5.count; ++i)
    {
        const auto& param = paramThing5.params[i];

        if (!m_paramThing3->paramThing4s[param.index].curValue)
        {
            FUN_8005cfdc(param.index, &param.value, valIndex);
        }
        else
        {
            FUN_8005d060(param.index, &param.value, valIndex);
        }
    }
}

void ParameterThing2::FUN_8005d1c8(const ParameterThing5& paramThing5, int valIndex)
{
    for (std::size_t i = 0; i < paramThing5.count; ++i)
    {
        FUN_8005d060(paramThing5.params[i].index,
            &paramThing5.params[i].value, valIndex);
    }
}

void ParameterThing2::FUN_8005d234(const ParameterThing5& paramThing5, int valIndex)
{
    for (std::size_t i = 0; i < paramThing5.count; ++i)
    {
        FUN_8005d0c0(paramThing5.params[i].index,
            &paramThing5.params[i].value, valIndex);
    }
}

ParameterThing6::ParameterThing6()
    : index(-1)
    , paramThing5(nullptr)
{
}

void CParameterGOC::SetupCommonParameter()
{
    m_paramThing2->FUN_8005d130(ParameterThing5_808f1608, 0);
    ChangeParam(Param::Type::NORMAL);
}

float CParameterGOC::Get(unsigned int paramIndex) const
{
    return m_paramThing2->GetParamValue(paramIndex);
}

void CParameterGOC::ChangeParam(Param::Type::EType__ type)
{
    if (type != m_curType)
    {
        for (int i = 2; i < 4; ++i)
        {
            FUN_8005d5f4(m_curType, m_paramThing6s[i].index, i);
        }

        if (m_paramThing5)
        {
            m_paramThing2->FUN_8005d234(*m_paramThing5, 1);
        }

        if (type == Param::Type::NORMAL)
        {
            m_paramThing5 = (field_0x44) ?
                &ParameterThing5_808f1630 :
                &ParameterThing5_808f1610;
        }
        else
        {
            m_paramThing5 = (field_0x44) ?
                &ParameterThing5_808f1638 :
                &ParameterThing5_808f1618;
        }

        if (m_paramThing5)
        {
            m_paramThing2->FUN_8005d1c8(*m_paramThing5, 1);
        }

        m_curType = type;
    }
}

void CParameterGOC::FUN_8005d5f4(Param::Type::EType__ type, int param_2, int valIndex)
{
    if (param_2 == m_paramThing6s[valIndex].index)
    {
        const auto paramThing5 = m_paramThing6s[valIndex].paramThing5;
        if (paramThing5)
        {
            if (paramThing5) // TODO: Why does it check this twice??
            {
                m_paramThing2->FUN_8005d234(*paramThing5, valIndex);
            }

            m_paramThing6s[valIndex].index = -1;
            m_paramThing6s[valIndex].paramThing5 = nullptr;
        }
    }
}

CParameterGOC::CParameterGOC(app::Player::CPlayer& player)
    : m_paramThing6s()
    , m_player(&player)
    , m_curType(static_cast<Param::Type::EType__>(-1))
    , m_paramThing5(nullptr)
    , m_paramThing2(nullptr)
    , field_0x44(false)
{
    m_paramThing2 = new ParameterThing2();
}

CParameterGOC TemporaryParameterGOCInstance = CParameterGOC(*(app::Player::CPlayer*)nullptr); // TODO !
} // Player
} // Sonic
