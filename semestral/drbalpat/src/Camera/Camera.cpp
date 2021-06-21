#include "Camera.hpp"

Camera * Camera::camera;

//---------------------------------------------------------------------------
void Camera::update () {
	view.x = target->x - view.w / 2;
	view.y = target->y - view.h / 2;

	if ( view.x < 0 )
		view.x = 0;
	if ( view.y < 0 )
		view.y = 0;

	if ( view.x > mapW - view.w )
		view.x = mapW - view.w;
	if ( view.y > mapH - view.h )
		view.y = mapH - view.h;

	pos = Vector2( view.x, view.y );
}
