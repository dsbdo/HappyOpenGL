#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ResourceManager.h"
#include "GeniusRender.h"
namespace lmm {
	enum GameState {
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};


	class BreakoutGame
	{
	public:
		BreakoutGame();
		BreakoutGame(GLuint width, GLuint height);
		~BreakoutGame();
		//game state
		GameState state_;
		GLboolean keys_[1024];
		GLuint width_, height_;
		void init();
		void processInput(GLfloat dt);
		void update(GLfloat dt);
		void render();
	private:
		GeniusRender* genius_render_;


	};

}//namespace lmm over;

