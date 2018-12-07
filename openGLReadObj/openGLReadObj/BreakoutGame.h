#pragma once

#include <vector>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ResourceManager.h"
#include "GeniusRender.h"
#include "GameLevel.h"
#include "BallObject.h"
#include <GLFW/glfw3.h>
namespace lmm {
	enum GameState {
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
	//init the paddle size
	const glm::vec2 PLAYER_SIZE(100, 20);
	const GLfloat PLAYER_VELOCITY(500.0f);

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

		std::vector<GameLevel> levels_;
		GLuint level_;


		void init();
		void processInput(GLfloat dt);
		void update(GLfloat dt);
		void render();


		//check collision
		void doCollisions();
		bool checkCollision(GameObject &one, GameObject &two);
	private:
		GeniusRender* genius_render_;
		GameObject* player_;
		BallObject* ball_;
	};

}//namespace lmm over;

