#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <memory>
#include "ImmobileSprite.hpp"

namespace mcDirr {

	class Obstacle : public ImmobileSprite {

	public:
		static std::shared_ptr<Obstacle> getInstance(SDL_Surface* s, int x, int y, float b);
		~Obstacle();

	protected:
		void customTick(int timeDiff) override;
		Obstacle(SDL_Surface* s, int x, int y, float b);

	};
}


#endif
