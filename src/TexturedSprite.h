#ifndef TEXTUREDSPRITE_H
#define TEXTUREDSPRITE_H

#include <string>

#include <SDL.h>

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
