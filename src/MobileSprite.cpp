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

MobileSprite::MobileSprite(SDL_Surface* surf, int x, int y, SDL_Texture* healthSym, int teamNum) :
	Sprite(surf, x, y), healthSymbol(healthSym), teamNO(teamNum) {
	surface = surf;

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
	drawHealth();
}

void MobileSprite::drawHealth() const {
	if (renderHealth) {
		int width;
		int height;
		SDL_QueryTexture(healthSymbol, NULL, NULL, &width, &height);
		int startX = dest.x + dest.w/2 - (width * health) / 2;
		SDL_Rect pos = { startX, dest.y-height, width, height };

		for (int i = 0; i < health; i++) {
			SDL_RenderCopy(sys.getRen(), healthSymbol, NULL, &pos);
			pos.x += width;
		}

	}
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

void MobileSprite::checkImmobileCollisions(std::list<ImmobileSprite*>& others) {
	onGround = false;
	for (std::list<ImmobileSprite*>::iterator immobile = others.begin(); immobile != others.end();) {
		handleImmobileCollision(*immobile, checkCollision(*immobile));

		if (!(*immobile)->isAlive())
			immobile = others.erase(immobile);
		else
			immobile++;
	}
}

void MobileSprite::checkMobileCollisions(std::list<MobileSprite*>& others) {
	for (std::list<MobileSprite*>::iterator mob = others.begin(); mob != others.end(); mob++) {
		if (*mob != this)
			handleMobileCollision(*mob, checkCollisionForMobile(*mob));
	}
}


bool MobileSprite::isPixelColored(int x, int y) const {
	SDL_Surface* tempsurf = getSurface();
	int surfX = x - getX();
	int surfY = y - getY();
	SDL_LockSurface(tempsurf);
	Uint32* pixels = static_cast<Uint32*>(tempsurf->pixels);
	Uint32 pixel = pixels[surfY*tempsurf->w + surfX];
	SDL_UnlockSurface(tempsurf);
	//std::cout << pixel << std::endl;
	if (pixel > 0)
		return true;
	else
		return false;
}

int MobileSprite::checkCollisionForMobile(MobileSprite* other) const {
	SDL_Rect intersection;
	SDL_Rect& oDest = (*other->getDestRect());
	int side = 0;

	if (SDL_IntersectRect(&dest, &oDest, &intersection)) {
		const int& oX = oDest.x;
		const int& oY = oDest.y;
		const int& myX = dest.x;
		const int& myY = dest.y;

		if (intersection.h > intersection.w) {
			bool found = false;
			for (int i = 0; i < intersection.w; i++) {
				if (found) {
					break;
				}
				for (int a = 0; a < intersection.h; a++) {
					if (other->isPixelColored(intersection.x + i, intersection.y + a) && isPixelColored(intersection.x + i, intersection.y + a)) {
						//std::cout << "ja" << std::endl;
						if (oX > myX) {
							side = 4;
						}
						else {
							side = 2;
						}
						found = true;
						break;

					}
				}
			}
		}
		else {
			for (int i = 0; i < intersection.w; i++) {
				for (int a = 0; a < intersection.h; a++) {
					if (other->isPixelColored(intersection.x + i, intersection.y + a) && isPixelColored(intersection.x + i, intersection.y + a)) {
						if (oY > myY) {
							side = 3;
						}
						else {
							side = 1;
						}
						break;
					}
				}
			}
		}
		return side;
	}
}

int MobileSprite::checkCollision(Sprite* other) const {
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

void MobileSprite::handleImmobileCollision(ImmobileSprite* collidedWith, int side) {
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

int MobileSprite::getTeam() {
	return teamNO;
}

void MobileSprite::setXVel(double vel) {
	xVel = vel;
}

void MobileSprite::setYVel(double vel) {
	yVel = vel;
}

void MobileSprite::setXAccel(double acc) {
	xAccel = acc;
}

void MobileSprite::setYAccel(double acc) {
	yAccel = acc;
}

bool MobileSprite::isAlive() const {
	return alive;
}

void MobileSprite::showHealth(bool onOff) {
	renderHealth = onOff;
}

void MobileSprite::setSpriteOutbox(std::stack<MobileSprite*>* ptr) {
	spriteOutbox = ptr;
}

std::stack<MobileSprite*>* MobileSprite::getSpriteOutbox() const {
	return spriteOutbox;
}

void MobileSprite::kill() {
	alive = false;
}

SDL_Surface* MobileSprite::getSurface() const {
	return surface;
}
