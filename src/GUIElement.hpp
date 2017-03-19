#ifndef GUIELEMENT_HPP
#define GUIELEMENT_HPP

#include <SDL.h>

#include "Sprite.hpp"

namespace mcDirr {
	class GUIElement: public Sprite {
		public:
			GUIElement(SDL_Surface* surf, int x, int y);

			virtual void mouseClick() = 0;

			virtual ~GUIElement();

		protected:

		private:
	};
}

#endif // GUIELEMENT_HPP
