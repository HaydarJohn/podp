#pragma once
#include "window.h"

struct SDL_Window;


class SDLWindowAdapter : public Window
{
private:
    SDL_Window* m_window = nullptr;
public:
    SDLWindowAdapter() = default;
    virtual ~SDLWindowAdapter() override;
    bool initialize(int width, int height, const char* title) override;
    void pollEvents() override;
    void* getNativeWindowHandle() override;
};