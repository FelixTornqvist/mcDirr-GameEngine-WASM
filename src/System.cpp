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
#include <iostream>
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
					mouseButtons[eve.button.button] = true;
					break;
				case SDL_MOUSEBUTTONUP:
					mouseButtons[eve.button.button] = false;
					break;
				case SDL_MOUSEMOTION:
					mouseX = eve.motion.x;
					mouseY = eve.motion.y;
					break;
				case SDL_KEYDOWN:
					keys[eve.key.keysym.sym] = true;
					if(collectTyping) {
						typed += eve.key.keysym.sym;
//						std::cout << typed << std::endl;
					}
					break;
				case SDL_KEYUP:
					keys[eve.key.keysym.sym] = false;
					break;
			}
		}
	}

	bool System::isQuitRequested() const {
		return quitRequested;
	}

	bool System::isKeyDown(Uint8 key) {
		return keys[key];
	}
	bool System::isMouseButtonDown(Uint8 button) {
		return mouseButtons[button];
	}

	Sint32 System::getMouseX() const {
		return mouseX;
	}

	Sint32 System::getMouseY() const {
		return mouseY;
	}

	std::string System::getTypedString() const {
		return typed;
	}

	void System::listenForTyping(bool listen) {
		collectTyping = listen;
		if(!listen)
			typed.clear();
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
