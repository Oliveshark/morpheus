#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>

#include "../core/ecs/Entity.h"

class Box : public Entity
{
	public:
		static Box* createBox(const Update&);
		static Box* createFixedBox(const Update&, int x, int y, int w, int h);
};
