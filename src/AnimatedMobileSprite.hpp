#ifndef ANIMATEDMOBILESPRITE_HPP
#define ANIMATEDMOBILESPRITE_HPP

#include "AnimatedSprite.hpp"
#include "MobileSprite.hpp"


namespace mcDirr {
	class AnimatedMobileSprite : public MobileSprite, public AnimatedSprite{
		public:
			AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, int divs, int millisPerFrame);

			void draw() const;
			void tick(int millisPassed) override;

			virtual ~AnimatedMobileSprite();
	};
}

#endif // ANIMATEDMOBILESPRITE_HPP
