#include "mat2f.hpp"
#include <iostream>

namespace gooapi::math {

    bool isEqual(const Tmat2f& a, const Tmat2f& b) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (gooapi::math::abs(a.mat[i][j] - b.mat[i][j]) > EPSILON)
                    return false;
        
        return true;
    }

    Tmat2f add(const Tmat2f& a, const Tmat2f& b) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_add_mat2x2f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat2f tmp{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        return tmp;
#endif
    }

    Tmat2f mul(const Tmat2f& a, const float s) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_mul_scalar_asm_impl(a, s, tmp);
        return tmp;
#else
        Tmat2f tmp{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp.mat[i][j] = a.mat[i][j] * s;

        return tmp;
#endif
    }

    Tmat2f sub(const Tmat2f& a, const Tmat2f& b) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_sub_mat2x2f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat2f tmp{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp.mat[i][j] = a.mat[i][j] - b.mat[i][j];

        return tmp;
#endif
    }

    Tmat2f mul(const Tmat2f& a, const Tmat2f& b) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_mul_mat2x2f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat2f tmp{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp.mat[i][j] = a.mat[i][0] * b.mat[0][j] + 
                                a.mat[i][1] * b.mat[1][j];

        return tmp;
#endif
    }

    Tvec2f mul(const Tvec2f& v, const Tmat2f& a) {
        Tvec2f tmp{};
        for (int i = 0; i < 2; i++)
            tmp.v[i] = v.v[0] * a.mat[0][i] + 
                       v.v[1] * a.mat[1][i];

        return tmp;
    }

    Tmat2f transpose(const Tmat2f& a) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_transpose_asm_impl(a, tmp);
        return tmp;
#else
        Tmat2f tmp{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp.mat[i][j] = a.mat[j][i];

        return tmp;
#endif
    }

    float det(const Tmat2f& a) {
#ifdef GOO_ASM_MATH
        return gooapi::math::mat2x2f_det_asm_impl(a);
#else
        return {a.e11 * a.e22 - a.e12 * a.e21};
#endif
    }

    Tmat2f inverse(const Tmat2f& a) {
#ifdef GOO_ASM_MATH
        xmmword tmp{};
        gooapi::math::mat2x2f_inverse_asm_impl(a, tmp);
        return tmp;
#else
        float d = gooapi::math::det(a);
        if (gooapi::math::abs(0.0f - d) < EPSILON)
            return {};
        float onebyd = 1.0f / d;
        Tmat2f tmp{
             a.e22, -a.e12,
            -a.e21,  a.e11
        };
        return gooapi::math::mul(tmp, onebyd);
#endif
    }
}