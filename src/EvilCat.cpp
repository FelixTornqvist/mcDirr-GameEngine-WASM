#include "EvilCat.hpp"

using namespace mcDirr;


EvilCat* EvilCat::getInstance(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) {
	return new EvilCat(surface, x, y, healthSym);
}

void EvilCat::customTick(int timeDiff) {
	// move move
}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) :
	InteractionSprite(surface, x, y, 1, 100000, healthSym), FramedSprite(surface, 1, x, y), Sprite(surface, x, y) {}

void EvilCat::handleCollision(MobileSprite* collidedWith, int side) {

}
