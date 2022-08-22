#include "vec-comp.hpp"
#include <iostream>

namespace gooapi::math {

    float magnitude(const xmmword& xw) {
        return vec4f_mag_asm_impl(xw);
    }

    float dot_product(const xmmword& xwA, const xmmword& xwB) {
        return vec4f_dot_product_asm_impl(xwA, xwB);
    }

    xmmword cross_product(const xmmword& xwA, const xmmword& xwB) {
        xmmword xwOut{};
        vec4f_cross_product_asm_impl(xwA, xwB, xwOut);
        return xwOut;
    }

    void normal(const xmmword& xwIn, xmmword& xwOut) {
        vec4f_normalize_asm_impl(xwIn, xwOut);
    }

    xmmword addition(const float a, const xmmword& xwIn) {
        xmmword xwOut{};
        vec4f_scalar_add_asm_impl(a, xwIn, xwOut);
        return xwOut;
    }
    
    xmmword addition(const xmmword& xwA, const xmmword& xwB) {
        xmmword xwOut{};
        vec4f_vector_add_asm_impl(xwA, xwB, xwOut);
        return xwOut;
    }

    xmmword substraction(const float a, const xmmword& xwIn) {
        xmmword xwOut{};
        vec4f_scalar_sub_asm_impl(a, xwIn, xwOut);
        return xwOut;
    }

    xmmword substraction(const xmmword& xwA, const xmmword& xwB) {
        xmmword xwOut{};
        vec4f_vector_sub_asm_impl(xwA, xwB, xwOut);
        return xwOut;
    }

    xmmword multiplication(const float a, const xmmword& xwIn) {
        xmmword xwOut{};
        vec4f_scalar_mul_asm_impl(a, xwIn, xwOut);
        return xwOut;
    }

    xmmword multiplication(const xmmword& xwA, const xmmword& xwB) {
        xmmword xwOut{};
        vec4f_vector_mul_asm_impl(xwA, xwB, xwOut);
        return xwOut;
    }

}