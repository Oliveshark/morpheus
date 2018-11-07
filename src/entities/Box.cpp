#include "Box.h"
#include "../components/PhysicsComponent.h"
#include "../components/RectangleDrawComponent.h"
#include "../core/struct/Vector2.h"

Box* Box::createBox(const Update& update)
{
	Vector2<int> pos(60, 10);
	Dimension<int> dim(32, 32);

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(pos, dim));

	PhysicsComponent *pc = new PhysicsComponent(pos, dim);
	pc->bodyDef.type = b2_dynamicBody;
	pc->fixtureDef.density = 1.0f;
	pc->fixtureDef.friction = 0.3f;
	pc->buildBox(update.world);
	box->addComponent(pc);

	return box;
}

Box* Box::createFixedBox(const Update& update,
						 int x,
						 int y,
						 int w,
						 int h)
{
	Vector2<int> pos(x, y);
	Dimension<int> dim(w, h);

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(pos, dim));

	PhysicsComponent *pc = new PhysicsComponent(pos, dim);
	pc->buildBox(update.world);
	box->addComponent(pc);

	return box;
}
