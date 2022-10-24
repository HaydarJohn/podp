#include<iostream>
#include"glad/glad.h"
#include<GLFW/glfw3.h>


int main()
{
	if(!glfwInit())
		std::cout<<"GLFW can not initialized."<<std::endl;

	GLFWwindow* window = glfwCreateWindow(720,640,"Pass Out Day Project",NULL,NULL);
	if(!window)
		std::cout<<"Window could not created."<<std::endl;

	while(!glfwWindowShouldClose(window))
	{

	}
	glfwDestroyWindow(window);
	
	glfwTerminate();
}
