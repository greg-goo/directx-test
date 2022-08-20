#include "windows_window.hpp"

namespace gooapi::win {
    
    LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

        switch (iMsg) {
           
            case WM_CLOSE:
                // Wysyłany jako sygnał, że okno lub aplikacja powinna zostać zakończona.
                DestroyWindow(hwnd);
            break;

            case WM_DESTROY:
                // Wysyłane, gdy okno jest niszczone.
                // Jest on wysyłany do procedury okna niszczonego okna po usunięciu okna z ekranu
                PostQuitMessage(0);
            break;
            
            default:
                return DefWindowProc(hwnd, iMsg, wParam, lParam);
            
        };

        return 0;
    }

    Twindows_window::Twindows_window(
        unsigned int aWidth, 
        unsigned int aHeight,
        const std::string& aTitle) 
            : Tiwindow(aWidth, aHeight, aTitle) {}
    
    Twindows_window::~Twindows_window() {
        destroyWindow();
    }

    void Twindows_window::pollEvents() {
        MSG msg{};

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                setShouldQuit();

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    bool Twindows_window::initWindow() {
        wndclass.cbSize = sizeof(WNDCLASSEX);
        wndclass.style = CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc = WndProc;
        wndclass.cbClsExtra = 0;
        wndclass.cbWndExtra = 0;
        wndclass.hInstance = GetModuleHandle(nullptr);
        wndclass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        wndclass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
        wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wndclass.lpszMenuName = 0;
        wndclass.lpszClassName = reinterpret_cast<LPCSTR>(mWinClassName.c_str());

        if (RegisterClassEx(&wndclass) == 0) {
            return false;
        }

        return true;
    }
    
    bool Twindows_window::createWindow() {
        RECT windowRect = getRect(mWidth, mHeight);

        DWORD style = ( WS_OVERLAPPED  |
                        WS_CAPTION     |
                        WS_SYSMENU     |
                        WS_MINIMIZEBOX |
                        WS_MAXIMIZEBOX |
                        WS_THICKFRAME ); // dla zmiany rozmiaru okna

        AdjustWindowRectEx(&windowRect, style, false, 0);

        mHwnd = CreateWindowEx(0, reinterpret_cast<LPCSTR>(mWinClassName.c_str()),
            reinterpret_cast<LPCSTR>(mTitle.c_str()), style, windowRect.left,
            windowRect.top, windowRect.right -
            windowRect.left, windowRect.bottom -
            windowRect.top, nullptr, nullptr,
            wndclass.hInstance, this);

        if (mHwnd == nullptr) {
            return false;
        }

        hdc = GetDC(mHwnd);
        
        showWindow();
        return true;
    }

    void Twindows_window::destroyWindow() {
        
    }

    RECT Twindows_window::getRect(int aWidth, int aHeight) {
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        RECT windowRect;
        BOOL res = SetRect(&windowRect,
            (screenWidth / 2) - (aWidth / 2),
            (screenHeight / 2) - (aHeight / 2),
            (screenWidth / 2) + (aWidth / 2),
            (screenHeight / 2) + (aHeight / 2));

        return windowRect;
    }

    void Twindows_window::showWindow() {
        ShowWindow(mHwnd, SW_SHOW);
    }

}