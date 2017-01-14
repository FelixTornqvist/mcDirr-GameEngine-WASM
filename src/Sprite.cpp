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
#include "Loader.hpp"

namespace mcDirr {

	Sprite::Sprite(SDL_Surface* surf, int x, int y) :
		texture(loader.loadTexture(surf)) {
		int width;
		int height;
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
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
