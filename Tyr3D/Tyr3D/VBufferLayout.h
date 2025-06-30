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
		unsigned int stride;
		bool isnormalised;
	};


	class VBufferLayout
	{
	private:
		std::vector<VBufferElement> memElements;


	public:
		VBufferLayout();

	};

}