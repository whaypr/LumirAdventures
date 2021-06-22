#include "Player.hpp"
#include "../../Game/Game.hpp"
#include "../../CollisionChecker/CollisionChecker.hpp"
#include "../EntityManager/EntityManager.hpp"
#include "../Enemies/Enemy.hpp"

//---------------------------------------------------------------------------
Player::Player ( const char * texturePath, Vector2 pos ) : Character( texturePath, pos ) {
	anim->addFrame( "move", {9,42,15,22} );
	anim->addFrame( "move", {41,41,15,22} );
	anim->addFrame( "move", {72,42,16,22} );
	anim->addFrame( "move", {104,41,17,22} );
	anim->addFrame( "idle", {9,42,15,22} );
	anim->addFrame( "jump", {41,41,15,22} );
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
	// enemy collision: get damage when hit
	std::vector< std::pair<char, std::shared_ptr<Entity>> > col = CollisionChecker::getInstance()->checkCollision( "enemy", pos, dstR.w, dstR.h );
	if ( ! col.empty() ) {
		if ( lastHit >= invincibleFrames ) {
			lastHit = 0;

			Enemy * enemy = static_cast<Enemy*>( col[0].second.get() ); // this Entity is always Enemy
			hp -= enemy->getDamage();

			// game over
			if ( hp <= 0 )
				std::exit(1);
		}
	}
	fireCurrent++;
}

//---------------------------------------------------------------------------
void Player::render() const {
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
