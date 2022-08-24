.CONST
    one_by real4 1.0, -1.0, -1.0, 1.0
.CODE
    option casemap:none
    public mat2x2f_mul_mat2x2f_asm_impl
    public mat2x2f_add_mat2x2f_asm_impl
    public mat2x2f_sub_mat2x2f_asm_impl
    public mat2x2f_mul_scalar_asm_impl
    public mat2x2f_transpose_asm_impl
    public mat2x2f_det_asm_impl
    public mat2x2f_inverse_asm_impl
    MAT_BASIC_OP_BIT_SET = 000000000b
    ; matOut.mF32[0] = matA.mF32[0] * matB.mF32[0] + matA.mF32[1] * matB.mF32[2];
    ; matOut.mF32[1] = matA.mF32[0] * matB.mF32[1] + matA.mF32[1] * matB.mF32[3];
    ; matOut.mF32[2] = matA.mF32[2] * matB.mF32[0] + matA.mF32[3] * matB.mF32[2];
    ; matOut.mF32[3] = matA.mF32[2] * matB.mF32[1] + matA.mF32[3] * matB.mF32[3];

mat2x2f_mul_mat2x2f_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
	movaps xmm1, xmmword ptr [rdx]
    shufps xmm0, xmm0, 010100000b
    shufps xmm1, xmm1, 001000100b
    mulps xmm0, xmm1
    movaps xmm2, xmmword ptr [rcx]
	movaps xmm3, xmmword ptr [rdx]
    shufps xmm2, xmm2, 011110101b
    shufps xmm3, xmm3, 011101110b
    mulps xmm2, xmm3
    addps xmm0, xmm2
    movaps xmmword ptr [r8], xmm0
    ret
mat2x2f_mul_mat2x2f_asm_impl endp

    ; gooapi::math::Xmmword matTmp{
    ;     matA.mF32[0] * vecB.mF32[0] + matA.mF32[1] * vecB.mF32[1],
    ;     matA.mF32[2] * vecB.mF32[0] + matA.mF32[3] * vecB.mF32[1]
    ; };

mat2x2f_add_mat2x2f_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
	addps xmm0, xmmword ptr [rdx]
    movaps xmmword ptr [r8], xmm0
    ret
mat2x2f_add_mat2x2f_asm_impl endp

mat2x2f_sub_mat2x2f_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
	subps xmm0, xmmword ptr [rdx]
    movaps xmmword ptr [r8], xmm0
    ret
mat2x2f_sub_mat2x2f_asm_impl endp

mat2x2f_mul_scalar_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
    shufps xmm1, xmm1, MAT_BASIC_OP_BIT_SET
    mulps xmm0, xmm1
    movaps xmmword ptr [r8], xmm0
    ret
mat2x2f_mul_scalar_asm_impl endp

    ; matTmp.mF32[0] = matA.mF32[0];
    ; matTmp.mF32[1] = matA.mF32[2];
    ; matTmp.mF32[2] = matA.mF32[1];
    ; matTmp.mF32[3] = matA.mF32[3];

mat2x2f_transpose_asm_impl proc
    movaps xmm0, xmmword ptr [rcx]
    shufps xmm0, xmm0, 011011000b
    movaps xmmword ptr [rdx], xmm0
    ret
mat2x2f_transpose_asm_impl endp

    ; matA.mF32[0] * matA.mF32[3] - matA.mF32[1] * matA.mF32[2]

mat2x2f_det_asm_impl proc
    movss xmm0, real4 ptr [rcx]
    movss xmm1, real4 ptr [rcx + 4]
    movss xmm2, real4 ptr [rcx + 8]
    movss xmm3, real4 ptr [rcx + 12]
    mulss xmm0, xmm3
    mulss xmm1, xmm2
    subss xmm0, xmm1
    ret
mat2x2f_det_asm_impl endp

    ; matTmp.mF32[0] = matA.mF32[3] * ( 1 / det);
    ; matTmp.mF32[1] = matA.mF32[1] * (-1 / det);
    ; matTmp.mF32[2] = matA.mF32[2] * (-1 / det);
    ; matTmp.mF32[3] = matA.mF32[0] * ( 1 / det);

mat2x2f_inverse_asm_impl proc
    call mat2x2f_det_asm_impl
    movaps xmm1, xmmword ptr [rcx]
    shufps xmm1, xmm1, 000100111b
    shufps xmm0, xmm0, 000000000b
    movaps xmm2, [one_by]
    divps xmm2, xmm0
    mulps xmm1, xmm2
    movaps xmmword ptr [rdx], xmm1
    ret
mat2x2f_inverse_asm_impl endp

END