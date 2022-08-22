#ifndef CORE_MATH_HPP
#define CORE_MATH_HPP

namespace gooapi::math {

    constexpr float GOO_PI = 3.141592654f;
    constexpr float EPSILON = 0.001f;

    float toRadians(float deg);  // stopnie na radiany
    float toDegrees(float rad);  // radiany na stopnie
    float abs(float);

}

#endif
