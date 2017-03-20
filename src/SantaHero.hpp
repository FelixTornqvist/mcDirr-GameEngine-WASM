#ifndef SANTAHERO_HPP
#define SANTAHERO_HPP

#include <SDL.h>
#include "AnimatedMobileSprite.hpp"
#include "Level.hpp"

namespace mcDirr {
	class SantaHero : public AnimatedMobileSprite {

		public:
			static SantaHero* getInstance(SDL_Surface* santasheet, SDL_Surface* fireSheet, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);
			void kill() override;

		protected:
			SantaHero(SDL_Surface* surf, SDL_Surface* fireSheet,int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);
			void customTick(int timeDiff);

		private:
			void handleMobileCollision(MobileSprite* collidedWith, int side) override;

			int spawnX, spawnY;
			int projCooldown = 0;
			SDL_Surface* firesheet;
			bool facingRight = true;
	};
}

#endif
