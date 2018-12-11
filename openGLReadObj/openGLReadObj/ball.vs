#version 330 core
layout (location = 0) in vec3 vertex_;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	gl_Position =  projection * view * model * vec4(vertex_, 1.0);
}