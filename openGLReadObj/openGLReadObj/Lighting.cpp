//#include "Common.h"
//namespace lmm {
//	//light use practice
//	const float  vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//
//	const glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	const glm::vec3 pointLightPositions[] = {
//	glm::vec3(0.7f,  0.2f,  2.0f),
//	glm::vec3(2.3f, -3.3f, -4.0f),
//	glm::vec3(-4.0f,  2.0f, -12.0f),
//	glm::vec3(0.0f,  0.0f, -3.0f)
//	};
//	int light() {
//		GLFWwindow*  window = Init();
//		Shader light_shader("color.vs", "color.fs");
//		Shader lamp_shader("lamp.vs", "lamp.fs");
//
//
//		//use VBO and VAO
//		GLuint VBO, cubeVAO;
//		glGenVertexArrays(1, &cubeVAO);
//		glCheckError();
//
//		glGenBuffers(1, &VBO);
//		glCheckError();
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		glCheckError();
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//		glCheckError();
//
//
//		glBindVertexArray(cubeVAO);
//		glCheckError();
//		//VAO record position attribute
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//		//tell that this array is used by the layout position 0
//		glEnableVertexAttribArray(0);
//		// norm data
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(1);
//
//		//texture
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//		glEnableVertexAttribArray(2);
//
//		GLuint lightVAO;
//		glGenVertexArrays(1, &lightVAO);
//		glBindVertexArray(lightVAO);
//		glCheckError();
//
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		glCheckError();
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//		glCheckError();
//		glEnableVertexAttribArray(0);
//
//		light_shader.use();
//		// use index 0 texture;
//		//light_shader.setInt("material.diffuse", 0);
//		unsigned int  diffuse_map = setTexture("./images/container2.png", light_shader, "material.diffuse", 0, true);
//
//		unsigned int specular_map = setTexture("./images/container2_specular.png", light_shader, "material.specular", 1, true);
//		// render loop
//		while (!glfwWindowShouldClose(window)) {
//			float currentFrame = glfwGetTime();
//			deltaTime = currentFrame - lastFrame;
//			lastFrame = currentFrame;
//			//keyboard
//			processInput(window);
//
//			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			//lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
//			//lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
//			//set uniform or draw objects we should active shader first
//
//	
//			//glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // 降低影响
//			//glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // 很低的影响
//
//			light_shader.use();
//			light_shader.setVec3("viewPos", camera.m_camera_position);
//			light_shader.setFloat("material.shininess", 32.0f);
//
//			//set light based infomation
//			//first direction light
//			light_shader.setVec3("dir_light.direction", -0.2f, -0.1f, 0.3f);
//			light_shader.setVec3("dir_light.ambient", 0.05f, 0.05f, 0.05f);
//			light_shader.setVec3("dir_light.diffuse", 0.4f, 0.4f, 0.4f);
//			light_shader.setVec3("dir_light.specular", 0.5f, 0.5f, 0.5f);
//
//
//			glm::vec3 light_bright(0.5f, 0.5f, 0.5f);
//			glm::vec3 light_diffuse(0.1f, 0.1f, 0.1f);
//			light_bright.x = sin(glfwGetTime() * 2.0f);
//			light_bright.y = sin(glfwGetTime() * 0.7f);
//			light_bright.z = sin(glfwGetTime() * 1.3f);
//			//point light 0
//			light_shader.setVec3("point_lights[0].position", pointLightPositions[0]);
//			light_shader.setVec3("point_lights[0].ambient", 0.05f, 0.05f, 0.05f);
//			light_shader.setVec3("point_lights[0].diffuse", light_diffuse);
//			light_shader.setVec3("point_lights[0].specular", light_bright);
//			light_shader.setFloat("point_lights[0].constant", 1.0f);
//			light_shader.setFloat("point_lights[0].linear", 0.09);
//			light_shader.setFloat("point_lights[0].constant", 0.032);
//			//point light 1
//			light_shader.setVec3("point_lights[1].position", pointLightPositions[1]);
//			light_shader.setVec3("point_lights[1].ambient", 0.05f, 0.05f, 0.05f);
//			light_shader.setVec3("point_lights[1].diffuse", light_diffuse);
//			light_shader.setVec3("point_lights[1].specular", light_bright);
//			light_shader.setFloat("point_lights[1].constant", 1.0f);
//			light_shader.setFloat("point_lights[1].linear", 0.09);
//			light_shader.setFloat("point_lights[1].constant", 0.032);
//
//			//point light 2
//			light_shader.setVec3("point_lights[2].position", pointLightPositions[2]);
//			light_shader.setVec3("point_lights[2].ambient", 0.05f, 0.05f, 0.05f);
//			light_shader.setVec3("point_lights[2].diffuse", light_diffuse);
//			light_shader.setVec3("point_lights[2].specular", light_bright);
//			light_shader.setFloat("point_lights[2].constant", 1.0f);
//			light_shader.setFloat("point_lights[2].linear", 0.09);
//			light_shader.setFloat("point_lights[2].constant", 0.032);
//
//			//point light 3
//			light_shader.setVec3("point_lights[3].position", pointLightPositions[3]);
//			light_shader.setVec3("point_lights[3].ambient", 0.05f, 0.05f, 0.05f);
//			light_shader.setVec3("point_lights[3].diffuse", light_diffuse);
//			light_shader.setVec3("point_lights[3].specular", light_bright);
//			light_shader.setFloat("point_lights[3].constant", 1.0f);
//			light_shader.setFloat("point_lights[3].linear", 0.09);
//			light_shader.setFloat("point_lights[3].constant", 0.032);
//
//			//spotlight
//			light_shader.setVec3("spotlight.position", camera.m_camera_position);
//			light_shader.setVec3("spotlight.direction", camera.m_camera_front);
//			light_shader.setVec3("spotlight.ambient", 0.0f, 0.0f, 0.0f);
//			light_shader.setVec3("spotlight.diffuse", 1.0f, 1.0f, 1.0f);
//			light_shader.setVec3("spotlight.specular", 1.0f, 1.0f, 1.0f);
//			light_shader.setFloat("spotlight.constant", 1.0f);
//			light_shader.setFloat("spotlight.linear", 0.01);
//			light_shader.setFloat("spotlight.quadratic", 0.01);
//			light_shader.setFloat("spotlight.cut_off", glm::cos(glm::radians(12.5f)));
//			light_shader.setFloat("spotlight.outer_cut_off", glm::cos(glm::radians(15.0f)));
//
//			//set view / projection glm::radians(camera.m_zoom) is to calculate the fovy
//			glm::mat4 projection = glm::perspective(glm::radians(camera.m_zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//			//this is glm::LookAt function
//			glm::mat4 view = camera.GetViewMatrix();
//			light_shader.setMat4("projection", projection);
//			light_shader.setMat4("view", view);
//			//world transformation
//			glm::mat4 model = glm::mat4(1);
//			light_shader.setMat4("model", model);
//
//
//
//
//			glCheckError();
//			glActiveTexture(GL_TEXTURE0);
//			glBindTexture(GL_TEXTURE_2D, diffuse_map);
//			glCheckError();
//			glActiveTexture(GL_TEXTURE1);
//			glBindTexture(GL_TEXTURE_2D, specular_map);
//			glCheckError();
//			//render the cube
//			glBindVertexArray(cubeVAO);
//
//
//			for (unsigned int i = 0; i < 10; i++) {
//				glm::mat4 model = glm::mat4(1);
//				model = glm::translate(model, cubePositions[i]);
//				float angle = 20.0f * i;
//				model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//				light_shader.setMat4("model", model);
//				glDrawArrays(GL_TRIANGLES, 0, 36);
//				glCheckError();
//			}
//
//			//std::cout << glGetError() << std::endl;
//
//
//
//			//lamp draw
//			lamp_shader.use();
//			lamp_shader.setMat4("projection", projection);
//			lamp_shader.setMat4("view", view);
//			glBindVertexArray(lightVAO);
//			for (unsigned int i = 0; i < 4; i++)
//			{
//				model = glm::mat4(1);
//				model = glm::translate(model, pointLightPositions[i]);
//				model = glm::scale(model, glm::vec3(0.2f));
//				lamp_shader.setMat4("model", model);
//				glDrawArrays(GL_TRIANGLES, 0, 36);
//			}
//
//			//lamp_shader.setMat4("model", model);
//
//			glfwSwapBuffers(window);
//			glfwPollEvents();
//		}
//		glDeleteVertexArrays(1, &cubeVAO);
//		glDeleteVertexArrays(1, &lightVAO);
//		glDeleteBuffers(1, &VBO);
//
//		// glfw: terminate, clearing all previously allocated GLFW resources.
//		// ------------------------------------------------------------------
//		glfwTerminate();
//		return 0;
//	}
//} // namespace lmm over