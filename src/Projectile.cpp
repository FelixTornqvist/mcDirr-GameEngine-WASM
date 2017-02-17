#include "Projectile.hpp"

namespace mcDirr {
	Projectile::Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _damage, bool affectedByGravity, double Xvel, double Yvel):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), InteractionSprite(surf, x, y, divs, millisPerFrame, _damage, affectedByGravity, Xvel, Yvel) {
		//ctor
	}

	void Projectile::handleCollision(MobileSprite *collidedWith, int side) {
		collidedWith->kill();
		alive = false;
	}

	void Projectile::customTick(int millisPassed) {

		if (xVel < 0) {
			setStartFrame(0);
			setEndFrame(3);
			facingRight = false;
		} else if (xVel > 0) {
			setStartFrame(4);
			setEndFrame(7);
			facingRight = true;
		} else {
			if (!facingRight) {
				setStartFrame(0);
				setEndFrame(0);
			} else {
				setStartFrame(1);
				setEndFrame(1);
			}
		}
	}

	Projectile::~Projectile() {
		//dtor

	}
}
