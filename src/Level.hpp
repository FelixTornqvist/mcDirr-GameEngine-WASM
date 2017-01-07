#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <list>

#include "Sprite.hpp"
#include "MobileSprite.hpp"
#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class Level {
		public:
			static Level* getInstance(Level* nextLvl);

			void tick(int timeDiff);
			void draw();

			void add(Sprite* sprite);
			void add(MobileSprite* pSprite);
			void add(AnimatedMobileSprite* aSprite);
			void remove(Sprite* sprite);
			void remove(MobileSprite* sprite);
			bool isComplete();
			Level* getNextLevel();

			virtual ~Level();

		protected:
			Level(Level* nextLvl);

		private:
			bool complete = false;
			Level* nextLevel;

			std::list<Sprite*> sprites;
			std::list<MobileSprite*> mobileSprites, immobileSprites;

			void collisionChecks(MobileSprite* movableSprite);
	};
}

#endif // LEVEL_HPP
