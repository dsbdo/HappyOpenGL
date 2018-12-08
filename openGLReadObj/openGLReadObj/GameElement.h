#pragma once
#include <GLEW/glew.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Texture.h"
#include "Shader.h"
namespace lmm {
	class GameElement
	{
	public:
		GameElement();
		~GameElement();
		glm::vec2 position_;
		GLuint VAO_;
		virtual void draw(glm::vec2 size, GLfloat rotate, glm::vec3 color) = 0 ;
		virtual void move() {};
		virtual void reset() {};
		virtual void initRenderData()=0;
	};
}//namespace lmm over


