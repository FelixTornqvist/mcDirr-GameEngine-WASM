#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"
#include <iostream>



using namespace mcDirr;

PhysicalSprite::PhysicalSprite(SDL_Texture* t, int x, int y):
	Sprite(t, x, y), currentTime(0), alive(true) {}


void PhysicalSprite::draw() const {
    SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
}

void PhysicalSprite::tick(int time) {
	if (sys.isKeyDown(SDLK_s) || sys.isMouseButtonDown(SDL_BUTTON_LEFT)) {
		std::cout << "yes?" << std::endl;
		alive = false;
	}
}

bool PhysicalSprite::isAlive() const{
	return alive;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
