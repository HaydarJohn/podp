#pragma once

class Window;

class Engine
{
private:
    /* data */
    Window* window;

public:
    Engine(/* args */);
    ~Engine();

    void run();
};


