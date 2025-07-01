#include "VertexArray.h"
#include "Renderer.h"

Tyr3D::VertexArray::VertexArray()
{

}

Tyr3D::VertexArray::~VertexArray()
{

}

void Tyr3D::VertexArray::addVBuffer(const VertexBuffer& vbuff, const VBufferLayout& layout)
{
	vbuff.Bind();
	const auto& elements = layout.GetElements();

	for (int i=0; i<elements.size();i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(0, element.count, element.type, element.isnormalised, sizeof(float) * 3, 0);
	}
	
}
