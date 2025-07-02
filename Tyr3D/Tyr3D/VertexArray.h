#pragma once
#include "VertexBuffer.h"
#include "VBufferLayout.h"


namespace Tyr3D
{
	class VertexArray
	{
	private:
		unsigned int rendererID;
	public:
		VertexArray();
		~VertexArray();

		void addVBuffer(const VertexBuffer& vbuff, const VBufferLayout& layout);
		void bind() const;
			void unbind() const;
	};

}