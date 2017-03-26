#ifndef SANTAHERO_HPP
#define SANTAHERO_HPP

#include <functional>
#include <memory>
#include <SDL.h>

#include "AnimatedMobileSprite.hpp"
#include "Level.hpp"
#include "GameEngine.hpp"

namespace mcDirr {

	class SantaHero : public AnimatedMobileSprite {

		public:
			static std::shared_ptr<SantaHero> getInstance(SDL_Surface* santasheet, SDL_Surface* fireSheet, SDL_Texture* healthSym, GameEngine* GEpek, void (*resetFunk)());
			void kill() override;

		protected:
			SantaHero(SDL_Surface* surf, SDL_Surface* fireSheet, SDL_Texture* healthSym, GameEngine* GEpek, void (*resetFunk)());
			void customTick(int timeDiff);

		private:
			std::shared_ptr<SantaHero> me;
			void handleMobileCollision(std::shared_ptr<MobileSprite> collidedWith, int side) override {}
			void checkBounds();
			int projCooldown = 0;
			SDL_Surface* firesheet;
			bool facingRight = true;
			GameEngine* gameEngine;
			std::function<void()> resetFunc;
	};
}

#endif
