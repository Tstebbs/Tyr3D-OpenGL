#include "VertexArray.h"
#include "Renderer.h"
#include <glad/glad.h>


namespace Tyr3D
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &rendererID);
	}

	VertexArray::~VertexArray()
	{

	}

	void VertexArray::addVBuffer(const VertexBuffer& vbuff, const VBufferLayout& layout)
	{
		bind();
		vbuff.Bind();
		const auto& elements = layout.GetElements();
		unsigned int offset = 0;

		for (int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.count, element.type, element.isnormalised, layout.GetStride(), (const void*)(offset));
			offset += element.count * 4;
		}

	}
	void VertexArray::bind() const
	{
		glBindVertexArray(rendererID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
}