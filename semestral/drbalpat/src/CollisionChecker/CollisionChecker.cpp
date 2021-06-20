#include "CollisionChecker.hpp"
#include "../Entities/EntityManager/EntityManager.hpp"

CollisionChecker * CollisionChecker::collisionChecker = nullptr;

std::vector< std::pair<char, std::shared_ptr<Entity>> > CollisionChecker::checkCollision (  std::string entityID, Vector2 pos, int w, int h ) {
	std::vector< std::pair<char, std::shared_ptr<Entity>> > res; // first: side of collision, second: colliding tile

	for ( auto & e : EntityManager::getInstance()->getEntities( entityID ) ) {
		Vector2 tPos = e->getPos();
		SDL_Rect tRect = e->getRect();

		// AABB - collision occurs
		if ( pos.x + w >= tPos.x &&
		     tPos.x + tRect.w >= pos.x &&
		     pos.y + h >= tPos.y &&
		     tPos.y + tRect.h >= pos.y
		   )
		{
			// from which sides there is a collision
			float b_clsn = ( pos.y + h         ) - tPos.y; // ( entity bottom )
			float t_clsn = ( tPos.y + tRect.h ) -  pos.y; // ( tiles bottom )
			float r_clsn = ( pos.x + w         ) - tPos.x; // ( entity right )
			float l_clsn = ( tPos.x + tRect.w ) -  pos.x; // ( tiles right )

				// bottom collision
			if (b_clsn < t_clsn && b_clsn < r_clsn && b_clsn < l_clsn ) {
				res.push_back( std::make_pair('b', e) );
			}
				// top collision
			if (t_clsn < b_clsn && t_clsn < r_clsn && t_clsn < l_clsn) {
				res.push_back( std::make_pair('t', e) );
			}
				// right collision
			if (r_clsn < l_clsn && r_clsn < b_clsn && r_clsn < t_clsn) {
				res.push_back( std::make_pair('r', e) );
			}
				// left collision
			if (l_clsn < r_clsn && l_clsn < b_clsn && l_clsn < t_clsn ) {
				res.push_back( std::make_pair('l', e) );
			}
		}
	}

	return res;
}
