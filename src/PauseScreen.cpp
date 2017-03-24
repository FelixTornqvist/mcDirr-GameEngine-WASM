#include <iostream>
#include <exception>

#include "Loader.hpp"
#include "System.hpp"
#include "PauseScreen.hpp"

#define newB(surf, obj, funk) GUIButton::getInstance(surf, obj, funk)

using namespace mcDirr;

PauseScreen::PauseScreen(GameEngine *_ge):GUIScreen(), ge(_ge) {
	bg = loader.loadSurface("media/pauseBG.png");
	setBackground(bg);

	continueSurf = loader.loadSurface("media/button/continueButton.png");
	exitSurf = loader.loadSurface("media/button/exitButton.png");
	restartSurf = loader.loadSurface("media/button/restartButton.png");
	updateSurf = loader.loadSurface("media/button/updateButton.png");

	font = loader.loadFont("media/Ubuntu-B.ttf", 50);
	title = GUIText::getInstance(font, {0,0,0}, "Paused");

	continueB = newB(continueSurf, this, &PauseScreen::unPause);
	exitB = newB(exitSurf, ge, &GameEngine::stop);
	restartB = newB(restartSurf, this, &PauseScreen::restart);
	updateB = newB(updateSurf, this, &PauseScreen::setFrameRate);

	tfFont = loader.loadFont("media/Ubuntu-B.ttf", 15);
	fpsLabel = GUIText::getInstance(tfFont, {0,0,0}, "FPS:");
	fpsInput = GUITextField::getInstance(tfFont, {0,0,0}, restartB->getWidth());
	fpsInput->setText(std::to_string(ge->getSetFrameRate()));

	add(continueB);
	add(exitB);
	add(restartB);
	add(fpsInput);
	add(updateB);
	add(fpsLabel);
	add(title);

	putOnXMiddle(continueB);
	continueB->setY(200);
	putOnXMiddle(restartB);
	restartB->setY(250);
	putOnXMiddle(exitB);
	exitB->setY(300);
	putOnXMiddle(title);
	title->setY(100);

	putOnXMiddle(fpsInput);
	fpsInput->setY(350);
	fpsInput->setWidth(fpsInput->getWidth() - updateB->getWidth());
	updateB->setX(fpsInput->getX() + fpsInput->getWidth() + 10);
	updateB->setY(fpsInput->getY() - 5);
	fpsLabel->setX(fpsInput->getX() - fpsLabel->getWidth() - 10);
	fpsLabel->setY(fpsInput->getY());
}

void PauseScreen::putOnXMiddle(GUIElement* btn) {
	int w;
	SDL_GetWindowSize(sys.getWin(), &w, nullptr);
	int halfWindow = w / 2;
	btn->setX(halfWindow - btn->getWidth() / 2);

}

void PauseScreen::restart() {
	fpsInput->setFocused(false);
	ge->setScreen(0);
	ge->unPause();
}

void PauseScreen::setFrameRate() {
	try {
		int fps = std::stoi(fpsInput->getText());
		ge->setFrameRate(fps);
	} catch (const std::exception& e) {
		fpsInput->setText("Not a valid FPS!");
	}
	fpsInput->setFocused(false);
}

void PauseScreen::unPause() {
	fpsInput->setFocused(false);
	ge->unPause();
}

PauseScreen::~PauseScreen() {
	SDL_FreeSurface(bg);
	delete continueB;
	delete exitB;
	delete restartB;
	delete updateB;
	delete fpsInput;
	delete fpsLabel;
	delete title;
	delete font;
	delete tfFont;

	SDL_FreeSurface(continueSurf);
	SDL_FreeSurface(exitSurf);
	SDL_FreeSurface(restartSurf);
	SDL_FreeSurface(updateSurf);
}
