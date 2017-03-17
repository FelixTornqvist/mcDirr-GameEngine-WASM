#include "System.hpp"
#include "GUIButton.hpp"

#include <iostream>

using namespace mcDirr;

GUIButton::GUIButton(TTF_Font* fnt, SDL_Color colour, std::string labl, SDL_Rect dest): GUIElement(dest), label(labl) {
}

void GUIButton::draw() {
	if (clickTest) {
		SDL_RenderFillRect(sys.getRen(), &dest);
	} else {
		SDL_RenderDrawRect(sys.getRen(), &dest);
	}
}

void GUIButton::tick(int millisPassed) {

}

GUIButton::~GUIButton() {
}
