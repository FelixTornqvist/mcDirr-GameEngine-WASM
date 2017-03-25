#include "Obstacle.hpp"

using namespace mcDirr;

std::shared_ptr<Obstacle> Obstacle::getInstance(SDL_Surface* s, int x, int y, float b) {
	return std::shared_ptr<Obstacle>( new Obstacle(s, x, y, b) );
}

Obstacle::Obstacle(SDL_Surface* s, int x, int y, float b) : ImmobileSprite(s,x,y,b){
}

void Obstacle::customTick(int timeDiff) {}

Obstacle::~Obstacle(){}
