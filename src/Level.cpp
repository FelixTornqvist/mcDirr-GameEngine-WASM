#include <iostream>

#include "Level.hpp"
#include "System.hpp"


namespace mcDirr {

	Level* Level::getInstance(int startX, int startY, int endX, int endY) {
		return new Level(startX, startY, endX, endY);
	}

	Level::Level(int startX, int startY, int endX, int endY) {
	}

	void Level::tick(int timeDiff) {
		for (Sprite* curr : sprites) {
			curr->tick(timeDiff);
		}

		for (std::list<MobileSprite*>::iterator mob = mobileSprites.begin(); mob != mobileSprites.end(); mob++) {
			(*mob)->tick(timeDiff);
			(*mob)->customTick(timeDiff);
			(*mob)->checkImmobileCollisions(immobileSprites);
		}

		emptySpriteInbox();

		for (std::list<MobileSprite*>::iterator mob = mobileSprites.begin(); mob != mobileSprites.end();) {
			(*mob)->checkMobileCollisions(mobileSprites);

			if (!(*mob)->isAlive()) {
				delete *mob;
				mob = mobileSprites.erase(mob);
			} else
				mob++;
		}
	}

	void Level::draw() {
		for(Sprite* curr : sprites)
			curr->draw();

		for (ImmobileSprite* curr : immobileSprites)
			curr->draw();

		for (MobileSprite* curr : mobileSprites)
			curr->draw();
	}

	void Level::emptySpriteInbox() {
		while (!spriteInbox.empty()) {
			add(spriteInbox.top());
			spriteInbox.pop();
		}
	}

	bool Level::exists(MobileSprite* mob) {
		for (MobileSprite* curr : mobileSprites) {
			if (curr == mob) {
				return true;
			}
		}
		return false;
	}

	int Level::getStartX() {
		return startX;
	}
	int Level::getStartY() {
		return startY;
	}
	int Level::getEndY() {
		return endY;
	}
	int Level::getEndX() {
		return endX;
	}

	void Level::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void Level::add(MobileSprite* sprite) {
		mobileSprites.push_back(sprite);
		sprite->setSpriteOutbox(&spriteInbox);
	}

	void Level::add(ImmobileSprite* sprite) {
		immobileSprites.push_back(sprite);
	}


	void Level::remove(Sprite* sprite) {
		sprites.remove(sprite);
		delete sprite;
	}

	void Level::remove(MobileSprite* sprite) {
		mobileSprites.remove(sprite);
		delete sprite;
	}

	void Level::remove(ImmobileSprite* sprite) {
		immobileSprites.remove(sprite);
		delete sprite;
	}

	Level::~Level() {
		for(Sprite* sprite : sprites)
			delete sprite;
	}
}
