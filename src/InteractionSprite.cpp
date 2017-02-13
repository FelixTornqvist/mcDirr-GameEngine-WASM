#include "InteractionSprite.hpp"
#include "Sprite.hpp"
#include "AnimatedMobileSprite.hpp"


namespace mcDirr {
	InteractionSprite::InteractionSprite(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _damage, bool affectedByGravity, int Xvel, int Yvel):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), AnimatedMobileSprite(surf, x, y, divs, millisPerFrame), damage(_damage) {

		if (affectedByGravity) {
			yAccel = 0;
			xAccel = 0;
		}
		xVel = Xvel;
		yVel = Yvel;

	}

	void InteractionSprite::checkCollision(ImmobileSprite* other) {
		AnimatedMobileSprite::checkCollision(other);
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
