#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>

#include "Entity.h"

class Box : public Entity<int>
{

	public:
		static Box* createBox(const SDL_Rect& box, SDL_Color color);
};
