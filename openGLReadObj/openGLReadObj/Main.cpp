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
