#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <sstream>

#include <Box2D/Box2D.h>

#include "Config.h"
#include "core/util/Timer.h"
#include "core/input/Input.h"
#include "core/ecs/Update.h"
#include "core/struct/Stage.h"
#include "entities/Box.h"

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
	// Box2D world
	b2Vec2 gravity(0.0f, -30.0f);
	b2World world(gravity);

	// Box2D ground
	/*
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(10.0f, -300.0f);

	b2Body *groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 10.0f);
	*/

	// Box2D box
	/*
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 60/20);
	b2Body *body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
	*/
	
	float timestep = 1.0f/60.0f;
	int velocityIteration = 6;
	int positionIterations = 2;

	Timer capTimer;
	bool quit = false;

	Input input;

	Update update;
	update.input = &input;
	update.world = &world;
	update.renderer = gRenderer;

	Stage stage;
	stage.addEntity(Box::createBox(update));
	stage.addEntity(Box::createFixedBox(update));

	SDL_Event event;
	while (!quit) {
		capTimer.start();

		input.reset();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				quit = true;
			input.handleEvent(event);
		}

		if (input.isPressed(SDLK_ESCAPE)) {
			quit = true;
		}

		world.Step(timestep, velocityIteration, positionIterations);

		SDL_SetRenderDrawColor(gRenderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(gRenderer);

		stage.update(update);

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
