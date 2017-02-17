#ifndef INTERACTIONSPRITE_HPP
#define INTERACTIONSPRITE_HPP

#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class InteractionSprite : public AnimatedMobileSprite {
		public:
			int getDamage();

			void checkCollisions(std::list<MobileSprite*>& mobiles);
			void checkCollision(MobileSprite* other);
			void checkPixelCollission(MobileSprite* other, int side);
			int getHealthImpact();

			virtual ~InteractionSprite();

		protected:
			InteractionSprite(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _damage, bool affectedByGravity, double Xvel, double Yvel);

			void virtual handleCollision(MobileSprite* collidedWith, int side) = 0;

		private:
			int healthImpact;
	};
}
#endif // INTERACTIONSPRITE_HPP
