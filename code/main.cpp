#include <window/windows_window.hpp>

int main(int argc, char const *argv[]) {
    
    gooapi::win::Tiwindow* win = new gooapi::win::Twindows_window(800, 600, "Nice Window");
    win->windowSetup();

    while (!win->shouldQuit()) {
        // Process Input
        win->pollEvents();

        // Update game
        
        // Render
    }

    delete win;
    return 0;
}
