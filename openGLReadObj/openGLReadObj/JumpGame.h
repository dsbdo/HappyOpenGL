#pragma once
#include "Human.h"

namespace lmm {
	//����һ������С�� ��һ������ģ��

	//����һ��ƽ���ͼ
	
	//����ܶ������壬�����鵱����ص�

	//С�˰�space ������ 45��������б��

	class JumpGame
	{
	public:
		JumpGame();
		~JumpGame();
		//render ����
		void render();
		//��ײ���
		void checkCollision(GameObject &one, GameObject &two);
		void doCollision();
	private:
		Human* human;
		CubeRender* cube_render;
	};
}// namespce lmm over;


