#pragma once
#include<GLEW/glew.h>
#include<glm/glm.hpp>
#include"Texture.h"
#include "GeniusRender.h"
#include "GameObject.h"

namespace lmm {
	class BallObject : public GameObject
	{
	public:

		BallObject();
		BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture texture_image);
		~BallObject();
		GLfloat radius_;
		GLboolean stuck_;
		glm::vec2 move(GLfloat dt, GLuint window_width);
		void reset(glm::vec2 position, glm::vec2 velocity);
	};
}

