#include <iostream>

#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

//this is to record the function name for use.


#include "JumpGame.h"
#include "Texture.h"
#include "ResourceManager.h"

const GLuint K_SCREEN_WIDTH = 800;
const GLuint K_SCREEN_HEIGHT = 600;
lmm::JumpGame G_jump_game(K_SCREEN_HEIGHT, K_SCREEN_HEIGHT);
//lmm::BreakoutGame G_breakout(K_SCREEN_WIDTH, K_SCREEN_HEIGHT);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode); 
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
int main() {
	using std::cout;
	using std::endl;
	cout << "hello World" << endl;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(K_SCREEN_WIDTH, K_SCREEN_HEIGHT, "Breakout", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glewInit();
	//check that if init processhave error or not
	glGetError();
	//accept the keyboard input
	glfwSetKeyCallback(window, keyCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetScrollCallback(window, scrollCallback);


	//openGL configure
	glViewport(0, 0, K_SCREEN_WIDTH, K_SCREEN_HEIGHT);
	//this is face cull function enable to improve the render speed
	//glEnable(GL_CULL_FACE);
	//mix the original color and the target color
	//glEnable(GL_BLEND);
	//take the render image to the target area
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//open depth test
	glEnable(GL_DEPTH_TEST);
	//G_breakout.init();
	G_jump_game.init();

	//------------------------------------------------------
	Shader shader = lmm::ResourceManager::GetShader("ball");
	std::vector<GLfloat> vertices_;
	std::vector<GLuint> indices_;
	GLuint VAO_;
	float radius = 2;
	//经度方向
	const int k_VERTICAL_SLICE = 100;
	float vertical_step = (float)(glm::two_pi<float>() / k_VERTICAL_SLICE);
	//纬度方向
	const int k_HORIZONTAL_SLICE = 50;
	float horizontal_step = (float)(glm::pi<float>() / k_HORIZONTAL_SLICE);
	GLuint start_index = 0;
	GLuint current_index = 0;
	//longitude direction to get 50 circle with different radius
	for (GLuint i = 0; i <= k_HORIZONTAL_SLICE; i++) {
		start_index = current_index;
		float vertical_angle = horizontal_step * i;
		float z_coord = radius * cosf(vertical_angle);
		float sub_radius = radius * sinf(vertical_angle);
		//latitude direction to cut 100 block
		for (GLuint j = 0; j <= k_VERTICAL_SLICE; j++) {
			float horiaontal_angle = vertical_step * j;
			float x_coord = sub_radius * cosf(horiaontal_angle);
			float y_coord = sub_radius * sinf(horiaontal_angle);
			//start point encounter end point
			if (j == k_VERTICAL_SLICE) {
				vertices_.push_back(vertices_[start_index]);
				vertices_.push_back(vertices_[start_index + 1]);
				vertices_.push_back(vertices_[start_index + 2]);
			}
			else {
				//change the coordinate
				vertices_.push_back(x_coord);
				vertices_.push_back(z_coord);
				vertices_.push_back(y_coord);
			}
			current_index += 3;
			if (i > 0 && j > 0) {
				unsigned int bottom_ring_a = (k_VERTICAL_SLICE + 1) * i + j;
				unsigned int bottom_ring_b = (k_VERTICAL_SLICE + 1) * i + j - 1;
				//next ring
				unsigned int top_ring_a = (k_VERTICAL_SLICE + 1) * (i - 1) + j;
				unsigned int top_ring_b = (k_VERTICAL_SLICE + 1) * (i - 1) + j - 1;
				//j == 1
				if (j == 1) {
					indices_.push_back(bottom_ring_a);
					indices_.push_back(top_ring_a);
					indices_.push_back(top_ring_b);
				}
				//j == 
				else if (j == k_HORIZONTAL_SLICE) {
					indices_.push_back(bottom_ring_a);
					indices_.push_back(top_ring_a);
					indices_.push_back(bottom_ring_b);
				}
				else {
					// 逆时钟方向连接顶点，每次连接成一个四边形
					// 逆时钟方向避免三角形被背面剔除处理掉
					indices_.push_back(bottom_ring_a);
					indices_.push_back(top_ring_a);
					indices_.push_back(top_ring_b);
					indices_.push_back(bottom_ring_a);
					indices_.push_back(top_ring_b);
					indices_.push_back(bottom_ring_b);
				}
			}
		}
	}
	GLuint VBO, IBO;
	glGenVertexArrays(1, &VAO_);
	glBindVertexArray(VAO_);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(GLfloat), vertices_.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	//indices
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(GLfloat), indices_.data(), GL_STATIC_DRAW);

	//unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	
	//---------------------------------------------------------


	//lmm::light();
	//deltaTime 
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	//G_breakout.state_ = lmm::GameState::GAME_ACTIVE;

	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//deltaTime = 0.001f;
		// Manage user input
		//G_breakout.processInput(deltaTime);
		G_jump_game.processInput(deltaTime);
		// Update Game state
		//G_breakout.update(deltaTime);
		G_jump_game.update(deltaTime);
		// Render
		G_jump_game.render();

		shader.use();
		glBindVertexArray(VAO_);
		glDrawElements(GL_LINE_STRIP, indices_.size(), GL_UNSIGNED_INT, (void*)0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS) {
			G_jump_game.keys_[key] = GL_TRUE;
		}
			//G_breakout.keys_[key] = GL_TRUE;


		else if (action == GLFW_RELEASE) {
			G_jump_game.keys_[key] = GL_FALSE;
		}
			//G_breakout.keys_[key] = GL_FALSE;
	}
}



void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	G_jump_game.processMouse(xpos, ypos);
}
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	G_jump_game.processScroll(xoffset, yoffset);
}
