#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <string>
#include <unordered_map>

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

			bool isQuitRequested() const;

			/**Example: isKeyDown(SDLK_A); to check if the 'A'-key is down*/
			bool isKeyDown(Uint8 key);

			/**Example: isMouseButtonDown(SDL_BUTTON_LEFT); to check if the left mouse button is down*/
			bool isMouseButtonDown(Uint8 button);

			/**mouse movements relative to the last time updateInputs() was called*/
			Sint32 getMouseX() const;
			Sint32 getMouseY() const;

			std::string getTypedString() const;
			void listenForTyping(bool listen);

			void Quit();

		protected:

		private:
			SDL_Renderer* ren;
			SDL_Window* win;

			bool quitRequested = false;
			std::unordered_map<Uint8, bool> keys;
			std::unordered_map<Uint8, bool> mouseButtons;
			Sint32 mouseX, mouseY;

			bool collectTyping = false;
			std::string typed = " ";
	};

	extern System sys;
}
#endif // SYSTEM_H
