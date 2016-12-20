#ifndef PhysicalSprite_hpp
#define PhysicalSprite_hpp

#include "Sprite.hpp"


namespace mcDirr {

	class PhysicalSprite : public Sprite {

		public:
			static PhysicalSprite* getInstance(SDL_Texture* texure, int, int, double);
			void draw() const override;
			void tick(int passedMillis) override;
			bool isAlive() const;
			void checkCollision(PhysicalSprite* other);
		protected:
			PhysicalSprite(SDL_Texture* t, int x, int y, double temporaryTestSpeed);
			float currentTime;
		private:
			double ttSpeed;
			bool alive;

	};
}

#endif
