#include <SDL.h>
#include <iostream>

#include "GUIScreen.hpp"
#include "System.hpp"

using namespace mcDirr;

GUIScreen::GUIScreen(Screen* next) {
	nextScreen = next;
}

void GUIScreen::tick(int millisPassed) {
	if (sys.haveMouseButtonsChanged()) {
		for (GUIElement* ele: guiElements) {
			ele->tick(millisPassed);

			if (pointInRect(sys.getMouseX(), sys.getMouseY(), ele->getDest())) {
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
	for (GUIElement* ele : guiElements) {
		ele->draw();
	}
}

void GUIScreen::add(GUIElement* element) {
	guiElements.push_back(element);
}


GUIScreen::~GUIScreen() {
}
