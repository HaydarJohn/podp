#include <GLFW/glfw3.h>
#include "window.h"
#include "engine.h"



Engine::Engine()
{
    this->m_init();
    this->window = new Window(1920,1090,"Pong");
}

Engine::~Engine()
{
    delete this->window;
    glfwTerminate();
}
void Engine::m_init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    #endif
}

void Engine::run()
{
    while (!glfwWindowShouldClose(this->window->getCurrentWindowContext()))
    {

        glfwPollEvents();
        glfwSwapBuffers(window->getCurrentWindowContext());
    }
    
}