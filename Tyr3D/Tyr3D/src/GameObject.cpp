#include "GameObject.h"
#include "Component.h"


namespace Tyr3D
{
	GameObject::GameObject()
	{

	}
	void GameObject::Start()
	{
		for (auto& component : memberComponents)
		{
			component->Start();
		}
	}
	void GameObject::Update(float dt)
	{
		for (auto& component : memberComponents) 
		{
			component->Update(dt);
		}
	}

	
	

}