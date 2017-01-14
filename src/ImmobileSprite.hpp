#ifndef IMMOBILESPRITE_HPP
#define IMMOBILESPRITE_HPP

#include "Sprite.hpp"

namespace mcDirr {
	class ImmobileSprite : public Sprite {
		public:
			static ImmobileSprite* getInstance(SDL_Surface* s, int x, int y);
			void tick(int timeDiff) override {};
			bool isAlive();
			virtual ~ImmobileSprite();

		protected:
			ImmobileSprite(SDL_Surface* s, int x, int y);

		private:
			bool alive;
	};
}

#endif // IMMOBILESPRITE_HPP
