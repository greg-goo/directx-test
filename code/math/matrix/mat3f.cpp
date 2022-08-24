#include "mat3f.hpp"

namespace gooapi::math {

    Tmat2f reduce(const unsigned int row, const unsigned int col, const Tmat3f& a) {
        Tmat2f tmp{};
        if ((row < 1 || row > 3) || (col < 1 || col > 3))
            return tmp;

        for (int i = 0, k = 0; i < 2; k++) {
            if (k == row - 1) 
                continue;

            for (int j = 0, l = 0; j < 2; l++) {
                if (l == col - 1) 
                    continue;

                tmp.mat[i][j++] = a.mat[k][l];
            }
            i++;
        }

        return tmp;
    }

    bool isEqual(const Tmat3f& a, const Tmat3f& b) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (gooapi::math::abs(a.mat[i][j] - b.mat[i][j]) > EPSILON)
                    return false;
        
        return true;
    }

    Tmat3f add(const Tmat3f& a, const Tmat3f& b) {
        Tmat3f tmp{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp.mat[i][j] = a.mat[i][j] + b.mat[i][j];

        return tmp;
    }

    Tmat3f mul(const Tmat3f& a, const float s) {
        Tmat3f tmp{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp.mat[i][j] = a.mat[i][j] * s;

        return tmp;
    }

    Tmat3f sub(const Tmat3f& a, const Tmat3f& b) {
        Tmat3f tmp{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp.mat[i][j] = a.mat[i][j] - b.mat[i][j];

        return tmp;
    }

    Tmat3f mul(const Tmat3f& a, const Tmat3f& b) {
        Tmat3f tmp{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp.mat[i][j] = a.mat[i][0] * b.mat[0][j] + 
                                a.mat[i][1] * b.mat[1][j] + 
                                a.mat[i][2] * b.mat[2][j];

        return tmp;
    }

    Tvec3f mul(const Tvec3f& v, const Tmat3f& a) {
        Tvec3f tmp{};
        for (int i = 0; i < 3; i++)
            tmp.v[i] = v.v[0] * a.mat[0][i] + 
                       v.v[1] * a.mat[1][i] + 
                       v.v[2] * a.mat[2][i];

        return tmp;
    }

    Tmat3f transpose(const Tmat3f& a) {
        Tmat3f tmp{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp.mat[i][j] = a.mat[j][i];

        return tmp;
    }

    float det(const Tmat3f& a) {
        return ((a.e11 * a.e22 * a.e33) +
                (a.e12 * a.e23 * a.e31) +
                (a.e13 * a.e21 * a.e32)) -
               ((a.e13 * a.e22 * a.e31) +
                (a.e11 * a.e23 * a.e32) +
                (a.e12 * a.e21 * a.e33)); 
    }

    Tmat3f inverse(const Tmat3f& a) {
        float d = gooapi::math::det(a);
        if (gooapi::math::abs(0.0f - d) < EPSILON)
            return {};

        Tmat3f md{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                md.mat[i][j] = std::powf(-1.0, (i+1) + (j+1)) * 
                               gooapi::math::det(gooapi::math::reduce((i+1),(j+1), a));
        
        float onebyd = 1.0f / d;
        return gooapi::math::mul(gooapi::math::transpose(md), onebyd);
    }

}