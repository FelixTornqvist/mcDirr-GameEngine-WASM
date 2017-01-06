#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"


namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, bool mbl, int divs, int millisPerFrame) :
	AnimatedSprite(loader.loadTexture(surf),x,y,divs,millisPerFrame), MobileSprite(surf,x,y,bounciness,mbl) {
		//ctor
	}

	void AnimatedMobileSprite::draw() const {
		AnimatedSprite::draw();
	}

	void AnimatedMobileSprite::tick(int millisPassed) {
		AnimatedSprite::tick(millisPassed);
		MobileSprite::tick(millisPassed);
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
