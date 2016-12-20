#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "sprite/Sprite.hpp"


namespace mcDirr {

    class PhysicalSprite : public Sprite {

    public:
		 static PhysicalSprite* getInstance(SDL_Texture* texure, int, int, int);
         void draw() const override;
         void tick(int passedMillis) override;
		 bool isAlive() const;
    protected:
		PhysicalSprite::PhysicalSprite(SDL_Texture* t, int x, int y, int temporaryTestSpeed) : Sprite(t, x, y)
		{
			currentTime = 0;
			ttSpeed = temporaryTestSpeed; // temporary just so that collision could be tested 
			alive = (true);
		}
        float currentTime;
	private:
		int ttSpeed;
		bool alive;

    };
}

#endif
