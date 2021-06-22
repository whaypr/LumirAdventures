#include "Character.hpp"
#include "../CollisionChecker/CollisionChecker.hpp"

//---------------------------------------------------------------------------
Character::Character ( const char * texturePath, Vector2 pos ) : Moving( texturePath, pos ) {
	anim = new Animation( &srcR, &dstR );
}

//---------------------------------------------------------------------------
Character::~Character () {
	delete anim;
}

//---------------------------------------------------------------------------
void Character::update() {
	Moving::update();

	isGrounded = false;

	if ( velocity.x > 0 )
		isLookingRight = true;
	else if ( velocity.x < 0 )
		isLookingRight = false;

	// check collision
	for ( const auto & c : CollisionChecker::getInstance()->checkCollision( "tile", pos, dstR.w, dstR.h ) ) {
		Vector2 tPos = c.second->getPos();
		SDL_Rect tRect = c.second->getRect();

		switch ( c.first ) {
			case 'b':
				isGrounded = true;
				if ( velocity.y > 0 ) {
					velocity.y = 0;
					pos.y = tPos.y - dstR.h;
				}
				break;
			case 't':
				if ( velocity.y < 0 ) {
					velocity.y = 0;
					pos.y = tPos.y + tRect.h;
				}
				break;
			case 'r':
				if ( velocity.x > 0 ) {
					velocity.x = 0;
					if ( ! grounded() ) pos.x = tPos.x - dstR.w; // cond to prevent unwanted "teleportation"
				}
				break;
			case 'l':
				if ( velocity.x < 0 ) {
					velocity.x = 0;
					if ( ! grounded() ) pos.x = tPos.x + tRect.w; // cond to prevent unwanted "teleportation"
				}
				break;
		}
	}

	// position update
	pos += velocity;

	// animation
	if ( grounded() ) {
		if ( velocity.x || velocity.y )
			anim->animate("move");
		else
			anim->animate("idle");
	} else
		anim->animate("jump");

	// reset x velocity for calculations in the next step
	velocity.x = 0;
}

//---------------------------------------------------------------------------
void Character::changeHP ( int val ) {
	hp += val;
	hp = hp > max_hp ? max_hp : hp;
}
