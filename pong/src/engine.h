#pragma once

class Window;

class Engine
{
private:
    /* data */
    Window* window;

    void m_init();
public:
    Engine(/* args */);
    ~Engine();

    void run();
};


