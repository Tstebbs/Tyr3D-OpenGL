#include "TransformComponent.h"
#include "GameObject.h"

#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/quaternion.hpp> 


namespace Tyr3D
{
	void TransformComponent::Start()
	{
		
	}

	void TransformComponent::Update(float dt)
	{

	}


	const glm::vec3 TransformComponent::GetPosition()
	{
		return position;
	}

	void TransformComponent::SetPosition(glm::vec3 pos)
	{
		position = pos;
	}

	const glm::vec3 TransformComponent::GetRotation()
	{
		return rotation;
	}

	void TransformComponent::SetRotation(glm::vec3 rotate)
	{
		rotation = rotate;
	}

	const glm::vec3 TransformComponent::GetScale()
	{
		return scale;
	}

	void TransformComponent::SetScale(glm::vec3 scalefactor)
	{
		scale = scalefactor;
	}

	const glm::mat4 TransformComponent::GetTransformationMatrix()
	{
		//takes identity matrix and multiplies by translation,rotation and scale

		glm::mat4 Object = glm::translate(glm::mat4(1.0f), position);
		Object *= glm::mat4_cast(glm::quat(rotation));
		Object = glm::scale(Object, scale);
		return Object;
	}
}