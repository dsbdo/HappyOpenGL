#version 330 core
layout (location = 0) in vec3 vertex_;
layout (location = 1) in vec2 texture_coordinate_;

//out vec2 texture_coordinate;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	//texture_coordinate = texture_coordinate_;
	gl_Position =  projection * view * model * vec4(vertex_, 1.0);
	//gl_Position = vec4(vertex_.x, vertex_.y, vertex_.z, 1.0);
}