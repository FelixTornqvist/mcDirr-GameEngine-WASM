#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <list>
#include <stack>
#include <memory>

#include "Screen.hpp"
#include "Sprite.hpp"
#include "MobileSprite.hpp"
#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class Level: public Screen {
		public:
			static Level* getInstance(int startX, int startY, int endX, int endY);

			void tick(int timeDiff) override;
			void draw() override;


			void add(std::shared_ptr<Sprite> sprite);
			void add(std::shared_ptr<MobileSprite> sprite);
			void add(std::shared_ptr<ImmobileSprite> sprite);

			void remove(std::shared_ptr<Sprite> sprite);
			void remove(std::shared_ptr<MobileSprite> sprite);
			void remove(std::shared_ptr<ImmobileSprite> sprite);

			bool exists(std::shared_ptr<MobileSprite> mob);
			void setSpriteOutBox(MobileSprite* sprite);
			int getStartX();
			int getStartY();
			int getEndY();
			int getEndX();


			virtual ~Level();

		protected:
			Level(int startX, int startY, int endX, int endY);

		private:
			void emptySpriteInbox();

			int startX;
			int	startY;
			int	endX;
			int endY;
			std::stack<std::shared_ptr<MobileSprite>> spriteInbox;

			std::list<std::shared_ptr<Sprite>> sprites;
			std::list<std::shared_ptr<MobileSprite>> mobileSprites;
			std::list<std::shared_ptr<ImmobileSprite>> immobileSprites;
	};
}

#endif // LEVEL_HPP
