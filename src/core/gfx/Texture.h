#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "../struct/Dimension.h"

class Texture
{
	private:
		SDL_Texture *texture = nullptr;
		Dimension<uint32_t> dim;

	public:
		bool loadFromFile(const std::string& path, SDL_Renderer *renderer);

		void render(SDL_Renderer *renderer,
					const SDL_Rect* clip,
					const SDL_Rect* area);

		uint32_t getWidth() const;

		uint32_t getHeight() const;
};
