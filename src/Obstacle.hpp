#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "ImmobileSprite.hpp"

namespace mcDirr {

	class Obstacle : public ImmobileSprite {

	public:
		static Obstacle* getInstance(SDL_Surface* s, int x, int y, float b);
		~Obstacle();

	protected:
		void customTick(int timeDiff);
	

	private:
		Obstacle(SDL_Surface* s, int x, int y, float b);

	};
}


#endif