#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <memory>
#include "MobileSprite.hpp"

namespace mcDirr {

	class Particle : public MobileSprite {

		public:
			static std::shared_ptr<Particle> getInstance(SDL_Surface* surf, int x, int y, double xVel, double yVel, int lifetime);

			void customTick(int timeDiff) override;
			void handleMobileCollision(std::shared_ptr<MobileSprite> collWith, int side) {}
			void draw() const override;

			virtual ~Particle() {}

		protected:
			Particle(SDL_Surface* surf, int x, int y, double xVel, double yVel, int lifetime);

		private:
			int lifeTime, passedTime;
			SDL_Rect src;
	};
}

#endif // PARTICLE_HPP
