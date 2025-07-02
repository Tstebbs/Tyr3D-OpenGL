#include "IndexBuffer.h"
#include "Renderer.h"

namespace Tyr3D
{
	IndexBuffer::IndexBuffer(const void* data, unsigned int count)
	{
		iCount = count;
		glGenBuffers(1, &rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(GLuint),data,GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
	}

	void IndexBuffer::Unbind() const
	{
		(GL_ARRAY_BUFFER, rendererID);
	}

	unsigned int IndexBuffer::GetCount() const
	{
		return iCount;
	}
}