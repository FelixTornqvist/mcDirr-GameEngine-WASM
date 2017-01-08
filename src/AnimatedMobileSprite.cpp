#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"
#include "System.hpp"

namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, int divs, int millisPerFrame) :
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), MobileSprite(surf,x,y,bouciness), AnimatedSprite(surf,x,y,divs,millisPerFrame)  {
	}

	void AnimatedMobileSprite::draw() const{
		AnimatedSprite::draw();
	}

	void AnimatedMobileSprite::tick(int millisPassed) {
		MobileSprite::tick(millisPassed);
		AnimatedSprite::tick(millisPassed);
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
