#include "Renderer.h"


namespace Tyr3D
{
	const void Draw(const VertexArray& va, const IndexBuffer& ib)
	{
		va.bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}