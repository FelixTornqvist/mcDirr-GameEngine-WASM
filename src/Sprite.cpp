#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include <stdexcept>

#include "Sprite.hpp"
#include "System.hpp"

namespace mcDirr {

	Sprite::Sprite(SDL_Texture* t, int x, int y) :
		texture(t) {
		int width;
		int height;
		SDL_QueryTexture(t, NULL, NULL, &width, &height);
		dest = { x, y, width, height };
	}

	SDL_Rect* Sprite::getDestRect() {
		return &dest;
	}

	SDL_Texture* Sprite::getTexture() const {
		return texture;
	}

	void Sprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
	}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}
}
