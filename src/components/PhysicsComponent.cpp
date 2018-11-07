#include <iostream>
#include <Box2D/Box2D.h>
#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(int x,
								   int y,
								   int w,
								   int h) :
	renderPos(x, y),
	renderDim(w, h)
{
	worldDim.w = static_cast<float>(renderDim.w)/PPM;
	worldDim.h = static_cast<float>(renderDim.h)/PPM;

	worldPos.x = static_cast<float>(renderPos.x + renderDim.w/2)/PPM;
	worldPos.y = -static_cast<float>(renderPos.y + renderDim.h/2)/PPM;

}

Vector2<int> PhysicsComponent::asRenderPos(const Vector2<float>& wp)
{
	Vector2<float> pos(wp.x*PPM, -wp.y*PPM);
	pos.x -= static_cast<float>(renderDim.w)/2;
	pos.y -= static_cast<float>(renderDim.h)/2;
	return Vector2<int>(static_cast<int>(pos.x), static_cast<int>(pos.y));
}

void PhysicsComponent::update(const Update& update)
{
	b2Vec2 position = body->GetPosition();
	if (worldPos.x != position.x || worldPos.y != position.y) {
		Message msg(MSG_POSITION_UPDATE);
		worldPos.x = position.x;
		worldPos.y = position.y;
		std::cout << "World position: " << worldPos << std::endl;
		renderPos = asRenderPos(worldPos);
		std::cout << "Render position: " << renderPos << std::endl;
		msg.getData()->position = renderPos;
		entity->transmit(msg);
	}

	if (update.input->isPressed(SDLK_SPACE)) {
		std::cout << "Jump" << std::endl;
		body->ApplyLinearImpulse( b2Vec2(0, 50), body->GetWorldCenter(), true );
	}
	if (update.input->isPressed(SDLK_d)) {
		std::cout << "Right" << std::endl;
		body->ApplyLinearImpulse( b2Vec2(50, 0), body->GetWorldCenter(), true );
	}
	if (update.input->isPressed(SDLK_a)) {
		std::cout << "Left" << std::endl;
		body->ApplyLinearImpulse( b2Vec2(-50, 0), body->GetWorldCenter(), true );
	}
}

void PhysicsComponent::receive(const Message& message)
{
	(void) message;
}

void PhysicsComponent::buildBox(b2World *world)
{
	bodyDef.position.Set(worldPos.x, worldPos.y);
	body = world->CreateBody(&bodyDef);
	shape.SetAsBox(worldDim.w/2, worldDim.h/2);

	fixtureDef.shape = &shape;

	body->CreateFixture(&fixtureDef);
}
