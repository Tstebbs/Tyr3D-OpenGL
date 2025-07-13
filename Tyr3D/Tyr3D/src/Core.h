#pragma once
#include <glad/glad.h> 

struct GLFWwindow;

namespace Tyr3D
{
	class Core 
	{
	public:

		Core();
		~Core();
		// must be public
		void CreateWindow(int width, int height, const char* name);
		void Run();
		
	private:
		float CalcDelta();
		float lastFrameTime;
		GLFWwindow* window;
		float dt;
	};
}