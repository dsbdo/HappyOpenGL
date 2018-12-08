#version 330 core
in vec2 texture_coordinate;
out vec4 color;
uniform sampler2D image;

void main() {
	color = vec4(1.0, 1.0, 1.0, 1.0) * texture(image, texture_coordinate);
	//color  = vec4(0.8f,0.8f, 0.8f, 1.0f);
}