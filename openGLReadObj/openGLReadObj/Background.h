#pragma once
#include<GLEW/glew.h>
#include "GameElement.h"
#include "Texture.h"
namespace lmm {
	class Background : public GameElement
	{
	public:
		Background();
		Background(glm::vec2 pos, Shader shader, Texture texture);
		~Background();
		virtual void initRenderData();
		virtual void draw(glm::vec2 size, GLfloat rotate, glm::vec3 color);
	private:
		glm::vec2 position_;
		Texture texture_;
		Shader shader_;

		const GLfloat vertices_[20] = {
			-0.5f, -1.0f, -0.5f,     0.0f, 0.0f,
			0.5f, -1.0f, -0.5f,       0.0f, 0.0f,
			0.5f, 0.5f, 0.5f,		0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f,		0.0f, 0.0f
		};
		const GLuint vertex_index_[6] = {
			0, 1, 2,
			2, 3, 0
		};


	};

}//namespace lmm over

