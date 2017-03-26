#include <SDL.h>
#include "MobileSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"

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

		if (fabs(xVel) <= debounceVel) {
			xVel = 0;
		}

		if (fabs(yVel) <= debounceVel) {
			yVel = 0;
		}
	}

	dest.x += xVel * millisPassed;
	dest.y += yVel * millisPassed;
}

void MobileSprite::tick(int time) {
	doPhysics(time);
}

void MobileSprite::checkImmobileCollisions(std::list<std::shared_ptr<ImmobileSprite>>& others) {
	onGround = false;
	
	for (std::list<std::shared_ptr<ImmobileSprite>>::iterator immobile = others.begin(); immobile != others.end();) {
		handleImmobileCollision(*immobile, checkCollision(*immobile));

		if (!(*immobile)->isAlive()) {
			immobile = others.erase(immobile);
		} else {
			immobile++;
		}
	}
}

void MobileSprite::checkMobileCollisions(std::list<std::shared_ptr<MobileSprite>>& others) {
	for (std::list<std::shared_ptr<MobileSprite>>::iterator mob = others.begin(); mob != others.end(); mob++) {
		if ((*mob).get() != this && canCollide && (*mob)->canCollide) {

			int side = checkCollisionForMobile(*mob);
			if ((*mob)->getTeam() != getTeam()) {
				collisionBounce(*mob, side);
			}
			handleMobileCollision(*mob, side);
		}
	}
}

void MobileSprite::collisionBounce(std::shared_ptr<MobileSprite> collidedWith, int side) {
	if (bouncy && collidedWith->bouncy && side) {
		float upBounce = 0;

		if (onGround) {
			upBounce = 0.2f;
		}

		switch (side) {
			case 1:
				yVel = bounce;
				collidedWith->setYVel(-bounce);
				break;
			case 2:
				xVel = bounce;
				yVel = -upBounce;
				collidedWith->setXVel(-bounce);
				collidedWith->setYVel(-upBounce);
				break;
			case 3:
				yVel = -bounce;
				collidedWith->setYVel(bounce);
				break;
			case 4:
				xVel = -bounce;
				yVel = -upBounce;
				collidedWith->setXVel(bounce);
				collidedWith->setYVel(-upBounce);
				break;
		}
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

	SDL_PixelFormat* pfm = tempsurf->format;
	Uint8 r, g, b, alpha = 0;
	SDL_GetRGBA(pixel, pfm, &r, &g, &b, &alpha);

	// true if > 50% alpha
	return alpha > 0x0F;
}

/** returns the side that the other sprite collided with. 0:none, 1:top, 2:right, 3:bottom, 4:left */
int MobileSprite::checkCollisionForMobile(std::shared_ptr<MobileSprite> other) const {
	SDL_Rect intersection;
	SDL_Rect& oDest = (*other->getDestRect());

	if (SDL_IntersectRect(&dest, &oDest, &intersection)) {
		const int& oX = oDest.x;
		const int& oY = oDest.y;
		const int& myX = dest.x;
		const int& myY = dest.y;

		for (int i = 0; i < intersection.w; i++) {
			for (int a = 0; a < intersection.h; a++) {
				if (other->isPixelColored(intersection.x + i, intersection.y + a) && isPixelColored(intersection.x + i, intersection.y + a)) {

					if (intersection.h > intersection.w) {
						if (oX > myX) {
							return 4;
						} else {
							return 2;
						}
					} else {

						if (oY > myY) {
							return 3;
						} else {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int MobileSprite::checkCollision(std::shared_ptr<Sprite> other) const {
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

void MobileSprite::handleImmobileCollision(std::shared_ptr<ImmobileSprite> collidedWith, int side) {
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

void MobileSprite::setBounce(float boun) {
	bounce = boun;
}

void MobileSprite::setCanCollide(bool collide) {
	canCollide = collide;
}

void MobileSprite::setBouncy(bool bounce) {
	bouncy = bounce;
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

double MobileSprite::getXVel(double vel) const {
	return xVel;
}

double MobileSprite::getYVel(double vel) const {
	return yVel;
}

bool MobileSprite::isAlive() const {
	return alive;
}

void MobileSprite::setAlive(bool live) {
	alive = live;
}

void MobileSprite::showHealth(bool onOff) {
	renderHealth = onOff;
}

void MobileSprite::setSpriteOutbox(std::stack<std::shared_ptr<MobileSprite>>* ptr) {
	spriteOutbox = ptr;
}

std::stack<std::shared_ptr<MobileSprite>>* MobileSprite::getSpriteOutbox() const {
	return spriteOutbox;
}

void MobileSprite::kill() {
	alive = false;
}

SDL_Surface* MobileSprite::getSurface() const {
	return surface;
}
