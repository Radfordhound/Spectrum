#pragma once

namespace app
{
namespace Player
{
enum ESpectrumStateType
{
    SPECTRUM_FIRST_NEW_PLAYER_STATE_ID = 0x83,

#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName) enumTypeName,
#include "PlayerState.inl"

    SPECTRUM_TOTAL_PLAYER_STATE_COUNT
};
} // Player
} // app
