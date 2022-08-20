cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
project(goo-directx VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    "${CMAKE_SOURCE_DIR}/code/"
)

add_executable(dx-sandbox "code/main.cpp")

add_library(dx-window
    STATIC
        "code/window/iwindow.hpp"
        "code/window/windows_window.hpp"
        "code/window/windows_window.cpp"
)

target_link_libraries(dx-sandbox PUBLIC dx-window)

set_target_properties(dx-sandbox dx-window
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)