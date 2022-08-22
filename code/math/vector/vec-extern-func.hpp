#ifndef VEC_EXERN_FUNC_HPP
#define VEC_EXERN_FUNC_HPP
#include <asm_types/xmmword.hpp>

namespace gooapi::math {

    float vec4f_dot_product_asm_impl(const xmmword&, const xmmword&);
    float vec4f_mag_asm_impl(const xmmword&);
    void vec4f_cross_product_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void vec4f_normalize_asm_impl(const xmmword&, xmmword&);
    void vec4f_scalar_add_asm_impl(const float, const xmmword&, xmmword&);
    void vec4f_vector_add_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void vec4f_scalar_sub_asm_impl(const float, const xmmword&, xmmword&);
    void vec4f_vector_sub_asm_impl(const xmmword&, const xmmword&, xmmword&);
    void vec4f_scalar_mul_asm_impl(const float, const xmmword&, xmmword&);
    void vec4f_vector_mul_asm_impl(const xmmword&, const xmmword&, xmmword&);

}

#endif