#pragma once

namespace app
{
namespace Player
{
// TODO: Make PLAYER_STATE values part of LWAPI
enum ESpectrumStateType
{
    PLAYER_STATE_NONE = -1,
    PLAYER_STATE_STAND_ROOT = 0x1,
    PLAYER_STATE_RUN = 0x3,
    PLAYER_STATE_JUMP = 0x5,
    PLAYER_STATE_DOUBLE_JUMP = 0x7,
    PLAYER_STATE_FALL = 0x12,

    SPECTRUM_LAST_VANILLA_STATE_ID = 0x82,

#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName) enumTypeName,
#include "PlayerState.inl"

    SPECTRUM_TOTAL_PLAYER_STATE_COUNT
};
} // Player
} // app
