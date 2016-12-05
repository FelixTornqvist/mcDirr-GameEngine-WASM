#ifndef TEXTUREDSPRITE_H
#define TEXTUREDSPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <string>
#include "Sprite.h"

namespace mcDirr {
	class TexturedSprite : public Sprite {
		public:
			TexturedSprite(const std::string imagePath);

			void const draw() override;
			void tick(int timediff) override;

			virtual ~TexturedSprite();

		protected:

		private:
			SDL_Texture* texture;
	};
}

#endif // TEXTUREDSPRITE_H
