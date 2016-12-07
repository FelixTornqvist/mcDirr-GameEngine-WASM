#include "../System.hpp"
#include "AnimatedSprite.hpp"

namespace mcDirr {
	AnimatedSprite::AnimatedSprite(SDL_Texture* t, int x, int y, int divs, int _millisPerFrame):
		FramedSprite(t, x, y, divs), millisPerFrame(_millisPerFrame) {
		startFrame = 0;
		endFrame = getFramesAmt();
	}

	void AnimatedSprite::tick(int timeDiff) {
		currentCount += timeDiff;
		checkCurrentCount();

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
