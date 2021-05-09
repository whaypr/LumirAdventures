#include "Entity.hpp"

class Moving : public Entity {
public:
	Moving ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}

protected:
	Vector2 velocity;
};
