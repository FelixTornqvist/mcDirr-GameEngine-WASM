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
	SDL_Surface * surf = loader.loadSurface("media/ball.png");
	SDL_Surface * catSurf = loader.loadSurface("media/cat.bmp");


	// SDL_Texture* catTexture = loader.loadTexture("media/cat.bmp");
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, BGmusic, -1);

	//Sprite* s1 = new AnimatedSprite(texture, 10, 10, 4, 1000);
	//Sprite* s2 = new CustSprite(texture, 300, 250, 0, -1);

	PhysicalSprite* s15 = PhysicalSprite::getInstance(catSurf, 600, 200, 0, true);
	PhysicalSprite* s16 = PhysicalSprite::getInstance(catSurf, 800, 200, 0.5, true);

	PhysicalSprite* s17 = PhysicalSprite::getInstance(catSurf, 400, 600, 0, false);
	PhysicalSprite* s18 = PhysicalSprite::getInstance(catSurf, 500, 600, 0, false);
	PhysicalSprite* s19 = PhysicalSprite::getInstance(catSurf, 600, 600, 0, false);
	PhysicalSprite* s20 = PhysicalSprite::getInstance(catSurf, 700, 600, 0, false);
	PhysicalSprite* s21 = PhysicalSprite::getInstance(catSurf, 800, 600, 0, false);

	Level* lvl2 = Level::getInstance(nullptr);

	lvl2->add(s15);
	lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);
	lvl2->add(s19);
	lvl2->add(s20);
	lvl2->add(s21);


	PhysicalSprite* s1 = PhysicalSprite::getInstance(surf, 400, 200, 0, false); // last int is for speed. 0 cant be moved.
	PhysicalSprite* s2 = PhysicalSprite::getInstance(catSurf, 400, 200, 0, true);
	PhysicalSprite* s3 = PhysicalSprite::getInstance(catSurf, 600, 200, 0, true);
	PhysicalSprite* s4 = PhysicalSprite::getInstance(surf, 600, 200, 0.1, true); // can be moved. Remove last int later. only to test collision.

	PhysicalSprite* s5 = PhysicalSprite::getInstance(catSurf, 200, 600, 0, false);
	PhysicalSprite* s6 = PhysicalSprite::getInstance(catSurf, 300, 600, 0, false);
	PhysicalSprite* s7 = PhysicalSprite::getInstance(catSurf, 400, 600, 0, false);
	PhysicalSprite* s8 = PhysicalSprite::getInstance(catSurf, 500, 600, 0, false);
	PhysicalSprite* s9 = PhysicalSprite::getInstance(catSurf, 600, 600, 0, false);
	PhysicalSprite* s10 = PhysicalSprite::getInstance(catSurf, 700, 600, 0, false);
	PhysicalSprite* s11 = PhysicalSprite::getInstance(catSurf, 800, 600, 0, false);
	PhysicalSprite* s12 = PhysicalSprite::getInstance(catSurf, 900, 600, 0, false);
	PhysicalSprite* s13 = PhysicalSprite::getInstance(catSurf, 100, 600, 0, false);
	PhysicalSprite* s14 = PhysicalSprite::getInstance(catSurf, 0, 600, 0, false);

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

