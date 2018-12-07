#include <iostream>

#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

//this is to record the function name for use.

#include "BreakoutGame.h"
#include "Texture.h"

const GLuint K_SCREEN_WIDTH = 800;
const GLuint K_SCREEN_HEIGHT = 600;

lmm::BreakoutGame G_breakout(K_SCREEN_WIDTH, K_SCREEN_HEIGHT);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
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

	//openGL configure
	glViewport(0, 0, K_SCREEN_WIDTH, K_SCREEN_HEIGHT);
	//this is face cull function enable to improve the render speed
	glEnable(GL_CULL_FACE);
	//mix the original color and the target color
	glEnable(GL_BLEND);
	//take the render image to the target area
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	G_breakout.init();
	//lmm::light();
	//deltaTime 
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	G_breakout.state_ = lmm::GameState::GAME_ACTIVE;
	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();

		//deltaTime = 0.001f;
		// Manage user input
		G_breakout.processInput(deltaTime);

		// Update Game state
		G_breakout.update(deltaTime);

		// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		G_breakout.render();

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
		if (action == GLFW_PRESS)
			G_breakout.keys_[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			G_breakout.keys_[key] = GL_FALSE;
	}
}