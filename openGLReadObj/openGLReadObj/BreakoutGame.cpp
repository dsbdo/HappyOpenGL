#include "BreakoutGame.h"
namespace lmm {

	BreakoutGame::BreakoutGame()
	{
		
	}

	BreakoutGame::BreakoutGame(GLuint width, GLuint height) : state_(GameState::GAME_ACTIVE), width_(width), height_(height), genius_render_(nullptr)
	{
	}


	BreakoutGame::~BreakoutGame()
	{
		delete genius_render_;
	}
	void BreakoutGame::init()
	{
		ResourceManager::LoadShader("genius.vs", "genius.fs", nullptr, "genius");

		glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->width_), static_cast<GLfloat>(this->height_), 0.0f, -1.0f, 1.0f);
		ResourceManager::GetShader("genius").use();
		ResourceManager::GetShader("genius").setInt("image", 0);
		ResourceManager::GetShader("genius").setMat4("projection", projection);
		//texture
		ResourceManager::LoadTexture("./images/awesomeface.png", GL_TRUE, "face");

		genius_render_ = new GeniusRender( &ResourceManager::GetShader("genius"));

	}
	void BreakoutGame::processInput(GLfloat dt)
	{
	}
	void BreakoutGame::update(GLfloat dt)
	{
	}
	void BreakoutGame::render()
	{
		genius_render_->drawGenius(&ResourceManager::GetTexture("face"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	}
}//namespace lmm over;


