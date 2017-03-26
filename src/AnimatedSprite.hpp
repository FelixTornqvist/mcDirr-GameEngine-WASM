#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SDL.h>
#include "FramedSprite.hpp"

namespace mcDirr {

	class AnimatedSprite : virtual public FramedSprite {

		public:
			static AnimatedSprite* getInstance(SDL_Surface*, int, int, int, int);

			void tick(int passedTime) override;
			void setStartFrame(int frame);
			void setEndFrame(int frame);

			virtual ~AnimatedSprite();
			
		protected:
			AnimatedSprite(SDL_Surface* s, int x, int y, int divs, int _millisPerFrame);

		private:
			int startFrame, endFrame;
			int millisPerFrame, currentCount = 0;
			bool revAnimation = false;
			void inline checkCurrentCount();
	};
}
#endif // ANIMATEDSPRITE_H
