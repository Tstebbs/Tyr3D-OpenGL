#pragma once
#include <iostream>
#include <glad/glad.h> 
#include"glm/glm.hpp"



namespace Tyr3D
{
	class Shader
	{
	public:
		Shader(const std::string& filepathvs,const std::string& filepathfrag);
		~Shader(); 
	
		void Bind() const;
		void Unbind() const;

		void SetUniform4f(const std::string& name, float v1,float v2,float v3, float v4) const;
		void SetUniformMat4(const std::string& name, glm::mat4 matrix) const;

	private:
		unsigned int rendererID;
		std::string memFilepath;
		int GetUniformLoc(const std::string& name) const;
	
		std::string ReadShader(const std::string& filepath);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragShader);
		unsigned int CompShader(unsigned int type, const std::string& src);

		
		//caching?
	};

}