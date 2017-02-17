#include "InteractionSprite.hpp"
#include "Sprite.hpp"
#include "AnimatedMobileSprite.hpp"


namespace mcDirr {
	InteractionSprite::InteractionSprite(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _healthImpact, bool affectedByGravity, double Xvel, double Yvel):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), AnimatedMobileSprite(surf, x, y, divs, millisPerFrame), healthImpact(_healthImpact) {

		if (!affectedByGravity) {
			yAccel = 0;
			xAccel = 0;
		}
		xVel = Xvel;
		yVel = Yvel;

	}

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

	int InteractionSprite::getHealthImpact() {
		return healthImpact;
	}

	InteractionSprite::~InteractionSprite() {
		//dtor
	}
}
