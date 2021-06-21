/**
* \brief Class used for collision detection.
*
* This class is a singleton.
*/

#pragma once

#include "../Utils/Vector.hpp"
#include "../Entities/Entity.hpp"

#include <vector>
#include <memory>
#include <string>

class CollisionChecker {
public:
	/**
	* Get class instance to access its public interface.
	* @return instance pointer
	*/
	static CollisionChecker * getInstance() { return collisionChecker = collisionChecker ? collisionChecker : new CollisionChecker(); }


	/**
	* Find collisions using [AABB](https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection)
	* 2D collision detection mechanism.
	* @param entityID one of EntityManager's entity ID to restrict collision check only to entities with this ID
	* @param pos caller's position (top left)
	* @param w  caller's width
	* @param h  caller's height
	* @return all detected collisions,
			  first item of the pair is char indicating side of the collision (from caller's perspective),
			  second item is shared pointer to colliding entity
	*/
	std::vector< std::pair<char, std::shared_ptr<Entity>> > checkCollision ( std::string entityID, Vector2 pos, int w, int h );

private:
	CollisionChecker() {}
	static CollisionChecker * collisionChecker;
};
