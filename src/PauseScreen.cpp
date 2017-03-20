#include "Loader.hpp"
#include "System.hpp"
#include "PauseScreen.hpp"

#define newB(surf, obj, funk) GUIButton::getInstance(surf, obj, funk)

using namespace mcDirr;

PauseScreen::PauseScreen(GameEngine *_ge):GUIScreen(), ge(_ge){
	bg = loader.loadSurface("media/pauseBG.png");
	setBackground(bg);

	continueSurf = loader.loadSurface("media/continueButton.png");
	exitSurf = loader.loadSurface("media/exitButton.png");
	restartSurf = loader.loadSurface("media/restartButton.png");
    font = loader.loadFont("media/Ubuntu-B.ttf", 50);
    title = GUIText::getInstance(font, {0,0,0}, "Paused");

    continueB = newB(continueSurf, ge, &GameEngine::unPause);
    exitB = newB(exitSurf, ge, &GameEngine::stop);
    restartB = newB(restartSurf, this, &PauseScreen::restart);

    add(continueB);
    add(exitB);
    add(restartB);
    add(title);

    putOnXMiddle(continueB);
    continueB->setY(200);
    putOnXMiddle(restartB);
    restartB->setY(250);
    putOnXMiddle(exitB);
    exitB->setY(300);
    putOnXMiddle(title);
    title->setY(100);
}

void PauseScreen::putOnXMiddle(GUIElement* btn) {
	int w;
    SDL_GetWindowSize(sys.getWin(), &w, nullptr);
    int halfWindow = w / 2;
	btn->setX(halfWindow - btn->getWidth() / 2);
}

void PauseScreen::restart() {
	ge->setScreen(0);
	ge->unPause();
}

PauseScreen::~PauseScreen() {
	SDL_FreeSurface(bg);
	delete continueB;
	delete exitB;
	delete restartB;
	delete title;
	delete font;

	SDL_FreeSurface(continueSurf);
	SDL_FreeSurface(exitSurf);
	SDL_FreeSurface(restartSurf);
}
