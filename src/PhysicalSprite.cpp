#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"
#include <iostream>



using namespace mcDirr;

PhysicalSprite::PhysicalSprite(SDL_Texture* t, int x, int y, int temporaryTestSpeed): Sprite(t, x, y)
{ 
	currentTime = 0;
	ttSpeed = temporaryTestSpeed;
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
		dest.x += ttSpeed;
	}
	if (sys.isKeyDown(SDLK_a)) {
		dest.x -= ttSpeed;
	}
	if (sys.isKeyDown(SDLK_w)) {
		dest.y -= ttSpeed;
	}
	if (sys.isKeyDown(SDLK_s)) {
		dest.y += ttSpeed;
	}
}

bool PhysicalSprite::isAlive() const{
	return alive;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
