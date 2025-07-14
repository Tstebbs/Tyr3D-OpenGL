#include "Shader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <glm/glm.hpp>


namespace Tyr3D
{
	Shader::Shader(const std::string& filepathvs,const std::string& filepathfrag)
		: rendererID(0)
	{
		std::string vertShad = ReadShader("res/Shaders/vertexShader.vs");
		std::string fragShad = ReadShader("res/Shaders/fragmentShader.frag");
		rendererID  = CreateShader(vertShad, fragShad);
		
	}
	Shader::~Shader()
	{
		glDeleteProgram(rendererID);
	}


	void Shader::Bind() const
	{
		glUseProgram(rendererID);
	}

	void Shader::Unbind() const
	{

	}

	void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) const
	{
		glUniform4f(GetUniformLoc(name), v1, v2, v3, v4);
	}

	int Shader::GetUniformLoc(const std::string& name) const
	{
		int loc = glGetUniformLocation(rendererID, name.c_str());
		return loc;
	}
	

	std::string Shader::ReadShader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		std::string   line;
		std::string   shader;

		//loops through lines in shader adding them to a string
		while (std::getline(stream, line))
		{
			shader += line + "\n";
		}
	
		return shader;
	}

	//complies vertex and fragment shader attaches it to a program and returns it 
	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragShader)
	{
		unsigned int prog = glCreateProgram();
		unsigned int vertShad= CompShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fragShad = CompShader(GL_FRAGMENT_SHADER, fragShader);
		
		//attach shaders to program
		glAttachShader(prog, vertShad);
		glAttachShader(prog, fragShad);
#
		//links program
		glLinkProgram(prog);

		glDeleteShader(vertShad);
		glDeleteShader(fragShad);

		return prog;
	}

	unsigned int Shader::CompShader(unsigned int type, const std::string& src)
	{ 
		unsigned int id = glCreateShader(type);

		//pointer to string 
		const char* source = src.c_str();
		glShaderSource(id, 1, &source, NULL);
		glCompileShader(id);

		return id;
		
	}
}