#ifndef FRAMEDSPRITE_H
#define FRAMEDSPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "Sprite.hpp"

namespace mcDirr {
	class FramedSprite : public Sprite {
		public:
			static FramedSprite* getInstance(SDL_Texture*, int, int, int);

			void draw() const override;
			void setCurrentFrame(int frame);
			int getFramesAmt() const;

			virtual ~FramedSprite();

		protected:
			FramedSprite(SDL_Texture* tex, int x, int y, int divs);
		private:
			int frames;
			int spriteSheetDivs;
			SDL_Rect srcRect;
	};
}
#endif // FRAMEDSPRITE_H
