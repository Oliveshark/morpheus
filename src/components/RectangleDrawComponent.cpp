#include "RectangleDrawComponent.h"

void RectangleDrawComponent::update(const Update& update)
{
	SDL_SetRenderDrawColor(update.renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_Rect rect = { pos.x, pos.y, dim.w, dim.h };
	SDL_RenderDrawRect(update.renderer, &rect);
}

void RectangleDrawComponent::receive(const Message& msg)
{
	if (msg.getType() != MSG_POSITION_UPDATE)
		return;

	pos = msg.getData()->position;
}
