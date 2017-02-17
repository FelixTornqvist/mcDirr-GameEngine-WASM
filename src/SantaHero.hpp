#ifndef SANTAHERO_HPP
#define SANTAHERO_HPP

#include <SDL.h>
#include "AnimatedMobileSprite.hpp"


#include <iostream>

namespace mcDirr {
	class SantaHero : public AnimatedMobileSprite {

	public:

	protected:
		void customTick(int timeDiff);

	private:

	};
}

#endif
