#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// Game engine
#include "Sprite.hpp"
#include "AnimatedSprite.hpp"
#include "AnimatedMobileSprite.hpp"
#include "VisualSprite.hpp"
#include "MobileSprite.hpp"
#include "Level.hpp"
#include "GameEngine.hpp"
#include "System.hpp"
#include "Loader.hpp"
#include "GUIText.hpp"
#include "GUIScreen.hpp"
#include "GUIButton.hpp"
#include "GUITextField.hpp"

// Game implementation
#include "SantaHero.hpp"
#include "Obstacle.hpp"
#include "Background.hpp"
#include "EvilCat.hpp"
#include "Projectile.hpp"
#include "PauseScreen.hpp"

#define FPS 60
#define W_WIDTH 1024
#define W_HEIGHT 768

using namespace std;
using namespace mcDirr;


GameEngine ge = GameEngine("mcDirr - The gaem", W_WIDTH, W_HEIGHT, FPS);
GUIScreen* start;
Level *lvl1, *lvl2, *lvl3, *lvl4;

Mix_Chunk *BGmusic;
TTF_Font *ubuntuB, *tfFont;
SDL_Texture *hearts;
SDL_Surface *grass, *deadgrass, *spacegrass, *slime, *cat, *evilCat, *santasheet, *fireballSheet, *startBSurf, *treeSurf;
SDL_Surface *lvl1BGSurf, *lvl2BGSurf, *lvl3BGSurf, *lvl4BGSurf;

std::shared_ptr<GUIText> l1FuncText, startTitle;
std::shared_ptr<GUITextField> startNameInput;
std::shared_ptr<GUIButton> startB;
std::shared_ptr<Sprite> lvl1BG, lvl2BG, lvl3BG, lvl4BG;
std::shared_ptr<MobileSprite> santa, l1Cat1, l1Cat2, l3BossCat1, l2Cat1, l2Cat2;
std::shared_ptr<ImmobileSprite> l1Obst1, l1Obst2, l2Obst1, l2Obst2, l3Obst1, l4Obst1, l4Tree1;


void freeFunk() {
	static bool funkyState;
	cout << "I am a free-range function!" << endl;
	if(funkyState) {
		l1FuncText->setText("Yes indeed,");
	} else {
		l1FuncText->setText("I am a free-range function!");
	}
	funkyState = !funkyState;
}

void startButton() {
	startNameInput->setText("");
	startNameInput->setFocused(false);
	ge.nextScreen();

	Level* lvl = ge.getLevel();
	if (lvl != nullptr) {
		santa->setX(lvl->getStartX());
		santa->setY(lvl->getStartY());
	}
}

void loadMedia() {
	BGmusic = loader.loadWAV("media/bgMusic.wav");
	ubuntuB = loader.loadFont("media/Ubuntu-B.ttf", 50);
	tfFont = loader.loadFont("media/Ubuntu-B.ttf", 15);

	grass = loader.loadSurface("media/grass.png");
	deadgrass = loader.loadSurface("media/deadgrass.png");
	spacegrass = loader.loadSurface("media/spacegrass.png");
	slime = loader.loadSurface("media/slime.png");
	cat = loader.loadSurface("media/tinyCat.png");
	evilCat = loader.loadSurface("media/extraevilCat.png");
	hearts = loader.loadTexture("media/heart.png");
	treeSurf = loader.loadSurface("media/pepperTree.png");

	lvl1BGSurf = loader.loadSurface("media/level1BG.png");
	lvl2BGSurf = loader.loadSurface("media/level2BG.png");
	lvl3BGSurf = loader.loadSurface("media/level3BG.png");
	lvl4BGSurf = loader.loadSurface("media/level4BG.png");

	santasheet = loader.loadSurface("media/santa-sheet.png");
	fireballSheet = loader.loadSurface("media/fireball.png");
	startBSurf = loader.loadSurface("media/button/startButton.png");

}

inline void add(Level* lvl, std::shared_ptr<MobileSprite> sprite) {
	if(!lvl->exists(sprite)) {
		sprite->setAlive(true);
		lvl->add(sprite);
	}
}

inline void setXY(std::shared_ptr<MobileSprite> sprite, int x, int y) {
	sprite->setX(x);
	sprite->setY(y);
}

inline void zeroVel(std::shared_ptr<MobileSprite> sprite) {
	sprite->setXVel(0);
	sprite->setYVel(0);
}

void reset() {
	// --level1--
	add(lvl1, santa);
	lvl1->setSpriteOutBox(santa.get());
	santa->setHealth(4);
	santa->showHealth(true);
	setXY(santa, lvl1->getStartX(), lvl1->getStartY());
	zeroVel(santa);

	add(lvl1, l1Cat1);
	l1Cat1->setHealth(40);
	setXY(l1Cat1, 200, 100);
	zeroVel(l1Cat1);

	add(lvl1, l1Cat2);
	l1Cat2->setHealth(2);
	l1Cat2->showHealth(true);
	setXY(l1Cat2, 600, 200);
	zeroVel(l1Cat2);

	// --level2--
	add(lvl2, l2Cat1);
	setXY(l2Cat1, 600, 200);
	zeroVel(l2Cat1);

	add(lvl2, l2Cat2);
	setXY(l2Cat2, 800, 200);
	zeroVel(l2Cat2);


	// --level3--
	add(lvl3, l3BossCat1);
	l3BossCat1->setHealth(20);
	l3BossCat1->showHealth(true);
	setXY(l3BossCat1, 500, 300);
	zeroVel(l3BossCat1);
}

void makeObjects() {

	// --start screen--
	start = GUIScreen::getInstance();
	startB = GUIButton::getInstance(startBSurf, &startButton);
	startTitle = GUIText::getInstance(ubuntuB, {10,90,5}, "McDirr - The Gaem");
	startNameInput = GUITextField::getInstance(tfFont, {0,0,0}, 300);



	/** -- LEVELS -- **/
	santa = SantaHero::getInstance(santasheet, fireballSheet, hearts, &ge, &reset);

	// --level 1--
	lvl1 = Level::getInstance(10, 400, 700, 400);
	lvl1BG = Background::getInstance(lvl1BGSurf, 0, 0);
	l1Cat1 = EvilCat::getInstance(cat, hearts);
	l1Cat2 = EvilCat::getInstance(cat, hearts);
	l1Obst1 = Obstacle::getInstance(grass, 10, 600, 0.2f);
	l1Obst2 = Obstacle::getInstance(slime, 500, 510, 1.1f);
	l1FuncText = GUIText::getInstance(ubuntuB, {0,0,0}, "McDirr - the Gaem!");


	// --level 2--
	lvl2 = Level::getInstance(1,190,900,500);
	lvl2BG = Background::getInstance(lvl2BGSurf, 0, 0);
	l2Cat1 = EvilCat::getInstance(cat, hearts);
	l2Cat2 = EvilCat::getInstance(cat, hearts);
	l2Obst1 = Obstacle::getInstance(grass, 400, 600, 0.2f);
	l2Obst2 = Obstacle::getInstance(grass, -500, 400, 0.2f);



	// --level 3--
	lvl3 = Level::getInstance(1,190,600,299);
	lvl3BG = Background::getInstance(lvl3BGSurf, 0, 0);
	l3Obst1 = Obstacle::getInstance(deadgrass, -100, 400, 0.2f);
	l3BossCat1 = EvilCat::getInstance(evilCat, hearts);



	// --level 4--
	lvl4 = Level::getInstance(30, 399, 10, 10);
	lvl4BG = Background::getInstance(lvl4BGSurf, 0, 0);
	l4Obst1 = Obstacle::getInstance(spacegrass, 30, 600, 0.2f);
	l4Tree1 = Obstacle::getInstance(treeSurf, 600, 300, 0.1f);

}

void addStaticObjects() {
	// --start screen--
	start->setBackground(lvl1BGSurf);
	start->add(startTitle);
	start->add(startNameInput);
	start->add(startB);

	startTitle->setY(100);
	startTitle->setX(W_WIDTH/2 - startTitle->getWidth() / 2);
	startB->setY(200);
	startB->setX(W_WIDTH/2 - startB->getWidth()/2);

	startNameInput->setX(100);
	startNameInput->setY(200);


	// --level1--
	lvl1->add(lvl1BG);
	lvl1->add(l1FuncText);
	lvl1->add(l1Obst1);
	lvl1->add(l1Obst2);
	l1FuncText->setX(100);
	l1FuncText->setY(100);


	// --level2--
	lvl2->add(lvl2BG);
	lvl2->add(l2Obst1);
	lvl2->add(l2Obst2);


	// --level3--
	lvl3->add(lvl3BG);
	lvl3->add(l3Obst1);


	// --level4--
	lvl4->add(lvl4BG);
	lvl4->add(l4Obst1);
	lvl4->add(l4Tree1);
}

int main(int argc, char** argv) {
	loadMedia();
	makeObjects();
	addStaticObjects();
	reset();

	ge.setPauseScreen(new PauseScreen(&ge, &reset));
	ge.addScreen(start);
	ge.addScreen(lvl1);
	ge.addScreen(lvl2);
	ge.addScreen(lvl3);
	ge.addScreen(lvl4);

	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::nextScreen);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	Mix_PlayChannel(-1, BGmusic, -1);
	ge.run();

	return 0;
}

