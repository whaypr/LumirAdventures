#include "Moving.hpp"

Moving::Moving ( const char * texturePath, Vector2 pos, bool enableGravity ) :
	Entity( texturePath, pos ),
	gravityEnabled ( enableGravity ) {}

//---------------------------------------------------------------------------
void Moving::update() {
	Entity::update();

	if ( gravityEnabled )
		velocity.y += gravity;
}

//---------------------------------------------------------------------------
void Moving::changeVelocity ( float x, float y ) {
	velocity.x += x;
	velocity.y += y;
}
