#include "TextSprite.hpp"
#include "Loader.hpp"

namespace mcDirr {

	TextSprite::TextSprite(TTF_Font* fnt, SDL_Color colour, std::string txt):
		VisualSprite(nullptr, 0,0), font(fnt), text(txt), color(colour) {
		surf = TTF_RenderText_Solid(fnt, txt.c_str(), colour);
		texture = loader.loadTexture(surf);
		updateText();
	}

	void TextSprite::setText(std::string txt) {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surf);
		text = txt;
		updateText();
	}

	void TextSprite::updateText() {
		surf = TTF_RenderText_Solid(font, text.c_str(), color);
		texture = loader.loadTexture(surf);
		int width;
		int height;
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		dest.h = height;
		dest.w = width;
	}

	std::string TextSprite::getText() {
		return text;
	}

	TextSprite::~TextSprite() {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surf);
	}
}
