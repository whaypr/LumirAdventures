#include "Enemy.hpp"
#include "../../Game/Game.hpp"
#include "../../CollisionChecker/CollisionChecker.hpp"
#include "../EntityManager/EntityManager.hpp"
#include "../Pickups/BoxHp.hpp"
#include "../Pickups/BoxAmmo.hpp"

#include <ctime>

//---------------------------------------------------------------------------
Enemy::Enemy ( const char * texturePath, Vector2 pos ) : Character( texturePath, pos ) {
}

//---------------------------------------------------------------------------
void Enemy::update() {
	Character::update();

	if ( hp <= 0 ) {
		Game::score = Game::score * 1.1 + max_hp;

		// chance to drop a pickup
		std::srand ( time(NULL) ); // init pseudo RNG with seed
		int r = rand() % 10 + 1;
		if ( r >= 0 && r <= 2 ) {
			EntityManager::getInstance()->addEntity(
				"boxHp",
				std::make_shared<BoxHp>( "assets/images/pickups/hp.png", Vector2( origin.x, origin.y ) )
			);
		} else if ( r >= 3 && r <= 5 ) {
			EntityManager::getInstance()->addEntity(
				"boxAmmo",
				std::make_shared<BoxAmmo>( "assets/images/pickups/ammo.png", Vector2( origin.x, origin.y ) )
			);
		}

		isDestroyed = true;
	}
}
