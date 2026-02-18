#pragma once

// WARNING: Always include glad before glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include "eventHandler.h"


class Window
{
private:
    GLFWwindow* window;
    glm::uvec2* resolution;
    const char* title;
public:
    Window(int width,int height,const char* title);
    ~Window();

    /*  @brief sets resolution of the game window.
    * 
    *   @return true if unsuccessfull and does nothing. false when changed.
    *
    */
    bool setResolution(int width,int height);
    
    glm::uvec2 getResolution();

    GLFWwindow* getCurrentWindowContext();

    static void framebufferSizeCallback(GLFWwindow* window,int width,int height);

    
};
