#include "Camera.hpp"

Camera * Camera::camera = nullptr;

void Camera::update () {
	view.x = target->x - view.w / 2;
	view.y = target->y - view.h / 2;

	if ( view.x < 0 )
		view.x = 0;
	if ( view.y < 0 )
		view.y = 0;

	if ( view.x > 64*35 - view.w )
		view.x = 64*35 - view.w;
	if ( view.y > 64*25 - view.h )
		view.y = 64*25 - view.h;
	

	pos = Vector2( view.x, view.y );
}
