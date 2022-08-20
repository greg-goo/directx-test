#ifndef WINDOWS_WINDOW_HPP
#define WINDOWS_WINDOW_HPP
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#include <Windows.h>
#include <string>

#include "iwindow.hpp"

namespace gooapi::win {

    class Twindows_window : public Tiwindow {
        public:
            Twindows_window(unsigned int, unsigned int, const std::string&);
            virtual ~Twindows_window();

            void pollEvents() override;

            friend LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
        private:
            bool initWindow() override;
            bool createWindow() override;
            void destroyWindow() override;

            RECT getRect(int, int);
            void showWindow();

            HWND mHwnd{nullptr};
            HDC hdc{nullptr};
            WNDCLASSEX wndclass{};
            const std::string mWinClassName{"Goo-Engine-Window"};
    };

}

#endif