#pragma once

#include <Box2D/Box2D.h>
#include "../core/ecs/Component.h"
#include "../core/ecs/Update.h"
#include "../core/ecs/Message.h"

#define PPM 15

class PhysicsComponent : public Component
{
	private:
		float xpos, ypos;

	public:
		b2Body *body = nullptr;
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2PolygonShape shape;

	public:
		void update(const Update&) override;

		void receive(const Message&) override;
};
