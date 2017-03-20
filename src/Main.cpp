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
#include "GUIText.hpp"
#include "GUIScreen.hpp"
#include "GUIButton.hpp"

#define FPS 60
#define W_WIDTH 1024
#define W_HEIGHT 768

using namespace std;
using namespace mcDirr;


GameEngine ge = GameEngine("mcDirr - The gaem", W_WIDTH, W_HEIGHT, FPS);
Level* lvl2 = Level::getInstance(nullptr);
Level* lvl1 = Level::getInstance(lvl2);
GUIScreen* start;
GUIText* text;

class StartGameButton : public GUIButton {
	public:
		StartGameButton(SDL_Surface* bg):
			GUIButton(bg) {
		}

		void mouseClick() override {
			if (sys.isMouseButtonDown(SDL_BUTTON_LEFT)) {

				ge.skipScreen();
			}

		}
	protected:
	private:

};

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

	lvl2 = Level::getInstance(nullptr);

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

	lvl1 = Level::getInstance(lvl2);

	SantaHero* santa = SantaHero::getInstance(santasheet, fireballSheet, 50, 50, 11, 10, hearts);
	santa->setHealth(4);
	santa->showHealth(true);
	SantaHero* santa2 = SantaHero::getInstance(santasheet, fireballSheet, 300, 300, 11, 10, hearts);

	text = GUIText::getInstance(ubuntuB, {0,0,0}, "McDirr - the Gaem!");
	text->setX(100);
	text->setY(100);

	lvl1->add(s2);
	lvl1->add(s3);

	lvl1->add(santa);
	lvl1->add(santa2);

	lvl1->add(s5);
	lvl1->add(s8);
	lvl1->add(lvl1BG);
	lvl1->add(text);


	GUIScreen* start = GUIScreen::getInstance(lvl1);

	GUIText* gameTitle = GUIText::getInstance(ubuntuB, {10,90,5}, "McDirr - The Gaem");
	gameTitle->setY(100);
	gameTitle->setX(W_WIDTH/2 - gameTitle->getWidth() / 2);

	SDL_Surface* startBSurf = loader.loadSurface("media/startButton.png");
	GUIButton* startB = new StartGameButton(startBSurf);
	startB->setY(200);
	startB->setX(W_WIDTH/2 - startB->getWidth()/2);

	start->setBackground(lvl1BGSurf);
	start->add(startB);
	start->add(gameTitle);

	ge.setFirstScreen(start);

	sys.addKeyFunction<GameEngine>(SDLK_l, &ge, &GameEngine::skipScreen);
	sys.addKeyFunction(SDLK_f, &freeFunk);

	ge.run();

	return 0;
}

