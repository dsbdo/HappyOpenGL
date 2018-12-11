#version 330 core
layout (location = 0) in vec3 vertex_;
layout (location = 1) in vec2 texcoord_;

out vec2 out_texcoord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	out_texcoord = texcoord_;
	gl_Position =  projection * view * model * vec4(vertex_, 1.0);
}