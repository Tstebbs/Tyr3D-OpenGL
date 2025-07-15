#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Tyr3D
{
	Core::Core()
	{
		lastFrameTime = 0.0f;
		dt = 0.0f;
		window=nullptr;
		
	}

	Core::~Core()
	{

	}

	void Core::CreateWindow(int width, int height, const char* name)
	{
		glfwInit();
		glfwSetTime(0.0);

		window = glfwCreateWindow(1240, 1000, name, NULL, NULL);
		
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

		glClearColor(0.3f, 0.4f, 0.8f, 1.0f);


	}

	void Core::Run()
	{
		//CreateWindow(800, 600, "Game");
		
		while (!glfwWindowShouldClose(window))
		{
			dt = CalcDelta();
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			renderer.DrawAll();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
	}


	float Core::CalcDelta()
	{
		float currTime = glfwGetTime();
		float dt = currTime - lastFrameTime;
		lastFrameTime = currTime;
		return dt;
	}

}

