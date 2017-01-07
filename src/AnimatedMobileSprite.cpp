#include "AnimatedMobileSprite.hpp"
#include "Loader.hpp"
#include "System.hpp"

namespace mcDirr {

	AnimatedMobileSprite::AnimatedMobileSprite(SDL_Surface* surf, int x, int y, double bouciness, int divs, int millisPerFrame) :
		MobileSprite(surf,x,y,bouciness), AnimatedSprite(loader.loadTexture(surf),x,y,divs,millisPerFrame)  {
		MobileSprite::dest = AnimatedSprite::dest;
	}

	void AnimatedMobileSprite::draw() const{
		AnimatedSprite::draw();
	}

	void AnimatedMobileSprite::tick(int millisPassed) {

		MobileSprite::tick(millisPassed);
		AnimatedSprite::tick(millisPassed);
	}

	void AnimatedMobileSprite::checkCollision(ImmobileSprite* other){
		MobileSprite::checkCollision(other);

		AnimatedSprite::dest.x = MobileSprite::dest.x;
		AnimatedSprite::dest.y = MobileSprite::dest.y;
	}

	AnimatedMobileSprite::~AnimatedMobileSprite() {
		//dtor
	}
}
