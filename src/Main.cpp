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
	SDL_Texture* catTexture = loader.loadTexture("media/cat.bmp");
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, BGmusic, -1);

	TTF_Font* font = loader.loadFont("media/Ubuntu-B.ttf", 24);
	Sprite* testText = Sprite::getInstance(loader.loadTexture(TTF_RenderText_Solid(font, "Hello World!", {0,0,0})) , 10 , 10);


	PhysicalSprite* s3 = PhysicalSprite::getInstance(catTexture, 200, 200, 0);
	PhysicalSprite* s4 = PhysicalSprite::getInstance(catTexture, 400, 200, 0);
	PhysicalSprite* s5 = PhysicalSprite::getInstance(catTexture, 600, 200, 0);
	PhysicalSprite* s6 = PhysicalSprite::getInstance(catTexture, 800, 200, 0.5); // can be moved. Remove last int later. only to test collision.

	std::cout << "hej" << endl;

	ge.add(testText);
	ge.add(s3);
	ge.add(s5);
	ge.add(s4);
	ge.add(s6);

	ge.run();

	return 0;
}

