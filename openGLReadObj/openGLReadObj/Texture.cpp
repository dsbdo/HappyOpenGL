#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "LoadImage.h"


namespace lmm {
	Texture::Texture():width_(0), height_(0), internal_format_(GL_RGB), image_formal_(GL_RGB), wrap_s_(GL_REPEAT), wrap_t_(GL_REPEAT), filter_min_(GL_LINEAR), filter_max_(GL_LINEAR)
	{
		glGenTextures(1, &this->texture_id_);
	}


	Texture::~Texture()
	{
	}
	void Texture::generate(std::string path)
	{
		unsigned char* data = readImage(path);

		//create the texture
		glBindTexture(GL_TEXTURE_2D, this->texture_id_);
		glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format_, this->width_, this->height_, 0, this->image_formal_, GL_UNSIGNED_BYTE, data);
		//set para of the texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s_);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t_);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min_);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_max_);

		//unbind the texture
		glBindTexture(GL_TEXTURE_2D, 0);
		//free the memory
		stbi_image_free(data);
	}
	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, this->texture_id_);
	}
	unsigned char * Texture::readImage(std::string path)
	{
		int width, height, channels;
		//stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		this->width_ = width;
		this->height_ = height;
		this->channels_ = channels;


		if (data)
		{
			return data;
		}
		else
		{
			std::cout << "Failed to load texture from "<< path << " exit now"  << std::endl;
			exit(-1);
		}
	}
}

