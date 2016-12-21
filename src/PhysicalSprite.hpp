#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"


namespace mcDirr {

	class PhysicalSprite : public Sprite {

		public:
			static PhysicalSprite* getInstance(SDL_Surface* surface, int, int, double, bool);
			void draw() const override;
			void tick(int passedMillis) override;
			bool isAlive() const;
			void checkCollision(PhysicalSprite* other);
			bool pixelCollision(SDL_Rect* tempRect, SDL_Surface* otherSurf);
			SDL_Surface* getSurface() const;

		protected:
			PhysicalSprite(SDL_Surface* s, int x, int y, double temporaryTestSpeed, bool affectedByGravity);
			void doPhysics(int millisPassed);
			inline void bounceBack(int& myAxis, int& myPadding, int& othrsAxis, int& othrsPadding);
			float currentTime;

		private:
			SDL_Surface* surface;
			bool alive;
			bool solid;

			double bounciness;
			double yAccel, xAccel;
			double yVel, xVel;

	};
}

#endif
