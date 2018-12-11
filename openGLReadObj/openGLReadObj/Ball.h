#pragma once
#include<vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GameElement.h"
namespace lmm {
	class Ball : public GameElement
	{
	public:
		Ball();
		Ball(glm::vec3 pos, Shader shader, Texture texture);
		~Ball();
		virtual void draw(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec2 size, GLfloat rotate, glm::vec3 color) ;
		virtual void move();
		virtual void reset();
		virtual void initRenderData();
		Texture texture_second;
	private:
		glm::vec3 position_;
		Texture texture_;
		Shader shader_;
		GLuint top_VAO_;
		GLuint bottom_VAO_;

		std::vector<GLfloat> vertices_;
		std::vector<GLuint> top_indices_;
		std::vector<GLuint> middle_indices_;
		std::vector<GLuint> bottom_indices_;

		std::vector<GLfloat> vertices;
		std::vector<GLuint> indices;
	};


}//namespace lmm over
