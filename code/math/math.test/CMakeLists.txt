cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(goo-math.test
  "goo-math.vec2f.test.cpp"
  "goo-math.vec3f.test.cpp"
  "goo-math.vec4f.test.cpp"
  "goo-math.vec.asm.test.cpp"
)

target_link_libraries(goo-math.test PUBLIC dx-math gtest_main)
target_include_directories(goo-math.test PUBLIC "${CMAKE_SOURCE_DIR}/code/math/")

include(GoogleTest)
gtest_discover_tests(goo-math.test)
