#pragma once
#include "Component.h"



namespace Tyr3D
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent();
		~RenderComponent();

		virtual void Start();
		virtual void Update(float dt);





	};
}

