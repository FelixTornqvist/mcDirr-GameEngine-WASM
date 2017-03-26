#include "System.hpp"
#include "GUIButton.hpp"

#include <iostream>

using namespace mcDirr;

std::shared_ptr<GUIButton> GUIButton::getInstance(SDL_Surface* surf, void (*func)() ) {
	return std::shared_ptr<GUIButton>( new GUIButton(surf, func) );
}

GUIButton::GUIButton(SDL_Surface* surface, std::function<void()> act): GUIElement(surface), action(act) {}

void GUIButton::mouseClick() {
	if (sys.isMouseButtonDown(SDL_BUTTON_LEFT)) {
		action();
	}
}

void GUIButton::tick(int millisPassed) {

}

void GUIButton::customTick(int millisPassed) {

}

GUIButton::~GUIButton() {
}
