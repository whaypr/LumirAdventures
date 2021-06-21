/**
* \brief Class used for creating pause menu indicating that game is paused and thus not updated periodically.
*
* This class is a singleton.
*/

#pragma once

#include <SDL2/SDL.h>

class Pause {
public:
	/**
	* Get class instance to access its public interface.
	* @return instance pointer
	*/
	static Pause * getPause () { return pause = pause ? pause : new Pause(); }	
	~Pause ();

	void render () const;

private:
	Pause ();
	static Pause * pause;

	SDL_Texture * title;
	SDL_Texture * background;

	SDL_Rect titlePos;
};
