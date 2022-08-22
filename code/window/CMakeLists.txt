cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
add_library(dx-window
    STATIC
        "iwindow.hpp"
        "windows_window.hpp"
        "windows_window.cpp"
)