#pragma once

#include "Math.hpp"
#include "Tile.hpp"

#include <vector>
#include <memory>

class CollisionChecker {
public:
	std::vector< std::pair<char, std::shared_ptr<Tile>> > checkCollision ( Vector2 pos, int w, int h );
};
