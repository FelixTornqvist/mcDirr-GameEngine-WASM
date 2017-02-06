#include <iostream>

#include "Level.hpp"
#include "System.hpp"


namespace mcDirr {

	Level* Level::getInstance(Level* nextLvl) {
		return new Level(nextLvl);
	}

	Level::Level(Level* nextLvl) {
		nextLevel = nextLvl;
	}

	void Level::tick(int timeDiff) {
		for (Sprite* curr : sprites) {
			curr->tick(timeDiff);
		}

		for (std::list<MobileSprite*>::iterator it = mobileSprites.begin(); it != mobileSprites.end();) {
			(*it)->tick(timeDiff);
			(*it)->checkCollisions(immobileSprites);

			if (!(*it)->isAlive()) {
				it = mobileSprites.erase(it);
			} else
				it++;
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

	void Level::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void Level::add(MobileSprite* sprite) {
		mobileSprites.push_back(sprite);
	}

	void Level::add(ImmobileSprite* sprite) {
		immobileSprites.push_back(sprite);
	}

	void Level::add(AnimatedMobileSprite* sprite) {
		mobileSprites.push_back(sprite);
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
	void Level::remove(AnimatedMobileSprite* sprite){
		mobileSprites.remove(sprite);
		delete sprite;
	}

	bool Level::isComplete() {
		return complete;
	}

	Level* Level::getNextLevel() {
		return nextLevel;
	}

	Level::~Level() {
		delete nextLevel;
		for(Sprite* sprite : sprites)
			delete sprite;
	}
}
