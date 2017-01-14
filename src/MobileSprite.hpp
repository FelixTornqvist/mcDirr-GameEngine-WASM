#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"
#include "ImmobileSprite.hpp"


namespace mcDirr {

	class MobileSprite : virtual public Sprite {

		public:
			static MobileSprite* getInstance(SDL_Surface* surface, int, int, double);
			void draw() const override;
			void tick(int passedMillis) override;
			void virtual checkCollision(ImmobileSprite* other);
			bool pixelCollision(SDL_Rect* tempRect, SDL_Surface* otherSurf);
			bool isAlive() const;
			SDL_Surface* getSurface() const;


		protected:
			MobileSprite(SDL_Surface* s, int x, int y, double temporaryTestSpeed);
			void doPhysics(int millisPassed);
			inline void bounceBack(int& myAxis, int& myPadding, int& othrsAxis, int& othrsPadding);
			float currentTime;

		private:
			SDL_Surface* surface;
			bool alive;

			double bounciness, friction = 0.1;
			double yAccel, xAccel;
			double yVel, xVel;
	};
}

#endif
