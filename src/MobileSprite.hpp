#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"
#include "ImmobileSprite.hpp"

#include <list>


namespace mcDirr {

	class MobileSprite : virtual public Sprite {

		public:
			void draw() const override;
			void tick(int passedMillis) override;
			void checkCollisions(std::list<ImmobileSprite*>& others);
			bool isAlive() const;
			void kill();
			SDL_Surface* getSurface() const;
			virtual ~MobileSprite() {};
			void setHealth(int newHealth);
			void changeHealth(int impact);

		protected:
			MobileSprite(SDL_Surface* s, int x, int y, SDL_Texture* healthSym);
			int checkCollision(Sprite* other) const;
			void virtual handleCollision(ImmobileSprite* collidedWith, int side);
			void doPhysics(int millisPassed);
			void drawHealth() const;

			virtual void checkBounds();
			float currentTime;
			double yVel, xVel;
			double yAccel, xAccel;
			bool alive;
			bool onGround;
			int health;

		private:
			double debounceVel;
			SDL_Surface* surface;
			SDL_Texture* healthSymbol;
	};
}

#endif
