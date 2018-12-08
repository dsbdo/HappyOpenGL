#include "Background.h"

namespace lmm {
	Background::Background()
	{
	}

	Background::Background(glm::vec2 pos, Shader shader, Texture texture):position_(pos), shader_(shader), texture_(texture)
	{
		this->initRenderData();
	}


	Background::~Background()
	{
	}

	void Background::initRenderData() {
		GLuint VBO, IBO;

		glGenVertexArrays(1, &this->VAO_);

		glGenBuffers(1, &VBO);
		glGenBuffers(1, &IBO);
		//bind VAO
		glBindVertexArray(this->VAO_);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices_), this->vertices_, GL_STATIC_DRAW);
		

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertex_index_), this->vertex_index_, GL_STATIC_DRAW);
	
	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)3);
		//glEnableVertexAttribArray(1);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		//这一种情况是允许解开绑定的，因为VAO在这里是记录glVertexAttribPointer 的记录情况
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用。这也意味着它也会储存解绑调用，所以确保你没有在解绑VAO之前解绑索引数组缓冲，否则它就没有这个EBO配置了。
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	void Background::draw(glm::vec2 size, GLfloat rotate, glm::vec3 color)
	{
		this->shader_.use();

		glm::mat4 model = glm::mat4(1);

		//this->shader_.setMat4("model", model);

		//this->shader_.setMat4("projection", model);

		//glActiveTexture(GL_TEXTURE0);
		//this->texture_.bind();
		glm::mat4 view;
		glm::mat4 projection;
		
		projection = glm::perspective(glm::radians(160.0f), (float)800 / (float)600, 0.1f, 100.0f);
		
		//????
		view = glm::translate(view, glm::vec3(0.0f, 1.0f, -100.0f));

		// pass transformation matrices to the shader
		this->shader_.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		this->shader_.setMat4("view", view);


		glBindVertexArray(this->VAO_);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}
}//namespace lmm over


