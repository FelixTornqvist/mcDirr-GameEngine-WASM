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
        Sprite(SDL_Texture* _texure);

        void const draw();
        void tick(int timediff);

        virtual ~Sprite();

		protected:
        
        

		private:
			SDL_Texture* texture;
            SDL_Rect dest;
        
	};
}

#endif // Sprite_H
