#include "ImmobileSprite.hpp"

namespace mcDirr {
	ImmobileSprite* ImmobileSprite::getInstance(SDL_Texture* t, int x, int y) {
		return new ImmobileSprite(t, x, y);
	}

	ImmobileSprite::ImmobileSprite(SDL_Texture* t, int x, int y): Sprite(t, x, y), alive(true) {}

	bool ImmobileSprite::isAlive() {
		return alive;
	}
	ImmobileSprite::~ImmobileSprite() {}
}
