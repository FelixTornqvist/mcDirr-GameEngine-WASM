#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"
#include "ImmobileSprite.hpp"

#include <list>
#include <stack>


namespace mcDirr {
	class MobileSprite : virtual public Sprite {

		public:
			void draw() const override;
			void tick(int passedMillis) override;
			void checkImmobileCollisions(std::list<ImmobileSprite*>& others);
			void checkMobileCollisions(std::list<MobileSprite*>& others);
			bool isAlive() const;
			SDL_Surface* getSurface() const;

			int getTeam();
			virtual void kill();
			void showHealth(bool onOff);
			void setHealth(int newHealth);
			void changeHealth(int impact);

			void setXVel(double vel);
			void setYVel(double vel);
			void setXAccel(double acc);
			void setYAccel(double acc);

			void setSpriteOutbox(std::stack<MobileSprite*>* ptr);
			std::stack<MobileSprite*>* getSpriteOutbox() const;

			virtual ~MobileSprite() {};
		protected:
			MobileSprite(SDL_Surface* s, int x, int y, SDL_Texture* healthSym, int teamNO);

			void virtual handleImmobileCollision(ImmobileSprite* collidedWith, int side);
			void virtual handleMobileCollision(MobileSprite* collidedWith, int side) = 0;
			int checkCollisionForMobile(MobileSprite* other) const;
			bool isPixelColored(MobileSprite* other, int x, int y) const;
			int checkCollision(Sprite* other) const;

			void doPhysics(int millisPassed);
			virtual void checkBounds();
			virtual void drawHealth() const;


			double yVel, xVel;
			double yAccel, xAccel;
			bool alive;
			bool onGround;
			bool renderHealth = false;
			int health;
			SDL_Texture* healthSymbol;

		private:
			std::stack<MobileSprite*>* spriteOutbox;
			int teamNO;

			double debounceVel;
			SDL_Surface* surface;
	};
}

#endif
