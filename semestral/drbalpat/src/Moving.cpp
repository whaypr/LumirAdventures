#include "Moving.hpp"

void Moving::update() {
	Entity::update();

	velocity.y += gravity;
}

//---------------------------------------------------------------------------
void Moving::changeVelocity ( float x, float y ) {
	velocity.x += x;
	velocity.y += y;
}
