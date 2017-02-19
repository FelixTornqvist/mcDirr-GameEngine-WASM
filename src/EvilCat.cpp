#include "EvilCat.hpp"
#define TEAM 2

using namespace mcDirr;

EvilCat* EvilCat::getInstance(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) {
	return new EvilCat(surface, x, y, healthSym);
}

void EvilCat::customTick(int timeDiff) {
	// move move
}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) :
	AnimatedMobileSprite(surface, x, y, 1, 70, healthSym, TEAM), FramedSprite(surface, x, y, 1), Sprite(surface, x, y) {
}

void EvilCat::handleMobileCollision(MobileSprite* collidedWith, int side) {

}
