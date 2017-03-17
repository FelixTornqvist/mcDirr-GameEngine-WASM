#include "System.hpp"
#include "GUIElement.hpp"

using namespace mcDirr;

GUIElement::GUIElement(SDL_Rect dst): dest(dst) {
}

SDL_Rect GUIElement::getDest() {
	return dest;
}

GUIElement::~GUIElement() {
}
