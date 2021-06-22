/**
* \brief Main class maintaining the basic game logic like updating, rendering and event handling.
*/

#pragma once

#include "../Entities/Player/Player.hpp"
#include "../Map/Map.hpp"
#include "../UI/HUD.hpp"

#include <SDL2/SDL.h>

class Game {
public:
	/**
	* Game constructor. Necessary for creating the game.
	* @param title window title
	* @param xpos x position of the game window
	* @param ypos y position of the game window
	* @param w width of the game window
	* @param h height of the game window
	* @param fullscreen fullscreen toggle flag
	*/
	Game ( const char * title, int xpos, int ypos, int w, int h, bool fullscreen );
	~Game ();


	/**
	* Handle events from keyboard and mouse and call appropriate methods to process them.
	* Controlling the player, pausing and quiting the game.
	*/
	void handleEvents ();
	/**
	* Update all game objects, typically by calling their *update()* method.
	*/
	void update ();
	/**
	* Render all game objects, typically by calling their *render()* method.
	*/
	void render () const;


	/**
	* Is game running?
	* @return a flag whether the game is running or not
	*/
	bool running () const { return isRunning; }
	/**
	* Is game stopped?
	* @return a flag whether the game is stopped or not
	*/
	bool stopped () const { return isPaused; }
	/**
	* Get rafresh rate of a monitor the game is rendering on.
	* @return monitor refresh rate
	*/
	int getRefreshRate () const;


	/**
	* If score is higher than the best previous score, save it to a file.
	*/
	void saveBestScore();


	//! game window width
	static int width;
	//! game window height
	static int height;
	//! game renderer rendering objects on the screen
	static SDL_Renderer * renderer;
	//! event object for handling input events
	static SDL_Event event;
	//! player's current reached score
	static int score;

private:
	bool isRunning;
	bool isPaused = false;

	bool esc_lock = false;
	bool left_lock = false;

	SDL_Window * window;
	Map * map;
	HUD *hud;

	Player * pl;

	int bestScore = 0;
};
