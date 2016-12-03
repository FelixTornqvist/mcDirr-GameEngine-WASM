#include "System.h"

namespace mcDirr {

	System::System() {}

	void System::collectInputs() {
		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {
			switch (eve.type) {
				case SDL_QUIT:
					quitRequested = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					//mouse-button: eve.button.button
					break;
				case SDL_MOUSEBUTTONUP:
					break;
				case SDL_MOUSEMOTION:
					//mouse-motion: eve.motion.xrel eve.motion.yrel
					break;
				case SDL_KEYDOWN:
					//key: eve.key.keysym.sym
					break;
			}
		}
	}

	bool const System::isQuitRequested() {
		return quitRequested;
	}

	bool const System::isKeyDown(Uint8 key) {
		return false;
	}
	bool const System::isMouseButtonDown(Uint8 button) {
		return false;
	}

	Sint32 const System::relMouseX() {
		return 0;
	}

	Sint32 const System::relMouseY() {
		return 0;
	}

	System::~System() {}

	System sys;
}
