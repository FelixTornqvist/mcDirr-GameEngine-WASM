#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <string>
#include <unordered_map>
#include <functional>

namespace mcDirr {
	class System {
		public:
			void initialize(std::string winName, int wWidth, int wHeight);

			SDL_Renderer* getRen();
			SDL_Window* getWin();

			/**reads all of the current inputs and saves them for later calculations for "this tick" */
			void collectInputs();

			bool isQuitRequested() const;

			/**Example: isKeyDown(SDLK_A); to check if the 'A'-key is down*/
			bool isKeyDown(Uint8 key);

			/**Example: isMouseButtonDown(SDL_BUTTON_LEFT); to check if the left mouse button is down*/
			bool isMouseButtonDown(Uint8 button);
			bool haveMouseButtonsChanged();

			/**mouse movements relative to the last time updateInputs() was called*/
			Sint32 getMouseX() const;
			Sint32 getMouseY() const;

			std::string getTypedString() const;
			void listenForTyping(bool listen);

			template<class AnyClass>
			/** member functions*/
			void addKeyFunction(Uint8 key, AnyClass *object, void (AnyClass::*func)() );

			/** free functions*/
			void addKeyFunction(Uint8 key, void (*func)() );

			void Quit();

		protected:

		private:
			SDL_Renderer* ren;
			SDL_Window* win;

			bool quitRequested = false;
			std::unordered_map<Uint8, bool> keys;
			std::unordered_map<Uint8, bool> mouseButtons;
			bool mouseButtonsChanged = false;
			Sint32 mouseX, mouseY;

			std::unordered_map<Uint8, std::function<void()>> funcMapping;

			bool collectTyping = false;
			std::string typed = " ";
	};

	/* implementation needed in header file because of the use of template*/
	template<class AnyClass>
	void System::addKeyFunction(Uint8 key, AnyClass *object, void (AnyClass::*func)() ) {
		funcMapping[key] = std::bind(func, object);
	}

	extern System sys;
}
#endif // SYSTEM_H
