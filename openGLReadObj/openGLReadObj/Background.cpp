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
		//GLfloat circle_vertex[31 * 5 + 5];
		//GLfloat theta = 0;
		//GLfloat radius = 1;
		//const GLfloat M_PI = 3.1415926;
		////center point we can think it is the circle center point 
		//circle_vertex[0] = 0;
		//circle_vertex[1] = 0;
		//circle_vertex[2] = 0;
		////texture
		//circle_vertex[3] = 0;
		//circle_vertex[4] = 0;
		//circle_vertex[5] = 1;
		//circle_vertex[6] = 0;
		//circle_vertex[7] = 0;
		////texture
		//circle_vertex[8] = 1;
		//circle_vertex[9] = 0;
		////circle_vertex[3]
		//for (int i = 1; i <= 30; i++) {

		//	theta = i  * 12;
		//	GLfloat x = (GLfloat)radius * cosf(theta * M_PI / 180.0f);
		//	GLfloat z = (GLfloat)radius * sinf(theta * M_PI / 180.0f);

		//	circle_vertex[(i +1) * 5] = x;
		//	circle_vertex[(i + 1) * 5 + 1] = 0; 
		//	circle_vertex[(i + 1) * 5 + 2] = z;

		//	circle_vertex[(i + 1) * 5 + 3] = (x + 1) / 2.0f;
		//	circle_vertex[(i + 1) * 5 + 4] = (z + 1) / 2.0f;
		//}

		GLfloat circle_vertex[30 * 3 * 5];
		GLfloat theta = 0;
		GLfloat radius = 1;
		const GLfloat M_PI = 3.1415926;
		for (int i = 0; i < 30; i++) {
			theta = i * 12;
			//第一个点
			circle_vertex[i * 3 * 5] = 0;
			circle_vertex[i * 3 * 5 + 1] = 0;
			circle_vertex[i * 3 * 5 + 2] = 0;
			circle_vertex[i * 3 * 5 + 3] = 0;
			circle_vertex[i * 3 * 5 + 4] = 0;
			//第二个点	  i * 3 * 5
			circle_vertex[i * 3 * 5 + 5] = (GLfloat)radius * cosf(theta * M_PI / 180.0f);
			circle_vertex[i * 3 * 5 + 6] = 0;
			circle_vertex[i * 3 * 5 + 7] = (GLfloat)radius * sinf(theta * M_PI / 180.0f);
			circle_vertex[i * 3 * 5 + 8] = 1;
			circle_vertex[i * 3 * 5 + 9] = 0;
						  
			//第三个点	  i * 3 * 5
			theta += 12; 
			circle_vertex[i * 3 * 5 + 10] = (GLfloat)radius * cosf(theta * M_PI / 180.0f);
			circle_vertex[i * 3 * 5 + 11] = 0;
			circle_vertex[i * 3 * 5 + 12] = (GLfloat)radius * sinf(theta * M_PI / 180.0f);
			circle_vertex[i * 3 * 5 + 13] = 1;
			circle_vertex[i * 3 * 5 + 14] = 1;

		}

		GLuint VBO, IBO;

		glGenVertexArrays(1, &this->VAO_);

		glGenBuffers(1, &VBO);
		glGenBuffers(1, &IBO);
		//bind VAO
	

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(circle_vertex),circle_vertex, GL_STATIC_DRAW);
		
		glBindVertexArray(this->VAO_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertex_index_), this->vertex_index_, GL_STATIC_DRAW);
	
	
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
	void Background::draw(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec2 size, GLfloat rotate, glm::vec3 color)
	{
		this->shader_.use();

		glActiveTexture(GL_TEXTURE0);
		this->texture_.bind();
	//	projection = glm::mat4(1);
		//projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		//view = glm::mat4(1);
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		model = glm::mat4(1);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(10.0, 10.0, 10.0));

		this->shader_.setMat4("model", model);
		// pass transformation matrices to the shader
		this->shader_.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		
		this->shader_.setMat4("view", view);


		glBindVertexArray(this->VAO_);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//it means 32 points
		glDrawArrays(GL_TRIANGLES, 0, 30 * 3);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}
}//namespace lmm over


