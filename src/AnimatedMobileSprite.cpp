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

		//temporary, should be in game implementation
		if (xVel < 0) {
			setStartFrame(0);
			setEndFrame(3);
			facingRight = false;
		} else if (xVel > 0) {
			setStartFrame(4);
			setEndFrame(7);
			facingRight = true;
		} else {
			if (!facingRight) {
				setStartFrame(0);
				setEndFrame(0);
			} else {
				setStartFrame(1);
				setEndFrame(1);
			}
		}
	}

	bool AnimatedMobileSprite::isFacingRight() const {
		return facingRight;
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
