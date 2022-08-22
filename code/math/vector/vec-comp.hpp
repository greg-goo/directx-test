#ifndef VEC_COMP_HPP
#define VEC_COMP_HPP
#include <asm_types/xmmword.hpp>

extern "C" {
    #include "vec-extern-func.hpp"
}

namespace gooapi::math {

    float magnitude(const xmmword&);
    float dot_product(const xmmword&, const xmmword&);
    xmmword cross_product(const xmmword&, const xmmword&);
    void normal(const xmmword&, xmmword&);
    xmmword addition(const float, const xmmword&);
    xmmword addition(const xmmword&, const xmmword&);
    xmmword substraction(const float, const xmmword&);
    xmmword substraction(const xmmword&, const xmmword&);
    xmmword multiplication(const float, const xmmword&);
    xmmword multiplication(const xmmword&, const xmmword&);

}

#endif