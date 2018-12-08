#pragma once
#include "Human.h"
#include "Background.h"
#include "ResourceManager.h"
namespace lmm {
	enum GameState {
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
	//����һ������С�� ��һ������ģ��

	//����һ��ƽ���ͼ
	
	//����ܶ������壬�����鵱����ص�

	//С�˰�space ������ 45��������б��

	class JumpGame
	{
	public:
		JumpGame();
		JumpGame(GLuint width, GLuint height);
		~JumpGame();
		//render ����
		void render();
		//��ײ���
		void checkCollision();
		void doCollision();

		//��ʼ��load the basic resource 
		void init();
		void processInput(GLfloat dt) ;
		void update(GLfloat dt);

		GLboolean game_state_;
		GLuint width_, height_;
		GLboolean keys_[1024];
	private:
		Human* human;
		Background* background;
		//CubeRender* cube_render;
	};
}// namespce lmm over;


