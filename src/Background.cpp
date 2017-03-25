#include "Background.hpp"

using namespace mcDirr;

std::shared_ptr<Background> Background::getInstance(SDL_Surface* s, int x, int y){
	return std::shared_ptr<Background>( new Background(s, x, y) );
}

Background::Background(SDL_Surface* s, int x, int y): VisualSprite(s, x, y) {
}


void Background::customTick(int timeDiff) {
	//nothing, could be used for a moving sun for example
}

Background::~Background() {
}
