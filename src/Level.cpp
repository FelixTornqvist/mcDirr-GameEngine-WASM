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

		for (std::list<PhysicalSprite*>::iterator it = physicalSprites.begin(); it != physicalSprites.end();) {
			(*it)->tick(timeDiff);
			collisionChecks(it);

			if (!(*it)->isAlive()) {
				it = physicalSprites.erase(it);
			} else
				it++;
		}

		if(sys.getTypedString().back() == 'l') {
			sys.listenForTyping(false);
			std::cout << "next Level!" << std::endl;
			complete = true;
			sys.listenForTyping(true);
		}
	}

	void Level::draw() {
		for (PhysicalSprite* curr : physicalSprites)
			curr->draw();

		for(Sprite* curr : sprites)
			curr->draw();
	}

	void Level::collisionChecks(std::list<PhysicalSprite*>::iterator it) {
		for (std::list<PhysicalSprite*>::iterator curr = it; curr != physicalSprites.end(); curr++) {

			if ((it != curr)) {
				(*it)->checkCollision(*curr);
			}
		}
	}

	void Level::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void Level::add(PhysicalSprite* pSprite) {
		physicalSprites.push_back(pSprite);
	}

	void Level::remove(Sprite* sprite) {
		sprites.remove(sprite);
		delete sprite;
	}

	void Level::remove(PhysicalSprite* pSprite) {
		physicalSprites.remove(pSprite);
		delete pSprite;
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
