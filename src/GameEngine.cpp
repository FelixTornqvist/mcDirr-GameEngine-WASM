#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameEngine.hpp"
#include "System.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <emscripten.h>

namespace mcDirr {

	GameEngine::GameEngine(std::string windowName, int wWidth, int wHeight, int _fps): fps(_fps) {
		sys.initialize(windowName, wWidth, wHeight);
	}

	void GameEngine::tick(long timePassed) {
		SDL_RenderClear(sys.getRen());
			screens[currentScreen]->draw();
			if (paused)
				pauseScreen->draw();
		SDL_RenderPresent(sys.getRen());

		if(screens[currentScreen]->isFinished()) {
			nextScreen();
		}
		if (paused){
			pauseScreen->tick(timePassed);
		} else {
			screens[currentScreen]->tick(timePassed);
		}

		sys.collectInputs();
		paused |= sys.isKeyDown(SDLK_ESCAPE);
		running &= !(sys.isQuitRequested() || (paused && pauseScreen == nullptr));
	}

	void GameEngine::tickWrap(void* g) {
		GameEngine* ge = static_cast<GameEngine*>(g);
		ge->tick(100);
	}
	
	void GameEngine::run() {
		running = true;

#ifdef __EMSCRIPTEN__
		//std::function<void(long)> tiick = std::bind(&GameEngine::tick, this, std::placeholders::_1);
		emscripten_set_main_loop_arg(&GameEngine::tickWrap, this, 60, 1);

#else
		Uint32 lastTick = SDL_GetTicks();
		Uint32 nextTick;

		while (running) {
			nextTick = lastTick + 1000 / fps;
			tick(nextTick - lastTick);

			delay(nextTick);
			lastTick = nextTick;
		}
#endif
	}

	void GameEngine::setScreen(Uint32 screenIndex) {
		currentScreen = screenIndex;
		if (currentScreen >= screens.size())
			running = false;
	}

	void GameEngine::nextScreen() {
		if (currentScreen < screens.size() - 1)
			currentScreen++;
	}

	void GameEngine::previousScreen() {
		if (currentScreen > 0)
			currentScreen--;
	}

	Level* GameEngine::getLevel() {
		if (Level* v = dynamic_cast<Level*>(screens[currentScreen]))
			return v;
		return nullptr;
	}

	int GameEngine::getScreenIndex() {
		return currentScreen;
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

	void GameEngine::setFrameRate(int frameRate) {

		if (frameRate <= 0) {
			throw std::invalid_argument("invalid framerate");

		} else {
			fps = frameRate;
		}
	}

	int GameEngine::getSetFrameRate() const {
		return fps;
	}

	void GameEngine::delay(Uint32 nextTick) const {
		int delay = nextTick - SDL_GetTicks();

		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

	GameEngine::~GameEngine() {
		for (Screen* screen : screens) {
			delete screen;
		}

		delete pauseScreen;
		sys.Quit();
	}
}
