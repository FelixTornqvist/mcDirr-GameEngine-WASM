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

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
