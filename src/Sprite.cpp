#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include <stdexcept>

#include "Sprite.hpp"
#include "System.hpp"

namespace mcDirr {
    Sprite::Sprite(SDL_Texture* t) :
    texture(t) {
        int width;
        int height;
        SDL_QueryTexture(t, NULL, NULL, &width, &height);
        dest = {10, 10, width, height};
        
        dest.y++;
        
	}

	void const Sprite::draw(){
        SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
	}

	void Sprite::tick(int timediff){

	}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}
}
