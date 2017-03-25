#include "GUIText.hpp"
#include "Loader.hpp"

namespace mcDirr {

	std::shared_ptr<GUIText> GUIText::getInstance(TTF_Font* font, const SDL_Color& colr, std::string txt) {
		return std::shared_ptr<GUIText>( new GUIText(font, colr, txt) );
	}

	GUIText::GUIText(TTF_Font* fnt, const SDL_Color& colour, std::string txt):
		GUIElement(nullptr),text(txt), font(fnt), color(colour) {
		updateText();
	}

	void GUIText::setText(std::string txt) {
		SDL_DestroyTexture(texture);
		text = txt;
		updateText();
	}

	void GUIText::updateText() {
		SDL_Surface* surf = TTF_RenderUTF8_Solid(font, text.c_str(), color);
		SDL_DestroyTexture(texture);
		texture = loader.loadTexture(surf);
		SDL_FreeSurface(surf);

		int width;
		int height;
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		dest.h = height;
		dest.w = width;
	}

	std::string GUIText::getText() {
		return text;
	}

	SDL_Color GUIText::getColor() {
		return color;
	}

	TTF_Font* GUIText::getFont() {
		return font;
	}

	GUIText::~GUIText() {
		SDL_DestroyTexture(texture);
	}
}
