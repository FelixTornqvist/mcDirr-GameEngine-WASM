#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <SDL.h>

namespace mcDirr {
	class System {
		public:
			void initialize(std::string winName, int wWidth, int wHeight);

			SDL_Renderer* getRen() {
				return ren;
			}
			SDL_Window* getWin() {
				return win;
			}

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

			void Quit();

		protected:

		private:
			SDL_Renderer* ren;
			SDL_Window* win;

			bool quitRequested = false;
			// datastructures to hold pressed keys, mouse-buttons and mouse-movements
	};

	extern System sys;
}
#endif // SYSTEM_H
