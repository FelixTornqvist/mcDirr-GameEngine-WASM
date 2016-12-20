#ifndef FRAME_H
#define FRAME_H

#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include <list>
#include <vector>

#include "Sprite.hpp"
#include "PhysicalSprite.hpp"

namespace mcDirr {
	class GameEngine {
	public:
		GameEngine(std::string windowName, int _fps);
		void add(Sprite* sprite);
		void add(PhysicalSprite* pSprite);
		void remove(Sprite* sprite);
		void remove(PhysicalSprite* sprite);
		void run();
		virtual ~GameEngine();

	protected:

	private:
		int fps;
		bool running = false;

		std::list<Sprite*> sprites;
		std::list<PhysicalSprite*> physicalSprites;

		void collisionChecks(std::list<PhysicalSprite*>::iterator);
		void delay(Uint32 nextTick) const;
	};
}
#endif // FRAME_H
