/**
* \brief Class used for handling animations of entities.
*
* Each instance has its own frames categorized by their purpose (idle, move, jump, ...).
*/

#pragma once

#include <SDL2/SDL.h>

#include <map>
#include <string>
#include <vector>

class Animation {
public:
	/**
	* Create animation instance which have access to caller entity's source and destination texture rectangles.
	* @param src source rectangle pointer
	* @param dst destination rectangle pointer
	*/
	Animation ( SDL_Rect * src, SDL_Rect * dst ) : srcRect( src ), dstRect( dst ) {}


	/**
	* Add new animation frame.
	* @param id category id
	* @param frame SDL_Rect indicating frame's position and size within texture spritesheet
	*/
	void addFrame ( std::string id, SDL_Rect frame ) { animationFrames[id].push_back(frame); }
	/**
	* Set animation framerate. Bigger framerate => slower speed.
	* @param val new framerate value
	*/
	void setFrameRate ( Uint64 val ) { frameRate = val; }


	/**
	* Do the animation of type defined by given id. Do nothing if no animation of that type exists.
	* @param id animation type id
	*/
	void animate ( std::string id );

private:
	SDL_Rect * srcRect;
	SDL_Rect * dstRect;

	Uint64 frameRate = 150;
	int currentFrame = 0;
	int lastTime = 0;

	std::string lastID;

	std::map <
		std::string, // id
		std::vector<SDL_Rect> // frames
	> animationFrames;
};
