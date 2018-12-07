#pragma once
#include "Human.h"

namespace lmm {
	//定义一个跳动小人 用一个球来模拟

	//定义一副平板地图
	
	//定义很多立方体，立方块当成落地点

	//小人按space 蓄力， 45度抛物线斜抛

	class JumpGame
	{
	public:
		JumpGame();
		~JumpGame();
		//render 函数
		void render();
		//碰撞检测
		void checkCollision(GameObject &one, GameObject &two);
		void doCollision();
	private:
		Human* human;
		CubeRender* cube_render;
	};
}// namespce lmm over;


