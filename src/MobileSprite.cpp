#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "MobileSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"

#include <iostream>
#include <cmath>



using namespace mcDirr;

MobileSprite* MobileSprite::getInstance(SDL_Surface* surface, int x, int y, double s, bool mobile) {
	return new MobileSprite(surface, x, y, s, mobile);
}

MobileSprite::MobileSprite(SDL_Surface* surf, int x, int y, double bouciness, bool mbl) : Sprite(loader.loadTexture(surf), x, y) {
	surface = surf;
	currentTime = 0;

	bounciness = bouciness;
	alive = true;
	mobile = mbl;

	yVel = xVel = 0;
	yAccel = 9.82 / 5;
	xAccel = 0;
}

void MobileSprite::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void MobileSprite::doPhysics(int millisPassed) {
	double secsPassed = millisPassed / 1000.0;
	xVel += xAccel * secsPassed;
	yVel += yAccel * secsPassed;

//	xVel *= friction;
//	yVel *= friction;
//	std::cout << yVel << std::endl;

	dest.x += xVel * millisPassed;
	dest.y += yVel * millisPassed;
}

void MobileSprite::tick(int time) {
	if (mobile) {
		// ~ temporary for controls: ~
		if (sys.isKeyDown(SDLK_w))
			yVel = -0.5;
		else if (sys.isKeyDown(SDLK_s))
			yVel = 0.5;
		if (sys.isKeyDown(SDLK_a))
			xVel = -0.5;
		else if (sys.isKeyDown(SDLK_d))
			xVel = 0.5;
		// ~ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ~

		doPhysics(time);
	}
	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "I've been killed by Q" << std::endl;
		alive = false;
	}
}

void MobileSprite::checkCollision(MobileSprite* other) {
	SDL_Rect intersection;
	bool collided = false;

	if (SDL_IntersectRect(getRect(), other->getRect(), &intersection)) {

		int& oX = other->dest.x;
		int& oY = other->dest.y;
		int& myX = dest.x;
		int& myY = dest.y;

		if (intersection.h > intersection.w) {
			if (oX > myX) {
				myX = oX - other->dest.w;
			} else {
				myX = oX + dest.w;
			}
			xVel = 0;
		} else {
			if (oY > myY) {
				myY = oY - other->dest.h;
			} else {
				myY = oY + dest.h;
			}
			yVel = 0;
			xVel = 0;

		}
	}
}


bool MobileSprite::pixelCollision(SDL_Rect* tempRect, SDL_Surface* otherSurf) {
	// std::cout << "Hello" << std::endl;

	int tempX = tempRect->x;
	int tempY = tempRect->y;

	int xDiff = tempX - dest.x;
	int yDiff = tempY - dest.y;





	return false;
}

bool MobileSprite::isAlive() const {
	return alive;
}

bool MobileSprite::isMobile() const {
	return mobile;
}

SDL_Surface* MobileSprite::getSurface() const {
	return surface;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
