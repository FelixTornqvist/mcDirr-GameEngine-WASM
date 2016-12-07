#include "../System.hpp"
#include "AnimatedSprite.hpp"

namespace mcDirr {
	AnimatedSprite::AnimatedSprite(SDL_Texture* t, int x, int y, int divs, int _millisPerFrame):
		Sprite(t, x, y), spriteSheetDivs(divs), millisPerFrame(_millisPerFrame) {
		int width;
		int height;
		SDL_QueryTexture(t, NULL, NULL, &width, &height);
		srcRect = {0, 0, width / divs, height / divs};

		dest.w /= divs;
		dest.h /= divs;
	}

	void AnimatedSprite::tick(int timeDiff) {
		currentCount += timeDiff;

		int frames = spriteSheetDivs * spriteSheetDivs;
		if (currentCount >= frames * millisPerFrame) {
			currentCount = 0;
		}

		int currentFrame = currentCount / millisPerFrame;
		int x = currentFrame % spriteSheetDivs;
		int y = currentFrame / spriteSheetDivs;
		srcRect.x = x * srcRect.w;
		srcRect.y = y * srcRect.h;
	}

	void AnimatedSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, &srcRect, &dest);
	}

	AnimatedSprite::~AnimatedSprite() {
		//dtor
	}
}
