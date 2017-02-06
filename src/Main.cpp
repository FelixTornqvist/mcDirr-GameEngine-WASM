#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <math.h>

#include "Sprite.hpp"
#include "AnimatedSprite.hpp"
#include "AnimatedMobileSprite.hpp"
#include "VisualSprite.hpp"
#include "MobileSprite.hpp"
#include "Level.hpp"
#include "GameEngine.hpp"
#include "System.hpp"
#include "Loader.hpp"

#define FPS 60
#define W_WIDTH 1024
#define W_HEIGHT 768

using namespace std;
using namespace mcDirr;

void freeFunk(){
	cout << "I am a free-range function!" << endl;
}

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", W_WIDTH, W_HEIGHT, FPS);
	SDL_Surface* cat = loader.loadSurface("media/tinyCat.png");

	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, BGmusic, -1);

	MobileSprite* s15 = MobileSprite::getInstance(cat, 600, 200);
	MobileSprite* s16 = MobileSprite::getInstance(cat, 800, 200);
	ImmobileSprite* s17 = ImmobileSprite::getInstance(cat, 400, 600, 0.5);
	ImmobileSprite* s18 = ImmobileSprite::getInstance(cat, 500, 600, 0.5);
	ImmobileSprite* s19 = ImmobileSprite::getInstance(cat, 600, 600, 0.5);
	ImmobileSprite* s20 = ImmobileSprite::getInstance(cat, 700, 600, 0.5);
	ImmobileSprite* s21 = ImmobileSprite::getInstance(cat, 800, 600, 0.5);

	Level* lvl2 = Level::getInstance(nullptr);

	lvl2->add(s15);
	lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);
	lvl2->add(s19);
	lvl2->add(s20);
	lvl2->add(s21);


	SDL_Surface* lvl1BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* santasheet = loader.loadSurface("media/santa-sheet.png");
	SDL_Surface* grass = loader.loadSurface("media/grass.png");
	SDL_Surface* slime = loader.loadSurface("media/slime.png");

	VisualSprite* lvl1BG = VisualSprite::getInstance(lvl1BGSurf, 0, 0);
	MobileSprite* s2 = MobileSprite::getInstance(cat, 400, 200);
	MobileSprite* s3 = MobileSprite::getInstance(cat, 600, 200);

	AnimatedMobileSprite* s4 = new AnimatedMobileSprite(santasheet, 200, 0, 11, 10);

	ImmobileSprite* s5 = ImmobileSprite::getInstance(grass, 10, 600, 0.2);
	ImmobileSprite* s8 = ImmobileSprite::getInstance(slime, 500, 510, 1.1);

	Level* lvl1 = Level::getInstance(lvl2);

	lvl1->add(s4);
	lvl1->add(s2);
	lvl1->add(s3);

	lvl1->add(s5);
	lvl1->add(s8);
	lvl1->add(lvl1BG);

	ge.setFirstLevel(lvl1);

	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::skipLevel);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	ge.run();

	return 0;
}

