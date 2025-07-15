#include "RenderComponent.h"
#include "Renderer.h"
#include <string>

namespace Tyr3D
{
	

	RenderComponent::RenderComponent(const float* verts, unsigned int vertSize,const unsigned int* indices, unsigned int idxCount)
		:memVBuff(verts, vertSize),//as contructors have parameters they need to be initiliazed here
		memIBuff(indices, idxCount),
		shader("res/Shaders/vertexShader.vs",
			"res/Shaders/fragmentShader.frag")
	{
		memVArray.bind();
		
		memVBLayout.Push<float>(3);//vert pos
		memVBLayout.Push<float>(2);//UV

		memVBuff.Bind();
		memVArray.addVBuffer(memVBuff, memVBLayout);
		
		memIBuff.Bind();
		shader.Bind();
		shader.SetUniform4f("u_Color", 1, 0, 0, 1);
		memVArray.unbind();
	}


	RenderComponent::~RenderComponent()
	{

	}

	void RenderComponent::Start()
	{

	}

	void RenderComponent::Update(float dt)
	{

	}

	void RenderComponent::Draw()
	{
		
		memVArray.bind();
		memIBuff.Bind();
		shader.Bind();
		glDrawElements(GL_TRIANGLES, memIBuff.GetCount(), GL_UNSIGNED_INT, nullptr);
		memVArray.unbind();
	}

}