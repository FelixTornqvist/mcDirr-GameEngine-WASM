#include "SantaHero.hpp"
#include "System.hpp"
#include "Projectile.hpp"
#include "Loader.hpp"

#include <iostream>

#define TEAM 1

using namespace mcDirr;

std::shared_ptr<SantaHero> SantaHero::getInstance(SDL_Surface* surf, SDL_Surface* fireSheet, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, GameEngine* GEpek) {
	std::shared_ptr<SantaHero> newMe( new SantaHero(surf, fireSheet, x, y, divs, millisPerFrame, healthSym, GEpek) );
	newMe->me = newMe;
	return newMe;
}

SantaHero::SantaHero(SDL_Surface* surf, SDL_Surface* fireSheet, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, GameEngine* GEpek)
	: Sprite(surf, x, y), FramedSprite(surf, x, y, divs),
	  AnimatedMobileSprite(surf, x, y, divs, millisPerFrame, healthSym, TEAM), firesheet(fireSheet), gameEngine(GEpek) {
	spawnX = x;
	spawnY = y;
}

void SantaHero::checkBounds() {
	int winWidth = 0;
	int winHeight = 0;

	SDL_Window* window = sys.getWin();
	SDL_GetWindowSize(window, &winWidth, &winHeight);

	if (dest.y > winHeight) {
		gameEngine->previousScreen();
		Level* lvl = gameEngine->getLevel();
		if (lvl != nullptr) {
			dest.x = gameEngine->getLevel()->getStartX();
			std::cout << dest.x << std::endl;
			dest.y = gameEngine->getLevel()->getStartY();
			std::cout << dest.y << std::endl;
			yVel = 0;
		}
		return;
	}
	if (dest.x <= 0) {
		if (gameEngine->getScreenIndex() > 1) {
			gameEngine->previousScreen();
			dest.x = gameEngine->getLevel()->getEndX();
			std::cout << dest.x << std::endl;
			dest.y = gameEngine->getLevel()->getEndY();
			std::cout << dest.y << std::endl;
			gameEngine->getLevel()->setSpriteOutBox(this);
		} else {
			dest.x = 1;
		}
		xVel = 0;
		yVel = 0;
		return;

	} else if (dest.x > winWidth) {
		dest.x = winWidth - 1;
		xVel = 0;
		gameEngine->nextScreen();

		Level* lvl = gameEngine->getLevel();

		if (lvl != nullptr) {
			if (!lvl->exists(me)) {
				std::shared_ptr<MobileSprite> mobileMe = me;
				lvl->add(mobileMe);
			} else {
				lvl->setSpriteOutBox(this);
			}
			
			yVel = 0;
			dest.x = lvl->getStartX();
			std::cout << dest.x << std::endl;
			dest.y = lvl->getStartY();
			std::cout << dest.y << std::endl;
			

		}

	}
}


void SantaHero::customTick(int timeDiff) {
	if(projCooldown > 0)
		projCooldown -= timeDiff;

	if (sys.isKeyDown(SDLK_w) && onGround)
		yVel -= 1;
	if (sys.isKeyDown(SDLK_a))
		xVel = -0.5;
	else if (sys.isKeyDown(SDLK_d))
		xVel = 0.5;

	if (sys.isKeyDown(SDLK_SPACE) && projCooldown <= 0) {
		std::cout << dest.x << " " << dest.y << std::endl;
		projCooldown = 200;
		SDL_Rect* rect = getDestRect();
		int projX = rect->x + 50;
		std::shared_ptr<MobileSprite> sprite = Projectile::getInstance(firesheet, projX, rect->y, 3, 70, healthSymbol, 1, facingRight);
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

void SantaHero::handleMobileCollision(std::shared_ptr<MobileSprite> collidedWith, int side) {
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
