#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>
#include <stdexcept>

#include "Loader.hpp"
#include "System.hpp"

namespace mcDirr {

	SDL_Texture* Loader::loadTexture(std::string path) {
		SDL_Surface* surface = loadSurface(path);
		SDL_Texture* texture = loadTexture(surface);
		SDL_FreeSurface(surface);

		return texture;
	}

	SDL_Texture* Loader::loadTexture(SDL_Surface* surface) {
		return SDL_CreateTextureFromSurface(sys.getRen(), surface);
	}

	SDL_Surface* Loader::loadSurface(std::string path) {
		SDL_Surface* surface = IMG_Load(path.c_str());
		if (surface == nullptr)
			throw std::runtime_error(std::string("could not load texture:") + SDL_GetError());
		return surface;
	}


	Loader loader;
}
