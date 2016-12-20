#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"
#include <iostream>



using namespace mcDirr;

PhysicalSprite* PhysicalSprite::getInstance(SDL_Surface* surface, int x, int y, double s, bool affectedByGravity) {
	return new PhysicalSprite(surface, x, y, s, affectedByGravity);
}

PhysicalSprite::PhysicalSprite(SDL_Surface* surf, int x, int y, double temporaryTestSpeed, bool abg) : Sprite(loader.loadTexture(surf), x, y) {
	surface = surf;
	currentTime = 0;
	ttSpeed = temporaryTestSpeed; // temporary just so that collision could be tested
	alive = true;
	affectedByGravity = abg;
	solidBelow = false;
	solidAbove = false;
	solidRight = false;
	solidLeft = false;
	yVelocity = 0;
}

void PhysicalSprite::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void PhysicalSprite::gravity() {
	std::cout << "" << yVelocity << std::endl;
	yVelocity += (9.82 / 20);
	dest.y += yVelocity;
}

void PhysicalSprite::tick(int time) {
	if (affectedByGravity && !solidBelow) { // if object should be affected by gravity and if its not standing on something solid
		gravity();
	}
	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "yes?" << std::endl;
		alive = false;
	}
	if (sys.isKeyDown(SDLK_r)) {
		yVelocity -= 5;
	}
	if (sys.isKeyDown(SDLK_d) && !solidRight) {
		dest.x += ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_a) && !solidLeft) {
		dest.x -= ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_w) && !solidAbove) {
		dest.y -= ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_s) && !solidBelow) {
		dest.y += ttSpeed * time;
	}
	solidAbove = false;
	solidBelow = false;
	solidRight = false;
	solidLeft = false;
}

void PhysicalSprite::checkCollision(PhysicalSprite* other) {
	SDL_Rect* result = new SDL_Rect;

	if (SDL_IntersectRect(getRect(), other->getRect(), (result))) {
		SDL_Rect* tempRect = result;

		if (getRect()->y < other->getRect()->y) {
			yVelocity = 0;
			solidBelow = true;
			other->yVelocity = 0;
			other->solidAbove = true;
		}
		if (getRect()->y > other->getRect()->y) {
			yVelocity = 0;
			solidAbove = true;
			other->yVelocity = 0;
			other->solidBelow = true;
		}

		if (getRect()->x > other->getRect()->x) {
			solidLeft = true;
			other->solidRight = true;
		}

		if (getRect()->x < other->getRect()->x) {
			solidRight = true;
			other->solidLeft = true;
		}
		
		pixelCollision(tempRect, other->getSurface());
	}

	delete result;
}

bool PhysicalSprite::isAlive() const {
	return alive;
}

SDL_Surface* PhysicalSprite::getSurface() const {
	return surface;
}


bool PhysicalSprite::pixelCollision(SDL_Rect* tempRect, SDL_Surface* otherSurf) {
	// std::cout << "Hello" << std::endl;

	int tempX = tempRect->x;
	int tempY = tempRect->y;
 
 	int xDiff = tempX - dest.x;
 	int yDiff = tempY - dest.y;





 	return false;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
