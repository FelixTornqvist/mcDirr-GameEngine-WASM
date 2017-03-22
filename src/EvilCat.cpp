#include "EvilCat.hpp"
#include "Particle.hpp"

#include <math.h>
#include <stdlib.h>

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
		if(side == 1) {
			yVel = 0.5;
			collidedWith->setYVel(-0.5);
		}
		if(side == 2) {
			xVel = 0.5;
			yVel = -0.1;
			collidedWith->setXVel(-0.5);
			collidedWith->setYVel(-0.1);
		}
		if(side == 3) {
			yVel = -0.5;
			collidedWith->setYVel(0.5);
		}
		if (side == 4) {
			xVel = -0.5;
			yVel = -0.1;
			collidedWith->setXVel(0.5);
			collidedWith->setYVel(-0.1);
		}
	}
}

void EvilCat::kill() {
	// splatter effect
	srand(SDL_GetTicks());
	float amount = 30.0;
	float velocity = 0.7;

	for (int i = 0; i < amount; i++) {
		int duration = rand() % 1500 + 1500;
		float rnd = (rand() % 1000) / 990.0;
		float xVel = sin( (i/amount) * 2.0 * M_PI) * velocity + rnd;
		float yVel = cos( (i/amount) * 2.0 * M_PI) * velocity + rnd;

		Particle* p = Particle::getInstance(getSurface(), dest.x, dest.y, xVel, yVel, duration);
		getSpriteOutbox()->push(p);
	}

	changeHealth(-1);
	dest.x = spawnX;
	dest.y = spawnY;
	xVel = 0;
	yVel = 0;

	if (health <= 0) {
		alive = false;
	}
}
