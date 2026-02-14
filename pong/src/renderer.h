#pragma once

class Window;

class Renderer
{
public:
    virtual ~Renderer() = default;
    virtual void init(Window* window) = 0;
    virtual void clearColor() = 0;
    virtual void drawMesh(/* Mesh data */) = 0;
    virtual void present() = 0; // Swap buffers)
};