#pragma once

#include "Component.h"

class PhysicsComponent : public Component<int>
{
	private:
		b2Body *body;

	public:
		PhysicsComponent(b2Body *b) : body(b) { };
};
