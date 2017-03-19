#include "System.hpp"
#include "GUIElement.hpp"

using namespace mcDirr;

GUIElement::GUIElement(SDL_Surface* surf, int x, int y): Sprite(surf, x, y) {
}

GUIElement::~GUIElement() {
}
