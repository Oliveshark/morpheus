#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>

#include "../input/Input.h"

class Update
{
	public:
		Input *input;
		SDL_Renderer *renderer;
		b2World *world;

	public:
		Update() { };
};
