#pragma once

//#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"



namespace Tyr3D
{
	class Renderer
	{
	public:
		//shader?
		const void Draw(const VertexArray& va, const IndexBuffer& ib) const;
	};

}