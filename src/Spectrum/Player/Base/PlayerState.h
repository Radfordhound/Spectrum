#pragma once

namespace app
{
namespace Player
{
enum ESpectrumStateType
{
    PLAYER_STATE_STAND_ROOT = 0x1, // TODO
    PLAYER_STATE_RUN = 0x3, // TODO
    PLAYER_STATE_JUMP = 0x5, // TODO
    PLAYER_STATE_DOUBLE_JUMP = 0x7, // TODO
    PLAYER_STATE_FALL = 0x12, // TODO

    SPECTRUM_LAST_VANILLA_STATE_ID = 0x82,

#define SPECTRUM_PLAYER_STATE_AUTOGEN(className, enumTypeName) enumTypeName,
#include "PlayerState.inl"

    SPECTRUM_TOTAL_PLAYER_STATE_COUNT
};
} // Player
} // app
