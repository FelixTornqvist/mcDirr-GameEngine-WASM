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
			void checkImmobileCollisions(std::list<ImmobileSprite*>& others);
			void checkMobileCollisions(std::list<MobileSprite*>& others);
			bool isAlive() const;
			void kill();
			SDL_Surface* getSurface() const;
			void setHealth(int newHealth);
			void changeHealth(int impact);
			int getTeam();

			void setXVel(double vel);
			void setYVel(double vel);

			virtual ~MobileSprite() {};
		protected:
			MobileSprite(SDL_Surface* s, int x, int y, SDL_Texture* healthSym, int teamNO);

			void virtual handleImmobileCollision(ImmobileSprite* collidedWith, int side);
			void virtual handleMobileCollision(MobileSprite* collidedWith, int side) = 0;
			int checkCollision(Sprite* other) const;

			void doPhysics(int millisPassed);
			virtual void checkBounds();
			void drawHealth() const;


			double yVel, xVel;
			double yAccel, xAccel;
			bool alive;
			bool onGround;
			int health;

		private:
			int teamNO;

			double debounceVel;
			SDL_Surface* surface;
			SDL_Texture* healthSymbol;
	};
}

#endif
