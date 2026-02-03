#include <iostream>
#include "window.h"



Window::Window(int width,int height,const char* title)
{
    this->title = title;
    this->resolution = new glm::uvec2();
    setResolution(width,height);
    this->window = glfwCreateWindow(this->resolution->x,this->resolution->y,this->title,NULL,NULL);
    // TODO: Do a proper error logger and EventHandler
    if(this->window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);

     // TODO: Do a proper error logger and handler
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Window::~Window()
{
    delete this->resolution;
    glfwDestroyWindow(this->window);
}

bool Window::setResolution(int width,int height)
{
    if(width<160 || height < 120) // QQVGA  Resolution. Could not find smaller standart
    {
        // TODO: ERROR: Log and Inform the programmer.
        std::exit(EXIT_FAILURE);
    }

    this->resolution->x = width;
    this->resolution->y = height;
    return false;
}

glm::uvec2 Window::getResolution()
{
    return *(this->resolution);
}

GLFWwindow* Window::getCurrentWindowContext()
{
    return this->window;
}

void Window::framebufferSizeCallback(GLFWwindow* window,int width,int height)
{
    glViewport(0, 0, width, height);
}