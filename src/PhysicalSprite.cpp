#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"
#include <iostream>



using namespace mcDirr;

PhysicalSprite* PhysicalSprite::getInstance(SDL_Texture* t, int x, int y, double s) {
	return new PhysicalSprite(t, x, y, s);
}

PhysicalSprite::PhysicalSprite(SDL_Texture* t, int x, int y, double temporaryTestSpeed) : Sprite(t, x, y) {
	currentTime = 0;
	ttSpeed = temporaryTestSpeed; // temporary just so that collision could be tested
	alive = (true);
}

void PhysicalSprite::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void PhysicalSprite::tick(int time) {
	if (sys.isKeyDown(SDLK_q)) {
		std::cout << "yes?" << std::endl;
		alive = false;
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
		uint tempX = result->x;
		uint tempY = result->y;
 
 		int xDiff = tempX - dest.x;
 		int yDiff = tempY - dest.y;

 		


	}

	delete result;
}

bool PhysicalSprite::isAlive() const {
	return alive;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
