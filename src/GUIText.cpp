#include "GUIText.hpp"
#include "Loader.hpp"

namespace mcDirr {

	GUIText* GUIText::getInstance(TTF_Font* font, SDL_Color colr, std::string txt) {
		return new GUIText(font, colr, txt);
	}

	GUIText::GUIText(TTF_Font* fnt, SDL_Color colour, std::string txt):
		GUIElement(nullptr), font(fnt), text(txt), color(colour) {
		surf = TTF_RenderText_Solid(fnt, txt.c_str(), colour);
		texture = loader.loadTexture(surf);
		updateText();
	}

	void GUIText::setText(std::string txt) {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surf);
		text = txt;
		updateText();
	}

	void GUIText::updateText() {
		surf = TTF_RenderText_Solid(font, text.c_str(), color);
		texture = loader.loadTexture(surf);
		int width;
		int height;
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		dest.h = height;
		dest.w = width;
	}

	std::string GUIText::getText() {
		return text;
	}

	GUIText::~GUIText() {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surf);
	}
}
