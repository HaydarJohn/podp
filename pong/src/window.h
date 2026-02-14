#pragma once

class Window
{
public:
    virtual ~Window() = default;


    virtual bool initialize(int width, int height, const char* title) = 0;
    virtual bool shouldClose() = 0;
    // This is destructor. Why make different one if you already have one?
    // you can control when to do with this. like AI says 
    // "In game engines, destruction order matters immensely. You might want to close the 
    // window before the engine shuts down the logger or the memory allocator. Relying solely
    // on C++ destructors (which fire automatically when an object goes out of scope) can sometimes
    // lead to crashes if dependencies are destroyed in the wrong order."
    virtual void shutdown() = 0;



    virtual void pollEvents() = 0;


    // This is needed if we want rederer agnostic
    // We will give this to renderer when it is neccesary
    // Ex: when not opengl
    // Even AI comments better explainer than i am
    // --------------------------
    // Getting the "Native" handle (Crucial for the Renderer!)
    // Returns void* because it could be HWND (Windows), NSWindow (Mac), or X11 (Linux)
    virtual void* getNativeWindowHandle() = 0;     
};


