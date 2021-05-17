#include "Entity.hpp"

class Stationary : public Entity {
public:
	Stationary ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}
};
