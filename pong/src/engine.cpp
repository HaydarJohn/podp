#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "engine.h"



Engine::Engine()
{
    this->window = new Window(1920,1090,"Pong");
}

Engine::~Engine()
{
    delete this->window;
    glfwTerminate();
}

void Engine::run()
{
    while (!glfwWindowShouldClose(this->window->getCurrentWindowContext()))
    {

        glfwPollEvents();
        glfwSwapBuffers(window->getCurrentWindowContext());
    }
    
}