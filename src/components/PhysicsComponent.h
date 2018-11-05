#pragma once

#include "../core/ecs/Component.h"
#include "../core/ecs/Update.h"
#include "../core/ecs/Message.h"

class PhysicsComponent : public Component
{
	private:
		b2Body *body;

	public:
		PhysicsComponent(b2Body *b) : body(b) { };

		void update(const Update&) override;

		void receive(const Message&) override;
};
