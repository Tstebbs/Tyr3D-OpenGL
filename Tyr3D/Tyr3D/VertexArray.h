#pragma once
#include "VertexBuffer.h"
#include "VBufferLayout.h"


namespace Tyr3D
{
	class VertexArray
	{
	private:

	public:
		VertexArray();
		~VertexArray();

		void addVBuffer(const VertexBuffer& vbuff, const VBufferLayout& layout);
	 
	};

}