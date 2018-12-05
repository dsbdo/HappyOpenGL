//#pragma once
//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "Shader.h"
//#include "Camera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "LoadImage.h"
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//// lighting
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
//
//
//void mouseCallback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//
////读取一张图片并输出设置纹理
//unsigned int setTexture(std::string path, Shader& shader_program, std::string texture_name, int position, bool isPng) {
//	//创建纹理
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//设置坐标轴取值模式, S方向上
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//设置纹理过滤器，采用什么样的插值方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	//加载图片
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		//生成纹理
//		if (isPng) {
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		}
//		else {
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		}
//		//创建一系列的多级渐远纹理
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	shader_program.use();
//	shader_program.setInt(texture_name, position);
//	return texture;
//}
//
//namespace lmm {
//	GLFWwindow*  Init() {
//		glfwInit();
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//		if (window == NULL)
//		{
//			std::cout << "Failed to create GLFW window" << std::endl;
//			glfwTerminate();
//			return nullptr;
//		}
//		glfwMakeContextCurrent(window);
//		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//		glfwSetCursorPosCallback(window, mouseCallback);
//		glfwSetScrollCallback(window, scrollCallback);
//
//		// tell GLFW to capture our mouse
//		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//		{
//			std::cout << "Failed to initialize GLAD" << std::endl;
//			return nullptr;
//		}
//		int nrAttributes;
//		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//		std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//
//
//		//	//编译着色器
//				//this will open the depth test to make the 3D model be more real
//		glEnable(GL_DEPTH_TEST);
//		return window;
//	}
//}
//
//
//GLenum glCheckError_(const char *file, int line)
//{
//	GLenum errorCode;
//	while ((errorCode = glGetError()) != GL_NO_ERROR)
//	{
//		std::string error;
//		switch (errorCode)
//		{
//		case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
//		case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
//		case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
//		case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
//		case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
//		case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
//		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
//		}
//		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
//	}
//	return errorCode;
//}
//#define glCheckError() glCheckError_(__FILE__, __LINE__) 