#ifndef FRAME_H
#define FRAME_H

#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include <vector>
#include <string>

#include "Level.hpp"

namespace mcDirr {
	class GameEngine {
		public:
			GameEngine(std::string windowName, int _fps);
			void run();
			void setFirstLevel(Level* lvl);
			virtual ~GameEngine();

		protected:

		private:
			int fps;
			bool running = false;
			Level* currentLevel;
			Level* firstLevel;

			void delay(Uint32 nextTick) const;
	};
}
#endif // FRAME_H
