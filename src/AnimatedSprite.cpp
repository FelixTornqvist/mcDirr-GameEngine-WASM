#include "System.hpp"
#include "Sprite.hpp"
#include "AnimatedSprite.hpp"

namespace mcDirr {
	AnimatedSprite* AnimatedSprite::getInstance(SDL_Surface* s, int x, int y, int divs, int _millisPerFrame) {
		return new AnimatedSprite(s, x, y, divs, _millisPerFrame);
	}

	AnimatedSprite::AnimatedSprite(SDL_Surface* s, int x, int y, int divs, int _millisPerFrame) :
		Sprite(s,x,y), FramedSprite(s, x, y, divs), millisPerFrame(_millisPerFrame) {

		startFrame = 0;
		endFrame = divs;
	}

    void AnimatedSprite::tick(int timeDiff) {
        currentCount += timeDiff;

		if (sys.isKeyDown(SDLK_a)) {	//  frames 2 and 3
			setStartFrame(2);
			setEndFrame(4);
		} else if (sys.isKeyDown(SDLK_d)) {     // frames 0 and 1
			setStartFrame(0);
			setEndFrame(2);
		} else {
			checkCurrentCount();
		}

		int currentFrame = currentCount / millisPerFrame;
		setCurrentFrame(currentFrame);
	}

    void AnimatedSprite::checkCurrentCount() {
        currentCount %= getFramesAmt() * millisPerFrame;
        int endTime = endFrame * millisPerFrame;
        int startTime = startFrame * millisPerFrame;

        if (endFrame < startFrame) {
            bool betweenStartAndStop = (currentCount > endTime) && (currentCount < startTime);
            if (betweenStartAndStop)
                currentCount = startTime;

        } else {
            bool outsideStartAndStop = (currentCount > endTime) || (currentCount < startTime);
            if (outsideStartAndStop)
                currentCount = startTime;
        }
    }

    void AnimatedSprite::setStartFrame(int frame) {
        startFrame = frame;
        checkCurrentCount();
    }

    void AnimatedSprite::setEndFrame(int frame) {
        endFrame = frame;
        checkCurrentCount();
    }


    AnimatedSprite::~AnimatedSprite() {
        //dtor
    }
}
