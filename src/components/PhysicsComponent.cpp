#include <iostream>
#include <Box2D/Box2D.h>
#include "PhysicsComponent.h"

void PhysicsComponent::update(const Update& update)
{
	(void) update;

	b2Vec2 position = body->GetPosition();
	if (xpos != position.x || ypos != position.y) {
		Message msg(MSG_POSITION_UPDATE);
		xpos = position.x;
		ypos = position.y;
		msg.getData()->position.x = (int) (xpos * PPM);
		msg.getData()->position.y = (int) -(ypos * PPM);
		entity->transmit(msg);
		float angle = body->GetAngle();
		std::cout << "Pos: " << static_cast<int>(xpos * PPM)
			<< " x " << -static_cast<int>(ypos * PPM)
			<< " * " << angle << std::endl;
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
