#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class Projectile : public AnimatedMobileSprite {
		public:
			static Projectile* getInstance(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction);

			void customTick(int timeDiff);

			virtual ~Projectile();
		protected:
			Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction);

		private:
			bool facingRight = false;
			void handleImmobileCollision(ImmobileSprite* collWith, int side) override;
			void handleMobileCollision(MobileSprite* collidedWith, int side) override;

	};
}
#endif // PROJECTILE_HPP
