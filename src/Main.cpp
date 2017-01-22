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

using namespace std;
using namespace mcDirr;

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);
	SDL_Surface* cat = loader.loadSurface("media/cat.bmp");

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


	ImmobileSprite* s1 = ImmobileSprite::getInstance(cat, 200, 200, 0.5);
	MobileSprite* s2 = MobileSprite::getInstance(cat, 400, 200);
	MobileSprite* s3 = MobileSprite::getInstance(cat, 600, 200);

	AnimatedMobileSprite* s4 = new AnimatedMobileSprite(loader.loadSurface("media/gubbe spritesheet.png"), 200, 0, 2, 1050);

	ImmobileSprite* s5 = ImmobileSprite::getInstance(cat, 200, 600, 0.5);
	ImmobileSprite* s6 = ImmobileSprite::getInstance(cat, 300, 600, 0.5);
	ImmobileSprite* s7 = ImmobileSprite::getInstance(cat, 400, 600, 0.5);
	ImmobileSprite* s8 = ImmobileSprite::getInstance(loader.loadSurface("media/greencat.png"), 500, 600, 1.1);
	ImmobileSprite* s9 = ImmobileSprite::getInstance(cat, 600, 600, 0.5);
	ImmobileSprite* s10 = ImmobileSprite::getInstance(cat, 700, 600, 0.5);
	ImmobileSprite* s11 = ImmobileSprite::getInstance(cat, 800, 600, 0.5);
	ImmobileSprite* s12 = ImmobileSprite::getInstance(cat, 900, 600, 0.5);
	ImmobileSprite* s13 = ImmobileSprite::getInstance(cat, 100, 600, 0.5);
	ImmobileSprite* s14 = ImmobileSprite::getInstance(cat, 0, 600, 0.5);

	Level* lvl1 = Level::getInstance(lvl2);

	lvl1->add(s4);
	lvl1->add(s1);
	lvl1->add(s2);
	lvl1->add(s3);

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

