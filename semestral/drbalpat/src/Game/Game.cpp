#include "Game.hpp"
#include "../TextureManager/TextureManager.hpp"
#include "../Entities/EntityManager/EntityManager.hpp"
#include "../CollisionChecker/CollisionChecker.hpp"
#include "../Camera/Camera.hpp"
#include "../UI/Pause.hpp"
#include "../Entities/Enemies/Enemy.hpp"

#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <fstream>

int Game::width, Game::height;
SDL_Renderer * Game::renderer;
SDL_Event Game::event;
int Game::score = 0;

//---------------------------------------------------------------------------
Game::Game ( const char * title, int xpos, int ypos, int w, int h, bool fullscreen ) {
	width = w;
	height = h;

	int flags = 0;
	if ( fullscreen )
		flags = SDL_WINDOW_FULLSCREEN;

	if ( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if ( ! window )
			std::cerr << "WINDOW CREATION ERROR!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if ( renderer ) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		} else
			std::cerr << "RENDERER CREATION ERROR!" << std::endl;

		isRunning = true;

		if ( TTF_Init() == -1 )
			std::cerr << "TTF ERROR" << std::endl;
	} else {
		std::cerr << "INIT ERROR!" << std::endl;
		isRunning = false;
		return;
	}

	map = new Map();
	hud = new HUD();

	// entities creation
	pl = new Player( "assets/images/characters.png", Vector2(600, 80) );
	EntityManager::getInstance()->addEntity( "player", std::shared_ptr<Player>(pl) );

	Camera::getCamera()->setView( width, height );
	Camera::getCamera()->setTarget( pl->getOrigin() );

	// load best score from file
	std::ifstream ifs;
	ifs.open("examples/best_score.txt");

   	if( ifs ) {
		ifs >> bestScore;
		ifs.close();
	} else
		std::cerr << "Error: file could not be opened" << std::endl;
}

//---------------------------------------------------------------------------
Game::~Game () {
	delete pl;
	delete hud;
	delete map;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

//---------------------------------------------------------------------------
void Game::handleEvents () {
	SDL_PollEvent( &event );

	switch ( event.type ) {
		case SDL_QUIT:
			saveBestScore();
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			// pause the game
			if ( event.key.keysym.sym == SDLK_ESCAPE && ! esc_lock ) {
				isPaused = !isPaused;
				esc_lock = true; // cannot unpause until next press

			}
			break;
		case SDL_KEYUP:
			if ( event.key.keysym.sym == SDLK_ESCAPE )
				esc_lock = false;
			break;
	}

	if ( isPaused )
		return;

	// keyboard input
	const Uint8 *state = SDL_GetKeyboardState(NULL);

		// player move
	if ( state[SDL_SCANCODE_A])
		pl->changeVelocity( Vector2(-pl->getSpeed(), 0) );
	if ( state[SDL_SCANCODE_D] )
		pl->changeVelocity( Vector2(pl->getSpeed(), 0) );
	if ( state[SDL_SCANCODE_SPACE] && pl->grounded() )
		pl->changeVelocity( Vector2(0, -9) );

	// shoot
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		pl->shoot();
}

//---------------------------------------------------------------------------
void Game::update () {
	EntityManager::getInstance()->update();

	hud->SetHp( pl->getHp(), pl->getMaxHp() );
	hud->SetAmmo( pl->getAmmo() );
	hud->SetScore( score, bestScore );

	Camera::getCamera()->update();
}

//---------------------------------------------------------------------------
void Game::render () const {
	SDL_RenderClear(renderer);

	map->render();
	EntityManager::getInstance()->render();
	hud->render();

	if ( isPaused ) {
		Pause::getPause()->render();
	}

	SDL_RenderPresent(renderer);
}

//---------------------------------------------------------------------------
int Game::getRefreshRate() const {
	int displayIndex = SDL_GetWindowDisplayIndex( window );

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

//---------------------------------------------------------------------------
void Game::saveBestScore() {
	if ( score <= bestScore )
		return;

	std::ofstream ofs;
	ofs.open("examples/best_score.txt");

   	if( ! ofs ) {
		std::cerr << "Error: file could not be opened" << std::endl;
      	return;
	}

	ofs << score;
	ofs.close();
}
