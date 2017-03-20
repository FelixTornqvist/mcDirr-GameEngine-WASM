#ifndef PAUSESCREEN_HPP
#define PAUSESCREEN_HPP

#include "GUIScreen.hpp"
#include "GUIButton.hpp"
#include "GameEngine.hpp"

namespace mcDirr {
	class PauseScreen : public GUIScreen {
		public:
			PauseScreen(GameEngine *ge);
			virtual ~PauseScreen();

		protected:

		private:
			SDL_Surface *bg;
			SDL_Surface *continueSurf, *restartSurf, *exitSurf;
			GUIButton *continueB, *restartB, *exitB;

			GameEngine *ge;
			void restart();
			void putOnXMiddle(GUIButton* btn);
	};
}
#endif // PAUSESCREEN_HPP
