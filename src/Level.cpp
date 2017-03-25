#include <iostream>

#include "Level.hpp"
#include "System.hpp"


namespace mcDirr {

	Level* Level::getInstance(int startX, int startY, int endX, int endY) {
		return new Level(startX, startY, endX, endY);
	}

	Level::Level(int sX, int sY, int eX, int eY) : startX(sX), startY(sY), endX(eX), endY(eY) {
	}

	void Level::tick(int timeDiff) {
		for (std::shared_ptr<Sprite> curr : sprites) {
			curr->tick(timeDiff);
		}

		for (std::list<std::shared_ptr<MobileSprite>>::iterator mob = mobileSprites.begin(); mob != mobileSprites.end(); mob++) {
			(*mob)->tick(timeDiff);
			(*mob)->customTick(timeDiff);
			(*mob)->checkImmobileCollisions(immobileSprites);
		}

		emptySpriteInbox();

		for (std::list<std::shared_ptr<MobileSprite>>::iterator mob = mobileSprites.begin(); mob != mobileSprites.end();) {
			(*mob)->checkMobileCollisions(mobileSprites);

			if (!(*mob)->isAlive()) {
				mob = mobileSprites.erase(mob);
			} else
				mob++;
		}
	}

	void Level::draw() {
		for(std::shared_ptr<Sprite> curr : sprites)
			curr->draw();

		for (std::shared_ptr<ImmobileSprite> curr : immobileSprites)
			curr->draw();

		for (std::shared_ptr<MobileSprite> curr : mobileSprites)
			curr->draw();
	}

	void Level::emptySpriteInbox() {
		while (!spriteInbox.empty()) {
			add(spriteInbox.top());
			spriteInbox.pop();
		}
	}

	bool Level::exists(std::shared_ptr<MobileSprite> mob) {
		for (std::shared_ptr<MobileSprite> curr : mobileSprites) {
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
	int Level::getEndX() {
		return endX;
	}
	int Level::getEndY() {
		return endY;
	}

	void Level::add(std::shared_ptr<Sprite> sprite) {
		sprites.push_back(sprite);
	}

	void Level::add(std::shared_ptr<MobileSprite> sprite) {
		mobileSprites.push_back(sprite);
		sprite->setSpriteOutbox(&spriteInbox);
	}

	void Level::setSpriteOutBox(MobileSprite* sprite) {
		sprite->setSpriteOutbox(&spriteInbox);
	}

	void Level::add(std::shared_ptr<ImmobileSprite> sprite) {
		immobileSprites.push_back(sprite);
	}


	void Level::remove(std::shared_ptr<Sprite> sprite) {
		sprites.remove(sprite);
	}

	void Level::remove(std::shared_ptr<MobileSprite> sprite) {
		mobileSprites.remove(sprite);
	}

	void Level::remove(std::shared_ptr<ImmobileSprite> sprite) {
		immobileSprites.remove(sprite);
	}

	Level::~Level() {
	}
}
