#ifndef MAT3F_HPP
#define MAT3F_HPP
#include <math/vector/vec3f.hpp>
#include <math/matrix/mat2f.hpp>
#include <math/core/core-math.hpp>

namespace gooapi::math {

    struct Tmat3f;

    Tmat2f reduce(const unsigned int, const unsigned int, const Tmat3f&);

    bool isEqual(const Tmat3f&, const Tmat3f&);
    Tmat3f add(const Tmat3f&, const Tmat3f&);
    Tmat3f mul(const Tmat3f&, const float);
    Tmat3f sub(const Tmat3f&, const Tmat3f&);
    Tmat3f mul(const Tmat3f&, const Tmat3f&);
    Tvec3f mul(const Tvec3f&, const Tmat3f&);
    Tmat3f transpose(const Tmat3f&);
    float det(const Tmat3f&);
    Tmat3f inverse(const Tmat3f&);

    struct Tmat3f {
        union {
            struct {
                float e11, e12, e13,
                      e21, e22, e23,
                      e31, e32, e33;
            };
            Tvec3f vec[3];
            float mat[3][3];
        };
        
    };

}

using mat3f = gooapi::math::Tmat3f;

#endif
