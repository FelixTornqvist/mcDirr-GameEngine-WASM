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


#include "GameEngine.hpp"
#include "System.hpp"

#include <iostream>
#include <vector>
#include <list>

#define W_WIDTH 1000
#define W_HEIGHT 800

namespace mcDirr {

	GameEngine::GameEngine(std::string windowName, int _fps): fps(_fps) {
		sys.initialize(windowName, W_WIDTH, W_HEIGHT);
	}

	void GameEngine::run() {
		const Uint32 MILLIS_PER_LOOP = 1000 / fps;
		Uint32 lastTick = SDL_GetTicks();
		Uint32 nextTick;

		running = true;
		sys.listenForTyping(true);
		while(running) {
			SDL_SetRenderDrawColor(sys.getRen(), 200, 255, 255, 255);	//TODO: temporary
			nextTick = SDL_GetTicks() + MILLIS_PER_LOOP;
			sys.collectInputs();

			currentLevel->tick(nextTick - lastTick);

			SDL_RenderClear(sys.getRen());
			currentLevel->draw();
			SDL_RenderPresent(sys.getRen());

			if(currentLevel->isComplete()) {
				currentLevel = currentLevel->getNextLevel();
				if(currentLevel == nullptr)
					running = false;
			}

			running &= !(sys.isQuitRequested() || sys.isKeyDown(SDLK_ESCAPE));
			delay(nextTick);
			lastTick = nextTick;
		}
	}

	void GameEngine::delay(Uint32 nextTick) const {
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}

	void GameEngine::setFirstLevel(Level* lvl) {
		if(firstLevel != nullptr) {
			firstLevel = lvl;
			currentLevel = lvl;
		}

	}

	GameEngine::~GameEngine() {
		delete firstLevel;

		sys.Quit();
	}
}
