#ifndef PAUSESCREEN_HPP
#define PAUSESCREEN_HPP

#include <memory>

#include "GUIScreen.hpp"
#include "GUIButton.hpp"
#include "GUIText.hpp"
#include "GUITextField.hpp"
#include "GameEngine.hpp"

namespace mcDirr {
	class PauseScreen : public GUIScreen {
		public:
			PauseScreen(GameEngine *ge, void (*resetFunk)());
			virtual ~PauseScreen();

		protected:

		private:
			SDL_Surface *bg;
			SDL_Surface *continueSurf, *restartSurf, *exitSurf, *updateSurf;
			TTF_Font *font, *tfFont;
			std::shared_ptr<GUIButton> continueB, restartB, exitB, updateB;
			std::shared_ptr<GUITextField> fpsInput;
			std::shared_ptr<GUIText> title, fpsLabel;

			GameEngine *ge;
			std::function<void()> resetFunc;
			void restart();
			void setFrameRate();
			void unPause();
			void putOnXMiddle(std::shared_ptr<GUIElement> btn);
	};
}
#endif // PAUSESCREEN_HPP
