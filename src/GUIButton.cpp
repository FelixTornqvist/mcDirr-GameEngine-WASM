#include "System.hpp"
#include "GUIButton.hpp"

#include <iostream>

using namespace mcDirr;

GUIButton::GUIButton(SDL_Surface* surface, int x, int y): GUIElement(surface,x,y) {

}

void GUIButton::tick(int millisPassed) {

}

void GUIButton::customTick(int millisPassed) {

}

GUIButton::~GUIButton() {
}
