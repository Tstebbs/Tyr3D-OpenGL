#include "TransformComponent.h"
#include "GameObject.h"


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
}