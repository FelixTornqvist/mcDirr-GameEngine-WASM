#include "SantaHero.hpp"
#include "System.hpp"
#include "Projectile.hpp"
#include "Loader.hpp"

#include <iostream>

#define TEAM 1

using namespace mcDirr;

SantaHero* SantaHero::getInstance(SDL_Surface* surf, SDL_Surface* fireSheet, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, GameEngine* GEpek) {
	return new SantaHero(surf, fireSheet, x, y, divs, millisPerFrame, healthSym, GEpek);
}

SantaHero::SantaHero(SDL_Surface* surf, SDL_Surface* fireSheet, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, GameEngine* GEpek)
	:
	  Sprite(surf, x, y), FramedSprite(surf, x, y, divs), gameEnginePointer(GEpek),
	  AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym, TEAM), firesheet(fireSheet) {
	spawnX = x;
	spawnY = y;
}

void SantaHero::checkBounds() {
	int winWidth = 0;
	int winHeight = 0;

	SDL_Window* window = sys.getWin();
	SDL_GetWindowSize(window, &winWidth, &winHeight);
	// std::cout << dest.x << " - " << winWidth << std::endl;

	if (dest.y > winHeight) {
		alive = false;
		return;
	}
	if (dest.x <= 0) {
		dest.x = 1;
		xVel = 0;
		gameEnginePointer->previousScreen();
		return;
	}

	if (dest.x > winWidth) {
		dest.x = winWidth - 1;
		xVel = 0;
		gameEnginePointer->nextScreen();
		
		if (gameEnginePointer->getScreen() != nullptr) {
			std::cout << "körs" << std::endl;
			if (!gameEnginePointer->getScreen()->exists(this)) {
				std::cout << "det här med!" << std::endl;
				gameEnginePointer->getScreen()->add(this);
			}
			dest.x = 50;
			dest.y = 50;
			//dest.x = gameEnginePointer->getScreen()->getStartX();
			//dest.y = gameEnginePointer->getScreen()->getStartY();
			
		}
		
	}
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
		projCooldown = 30;
		SDL_Rect* rect = getDestRect();
		int projX = rect->x + 50;
		AnimatedMobileSprite* sprite = Projectile::getInstance(firesheet, projX, rect->y, 3, 70, healthSymbol, 1, facingRight);
		sprite->setYAccel(0.1);
		sprite->setBouncy(false);

		getSpriteOutbox()->push(sprite);
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
	checkBounds();
}

void SantaHero::handleMobileCollision(MobileSprite* collidedWith, int side) {
}

void SantaHero::kill() {
	if (health > 0) {
		changeHealth(-1);
	} else {
		//alive = false;
		health = 4;
		dest.x = spawnX;
		dest.y = spawnY;
	}
}
