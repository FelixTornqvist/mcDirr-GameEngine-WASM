#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>

namespace mcDirr {
	class System {
		public:
			System();

			/**reads all of the current inputs and saves them for later calculations for "this tick" */
			void collectInputs();

			bool const isQuitRequested();

			/**Example: isKeyDown(SDLK_A); to check if the 'A'-key is down*/
			bool const isKeyDown(Uint8 key);

			/**Example: isMouseButtonDown(SDL_BUTTON_LEFT); to check if the left mouse button is down*/
			bool const isMouseButtonDown(Uint8 button);

			/**mouse movements relative to the last time updateInputs() was called*/
			Sint32 const relMouseX();
			Sint32 const relMouseY();

			virtual ~System();

		protected:

		private:
			bool quitRequested = false;
			// datastructures to hold pressed keys, mouse-buttons and mouse-movements
	};

	extern System sys;
}
#endif // SYSTEM_H
