#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "Sprite.hpp"

namespace mcDirr {
	class AnimatedSprite : public Sprite {
		public:
			AnimatedSprite(SDL_Texture* t, int x, int y, int sheetDivisions, int millisPerFrame);

			void tick(int passedTime) override;
			void draw() const override;

			virtual ~AnimatedSprite();

		protected:

		private:
			int spriteSheetDivs;
			int millisPerFrame, currentCount = 0;
			SDL_Rect srcRect;
	};
}
#endif // ANIMATEDSPRITE_H
