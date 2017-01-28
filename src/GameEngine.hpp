#ifndef FRAME_H
#define FRAME_H
#include <SDL.h>
#include <vector>
#include <string>

#include "Level.hpp"

namespace mcDirr {
	class GameEngine {
		public:
			GameEngine(std::string windowName, int w, int h, int _fps);
			void run();
			void setFirstLevel(Level* lvl);
			void skipLevel();
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
