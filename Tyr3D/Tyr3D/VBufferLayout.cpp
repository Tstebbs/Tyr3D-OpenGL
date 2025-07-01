#include "VBufferLayout.h"



namespace Tyr3D
{
	VBufferLayout::VBufferLayout()
	{
		stride = 0;
	}


	template<typename T>
	void VBufferLayout::Push(int count)
	{
		if constexpr (std::is_same_v <T, GL_FLOAT>)
		{
			memElements.emplace_back(GL_FLOAT,count,false);
			stride += sizeof(GLfloat);
		}
		else if constexpr (std::is_same_v<T, GL_UNSIGNED_INT>)
		{
			memElements.emplace_back(GL_UNSIGNED_INT, count, false);
			stride += sizeof(GLuint);
		}
		else
		{
			return;
		}
	}


	std::vector<VBufferElement> VBufferLayout::GetElements() const
	{
		return memElements;
	}

	unsigned int VBufferLayout::GetStride() const
	{
		return stride;
	}

}