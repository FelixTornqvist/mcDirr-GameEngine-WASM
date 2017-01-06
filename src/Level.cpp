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

		for (std::list<PhysicalSprite*>::iterator it = mobileSprites.begin(); it != mobileSprites.end();) {
			(*it)->tick(timeDiff);
			collisionChecks((*it));

			if (!(*it)->isAlive()) {
				it = mobileSprites.erase(it);
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
		for (PhysicalSprite* curr : immobileSprites)
			curr->draw();

		for (PhysicalSprite* curr : mobileSprites)
			curr->draw();

		for(Sprite* curr : sprites)
			curr->draw();
	}

	void Level::collisionChecks(PhysicalSprite* mobile) {
		for (std::list<PhysicalSprite*>::iterator immobile = immobileSprites.begin(); immobile != immobileSprites.end();) {
			mobile->checkCollision(*immobile);

			if (!(*immobile)->isAlive())
				immobile = mobileSprites.erase(immobile);
			else
				immobile++;
		}
	}

	void Level::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void Level::add(PhysicalSprite* pSprite) {
		if(pSprite->isMobile())
			mobileSprites.push_back(pSprite);
		else
			immobileSprites.push_back(pSprite);
	}

	void Level::remove(Sprite* sprite) {
		sprites.remove(sprite);
		delete sprite;
	}

	void Level::remove(PhysicalSprite* pSprite) {
		if(pSprite->isMobile()){
			mobileSprites.remove(pSprite);
			delete pSprite;
		} else {
			immobileSprites.remove(pSprite);
			delete pSprite;
		}

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
