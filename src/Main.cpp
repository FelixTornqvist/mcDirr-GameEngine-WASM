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
#include "GUIText.hpp"
#include "GUIScreen.hpp"
#include "GUIButton.hpp"
#include "GUITextField.hpp"

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
Level *lvl1, *lvl2, *lvl3, *lvl4;
GUIScreen* start;
std::shared_ptr<GUIText> text;
std::shared_ptr<GUITextField> nameInput, nameInput2;
std::shared_ptr<MobileSprite> santa;

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

void startButton() {
	nameInput->setText("");
	nameInput2->setText("");
	nameInput->setFocused(false);
	nameInput2->setFocused(false);
	ge.nextScreen();

	Level* lvl = ge.getLevel();
	if (lvl != nullptr) {
		santa->setX(lvl->getStartX());
		santa->setY(lvl->getStartY());
	}
}

int main(int argc, char** argv) {
	//test code
	Mix_Chunk* BGmusic = loader.loadWAV("media/bgMusic.wav");
	TTF_Font* ubuntuB = loader.loadFont("media/Ubuntu-B.ttf", 50);
	Mix_PlayChannel(-1, BGmusic, -1);

	SDL_Surface* grass = loader.loadSurface("media/grass.png");
	SDL_Surface* cat = loader.loadSurface("media/tinyCat.png");
	SDL_Surface* evilCat = loader.loadSurface("media/extraevilCat.png");
	SDL_Texture* hearts = loader.loadTexture("media/heart.png");

	SDL_Surface* lvl1BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* lvl2BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* lvl3BGSurf = loader.loadSurface("media/level1BG.png");
	SDL_Surface* lvl4BGSurf = loader.loadSurface("media/level1BG.png");

	SDL_Surface* santasheet = loader.loadSurface("media/santa-sheet.png");
	SDL_Surface* fireballSheet = loader.loadSurface("media/fireball.png");
	SDL_Surface* slime = loader.loadSurface("media/slime.png");

	santa = SantaHero::getInstance(santasheet, fireballSheet, 50, 50, 11, 10, hearts, &ge);
	santa->setHealth(4);
	santa->showHealth(true);

	std::shared_ptr<MobileSprite> s15 = EvilCat::getInstance(cat, 600, 200, hearts);
	std::shared_ptr<MobileSprite> s16 = EvilCat::getInstance(cat, 800, 200, hearts);

	std::shared_ptr<ImmobileSprite> s17 = Obstacle::getInstance(grass, 400, 600, 0.2f);
	std::shared_ptr<ImmobileSprite> s18 = Obstacle::getInstance(grass, -500, 400, 0.2f);

	std::shared_ptr<ImmobileSprite> l3o1 = Obstacle::getInstance(grass, -100, 400, 0.2f);

	std::shared_ptr<ImmobileSprite> l4o1 = Obstacle::getInstance(grass, 30, 400, 0.2f);

	lvl1 = Level::getInstance(10, 400, 700, 400);
	lvl2 = Level::getInstance(1, 190, 900, 500);
	lvl3 = Level::getInstance(1, 190, 600, 299);
	lvl4 = Level::getInstance(30, 190, 10, 10);

	lvl3->add(l3o1);

	lvl4->add(l4o1);

	lvl2->add(s15);
	lvl2->add(s16);
	lvl2->add(s17);
	lvl2->add(s18);

	std::shared_ptr<Sprite> lvl1BG = Background::getInstance(lvl1BGSurf, 0, 0);
	std::shared_ptr<Sprite> lvl2BG = Background::getInstance(lvl2BGSurf, 0, 0);
	std::shared_ptr<Sprite> lvl3BG = Background::getInstance(lvl3BGSurf, 0, 0);
	std::shared_ptr<Sprite> lvl4BG = Background::getInstance(lvl4BGSurf, 0, 0);

	lvl1->add(lvl1BG);
	lvl2->add(lvl2BG);
	lvl3->add(lvl3BG);
	lvl4->add(lvl4BG);

	std::shared_ptr<MobileSprite> s2 = EvilCat::getInstance(cat, 200, 100, hearts);
	std::shared_ptr<MobileSprite> s3 = EvilCat::getInstance(cat, 600, 200, hearts);
	std::shared_ptr<MobileSprite> l3ec1 = EvilCat::getInstance(evilCat, 600, 300, hearts);

	l3ec1->setHealth(20);
	l3ec1->showHealth(true);
	//lvl3->add(l3ec1);

	s2->setHealth(40);
	s3->setHealth(40);
	s3->setHealth(8);
	s3->showHealth(true);

	std::shared_ptr<ImmobileSprite> s5 = Obstacle::getInstance(grass, 10, 600, 0.2f);
	std::shared_ptr<ImmobileSprite> s8 = Obstacle::getInstance(slime, 500, 510, 1.1f);

	//SantaHero* santa2 = SantaHero::getInstance(santasheet, fireballSheet, 300, 300, 11, 10, hearts, &ge);

	text = GUIText::getInstance(ubuntuB, {0,0,0}, "McDirr - the Gaem!");
	text->setX(100);
	text->setY(100);

	lvl1->add(s2);
	lvl1->add(s3);

	lvl1->add(santa);
	//lvl1->add(santa2);

	lvl1->add(s5);
	lvl1->add(s8);
	lvl1->add(text);


	GUIScreen* start = GUIScreen::getInstance();

	std::shared_ptr<GUIText> gameTitle = GUIText::getInstance(ubuntuB, {10,90,5}, "McDirr - The Gaem");
	gameTitle->setY(100);
	gameTitle->setX(W_WIDTH/2 - gameTitle->getWidth() / 2);

	SDL_Surface* startBSurf = loader.loadSurface("media/button/startButton.png");
	std::shared_ptr<GUIButton> startB = GUIButton::getInstance(startBSurf, &startButton);
	startB->setY(200);
	startB->setX(W_WIDTH/2 - startB->getWidth()/2);

	TTF_Font* tfFont = loader.loadFont("media/Ubuntu-B.ttf", 15);
	nameInput = GUITextField::getInstance(tfFont, {0,0,0}, 300);
	nameInput->setX(100);
	nameInput->setY(200);
	nameInput2 = GUITextField::getInstance(tfFont, {0,0,0}, 300);
	nameInput2->setX(100);
	nameInput2->setY(250);

	start->setBackground(lvl1BGSurf);
	start->add(startB);
	start->add(gameTitle);
	start->add(nameInput);
	start->add(nameInput2);

	ge.setPauseScreen(new PauseScreen(&ge));
	ge.addScreen(start);
	ge.addScreen(lvl1);
	ge.addScreen(lvl2);
	ge.addScreen(lvl3);
	ge.addScreen(lvl4);


	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::nextScreen);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	ge.run();

	return 0;
}

