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
			static Sprite* getInstance(SDL_Texture*, int, int);
			virtual void draw() const;
			virtual void tick(int timediff);

	        virtual ~Sprite();
			SDL_Rect* getRect();
		protected:
			Sprite(SDL_Texture* t, int x, int y) :
				texture(t) {
				int width;
				int height;
				SDL_QueryTexture(t, NULL, NULL, &width, &height);
				dest = { x, y, width, height };
			}

            SDL_Rect dest;
			SDL_Texture* texture;

		private:

	};
}

#endif // Sprite_H
