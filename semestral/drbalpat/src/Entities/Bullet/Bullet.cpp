#include "Bullet.hpp"
#include "../../CollisionChecker/CollisionChecker.hpp"
#include "../Enemies/Enemy.hpp"

//---------------------------------------------------------------------------
Bullet::Bullet ( const char * texturePath, Vector2 pos, int direction, bool enableGravity ) :
	Moving( texturePath, pos, enableGravity ) {
	speed = 15;
	velocity = Vector2( direction * speed, 0 );
}

//---------------------------------------------------------------------------
void Bullet::update() {
	Moving::update();

	pos += velocity;
	timeLiving++;

	// tile collision and lifeSpan
	std::vector< std::pair<char, std::shared_ptr<Entity>> > col = CollisionChecker::getInstance()->checkCollision( "tile", pos, dstR.w, dstR.h );
	if ( ! col.empty() || timeLiving >= lifeSpan ) {
		isDestroyed = true;
		return;
	}
	
	// enemy collision
	col = CollisionChecker::getInstance()->checkCollision( "enemy", pos, dstR.w, dstR.h );
	if ( ! col.empty() ) {
		Enemy * enemy = static_cast<Enemy*>( col[0].second.get() ); // this Entity is always Enemy
		enemy->changeHP( -damage );

		isDestroyed = true;
		return;
	}
}
