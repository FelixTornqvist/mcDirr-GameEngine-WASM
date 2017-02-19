#ifndef SANTAHERO_HPP
#define SANTAHERO_HPP

#include <SDL.h>
#include "AnimatedMobileSprite.hpp"
#include "Level.hpp"



#include <iostream>

namespace mcDirr {
	class SantaHero : public AnimatedMobileSprite {

		public:
			static SantaHero* getInstance(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);

		protected:
			SantaHero(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);
			void customTick(int timeDiff);

		private:
			void handleMobileCollision(MobileSprite* collidedWith, int side) override;

			int projCooldown = 0;
	};
}

#endif
