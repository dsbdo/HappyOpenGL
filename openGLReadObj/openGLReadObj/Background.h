#pragma once
#include<GLEW/glew.h>
#include "GameElement.h"
#include "Texture.h"
namespace lmm {
	class Background : public GameElement
	{
	public:
		Background();
		Background(glm::vec2 pos, Texture texture);
		~Background();
		virtual void initRenderData();
	private:
		Texture texture_;
		const GLfloat vertices_[20] = {
			-1.0f, -1.0f, 0.0f,     0.0f, 0.0f,
			1.0f, -1.0f, 0.0f,       0.0f, 0.0f,
			1.0f, 1.0f, 10.0f,		0.0f, 0.0f,
			-1.0f, 1.0f, 10.0f,		0.0f, 0.0f
		};
		const GLuint vertex_index_[6] = {
			1,2,3,
			3,4,1
		};

	};

}//namespace lmm over

