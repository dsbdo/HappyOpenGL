#pragma once
#include <GLEW/glew.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace lmm {
	class GameElement
	{
	public:
		GameElement();
		~GameElement();
		glm::vec2 position_;
		GLuint VAO_;
		virtual void draw();
		virtual void move();
		virtual void reset();
		virtual void initRenderData();
	};
}//namespace lmm over


