#include <SDL.h>
#include "MobileSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"

#include <iostream>
#include <math.h>

using namespace mcDirr;

void MobileSprite::setHealth(int newHealth) {
	health = newHealth;
}

void MobileSprite::changeHealth(int impact) {
	health += impact;
}

MobileSprite::MobileSprite(SDL_Surface* surf, int x, int y, SDL_Texture* healthSym) : Sprite(surf, x, y), healthSymbol(healthSym){
	surface = surf;
	currentTime = 0;

	onGround = false;
	alive = true;
	health = 1;

	debounceVel = 0.15;
	yVel = xVel = 0;
	yAccel = 9.82 / 5;
	xAccel = 0;
}

void MobileSprite::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void MobileSprite::drawHealth() const {

}

void MobileSprite::doPhysics(int millisPassed) {
	double secsPassed = millisPassed / 1000.0;

	if (!onGround) {
		xVel += xAccel * secsPassed;
		yVel += yAccel * secsPassed;
	} else {
		if (fabs(xVel) <= debounceVel)
			xVel = 0;
		if (fabs(yVel) <= debounceVel)
			yVel = 0;
	}

	dest.x += xVel * millisPassed;
	dest.y += yVel * millisPassed;
}

void MobileSprite::tick(int time) {
	doPhysics(time);
	checkBounds();
}

void MobileSprite::checkBounds() {
	int winWidth = 0;
	int winHeight = 0;

	SDL_Window* window = sys.getWin();
	SDL_GetWindowSize(window, &winWidth, &winHeight);
	// std::cout << dest.x << " - " << winWidth << std::endl;

	if (dest.y > winHeight) {
		dest.x = 50;
		dest.y = 50;
		return;
	}

	if (dest.x <= 0) {
		dest.x = 1;
		return;
	}

	if (dest.x > winWidth) {
		dest.x = 50;
	}
}

void MobileSprite::checkCollisions(std::list<ImmobileSprite*>& others) {
	onGround = false;
	for (std::list<ImmobileSprite*>::iterator immobile = others.begin(); immobile != others.end();) {
		handleCollision(*immobile, checkCollision(*immobile));

		if (!(*immobile)->isAlive())
			immobile = others.erase(immobile);
		else
			immobile++;
	}
}

int MobileSprite::checkCollision(Sprite* other) const{
	SDL_Rect intersection;
	SDL_Rect& oDest = (* other->getDestRect());
	int side = 0;

	if (SDL_IntersectRect(&dest, &oDest, &intersection)) {
		const int& oX = oDest.x;
		const int& oY = oDest.y;
		const int& myX = dest.x;
		const int& myY = dest.y;

		if (intersection.h > intersection.w) {
			if (oX > myX) {
				side = 4;
			} else {
				side = 2;
			}
		} else {
			if (oY > myY) {
				side = 3;
			} else {
				side = 1;
			}
		}
	}
	return side;
}

void MobileSprite::handleCollision(ImmobileSprite* collidedWith, int side) {
	if (side) {
		SDL_Rect& oDest = (* collidedWith->getDestRect());
		int& oX = oDest.x;
		int& oY = oDest.y;
		int& myX = dest.x;
		int& myY = dest.y;

		if(side == 1) {
			myY = oY + oDest.h;
		} else if (side == 3) {
			myY = oY - dest.h;
			onGround = true;
		} else if (side == 2) {
			myX = oX + oDest.w;
		} else if (side == 4) {
			myX = oX - dest.w;
		}

		if (side == 1 || side == 3) {
			yVel *= -collidedWith->getBounciness();
			xVel = 0;
		}

		if (side == 4 || side == 2) {
			xVel *= -collidedWith->getBounciness();
		}
	}
}

bool MobileSprite::isAlive() const {
	return alive;
}

void MobileSprite::kill() {
	std::cout << "killed" << std::endl;
	alive = false;
}

SDL_Surface* MobileSprite::getSurface() const {
	return surface;
}
