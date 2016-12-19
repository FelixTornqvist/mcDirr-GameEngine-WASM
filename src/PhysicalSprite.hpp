#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "sprite/Sprite.hpp"


namespace mcDirr {

    class PhysicalSprite : public Sprite {

    public:
         PhysicalSprite(SDL_Texture* texure, int, int);
         void draw() const override;
         void tick(int passedMillis) override;
		 bool isAlive() const;
    protected:
        float currentTime;
	private:
		bool alive;

    };
}

#endif