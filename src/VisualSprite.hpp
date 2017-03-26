#ifndef VISUALSPRITE_H
#define VISUALSPRITE_H

#include <SDL.h>
#include "Sprite.hpp"

namespace mcDirr {

	class VisualSprite : public Sprite {

	public:
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
