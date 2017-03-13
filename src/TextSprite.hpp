#ifndef TEXTSPRITE_HPP
#define TEXTSPRITE_HPP

#include <string>

#include <SDL_ttf.h>

#include "VisualSprite.hpp"

namespace mcDirr {

	class TextSprite : public VisualSprite {
		public:
			TextSprite(TTF_Font* font, SDL_Color colr, std::string txt);
			void customTick(int ) {};

			void setText(std::string txt);
			std::string getText();

			virtual ~TextSprite();

		protected:

		private:
			void updateText();
			std::string text;
			TTF_Font* font;
			SDL_Color color;
			SDL_Surface* surf;
	};

}

#endif // TEXTSPRITE_HPP
