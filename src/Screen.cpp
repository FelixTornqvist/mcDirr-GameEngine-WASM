#include "Screen.hpp"

using namespace mcDirr;

Screen::Screen() {
}

bool Screen::isFinished() {
	return finished;
}

Screen* Screen::getNextScreen() {
	return nextScreen;
}


Screen::~Screen() {
	delete nextScreen;
}
