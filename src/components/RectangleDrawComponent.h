#pragma once

#include <SDL.h>
#include "../core/ecs/Component.h"
#include "../core/struct/Vector2.h"
#include "../core/struct/Dimension.h"

class RectangleDrawComponent : public Component
{
	private:
		Vector2<int> pos;
		Dimension<int> dim;

	public:
		RectangleDrawComponent(int x, int y, int w, int h) :
			pos(x, y),
			dim(w, h) { };

		void update(const Update&) override;

		void receive(const Message&) override;
};
