#include "eventHandler.h"
#include "window.h"



Window::Window(int width,int height,const char* title)
{
    this->EventHandler = this->EventHandler->getInstance();
    this->title = title;
    this->resolution = new glm::uvec2();
    setResolution(width,height);
    this->window = glfwCreateWindow(this->resolution->x,this->resolution->y,this->title,NULL,NULL);
    // TODO: Do a proper error logger and EventHandler
    if(this->window == NULL)
    {
        EventHandler->pushEvent(ERROR,"could not create window!");
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);

    // I asked gemini if i had to get opengl functions every time i made a new GLFW window and it said yes because without
    // Context(window) it can not get pointers so i will get glad functions every time i make new window object
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        EventHandler->pushEvent(ERROR,"Failed to get opengl functions(glad)");
        return;
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
        EventHandler->pushEvent(ERROR,"Too litle resolution");
        return true;
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