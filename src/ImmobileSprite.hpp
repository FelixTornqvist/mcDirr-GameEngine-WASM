#ifndef IMMOBILESPRITE_HPP
#define IMMOBILESPRITE_HPP

#include "Sprite.hpp"

namespace mcDirr {
	class ImmobileSprite : public Sprite {
		public:
			static ImmobileSprite* getInstance(SDL_Surface* s, int x, int y, float b);
			void tick(int timeDiff) override {};
			bool isAlive();
			void setBounciness(float bounciness);
			float getBounciness();
			virtual ~ImmobileSprite();

		protected:
			ImmobileSprite(SDL_Surface* s, int x, int y, float b);

		private:
			bool alive;
			float bounciness;
	};
}

#endif // IMMOBILESPRITE_HPP
