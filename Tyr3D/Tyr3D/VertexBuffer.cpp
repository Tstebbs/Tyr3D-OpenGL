#include "VertexBuffer.h"
#include "Renderer.h"

namespace Tyr3D
{
	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		glGenBuffers(1, &rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
	}

	void VertexBuffer::Unbind() const
	{
		//(GL_ARRAY_BUFFER, rendererID);
	}
}