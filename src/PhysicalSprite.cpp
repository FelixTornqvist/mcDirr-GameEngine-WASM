#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"

#include <iostream>
#include <cmath>



using namespace mcDirr;

PhysicalSprite* PhysicalSprite::getInstance(SDL_Surface* surface, int x, int y, double s, bool solid) {
	return new PhysicalSprite(surface, x, y, s, solid);
}

PhysicalSprite::PhysicalSprite(SDL_Surface* surf, int x, int y, double bouciness, bool sld) : Sprite(loader.loadTexture(surf), x, y) {
	surface = surf;
	currentTime = 0;

	bounciness = bouciness;
	alive = true;
	solid = sld;

	yVel = xVel = 0;
	yAccel = 9.82 / 5;
	xAccel = 0;
}

void PhysicalSprite::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void PhysicalSprite::doPhysics(int millisPassed) {
	double secsPassed = millisPassed / 1000.0;
	xVel += xAccel * secsPassed;
	yVel += yAccel * secsPassed;
	std::cout << yVel << std::endl;

	dest.x += xVel * millisPassed;
	dest.y += yVel * millisPassed;
}

void PhysicalSprite::tick(int time) {
	if (!solid) {
		// ~ temporary for controls: ~
		if (sys.isKeyDown(SDLK_w))
			yVel = -1;
		if (sys.isKeyDown(SDLK_a))
			xVel = -1;
		else if (sys.isKeyDown(SDLK_d))
			xVel = 1;
		// ~ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ~

		doPhysics(time);
	}
	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "I've been killed by Q" << std::endl;
		alive = false;
	}
}

void PhysicalSprite::checkCollision(PhysicalSprite* other) {
	SDL_Rect intersection;
	bool collided = false;

	// needed for pixel-by-pixel bounce-back (later on)
	if (SDL_IntersectRect(getRect(), other->getRect(), &intersection)) {

//		if (pixelCollision(&intersection, other->getSurface())) {
//		}
		int& oX = other->dest.x;
		int& oY = other->dest.y;
		int& myX = dest.x;
		int& myY = dest.y;

		int xDiff = std::abs( oX - myX );
		int yDiff = std::abs( oX - myY );

		if( xDiff > yDiff ) {

			if (!other->solid) {
				if( oX > myX ) {
					oX = myX + dest.w;
				} else {
					oX = myX - other->dest.w;
				}
			} else {
			}

		} else {

			if (!other->solid) {
				if( oY > myY ) {
					oY = myY + dest.h;
				} else {
					oY = myY - other->dest.h;
				}
			} else {

			}
		}
	}

	if (collided) {
		yVel *= -bounciness;
		xVel *= -bounciness;
	}
}

inline void PhysicalSprite::bounceBack(int& myAxis, int& myPadding, int& othrsAxis, int& othrsPadding) {
	if( othrsAxis > myAxis ) {
		othrsAxis = myAxis + myPadding;
	} else {
		othrsAxis = myAxis - othrsPadding;
	}
}


bool PhysicalSprite::pixelCollision(SDL_Rect* tempRect, SDL_Surface* otherSurf) {
	// std::cout << "Hello" << std::endl;

	int tempX = tempRect->x;
	int tempY = tempRect->y;

	int xDiff = tempX - dest.x;
	int yDiff = tempY - dest.y;





	return false;
}

bool PhysicalSprite::isAlive() const {
	return alive;
}

SDL_Surface* PhysicalSprite::getSurface() const {
	return surface;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
