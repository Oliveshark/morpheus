#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <sstream>

#include "Config.h"
#include "Timer.h"

static std::string gTitle;

static SDL_Window	*gWindow;
static SDL_Renderer	*gRenderer;

static bool initSDL()
{
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not initiate SDL2: " <<  SDL_GetError() << std::endl;
		return false;
	}

	if ( (IMG_Init(imgFlags) & imgFlags) == 0 ) {
		std::cerr
			<< "Unable to initiate img loading: "
			<< IMG_GetError()
			<< std::endl;
		return false;
	}

	std::stringstream ss;
	ss << APP_TITLE << " "
		<< MAJOR_VERSION << "."
		<< MINOR_VERSION << "."
		<< PATCH_VERSION << " "
		<< RELEASE_TYPE;
	gTitle = ss.str();

	gWindow = SDL_CreateWindow(gTitle.c_str(),
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, 
								400,
								300,
								SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	return true;
}

static void close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	IMG_Quit();
	SDL_Quit();
}

#define FPS 60
#define SCREEN_TICKS_PER_FRAME (1000 / FPS)

static int
gameLoop()
{
	Timer capTimer;
	bool quit = false;

	SDL_Event event;
	while (!quit) {
		capTimer.start();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				quit = true;
			if (event.type == SDL_KEYDOWN) {
				quit = event.key.keysym.sym == SDLK_ESCAPE;
			}
		}
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		// TODO: Game code

		SDL_RenderPresent(gRenderer);

		uint32_t frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	if (!initSDL())
		return 1;

	gameLoop();
	close();
}
