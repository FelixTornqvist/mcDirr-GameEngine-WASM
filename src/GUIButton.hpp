#ifndef GUIBUTTON_HPP
#define GUIBUTTON_HPP

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "GUIElement.hpp"

namespace mcDirr {
	class GUIButton : public GUIElement {
		public:
			GUIButton(TTF_Font* fnt, SDL_Color colour, std::string labl, SDL_Rect dest);

			virtual void draw() override;
			virtual void tick(int millisPassed) override;
			virtual void mouseClick() override = 0;

			virtual ~GUIButton();

		protected:

		private:
			std::string label;
			bool clickTest = false;
	};
}

#endif // GUIBUTTON_HPP
