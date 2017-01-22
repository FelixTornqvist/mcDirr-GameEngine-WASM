#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"
#include "System.hpp"

namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame) :
		Sprite(surf, x, y), FramedSprite(surf, x, y, divs), MobileSprite(surf,x,y), AnimatedSprite(surf,x,y,divs,millisPerFrame)  {
	}

    void AnimatedMobileSprite::draw() const{
        AnimatedSprite::draw();
    }

	void AnimatedMobileSprite::tick(int millisPassed) {
		MobileSprite::tick(millisPassed);
		AnimatedSprite::tick(millisPassed);

		if (xVel < 0) {	//  frames 2 and 3
			setStartFrame(2);
			setEndFrame(3);
			facingRight = false;
		} else if (xVel > 0) {     // frames 0 and 1
			setStartFrame(0);
			setEndFrame(1);
			facingRight = true;
		}
	}

	bool AnimatedMobileSprite::isFacingRight() const {
		return facingRight;
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
