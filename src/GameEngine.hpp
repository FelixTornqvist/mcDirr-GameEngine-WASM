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
			void setFirstScreen(Screen* scrn);
			void skipScreen();
			virtual ~GameEngine();

		protected:

		private:
			int fps;
			bool running = false;
			Screen* currentScreen;
			Screen* firstScreen;

			void delay(Uint32 nextTick) const;
	};
}
#endif // FRAME_H
