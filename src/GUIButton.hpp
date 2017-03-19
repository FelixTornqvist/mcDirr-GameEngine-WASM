#ifndef GUIBUTTON_HPP
#define GUIBUTTON_HPP

#include <SDL.h>

#include "GUIElement.hpp"

namespace mcDirr {
	class GUIButton : public GUIElement {
		public:
			GUIButton(SDL_Surface* surf);

			virtual void tick(int millisPassed) override;
			virtual void customTick(int millisPassed) override;
			virtual void mouseClick() override = 0;

			virtual ~GUIButton();

		protected:

		private:
			bool clickTest = false;
	};
}

#endif // GUIBUTTON_HPP
