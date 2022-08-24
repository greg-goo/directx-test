#ifndef MAT2F_HPP
#define MAT2F_HPP
#include <math/asm_types/xmmword.hpp>
#include <math/vector/vec2f.hpp>
#include <math/core/core-math.hpp>

#ifdef GOO_ASM_MATH
extern "C" {
    #include "mat2f-extern.hpp"
}
#endif

namespace gooapi::math {

    struct Tmat2f;

    bool isEqual(const Tmat2f&, const Tmat2f&);
    Tmat2f add(const Tmat2f&, const Tmat2f&);
    Tmat2f mul(const Tmat2f&, const float);
    Tmat2f sub(const Tmat2f&, const Tmat2f&);
    Tmat2f mul(const Tmat2f&, const Tmat2f&);
    Tvec2f mul(const Tvec2f&, const Tmat2f&);
    Tmat2f transpose(const Tmat2f&);
    float det(const Tmat2f&);
    Tmat2f inverse(const Tmat2f&);

    struct Tmat2f {
        union {
            struct {
                float e11, e12,
                      e21, e22;
            };
            Tvec2f vec[2];
            float mat[2][2];
        };

        Tmat2f() : Tmat2f(0.0f, 0.0f, 0.0f, 0.0f) {};
        Tmat2f(float ae11, float ae12, float ae21, float ae22) : e11{ae11}, e12{ae12}, e21{ae21}, e22{ae22} {}

        Tmat2f(const xmmword& xmw) {
            this->e11 = xmw.mF32[0];
            this->e12 = xmw.mF32[1];
            this->e21 = xmw.mF32[2];
            this->e22 = xmw.mF32[3];
        }

        operator xmmword() const {
            return xmmword{e11, e12, e21, e22};
        }  
    };
}

using mat2f = gooapi::math::Tmat2f;

#endif