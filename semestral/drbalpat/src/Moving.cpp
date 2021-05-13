#include "Moving.hpp"

void Moving::update() {
	Entity::update();

	velocity.y += gravity;
}
