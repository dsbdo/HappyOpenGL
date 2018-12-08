#pragma once
#include<GLEW/glew.h>
#include <GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
		virtual void draw(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec2 size, GLfloat rotate, glm::vec3 color);
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
		float vertices[30] = {

		-0.5f, 0.0f, -0.5f,  0.0f, 1.0f,
		 0.5f, 0.0f, -0.5f,  1.0f, 1.0f,
		0.5f, 0.0f,  0.5f,  1.0f, 0.0f,
		0.5f, 0.0f,  0.5f,  1.0f, 0.0f,
		-0.5f, 0.0f,  0.5f,  0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,  0.0f, 1.0f,
		};
		const float triangle[9] = {
		-0.5f, 0.0f, -0.5f,
		 0.5f, 0.0f, -0.5f,
		 0.5f, 0.0f,  0.5f
		}; 

	};

}//namespace lmm over

