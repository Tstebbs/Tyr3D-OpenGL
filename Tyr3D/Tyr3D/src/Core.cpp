#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Tyr3D
{
	
		float lastFrameTime = 0.0;
		GLFWwindow* window;
		float dt;

		void Core::CreateWindow(int width, int height, const char* name)
		{
			glfwInit();
			glfwSetTime(0.0);

			window = glfwCreateWindow(1240, 1000, name, NULL, NULL);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.3f, 0.4f, 0.8f, 1.0f);
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



			glfwDestroyWindow(window);
			glfwTerminate();
			return;
		}

		void Core::Run()
		{
			dt = CalcDelta();
			while (!glfwWindowShouldClose(window))
			{
	
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
		}


		float Core::CalcDelta()
		{
			float currTime = glfwGetTime();
			float dt = currTime - lastFrameTime;
			lastFrameTime = currTime;
			return dt;
		}

}

