#include "EvilCat.hpp"
#define TEAM 2

using namespace mcDirr;

EvilCat* EvilCat::getInstance(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) {
	return new EvilCat(surface, x, y, healthSym);
}

EvilCat::EvilCat(SDL_Surface* surface, int x, int y, SDL_Texture* healthSym) :
	MobileSprite(surface, x, y,healthSym, TEAM), Sprite(surface, x, y) {
	spawnX = x;
	spawnY = y;
}

void EvilCat::customTick(int timeDiff) {
	// move move
}

void EvilCat::handleMobileCollision(MobileSprite* collidedWith, int side) {
	if (side && collidedWith->getTeam() == 1) {
		collidedWith->kill();
	}
}

void EvilCat::kill() {
	if (health > 0) {
		changeHealth(-1);
		dest.x = spawnX;
		dest.y = spawnY;
	} else {
		alive = false;
	}
}
