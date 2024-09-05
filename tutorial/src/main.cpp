#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    // Initilize glfw , pick opengl version 3.3 and set opengl profile to core
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__  // Apple is retarded.
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


    // Create glfw window if failed scream and close and if succesfull make window current
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    /*
        Until now all operations for creating window is OS specific.
        I am not sure but we dont need opengl for just creating window and displaying it.
    */


    // I dont understad what black magic this shit do but I think we give glfw process retrieve fuction to glad as glad process loader.
    // This is what learnopengl.com says

    /*7*/

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // glViewport set location with first two parameters. (0,0) is left bottom. other two parameters are width and heigth
    glViewport(0, 0, 800, 600);


    // To understan what shenanigans going here please visit frame_size_callback function :)
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // Render loop
    while(!glfwWindowShouldClose(window))// glfwWindow should  close is self explanatory. it return true if glfw signals close

    {
        // To understan what shenanigans going here please visit processInput function :)
        processInput(window);

        //Render start


        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear all background to a color. For now 
        glClear(GL_COLOR_BUFFER_BIT);

        //Render end

        // i dont know what really glswapbuffers does. Furder research needed
        // i dont know what really glfwpollevents does. Furder reaseach needed.
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}







// In the website it says we shoul(must?) create a window resize function callback for when user wants to resize window
// and feed it to glfwSetFramebufferSizeCallback function with first parameter as our window and secon one our callback.
// i dont understand what is going on. resarch why we have to to this?
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Direct quote from website . still no idea what it does ?
    /*
        There are many callbacks functions we can set to register our own functions.
        For example, we can make a callback function to process joystick input changes, process error messages etc. 
        We register the callback functions after we've created the window and before the render loop is initiated. 
    */
    glViewport(0, 0, width, height);
}

// This is input handler for render loop. for now it only register escape to close app.
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}