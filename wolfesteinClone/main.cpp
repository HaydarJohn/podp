#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // GLFW WINDOW HINTS
    glfwWindowHint(GLFW_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Opening Window
    glfwInit();
    // FIXME: Can return NULL have an error check
    GLFWwindow* window = glfwCreateWindow(1920,1080,"WolfesteinClone",NULL,NULL);

    // Givimg GLFW window opengl Headers
    // FIXME: Can return NULL have an error check
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // MAIN LOOP
    while (true)
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}