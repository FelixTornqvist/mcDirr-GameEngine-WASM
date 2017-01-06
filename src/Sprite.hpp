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
			virtual void draw() const = 0;
			virtual void tick(int timediff) = 0;

	        virtual ~Sprite();
			SDL_Rect getDestRect() const;
			SDL_Texture* getTexture() const;

		protected:
			Sprite(SDL_Texture* t, int x, int y);
            SDL_Rect dest;
			SDL_Texture* texture;


		private:

	};
}

#endif // Sprite_H
