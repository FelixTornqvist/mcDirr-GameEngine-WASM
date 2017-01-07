#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"
#include "System.hpp"

#include <iostream>


namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, bool mbl, int divs, int millisPerFrame) :
		MobileSprite(surf,x,y,bouciness,mbl), AnimatedSprite(loader.loadTexture(surf),x,y,divs,millisPerFrame)  {
		MobileSprite::dest = AnimatedSprite::dest;
	}

	void AnimatedMobileSprite::draw() const{
		AnimatedSprite::draw();
	}

	void AnimatedMobileSprite::tick(int millisPassed) {
		MobileSprite::tick(millisPassed);
		AnimatedSprite::tick(millisPassed);
		AnimatedSprite::dest.x = MobileSprite::dest.x;
		AnimatedSprite::dest.y = MobileSprite::dest.y;

		std::cout << "ani:" << AnimatedSprite::dest.y << "mobi:" << MobileSprite::dest.y << std::endl;
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
