#include "JumpGame.h"

namespace lmm {

	JumpGame::JumpGame()
	{
	}

	JumpGame::JumpGame(GLuint width, GLuint height):width_(width), height_(height),game_state_(GameState::GAME_ACTIVE)
	{
		last_x_ = 800/2.0f;
		last_y_ = 600 / 2.0f;
		first_mouse_ = true;
		camera = new Camera(glm::vec3(0.0f, 10.0f, 10.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		camera->m_camera_front = glm::vec3(0.0f, 0.0f, 0.0f);
	}



	JumpGame::~JumpGame()
	{
	}

	void JumpGame::render()
	{
		glm::mat4 model = glm::mat4(1);
		glm::mat4 projection = glm::mat4(1);
		glm::mat4 view = glm::mat4(1);
		float radius = 10.0f;
		//float camX = sin(glfwGetTime()) * radius;
		//float camZ = cos(glfwGetTime()) * radius;
		//camera->m_camera_position.x = camX;
		//camera->m_camera_position.z = camZ;
		projection = glm::perspective(glm::radians(camera->m_zoom), (float)800 / (float)600, 0.1f, 100.0f);
		//view = glm::lookAt(glm::vec3(0.0f, 10.0f, 10.0f), glm::vec3(0,0,0) , glm::vec3(0, 1, 0));
		view = camera->GetViewMatrix();

		view = glm::rotate(view, (float)glm::radians(glfwGetTime()* 50), glm::vec3(0, 1, 0));
		//draw the background

		background->draw(projection, view, model, glm::vec2(0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		for (auto it = cube_array_.begin(); it != cube_array_.end(); it++) {
			it->draw(projection, view, model, glm::vec2(0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		}
		light_->draw(projection, view, model, glm::vec2(0.0f, 0.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
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
		ResourceManager::LoadShader("./background.vs", "./background.fs", nullptr, "background");
		ResourceManager::LoadTexture("./images/wall.jpg", GL_FALSE, "background");
		ResourceManager::LoadShader("./cube.vs", "./cube.fs", nullptr, "cube");
	
		ResourceManager::LoadTexture("./images/scut.jpg", GL_FALSE, "cube");
		ResourceManager::LoadTexture("./images/container2.png", GL_TRUE, "cube2");
		ResourceManager::LoadTexture("./images/container.jpg", GL_FALSE, "cube3");
		ResourceManager::LoadTexture("./images/awesomeface.png", GL_TRUE, "cube4");
		ResourceManager::LoadTexture("./images/block.png", GL_TRUE, "cube5");


		background = new Background(glm::vec2(0.0, 0.0), ResourceManager::GetShader("background"), ResourceManager::GetTexture("background"));
		CubeRender cube(glm::vec3(5, 2, 0.0), ResourceManager::GetShader("cube"), ResourceManager::GetTexture("cube"));
		cube_array_.push_back(cube);
		CubeRender cube2(glm::vec3(3.0, 0.5, 4.0), ResourceManager::GetShader("cube"), ResourceManager::GetTexture("cube2"));
		cube_array_.push_back(cube2);
		CubeRender cube3(glm::vec3(0.0, 0.5, 0.0), ResourceManager::GetShader("cube"), ResourceManager::GetTexture("cube3"));
		cube_array_.push_back(cube3);
		CubeRender cube4(glm::vec3(3.0, 0.5, 0.0), ResourceManager::GetShader("cube"), ResourceManager::GetTexture("cube4"));
		cube_array_.push_back(cube4);
		CubeRender cube5(glm::vec3(-3, 0.5, 4.0), ResourceManager::GetShader("cube"), ResourceManager::GetTexture("cube5"));
		cube_array_.push_back(cube5);

		//建立一个灯泡
		ResourceManager::LoadShader("./ball.vs", "./ball.fs", nullptr, "ball");
		ResourceManager::LoadTexture("./images/sun2.jpg", GL_FALSE, "sun");
		light_ = new Ball(glm::vec3(0.0, 4.0, 0.0), ResourceManager::GetShader("ball"), ResourceManager::GetTexture("sun"));
		light_->texture_second = ResourceManager::GetTexture("cube5");

	}

	void JumpGame::processInput(GLfloat dt)
	{
		if (this->keys_[GLFW_KEY_W]) {
			camera->ProcessKeyboard(FORWARD, dt);
		}
		if (this->keys_[GLFW_KEY_S]) {
			camera->ProcessKeyboard(BACKWARD, dt);
		}
		if (this->keys_[GLFW_KEY_A]) {
			camera->ProcessKeyboard(LEFT, dt);
		}
		if (this->keys_[GLFW_KEY_D]) {
			camera->ProcessKeyboard(RIGHT, dt);
		}
	}

	void JumpGame::processMouse(double xpos, double ypos)
	{
		if (first_mouse_)
		{
			last_x_ = xpos;
			last_y_ = ypos;
			first_mouse_ = false;
		}

		float xoffset = xpos - last_x_;
		float yoffset = last_y_ - ypos; // reversed since y-coordinates go from bottom to top

		last_x_ = xpos;
		last_y_ = ypos;

		camera->ProcessMouseMovement(xoffset, yoffset);
	}


	void JumpGame::processScroll(double xoffset, double yoffset)
	{
		camera->ProcessMouseScroll(yoffset);
	}

	void JumpGame::update(GLfloat dt)
	{
	}

}//namespace lmm over

