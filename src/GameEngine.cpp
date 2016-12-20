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

    // helloooo

	GameEngine::GameEngine(std::string windowName, int _fps): fps(_fps) {
		sys.initialize(windowName, W_WIDTH, W_HEIGHT);
	}

	void GameEngine::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}
	
	void GameEngine::add(PhysicalSprite* pSprite) {
		physicalSprites.push_back(pSprite);
	}

	void GameEngine::remove(Sprite* sprite) {
		sprites.remove(sprite);
		delete sprite;
	}

	void GameEngine::remove(PhysicalSprite* pSprite) {
		physicalSprites.remove(pSprite);
		delete pSprite;
	}

	void GameEngine::run() {
		const Uint32 MILLIS_PER_LOOP = 1000 / fps;
		Uint32 lastTick = SDL_GetTicks();
		Uint32 nextTick;

		running = true;
		while(running) {
			nextTick = SDL_GetTicks() + MILLIS_PER_LOOP;
			sys.collectInputs();

			for (Sprite* curr : sprites) {
				curr->tick(nextTick - lastTick);
			}

			for (std::list<PhysicalSprite*>::iterator it = physicalSprites.begin(); it != physicalSprites.end();) {
				(*it)->tick(nextTick - lastTick);
				
				for (PhysicalSprite* curr : physicalSprites) {
					if (((*it) != curr) && (SDL_HasIntersection((*it)->getRect(), curr->getRect()))) {
						std::cout << "kollision" << std::endl;
					}	
				} 
				
				if (!(*it)->isAlive()) {
					it = physicalSprites.erase(it);
				}
				else
					it++;
			}
			SDL_SetRenderDrawColor(sys.getRen(), 200, 255, 255, 255);	//TODO: temporary
			SDL_RenderClear(sys.getRen());
			for (PhysicalSprite* curr : physicalSprites)
				curr->draw();

			for(Sprite* curr : sprites)
				curr->draw();

			SDL_RenderPresent(sys.getRen());

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

		sys.Quit();
	}
}
