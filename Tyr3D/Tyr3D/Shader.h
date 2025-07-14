#pragma once
#include <iostream>
#include <glm/glm.hpp>

#include "src/Renderer.h"



namespace Tyr3D
{
	class Shader
	{
	public:
		Shader(const std::string& filepath);
		~Shader();
	
		void Bind() const;
		void Unbind() const;

		void SetUniform4f(std::string& name, glm::vec4 vec4);
	private:
		unsigned int rendererID;
		std::string memFilepath;
		unsigned int GetUniformLoc(const std::string& name);
	
		static void ParseShader(const std::string& filepath);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragShader);
		unsigned int CompShader(unsigned int type, const std::string& src);

		
		//caching?
	};

}