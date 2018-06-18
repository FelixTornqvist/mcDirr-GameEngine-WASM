#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
#include <iostream>
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
		std::cout << "LoadSurface" << std::endl;
		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			std::cout << "surface error" << SDL_GetError() << std::endl;
			throw std::runtime_error(std::string("Could not load texture: ") + SDL_GetError());
		}
		return surface;
	}

	TTF_Font* Loader::loadFont(std::string path, int ptSize) {
		std::cout << "openFont" << std::endl;
		TTF_Font* font = TTF_OpenFont(path.c_str(), ptSize);

		std::cout << "font opened" << std::endl;
		if (font == nullptr) {
			std::cout << "font error" << SDL_GetError() << std::endl;
			throw std::runtime_error(std::string("Could not load font: ") + SDL_GetError());
		}
		return font;
	}

	/*Mix_Chunk* Loader::loadWAV(std::string path) {
		Mix_Chunk* sound = Mix_LoadWAV(path.c_str());

		if (sound == nullptr)
			throw std::runtime_error(std::string("Could not load WAV file: ") + SDL_GetError());
		return sound;
	}*/

	Loader loader;
}
