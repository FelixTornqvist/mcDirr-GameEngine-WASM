#ifndef GUIELEMENT_HPP
#define GUIELEMENT_HPP

#include <SDL.h>

namespace mcDirr {
	class GUIElement {
		public:
			GUIElement(SDL_Rect dest);

			virtual void draw() = 0;
			virtual void tick(int millisPassed) = 0;
			virtual void mouseClick() = 0;
			SDL_Rect getDest();

			virtual ~GUIElement();

		protected:
			SDL_Rect dest;

		private:
	};
}

#endif // GUIELEMENT_HPP
