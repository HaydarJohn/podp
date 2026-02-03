#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "window.h"




int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    #endif

    Window* window = new Window(1920,1080,"Pong");


    

    while (!glfwWindowShouldClose(window->getCurrentWindowContext()))
    {
        


        glfwPollEvents();
        glfwSwapBuffers(window->getCurrentWindowContext());
    }
    
    glfwTerminate();
    return 0;
}