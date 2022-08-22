#include "vec3f.hpp"

namespace gooapi::math {

    bool isEqual(const Tvec3f& u, const Tvec3f& v) {
        return (gooapi::math::abs(u.x - v.x) < EPSILON) &&
               (gooapi::math::abs(u.y - v.y) < EPSILON) && 
               (gooapi::math::abs(u.z - v.z) < EPSILON);
    }

    Tvec3f add(const Tvec3f& u, const Tvec3f& v) {
#ifdef GOO_ASM_MATH
        return addition(u, v);
#endif
        return Tvec3f{u.x + v.x, u.y + v.y, u.z + v.z};
    }

    Tvec3f mul(const Tvec3f& u, const float skalar) {
#ifdef GOO_ASM_MATH
        return multiplication(skalar, u);
#endif
        return Tvec3f{u.x * skalar, u.y * skalar, u.z * skalar};
    }

    Tvec3f sub(const Tvec3f& u, const Tvec3f& v) {
#ifdef GOO_ASM_MATH
        return substraction(u, v);
#endif
        return Tvec3f{u.x - v.x, u.y - v.y, u.z - v.z};;
    }

    bool isZero(const Tvec3f& u) {
        return (gooapi::math::abs(0.0f - u.x) < EPSILON) &&
               (gooapi::math::abs(0.0f - u.y) < EPSILON) && 
               (gooapi::math::abs(0.0f - u.z) < EPSILON);
    }

    float mag(const Tvec3f& u) {
#ifdef GOO_ASM_MATH
        return magnitude(u);
#endif
        return std::sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
    }

    float magsqr(const Tvec3f& u) {
        return (u.x * u.x + u.y * u.y + u.z * u.z);
    }

    Tvec3f normalize(const Tvec3f& u) {
#ifdef GOO_ASM_MATH
        xmmword ret{};
        normal(u, ret);
        return ret;
#endif
        float m = mag(u);
        return Tvec3f{u.x / m, u.y / m, u.z / m};
    }

    float dot(const Tvec3f& u, const Tvec3f& v) {
#ifdef GOO_ASM_MATH
        return dot_product(u, v);
#endif
        return (u.x * v.x + u.y * v.y + u.z * v.z);
    }

    bool isOrtho(const Tvec3f& u, const Tvec3f& v) {
        return (gooapi::math::abs(0.0f - dot(u, v)) < EPSILON);
    }

    bool isAcute(const Tvec3f& u, const Tvec3f& v) {
        float d = dot(u, v);
        return ((gooapi::math::abs(0.0f - d) > EPSILON) && (d > 0.0f));
    }

    bool isObtuse(const Tvec3f& u, const Tvec3f& v) {
        float d = dot(u, v);
        return ((gooapi::math::abs(0.0f - d) > EPSILON) && (d < 0.0f));
    }

    Tvec3f cross(const Tvec3f& u, const Tvec3f& v) {
#ifdef GOO_ASM_MATH
        return cross_product(u, v);
#endif
        return Tvec3f{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
    }

    Tvec3f proj(const Tvec3f& v, const Tvec3f& n) {
        Tvec3f norm = normalize(n);
        return mul(norm, dot(v, norm));
    }
    
    Tvec3f prep(const Tvec3f& v, const Tvec3f& n) {
        return sub(v, proj(v, n));
    }

}