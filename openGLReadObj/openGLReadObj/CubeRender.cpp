#include "CubeRender.h"

namespace lmm {
	CubeRender::CubeRender()
	{

	}

	CubeRender::CubeRender(glm::vec3 pos, Shader shader, Texture texture)
		:position_(pos), shader_(shader), texture_(texture)
	{
		this->initRenderData();
	}


	CubeRender::~CubeRender()
	{

	}
	void CubeRender::initRenderData() {
		GLuint VBO;
		glGenVertexArrays(1, &this->VAO_);

		glGenBuffers(1, &VBO);
//		glGenBuffers(1, &IBO);
		//bind VAO


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->cube_data_), this->cube_data_, GL_STATIC_DRAW);

		glBindVertexArray(this->VAO_);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertex_index_), this->vertex_index_, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		//这一种情况是允许解开绑定的，因为VAO在这里是记录glVertexAttribPointer 的记录情况
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用。这也意味着它也会储存解绑调用，所以确保你没有在解绑VAO之前解绑索引数组缓冲，否则它就没有这个EBO配置了。
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void CubeRender::draw(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec2 size, GLfloat rotate, glm::vec3 color) {
		this->shader_.use();
		this->shader_.setInt("image_2", 2);
		
		glActiveTexture(GL_TEXTURE2);
		this->texture_.bind();

		model = glm::translate(model, position_);
		this->shader_.setMat4("model", model);
		// pass transformation matrices to the shader
		this->shader_.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.

		this->shader_.setMat4("view", view);

		glBindVertexArray(this->VAO_);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0,  36);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}//namespace lmm over

