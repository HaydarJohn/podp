#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <soloud.h>
#include <soloud_wav.h>
#include <iostream>
#include <random>
#include "main.h"
#include "utils.h"
#include "ball.h"
#include "paddle.h"





float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 2,   // first triangle
    1, 2, 3    // second triangle
};




int main()
{
    // Data Fields
    int windowHeight = 720 , windowWidth = 1280;
    const char* gameTitle = "Pong";


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    #endif

    GLFWwindow* window = glfwCreateWindow(windowWidth,windowHeight,gameTitle,NULL,NULL);

    // TODO: Do a proper error logger and handler
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);

    
    // TODO: Do a proper error logger and handler
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::string fileRead = getShaderSource("vertex");
    const char* vertexShaderSource = fileRead.c_str();
    std::string fileRead1 = getShaderSource("fragment");
    const char* fragmentShaderSource = fileRead1.c_str();

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW); 
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    
    
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << "start of infolog \n"<< infoLog << "end of infolog"<<std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << "start of infolog \n"<< infoLog << "end of infolog"<<std::endl;
    }


    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINK::LINKING_FAILED\n" << "start of infolog \n"<< infoLog << "end of infolog"<<std::endl;
    }

    // Initilize sound
    SoLoud::Soloud soloud;
    SoLoud::Wav music;
    SoLoud::Wav hit;
    soloud.init();

    music.load("assets/music.mp3");
    hit.load("assets/hit.mp3");

    music.setLooping(true);

    // Random Setup . Yoinked from stack overflow.
    std::random_device dev;
    std::mt19937 rnJesus(dev());
    std::uniform_real_distribution<float> randFloat(-1.0f,1.0f); // distribution in range [0, 1]

    // Set Input Function
        glfwSetKeyCallback(window, keyCallback);

    Paddle* left    = new Paddle(0,0.05f,0.3f);
    Paddle* right   = new Paddle(1,0.05f,0.3f);
    Ball* ball = new Ball(0.1);
    
    // Opengl Setup ? Still dont get it
    unsigned int VBO1[3];
    unsigned int VAO1[3];
    glGenBuffers(3, VBO1);
    glGenVertexArrays(3,VAO1);
    for (int i = 0; i < 3; i++)
    {
        glBindVertexArray(VAO1[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBO1[i]);  
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW); 
        glEnableVertexAttribArray(0);
    }

    
    soloud.playBackground(music);
    while (!glfwWindowShouldClose(window))
    {
        // Take input
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            left->y += 0.02;
            if((left->y + left->height/2)> 1) left->y = 1 - left->height/2;
        }
        else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            left->y -= 0.02;
            if(left->y -(left->height/2) < -1) left->y = -1+  left->height/2;
        }
        else;
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            right->y += 0.02;
            if((right->y + (right->height/2))> 1) right->y = 1 -(right->height/2);

        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            right->y -= 0.02;
            if(right->y -(right->height/2) < -1) right->y = -1+  right->height/2;
        }
        else;

        // Before Rendering Logic
        if(left->checkCollide(ball) || right->checkCollide(ball))
        {
            ball->vx *= -1.1f;
            ball->vy = ball->vx * randFloat(rnJesus);
            soloud.play(hit);
        }
        ball->update();
        // Rendering 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glUseProgram(shaderProgram);
        drawRect(ball->getIndecies() ,VBO1[0],VAO1[0]);
        drawRect(left->getIndecies() ,VBO1[1],VAO1[1]);
        drawRect(right->getIndecies(),VBO1[2],VAO1[2]);
        // std::cout<<"A new Frame\n";

        // glBindVertexArray(VAO);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);

        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
    glfwTerminate();
    return 0;
}


void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void drawRect(float* rect,unsigned int VBO,unsigned int VAO)
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12, rect, GL_DYNAMIC_DRAW);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE); // Close on Escape
    }
}