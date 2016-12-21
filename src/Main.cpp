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
#include "PhysicalSprite.hpp"
#include "Level.hpp"
#include "GameEngine.hpp"
#include "System.hpp"
#include "Loader.hpp"

#define FPS 50

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

	PhysicalSprite* s15 = PhysicalSprite::getInstance(surf, 600, 200, 0, false);
	PhysicalSprite* s16 = PhysicalSprite::getInstance(surf, 800, 200, 0.5, false);

	PhysicalSprite* s17 = PhysicalSprite::getInstance(surf, 400, 600, 0, true);
	PhysicalSprite* s18 = PhysicalSprite::getInstance(surf, 500, 600, 0, true);
	PhysicalSprite* s19 = PhysicalSprite::getInstance(surf, 600, 600, 0, true);
	PhysicalSprite* s20 = PhysicalSprite::getInstance(surf, 700, 600, 0, true);
	PhysicalSprite* s21 = PhysicalSprite::getInstance(surf, 800, 600, 0, true);

	Level* lvl2 = Level::getInstance(nullptr);

	lvl2->add(s15);
	lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);
	lvl2->add(s19);
	lvl2->add(s20);
	lvl2->add(s21);


	PhysicalSprite* s1 = PhysicalSprite::getInstance(surf, 200, 200, 0, true); // last int is for speed. 0 cant be moved.
	PhysicalSprite* s2 = PhysicalSprite::getInstance(surf, 400, 200, 0, false);
	PhysicalSprite* s3 = PhysicalSprite::getInstance(surf, 600, 200, 0, false);
	PhysicalSprite* s4 = PhysicalSprite::getInstance(surf, 800, 200, 0, false); // can be moved. Remove last int later. only to test collision.

	PhysicalSprite* s5 = PhysicalSprite::getInstance(surf, 200, 600, 0, true);
	PhysicalSprite* s6 = PhysicalSprite::getInstance(surf, 300, 600, 0, true);
	PhysicalSprite* s7 = PhysicalSprite::getInstance(surf, 400, 600, 0, true);
	PhysicalSprite* s8 = PhysicalSprite::getInstance(surf, 500, 600, 0, true);
	PhysicalSprite* s9 = PhysicalSprite::getInstance(surf, 600, 600, 0, true);
	PhysicalSprite* s10 = PhysicalSprite::getInstance(surf, 700, 600, 0, true);
	PhysicalSprite* s11 = PhysicalSprite::getInstance(surf, 800, 600, 0, true);
	PhysicalSprite* s12 = PhysicalSprite::getInstance(surf, 900, 600, 0, true);
	PhysicalSprite* s13 = PhysicalSprite::getInstance(surf, 100, 600, 0, true);
	PhysicalSprite* s14 = PhysicalSprite::getInstance(surf, 0, 600, 0, true);

	Level* lvl1 = Level::getInstance(lvl2);

	lvl1->add(s1);
	lvl1->add(s2);
	lvl1->add(s3);
	lvl1->add(s4);

	lvl1->add(s5);
	lvl1->add(s6);
	lvl1->add(s7);
	lvl1->add(s8);
	lvl1->add(s9);
	lvl1->add(s10);
	lvl1->add(s11);
	lvl1->add(s12);
	lvl1->add(s13);
	lvl1->add(s14);

	ge.setFirstLevel(lvl1);

	ge.run();

	return 0;
}

