#include "Player.hpp"

const int offset = 9; // spritesheet offset for each animation frame

Player::Player ( const char * texturePath, Vector2 pos ) : Moving( texturePath, pos ) {
	isLookingRight = true;

	srcR.x = 0 + offset;
	srcR.y = 32 + offset;
	srcR.w = 32 - (offset * 2);
	srcR.h = 32 - offset;

	dstR.w = (32 - (offset * 2)) * 4;
	dstR.h = (32 - offset) * 4;
}

void Player::update ( std::vector< std::unique_ptr<Tile> > & tiles ) {
	Moving::update();

	velocity = {0,0};

	// movement
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if ( state[SDL_SCANCODE_W] ) {
		velocity.y -= 4;
	} if ( state[SDL_SCANCODE_S]) {
		velocity.y += 4;
	} if ( state[SDL_SCANCODE_A]) {
		velocity.x -= 4;
		isLookingRight = false;
	} if ( state[SDL_SCANCODE_D] ) {
		velocity.x += 4;
		isLookingRight = true;
	}

	//temp
	// tiles collision
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
			float player_bottom = pos.y + dstR.h;
			float tiles_bottom = tPos.y + tileSize;
			float player_right = pos.x + dstR.w;
			float tiles_right = tPos.x + tileSize;

			float b_collision = tiles_bottom - pos.y;
			float t_collision = player_bottom - tPos.y;
			float l_collision = player_right - tPos.x;
			float r_collision = tiles_right - pos.x;

			// bottom collision
			if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision )
				if ( velocity.y > 0 ) velocity.y = 0;
			// top collision
			if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision)
				if ( velocity.y < 0 ) velocity.y = 0;
			// right collision
			if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision)
				if ( velocity.x > 0 ) velocity.x = 0;
			// left collision
			if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision )
				if ( velocity.x < 0 ) velocity.x = 0;
		}
	}

	// position update
	pos.x += velocity.x;
	pos.y += velocity.y;

	// animation
	if ( velocity.x || velocity.y ) {
		cnt++;
		srcR.x = 32 * ( (int)std::floor(cnt / 10) % 4 ) + offset;
	} else {
		srcR.x = 0 + offset;
	}
}

void Player::render() {
	if ( isLookingRight )
		SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
	else
		SDL_RenderCopyEx(Game::renderer, texture, &srcR, &dstR, 0, NULL, SDL_FLIP_HORIZONTAL);
}
