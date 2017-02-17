#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "InteractionSprite.hpp"

namespace mcDirr {
	class Projectile : public InteractionSprite {
		public:
			Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);

			void handleCollision(MobileSprite* collidedWith, int side);
			void customTick(int timeDiff);

			virtual ~Projectile();

		protected:

		private:
	};
}
#endif // PROJECTILE_HPP
