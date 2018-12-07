#include "BallObject.h"

namespace lmm {

	BallObject::BallObject() :GameObject(), radius_(12.5f), stuck_(true)
	{
	}

	BallObject::BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture texture_image)
		: GameObject(pos, glm::vec2(radius * 2, radius * 2), texture_image, glm::vec3(1.0f), velocity), radius_(radius), stuck_(true)
	{

	}


	BallObject::~BallObject()
	{
	}

	glm::vec2 BallObject::move(GLfloat dt, GLuint window_width)
	{
		if (!this->stuck_) {
			this->position_ += this->velocity_ * dt;
			if (this->position_.x <= 0.0f) {
				this->velocity_.x = -this->velocity_.x;
				this->position_.x = 0.0f;
			}
			else if (this->position_.x + this->size_.x >= window_width) {
				this->velocity_.x = -this->velocity_.x;
				this->position_.x = window_width - this->size_.x;
			}
			if (this->position_.y <= 0.0f) {
				this->velocity_.y = -this->velocity_.y;
				this->position_.y = 0.0f;
			}
		}
		return this->position_;
	}

	void BallObject::reset(glm::vec2 position, glm::vec2 velocity)
	{
		this->position_ = position;
		this->velocity_ = velocity;
		this->stuck_ = true;
	}

}
