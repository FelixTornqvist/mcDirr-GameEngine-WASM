#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "GameEngine.h"
#include "System.h"

#define W_WIDTH 1000
#define W_HEIGHT 800

namespace mcDirr {

	GameEngine::GameEngine(std::string windowName, int _fps): fps(_fps) {
		SDL_Init(SDL_INIT_EVERYTHING);
		IMG_Init(0);
		TTF_Init();
		win = SDL_CreateWindow(windowName.c_str(), 100, 100, W_WIDTH, W_HEIGHT, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
	}

	void GameEngine::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void GameEngine::remove(Sprite* sprite) {
		sprites.remove(sprite);
		delete sprite;
	}

	void GameEngine::run() {
		const Uint32 MILLIS_PER_LOOP = 1000 / fps;
		Uint32 lastTick = SDL_GetTicks();
		Uint32 nextTick;

		running = true;
		while(running) {
			nextTick = SDL_GetTicks() + MILLIS_PER_LOOP;
			sys.collectInputs();

			for(Sprite* curr : sprites)
				curr->tick(nextTick - lastTick);

			SDL_RenderClear(ren);
			for(Sprite* curr : sprites)
				curr->draw();
			SDL_RenderPresent(ren);

			running = !sys.isQuitRequested();
			delay(nextTick);
			lastTick = nextTick;
		}
	}

	void const GameEngine::delay(Uint32 nextTick) {
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}


	GameEngine::~GameEngine() {
		for(Sprite* sprite : sprites)
			delete sprite;

		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
}
