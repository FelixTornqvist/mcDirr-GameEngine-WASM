#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <list>
#include <stack>

#include "Screen.hpp"
#include "Sprite.hpp"
#include "MobileSprite.hpp"
#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class Level: public Screen {
		public:
			static Level* getInstance(Screen* nextScreen);

			void tick(int timeDiff) override;
			void draw() override;


			void add(Sprite* sprite);
			void add(MobileSprite* sprite);
			void add(ImmobileSprite* sprite);

			void remove(Sprite* sprite);
			void remove(MobileSprite* sprite);
			void remove(ImmobileSprite* sprite);

			virtual ~Level();

		protected:
			Level(Screen* nextScreen);

		private:
			void emptySpriteInbox();

			std::stack<MobileSprite*> spriteInbox;

			std::list<Sprite*> sprites;
			std::list<MobileSprite*> mobileSprites;
			std::list<ImmobileSprite*> immobileSprites;
	};
}

#endif // LEVEL_HPP
