#include "window.h"
#include "windowSDL.h"
#include <SDL3/SDL.h>
#include <iostream>




SDLWindowAdapter::~SDLWindowAdapter()
{
    if(m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

bool SDLWindowAdapter::initialize(int width, int height, const char* title)
{
    // Initialize Video Subsystem
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL3 Init Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // SDL3 creates windows centered by default if no flags override it.
    // We include SDL_WINDOW_VULKAN to ensure the surface is compatible.
    m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    
    if (!m_window) {
        std::cerr << "Window Creation Failed: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}





// TODO: handle events
void SDLWindowAdapter::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
        }
        // Future: Dispatch events to an Input Manager here
    }
}

void* SDLWindowAdapter::getNativeWindowHandle() {
    if (!m_window) return nullptr;

    // The New SDL3 Way: Access the property dictionary for the window
    SDL_PropertiesID props = SDL_GetWindowProperties(m_window);

    // --- Windows Implementation ---
    #if defined(_WIN32)
        return (void*)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);

    // --- macOS Implementation ---
    #elif defined(__APPLE__)
        return (void*)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, nullptr);

    // --- Linux Implementation (Wayland/X11) ---
    #elif defined(__linux__)
        // Try Wayland first
        void* waylandSurface = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, nullptr);
        if (waylandSurface) return waylandSurface;

        // Fallback to X11 (Note: XID is an integer, so we cast it to void*)
        uint64_t xwindow = SDL_GetNumberProperty(props, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
        return (void*)(uintptr_t)xwindow;
    #endif

    return nullptr;
}