#include "Enemy.hpp"
#include "../../Game/Game.hpp"
#include "../../CollisionChecker/CollisionChecker.hpp"

//---------------------------------------------------------------------------
Enemy::Enemy ( const char * texturePath, Vector2 pos ) : Character( texturePath, pos ) {
}

//---------------------------------------------------------------------------
void Enemy::update() {
	Character::update();

	if ( hp <= 0 )
		isDestroyed = true;
}
