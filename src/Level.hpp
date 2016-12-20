#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <list>

#include "Sprite.hpp"
#include "PhysicalSprite.hpp"

namespace mcDirr {
	class Level {
		public:
			static Level* getInstance();

			void tick(int timeDiff);
			void draw();

			void add(Sprite* sprite);
			void add(PhysicalSprite* pSprite);
			void remove(Sprite* sprite);
			void remove(PhysicalSprite* sprite);

			virtual ~Level();

		protected:
			Level();

		private:
			std::list<Sprite*> sprites;
			std::list<PhysicalSprite*> physicalSprites;

			void collisionChecks(std::list<PhysicalSprite*>::iterator);
	};
}

#endif // LEVEL_HPP
