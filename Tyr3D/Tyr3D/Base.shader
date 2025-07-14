
#shader vertex
#version 330 core
layout (location = 0) in vec4 Pos;
  
out vec4 vertexColour; // specify a color output to the fragment shader

void main()
{
    gl_Position = vec4(Pos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColour = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
};


#shader fragment
#version 330 core

layout (location = 0) in vec4 colour;

void main()
{
    colour=vec4(1.0,0.0,0.0,1.0);
};
