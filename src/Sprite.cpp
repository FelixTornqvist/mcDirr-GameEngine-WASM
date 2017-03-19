#include <SDL.h>
#include <SDL_image.h>
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

	int Sprite::getX() const {
		return dest.x;
	}

	int Sprite::getY() const {
		return dest.y;
	}

	void Sprite::setX(int x) {
		dest.x = x;
	}

	void Sprite::setY(int y) {
		dest.y = y;
	}


	int Sprite::getWidth() const {
		return dest.w;
	}

	int Sprite::getHeight() const {
		return dest.h;
	}

	void Sprite::setWidth(int w) {
		dest.w = w;
	}

	void Sprite::setHeight(int h) {
		dest.h = h;
	}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}
}
