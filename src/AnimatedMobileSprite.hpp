#ifndef ANIMATEDMOBILESPRITE_HPP
#define ANIMATEDMOBILESPRITE_HPP

#include "AnimatedSprite.hpp"
#include "MobileSprite.hpp"


namespace mcDirr {
	class AnimatedMobileSprite : public MobileSprite, public AnimatedSprite {
		public:
			AnimatedMobileSprite(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym);

			void draw() const;
			void tick(int millisPassed) override;
			bool isFacingRight() const;

			virtual ~AnimatedMobileSprite();

		protected:
			bool facingRight;

		private:
	};
}

#endif // ANIMATEDMOBILESPRITE_HPP
