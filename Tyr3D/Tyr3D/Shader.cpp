#include "Shader.h"


namespace Tyr3D
{
	Shader::Shader(const std::string& filepath)
		: memFilepath(filepath), rendererID(0)
	{
		//CompShader();
	}
	Shader::~Shader()
	{
	}


	void Bind()
	{

	}

	void Unbind()
	{

	}

	void Shader::SetUniform4f(std::string& name, glm::vec4 vec4)
	{
	}

	unsigned int Shader::GetUniformLoc(const std::string& name)
	{
		return 0;
	}
	
	//complies vertex and fragment shader attaches it to a program and returns it 
	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragShader)
	{
		unsigned int prog = glCreateProgram();
		GLuint vertShad= CompShader(GL_VERTEX_SHADER, vertexShader);
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