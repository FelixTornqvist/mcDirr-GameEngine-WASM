#include "System.hpp"
#include "GUIElement.hpp"

using namespace mcDirr;

GUIElement::GUIElement(SDL_Surface* surf): Sprite(surf, 0, 0) {
}

GUIElement::~GUIElement() {
}
