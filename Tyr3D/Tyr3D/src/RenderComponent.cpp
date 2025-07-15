#include "RenderComponent.h"
#include "Renderer.h"
#include <string>
#include "Camera.h"

namespace Tyr3D
{
	Camera cam(45.0f, 1000 / (float)500, 0.1f, 100.0f);
	

	RenderComponent::RenderComponent(const float* verts, unsigned int vertSize,const unsigned int* indices, unsigned int idxCount)
		:memVBuff(verts, vertSize),//as contructors have parameters they need to be initiliazed here
		memIBuff(indices, idxCount),
		shader("Assets/Shaders/vertexShader.shader",
			"Assets/Shaders/fragmentShader.shader")
	{
		memVArray.bind();
		
		cam.setPosition({ 4,0,5 });
		
		memVBLayout.Push<float>(3);//vert pos
		memVBLayout.Push<float>(2);//UV

		memVBuff.Bind();
		memVArray.addVBuffer(memVBuff, memVBLayout);
		
		memIBuff.Bind();
		memVArray.unbind();
	}


	RenderComponent::~RenderComponent()
	{

	}

	/*void RenderComponent::Start()
	{

	}

	void RenderComponent::Update(float dt)
	{

	}*/

	void RenderComponent::Draw()
	{
		shader.Bind();
		shader.SetUniform4f("u_colour", 0.2, 0.2, 0, 1);
		shader.SetUniformMat4("u_View", cam.GetViewMatrix());
		shader.SetUniformMat4("u_Proj", cam.GetProjMatrix());
		//shader.SetUniformMat4("u_trans", GameObject);

		memVArray.bind();
		memIBuff.Bind();

		glDisable(GL_BLEND);
	
		glDrawElements(GL_TRIANGLES, memIBuff.GetCount(), GL_UNSIGNED_INT, nullptr);
		memVArray.unbind();
	}

}