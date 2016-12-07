#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"


namespace mcDirr {

    class PhysicalSprite : public Sprite {

    public:
         PhysicalSprite(SDL_Texture* texure, int, int);
         void draw() const override;
         void tick(int passedMillis) override;

    protected:
        float currentTime;

    };
}

#endif
