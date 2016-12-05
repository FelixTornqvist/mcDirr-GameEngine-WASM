#include "TexturedSprite.h"
#include "System.h"

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif


#include <string>
#include <stdexcept>

namespace mcDirr {
	TexturedSprite::TexturedSprite(const std::string filePath): Sprite(filePath) {
		SDL_Surface* surface = IMG_Load(filePath.c_str());
		if(surface == nullptr)
			throw std::runtime_error(std::string("could not load texture:") + SDL_GetError());
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		SDL_FreeSurface(surface);
	}

	void const TexturedSprite::draw(){
		SDL_Rect r = {10, 10, 400, 400};
		SDL_RenderCopy(sys.getRen(), texture, NULL, &r);
	}

	void TexturedSprite::tick(int timediff){

	}

	TexturedSprite::~TexturedSprite() {
		SDL_DestroyTexture(texture);
	}
}
