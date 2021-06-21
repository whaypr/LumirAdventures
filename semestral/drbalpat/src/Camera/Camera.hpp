/**
* \brief Class representing camera following the target (player) and capturing its surroundings.
* 
* Game object like tiles, enemies and bullets are rendered relatively to camera.
*
* This class is a singleton.
*/

#pragma once

#include "../Utils/Vector.hpp"

#include <SDL2/SDL.h>

class Camera {
public:
	/**
	* Get class instance to access its public interface.
	* @return instance pointer
	*/
	static Camera * getCamera () { return camera = camera ? camera : new Camera(); }


	/**
	* Update camera position to correspond with target's origin.
	*/
	void update ();


	/**
	* Set target to be followed.
	* @param t followed target, typically player's origin
	*/
	void setTarget ( Vector2 * t ) { target = t; }
	/**
	* Set width and height of the rectangle camera is capturing.
	* @param w camera view's width
	* @param h camera view's height
	*/
	void setView ( int w, int h ) { view = {0, 0, w, h}; }
	/**
	* Set total map width and height in pixels to correctly adjusting camera's view.
	* @param w map width
	* @param h map height
	*/
	void setMapSize ( int w, int h ) { mapW = w; mapH = h; }


	/**
	* Get information about rectangle camera is capturing.
	*/
	SDL_Rect getView ()  { return view; }
	/**
	* Get camera's position (top left corner of camera's view).
	*/
	Vector2 getPos ()  { return pos; }

private:
	Camera () {}
	static Camera * camera;

	Vector2 * target, pos;
	int mapW, mapH;
	SDL_Rect view;
};
