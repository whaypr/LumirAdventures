#include "Entity.hpp"

class Moving : public Entity {
public:
	Moving ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}

	void update() override;

protected:
	const float gravity = .7;
	Vector2 velocity;
};
