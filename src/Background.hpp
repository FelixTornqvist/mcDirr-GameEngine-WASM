#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "VisualSprite.hpp"

namespace mcDirr {
	class Background : public VisualSprite {
		public:
			static Background* getInstance(SDL_Surface* s, int x, int y);
			virtual ~Background();

			void customTick(int timeDiff);

		protected:
			Background(SDL_Surface* s, int x, int y);

		private:
	};
}

#endif // BACKGROUND_HPP
