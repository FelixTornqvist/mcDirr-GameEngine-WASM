#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <iostream>
#include "Sprite.hpp"
#include "Sprite.hpp"
#include "GameEngine.hpp"
#include "System.hpp"

#define FPS 60

using namespace std;
using namespace mcDirr;

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);
    
    SDL_Surface* surface = IMG_Load("media/ebbug.png");
        if (surface == nullptr)
            throw std::runtime_error(std::string("could not load texture:") + SDL_GetError());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
    SDL_FreeSurface(surface);
    
    
    
	Sprite* s1 = new Sprite(texture);
//	Sprite* s2 = new Sprite("media/gubbe.bmp");

	ge.add(s1);
//	ge.add(s2);


	ge.run();

	return 0;
}

