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
void Player::update ( std::vector< std::unique_ptr<Tile> > & tiles ) {
	Moving::update();

	isGrounded = false;

	if ( velocity.x > 0 )
		isLookingRight = true;
	else if ( velocity.x < 0 )
		isLookingRight = false;

	checkCollision( tiles );

	// position update
	pos.x += velocity.x;
	pos.y += velocity.y;

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

//---------------------------------------------------------------------------
void Player::changeVelocity ( float x, float y ) {
	velocity.x += x;
	velocity.y += y;
}

//---------------------------------------------------------------------------
void Player::checkCollision ( std::vector< std::unique_ptr<Tile> > & tiles ) {
	for ( auto & t : tiles ) {
		Vector2 tPos = t->getPos();
		int tileSize = 64;

		// AABB - collision occurs
		if ( pos.x + dstR.w >= tPos.x &&
		     tPos.x + tileSize >= pos.x &&
		     pos.y + dstR.h >= tPos.y &&
		     tPos.y + tileSize >= pos.y
		   )
		{
			// from which sides there is a collision
			float b_colsn = ( tPos.y + tileSize ) -  pos.y; // ( tiles bottom )
			float t_colsn = ( pos.y + dstR.h    ) - tPos.y; // ( player bottom )
			float l_colsn = ( pos.x + dstR.w    ) - tPos.x; // ( player right )
			float r_colsn = ( tPos.x + tileSize ) -  pos.x; // ( tiles right )

			// bottom collision
			if (t_colsn < b_colsn && t_colsn < l_colsn && t_colsn < r_colsn ) {
				isGrounded = true;
				if ( velocity.y > 0 ) velocity.y = 0;
				pos.y = tPos.y - dstR.h;
			}
			// top collision
			if (b_colsn < t_colsn && b_colsn < l_colsn && b_colsn < r_colsn) {
				if ( velocity.y < 0 ) velocity.y = 0;
				pos.y = tPos.y + tileSize;
			}
			// right collision
			if (l_colsn < r_colsn && l_colsn < t_colsn && l_colsn < b_colsn) {
				if ( velocity.x > 0 ) velocity.x = 0;
				pos.x = tPos.x - dstR.w;
			}
			// left collision
			if (r_colsn < l_colsn && r_colsn < t_colsn && r_colsn < b_colsn ) {
				if ( velocity.x < 0 ) velocity.x = 0;
				pos.x = tPos.x + tileSize;
			}
		}
	}
}
