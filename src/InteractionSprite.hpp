#ifndef INTERACTIONSPRITE_HPP
#define INTERACTIONSPRITE_HPP

#include "MobileSprite.hpp"

namespace mcDirr {
	class InteractionSprite : public MobileSprite {
		public:
			int getDamage();
			void checkCollision(ImmobileSprite* other) override;
			void checkCollision(MobileSprite* other);

			void virtual handleCollision(MobileSprite* collidedWith, int side) = 0;

			virtual ~InteractionSprite();

		protected:
			InteractionSprite(SDL_Surface *surf, int x, int y, int damage, bool affectedByGravity, int Xvel, int Yvel);

		private:
			int damage;
	};
}
#endif // INTERACTIONSPRITE_HPP
