#include "engine.h"
#include "window.h"



Engine::Engine()
{
    //this->window = new Window(1920,1090,"Pong");
}

Engine::~Engine()
{
    
}

void Engine::run()
{
    while (!window->shouldClose())
    {
        //renderer
    }
    
}