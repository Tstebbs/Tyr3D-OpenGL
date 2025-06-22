#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core.h"

namespace Tyr3D
{


	void Core::CreateWindow(int width, int height)
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	}
}

