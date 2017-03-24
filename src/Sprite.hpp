#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

namespace mcDirr {
	class Sprite {
		public:
			virtual void draw() const;
			virtual void tick(int timediff) = 0;

			SDL_Texture* getTexture() const;
			SDL_Rect* getDestRect();

			int getX() const;
			int getY() const;
			virtual void setX(int x);
			virtual void setY(int y);

			int getWidth() const;
			int getHeight() const;
			virtual void setWidth(int w);
			virtual void setHeight(int h);

			virtual ~Sprite();

		protected:
			Sprite(SDL_Surface* surf, int x, int y);
			SDL_Rect dest;
			SDL_Texture* texture;

			virtual void customTick(int timeDiff) = 0;
			friend class Level;


		private:
			const Sprite& operator=(const Sprite& rhs) = delete;
			Sprite(const Sprite& other) = delete;


	};
}

#endif // Sprite_H
