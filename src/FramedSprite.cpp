#include "FramedSprite.hpp"
#include "System.hpp"


namespace mcDirr {
	FramedSprite* FramedSprite::getInstance(SDL_Texture* t, int x, int y, int z) {
		return new FramedSprite(t, x, y, z);
	}

	FramedSprite::FramedSprite(SDL_Texture* tex, int x, int y, int divs) :
		Sprite(tex, x, y), spriteSheetDivs(divs) {
		int width;
		int height;
		SDL_QueryTexture(tex, NULL, NULL, &width, &height);
		srcRect = { 0, 0, width / divs, height / divs };

		dest.w /= divs;
		dest.h /= divs;
		frames = divs * divs;
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

	SDL_Rect FramedSprite::getSrcRect() const {
		return srcRect;
	}

	void FramedSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, &srcRect, &dest);
	}


	FramedSprite::~FramedSprite() {
		//dtor
	}
}
