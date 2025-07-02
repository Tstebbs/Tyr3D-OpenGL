#pragma once

namespace Tyr3D
{
	class IndexBuffer
	{
	private:
		unsigned int rendererID;
		unsigned int iCount;
	public:
		IndexBuffer(const void* data, unsigned int iCount);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		unsigned int GetCount() const;
	};

}