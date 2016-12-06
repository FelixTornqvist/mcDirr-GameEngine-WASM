#ifndef Sprite_H
#define Sprite_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <string>
#include "Sprite.hpp"

namespace mcDirr {
	class Sprite{
		public:
        Sprite(SDL_Texture* _texure, int, int);

        virtual void draw() const;
        virtual void tick(int timediff);

        virtual ~Sprite();

		protected:
            SDL_Rect dest;
			SDL_Texture* texture;



		private:

	};
}

#endif // Sprite_H
