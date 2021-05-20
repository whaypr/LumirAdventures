#include "Player.hpp"

const int offset = 9; // spritesheet offset for each animation frame

//---------------------------------------------------------------------------
Player::Player ( const char * texturePath, Vector2 pos ) : Moving( texturePath, pos ) {
	isLookingRight = true;

	srcR.x = 0 + offset;
	srcR.y = 32 + offset;
	srcR.w = 32 - (offset * 2);
	srcR.h = 32 - offset;

	dstR.w = (32 - (offset * 2)) * 4;
	dstR.h = (32 - offset) * 4;
}

//---------------------------------------------------------------------------
void Player::update () {
	Moving::update();

	isGrounded = false;

	if ( velocity.x > 0 )
		isLookingRight = true;
	else if ( velocity.x < 0 )
		isLookingRight = false;

	// check collision
	for ( const auto & c : colCheck.checkCollision( pos, dstR.w, dstR.h ) ) {
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
		// on the ground
	if ( grounded() ) {
		if ( velocity.x || velocity.y ) {
			if ( lastTime + frameRate < SDL_GetTicks() ) {
				currentFrame = ( currentFrame + 1 ) % 4;
				lastTime = SDL_GetTicks();
			}
		} else
			currentFrame = 0;
		// in the air
	} else
		currentFrame = 1;

	srcR.x = 32 * currentFrame + offset;

	// reset x velocity for calculations in the next step
	velocity.x = 0;
}

//---------------------------------------------------------------------------
void Player::render() {
	if ( isLookingRight )
		SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
	else
		SDL_RenderCopyEx(Game::renderer, texture, &srcR, &dstR, 0, NULL, SDL_FLIP_HORIZONTAL);
}
