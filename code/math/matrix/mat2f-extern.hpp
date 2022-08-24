#ifndef MAT2F_EXTERN_HPP
#define MAT2F_EXTERN_HPP
#include <math/asm_types/xmmword.hpp>

namespace gooapi::math {

    struct Tmat2f;

    void mat2x2f_mul_mat2x2f_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void mat2x2f_add_mat2x2f_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void mat2x2f_sub_mat2x2f_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void mat2x2f_mul_scalar_asm_impl(const xmmword&, const float, xmmword&);
    void mat2x2f_transpose_asm_impl(const xmmword&, xmmword&);
    float mat2x2f_det_asm_impl(const xmmword&);
    void mat2x2f_inverse_asm_impl(const xmmword&, xmmword&);

}

#endif