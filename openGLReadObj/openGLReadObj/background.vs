#version 330 core
layout (location = 0) in vec3 vertex_;
layout (location = 1) in vec2 texture_coordinate_;
layout (location = 2) in vec3 normal_;


out vec2 texture_coordinate;
out vec3 Normal;
out vec3 frag_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	texture_coordinate = texture_coordinate_;
	frag_pos = vec3(model * vec4(vertex_, 1.0));
	Normal =mat3(transpose(inverse(model))) * normal_;


	gl_Position =  projection * view * model * vec4(vertex_, 1.0);
	//gl_Position = vec4(vertex_.x, vertex_.y, vertex_.z, 1.0);
}