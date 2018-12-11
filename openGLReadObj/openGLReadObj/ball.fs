#version 330 core

in vec2 out_texcoord;
uniform sampler2D image;
out vec4 color;
void main() {
	color = vec4(1.0, 1.0, 1.0, 1.0) * texture(image, out_texcoord);
	//color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}