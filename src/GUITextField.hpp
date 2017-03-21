#ifndef GUITEXTFIELD_HPP
#define GUITEXTFIELD_HPP

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "GUIText.hpp"

namespace mcDirr {
	class GUITextField : public GUIText {
		public:
			static GUITextField* getInstance(TTF_Font* font, const SDL_Color& color, int width);

			virtual void draw() const override;
			virtual void tick(int ) override;
			virtual void mouseClick() override;

			virtual ~GUITextField();

		protected:
			GUITextField(TTF_Font* font, const SDL_Color& color, int width);
			void updateText() override;

		private:
			bool focus = false;
			SDL_Rect textDest;
	};
}

#endif // GUITEXTFIELD_HPP
