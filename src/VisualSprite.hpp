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
		VisualSprite(SDL_Texture* t, int x, int y);

		void tick(int passedTime) override;
		void draw() const override;

		virtual ~VisualSprite();

	protected:

	private:
		SDL_Rect srcRect;
	};
}
#endif