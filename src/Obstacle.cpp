#include "Obstacle.hpp"

using namespace mcDirr;

Obstacle* Obstacle::getInstance(SDL_Surface* s, int x, int y, float b) {
	return new Obstacle(s, x, y, b);
}

Obstacle::Obstacle(SDL_Surface* s, int x, int y, float b) : ImmobileSprite(s,x,y,b){
}

void Obstacle::customTick(int timeDiff) {}

Obstacle::~Obstacle(){}
