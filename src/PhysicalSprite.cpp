#ifdef __APPLE__
#include <SDL2/SDL.h>

#else
#include <SDL.h>
#endif

#include "PhysicalSprite.hpp"
#include "System.hpp"



using namespace mcDirr;

PhysicalSprite::PhysicalSprite(SDL_Texture* t, int x, int y): Sprite(t, x, y)
{ currentTime = 0;}

        
void PhysicalSprite::draw() const override {
    SDL_RenderCopyEx(sys.getRen(), texture, NULL, &dest, currentTime, NULL, SDL_FLIP_NONE);
}

void PhysicalSprite::tick(int time) override {
    currentTime += time;
    dest.x ++;
    dest.y ++;
}

//Sprite::~Sprite() {
//    SDL_DestroyTexture(texture);
//}
