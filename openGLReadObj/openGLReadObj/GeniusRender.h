#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Texture.h"


namespace lmm {
	class GeniusRender
	{
	public:
		GeniusRender(Shader* shader);
		~GeniusRender();
		void drawGenius(Texture* texture, glm::vec2 position,
			glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
			glm::vec3 color = glm::vec3(1.0f));
		
	private:
		Shader shader;
		GLuint quadVAO;
		void initRenderData();

	};
}


