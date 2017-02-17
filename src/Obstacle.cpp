#include "Obstacle.hpp"

using namespace mcDirr;

Obstacle::Obstacle(SDL_Surface* s, int x, int y, float b) : ImmobileSprite(s,x,y,b){
}

Obstacle::customTick(int timeDiff) {}
