#include "InteractionSprite.hpp"
#include "Sprite.hpp"
#include "AnimatedMobileSprite.hpp"


namespace mcDirr {
	InteractionSprite::InteractionSprite(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym) {	}

	void InteractionSprite::checkCollisions(std::list<MobileSprite*>& mobiles) {
		for (std::list<MobileSprite*>::iterator mobile = mobiles.begin(); mobile != mobiles.end();) {

			int side = MobileSprite::checkCollision(*mobile);
			if (side)
				checkPixelCollission(*mobile, side);

			if (!(*mobile)->isAlive())
				mobile = mobiles.erase(mobile);
			else
				mobile++;
		}
	}

	void InteractionSprite::checkPixelCollission(MobileSprite* other, int side) {
		// if (pixelcollission) :
		handleCollision(other, side);
	}

	void InteractionSprite::setHealtImpact(int impact) {
		healthImpact = impact;
	}

	int InteractionSprite::getHealthImpact() {
		return healthImpact;
	}

	void InteractionSprite::setAffectedByGravity(bool affected) {
		if (affected)
			yAccel = 9.82 / 5;
		else
			yAccel = 0;

	}

	InteractionSprite::~InteractionSprite() {
		//dtor
	}
}
