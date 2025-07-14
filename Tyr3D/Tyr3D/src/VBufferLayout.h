#pragma once

#include<iostream>
#include<vector>
#include<glad/glad.h>



namespace Tyr3D
{
	struct VBufferElement
	{
		unsigned int type;
		unsigned int count;
		bool isnormalised;

		static unsigned int getSizeofType()
		{
			//for now no change in types size as char not supported
			return 4;
		}
		
		VBufferElement(unsigned int type,unsigned int count, bool isnormalised);
	};


	class VBufferLayout
	{
	private:
		std::vector<VBufferElement> memElements;
		unsigned int stride;

	public:
		VBufferLayout();

		//checks at compile time type of added elements if they are supported they are pushed
		template<typename T>
		void Push(int count);


		std::vector<VBufferElement> GetElements() const;
		unsigned int GetStride() const;

	};

}