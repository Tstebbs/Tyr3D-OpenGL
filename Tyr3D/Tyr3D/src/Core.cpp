#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Tyr3D
{
	void Core::CreateWindow(int width, int height, const char* name)
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(1240, 1000, name, NULL, NULL);

		if (window == NULL)
		{
			std::cout << "Window Failed";
			glfwTerminate();
			return;
		}
		
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "ERROR: gladLoadGLLoader failed\n";
			return;
		}

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.3f, 0.4f, 0.8f, 1.0f);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		
		

		glfwDestroyWindow(window);
		glfwTerminate();
		return;
	}



}

