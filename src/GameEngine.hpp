#ifndef FRAME_H
#define FRAME_H
#include <SDL.h>
#include <vector>
#include <string>

#include "Screen.hpp"

namespace mcDirr {
	class GameEngine {
		public:
			GameEngine(std::string windowName, int w, int h, int _fps);
			void run();
			void addScreen(Screen* screen);
			void setScreen(int screenIndex);
			void skipScreen();
			virtual ~GameEngine();

		protected:

		private:
			int fps;
			bool running = false;
			int currentScreen;
			std::vector<Screen*> screens;

			void delay(Uint32 nextTick) const;
	};
}
#endif // FRAME_H
