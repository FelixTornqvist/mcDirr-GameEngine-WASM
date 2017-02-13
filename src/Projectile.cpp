#include "Projectile.hpp"

namespace mcDirr {
	Projectile::Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _damage, bool affectedByGravity, int Xvel, int Yvel):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), InteractionSprite(surf, x, y, divs, millisPerFrame, _damage, affectedByGravity, Xvel, Yvel) {
		//ctor
	}

	void Projectile::handleCollision(MobileSprite *collidedWith, int side) {

	}

	Projectile::~Projectile() {
		//dtor

	}
}
