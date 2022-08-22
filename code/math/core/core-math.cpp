#include "core-math.hpp"

namespace gooapi::math {

    float toRadians(float deg) {
        return deg * (GOO_PI / 180.0f);
    }

    float toDegrees(float rad) {
        return rad * (180.0f / GOO_PI);
    }

    float abs(float val) {
        return val >= 0 ? val : -val;
    }

}