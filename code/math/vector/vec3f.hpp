#ifndef VEC3F_HPP
#define VEC3F_HPP
#include <cmath>
#include <asm_types/xmmword.hpp>
#include <core/core-math.hpp>

#ifdef GOO_ASM_MATH
#include "vec-comp.hpp"
#endif

namespace gooapi::math {

    struct Tvec3f;

    bool isEqual(const Tvec3f&, const Tvec3f&); // są równe
    Tvec3f add(const Tvec3f&, const Tvec3f&); // dodawanie wektorów
    Tvec3f mul(const Tvec3f&, const float skalar); // mnoże wektora przez skalar
    Tvec3f sub(const Tvec3f&, const Tvec3f&); // odejmowanie wektorów
    bool isZero(const Tvec3f&); // czy jest zerowy
    float mag(const Tvec3f&); // wielkość (długość)
    float magsqr(const Tvec3f&); // wielkość do kwadratu
    Tvec3f normalize(const Tvec3f&); // normalizacja; mag = 1.0f
    float dot(const Tvec3f&, const Tvec3f&); // iloczyn skalarny
    bool isOrtho(const Tvec3f&, const Tvec3f&); // są prostopadłe (rozeznać się jak używać epsilon)
    bool isAcute(const Tvec3f&, const Tvec3f&); // kąt ostry
    bool isObtuse(const Tvec3f&, const Tvec3f&); // kąt rozwarty
    Tvec3f cross(const Tvec3f&, const Tvec3f&); // iloczyn wektorowy
    Tvec3f proj(const Tvec3f& v, const Tvec3f& n); // projekcja wektora v na n
    Tvec3f prep(const Tvec3f& v, const Tvec3f& n); // wektor prostopadły do wektora projekcji v na n

    struct Tvec3f {
        union {
            struct  {
                float x, y, z;
            };
            float v[3];
        };

        Tvec3f() : x{0.0f}, y{0.0f}, z{0.0f} {}

        Tvec3f(const float aX, const float aY, const float aZ) {
            this->x = aX;
            this->y = aY;
            this->z = aZ;
        }
        
        Tvec3f(const xmmword& axw) {
            this->x = axw.mF32[0];
            this->y = axw.mF32[1];
            this->z = axw.mF32[2];
        }

        operator xmmword() const {
            return xmmword{x, y, z};
        }

        bool operator==(const Tvec3f& u) {
            return isEqual(*this, u);
        }

        Tvec3f operator+(const Tvec3f& u) {
            return add(*this, u);
        }

        Tvec3f operator*(float s) {
            return mul(*this, s);
        }

        Tvec3f operator-(const Tvec3f& u) {
            return sub(*this, u);
        }
    };
}

using vec3f = gooapi::math::Tvec3f;

#endif