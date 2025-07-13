#include "Renderer.h"


namespace Tyr3D
{
	
	void Renderer::DrawAll()
	{
		for (RenderComponent* rComp : components )
		{
			//loops through all render components drawing them
			rComp->Draw();
		}

	}

	void Renderer::AddComponents(RenderComponent* rComp)
	{
		components.push_back(rComp);//adds render components to vector
	}

	void Renderer::RemoveComponents(RenderComponent* rComp)
	{
		//TODO
	}
}