#ifndef TEXTSPRITE_HPP
#define TEXTSPRITE_HPP

#include <string>
#include <memory>

#include <SDL_ttf.h>

#include "GUIElement.hpp"

namespace mcDirr {

	class GUIText : public GUIElement {

		public:
			static std::shared_ptr<GUIText> getInstance(TTF_Font* font, const SDL_Color& colr, std::string txt);

			virtual void tick(int ) {};
			virtual void customTick(int ) {};
			virtual void mouseClick() {};

			void setText(std::string txt);
			std::string getText();
			SDL_Color getColor();
			TTF_Font* getFont();

			virtual ~GUIText();

		protected:
			GUIText(TTF_Font* font, const SDL_Color& colr, std::string txt);
			virtual void updateText();
			std::string text;

		private:
			TTF_Font* font;
			SDL_Color color;
	};
}

#endif // TEXTSPRITE_HPP