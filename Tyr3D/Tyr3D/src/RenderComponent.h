#pragma once
#include "Component.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VBufferLayout.h"
#include "Shader.h"


namespace Tyr3D
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent(const float* verts, unsigned int vertSize, const unsigned int* indices, unsigned int idxCount);
		~RenderComponent();


		void Draw();
		void Start();
		void Update(float dt);


	private:
		VertexArray memVArray;
		VertexBuffer memVBuff;
		IndexBuffer memIBuff;
		VBufferLayout memVBLayout;
		Shader shader;

	};
}

