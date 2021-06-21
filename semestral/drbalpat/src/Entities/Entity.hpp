/**
* \brief Base class for all entities appearing in the game such as player, enemies, tiles or bullets.
*
* Basically everything with texture and position is entity (except for background).
*/

#pragma once

#include "../Utils/Vector.hpp"
#include <SDL2/SDL.h>

class Entity {
public:
	/**
	* Init entity texture, corresponding SDL_Rects and position.
	* @param texturePath path to file with texture used for entity
	* @param pos initial position of entity
	*/
	Entity ( const char * texturePath, Vector2 pos );
	virtual ~Entity ();


	/**
	* Update entity position and origin.
	* This method is often overriden by child classes, but original functionality is preserved.
	*/
	virtual void update ();
	/**
	* Render entity texture.
	* This method is often overriden by child classes, but original functionality is preserved.
	*/
	virtual void render () const;


	/**
	* Change texture and destroy the old one.
	*/
	void changeTexture ( const char * texturePath );
	/**
	* Get position (top left corner of *getPos()*).
	* @return entity position
	*/
	Vector2 getPos () const { return pos; }
	/**
	* Get rectangle representing texture.
	* @return texture rectangle
	*/
	SDL_Rect getRect () const { return dstR; }
	/**
	* Get pointer to a center of the entity texture.
	* @return entity origin
	*/
	Vector2 * getOrigin () { return &origin; }


	/**
	* Is entity destroyed?
	* @return flag whether entity is destroyed or not
	*/
	bool destroyed () const { return isDestroyed; }

protected:
	Vector2 pos, origin;

	SDL_Texture * texture;
	SDL_Rect srcR, dstR;

	bool isDestroyed = false;
};
