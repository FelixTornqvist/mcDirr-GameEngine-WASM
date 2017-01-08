#ifndef SPRITE_H
#define SPRITE_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

namespace mcDirr {
	class Sprite {
		public:
			virtual void draw() const;
			virtual void tick(int timediff) = 0;

			virtual ~Sprite();
			SDL_Rect* getDestRect();
			SDL_Texture* getTexture() const;

		protected:
			Sprite(SDL_Surface* surf, int x, int y);
			SDL_Rect dest;
			SDL_Texture* texture;


		private:

	};
}

#endif // Sprite_H
