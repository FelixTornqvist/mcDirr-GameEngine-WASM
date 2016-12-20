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
	PhysicalSprite* s1 = PhysicalSprite::getInstance(surf, 200, 200, 0); // last int is for speed. 0 cant be moved.
	PhysicalSprite* s2 = PhysicalSprite::getInstance(surf, 400, 200, 0);
	PhysicalSprite* s3 = PhysicalSprite::getInstance(surf, 600, 200, 0);
	PhysicalSprite* s4 = PhysicalSprite::getInstance(surf, 800, 200, 0.5); // can be moved. Remove last int later. only to test collision.

	std::cout << "hej" << endl;

	ge.add(s1);
	ge.add(s2);
	ge.add(s3);
	ge.add(s4);

	ge.run();

	return 0;
}

