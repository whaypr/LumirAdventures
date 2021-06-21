#include "Game/Game.hpp"

using namespace std;

int main ( int argc, char * argv[] ) {
	Game game( "Unbelievable adventures of Lumír the Heartshooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 960, false );

	const int FPS = game.getRefreshRate();
	const int frameDelay = 1000 / FPS;

	while ( game.running() ) {
		Uint32 frameStart = SDL_GetTicks();

		game.handleEvents();
		if ( ! game.stopped() )
			game.update();
		game.render();

		int frameTime = SDL_GetTicks() - frameStart;
		if ( frameDelay > frameTime )
			SDL_Delay( frameDelay - frameTime ) ;
	}

	return 0;
}
