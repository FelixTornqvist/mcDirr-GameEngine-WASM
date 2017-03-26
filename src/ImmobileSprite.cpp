#include "ImmobileSprite.hpp"

namespace mcDirr {

	ImmobileSprite::ImmobileSprite(SDL_Surface* s, int x, int y, float b):
		Sprite(s, x, y), alive(true), bounciness(b) {}

	bool ImmobileSprite::isAlive() {
		return alive;
	}

	void ImmobileSprite::setBounciness(float bounce) {
		bounciness = bounce;
	}

	float ImmobileSprite::getBounciness() {
		return bounciness;
	}
}
