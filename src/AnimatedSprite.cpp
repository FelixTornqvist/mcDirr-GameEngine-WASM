#include "System.hpp"
#include "Sprite.hpp"
#include "AnimatedSprite.hpp"

namespace mcDirr {

	AnimatedSprite::AnimatedSprite(SDL_Surface* s, int x, int y, int divs, int _millisPerFrame) :
		Sprite(s,x,y), FramedSprite(s, x, y, divs), millisPerFrame(_millisPerFrame) {

		startFrame = 0;
		endFrame = divs;
	}

	void AnimatedSprite::tick(int timeDiff) {
		currentCount += revAnimation ? -timeDiff : timeDiff;
		checkCurrentCount();


		int currentFrame = currentCount / millisPerFrame;
		setCurrentFrame(currentFrame);
	}

	void AnimatedSprite::checkCurrentCount() {
		// times for when the start- and end-frame begin to show.
		int endTime = endFrame * millisPerFrame;
		int startTime = startFrame * millisPerFrame;

		// startTime + millisPerFrame - 1 is the time when the start-frame ends.
		// startTime + millisPerFrame would be when the next frame after the start-frame would begin.

		bool outsideRev = currentCount > startTime + millisPerFrame - 1 || currentCount < endTime;
		bool outsideFwd = currentCount > endTime + millisPerFrame - 1 || currentCount < startTime;

		if (revAnimation && outsideRev) {
			currentCount = startTime + millisPerFrame - 1;
		} else if (!revAnimation && outsideFwd) {
			currentCount = startTime;
		}
	}

	void AnimatedSprite::setStartFrame(int frame) {
		startFrame = frame;
		revAnimation = endFrame < startFrame;
	}

	void AnimatedSprite::setEndFrame(int frame) {
		endFrame = frame;
		revAnimation = endFrame < startFrame;
	}


	AnimatedSprite::~AnimatedSprite() {
		//dtor
	}
}
