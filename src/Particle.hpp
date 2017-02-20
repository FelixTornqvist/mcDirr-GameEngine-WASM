#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "MobileSprite.hpp"

namespace mcDirr {
	class Particle : public MobileSprite {
		public:
			Particle(SDL_Surface* surf, int x, int y, double xVel, double yVel, int lifetime);

			void customTick(int timeDiff) override;
			void handleMobileCollision(MobileSprite* collWith, int side) {}
			void draw() const override;

			virtual ~Particle();

		protected:

		private:
			int lifeTime, passedTime;
			SDL_Rect src;
	};
}
#endif // PARTICLE_HPP
