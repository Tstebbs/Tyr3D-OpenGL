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
		if constexpr (std::is_same_v <T, float>)
		{
			memElements.emplace_back(GL_FLOAT,count,GL_FALSE);
			stride += sizeof(GLfloat);
		}
		else if constexpr (std::is_same_v<T, unsigned int>)
		{
			memElements.emplace_back(GL_UNSIGNED_INT, count, GL_FALSE);
			stride += sizeof(GLuint);
		}
		else
		{
			return;
		}
	}

	unsigned int VBufferLayout::GetStride() const
	{
		return stride;
	}



	std::vector<VBufferElement> VBufferLayout::GetElements() const
	{
		return memElements;
	}

	template void VBufferLayout::Push<float>(int);
	template void VBufferLayout::Push<unsigned int>(int);
	
	VBufferElement::VBufferElement(unsigned int type, unsigned int count, bool isnormalised)
	{

	}

}

