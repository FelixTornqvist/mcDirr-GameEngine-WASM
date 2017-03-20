#include <SDL.h>
#include <iostream>

#include "GUIScreen.hpp"
#include "System.hpp"
#include "Loader.hpp"

using namespace mcDirr;

GUIScreen* GUIScreen::getInstance(Screen* nxt) {
	return new GUIScreen(nxt);
}

GUIScreen::GUIScreen(Screen* next) {
	nextScreen = next;
}

void GUIScreen::tick(int millisPassed) {
	if (sys.haveMouseButtonsChanged()) {
		for (GUIElement* ele: guiElements) {
			ele->tick(millisPassed);

			if (pointInRect(sys.getMouseX(), sys.getMouseY(), *ele->getDestRect())) {
				ele->mouseClick();
				break;
			}
		}
	} else {
		for (GUIElement* ele: guiElements) {
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
	for (GUIElement* ele : guiElements) {
		ele->draw();
	}
}

void GUIScreen::add(GUIElement* element) {
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
