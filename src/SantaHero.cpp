#include "SantaHero.hpp"
#include "System.hpp"

using namespace mcDirr;

SantaHero* SantaHero::getInstance(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym) {
	return new SantaHero(surf, x, y, divs, millisPerFrame, healthSym);
}

SantaHero::SantaHero(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym)
	: AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym),
	  FramedSprite(surf, x, y, divs), Sprite(surf, x, y) {}

void SantaHero::customTick(int timeDiff) {

	if (sys.isKeyDown(SDLK_w) && onGround)
		yVel -= 1;
	else if (sys.isKeyDown(SDLK_s))
		yVel = 1;
	if (sys.isKeyDown(SDLK_a))
		xVel = -0.5;
	else if (sys.isKeyDown(SDLK_d))
		xVel = 0.5;


	if (xVel < 0) {
		setStartFrame(2);
		setEndFrame(60);
		facingRight = false;
	} else if (xVel > 0) {
		setStartFrame(61);
		setEndFrame(120);
		facingRight = true;
	} else {
		if (!facingRight) {
			setStartFrame(0);
			setEndFrame(0);
		} else {
			setStartFrame(1);
			setEndFrame(1);
		}
	}
}
