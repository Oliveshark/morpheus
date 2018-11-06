#include "Box.h"
#include "../components/PhysicsComponent.h"
#include "../components/RectangleDrawComponent.h"

Box* Box::createBox(const Update& update)
{
	(void) update;

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(10, 10, 32, 32));

	int x = 40, y = 10;

	float centerx = static_cast<float>(x + 32/2);
	float centery = static_cast<float>(y + 32/2);

	PhysicsComponent *pc = new PhysicsComponent();
	pc->bodyDef.type = b2_dynamicBody;
	pc->bodyDef.position.Set(centerx/PPM, -centery/PPM);
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

	int x = 40, y = 268;

	float centerx = static_cast<float>(x + 320/2);
	float centery = static_cast<float>(y + 32/2);

	Box *box = new Box();
	box->addComponent(new RectangleDrawComponent(x, y, 320, 32));

	PhysicsComponent *pc = new PhysicsComponent();
	pc->bodyDef.position.Set(centerx/PPM, -centery/PPM);
	pc->body = update.world->CreateBody(&pc->bodyDef);
	pc->shape.SetAsBox((320/2)/PPM, (32/2)/PPM);

	pc->body->CreateFixture(&pc->shape, 10.0f);
	box->addComponent(pc);

	return box;
}
