#pragma once
#include <memory>

namespace Tyr3D
{
	class GameObject;

	class Component
	{
	public:
		Component() {};
		virtual void Start();
		virtual void Update(float dt);


		
	protected:
		GameObject* owner;

	};

}
