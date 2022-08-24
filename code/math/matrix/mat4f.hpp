#ifndef MAT4F_HPP
#define MAT4F_HPP
#include <math/matrix/mat3f.hpp>
#include <math/vector/vec4f.hpp>
#include <math/core/core-math.hpp>

#ifdef GOO_ASM_MATH
extern "C" {
    #include "mat4f-extern.hpp"
}
#endif

namespace gooapi::math {

    struct Tmat4f;

    Tmat3f reduce(const unsigned int, const unsigned int, const Tmat4f&);

    bool isEqual(const Tmat4f&, const Tmat4f&);
    Tmat4f add(const Tmat4f&, const Tmat4f&);
    Tmat4f mul(const Tmat4f&, const float);
    Tmat4f sub(const Tmat4f&, const Tmat4f&);
    Tmat4f mul(const Tmat4f&, const Tmat4f&);
    Tvec4f mul(const Tvec4f&, const Tmat4f&);
    Tmat4f transpose(const Tmat4f&);
    float det(const Tmat4f&);
    Tmat4f inverse(const Tmat4f&);

    struct alignas(16) Tmat4f {
        union {
            struct {
                float e11, e12, e13, e14,
                      e21, e22, e23, e24,
                      e31, e32, e33, e34,
                      e41, e42, e43, e44;
            };
            Tvec4f vec[4];
            float mat[4][4];
        };

    };

}

using mat4f = gooapi::math::Tmat4f;

#endif