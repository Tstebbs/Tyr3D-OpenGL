#pragma once
#include "Component.h"
#include <glm/glm.hpp> 

namespace Tyr3D
{
	class TransformComponent: public Component
	{
	public:
		TransformComponent();
		~TransformComponent();

		virtual void Start();
		virtual void Update(float dt);

		const glm::vec3 GetPosition();
		void SetPosition(glm::vec3 pos);

		const glm::vec3 GetRotation();
		void SetRotation(glm::vec3 rotation);

		const glm::vec3 GetScale();
		void SetScale(glm::vec3 scale);

	protected:
		glm::vec3 position{ 0.0f, 0.0f, 0.0f };
		glm::vec3 rotation{ 0.0f, 0.0f, 0.0f }; 
		glm::vec3 scale{ 1.0f, 1.0f, 1.0f };
	};

}

