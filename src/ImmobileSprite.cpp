#include "ImmobileSprite.hpp"

namespace mcDirr {
	ImmobileSprite* ImmobileSprite::getInstance(SDL_Surface* s, int x, int y) {
		return new ImmobileSprite(s, x, y);
	}

	ImmobileSprite::ImmobileSprite(SDL_Surface* s, int x, int y): Sprite(s, x, y), alive(true) {}

	bool ImmobileSprite::isAlive() {
		return alive;
	}
	ImmobileSprite::~ImmobileSprite() {}
}
