#include "SantaHero.hpp"
#include "System.hpp"
#include "Projectile.hpp"
#include "Loader.hpp"
#include "InteractionSprite.hpp"

using namespace mcDirr;

SantaHero* SantaHero::getInstance(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, Level* lvl) {
	return new SantaHero(surf, x, y, divs, millisPerFrame, healthSym, lvl);
}

SantaHero::SantaHero(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, Level* lvl)
	: AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym),
	  FramedSprite(surf, x, y, divs), Sprite(surf, x, y), currentLevel(lvl) {}

void SantaHero::setCurrentLevel(Level* lvl) {
	currentLevel = lvl;
}

void SantaHero::customTick(int timeDiff) {
	if(projCooldown > 0)
		projCooldown--;
	if (sys.isKeyDown(SDLK_w) && onGround)
		yVel -= 1;
	else if (sys.isKeyDown(SDLK_s))
		yVel = 1;
	if (sys.isKeyDown(SDLK_a))
		xVel = -0.5;
	else if (sys.isKeyDown(SDLK_d))
		xVel = 0.5;
	if (sys.isKeyDown(SDLK_SPACE) && projCooldown == 0) {
		projCooldown = 20;
		SDL_Surface* cat = loader.loadSurface("media/tinyCat.png");
		SDL_Texture* hearts = loader.loadTexture(cat);
		SDL_Surface* fireballSheet = loader.loadSurface("media/fireball.png");
		SDL_Rect* rect = getDestRect();
		int projX = rect->x + 50;
		InteractionSprite* sprite = new Projectile(fireballSheet, projX, rect->y, 3, 70, hearts, getFriendly(), 1, facingRight);
		currentLevel->add(sprite);
	}


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
