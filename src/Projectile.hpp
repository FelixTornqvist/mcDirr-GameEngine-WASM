#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <memory>
#include "AnimatedMobileSprite.hpp"

namespace mcDirr {

	class Projectile : public AnimatedMobileSprite {

		public:
			static std::shared_ptr<Projectile> getInstance(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction);
			void customTick(int timeDiff);
			virtual ~Projectile();

		protected:
			Projectile(SDL_Surface *surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int xVel, bool direction);

		private:
			bool facingRight = false;
			void handleImmobileCollision(std::shared_ptr<ImmobileSprite> collWith, int side) override;
			void handleMobileCollision(std::shared_ptr<MobileSprite> collidedWith, int side) override;
			void checkBounds();
	};
}

#endif // PROJECTILE_HPP