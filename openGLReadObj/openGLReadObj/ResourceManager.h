#pragma once
#include <map>
#include <string>

#include <GLEW/glew.h>

#include "Texture.h"
#include "Shader.h"

namespace lmm {
	class ResourceManager
	{
	public:

		ResourceManager();
		~ResourceManager();
		static std::map<std::string, Shader>    Shaders;
		static std::map<std::string, Texture> Textures;

		static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
		// Retrieves a stored sader
		static Shader   GetShader(std::string name);

		static Texture LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
		// Retrieves a stored texture
		static Texture GetTexture(std::string name);

		static void  Clear();

	};


} // namespace lmm over
