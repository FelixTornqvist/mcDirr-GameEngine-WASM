#include "FramedSprite.hpp"
#include "System.hpp"


namespace mcDirr {
	FramedSprite* FramedSprite::getInstance(SDL_Texture* t, int x, int y, int z) {
		return new FramedSprite(t, x, y, z);
	}

	void FramedSprite::setCurrentFrame(int frame) {
		int currentFrame = frame % (spriteSheetDivs * spriteSheetDivs);

		int x = currentFrame % spriteSheetDivs;
		int y = currentFrame / spriteSheetDivs;
		srcRect.x = x * srcRect.w;
		srcRect.y = y * srcRect.h;
	}

	int FramedSprite::getFramesAmt() const {
		return frames;
	}

	void FramedSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, &srcRect, &dest);
	}


	FramedSprite::~FramedSprite() {
		//dtor
	}
}
