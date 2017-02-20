#include "Particle.hpp"
#include "System.hpp"

#include <stdlib.h>

using namespace mcDirr;

Particle::Particle(SDL_Surface* surf, int x, int y, double xVel, double yVel, int lifetime):
	MobileSprite(surf, x, y, nullptr, -1), Sprite(surf, x, y), lifeTime(lifetime), passedTime(0){
	int rnd = rand() % 15 + 10;
	src = dest;
	src.x = rand() % (dest.w - rnd);
	src.y = rand() % (dest.h - rnd);
	src.h = src.w = rnd;

	dest.w = rnd;
	dest.h = rnd;
	setXVel(xVel);
	setYVel(yVel);
	yAccel /= 1.6;
}

void Particle::customTick(int timeDiff) {
	passedTime += timeDiff;
	if (passedTime > lifeTime)
		alive = false;
}

void Particle::draw() const {
	SDL_RenderCopy(sys.getRen(), texture, &src, &dest);
}

Particle::~Particle() {
}
