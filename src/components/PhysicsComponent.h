#pragma once

#include "Component.h"

class PhysicsComponent : public Component
{
	private:
		b2Body *body;

	public:
		PhysicsComponent(b2Body *b) : body(b) { };

		void update(const Update&) override;

		void receive(const std::string&) override;
};
