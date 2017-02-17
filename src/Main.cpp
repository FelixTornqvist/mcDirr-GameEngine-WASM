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
#include "InteractionSprite.hpp"
#include "Projectile.hpp"
#include "SantaHero.hpp"
#include "Obstacle.hpp"
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
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, BGmusic, -1);

	SDL_Surface* grass = loader.loadSurface("media/grass.png");
	SDL_Surface* cat = loader.loadSurface("media/tinyCat.png");

	// MobileSprite* s15 = MobileSprite::getInstance(cat, 600, 200);
	// MobileSprite* s16 = MobileSprite::getInstance(cat, 800, 200);
	Obstacle* s17 = Obstacle::getInstance(grass, 400, 600, 0.2);
	Obstacle* s18 = Obstacle::getInstance(grass, -500, 400, 0.2);

	Level* lvl2 = Level::getInstance(nullptr);

	// lvl2->add(s15);
	// lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);


	SDL_Surface* lvl1BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* santasheet = loader.loadSurface("media/santa-sheet.png");
	SDL_Surface* fireballSheet = loader.loadSurface("media/fireball.png");
	SDL_Surface* slime = loader.loadSurface("media/slime.png");

	VisualSprite* lvl1BG = VisualSprite::getInstance(lvl1BGSurf, 0, 0);
	// MobileSprite* s2 = MobileSprite::getInstance(cat, 400, 200);
	// MobileSprite* s3 = MobileSprite::getInstance(cat, 600, 200);

//	AnimatedMobileSprite* s4 = new AnimatedMobileSprite(fireballSheet, 200, 0, 3, 70);
	InteractionSprite* s4 = new Projectile(fireballSheet, 50, 50, 3, 70, -2, false, 0.3, 0);

	Obstacle* s5 = Obstacle::getInstance(grass, 10, 600, 0.2);
	Obstacle* s8 = Obstacle::getInstance(slime, 500, 510, 1.1);

	SantaHero* santa = new SantaHero(santasheet, 50, 50, 11, 10);

	Level* lvl1 = Level::getInstance(lvl2);

	lvl1->add(santa);

	lvl1->add(s4);
	// lvl1->add(s2);
	// lvl1->add(s3);

	lvl1->add(s5);
	lvl1->add(s8);
	lvl1->add(lvl1BG);

	ge.setFirstLevel(lvl1);

	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::skipLevel);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	ge.run();

	return 0;
}

