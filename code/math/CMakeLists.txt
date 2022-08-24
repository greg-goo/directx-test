cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
enable_language(ASM_MASM)

add_library(dx-math
    STATIC
        "core/core-math.hpp"
        "core/core-math.cpp"
        "core/transform.hpp"
        "core/transform.cpp"
        "asm_types/xmmword.hpp"
        "vector/vec2f.hpp"
        "vector/vec2f.cpp"
        "vector/vec3f.hpp"
        "vector/vec3f.cpp"
        "vector/vec4f.hpp"
        "vector/vec4f.cpp"
        "vector/vec-comp.hpp"
        "vector/vec-comp.cpp"
        "asm_masm_impl/vec_masm_impl.asm"
        "matrix/mat2f-extern.hpp"
        "matrix/mat2f.hpp"
        "matrix/mat2f.cpp"
        "matrix/mat3f.hpp"
        "matrix/mat3f.cpp"
        "matrix/mat4f.hpp"
        "matrix/mat4f.cpp"
        "asm_masm_impl/mat2x2_masm_impl.asm"
        "asm_masm_impl/mat4x4_masm_impl.asm"
)

target_include_directories(dx-math PUBLIC "${CMAKE_SOURCE_DIR}/code/math/")
target_compile_definitions(dx-math PUBLIC "GOO_ASM_MATH")

add_subdirectory("math.test/")