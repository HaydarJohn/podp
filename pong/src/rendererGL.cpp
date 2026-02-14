#include "renderer.h"
#include <glad/glad.h>

class OpenGLRendererAdapter : public Renderer {
public:
    void init(Window* window) override {
        // Here you would create the OpenGL Context using the window handle
        // Note: Usually SDL/SFML handles context creation easier than raw handle,
        // but for pure abstraction, you might attach context to the native handle here.
        
        // Setup GL state
        glEnable(GL_DEPTH_TEST);
    }

    void clearColor(/*float r, float g, float b, float a*/) override {
        //glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void drawMesh() override {
        // glDrawElements(...);
    }

    void present() override {
        // Context swap buffers logic
    }
};