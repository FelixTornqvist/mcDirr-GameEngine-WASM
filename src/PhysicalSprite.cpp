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



PhysicalSprite::PhysicalSprite(SDL_Surface* surface, int x, int y, double temporaryTestSpeed, bool abg) : Sprite(loader.loadTexture(surface), x, y) {
	currentTime = 0;
	ttSpeed = temporaryTestSpeed; // temporary just so that collision could be tested
	alive = true;
	affectedByGravity = abg;
	solidGround = false;
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
	if (affectedByGravity && !solidGround) { // if object should be affected by gravity and if its not standing on something solid
		gravity();
	}
	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "yes?" << std::endl;
		alive = false;
	}
	if (sys.isKeyDown(SDLK_r)) {
		yVelocity -= 5;
	}
	if (sys.isKeyDown(SDLK_d)) {
		dest.x += ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_a)) {
		dest.x -= ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_w)) {
		dest.y -= ttSpeed * time;
	}
	if (sys.isKeyDown(SDLK_s)) {
		dest.y += ttSpeed * time;
	}
}

// void PhysicalSprite::checkCollision(PhysicalSprite* other) {
// 	if ( SDL_HasIntersection(getRect(), other->getRect())) {

// 		std::cout << "box collision!" << std::endl;
// 	}
// }

void PhysicalSprite::checkCollision(PhysicalSprite* other) {
	SDL_Rect* result = new SDL_Rect;

	if (SDL_IntersectRect(getRect(), other->getRect(), (result))) {
		yVelocity = 0;
		other->yVelocity = 0;
		int tempX = result->x;
		int tempY = result->y;
 
 		int xDiff = tempX - dest.x;
 		int yDiff = tempY - dest.y;
 		// låt stå.

	}

	delete result;
}

bool PhysicalSprite::isAlive() const {
	return alive;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
