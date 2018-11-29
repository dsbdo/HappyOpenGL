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
//
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//static float g_vertices[] = {
//	 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//};
//
//static float g_ver_2[] = {
//	-0.5f, 0.5f, 0.0f,
//	0.5f, 0.5f, 0.0f,
//	0.0f, -0.5f, 0.0f
//};
//
//
//const char* vertexShader_2 = "#version 330 core\n"
//"layout (location = 1) in vec3 bPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(bPos.x, bPos.y, bPos.z, 1.0);\n"
//"}\0";
//
//const char* fragShader_2 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.0f , 0.0f, 1.0f);\n"
//"}\n\0";
//
//
//
//float textCoors[] = {
//	0.0f, 0.0f, // 左下角
//	1.0f, 0.0f, // 右下角
//	0.5f, 1.0f // 上中
//};
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
//
//
//int test_main(int argc, char** argv) {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//	//编译着色器
//	unsigned int vertexShaderId;
//	Shader first_shader("./Tri.vs", "./Tri.fs");
//	//检查编译是否成功
//	int  success;
//	char infoLog[512];
//
//
//	//第二个顶点着色器
//	unsigned int ver_shaer_2_id;
//	ver_shaer_2_id = glCreateShader(GL_VERTEX_SHADER);
//	//第三个参数指定了需要编译的代码
//	glShaderSource(ver_shaer_2_id, 1, &vertexShader_2, NULL);
//	glCompileShader(ver_shaer_2_id);
//	//检查编译是否成功
//
//	glGetShaderiv(ver_shaer_2_id, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(ver_shaer_2_id, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	unsigned int fragShaderId;
//	unsigned int frag_shader_2_id;
//
//
//	frag_shader_2_id = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(frag_shader_2_id, 1, &fragShader_2, NULL);
//	glCompileShader(frag_shader_2_id);
//	//链接
//
//	unsigned int shaderProgram_2;
//	shaderProgram_2 = glCreateProgram();
//	glAttachShader(shaderProgram_2, ver_shaer_2_id);
//	glAttachShader(shaderProgram_2, frag_shader_2_id);
//	glLinkProgram(shaderProgram_2);
//
//	//检查链接程序是否成功
//	glGetProgramiv(shaderProgram_2, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram_2, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//
//
//
//	//指定着色器程序
//	unsigned int VAO[2];
//	unsigned int VBO[2];
//	//生成缓冲区指针
//	glGenBuffers(2, VBO);
//	glGenVertexArrays(2, VAO);
//
//	glBindVertexArray(VAO[0]);
//
//	//绑定VAO后，后面的glGenBindBuffer 函数调用均会被记忆到VAO中
//
//	//指明缓冲区指针类型, 可以同时绑定多个缓冲，只要是不同类型的缓冲
//	glBindBuffer(GL_ARRAY_BUFFER/*缓冲类型*/, VBO[0]);
//
//	//开辟空间, 第四个参数指定显卡如何管理给定的参数，GL_STATIC_DRAW， 数据几乎不会改变
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertices), g_vertices, GL_STATIC_DRAW);
//
//	unsigned int IBO[]{
//	0, 1, 3,
//	3, 2, 0
//	};
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IBO), IBO, GL_STATIC_DRAW);
//	//告诉openGL 如何解析数据，第一个参数指明我们将数据传给那哪一个变量
//	//位置属性
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// 颜色属性
//	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	//glEnableVertexAttribArray(1);
//	//纹理属性
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//
//	unsigned int texture1 = setTexture("./images/wall.jpg", first_shader, "ourTexture0", 0);
//	unsigned int texture2 = setTexture("./images/scut_temp.jpg", first_shader, "ourTexture1", 1);
//
//
//	//第二个三角形
//	glBindVertexArray(VAO[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_ver_2), g_ver_2, GL_STATIC_DRAW);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(1);
//
//	//解绑VBO
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//解绑VAO
//	glBindVertexArray(0);
//	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
//	// 译注：下面就是矩阵初始化的一个例子，如果使用的是0.9.9及以上版本
//	// 下面这行代码就需要改为:
//	// glm::mat4 trans = glm::mat4(1.0f)
//	// 之后将不再进行提示
//	glm::mat4 trans = glm::mat4(1);
//	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
//	vec = trans * vec;
//	std::cout << vec.x << vec.y << vec.z << std::endl;
//
//
//	glm::vec3 cubePositions[] = {
//	  glm::vec3(0.0f,  0.0f,  0.0f),
//	  glm::vec3(2.0f,  5.0f, -15.0f),
//	  glm::vec3(-1.5f, -2.2f, -2.5f),
//	  glm::vec3(-3.8f, -2.0f, -12.3f),
//	  glm::vec3(2.4f, -0.4f, -3.5f),
//	  glm::vec3(-1.7f,  3.0f, -7.5f),
//	  glm::vec3(1.3f, -2.0f, -2.5f),
//	  glm::vec3(1.5f,  2.0f, -2.5f),
//	  glm::vec3(1.5f,  0.2f, -1.5f),
//	  glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//	glEnable(GL_DEPTH_TEST);
//	glfwSetCursorPosCallback(window, mouseCallback);
//	glfwSetScrollCallback(window, scrollCallback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
//
//		
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//		first_shader.use();
//
//		//初始化很重要，切记要初始化矩阵
//		glm::mat4 transform = glm::mat4(1);
//		transform = glm::translate(transform, glm::vec3(0.0f, 0.2f, 0.0f));
//		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		glm::mat4 model = glm::mat4(1);
//		glm::mat4 view = glm::mat4(1);
//		glm::mat4 projection = glm::mat4(1);
//		model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//		projection = glm::perspective(glm::radians(camera.m_zoom), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
//		unsigned int modelLoc = glGetUniformLocation(first_shader.ID, "model");
//		unsigned int viewLoc = glGetUniformLocation(first_shader.ID, "view");
//		unsigned int projectionLoc = glGetUniformLocation(first_shader.ID, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
//		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
//		//因为投影矩阵基本不变化，所以一般最好在循环外面初始化
//
//	
//
//		//unsigned int transformLoc = glGetUniformLocation(first_shader.ID, "transform");
//		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//		first_shader.setMat4("transform", transform);
//		//first_shader.setVec4("outcolor", greenValue);
//		view = glm::mat4(1);
//		float radius = 10.0f;
//		float camX = sin(glfwGetTime()) * radius;
//		float camZ = cos(glfwGetTime()) * radius;
//		//view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		view = camera.GetViewMatrix();
//		first_shader.setMat4("view", view);
//		glBindVertexArray(VAO[0]);
//		//画十个立方体
//		for (unsigned int i = 0; i < 10; i++) {
//			model = glm::mat4(1);
//			model = glm::translate(model, cubePositions[i]);
//			
//			float angle = 20.0f * i;
//			
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//			//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			
//			first_shader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		}
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		//glUseProgram(shaderProgram_2);
//		//glBindVertexArray(VAO[1]);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glDeleteVertexArrays(2, VAO);
//	glDeleteBuffers(2, VBO);
//	glfwTerminate();
//	return 0;
//}
//
//
////读取一张图片并输出设置纹理
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
////
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