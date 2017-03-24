#include "System.hpp"
#include "Projectile.hpp"

#define TEAM 3

namespace mcDirr {
	Projectile* Projectile::getInstance(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction) {
		return new Projectile(surf, x, y, divs, millisPerFrame, healthSym, xVel, direction);
	}

	Projectile::Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVelo, bool direction):
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym, TEAM) {
		if (direction)
			xVel = xVelo;
		else
			xVel = -xVelo;
	}

	void Projectile::handleMobileCollision(MobileSprite *collidedWith, int side) {
		if (side && collidedWith->getTeam() != TEAM && collidedWith->getTeam() != 1) {
			collidedWith->kill();
			alive = false;
		}
	}

	void Projectile::handleImmobileCollision(ImmobileSprite* collWith, int side) {
		if (side)
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
		checkBounds();
	}

	void Projectile::checkBounds() {
		int winWidth = 0;
		int winHeight = 0;

		SDL_Window* window = sys.getWin();
		SDL_GetWindowSize(window, &winWidth, &winHeight);

		if (getX() <= 0 || getX() >= winWidth || getY() <= 0 || getY() >= winHeight)
			alive = false;
	}

	Projectile::~Projectile() {
	}
}
