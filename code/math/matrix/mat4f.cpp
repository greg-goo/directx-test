#include "mat4f.hpp"

namespace gooapi::math {

    Tmat3f reduce(const unsigned int row, const unsigned int col, const Tmat4f& a) {
        Tmat3f tmp{};
        if ((row < 1 || row > 4) || (col < 1 || col > 4))
            return tmp;

        for (int i = 0, k = 0; i < 3; k++) {
            if (k == row - 1) 
                continue;

            for (int j = 0, l = 0; j < 3; l++) {
                if (l == col - 1) 
                    continue;

                tmp.mat[i][j++] = a.mat[k][l];
            }

            i++;
        }

        return tmp;
    }

    bool isEqual(const Tmat4f& a, const Tmat4f& b) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (gooapi::math::abs(a.mat[i][j] - b.mat[i][j]) > EPSILON)
                    return false;
        
        return true;
    }

    Tmat4f add(const Tmat4f& a, const Tmat4f& b) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_add_mat4x4f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat4f tmp{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp.mat[i][j] = a.mat[i][j] + b.mat[i][j];

        return tmp;
#endif
    }

    Tmat4f mul(const Tmat4f& a, const float s) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_mul_scalar_asm_impl(a, s, tmp);
        return tmp;
#else
        Tmat4f tmp{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp.mat[i][j] = a.mat[i][j] * s;

        return tmp;
#endif
    }

    Tmat4f sub(const Tmat4f& a, const Tmat4f& b) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_sub_mat4x4f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat4f tmp{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp.mat[i][j] = a.mat[i][j] - b.mat[i][j];

        return tmp;
#endif
    }

    Tmat4f mul(const Tmat4f& a, const Tmat4f& b) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_mul_mat4x4f_asm_impl(a, b, tmp);
        return tmp;
#else
        Tmat4f tmp{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp.mat[i][j] = a.mat[i][0] * b.mat[0][j] + 
                                a.mat[i][1] * b.mat[1][j] + 
                                a.mat[i][2] * b.mat[2][j] +
                                a.mat[i][3] * b.mat[3][j];

        return tmp;
#endif
    }

    Tvec4f mul(const Tvec4f& v, const Tmat4f& a) {
        Tvec4f tmp{};
        for (int i = 0; i < 4; i++)
            tmp.v[i] = v.v[0] * a.mat[0][i] + 
                       v.v[1] * a.mat[1][i] + 
                       v.v[2] * a.mat[2][i] +
                       v.v[3] * a.mat[3][i];

        return tmp;
    }

    Tmat4f transpose(const Tmat4f& a) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_transpose_asm_impl(a, tmp);
        return tmp;
#else
        Tmat4f tmp{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp.mat[i][j] = a.mat[j][i];

        return tmp;
#endif
    }

    float det(const Tmat4f& a) {
#ifdef GOO_ASM_MATH
        return gooapi::math::mat4x4f_det_asm_impl(a);
#else
        float d{0.0f}, m{1.0f};
        for (int i = 0; i < 4; i++, m *= -1.0f)
            d += m * a.mat[0][i] * gooapi::math::det(gooapi::math::reduce(1, i + 1, a));
            
        return d;
#endif
    }

    Tmat4f inverse(const Tmat4f& a) {
#ifdef GOO_ASM_MATH
        Tmat4f tmp{};
        gooapi::math::mat4x4f_inverse_asm_impl(a, tmp);
        return tmp;
#else
        float d = gooapi::math::det(a);
        if (gooapi::math::abs(0.0f - d) < EPSILON)
            return {};

        Tmat4f md{};
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                md.mat[i][j] = std::powf(-1.0, (i+1) + (j+1)) * 
                               gooapi::math::det(gooapi::math::reduce((i+1),(j+1), a));
        
        float onebyd = 1.0f / d;
        return gooapi::math::mul(gooapi::math::transpose(md), onebyd);
#endif
    }
}