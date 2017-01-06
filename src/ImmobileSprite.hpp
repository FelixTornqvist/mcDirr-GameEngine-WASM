#ifndef IMMOBILESPRITE_HPP
#define IMMOBILESPRITE_HPP

#include "Sprite.hpp"

namespace mcDirr {
	class ImmobileSprite : public Sprite {
		public:
			ImmobileSprite(SDL_Texture* t, int x, int y);
			virtual ~ImmobileSprite();

		protected:

		private:
	};
}

#endif // IMMOBILESPRITE_HPP
