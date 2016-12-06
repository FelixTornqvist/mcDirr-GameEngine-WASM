#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <iostream>
#include <math.h>

#include "Sprite.hpp"
#include "Sprite.hpp"
#include "GameEngine.hpp"
#include "System.hpp"

#define FPS 60

using namespace std;
using namespace mcDirr;

class CustSprite : public Sprite{
	public:
	CustSprite(SDL_Texture* t, int x, int y, int rad, int cw): Sprite(t,x,y), radius(rad), clockwise(cw){
	}
	float curr = 0;
	int radius;
	int clockwise;

	void tick(int time) override{
		curr += time;
		cout << curr << endl;
		dest.x = cos(curr / 200 * clockwise) * radius  + dest.x;
		dest.y = sin(curr / 200* clockwise) * radius + dest.y;
	}

	void draw() const override{
		SDL_RenderCopyEx(sys.getRen(),texture,NULL,&dest,curr,NULL, SDL_FLIP_NONE);
	}
};

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);

    SDL_Surface* surface = IMG_Load("media/ebbug.png");
        if (surface == nullptr)
            throw std::runtime_error(std::string("could not load texture:") + SDL_GetError());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
    SDL_FreeSurface(surface);



	Sprite* s1 = new CustSprite(texture, 100, 200, 50, 1);
	Sprite* s2 = new CustSprite(texture, 300, 500, 20, -1);
//	Sprite* s2 = new Sprite("media/gubbe.bmp");

	ge.add(s1);
	ge.add(s2);


	ge.run();

	return 0;
}

