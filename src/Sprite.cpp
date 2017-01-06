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

	SDL_Rect* Sprite::getRect() {
		return &dest;
	}

	void Sprite::draw() const{
        SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
	}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}
}
