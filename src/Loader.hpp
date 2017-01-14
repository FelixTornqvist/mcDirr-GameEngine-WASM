#ifndef LOADER_H
#define LOADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

namespace mcDirr {
	class Loader {
		public:
			SDL_Surface* loadSurface(std::string path);
			SDL_Texture* loadTexture(SDL_Surface* surface);
			SDL_Texture* loadTexture(std::string path);
			TTF_Font* loadFont(std::string path, int ptSize);
			Mix_Chunk* loadWAV(std::string path);
	};

	extern Loader loader;
}

#endif // LOADER_H
