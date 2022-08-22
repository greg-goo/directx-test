#ifndef VEC2F_HPP
#define VEC2F_HPP
#include <cmath>
#include <core/core-math.hpp>
#include "vec-comp.hpp"

namespace gooapi::math {

    struct Tvec2f;

    bool isEqual(const Tvec2f&, const Tvec2f&); // są równe
    Tvec2f add(const Tvec2f&, const Tvec2f&); // dodawanie wektorów
    Tvec2f mul(const Tvec2f&, const float skalar); // mnoże wektora przez skalar
    Tvec2f sub(const Tvec2f&, const Tvec2f&); // odejmowanie wektorów
    bool isZero(const Tvec2f&); // czy jest zerowy
    float mag(const Tvec2f&); // wielkość (długość)
    float magsqr(const Tvec2f&); // wielkość do kwadratu
    Tvec2f normalize(const Tvec2f&); // normalizacja; mag = 1.0f
    float dot(const Tvec2f&, const Tvec2f&); // iloczyn skalarny
    bool isOrtho(const Tvec2f&, const Tvec2f&); // są prostopadłe (rozeznać się jak używać epsilon)
    bool isAcute(const Tvec2f&, const Tvec2f&); // kąt ostry
    bool isObtuse(const Tvec2f&, const Tvec2f&); // kąt rozwarty
    Tvec2f proj(const Tvec2f& v, const Tvec2f& n); // projekcja wektora v na n
    Tvec2f prep(const Tvec2f& v, const Tvec2f& n); // wektor prostopadły do wektora projekcji v na n

    struct Tvec2f {
        union {
            struct  {
                float x, y;
            };
            float v[2];
        };

        Tvec2f(const float aX, const float aY) {
            this->x = aX;
            this->y = aY;
        }
        
        Tvec2f(const xmmword& axw) {
            this->x = axw.mF32[0];
            this->y = axw.mF32[1];
        }

        operator xmmword() const {
            return xmmword{x, y};
        }

        bool operator==(const Tvec2f& u) {
            return isEqual(*this, u);
        }

        Tvec2f operator+(const Tvec2f& u) {
            return add(*this, u);
        }

        Tvec2f operator*(float s) {
            return mul(*this, s);
        }

        Tvec2f operator-(const Tvec2f& u) {
            return sub(*this, u);
        }

    };

}

using vec2f = gooapi::math::Tvec2f;

#endif
