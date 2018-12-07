#include "GameLevel.h"
#include <fstream>
#include <sstream>

namespace lmm {
	GameLevel::GameLevel()
	{
	}
	GameLevel::~GameLevel()
	{
	}

	void GameLevel::load(const GLchar * file, GLuint level_width, GLuint level_height)
	{
		//clear old data
		this->bricks_.clear();
		GLuint tile_code;
		GameLevel level;
		std::string line;
		std::ifstream input(file);
		std::vector<std::vector<GLuint>> tile_data;
		if (input) {
			while (std::getline(input, line))
			{
				std::istringstream str_stream(line);
				std::vector<GLuint> row;
				while (str_stream >> tile_code)
				{
					row.push_back(tile_code);
				}
				tile_data.push_back(row);
			}
			if (tile_data.size() > 0) {
				this->init(tile_data, level_width, level_height);
			}
		}
	}

	void GameLevel::draw(GeniusRender & genius)
	{
		for (GameObject& tile : this->bricks_) {
			if (!tile.destroyed_) {
				tile.draw(genius);
			}
		}
	}

	GLboolean GameLevel::isComplete()
	{
		for (GameObject& tile : this->bricks_) {
			if (!tile.is_solid_ && !tile.destroyed_) {
				return GL_FALSE;
			}
		}
		return GL_TRUE;
	}

	void GameLevel::init(std::vector<std::vector<GLuint>> tile_data, GLuint level_width, GLuint level_height)
	{
		GLuint height = tile_data.size();
		GLuint width = tile_data[0].size();
		GLfloat unit_width = level_width / static_cast<GLfloat>(width), unit_height = level_height / height;
		//init
		for (GLuint y = 0; y < height; ++y) {
			for (GLuint x = 0; x < width; ++x) {
				if (tile_data[y][x] == 1) // solid 
				{
					glm::vec2 pos(unit_width * x, unit_height * y);
					glm::vec2 size(unit_width, unit_height);
					GameObject obj(pos, size, ResourceManager::GetTexture("block_solid"), glm::vec3(0.8f, 0.8f, 0.7f));
					obj.is_solid_ = GL_TRUE;
					this->bricks_.push_back(obj);
				}
				else if (tile_data[y][x] > 1) {
					glm::vec3 color = glm::vec3(1.0f); // original: white
					if (tile_data[y][x] == 2)
						color = glm::vec3(0.2f, 0.6f, 1.0f);
					else if (tile_data[y][x] == 3)
						color = glm::vec3(0.0f, 0.7f, 0.0f);
					else if (tile_data[y][x] == 4)
						color = glm::vec3(0.8f, 0.8f, 0.4f);
					else if (tile_data[y][x] == 5)
						color = glm::vec3(1.0f, 0.5f, 0.0f);
					glm::vec2 pos(unit_width * x, unit_height * y);
					glm::vec2 size(unit_width, unit_height);
					this->bricks_.push_back(GameObject(pos, size, ResourceManager::GetTexture("block"), color));
				}

			}
		}

	}

}//namespace lmm over

