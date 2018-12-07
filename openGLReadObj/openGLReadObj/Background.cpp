#include "Background.h"

namespace lmm {
	Background::Background()
	{
	}


	Background::~Background()
	{
	}
	void Background::initRenderData() {
		GLuint VBO, IBO;
		glGenVertexArrays(1, &this->VAO_);
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices_), this->vertices_, GL_STATIC_DRAW);
		
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertex_index_), this->vertex_index_, GL_STATIC_DRAW);
		//bind VAO
		glBindVertexArray(this->VAO_);
		glVertexAttribPointer(0, 5, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		//release the buffer index
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}//namespace lmm over


