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

	// bullets
	for ( auto b = bullets.begin(); b != bullets.end(); b++ ) {
		(*b)->update();
		if ( (*b)->destroyed() ) {
			delete (*b);
			bullets.erase(b++);
		}
	}
	fireCurrent++;
}

//---------------------------------------------------------------------------
void Player::render() {
	if ( isLookingRight )
		SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
	else
		SDL_RenderCopyEx(Game::renderer, texture, &srcR, &dstR, 0, NULL, SDL_FLIP_HORIZONTAL);

	// bullets
	for ( auto & b : bullets )
		b->render();
}

//---------------------------------------------------------------------------
void Player::shoot () {
	if ( ! ammo || fireCurrent < fireRate )
		return;

	fireCurrent = 0;
	ammo--;

	int direction = isLookingRight ? 1 : -1;
	Vector2 offset = Vector2( direction * 40, 0 );

    Bullet *b = new Bullet( "assets/images/bullet.png", *getOrigin() + offset, direction );
    bullets.emplace_back( b );
}
