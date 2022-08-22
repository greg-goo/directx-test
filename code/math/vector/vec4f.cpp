#include "vec4f.hpp"

namespace gooapi::math {

    bool isEqual(const Tvec4f& u, const Tvec4f& v) {
        return (gooapi::math::abs(u.x - v.x) < EPSILON) &&
               (gooapi::math::abs(u.y - v.y) < EPSILON) && 
               (gooapi::math::abs(u.z - v.z) < EPSILON) &&
               (gooapi::math::abs(u.w - v.w) < EPSILON);
    }

    Tvec4f add(const Tvec4f& u, const Tvec4f& v) {
#ifdef GOO_ASM_MATH
        return addition(u, v);
#endif
        return Tvec4f{u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w};
    }

    Tvec4f mul(const Tvec4f& u, const float skalar) {
#ifdef GOO_ASM_MATH
        return multiplication(skalar, u);
#endif
        return Tvec4f{u.x * skalar, u.y * skalar, u.z * skalar, u.w * skalar};
    }

    Tvec4f sub(const Tvec4f& u, const Tvec4f& v) {
#ifdef GOO_ASM_MATH
        return substraction(u, v);
#endif
        return Tvec4f{u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w};
    }

    bool isZero(const Tvec4f& u) {
        return (gooapi::math::abs(0.0f - u.x) < EPSILON) &&
               (gooapi::math::abs(0.0f - u.y) < EPSILON) && 
               (gooapi::math::abs(0.0f - u.z) < EPSILON) &&
               (gooapi::math::abs(0.0f - u.w) < EPSILON);
    }

    float mag(const Tvec4f& u) {
#ifdef GOO_ASM_MATH
        return magnitude(u);
#endif
        return std::sqrt(u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w);
    }

    float magsqr(const Tvec4f& u) {
        return (u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w);
    }

    Tvec4f normalize(const Tvec4f& u) {
#ifdef GOO_ASM_MATH
        xmmword ret{};
        normal(u, ret);
        return ret;
#endif
        float m = mag(u);
        return Tvec4f{u.x / m, u.y / m, u.z / m, u.w / m};
    }

    float dot(const Tvec4f& u, const Tvec4f& v) {
#ifdef GOO_ASM_MATH
        return dot_product(u, v);
#endif
        return (u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w);
    }

    bool isOrtho(const Tvec4f& u, const Tvec4f& v) {
        return std::abs(0.0f - dot(u, v)) < EPSILON;
    }

    bool isAcute(const Tvec4f& u, const Tvec4f& v) {
        float d = dot(u, v);
        return (std::abs(0.0f - d) > EPSILON) && (d > 0.0f);
    }

    bool isObtuse(const Tvec4f& u, const Tvec4f& v) {
        float d = dot(u, v);
        return (std::abs(0.0f - d) > EPSILON) && (d < 0.0f);
    }

}