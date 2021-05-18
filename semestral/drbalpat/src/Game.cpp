#include "Game.hpp"
#include "TextureManager.hpp"
#include "CollisionChecker.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Camera.hpp"

#include <iostream>

SDL_Renderer * Game::renderer = nullptr;
SDL_Event Game::event;

//temp
Map * map;
Player *pl;

//---------------------------------------------------------------------------
void Game::init ( const char * title, int xpos, int ypos, int width, int height, bool fullscreen ) {
	int flags = 0;
	if ( fullscreen )
		flags = SDL_WINDOW_FULLSCREEN;

	if ( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if ( ! window )
			std::cout << "WINDOW CREATION ERROR!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if ( renderer ) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		} else
			std::cout << "RENDERER CREATION ERROR!" << std::endl;

		isRunning = true;
	} else {
		std::cout << "INIT ERROR!" << std::endl;
		isRunning = false;
		return;
	}

	//temp
	map = new Map();
	pl = new Player( "assets/images/characters.png", Vector2(600, 80) );

	Camera::getCamera()->setTarget( pl->getOrigin() );
}

//---------------------------------------------------------------------------
void Game::handleEvents () {
	SDL_PollEvent( &event );

	switch ( event.type ) {
		case SDL_QUIT:
			isRunning = false;
			break;
	}

	// keyboard input
	const Uint8 *state = SDL_GetKeyboardState(NULL);

		// player move
	if ( state[SDL_SCANCODE_A])
		pl->changeVelocity( -pl->getSpeed(), 0 );
	if ( state[SDL_SCANCODE_D] )
		pl->changeVelocity( pl->getSpeed(), 0 );
	if ( state[SDL_SCANCODE_SPACE] && pl->grounded() )
		pl->changeVelocity( 0, -8 );
}

//---------------------------------------------------------------------------
void Game::update () {
	//temp
	map->update();
	pl->update();

	Camera::getCamera()->update();
}

//---------------------------------------------------------------------------
void Game::render () {
	SDL_RenderClear(renderer);

	//temp
	map->render();
	pl->render();

	SDL_RenderPresent(renderer);
}

//---------------------------------------------------------------------------
void Game::clean () {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleaned!" << std::endl;
}

//---------------------------------------------------------------------------
int Game::getRefreshRate() {
	int displayIndex = SDL_GetWindowDisplayIndex( window );

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}
