#ifndef TEXTSPRITE_HPP
#define TEXTSPRITE_HPP

#include <string>

#include <SDL_ttf.h>

#include "GUIElement.hpp"

namespace mcDirr {

	class GUIText : public GUIElement {
		public:
			static GUIText* getInstance(TTF_Font* font, SDL_Color colr, std::string txt);

			void tick(int ) {};
			void customTick(int ) {};
			void mouseClick() {};

			void setText(std::string txt);
			std::string getText();

			virtual ~GUIText();

		protected:
			GUIText(TTF_Font* font, SDL_Color colr, std::string txt);

		private:
			void updateText();
			std::string text;
			TTF_Font* font;
			SDL_Color color;
			SDL_Surface* surf;
	};

}

#endif // TEXTSPRITE_HPP
