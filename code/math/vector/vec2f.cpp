#include "vec2f.hpp"

namespace gooapi::math {
    
    /**
     * @brief Sprawdza czy dwa wektory vec2f są równe
     * 
     * @param u Pierwszy wektor
     * @param v Drugi wektor
     * @return efekt sprawdzenia
     */
    bool isEqual(const Tvec2f& u, const Tvec2f& v) {
        return (gooapi::math::abs(u.x - v.x) < EPSILON) &&
               (gooapi::math::abs(u.y - v.y) < EPSILON);
               
    }

    Tvec2f add(const Tvec2f& u, const Tvec2f& v) {
#ifdef GOO_ASM_MATH
        return addition(u, v);
#endif
        return Tvec2f{u.x + v.x, u.y + v.y};
    }

    Tvec2f mul(const Tvec2f& u, const float skalar) {
#ifdef GOO_ASM_MATH
        return multiplication(skalar, u);
#endif
        return Tvec2f{u.x * skalar, u.y * skalar};
    }

    Tvec2f sub(const Tvec2f& u, const Tvec2f& v) {
#ifdef GOO_ASM_MATH
        return substraction(u, v);
#endif
        return Tvec2f{u.x - v.x, u.y - v.y};;
    }

    bool isZero(const Tvec2f& u) {
        return (gooapi::math::abs(0.0f - u.x) < EPSILON) &&
               (gooapi::math::abs(0.0f - u.y) < EPSILON);
    }

    float mag(const Tvec2f& u) {
#ifdef GOO_ASM_MATH
        return magnitude(u);
#endif
        return std::sqrt(u.x * u.x + u.y * u.y);
    }

    float magsqr(const Tvec2f& u) {
        return (u.x * u.x + u.y * u.y);
    }

    Tvec2f normalize(const Tvec2f& u) {
#ifdef GOO_ASM_MATH
        xmmword ret{};
        normal(u, ret);
        return ret;
#endif
        float m = mag(u);
        return Tvec2f{u.x / m, u.y / m};
    }

    float dot(const Tvec2f& u, const Tvec2f& v) {
#ifdef GOO_ASM_MATH
        return dot_product(u, v);
#endif
        return (u.x * v.x + u.y * v.y);
    }

    bool isOrtho(const Tvec2f& u, const Tvec2f& v) {
        return (gooapi::math::abs(0.0f - dot(u, v)) < EPSILON);
    }

    bool isAcute(const Tvec2f& u, const Tvec2f& v) {
        float d = dot(u, v);
        return (std::abs(0.0f - d) > EPSILON) && (d > 0.0f);
    }

    bool isObtuse(const Tvec2f& u, const Tvec2f& v) {
        float d = dot(u, v);
        return (std::abs(0.0f - d) > EPSILON) && (d < 0.0f);
    }

    Tvec2f proj(const Tvec2f& v, const Tvec2f& n) {
        Tvec2f norm = normalize(n);
        return mul(norm, dot(v, norm));
    }
    
    Tvec2f prep(const Tvec2f& v, const Tvec2f& n) {
        return sub(v, proj(v, n));
    }

}