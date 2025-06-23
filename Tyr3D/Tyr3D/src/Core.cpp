#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core.h"
#include <iostream>

namespace Tyr3D
{
	void Core::CreateWindow(int width, int height)
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(1240, 1000, "My Title", NULL, NULL);

		if (window == NULL)
		{
			std::cout << "Window Failed";
			glfwTerminate();
			return;
			
		}
		
		glfwMakeContextCurrent(window);

		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "ERROR: gladLoadGLLoader failed\n";
			return;
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		return;
	}
}

