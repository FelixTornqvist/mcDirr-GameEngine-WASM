

#include "SantaHero.hpp"

using namespace mcDirr;

void SantaHero::customTick(int timeDiff) {
	if (sys.isKeyDown(SDLK_w) && onGround)
		yVel -= 0.5;
	else if (sys.isKeyDown(SDLK_s))
		yVel = 0.5;
	if (sys.isKeyDown(SDLK_a))
		xVel = -0.5;
	else if (sys.isKeyDown(SDLK_d))
		xVel = 0.5;
}