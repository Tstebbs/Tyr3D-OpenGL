#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>  


namespace Tyr3D
{


	Camera::Camera(float fov, float aspectRatio, float near, float far)
	{
		projMatrix = glm::perspective(glm::radians(fov), aspectRatio, near, far);
	}

	Camera::~Camera()
	{

	}


	
	void Camera::setPosition(glm::vec3 pos)
	{
		viewMatrix = glm::lookAt(pos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		return viewMatrix;
	}

	glm::mat4 Camera::GetProjMatrix()
	{
		return projMatrix;
	}

	


}
