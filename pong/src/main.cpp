#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "engine.h"



int main()
{
    
    
    Engine* engine = new Engine();

    engine->run();
    
    


    

    // while (!glfwWindowShouldClose(window->getCurrentWindowContext()))
    // {
        


    //     glfwPollEvents();
    //     glfwSwapBuffers(window->getCurrentWindowContext());
    // }
    
    // glfwTerminate();
    return 0;
}
