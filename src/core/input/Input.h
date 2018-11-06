#pragma once

#include <SDL.h>
#include <map>
#include "../struct/Vector2.h"

class Input
{
	private:
		std::map<uint32_t, bool> lastKeys, currentKeys;

	public:
		SDL_Renderer *renderer = nullptr;
		Vector2<int> mousePosition = Vector2(0, 0);	

	private:
		void setKey(uint32_t key, bool down);

	public:
		Input() { }

		void reset();

		void handleEvent(const SDL_Event&);

		bool isDown(uint32_t key) const;

		bool isPressed(uint32_t key) const;

		bool isReleased(uint32_t key) const;
};
