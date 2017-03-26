#ifndef ANIMATEDMOBILESPRITE_HPP
#define ANIMATEDMOBILESPRITE_HPP

#include "AnimatedSprite.hpp"
#include "MobileSprite.hpp"

namespace mcDirr {

	class AnimatedMobileSprite : public MobileSprite, public AnimatedSprite {

		public:
			void draw() const;
			void tick(int millisPassed) override;
			bool isPixelColored(int x, int y) const;

			virtual ~AnimatedMobileSprite() {}

		protected:
			AnimatedMobileSprite(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int teamNo);
	};
}

#endif // ANIMATEDMOBILESPRITE_HPP
