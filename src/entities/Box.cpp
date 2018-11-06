#include "Box.h"
#include "../components/PhysicsComponent.h"
#include "../components/RectangleDrawComponent.h"

Box* Box::createBox(const Update& update)
{
	(void) update;

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(10, 10, 32, 32));

	PhysicsComponent *pc = new PhysicsComponent();
	pc->bodyDef.type = b2_dynamicBody;
	pc->bodyDef.position.Set(10/PPM, -10/PPM);
	pc->body = update.world->CreateBody(&pc->bodyDef);
	pc->shape.SetAsBox((32/2)/PPM, (32/2)/PPM);

	pc->fixtureDef.shape = &pc->shape;
	pc->fixtureDef.density = 1.0f;
	pc->fixtureDef.friction = 0.3f;

	pc->body->CreateFixture(&pc->fixtureDef);
	box->addComponent(pc);

	return box;
}

Box* Box::createFixedBox(const Update& update)
{
	(void) update;

	int x = 5, y = 268;

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(x, y, 320, 32));

	PhysicsComponent *pc = new PhysicsComponent();
	pc->bodyDef.position.Set((float) x/PPM, -(float) y/PPM);
	pc->body = update.world->CreateBody(&pc->bodyDef);
	pc->shape.SetAsBox((320/2)/PPM, (32/2)/PPM);

	pc->body->CreateFixture(&pc->shape, 10.0f);
	box->addComponent(pc);

	return box;
}
