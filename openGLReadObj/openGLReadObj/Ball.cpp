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
		this->shader_.setInt("image", 3);
		glActiveTexture(GL_TEXTURE3);
		this->texture_.bind();

		//this->shader_ no texture
		model = glm::translate(model, this->position_);
		this->shader_.setMat4("model", model);
		this->shader_.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		this->shader_.setMat4("view", view);

		glBindVertexArray(this->top_VAO_);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		glDrawElements(GL_TRIANGLE_FAN, top_indices_.size(), GL_UNSIGNED_INT, (void*)0); // we use index buffer, so set it to null.  
		//glDrawArrays(GL_TRIANGLES, 0, 30 * 3);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glBindVertexArray(this->bottom_VAO_);
		glDrawElements(GL_TRIANGLE_FAN, bottom_indices_.size(), GL_UNSIGNED_INT, (void*)0);
		glBindVertexArray(0);

		//this->shader_.setInt("image", 5);
		//glActiveTexture(GL_TEXTURE5);
		//texture_second.bind();

		glBindVertexArray(this->VAO_);
		glDrawElements(GL_TRIANGLE_FAN, middle_indices_.size(), GL_UNSIGNED_INT, (void*)0);
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
		float radius = 1;
		//���ȷ���
		const int k_VERTICAL_SLICE = 100;
		float vertical_step = (float)(glm::two_pi<float>() / k_VERTICAL_SLICE);
		//γ�ȷ���
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
				//���һȦ�Ŀ�ʼ����
				bottom_indices_.push_back((k_VERTICAL_SLICE + 1 ) * (i + 1));
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
					vertices_.push_back(vertices_[start_index + 3]);
					vertices_.push_back(vertices_[start_index + 4]);
					//�����������
				}
				else {
					//change the coordinate
					vertices_.push_back(x_coord);
					vertices_.push_back(z_coord);
					vertices_.push_back(y_coord);
					//�����������
					float x_coord_temp = x_coord / 2.0f;
					float y_coord_temp = y_coord / 2.0f;
					
					//�����������
					vertices_.push_back(x_coord_temp);
					vertices_.push_back(y_coord_temp);
				}
				current_index += 3;
				if (i > 0) {
					if (i == 1 ) {
						top_indices_.push_back(i * k_VERTICAL_SLICE + j + i);
					}
					else if (i == k_HORIZONTAL_SLICE - 1) {
						bottom_indices_.push_back(i * k_VERTICAL_SLICE + k_VERTICAL_SLICE - j + i);
					}
					else  if (i >= 2 && i < k_HORIZONTAL_SLICE - 1) {
						//�м��Բ��
						middle_indices_.push_back(i* k_VERTICAL_SLICE + j + i);

						middle_indices_.push_back((i + 1) * k_VERTICAL_SLICE + j + (i + 1));
					}
				}
				
			}
		}
		
		//�����в�
		GLuint VBO, IBO;
		glGenVertexArrays(1, &this->VAO_);
		glBindVertexArray(this->VAO_);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(GLfloat), vertices_.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);


		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		//indices
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, middle_indices_.size() * sizeof(GLfloat), middle_indices_.data(), GL_STATIC_DRAW);
		
		//���嶥����
		glGenVertexArrays(1, &this->top_VAO_);
		glBindVertexArray(this->top_VAO_);

	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, top_indices_.size() * sizeof(GLfloat), top_indices_.data(), GL_STATIC_DRAW);
		//����ײ���
		glGenVertexArrays(1, &this->bottom_VAO_);
		glBindVertexArray(this->bottom_VAO_);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, bottom_indices_.size() * sizeof(GLfloat), bottom_indices_.data(), GL_STATIC_DRAW);

		//unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}//namespace lmm over

