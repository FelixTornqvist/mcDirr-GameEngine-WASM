#ifndef VISUALSPRITE_H
#define VISUALSPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "Sprite.hpp"

namespace mcDirr {
	class VisualSprite : public Sprite {
	public:
		static VisualSprite* getInstance(SDL_Surface*, int, int);

		void tick(int passedTime) override;
		void draw() const override;

		virtual ~VisualSprite();

	protected:
		VisualSprite(SDL_Surface* s, int x, int y);
	private:
		SDL_Rect srcRect;
	};
}
#endif
