#pragma once



namespace Tyr3D
{
	class Renderer
	{
	public:
		//shader?

		const void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	};

}