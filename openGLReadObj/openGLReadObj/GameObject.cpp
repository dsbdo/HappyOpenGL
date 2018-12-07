#include "GameObject.h"
namespace lmm {
	GameObject::GameObject()
		:position_(0, 0), size_(1, 1), velocity_(0.0f), color_(1.0f), rotation_(0.0f), texture_(), is_solid_(false), destroyed_(false)
	{
	}

	GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color, glm::vec2 velocity)
		:position_(pos), size_(size), velocity_(velocity), color_(color), rotation_(0.0f), texture_(sprite), is_solid_(false),destroyed_(false)
	{

	}


	GameObject::~GameObject()
	{
	}

	void GameObject::draw(GeniusRender & genius)
	{
		genius.drawGenius(&this->texture_, this->position_, this->size_, this->rotation_, this->color_);
	}

}// namespace lmm over;


