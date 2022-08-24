.CODE
    option casemap:none

    public mat4x4f_mul_mat4x4f_asm_impl
    public mat4x4f_add_mat4x4f_asm_impl
    public mat4x4f_sub_mat4x4f_asm_impl
    public mat4x4f_mul_scalar_asm_impl
    public mat4x4f_transpose_asm_impl
    public mat4x4f_det_asm_impl
    public mat4x4f_inverse_asm_impl


linear_comb proc
    xorps xmm0, xmm0
    movaps xmm1, xmmword ptr [rcx]
    movaps xmm2, xmmword ptr [rdx + 0 * 4]
    shufps xmm1, xmm1, 00000000b
    mulps xmm1, xmm2
    addps xmm0, xmm1

    movaps xmm1, xmmword ptr [rcx]
    movaps xmm2, xmmword ptr [rdx + 4 * 4]
    shufps xmm1, xmm1, 01010101b
    mulps xmm1, xmm2
    addps xmm0, xmm1

    movaps xmm1, xmmword ptr [rcx]
    movaps xmm2, xmmword ptr [rdx + 8 * 4]
    shufps xmm1, xmm1, 10101010b
    mulps xmm1, xmm2
    addps xmm0, xmm1

    movaps xmm1, xmmword ptr [rcx]
    movaps xmm2, xmmword ptr [rdx + 12 * 4]
    shufps xmm1, xmm1, 11111111b
    mulps xmm1, xmm2
    addps xmm0, xmm1
    ret
linear_comb endp


mat4x4f_mul_mat4x4f_asm_impl proc
    xor rbx, rbx
multiplication:
    call linear_comb
    movaps xmmword ptr [r8 + rbx * 4], xmm0
    add rcx, 16
    add bl, 4
    cmp bl, 16
    jne multiplication
    ret
mat4x4f_mul_mat4x4f_asm_impl endp

mat4x4f_mul_vec4f_asm_impl proc
    ; matTmp.mF32[0] = matA[0].mF32[0] * vecB.mF32[0] + matA[0].mF32[1] * vecB.mF32[1] + matA[0].mF32[2] * vecB.mF32[2] + matA[0].mF32[3] * vecB.mF32[3];
    ; matTmp.mF32[1] = matA[1].mF32[0] * vecB.mF32[0] + matA[1].mF32[1] * vecB.mF32[1] + matA[1].mF32[2] * vecB.mF32[2] + matA[1].mF32[3] * vecB.mF32[3];
    ; matTmp.mF32[2] = matA[2].mF32[0] * vecB.mF32[0] + matA[2].mF32[1] * vecB.mF32[1] + matA[2].mF32[2] * vecB.mF32[2] + matA[2].mF32[3] * vecB.mF32[3];
    ; matTmp.mF32[3] = matA[3].mF32[0] * vecB.mF32[0] + matA[3].mF32[1] * vecB.mF32[1] + matA[3].mF32[2] * vecB.mF32[2] + matA[3].mF32[3] * vecB.mF32[3];

    movaps xmm0, xmmword ptr [rcx +  0 * 4]
    movaps xmm1, xmmword ptr [rcx +  4 * 4]
    movaps xmm2, xmmword ptr [rcx +  8 * 4]
    movaps xmm3, xmmword ptr [rcx + 12 * 4]
    
    movaps xmm4, xmmword ptr [rdx]
    shufps xmm4, xmm4, 00000000b
    vshufps xmm5, xmm0, xmm1, 00000000b
    vshufps xmm6, xmm2, xmm3, 00000000b
    vshufps xmm7, xmm5, xmm6, 10001000b
    mulps xmm7, xmm4

    movaps xmm4, xmmword ptr [rdx]
    shufps xmm4, xmm4, 01010101b
    vshufps xmm5, xmm0, xmm1, 01010101b
    vshufps xmm6, xmm2, xmm3, 01010101b
    vshufps xmm8, xmm5, xmm6, 10001000b
    mulps xmm8, xmm4

    movaps xmm4, xmmword ptr [rdx]
    shufps xmm4, xmm4, 10101010b
    vshufps xmm5, xmm0, xmm1, 10101010b
    vshufps xmm6, xmm2, xmm3, 10101010b
    vshufps xmm9, xmm5, xmm6, 10001000b
    mulps xmm9, xmm4

    movaps xmm4, xmmword ptr [rdx]
    shufps xmm4, xmm4, 11111111b
    vshufps xmm5, xmm0, xmm1, 11111111b
    vshufps xmm6, xmm2, xmm3, 11111111b
    vshufps xmm10, xmm5, xmm6, 10001000b
    mulps xmm10, xmm4

    addps xmm7, xmm8
    addps xmm7, xmm9
    addps xmm7, xmm10

    movaps xmmword ptr [r8], xmm7

    ret
mat4x4f_mul_vec4f_asm_impl endp

mat4x4f_add_mat4x4f_asm_impl proc
    xor rbx, rbx
adding:
    movaps xmm0, xmmword ptr [rcx + rbx * 4]
    addps xmm0, xmmword ptr [rdx + rbx * 4]
    movaps xmmword ptr [r8 + rbx * 4], xmm0
    add bl, 4
    cmp bl, 16
    jne adding
    ret
mat4x4f_add_mat4x4f_asm_impl endp

mat4x4f_sub_mat4x4f_asm_impl proc
    xor rbx, rbx
subtsracting:
    movaps xmm0, xmmword ptr [rcx + rbx * 4]
    subps xmm0, xmmword ptr [rdx + rbx * 4]
    movaps xmmword ptr [r8 + rbx * 4], xmm0
    add bl, 4
    cmp bl, 16
    jne subtsracting
    ret
mat4x4f_sub_mat4x4f_asm_impl endp

mat4x4f_mul_scalar_asm_impl proc
    shufps xmm1, xmm1, 00000000b
    xor rbx, rbx
multiplication:
    movaps xmm0, xmmword ptr [rcx + rbx * 4]
    mulps xmm0, xmm1
    movaps xmmword ptr [r8 + rbx * 4], xmm0
    add bl, 4
    cmp bl, 16
    jne multiplication
    ret
mat4x4f_mul_scalar_asm_impl endp

mat4x4f_transpose_asm_impl proc
    movaps xmm0, xmmword ptr [rcx +  0 * 4]
    movaps xmm1, xmmword ptr [rcx +  4 * 4]
    movaps xmm2, xmmword ptr [rcx +  8 * 4]
    movaps xmm3, xmmword ptr [rcx + 12 * 4]

    shufps xmm0, xmm1, 10001000b
    movaps xmm4, xmm0
    movaps xmm0, xmmword ptr [rcx + 0 * 4]
    shufps xmm0, xmm1, 11011101b
    movaps xmm5, xmm0

    shufps xmm2, xmm3, 10001000b
    movaps xmm6, xmm2
    movaps xmm2, xmmword ptr [rcx + 8 * 4]
    shufps xmm2, xmm3, 11011101b
    movaps xmm7, xmm2

    movaps xmm0, xmm4
    shufps xmm4, xmm6, 10001000b
    movaps xmmword ptr [rdx + 0 * 4], xmm4

    movaps xmm1, xmm5
    shufps xmm5, xmm7, 10001000b
    movaps xmmword ptr [rdx +4 * 4], xmm5

    shufps xmm0, xmm6, 11011101b
    movaps xmmword ptr [rdx + 8 * 4], xmm0

    shufps xmm1, xmm7, 11011101b
    movaps xmmword ptr [rdx + 12 * 4], xmm1
    ret
mat4x4f_transpose_asm_impl endp

mat4x4f_det_asm_impl proc
    xorps xmm0, xmm0
    movlps xmm0, qword ptr [rcx + 0 * 4]
    movhps xmm0, qword ptr [rcx + 4 * 4]
    movaps xmm1, xmm0   ; tmp1 = xmm1
    
    movlps xmm0, qword ptr [rcx + 8 * 4]
    movhps xmm0, qword ptr [rcx + 12 * 4]
    movaps xmm2, xmm0   ; row1 = xmm2

    movaps xmm0, xmm1
    shufps xmm0, xmm2, 10001000b
    movaps xmm3, xmm0  ; row0 = xmm3

    movaps xmm0, xmm2
    shufps xmm0, xmm1, 11011101b
    movaps xmm4, xmm0  ; row1 = xmm4
    
    xorps xmm0, xmm0
    movlps xmm0, qword ptr [rcx + 2 * 4]
    movhps xmm0, qword ptr [rcx + 6 * 4]
    movaps xmm1, xmm0   ; tmp1 = xmm1

    movlps xmm0, qword ptr [rcx + 10 * 4]
    movhps xmm0, qword ptr [rcx + 14 * 4]
    movaps xmm6, xmm0   ; row3 = xmm6


    movaps xmm0, xmm1
    shufps xmm0, xmm6, 10001000b
    movaps xmm7, xmm0  ; row2 = xmm7

    movaps xmm0, xmm6
    shufps xmm0, xmm1, 11011101b
    movaps xmm6, xmm0  ; row3 = xmm6

    ;-----------------------

    movaps xmm0, xmm7
    mulps xmm0, xmm6
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    movaps xmm0, xmm4
    mulps xmm0, xmm1
    movaps xmm9, xmm0 ; minor0 = xmm9
   
    movaps xmm0, xmm3
    mulps xmm0, xmm1
    movaps xmm10, xmm0 ; minor1 = xmm10

    movaps xmm0, xmm1
    shufps xmm0, xmm0, 01001110b
    movaps xmm1, xmm0  ; tmp1 = xmm1

    movaps xmm0, xmm4
    mulps xmm0, xmm1
    subps xmm0, xmm9
    movaps xmm9, xmm0 ; minor0 = xmm9

    movaps xmm0, xmm3
    mulps xmm0, xmm1
    subps xmm0, xmm10
    shufps xmm0, xmm0, 01001110b
    movaps xmm10, xmm0 ; minor1 = xmm10


    ;-----------------------

    movaps xmm0, xmm4
    mulps xmm0, xmm7
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    addps xmm0, xmm9
    movaps xmm9, xmm0 ; minor0 = xmm9

    movaps xmm0, xmm3
    mulps xmm0, xmm1
    movaps xmm11, xmm0 ; minor3 = xmm11

    movaps xmm0, xmm1
    shufps xmm0, xmm0, 01001110b
    movaps xmm1, xmm0  ; tmp1 = xmm1

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    movaps xmm12, xmm0
    subps xmm9, xmm12 ; minor0 = xmm9

    movaps xmm0, xmm3
    mulps xmm0, xmm1
    subps xmm0, xmm11
    shufps xmm0, xmm0, 01001110b
    movaps xmm11, xmm0 ; minor3 = xmm11

    movaps xmm0, xmm4
    shufps xmm0, xmm0, 01001110b
    mulps xmm0, xmm6
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    shufps xmm7, xmm7, 01001110b ; row2 = xmm7

    movaps xmm0, xmm7
    mulps xmm0, xmm1
    addps xmm9, xmm0 ; minor0 = xmm9

    movaps xmm0, xmm3
    mulps xmm0, xmm1
    movaps xmm13, xmm0 ; minor2 = xmm13

    shufps xmm1, xmm1, 01001110b ; tmp1 = xmm1

    movaps xmm0, xmm7
    mulps xmm0, xmm1
    subps xmm9, xmm0 ; minor0 = xmm9

    movaps xmm0, xmm3
    mulps xmm0, xmm1
    subps xmm0, xmm13
    shufps xmm0, xmm0, 01001110b
    movaps xmm13, xmm0

    movaps xmm0, xmm3
    mulps xmm0, xmm4
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    addps xmm13, xmm0 ; minor2 = xmm13

    movaps xmm0, xmm7
    mulps xmm0, xmm1
    subps xmm0, xmm11
    movaps xmm11, xmm0 ; minor3 = xmm11

    shufps xmm1, xmm1, 01001110b ;tmp1 = xmm1

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    subps xmm0, xmm13
    movaps xmm13, xmm0 ;minor2 = xmm13

    movaps xmm0, xmm7
    mulps xmm0, xmm1
    subps xmm11, xmm0 ; minor3 = xmm11

    movaps xmm0, xmm3
    mulps xmm0, xmm6
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    
    movaps xmm0, xmm7
    mulps xmm0, xmm1
    subps xmm10, xmm0 ; minor1 = xmm10

    movaps xmm0, xmm4
    mulps xmm0, xmm1
    addps xmm0, xmm13 
    movaps xmm13, xmm0; minor2 = xmm13

    shufps xmm1, xmm1, 01001110b

    movaps xmm0, xmm7
    mulps xmm0, xmm1
    addps xmm10, xmm0 ; minor1 = xmm10

    movaps xmm0, xmm4
    mulps xmm0, xmm1
    subps xmm13, xmm0 ; minor2 = xmm13

    movaps xmm0, xmm3
    mulps xmm0, xmm7
    shufps xmm0, xmm0, 10110001b
    movaps xmm1, xmm0 ; tmp1 = xmm1

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    addps xmm10, xmm0 ; minor1 = xmm10


    movaps xmm0, xmm4
    mulps xmm0, xmm1
    subps xmm11, xmm0 ; minor3 = xmm11

    shufps xmm1, xmm1, 01001110b

    movaps xmm0, xmm6
    mulps xmm0, xmm1
    subps xmm10, xmm0 ; minor1 = xmm10

    movaps xmm0, xmm4
    mulps xmm0, xmm1
    addps xmm11, xmm0 ; minor3 = xmm11

    movaps xmm0, xmm3
    mulps xmm0, xmm9
    movaps xmm14, xmm0 ; det = xmm14
    shufps xmm0, xmm0, 01001110b
    addps xmm0, xmm14
    movaps xmm14, xmm0 ; det = xmm14
    shufps xmm0, xmm0, 10110001b
    addss xmm0, xmm14  ; det = xmm14
    movss xmm15, xmm0
    ret
mat4x4f_det_asm_impl endp

mat4x4f_inverse_asm_impl proc
    call mat4x4f_det_asm_impl
    rcpss xmm1, xmm0
    movss xmm0, xmm1
    mulss xmm0, xmm0
    mulss xmm0, xmm15
    addss xmm1, xmm1
    subss xmm1, xmm0

    shufps xmm1, xmm1, 00000000b

    mulps xmm9, xmm1
    movlps qword ptr [rdx + 0 * 4], xmm9
    movhps qword ptr [rdx + 2 * 4], xmm9

    mulps xmm10, xmm1
    movlps qword ptr [rdx + 4 * 4], xmm10
    movhps qword ptr [rdx + 6 * 4], xmm10

    mulps xmm13, xmm1
    movlps qword ptr [rdx +  8 * 4], xmm13
    movhps qword ptr [rdx + 10 * 4], xmm13

    mulps xmm11, xmm1
    movlps qword ptr [rdx + 12 * 4], xmm11
    movhps qword ptr [rdx + 14 * 4], xmm11
    ret
mat4x4f_inverse_asm_impl endp

END