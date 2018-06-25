#ifndef FRAME_H
#define FRAME_H

#include <SDL.h>
#include <vector>
#include <string>

#include "Screen.hpp"
#include "GUIScreen.hpp"
#include "Level.hpp"

namespace mcDirr {

	class GameEngine {
		
		public:
			GameEngine(std::string windowName, int w, int h, int _fps);

			void run();
			void addScreen(Screen* screen);
			void setScreen(Uint32 screenIndex);
			Level* getLevel();
			int getScreenIndex();
			void nextScreen();
			void previousScreen();

			void setPauseScreen(GUIScreen* screen);
			void setPause(bool pause);
			void pause();
			void unPause();
			void stop();
			void setFrameRate(int fps);
			int getSetFrameRate() const;

			virtual ~GameEngine();

		private:
			int fps;
			Uint32 lastTick, nextTick;
			bool running = false;
			Uint32 currentScreen;
			std::vector<Screen*> screens;

			bool paused = false;
			GUIScreen* pauseScreen = nullptr;

			void tick();
			static void tickWrap(void* ge);
			void delay(Uint32 nextTick) const;
	};
}

#endif // FRAME_H
