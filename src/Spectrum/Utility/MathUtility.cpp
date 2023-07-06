#include "pch.h"
#include "MathUtility.h"
#include <csl/math/vector3.h>

using namespace csl::math;

namespace app
{
namespace CMathUtility
{
void ChangeValueGradually(Vector3& param_1,
    Vector3 const& param_2, float param_3, float param_4)
{
    // TODO: Is all of this correct?
    Vector3 auStack176 = (param_2 - param_1);
    float len = auStack176.Length();

    //float v17 = param_1.Normalize();
    Vector3 v14 = param_2;

    if ((param_3 * param_4) <= len)
    {
        Vector3 v28(param_1 * (1.0f / len));
        Vector3 v30(v28 * param_3);
        Vector3 v32(v30 * param_4);

        param_1 = (param_1 + v32);
    }
    else
    {
        param_1 = param_2;
    }
}

void ChangeValueGradually(float& param_1, float param_2, float param_3, float param_4)
{
    param_3 = (param_3 * param_4);
    if (param_1 <= param_2)
    {
        if (param_3 < -(param_1 - param_2))
        {
            param_1 = (param_1 + param_3);
            return;
        }
    }
    else if (param_3 < (param_1 - param_2))
    {
        param_1 = (param_1 - param_3);
        return;
    }

    param_1 = param_2;
}

void ChangeValueD1Gradually(float& param_1, float param_2,
    float param_3, float param_4, float param_5,
    float param_6, float param_7)
{
    float fVar2 = (((param_3 - param_2) / param_4) * param_5);
    if (std::abs(param_5) < std::abs(fVar2))
    {
        if (0.0f < fVar2)
        {
            ChangeValueGradually(param_1, param_5, param_6, param_7);
            if (std::abs(param_1) > std::abs(param_5))
            {
                param_1 = param_5;
            }
            return;
        }

        fVar2 = -param_5;
    }

    ChangeValueGradually(param_1, fVar2, param_6, param_7);

    if (std::abs(param_1) > std::abs(fVar2))
    {
        param_1 = fVar2;
    }
}
} // CMathUtility
} // app
