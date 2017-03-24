#ifndef FRAME_H
#define FRAME_H

#include <SDL.h>
#include <vector>
#include <string>

#include "Screen.hpp"
#include "GUIScreen.hpp"

namespace mcDirr {
	class GameEngine {
		public:
			GameEngine(std::string windowName, int w, int h, int _fps);

			void run();
			void addScreen(Screen* screen);
			void setScreen(Uint32 screenIndex);
			void skipScreen();

			void setPauseScreen(GUIScreen* screen);
			void setPause(bool pause);
			void pause();
			void unPause();
			void stop();
			void setFrameRate(int fps);
			int getSetFrameRate() const;

			virtual ~GameEngine();

		protected:

		private:
			int fps;
			bool running = false;
			Uint32 currentScreen;
			std::vector<Screen*> screens;

			bool paused = false;
			GUIScreen* pauseScreen = nullptr;

			void delay(Uint32 nextTick) const;
	};
}
#endif // FRAME_H
