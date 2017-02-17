#ifndef SANTAHERO_HPP
#define SANTAHERO_HPP

#include <SDL.h>
#include "AnimatedMobileSprite.hpp"


#include <iostream>

namespace mcDirr {
	class SantaHero : public AnimatedMobileSprite {

	public:
		static SantaHero* getInstance(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame);

	protected:
		SantaHero(SDL_Surface* surf, int x, int y, int divs, int millisPerFrame);
		void customTick(int timeDiff);


	private:

	};
}

#endif
