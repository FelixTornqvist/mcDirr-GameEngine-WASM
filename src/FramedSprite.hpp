#ifndef FRAMEDSPRITE_H
#define FRAMEDSPRITE_H

#include <SDL.h>
#include "Sprite.hpp"

namespace mcDirr {
	class FramedSprite : virtual public Sprite {
		public:
			static FramedSprite* getInstance(SDL_Surface*, int, int, int);

			void tick(int millisPassed) {}
			void draw() const override;
			void setCurrentFrame(int frame);
			int getFramesAmt() const;
			SDL_Rect getSrcRect() const;

			virtual ~FramedSprite();

		protected:
			FramedSprite(SDL_Surface* surf, int x, int y, int divs);
		private:
			int frames;
			int spriteSheetDivs;
			SDL_Rect srcRect;
	};
}
#endif // FRAMEDSPRITE_H
