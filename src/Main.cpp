#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

#include <iostream>
#include <math.h>

#include "Sprite.hpp"
#include "AnimatedSprite.hpp"
#include "VisualSprite.hpp"
#include "GameEngine.hpp"
#include "PhysicalSprite.hpp"
#include "System.hpp"
#include "Loader.hpp"

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
			//cout << curr << endl;
			dest.x = cos(curr / 500 * clockwise) * radius  + dest.x;
			dest.y = sin(curr / 500* clockwise) * radius + dest.y;
		}

//		void draw() const override {
//			SDL_RenderCopyEx(sys.getRen(), texture, NULL, &dest, curr/10,NULL, SDL_FLIP_NONE);
//		}
};

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);

	//SDL_Texture* texture = loadTexture("media/test-spritesheet.png");
	// SDL_Texture* colors = loadTexture("media/colors.png");
	SDL_Surface * surf = IMG_Load("media/cat.bmp");


	// SDL_Texture* catTexture = loader.loadTexture("media/cat.bmp");
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, BGmusic, -1);

	//Sprite* s1 = new AnimatedSprite(texture, 10, 10, 4, 1000);
	//Sprite* s2 = new CustSprite(texture, 300, 250, 0, -1);
	PhysicalSprite* s1 = PhysicalSprite::getInstance(surf, 200, 200, 0, false); // last int is for speed. 0 cant be moved.
	PhysicalSprite* s2 = PhysicalSprite::getInstance(surf, 400, 200, 0, true);
	PhysicalSprite* s3 = PhysicalSprite::getInstance(surf, 600, 200, 0, true);
	PhysicalSprite* s4 = PhysicalSprite::getInstance(surf, 800, 200, 0.5, true); // can be moved. Remove last int later. only to test collision.

	PhysicalSprite* s5 = PhysicalSprite::getInstance(surf, 200, 600, 0, false);
	PhysicalSprite* s6 = PhysicalSprite::getInstance(surf, 300, 600, 0, false);
	PhysicalSprite* s7 = PhysicalSprite::getInstance(surf, 400, 600, 0, false);
	PhysicalSprite* s8 = PhysicalSprite::getInstance(surf, 500, 600, 0, false);
	PhysicalSprite* s9 = PhysicalSprite::getInstance(surf, 600, 600, 0, false);
	PhysicalSprite* s10 = PhysicalSprite::getInstance(surf, 700, 600, 0, false);
	PhysicalSprite* s11 = PhysicalSprite::getInstance(surf, 800, 600, 0, false);
	PhysicalSprite* s12 = PhysicalSprite::getInstance(surf, 900, 600, 0, false);
	PhysicalSprite* s13 = PhysicalSprite::getInstance(surf, 100, 600, 0, false);
	PhysicalSprite* s14 = PhysicalSprite::getInstance(surf, 0, 600, 0, false);

	ge.add(s1);
	ge.add(s2);
	ge.add(s3);
	ge.add(s4);

	ge.add(s5);
	ge.add(s6);
	ge.add(s7);
	ge.add(s8);
	ge.add(s9);
	ge.add(s10);
	ge.add(s11);
	ge.add(s12);
	ge.add(s13);
	ge.add(s14);

	ge.run();

	return 0;
}

