#ifndef EVILCAT_HPP
#define EVILCAT_HPP

#include <memory>
#include "MobileSprite.hpp"

namespace mcDirr {
	class EvilCat : public MobileSprite {
		public:
			static std::shared_ptr<EvilCat> getInstance(SDL_Surface* surface, SDL_Texture* healthSym);
			void kill() override;

		protected:
			void customTick(int timeDiff);
			EvilCat(SDL_Surface* s, SDL_Texture* healthSym);

		private:
			int damageCooldown = 0;
			void handleMobileCollision(std::shared_ptr<MobileSprite> collidedWith, int side) override;
	};
}

#endif
