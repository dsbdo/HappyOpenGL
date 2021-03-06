#pragma once
#include <vector>
#include "Human.h"
#include "Background.h"
#include "ResourceManager.h"
#include "CubeRender.h"
#include "Camera.h"
#include "Ball.h"
namespace lmm {
	enum GameState {
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
	//定义一个跳动小人 用一个球来模拟

	//定义一副平板地图
	
	//定义很多立方体，立方块当成落地点

	//小人按space 蓄力， 45度抛物线斜抛

	class JumpGame
	{
	public:
		JumpGame();
		JumpGame(GLuint width, GLuint height);
		~JumpGame();
		//render 函数
		void render();
		//碰撞检测
		void checkCollision();
		void doCollision();

		//初始化load the basic resource 
		void init();
		void processInput(GLfloat dt) ;
		void processMouse(double xpos, double ypos);
		void processScroll(double xoffset, double yoffset);
		void update(GLfloat dt);

		GLboolean game_state_;
		GLuint width_, height_;
		GLboolean keys_[1024];
	private:
		Human* human;
		Background* background;
		//CubeRender* cube_render;
		std::vector<CubeRender> cube_array_;
		Camera* camera;
		Ball* light_;
		float last_x_;
		float last_y_;
		bool first_mouse_;

	};
}// namespce lmm over;


