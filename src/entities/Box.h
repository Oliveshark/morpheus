#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>

#include "../core/ecs/Entity.h"

class Box : public Entity
{

	public:
		static Box* createBox(const SDL_Rect& box, SDL_Color color);
};
