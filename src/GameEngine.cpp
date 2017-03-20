#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "GameEngine.hpp"
#include "System.hpp"

#include <iostream>
#include <vector>
#include <list>

namespace mcDirr {

	GameEngine::GameEngine(std::string windowName, int wWidth, int wHeight, int _fps): fps(_fps) {
		sys.initialize(windowName, wWidth, wHeight);
	}

	void GameEngine::run() {
		const Uint32 MILLIS_PER_LOOP = 1000 / fps;
		Uint32 lastTick = SDL_GetTicks();
		Uint32 nextTick;

		running = true;
		while(running) {
			nextTick = lastTick + MILLIS_PER_LOOP;

			SDL_RenderClear(sys.getRen());
				screens[currentScreen]->draw();
				if (paused)
					pauseScreen->draw();
			SDL_RenderPresent(sys.getRen());

			if(screens[currentScreen]->isFinished()) {
				skipScreen();
			}
			if (paused){
				pauseScreen->tick(nextTick - lastTick);
			} else {
				screens[currentScreen]->tick(nextTick - lastTick);
			}

			sys.collectInputs();
			paused |= sys.isKeyDown(SDLK_ESCAPE);
			running &= !(sys.isQuitRequested() || (paused && pauseScreen == nullptr));
			delay(nextTick);
			lastTick = nextTick;
		}
	}

	void GameEngine::setScreen(int screenIndex) {
		currentScreen = screenIndex;
		if (currentScreen >= screens.size())
			running = false;
	}

	void GameEngine::skipScreen() {
		currentScreen++;
		if (currentScreen >= screens.size())
			running = false;
	}

	void GameEngine::addScreen(Screen* newScreen) {
		screens.push_back(newScreen);
	}

	void GameEngine::setPauseScreen(GUIScreen* screen) {
		pauseScreen = screen;
	}

	void GameEngine::setPause(bool pause) {
		paused = pause;
	}

	void GameEngine::pause() {
		paused = true;
	}

	void GameEngine::unPause() {
		paused = false;
	}

	void GameEngine::stop() {
		running = false;
	}

	void GameEngine::delay(Uint32 nextTick) const {
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}

	GameEngine::~GameEngine() {
		for (Screen* screen : screens)
			delete screen;

		sys.Quit();
	}
}
