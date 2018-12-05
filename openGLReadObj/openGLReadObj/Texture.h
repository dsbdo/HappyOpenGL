#pragma once
#include <iostream>
#include <string>
#include <GLEW/glew.h>
namespace lmm {
	class Texture
	{
	public:
		Texture();
		~Texture();
		GLuint texture_id_;
		GLuint width_, height_, channels_;

		//texture format
		GLuint internal_format_;
		GLuint image_formal_;
		//texture configure
		GLuint wrap_s_;
		GLuint wrap_t_;
		GLuint filter_min_;
		GLuint filter_max_;

		void generate(std::string path);
		//bind to the texture to the current GL_TEXTURE_2D
		void bind()const;
	private:
		unsigned char* readImage(std::string path);

	};

}

