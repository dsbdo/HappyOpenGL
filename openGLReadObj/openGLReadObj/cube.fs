#version 330 core
in vec2 texture_coordinate;
out vec4 color;
uniform sampler2D image_2;

void main() {
	
	color = vec4(1.0, 1.0, 1.0, 1.0) * texture(image_2, texture_coordinate);

}