#include "Player.hpp"
#include "../../Game/Game.hpp"
#include "../../CollisionChecker/CollisionChecker.hpp"

const int offset = 9; // spritesheet offset for each animation frame

//---------------------------------------------------------------------------
Player::Player ( const char * texturePath, Vector2 pos ) : Character( texturePath, pos ) {
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
	Character::update();

	srcR.x = 32 * currentFrame + offset;

		}
	}
}

//---------------------------------------------------------------------------
void Player::render() {
	if ( isLookingRight )
		SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
	else
		SDL_RenderCopyEx(Game::renderer, texture, &srcR, &dstR, 0, NULL, SDL_FLIP_HORIZONTAL);
}
