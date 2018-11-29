//#include<iostream>
//#include<string>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include "Shader.h"
//#include "Camera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "LoadImage.h"
//#include "Obj.h"
//const unsigned int SRC_WIDTH = 800;
//const unsigned int SRC_HEIGHT = 600;
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//float fov = 45;
//float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//float pitch = 0.0f;
//float lastX = 800.0f / 2.0;
//float lastY = 600.0 / 2.0;
//bool firstMouse = true;
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//
//unsigned int setTexture(std::string path, Shader& shader_program, std::string texture_name, int position);
//void processInput(GLFWwindow* window);
//void mouseCallback(GLFWwindow* window, double xpos, double ypos);
//void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
//GLuint LoadTexture(string file_path);
//
//int main() {
//	//初始化工作
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SRC_WIDTH, SRC_HEIGHT, "LearnOpenGL", NULL, NULL);
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	//版本功能检测
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//
//	/* get version info */
//	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
//	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
//	cout << "Renderer: " << renderer << endl;
//	cout << "OpenGL version supported " << version << endl;
//	//版本功能检测结束
//
//	//功能设置
//	glEnable(GL_DEPTH_TEST);
//	glfwSetCursorPosCallback(window, mouseCallback);
//	glfwSetScrollCallback(window, scrollCallback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	Shader first_shader("./PiKaChu.vs", "./PikaChu.fs");
//	Obj loadObj("./objs/Pikachu.obj");
//	//一组就需要一个VAO
//	int VAO_num = loadObj.getGroups()->size();
//	
//	GLuint vVBO, nVBO, tVBO;
//	GLuint* VAOs = new GLuint [VAO_num];
//	//GLuint* VBOs = new GLuint[nVBO];
//	//GLuint* IBOs = new GLuint[nIBO];
//	GLuint* textures = new GLuint[VAO_num];
//
//	//每一个group都有它自己的材质
//	for (int i = 0; i < loadObj.getGroups()->size(); i++) {
//		//绑定顶点的VBO
//		glGenBuffers(1, &vVBO);
//		glBindBuffer(GL_ARRAY_BUFFER, vVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * loadObj.getGroups()->at(i).vertices.size(), &loadObj.getGroups()->at(i).vertices[0], GL_STATIC_DRAW);
//		//绑定法向量的VBO
//		if (loadObj.getGroups()->at(i).normals.size() > 0) {
//			glGenBuffers(1, &nVBO);
//			glBindBuffer(GL_ARRAY_BUFFER, nVBO);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * loadObj.getGroups()->at(i).normals.size(), &loadObj.getGroups()->at(i).normals[0], GL_STATIC_DRAW);
//		}
//		//绑定纹理的VBO
//		if (loadObj.getGroups()->at(i).textures.size() > 0) {
//			glGenBuffers(1, &tVBO);
//			glBindBuffer(GL_ARRAY_BUFFER, tVBO);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * loadObj.getGroups()->at(i).textures.size(), &loadObj.getGroups()->at(i).textures[0], GL_STATIC_DRAW);
//		}
//		glGenVertexArrays(1, &VAOs[i]);
//		glBindVertexArray(VAOs[i]);
//
//		//绑定顶点属性
//		glBindBuffer(GL_ARRAY_BUFFER, vVBO);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
//		glEnableVertexAttribArray(0);
//		//绑定法向量属性
//		if (loadObj.getGroups()->at(i).normals.size() > 0) {
//			// Normal attribute
//			glBindBuffer(GL_ARRAY_BUFFER, nVBO);
//			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
//			glEnableVertexAttribArray(1);
//		}
//		//绑定纹理属性
//		if (loadObj.getGroups()->at(i).textures.size() > 0) {
//			// Texture coords attribute
//			glBindBuffer(GL_ARRAY_BUFFER, tVBO);
//			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
//			glEnableVertexAttribArray(2);
//			string texturePath = "./objs/" + loadObj.getGroups()->at(i).material.getMapKd();
//			//加载纹理，注意注意！！！！！
//			int texture = LoadTexture(texturePath);
//			textures[i] = texture;
//		}
//		else {
//			textures[i] = 0;
//		}
//	}
//	
//	//解绑定VBO, VAO
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	GLuint texture;
//	string texturePath;
//
//	float t = 0.0f;
//
//	while (!glfwWindowShouldClose(window))
//	{
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(window);
//
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		first_shader.use();
//
//
//
//
//		glm::mat4 transform = glm::mat4(1);
//		//transform = glm::translate(transform, glm::vec3(0.0f, 0.2f, 0.0f));
//		//transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		first_shader.setMat4("transform", transform);
//		
//		float radius = 2.0f;
//		float camX = sin(glfwGetTime()) * radius;
//		float camZ = cos(glfwGetTime()) * radius;
//		//view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		//camera.updateCameraPosition(glm::vec3(camX, 0.0f, camZ));
//	
//		// create transformations
//		glm::mat4 projection = glm::perspective(glm::radians(camera.m_zoom), (float)SRC_WIDTH / (float)SRC_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 model = glm::mat4(1);
//
//		view[0][0] = camX;
//		view[2][0] = camZ;
//		// Get their uniform location
//		GLint modelLoc = glGetUniformLocation(first_shader.ID, "model");
//
//		GLint viewLoc = glGetUniformLocation(first_shader.ID, "view");
//		
//		GLint projLoc = glGetUniformLocation(first_shader.ID, "projection");
//
//		// Pass them to the shaders
//		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		// Note: currently we set the projection matrix each frame, but since the projection
//		// matrix rarely changes it's often best practice to set it outside the main loop only once.
//		//glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		first_shader.setMat4("projection", projection);
//		first_shader.setMat4("view", view);
//		first_shader.setMat4("model", model);
//
//
//
//		for (int i = 0; i < loadObj.getGroups()->size(); i++) {
//			if (loadObj.getGroups()->at(i).indicesVT.size() > 0) {
//				//默认激活第一个，所以不需要使用那个active
//				glBindTexture(GL_TEXTURE_2D, textures[i]);
//			}
//			glBindVertexArray(VAOs[i]);
//
//			glDrawArrays(GL_TRIANGLES, 0, loadObj.getGroups()->at(i).vertices.size() / 3);
//		}
//
//
//
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, texture1);
//
//		//glActiveTexture(GL_TEXTURE1);
//		//glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//		//first_shader.use();
//
//		////初始化很重要，切记要初始化矩阵
//		//glm::mat4 transform = glm::mat4(1);
//		//transform = glm::translate(transform, glm::vec3(0.0f, 0.2f, 0.0f));
//		//transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		//glm::mat4 model = glm::mat4(1);
//		//glm::mat4 view = glm::mat4(1);
//		//glm::mat4 projection = glm::mat4(1);
//		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//		//projection = glm::perspective(glm::radians(camera.m_zoom), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//		//unsigned int modelLoc = glGetUniformLocation(first_shader.ID, "model");
//		//unsigned int viewLoc = glGetUniformLocation(first_shader.ID, "view");
//		//unsigned int projectionLoc = glGetUniformLocation(first_shader.ID, "projection");
//		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
//		//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
//		////因为投影矩阵基本不变化，所以一般最好在循环外面初始化
//
//
//
//		////unsigned int transformLoc = glGetUniformLocation(first_shader.ID, "transform");
//		////glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//		//first_shader.setMat4("transform", transform);
//		////first_shader.setVec4("outcolor", greenValue);
//		//view = glm::mat4(1);
//		//float radius = 10.0f;
//		//float camX = sin(glfwGetTime()) * radius;
//		//float camZ = cos(glfwGetTime()) * radius;
//		////view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		//view = camera.GetViewMatrix();
//		//first_shader.setMat4("view", view);
//		//glBindVertexArray(VAO[0]);
//		////画十个立方体
//		//for (unsigned int i = 0; i < 10; i++) {
//		//	model = glm::mat4(1);
//		//	model = glm::translate(model, cubePositions[i]);
//
//		//	float angle = 20.0f * i;
//
//		//	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//		//	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//		//	first_shader.setMat4("model", model);
//
//		//	glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		//}
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		//glUseProgram(shaderProgram_2);
//		//glBindVertexArray(VAO[1]);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glDeleteVertexArrays(VAO_num, VAOs);
//	//glDeleteBuffers(2, VBO);
//	glfwTerminate();
//
//	return 0;
//}
//
//
//
//unsigned int setTexture(std::string path, Shader& shader_program, std::string texture_name, int position) {
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
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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
//void processInput(GLFWwindow* window) {
//
//
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
//	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
//		std::cout << "水平旋转" << std::endl;
//		camera.ProcessKeyboard(SPACE, deltaTime);
//	}
//		
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
//GLuint LoadTexture(string file_path)
//{
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height, nrChannels;
//	unsigned char* image = stbi_load(file_path.c_str(), &width, &height, &nrChannels, 0); 
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	stbi_image_free(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	return textureID;
//}
