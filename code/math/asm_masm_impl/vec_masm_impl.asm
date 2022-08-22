.CODE
    option casemap:none
    public vec4f_dot_product_asm_impl
    public vec4f_mag_asm_impl
    public vec4f_cross_product_asm_impl
    public vec4f_normalize_asm_impl
    public vec4f_scalar_add_asm_impl
    public vec4f_vector_add_asm_impl
    public vec4f_scalar_sub_asm_impl
    public vec4f_vector_sub_asm_impl
    public vec4f_scalar_mul_asm_impl
    public vec4f_vector_mul_asm_impl
    VEC4_MAG_BIT_SET = 011111111b
    VEC4_BASIC_OP_BIT_SET = 000000000b

vec4f_dot_product_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
    movaps xmm1, xmmword ptr [rdx]
    dpps xmm0, xmm1, VEC4_MAG_BIT_SET
    ret
vec4f_dot_product_asm_impl endp

vec4f_mag_asm_impl proc
    mov rdx, rcx
    call vec4f_dot_product_asm_impl
    sqrtps xmm0, xmm0
    ret
vec4f_mag_asm_impl endp

    ; xwTmp.mF32[0] = xwA.mF32[1] * xwB.mF32[2] - xwA.mF32[2] * xwB.mF32[1];
    ; xwTmp.mF32[1] = xwA.mF32[2] * xwB.mF32[0] - xwA.mF32[0] * xwB.mF32[2];
    ; xwTmp.mF32[2] = xwA.mF32[0] * xwB.mF32[1] - xwA.mF32[1] * xwB.mF32[0];

vec4f_cross_product_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
    movaps xmm1, xmmword ptr [rdx]
    shufps xmm0, xmm0, 011001001b
    shufps xmm1, xmm1, 011010010b
    mulps xmm0, xmm1
    movaps xmm2, xmmword ptr [rcx]
    movaps xmm3, xmmword ptr [rdx]
    shufps xmm2, xmm2, 011010010b
    shufps xmm3, xmm3, 011001001b
    mulps xmm2, xmm3
    subps xmm0, xmm2
    movaps xmmword ptr [r8], xmm0
    ret
vec4f_cross_product_asm_impl endp

vec4f_normalize_asm_impl proc
    movaps xmm1, xmmword ptr [rcx]
    push rdx
    call vec4f_mag_asm_impl
    divps xmm1, xmm0
    pop rdx
    movaps xmmword ptr [rdx], xmm1
    ret
vec4f_normalize_asm_impl endp

vec4f_scalar_add_asm_impl proc
	movaps xmm1, xmmword ptr [rdx]
    shufps xmm0, xmm0, VEC4_BASIC_OP_BIT_SET
	addps xmm0, xmm1
	movaps xmmword ptr [r8], xmm0
    ret
vec4f_scalar_add_asm_impl endp

vec4f_vector_add_asm_impl proc
	movaps xmm0, xmmword ptr [rcx]
	movaps xmm1, xmmword ptr [rdx]
	addps xmm0, xmm1
	movaps xmmword ptr [r8], xmm0
    ret
vec4f_vector_add_asm_impl endp

vec4f_scalar_sub_asm_impl proc
    movaps xmm1, xmmword ptr [rdx]
    shufps xmm0, xmm0, VEC4_BASIC_OP_BIT_SET
	subps xmm1, xmm0
	movaps xmmword ptr [r8], xmm1
    ret
vec4f_scalar_sub_asm_impl endp

vec4f_vector_sub_asm_impl proc
	movaps xmm0, xmmword ptr [rcx]
	movaps xmm1, xmmword ptr [rdx]
	subps xmm0, xmm1
	movaps xmmword ptr [r8], xmm0
    ret
vec4f_vector_sub_asm_impl endp

vec4f_scalar_mul_asm_impl proc
    movaps xmm1, xmmword ptr [rdx]
    shufps xmm0, xmm0, VEC4_BASIC_OP_BIT_SET
	mulps xmm1, xmm0
	movaps xmmword ptr [r8], xmm1
    ret
vec4f_scalar_mul_asm_impl endp

vec4f_vector_mul_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
	movaps xmm1, xmmword ptr [rdx]
	mulps xmm0, xmm1
	movaps xmmword ptr [r8], xmm0
    ret
vec4f_vector_mul_asm_impl endp

END