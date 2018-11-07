#pragma once

#include <Box2D/Box2D.h>
#include "../core/ecs/Component.h"
#include "../core/ecs/Update.h"
#include "../core/ecs/Message.h"
#include "../core/struct/Vector2.h"
#include "../core/struct/Dimension.h"

#define PPM 15

class PhysicsComponent : public Component
{
	private:
		Vector2<int> renderPos;
		Dimension<int> renderDim;

		Vector2<float> worldPos;
		Dimension<float> worldDim;

	public:
		b2Body *body = nullptr;
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2PolygonShape shape;

	private:
		Vector2<int> asRenderPos(const Vector2<float>& wp);

	public:
		PhysicsComponent(int x, int y, int w, int h);

		PhysicsComponent(const Vector2<int>& pos, const Dimension<int>& dim) : 
			PhysicsComponent(pos.x, pos.y, dim.w, dim.h) { };

		PhysicsComponent(const SDL_Rect& rect) : 
			PhysicsComponent(rect.x, rect.y, rect.w, rect.h) { };

		void update(const Update&) override;

		void receive(const Message&) override;

		void buildBox(b2World *world);
};
