#ifndef ANIMATEDMOBILESPRITE_HPP
#define ANIMATEDMOBILESPRITE_HPP

#include "AnimatedSprite.hpp"
#include "MobileSprite.hpp"


namespace mcDirr {
	class AnimatedMobileSprite : public AnimatedSprite, public MobileSprite{
		public:
			AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, int divs, int millisPerFrame);

			void draw() const;
			void tick(int millisPassed) override;
			void checkCollision(ImmobileSprite* other) override;

			virtual ~AnimatedMobileSprite();

		protected:

		private:
	};
}

#endif // ANIMATEDMOBILESPRITE_HPP
