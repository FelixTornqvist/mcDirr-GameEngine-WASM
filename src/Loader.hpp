#ifndef LOADER_H
#define LOADER_H
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>

namespace mcDirr {
	class Loader {
		public:
			SDL_Surface* loadSurface(std::string path);
			SDL_Texture* loadTexture(SDL_Surface* surface);
			SDL_Texture* loadTexture(std::string path);

		protected:

		private:

	};

	extern Loader loader;
}

#endif // LOADER_H
