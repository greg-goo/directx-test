#include "transform.hpp"

namespace gooapi::math {

    Tmat4f identity() {
        return Tmat4f{
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f,
        };
    }

    Tmat4f scale(float x, float y, float z) {
        Tmat4f A = identity();
        A.e11 = x;
        A.e22 = y;
        A.e33 = z;
        return A;
    }

    Tmat4f scale(const Tvec3f& u) {
        Tmat4f A = identity();
        A.e11 = u.x;
        A.e22 = u.y;
        A.e33 = u.z;
        return A;
    }

}