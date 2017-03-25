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
	  Sprite(surf, x, y), FramedSprite(surf, x, y, divs), 
	  AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym, TEAM), firesheet(fireSheet), gameEnginePointer(GEpek) {
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
		dest.x = gameEnginePointer->getLevel()->getStartX();
		dest.y = gameEnginePointer->getLevel()->getStartY();
		gameEnginePointer->previousScreen();
		return;
	}
	if (dest.x <= 0) {
		if (gameEnginePointer->getScreenIndex() > 1) {
			gameEnginePointer->previousScreen();
			dest.x = gameEnginePointer->getLevel()->getEndX();
			dest.y = gameEnginePointer->getLevel()->getEndY();
			xVel = 0;
			gameEnginePointer->getLevel()->setSpriteOutBox(this);
		}
		else {
			dest.x = gameEnginePointer->getLevel()->getStartX();
			//dest.y = gameEnginePointer->getLevel()->getStartY();
			xVel = 0;
			//gameEnginePointer->previousScreen();
		}
		return;
	}

	if (dest.x > winWidth) {
		dest.x = winWidth - 1;
		xVel = 0;
		gameEnginePointer->nextScreen();
		
		if (gameEnginePointer->getLevel() != nullptr) {
			if (!gameEnginePointer->getLevel()->exists(this)) {
				gameEnginePointer->getLevel()->add(this);
			}
			else {
				gameEnginePointer->getLevel()->setSpriteOutBox(this);
			}

			dest.x = gameEnginePointer->getLevel()->getStartX();
			dest.y = gameEnginePointer->getLevel()->getStartY();
			
		}
		
	}
}


void SantaHero::customTick(int timeDiff) {
	if(projCooldown > 0)
		projCooldown--;

	if (sys.isKeyDown(SDLK_w) && onGround)
		yVel -= 1;
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
