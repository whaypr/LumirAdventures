#include "CollisionChecker.hpp"
#include "Map.hpp"

#include <iostream>

std::vector< std::pair<char, Vector2> > CollisionChecker::checkCollision ( Vector2 pos, int w, int h ) {
	std::vector< std::pair<char, Vector2> > res; // first: side of collision, second: pos of colliding tile

	for ( auto & t : Map::getTiles() ) {
		Vector2 tPos = t->getPos();
		int tileSize = 64;

		// AABB - collision occurs
		if ( pos.x + w >= tPos.x &&
		     tPos.x + tileSize >= pos.x &&
		     pos.y + h >= tPos.y &&
		     tPos.y + tileSize >= pos.y
		   )
		{
			// from which sides there is a collision
			float b_clsn = ( pos.y + h         ) - tPos.y; // ( player bottom )
			float t_clsn = ( tPos.y + tileSize ) -  pos.y; // ( tiles bottom )
			float r_clsn = ( pos.x + w         ) - tPos.x; // ( player right )
			float l_clsn = ( tPos.x + tileSize ) -  pos.x; // ( tiles right )

				// bottom collision
			if (b_clsn < t_clsn && b_clsn < r_clsn && b_clsn < l_clsn ) {
				res.push_back( std::make_pair('b', tPos) );
			}
				// top collision
			if (t_clsn < b_clsn && t_clsn < r_clsn && t_clsn < l_clsn) {
				res.push_back( std::make_pair('t', tPos) );
			}
				// right collision
			if (r_clsn < l_clsn && r_clsn < b_clsn && r_clsn < t_clsn) {
				res.push_back( std::make_pair('r', tPos) );
			}
				// left collision
			if (l_clsn < r_clsn && l_clsn < b_clsn && l_clsn < t_clsn ) {
				res.push_back( std::make_pair('l', tPos) );
			}
		}
	}

	return res;
}
