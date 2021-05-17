#include "Entity.hpp"

class Moving : public Entity {
public:
	Moving ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}

	void update() override;
	void changeVelocity ( float x, float y );
	int getSpeed () { return speed; }

protected:
	const float gravity = .7;
	Vector2 velocity;
	int speed = 4;
};
