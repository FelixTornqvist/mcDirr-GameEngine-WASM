#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <list>

#include "Sprite.hpp"
#include "PhysicalSprite.hpp"

namespace mcDirr {
	class Level {
		public:
			static Level* getInstance(Level* nextLvl);

			void tick(int timeDiff);
			void draw();

			void add(Sprite* sprite);
			void add(PhysicalSprite* pSprite);
			void remove(Sprite* sprite);
			void remove(PhysicalSprite* sprite);
			bool isComplete();
			Level* getNextLevel();

			virtual ~Level();

		protected:
			Level(Level* nextLvl);

		private:
			bool complete = false;
			Level* nextLevel;

			std::list<Sprite*> sprites;
			std::list<PhysicalSprite*> mobileSprites, immobileSprites;

			void collisionChecks(PhysicalSprite* movableSprite);
	};
}

#endif // LEVEL_HPP
