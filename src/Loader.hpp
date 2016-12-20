#ifndef LOADER_H
#define LOADER_H
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#endif

#include <string>

namespace mcDirr {
	class Loader {
		public:
			SDL_Surface* loadSurface(std::string path);
			SDL_Texture* loadTexture(SDL_Surface* surface);
			SDL_Texture* loadTexture(std::string path);

			TTF_Font* loadFont(std::string path, int ptSize);

			Mix_Chunk* loadWAV(std::string path);

		protected:

		private:

	};

	extern Loader loader;
}

#endif // LOADER_H
