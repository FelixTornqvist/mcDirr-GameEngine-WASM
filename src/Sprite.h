#ifndef Sprite_H
#define Sprite_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <string>
#include "Sprite.h"

namespace mcDirr {
	class Sprite{
		public:
			Sprite(const std::string imagePath);

			void const draw();
			void tick(int timediff);

			virtual ~Sprite();

		protected:

		private:
			SDL_Texture* texture;
	};
}

#endif // Sprite_H
