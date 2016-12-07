#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#endif

#include <string>
#include "System.hpp"

namespace mcDirr {

	void System::initialize(std::string winName, int wWidth, int wHeight) {
		SDL_Init(SDL_INIT_EVERYTHING);
		IMG_Init(0);
		TTF_Init();
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);

		win = SDL_CreateWindow(winName.c_str(), 100, 100, wWidth, wHeight, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
	}

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

					//TODO: remove vv
					if (eve.key.keysym.sym == SDLK_ESCAPE)
						quitRequested = true;
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

	void System::Quit() {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	System sys;
}
