#include "Ball.h"


namespace lmm {
	Ball::Ball()
	{
	}

	Ball::Ball(glm::vec3 pos, Shader shader, Texture texture) :position_(pos), shader_(shader), texture_(texture)
	{
		this->initRenderData();
	}


	Ball::~Ball()
	{
	}
	void Ball::draw(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec2 size, GLfloat rotate, glm::vec3 color)
	{
		this->shader_.use();
		//this->shader_ no texture
		model = glm::translate(model, this->position_);
		this->shader_.setMat4("model", model);
		this->shader_.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.

		this->shader_.setMat4("view", view);

		glBindVertexArray(this->VAO_);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		glDrawElements(GL_LINE_STRIP, indices.size(), GL_UNSIGNED_INT, (void*)0); // we use index buffer, so set it to null.  
		//glDrawArrays(GL_TRIANGLES, 0, 30 * 3);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void Ball::move()
	{
	}
	void Ball::reset()
	{
	}
	void Ball::initRenderData()
	{
		float radius = 0.5;
		//经度方向
		const int k_VERTICAL_SLICE = 100;
		float vertical_step = (float)(glm::two_pi<float>() / k_VERTICAL_SLICE);
		//纬度方向
		const int k_HORIZONTAL_SLICE = 50;
		float horizontal_step = (float)(glm::pi<float>() / k_HORIZONTAL_SLICE);
		GLuint start_index = 0;
		GLuint current_index = 0;
		//longitude direction to get 50 circle with different radius
		for (GLuint i = 0; i <= k_HORIZONTAL_SLICE; i++) {
			start_index = current_index;
			float vertical_angle = horizontal_step * i;
			float z_coord = radius * cosf(vertical_angle);
			float sub_radius = radius * sinf(vertical_angle);
			//latitude direction to cut 100 block
			if (i == 1) {
				top_indices_.push_back(0);
			}
			else if (i == k_HORIZONTAL_SLICE - 1) {
				//最后一圈的开始坐标
				bottom_indices_.push_back(k_VERTICAL_SLICE * (i + 1));
			}
			else {
				middle_indices_.push_back(i * k_VERTICAL_SLICE + 0);
			}
			for (GLuint j = 0; j <= k_VERTICAL_SLICE; j++) {
				float horiaontal_angle = vertical_step * j;
				float x_coord = sub_radius * cosf(horiaontal_angle);
				float y_coord = sub_radius * sinf(horiaontal_angle);
				//start point encounter end point
				if (j == k_VERTICAL_SLICE) {
					vertices_.push_back(vertices_[start_index]);
					vertices_.push_back(vertices_[start_index + 1]);
					vertices_.push_back(vertices_[start_index + 2]);
				}
				else {
					//change the coordinate
					vertices_.push_back(x_coord);
					vertices_.push_back(z_coord);
					vertices_.push_back(y_coord);
				}
				current_index += 3;
				if (i > 0 && j > 0) {
					if (i == 1 ) {
						top_indices_.push_back(i * k_VERTICAL_SLICE + j);
					}
					else if (i == k_HORIZONTAL_SLICE - 1) {
						bottom_indices_.push_back(i * k_VERTICAL_SLICE + k_VERTICAL_SLICE - j);
					}
					else {
						//中间的圆环
						middle_indices_.push_back(i * k_VERTICAL_SLICE + j );
						middle_indices_.push_back((i - 1)* k_VERTICAL_SLICE + j - 1);
					}
					if (j == k_VERTICAL_SLICE) {
						//
					}
				}
				
			}
			if (i > 0) {

				//unsigned int bottom_ring_a = (k_VERTICAL_SLICE + 1) * i + j;
				//unsigned int bottom_ring_b = (k_VERTICAL_SLICE + 1) * i + j - 1;
				////next ring
				//unsigned int top_ring_a = (k_VERTICAL_SLICE + 1) * (i -1) + j;
				//unsigned int top_ring_b = (k_VERTICAL_SLICE + 1) * (i - 1) + j - 1;
				////j == 1
				//if (j == 1) {
				//	indices_.push_back(bottom_ring_a);
				//	indices_.push_back(top_ring_a);
				//	indices_.push_back(top_ring_b);
				//}
				////j == 
				//else if (j == k_HORIZONTAL_SLICE) {
				//	indices_.push_back(bottom_ring_a);
				//	indices_.push_back(top_ring_a);
				//	indices_.push_back(bottom_ring_b);
				//}
				//else {
				//	// 逆时钟方向连接顶点，每次连接成一个四边形
				//	// 逆时钟方向避免三角形被背面剔除处理掉
				//	indices_.push_back(bottom_ring_a);
				//	indices_.push_back(top_ring_a);
				//	indices_.push_back(top_ring_b);
				//	indices_.push_back(bottom_ring_a);
				//	indices_.push_back(top_ring_b);
				//	indices_.push_back(bottom_ring_b);
				//}
				//画三角形的坐标定位
				
			}
		}
		
		GLuint VBO, IBO;
		glGenVertexArrays(1, &this->VAO_);
		glBindVertexArray(this->VAO_);
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);
		//indices
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLfloat), indices.data(), GL_STATIC_DRAW);

		//unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//GLfloat circle_vertex[30 * 3 * 5];
		//GLfloat theta = 0;
		//GLfloat radius = 1;
		//const GLfloat M_PI = 3.1415926;
		//for (int i = 0; i < 30; i++) {
		//	theta = i * 12;
		//	//第一个点
		//	circle_vertex[i * 3 * 5] = 0;
		//	circle_vertex[i * 3 * 5 + 1] = 0;
		//	circle_vertex[i * 3 * 5 + 2] = 0;
		//	circle_vertex[i * 3 * 5 + 3] = 0;
		//	circle_vertex[i * 3 * 5 + 4] = 0;
		//	//第二个点	  i * 3 * 5
		//	circle_vertex[i * 3 * 5 + 5] = (GLfloat)radius * cosf(theta * M_PI / 180.0f);
		//	circle_vertex[i * 3 * 5 + 6] = 0;
		//	circle_vertex[i * 3 * 5 + 7] = (GLfloat)radius * sinf(theta * M_PI / 180.0f);
		//	circle_vertex[i * 3 * 5 + 8] = 1;
		//	circle_vertex[i * 3 * 5 + 9] = 0;

		//	//第三个点	  i * 3 * 5
		//	theta += 12;
		//	circle_vertex[i * 3 * 5 + 10] = (GLfloat)radius * cosf(theta * M_PI / 180.0f);
		//	circle_vertex[i * 3 * 5 + 11] = 0;
		//	circle_vertex[i * 3 * 5 + 12] = (GLfloat)radius * sinf(theta * M_PI / 180.0f);
		//	circle_vertex[i * 3 * 5 + 13] = 1;
		//	circle_vertex[i * 3 * 5 + 14] = 1;

		//}

		//GLuint VBO, IBO;

		//glGenVertexArrays(1, &this->VAO_);

		//glGenBuffers(1, &VBO);
		//glGenBuffers(1, &IBO);
		////bind VAO


		//glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(circle_vertex), circle_vertex, GL_STATIC_DRAW);

		//glBindVertexArray(this->VAO_);
		////glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		////glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertex_index_), this->vertex_index_, GL_STATIC_DRAW);


		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		//glEnableVertexAttribArray(0);
		//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(float)));
		//glEnableVertexAttribArray(1);

		//// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		////这一种情况是允许解开绑定的，因为VAO在这里是记录glVertexAttribPointer 的记录情况
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		////当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用。这也意味着它也会储存解绑调用，所以确保你没有在解绑VAO之前解绑索引数组缓冲，否则它就没有这个EBO配置了。
		////glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		//glBindVertexArray(0);
	}
}//namespace lmm over

