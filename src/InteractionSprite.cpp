#include "InteractionSprite.hpp"
#include "Sprite.hpp"
#include "MobileSprite.hpp"


namespace mcDirr {
	InteractionSprite::InteractionSprite(SDL_Surface *surf, int x, int y, int _damage, bool affectedByGravity, int Xvel, int Yvel):
		Sprite(surf, x, y), MobileSprite(surf, x, y), damage(_damage) {

		if (affectedByGravity) {
			yAccel = 0;
			xAccel = 0;
		}
		xVel = Xvel;
		yVel = Yvel;

	}

	void InteractionSprite::checkCollision(ImmobileSprite* other) {

	}

	void InteractionSprite::checkCollision(MobileSprite* other) {

	}

	int InteractionSprite::getDamage() {
		return damage;
	}

	InteractionSprite::~InteractionSprite() {
		//dtor
	}
}
