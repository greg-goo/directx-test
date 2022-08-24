#ifndef VEC4F_HPP
#define VEC4F_HPP
#include <cmath>
#include <asm_types/xmmword.hpp>
#include <core/core-math.hpp>

#ifdef GOO_ASM_MATH
#include "vec-comp.hpp"
#endif

namespace gooapi::math {

    struct Tvec4f;

    bool isEqual(const Tvec4f&, const Tvec4f&); // są równe
    Tvec4f add(const Tvec4f&, const Tvec4f&); // dodawanie wektorów
    Tvec4f mul(const Tvec4f&, const float skalar); // mnoże wektora przez skalar
    Tvec4f sub(const Tvec4f&, const Tvec4f&); // odejmowanie wektorów
    bool isZero(const Tvec4f&); // czy jest zerowy
    float mag(const Tvec4f&); // wielkość (długość)
    float magsqr(const Tvec4f&); // wielkość do kwadratu
    Tvec4f normalize(const Tvec4f&); // normalizacja; mag = 1.0f
    float dot(const Tvec4f&, const Tvec4f&); // iloczyn skalarny

    struct Tvec4f {
        union {
            struct  {
                float x, y, z, w;
            };
            float v[4];
        };

        Tvec4f() : Tvec4f(0.0f, 0.0f, 0.0f, 0.0f) {};

        Tvec4f(const float aX, const float aY, const float aZ, const float aW) {
            this->x = aX;
            this->y = aY;
            this->z = aZ;
            this->w = aW;
        }
        
        Tvec4f(const xmmword& axw) {
            this->x = axw.mF32[0];
            this->y = axw.mF32[1];
            this->z = axw.mF32[2];
            this->w = axw.mF32[3];
        }

        operator xmmword() const {
            return xmmword{x, y, z, w};
        }

        bool operator==(const Tvec4f& u) {
            return isEqual(*this, u);
        }

        Tvec4f operator+(const Tvec4f& u) {
            return add(*this, u);
        }

        Tvec4f operator*(float s) {
            return mul(*this, s);
        }

        Tvec4f operator-(const Tvec4f& u) {
            return sub(*this, u);
        }
    };

}

using vec4f = gooapi::math::Tvec4f;

#endif