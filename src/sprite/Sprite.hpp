#ifndef SPRITE_H
#define SPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <string>

namespace mcDirr {
	class Sprite{
		public:
        Sprite(SDL_Texture*, int, int);

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
