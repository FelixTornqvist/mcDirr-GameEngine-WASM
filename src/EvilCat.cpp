#include "EvilCat.hpp"

using namespace mcDirr;


EvilCat* EvilCat::getInstance(SDL_Surface* surface, int x, int y) {
	return new EvilCat(surface, x, y);
}

void EvilCat::customTick(int timeDiff) {
	// move move
}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y) : MobileSprite(surface, x, y), Sprite(surface, x, y) {}
