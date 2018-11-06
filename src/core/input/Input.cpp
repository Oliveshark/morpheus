#include "Input.h"

void Input::reset()
{
	lastKeys = currentKeys;
}

void Input::setKey(uint32_t key, bool down)
{
	currentKeys[key] = down;
	if (lastKeys.find(key) == lastKeys.end())
		lastKeys[key] = false;
}

void Input::handleEvent(const SDL_Event& event)
{
	if (event.type == SDL_MOUSEMOTION) {
		mousePosition.x = event.motion.x;
		mousePosition.y = event.motion.y;
	}

	if (event.type == SDL_KEYDOWN) {
		setKey(event.key.keysym.sym, true);
	} else if (event.type == SDL_KEYUP) {
		setKey(event.key.keysym.sym, false);
	}
}

bool Input::isDown(uint32_t key) const try
{
	return currentKeys.at(key);
} catch (...) {
	return false;
}

bool Input::isPressed(uint32_t key) const try
{
	return currentKeys.at(key) && !lastKeys.at(key);
} catch (...) {
	return false;
}

bool Input::isReleased(uint32_t key) const try
{
	return !currentKeys.at(key) && lastKeys.at(key);
} catch (...) {
	return false;
}
