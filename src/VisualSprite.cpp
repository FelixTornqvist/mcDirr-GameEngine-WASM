#include "VisualSprite.hpp"
#include "System.hpp"

namespace mcDirr {
	VisualSprite* VisualSprite::getInstance(SDL_Surface* s, int x, int y) {
		return new VisualSprite(s, x, y);
	}

	VisualSprite::VisualSprite(SDL_Surface* s, int x, int y) :
		Sprite(s, x, y) {
	}

	void VisualSprite::tick(int timeDiff) {
		if (sys.isKeyDown(SDLK_d)) {
			dest.x += 20;
		}
		if (sys.isKeyDown(SDLK_a)) {
			dest.x -= 20;
		}
		if (sys.isKeyDown(SDLK_w)) {
			dest.y -= 20;
		}
		if (sys.isKeyDown(SDLK_s)) {
			dest.y += 20;
		}
	}

	void VisualSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
	}

	VisualSprite::~VisualSprite() {
		//dtor
	}
}
