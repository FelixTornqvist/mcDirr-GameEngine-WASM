#include "EvilCat.hpp"

using namespace mcDirr;


EvilCat* EvilCat::getInstance(SDL_Surface* surface, int x, int y) {
	return new EvilCat(surface, x, y);
}

void EvilCat::customTick(int timeDiff) {
	// move move
}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y) : MobileSprite(surface, x, y, nullptr), Sprite(surface, x, y) {}

void EvilCat::handleCollision(MobileSprite* collidedWith, int side) {

}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y) : InteractionSprite(surface, x, y, 1, 1000, 1, true, 0.3, 0.3) {}