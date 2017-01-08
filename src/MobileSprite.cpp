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

MobileSprite* MobileSprite::getInstance(SDL_Surface* surface, int x, int y, double s) {
	return new MobileSprite(surface, x, y, s);
}

MobileSprite::MobileSprite(SDL_Surface* surf, int x, int y, double bouciness) : Sprite(surf, x, y) {
	surface = surf;
	currentTime = 0;

	bounciness = bouciness;
	alive = true;

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

	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "I've been killed by Q" << std::endl;
		alive = false;
	}
}

void MobileSprite::checkCollision(ImmobileSprite* other) {
	SDL_Rect intersection;
	SDL_Rect& oDest = (* other->getDestRect());

	if (SDL_IntersectRect(&dest, &oDest, &intersection)) {

		int& oX = oDest.x;
		int& oY = oDest.y;
		int& myX = dest.x;
		int& myY = dest.y;

		if (intersection.h > intersection.w) {
			if (oX > myX) {
				myX = oX - dest.w;
			} else {
				myX = oX + oDest.w;
			}
			xVel = 0;
		} else {
			if (oY > myY) {
				myY = oY - dest.h;
			} else {
				myY = oY + oDest.h;
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

SDL_Surface* MobileSprite::getSurface() const {
	return surface;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
