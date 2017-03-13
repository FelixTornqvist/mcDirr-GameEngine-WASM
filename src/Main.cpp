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
#include "Projectile.hpp"
#include "SantaHero.hpp"
#include "Obstacle.hpp"
#include "EvilCat.hpp"
#include "Level.hpp"
#include "GameEngine.hpp"
#include "System.hpp"
#include "Loader.hpp"
#include "Background.hpp"
#include "TextSprite.hpp"

#define FPS 60
#define W_WIDTH 1024
#define W_HEIGHT 768

using namespace std;
using namespace mcDirr;


TextSprite* text;
void freeFunk() {
	static bool funkyState;
	cout << "I am a free-range function!" << endl;
	if(funkyState) {
		text->setText("Yes indeed,");
	} else {
		text->setText("I am a free-range function!");
	}
	funkyState = !funkyState;
}

int main(int argc, char** argv) {
	//test code
	GameEngine ge = GameEngine("mcDirr - The gaem", W_WIDTH, W_HEIGHT, FPS);
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	TTF_Font* ubuntuB = loader.loadFont("media/Ubuntu-B.ttf", 50);
	Mix_PlayChannel(-1, BGmusic, -1);

	SDL_Surface* grass = loader.loadSurface("media/grass.png");
	SDL_Surface* cat = loader.loadSurface("media/tinyCat.png");
	SDL_Texture* hearts = loader.loadTexture("media/heart.png");

	EvilCat* s15 = EvilCat::getInstance(cat, 600, 200, hearts);
	EvilCat* s16 = EvilCat::getInstance(cat, 800, 200, hearts);
	Obstacle* s17 = Obstacle::getInstance(grass, 400, 600, 0.2);
	Obstacle* s18 = Obstacle::getInstance(grass, -500, 400, 0.2);

	Level* lvl2 = Level::getInstance(nullptr);

	lvl2->add(s15);
	lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);


	SDL_Surface* lvl1BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* santasheet = loader.loadSurface("media/santa-sheet.png");
	SDL_Surface* fireballSheet = loader.loadSurface("media/fireball.png");
	SDL_Surface* slime = loader.loadSurface("media/slime.png");

	VisualSprite* lvl1BG = Background::getInstance(lvl1BGSurf, 0, 0);
	EvilCat* s2 = EvilCat::getInstance(cat, 200, 100, hearts);
	EvilCat* s3 = EvilCat::getInstance(cat, 600, 200, hearts);
	s3->setHealth(8);
	s3->showHealth(true);

	Obstacle* s5 = Obstacle::getInstance(grass, 10, 600, 0.2);
	Obstacle* s8 = Obstacle::getInstance(slime, 500, 510, 1.1);

	Level* lvl1 = Level::getInstance(lvl2);

	SantaHero* santa = SantaHero::getInstance(santasheet, fireballSheet, 50, 50, 11, 10, hearts);
	santa->setHealth(4);
	santa->showHealth(true);
	SantaHero* santa2 = SantaHero::getInstance(santasheet, fireballSheet, 300, 300, 11, 10, hearts);

	text = new TextSprite(ubuntuB, {0,0,0}, "McDirr - the Gaem!");
	SDL_Rect* dst = text->getDestRect();
	dst->x = 100;
	dst->y = 100;

	lvl1->add(s2);
	lvl1->add(s3);

	lvl1->add(santa);
	lvl1->add(santa2);

	lvl1->add(s5);
	lvl1->add(s8);
	lvl1->add(lvl1BG);
	lvl1->add(text);

	ge.setFirstLevel(lvl1);

	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::skipLevel);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	ge.run();

	return 0;
}

