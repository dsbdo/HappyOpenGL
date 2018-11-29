#include "Common.h"
namespace lmm {
	//light use practice
	const float  vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};
	int light() {
		GLFWwindow*  window = Init();
		Shader light_shader("color.vs", "color.fs");
		Shader lamp_shader("lamp.vs", "lamp.fs");


		//use VBO and VAO
		GLuint VBO, cubeVAO;
		glGenVertexArrays(1, &cubeVAO);
		glCheckError();

		glGenBuffers(1, &VBO);
		glCheckError();
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glCheckError();
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glCheckError();


		glBindVertexArray(cubeVAO);
		glCheckError();
		//VAO record position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		//tell that this array is used by the layout position 0
		glEnableVertexAttribArray(0);
		// norm data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//texture
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);
		glBindVertexArray(lightVAO);
		glCheckError();

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glCheckError();
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glCheckError();
		glEnableVertexAttribArray(0);

		light_shader.use();
		// use index 0 texture;
		//light_shader.setInt("material.diffuse", 0);
		unsigned int  diffuse_map = setTexture("./images/container2.png", light_shader, "material.diffuse", 0, true);
		// render loop
		while (!glfwWindowShouldClose(window)) {
			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			//keyboard
			processInput(window);

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
			//lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
			//set uniform or draw objects we should active shader first

			glm::vec3 lightColor;
			lightColor.x = sin(glfwGetTime() * 2.0f);
			lightColor.y = sin(glfwGetTime() * 0.7f);
			lightColor.z = sin(glfwGetTime() * 1.3f);
			//glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // 降低影响
			//glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // 很低的影响

			light_shader.use();
			light_shader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
			light_shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
			light_shader.setVec3("lightPos", lightPos);
			light_shader.setVec3("viewPos", camera.m_camera_position);
			
			//object's self color
			//light_shader.setVec3("material.ambient", 0.2f, 0.2f, 0.2f);
			//light_shader.setVec3("material.diffuse", 0.5f, 0.5f, 0.5f);
			light_shader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
			light_shader.setFloat("material.shininess", 32.0f);
			//object light attribute
			light_shader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
			light_shader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
			light_shader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
			light_shader.setVec3("light.position",lightPos);
			//set view / projection glm::radians(camera.m_zoom) is to calculate the fovy
			glm::mat4 projection = glm::perspective(glm::radians(camera.m_zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
			//this is glm::LookAt function
			glm::mat4 view = camera.GetViewMatrix();
			light_shader.setMat4("projection", projection);
			light_shader.setMat4("view", view);

			//world transformation
			glm::mat4 model = glm::mat4(1);
			light_shader.setMat4("model", model);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuse_map);
			//render the cube
			glBindVertexArray(cubeVAO);
			glCheckError();
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glCheckError();
			//std::cout << glGetError() << std::endl;

			//lamp draw
			lamp_shader.use();
			lamp_shader.setMat4("projection", projection);
			lamp_shader.setMat4("view", view);
			model = glm::mat4(1);
			model = glm::translate(model, lightPos);
			model = glm::scale(model, glm::vec3(0.2f));
			lamp_shader.setMat4("model", model);
			glBindVertexArray(lightVAO);
			glCheckError();
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glCheckError();
			//std::cout << glGetError() << std::endl;

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteVertexArrays(1, &lightVAO);
		glDeleteBuffers(1, &VBO);

		// glfw: terminate, clearing all previously allocated GLFW resources.
		// ------------------------------------------------------------------
		glfwTerminate();
		return 0;
	}
} // namespace lmm over