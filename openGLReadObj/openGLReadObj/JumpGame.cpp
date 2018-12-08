#include "JumpGame.h"
namespace lmm {

	JumpGame::JumpGame()
	{
	}

	JumpGame::JumpGame(GLuint width, GLuint height):width_(width), height_(height),game_state_(GameState::GAME_ACTIVE)
	{
		
	}


	JumpGame::~JumpGame()
	{
	}

	void JumpGame::render()
	{
		//draw the background
		background->draw(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	}

	void JumpGame::checkCollision()
	{
	}

	void JumpGame::doCollision()
	{
	}

	void JumpGame::init()
	{
		//Load background image
		ResourceManager::LoadShader("./background.vs", "./background.fs", nullptr, "bakcground");
		ResourceManager::LoadTexture("./images/background.jpg", GL_FALSE, "background");
		background = new Background(glm::vec2(0.0, 0.0), ResourceManager::GetShader("background"), ResourceManager::GetTexture("background"));
	}

	void JumpGame::processInput(GLfloat dt)
	{
	}

	void JumpGame::update(GLfloat dt)
	{
	}

}//namespace lmm over

