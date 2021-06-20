#pragma once

#include "../Math/Math.hpp"
#include "../Entities/Entity.hpp"

#include <vector>
#include <memory>
#include <string>

class CollisionChecker {
public:
	static CollisionChecker * getInstance() { return collisionChecker = collisionChecker ? collisionChecker : new CollisionChecker(); }

	std::vector< std::pair<char, std::shared_ptr<Entity>> > checkCollision ( std::string entityID, Vector2 pos, int w, int h );

private:
	CollisionChecker() {}
	static CollisionChecker * collisionChecker;
};
