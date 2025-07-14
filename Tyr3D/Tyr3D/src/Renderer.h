#pragma once

//#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "RenderComponent.h"
#include"Component.h"
#include "GameObject.h"
#include <vector>

namespace Tyr3D
{
	class Renderer
	{
	public:
		void DrawAll();

		void AddComponents(RenderComponent* rComp);
		void RemoveComponents(RenderComponent* rComp);

	private:
		std::vector<RenderComponent*> components;
	};
	extern Renderer renderer;
}