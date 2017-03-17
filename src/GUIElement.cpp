#include "System.hpp"
#include "GUIElement.hpp"

using namespace mcDirr;

GUIElement::GUIElement(SDL_Rect dst): dest(dst) {
}

void GUIElement::draw() {
	if (clickTest) {
		SDL_RenderFillRect(sys.getRen(), &dest);
	} else {
		SDL_RenderDrawRect(sys.getRen(), &dest);
	}
}

void GUIElement::tick(int millisPassed) {

}

void GUIElement::mouseClick() {
	if (sys.isMouseButtonDown(SDL_BUTTON_LEFT))
		clickTest = !clickTest;
}

SDL_Rect GUIElement::getDest() {
	return dest;
}

GUIElement::~GUIElement() {
}
