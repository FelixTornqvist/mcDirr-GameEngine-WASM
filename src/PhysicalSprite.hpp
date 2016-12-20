#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"


namespace mcDirr {

	class PhysicalSprite : public Sprite {

		public:
			static PhysicalSprite* getInstance(SDL_Surface* surface, int, int, double);
			void draw() const override;
			void tick(int passedMillis) override;
			bool isAlive() const;
			void checkCollision(PhysicalSprite* other);
		protected:
			PhysicalSprite(SDL_Surface* s, int x, int y, double temporaryTestSpeed);
			void gravity();
			float currentTime;
		private:
			double ttSpeed;
			bool alive;
			bool affectedByGravity;
			bool solidGround;
			double fallingSpeed;

	};
}

#endif
