#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"
#include "System.hpp"

namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame, SDL_Texture* healthSym, int teamNum) :
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), MobileSprite(surf,x,y, healthSym, teamNum), AnimatedSprite(surf,x,y,divs,millisPerFrame)  {
	}

	void AnimatedMobileSprite::draw() const{
		AnimatedSprite::draw();
		MobileSprite::drawHealth();
	}

	void AnimatedMobileSprite::tick(int millisPassed) {
		MobileSprite::tick(millisPassed);
		AnimatedSprite::tick(millisPassed);
	}

	bool AnimatedMobileSprite::isPixelColored(int x, int y) const {
		SDL_Surface* tempsurf = getSurface();
		int surfX = x - getX() + getSrcRect().x;
		int surfY = y - getY() + getSrcRect().y;
		SDL_LockSurface(tempsurf);
		Uint32* pixels = static_cast<Uint32*>(tempsurf->pixels);
		Uint32 pixel = pixels[surfY*tempsurf->w + surfX];
		SDL_UnlockSurface(tempsurf);
		if (pixel > 0)
			return true;
		else
			return false;
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
