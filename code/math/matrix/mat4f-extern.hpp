#ifndef Tmat4f_EXTERN_HPP
#define Tmat4f_EXTERN_HPP

namespace gooapi::math {
    
    class Tmat4f;

    void mat4x4f_mul_mat4x4f_asm_impl(const Tmat4f&, const Tmat4f&, Tmat4f&);
    void mat4x4f_add_mat4x4f_asm_impl(const Tmat4f&, const Tmat4f&, Tmat4f&);
    void mat4x4f_sub_mat4x4f_asm_impl(const Tmat4f&, const Tmat4f&, Tmat4f&);
    void mat4x4f_mul_scalar_asm_impl(const Tmat4f&, const float, Tmat4f&);
    void mat4x4f_transpose_asm_impl(const Tmat4f&, Tmat4f&);
    float mat4x4f_det_asm_impl(const Tmat4f&);
    void mat4x4f_inverse_asm_impl(const Tmat4f&, Tmat4f&);

}

#endif