cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
project(goo-directx VERSION 0.1.0 LANGUAGES CXX)
enable_testing()

include_directories(
    "${CMAKE_SOURCE_DIR}/code/"
)

add_executable(dx-sandbox "code/main.cpp")

add_subdirectory("code/window/")
add_subdirectory("code/math/")

target_link_libraries(dx-sandbox PUBLIC dx-window dx-math)

set_target_properties(dx-sandbox dx-window dx-math goo-math.test
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/"
)