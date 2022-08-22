cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
enable_language(ASM_MASM)

add_library(dx-math
    STATIC
        "core/core-math.hpp"
        "core/core-math.cpp"
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
)

target_include_directories(dx-math PUBLIC "${CMAKE_SOURCE_DIR}/code/math/")
target_compile_definitions(dx-math PUBLIC "GOO_ASM_MATH")

add_subdirectory("math.test/")