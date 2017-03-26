#include <SDL.h>

#include "GUIScreen.hpp"
#include "System.hpp"
#include "Loader.hpp"

using namespace mcDirr;

GUIScreen* GUIScreen::getInstance() {
	return new GUIScreen();
}


void GUIScreen::tick(int millisPassed) {
	if (sys.haveMouseButtonsChanged()) {
		for (std::shared_ptr<GUIElement> ele: guiElements) {
			ele->tick(millisPassed);

			if (pointInRect(sys.getMouseX(), sys.getMouseY(), *ele->getDestRect())) {
				ele->mouseClick();
				break;
			}
		}
	} else {
		for (std::shared_ptr<GUIElement> ele: guiElements) {
			ele->tick(millisPassed);
		}
	}
}

bool GUIScreen::pointInRect(Sint32 px, Sint32 py, SDL_Rect rect) {
	int rxMin = rect.x;
	int rxMax = rxMin + rect.w;

	int ryMin = rect.y;
	int ryMax = ryMin + rect.h;

	return px < rxMax && px > rxMin && py < ryMax && py > ryMin;
}


void GUIScreen::draw() {
	if (background)
		SDL_RenderCopy(sys.getRen(), background, NULL, NULL);
	for (std::shared_ptr<GUIElement> ele : guiElements) {
		ele->draw();
	}
}

void GUIScreen::add(std::shared_ptr<GUIElement> element) {
	guiElements.push_back(element);
}

void GUIScreen::setBackground(SDL_Surface* bg) {
	if (background)
		SDL_DestroyTexture(background);
	background = loader.loadTexture(bg);
}

GUIScreen::~GUIScreen() {
	if (background)
		SDL_DestroyTexture(background);
}
