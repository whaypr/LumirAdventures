#include "CollisionChecker.hpp"
#include "../Map/Map.hpp"

std::vector< std::pair<char, std::shared_ptr<Tile>> > CollisionChecker::checkCollision ( Vector2 pos, int w, int h ) {
	std::vector< std::pair<char, std::shared_ptr<Tile>> > res; // first: side of collision, second: colliding tile

	for ( auto & t : Map::getTiles() ) {
		Vector2 tPos = t->getPos();
		SDL_Rect tRect = t->getRect();

		// AABB - collision occurs
		if ( pos.x + w >= tPos.x &&
		     tPos.x + tRect.w >= pos.x &&
		     pos.y + h >= tPos.y &&
		     tPos.y + tRect.h >= pos.y
		   )
		{
			// from which sides there is a collision
			float b_clsn = ( pos.y + h         ) - tPos.y; // ( player bottom )
			float t_clsn = ( tPos.y + tRect.h ) -  pos.y; // ( tiles bottom )
			float r_clsn = ( pos.x + w         ) - tPos.x; // ( player right )
			float l_clsn = ( tPos.x + tRect.w ) -  pos.x; // ( tiles right )

				// bottom collision
			if (b_clsn < t_clsn && b_clsn < r_clsn && b_clsn < l_clsn ) {
				res.push_back( std::make_pair('b', t) );
			}
				// top collision
			if (t_clsn < b_clsn && t_clsn < r_clsn && t_clsn < l_clsn) {
				res.push_back( std::make_pair('t', t) );
			}
				// right collision
			if (r_clsn < l_clsn && r_clsn < b_clsn && r_clsn < t_clsn) {
				res.push_back( std::make_pair('r', t) );
			}
				// left collision
			if (l_clsn < r_clsn && l_clsn < b_clsn && l_clsn < t_clsn ) {
				res.push_back( std::make_pair('l', t) );
			}
		}
	}

	return res;
}
