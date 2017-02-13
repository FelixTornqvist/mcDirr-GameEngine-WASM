#ifndef INTERACTIONSPRITE_HPP
#define INTERACTIONSPRITE_HPP

#include "AnimatedMobileSprite.hpp"

namespace mcDirr {
	class InteractionSprite : public AnimatedMobileSprite {
		public:
			int getDamage();
			int checkCollision(Sprite* other) override;
			void checkCollision(MobileSprite* other);

			void virtual handleCollision(MobileSprite* collidedWith, int side) = 0;

			virtual ~InteractionSprite();

		protected:
			InteractionSprite(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, int _damage, bool affectedByGravity, double Xvel, double Yvel);

		private:
			int damage;
	};
}
#endif // INTERACTIONSPRITE_HPP
