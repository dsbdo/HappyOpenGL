#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	SPACE,
	ROTATE
};
const float YAW = -90.0f; //偏航角
const float PITCH = -0.0f; //俯仰角
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f; //鼠标灵敏度
const float ZOOM = 45.0f; //摄像机视角
class Camera {
public:
	glm::vec3 m_camera_position;
	glm::vec3 m_camera_front;
	glm::vec3 m_camera_up;
	glm::vec3 m_camera_right;
	glm::vec3 m_world_up;
	//下面是欧拉角
	float m_yaw; //偏航角
	float m_pitch;//俯仰角

	//这里是相机的基本属性
	float m_movement_speed;
	float m_mouse_sensitivity;
	float m_zoom;

	//初始话相机
	Camera(glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f), float camera_yaw = YAW, float camera_pitch = PITCH) :m_camera_front(glm::vec3(0.0f, 0.0f, 0.0f)), m_movement_speed(SPEED), m_mouse_sensitivity(SENSITIVITY), m_zoom(ZOOM) {
		//这不简直有毒，还不如直接初始话，后面再改
		m_camera_position = camera_position;
		m_world_up = world_up;
		m_yaw = camera_yaw;
		m_pitch = camera_pitch;
		updateCameraVectors();
	}

	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float camera_yaw, float camera_pitch) {
		m_camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
		m_movement_speed = SPEED;
		m_mouse_sensitivity = SENSITIVITY;
		m_zoom = ZOOM;
		m_camera_position = glm::vec3(posX, posY, posZ);
		m_world_up = glm::vec3(upX, upY, upZ);
		m_yaw = camera_yaw;
		m_pitch = camera_pitch;
	}
	
	glm::mat4 GetViewMatrix() {
		return glm::lookAt(m_camera_position, m_camera_front, m_camera_up);
	}

	void ProcessKeyboard(CameraMovement direction, float deltaTime)
	{
		float velocity = m_movement_speed * deltaTime;
		if (direction == FORWARD)
			m_camera_position += m_camera_front * velocity;
		if (direction == BACKWARD)
			m_camera_position -= m_camera_front * velocity;
		if (direction == LEFT)
			m_camera_position -= m_camera_right * velocity ;
		if (direction == RIGHT)
			m_camera_position += m_camera_right * velocity ;
		if (direction == ROTATE) {

		}
		
	}
	void updateCameraPosition(glm::vec3 position) {
		m_camera_position = position;
	}

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= m_mouse_sensitivity;
		yoffset *= m_mouse_sensitivity;

		m_yaw += xoffset;
		m_pitch += yoffset;

		// Make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (m_pitch > 89.0f)
				m_pitch = 89.0f;
			if (m_pitch < -89.0f)
				m_pitch = -89.0f;
		}

		// 更新矩阵
		updateCameraVectors();
	}

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset)
	{
		if (m_zoom >= 1.0f && m_zoom <= 45.0f)
			m_zoom -= yoffset;
		if (m_zoom <= 1.0f)
			m_zoom = 1.0f;
		if (m_zoom >= 45.0f)
			m_zoom = 45.0f;
	}


private:
	void updateCameraVectors()
	{
		//// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y =  sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

		m_camera_front = glm::normalize(front);
		// Also re-calculate the Right and Up vector
		m_camera_right = glm::normalize(glm::cross(m_camera_front, m_world_up));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_camera_up = glm::normalize(glm::cross(m_camera_right, m_camera_front));
	}
};
#endif