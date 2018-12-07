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


		// Load textures
		ResourceManager::LoadTexture("./images/background.jpg", GL_FALSE, "background");
		ResourceManager::LoadTexture("./images/block.png", GL_FALSE, "block");
		ResourceManager::LoadTexture("./images/block_solid.png", GL_FALSE, "block_solid");
		ResourceManager::LoadTexture("./images/paddle.png", GL_TRUE, "paddle");


		//set player
		genius_render_ = new GeniusRender( &ResourceManager::GetShader("genius"));

		// load level 
		GameLevel one;
		one.load("levels/one.lvl", this->width_, this->height_ * 0.5);
		this->levels_.push_back(one);
		this->level_ = 0;

		//configure
		glm::vec2 player_pos = glm::vec2(this->width_ / 2 - PLAYER_SIZE.x / 2, this->height_ - PLAYER_SIZE.y);
		this->player_ = new GameObject(player_pos, PLAYER_SIZE, ResourceManager::GetTexture("paddle"));
	}
	void BreakoutGame::processInput(GLfloat dt)
	{
		if (this->state_ == GameState::GAME_ACTIVE) {
			GLfloat velocity = PLAYER_VELOCITY * dt;
			//move the paddle
			if (this->keys_[GLFW_KEY_A]) {
				if (player_->position_.x >= 0) {
					player_->position_.x -= velocity;
				}
			}
			if (this->keys_[GLFW_KEY_D]) {
				if (player_->position_.x <= this->width_ - player_->size_.x) {
					player_->position_.x += velocity;

				}
			}
		}
	}
	void BreakoutGame::update(GLfloat dt)
	{
		// 更新对象
		ball_->move(dt, this->width_);
		// 检测碰撞
		this->doCollisions();
	}


	void BreakoutGame::render()
	{
		//genius_render_->drawGenius(&ResourceManager::GetTexture("face"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		if (this->state_ == GameState::GAME_ACTIVE) {
			//draw background 
			genius_render_->drawGenius(&ResourceManager::GetTexture("background"), glm::vec2(0, 0), glm::vec2(this->width_, this->height_), 0.0f);
			//genius_render_->drawGenius(&ResourceManager::GetTexture("face"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
			this->levels_[this->level_].draw(*genius_render_);
			player_->draw(*genius_render_);
		}
	}
	void BreakoutGame::doCollisions()
	{
		for (GameObject& box : this->levels_[this->level_].bricks_) {
			if (!box.destroyed_) {
				if (checkCollision(*ball_, box)) {
					if (!box.is_solid_) {
						box.destroyed_ = GL_TRUE;
					}
				}
			}
		}
	}
	bool BreakoutGame::checkCollision(GameObject & one, GameObject & two)
	{
		// x轴方向碰撞？
		bool collisionX = one.position_.x + one.size_.x >= two.position_.x &&
			two.position_.x + two.size_.x >= one.position_.x;
		// y轴方向碰撞？
		bool collisionY = one.position_.y + one.size_.y >= two.position_.y &&
			two.position_.y + two.size_.y >= one.position_.y;
		// 只有两个轴向都有碰撞时才碰撞
		return collisionX && collisionY;
	}
}//namespace lmm over;


