#version 330 core
layout (location = 0) in vec3 Pos;

uniform mat4 u_View;
uniform mat4 u_Proj;

out vec3 v_pos;

void main()
{
    gl_Position =  u_Proj* u_View*vec4(Pos, 1.0); 
   
}
