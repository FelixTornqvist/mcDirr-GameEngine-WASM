#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class Projectile : public AnimatedMobileSprite {
		public:
			Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction);

			void customTick(int timeDiff);

			virtual ~Projectile();
		protected:

		private:
			void handleImmobileCollision(ImmobileSprite* collWith, int side) override;
			void handleMobileCollision(MobileSprite* collidedWith, int side) override;

	};
}
#endif // PROJECTILE_HPP
