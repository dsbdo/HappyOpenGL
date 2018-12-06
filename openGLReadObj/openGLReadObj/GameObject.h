#pragma once
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include "Texture.h"
#include "GeniusRender.h"
namespace lmm {
	class GameObject
	{
	public:
		GameObject();
		GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
		~GameObject();
		glm::vec2 position_;
		glm::vec2 size_;
		glm::vec2 velocity_;
		glm::vec3 color_;
		GLfloat rotation_;
		GLboolean is_solid_;
		GLboolean destroyed_;

		//render state
		Texture genius_;

		virtual void draw(GeniusRender& genius);
	};

}//namespace lmm over

