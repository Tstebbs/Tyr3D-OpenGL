#pragma once
#include "glm/glm.hpp"
#include "component.h"
#include "GameObject.h"         
#include "TransformComponent.h"

namespace Tyr3D
{
	class Camera: public Component
	{
	public:
		using Component::Component;

		Camera(float fov, float aspectRatio, float near, float far);
		~Camera();

		void setPosition(glm::vec3 pos);

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjMatrix();

		void Update(float dt) override
		{
			auto* cTransformPtr = owner->GetComponent<TransformComponent>();

			auto& cTransform = *cTransformPtr;

			glm::vec3 pos = cTransform.GetPosition();
		}

	private:
		glm::mat4 projMatrix;
		glm::mat4 viewMatrix;

		
		

	};

}