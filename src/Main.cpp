#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <iostream>
#include <math.h>

#include "sprite/Sprite.hpp"
#include "sprite/AnimatedSprite.hpp"
#include "sprite/VisualSprite.hpp"
#include "GameEngine.hpp"
#include "System.hpp"

#define FPS 60

using namespace std;
using namespace mcDirr;

class CustSprite : public AnimatedSprite {
	public:
		CustSprite(SDL_Texture* t, int x, int y, int rad, int cw): AnimatedSprite(t,x,y, 4, 500), radius(rad), clockwise(cw) {
			setStartFrame(getFramesAmt() - 2);
			setEndFrame(4);
		}
		float curr = 0;
		int radius;
		int clockwise;

		void tick(int time) override {
			AnimatedSprite::tick(time);
			curr += time;
			cout << curr << endl;
			dest.x = cos(curr / 500 * clockwise) * radius  + dest.x;
			dest.y = sin(curr / 500* clockwise) * radius + dest.y;
		}

//		void draw() const override {
//			SDL_RenderCopyEx(sys.getRen(), texture, NULL, &dest, curr/10,NULL, SDL_FLIP_NONE);
//		}
};



SDL_Texture* loadTexture(string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr)
		throw std::runtime_error(std::string("could not load texture:") + SDL_GetError());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
	SDL_FreeSurface(surface);

	return texture;
}



int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);

	SDL_Texture* texture = loadTexture("media/test-spritesheet.png");

	Sprite* s1 = new AnimatedSprite(texture, 10, 10, 4, 1000);
	Sprite* s2 = new CustSprite(texture, 300, 250, 0, -1);
	Sprite* s3 = new VisualSprite(texture, 200, 200);

	ge.add(s3);
	ge.add(s1);
	ge.add(s2);

	ge.run();

	return 0;
}

