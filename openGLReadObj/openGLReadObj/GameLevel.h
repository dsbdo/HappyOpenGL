#pragma once
#include <vector>
#include "GameObject.h"
#include "ResourceManager.h"
namespace lmm {
	class GameLevel
	{
	public:
		GameLevel();
		~GameLevel();
		std::vector<GameObject> bricks_;
		//load the level from file
		void load(const GLchar* file, GLuint level_width, GLuint level_height);
		//render level
		void draw(GeniusRender& genius);
		//check the level if complete
		GLboolean isComplete();
	private:
		void init(std::vector<std::vector<GLuint>> tile_data, GLuint level_width, GLuint level_height);
	};

}//namespace lmm over

