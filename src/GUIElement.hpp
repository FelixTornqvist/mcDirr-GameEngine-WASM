#ifndef GUIELEMENT_HPP
#define GUIELEMENT_HPP

#include <SDL.h>

namespace mcDirr {
	class GUIElement {
		public:
			GUIElement(SDL_Rect dest);

			virtual void draw();
			virtual void tick(int millisPassed);
			virtual void mouseClick();
			SDL_Rect getDest();

			virtual ~GUIElement();

		protected:

		private:
			SDL_Rect dest;
			bool clickTest;
	};
}

#endif // GUIELEMENT_HPP
