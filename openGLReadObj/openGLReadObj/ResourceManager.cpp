#include "ResourceManager.h"
#include <iostream>
#include <sstream>
#include <fstream>


namespace lmm{
	std::map<std::string, Texture>    ResourceManager::Textures;
	std::map<std::string, Shader>       ResourceManager::Shaders;
	Shader ResourceManager::LoadShader(const GLchar * vShaderFile, const GLchar * fShaderFile, const GLchar * gShaderFile, std::string name)
	{
		Shader shader(vShaderFile, fShaderFile);
		Shaders[name] = shader;
		return Shaders[name];
	}
	Shader ResourceManager::GetShader(std::string name)
	{
		return Shaders[name];
	}
	Texture ResourceManager::LoadTexture(const GLchar * file, GLboolean alpha, std::string name)
	{
		Texture texture;
		//判断是否是透明通道
		if (alpha) {
			texture.internal_format_ = GL_RGB;
			texture.image_formal_ = GL_RGBA;
		}
		texture.generate(file);
		Textures[name] = texture;
		return Textures[name];
	}

	Texture ResourceManager::GetTexture(std::string name)
	{
		return Textures[name];
	}

	void ResourceManager::Clear()
	{
		for (auto iter : Shaders)
			glDeleteProgram(iter.second.ID);
		// (Properly) delete all textures
		for (auto iter : Textures)
			glDeleteTextures(1, &iter.second.texture_id_);
	}


	ResourceManager::ResourceManager()
	{
	}


	ResourceManager::~ResourceManager()
	{
	}

}


