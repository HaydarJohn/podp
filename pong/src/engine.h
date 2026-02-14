#pragma once

class Window;
class Renderer;

class Engine
{
private:
    /* data */
    Window* window;
    Renderer* renderer;

public:
    Engine(/* args */);
    ~Engine();

    void run();
};


