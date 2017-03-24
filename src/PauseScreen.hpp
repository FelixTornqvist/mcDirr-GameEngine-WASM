#ifndef PAUSESCREEN_HPP
#define PAUSESCREEN_HPP

#include "GUIScreen.hpp"
#include "GUIButton.hpp"
#include "GUIText.hpp"
#include "GUITextField.hpp"
#include "GameEngine.hpp"

namespace mcDirr {
	class PauseScreen : public GUIScreen {
		public:
			PauseScreen(GameEngine *ge);
			virtual ~PauseScreen();

		protected:

		private:
			SDL_Surface *bg;
			SDL_Surface *continueSurf, *restartSurf, *exitSurf, *updateSurf;
			GUIButton *continueB, *restartB, *exitB, *updateB;
			GUITextField* fpsInput;
			TTF_Font *font, *tfFont;
			GUIText *title, *fpsLabel;

			GameEngine *ge;
			void restart();
			void setFrameRate();
			void unPause();
			void putOnXMiddle(GUIElement* btn);
	};
}
#endif // PAUSESCREEN_HPP
