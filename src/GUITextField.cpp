#include <iostream>

#include "System.hpp"
#include "Loader.hpp"
#include "GUITextField.hpp"

#define PADDING 5

using namespace mcDirr;

GUITextField* GUITextField::getInstance(TTF_Font* font, const SDL_Color& color, int width) {
	return new GUITextField(font, color, width);
}

GUITextField::GUITextField(TTF_Font* font, const SDL_Color& colr, int width): GUIText(font, colr, "") {
	dest = {0,0,width + PADDING*2, TTF_FontHeight(font) + PADDING*2};
	textDest = dest;
}

void GUITextField::draw() const {
	if (focus)
		SDL_SetRenderDrawColor(sys.getRen(), 255,255,255,255);
	else
		SDL_SetRenderDrawColor(sys.getRen(), 200,200,200,255);

	SDL_RenderFillRect(sys.getRen(), &dest);
	SDL_SetRenderDrawColor(sys.getRen(), 0,0,0,255);
	SDL_RenderDrawRect(sys.getRen(), &dest);

	SDL_RenderDrawRect(sys.getRen(), &textDest);
	SDL_RenderCopy(sys.getRen(), texture, NULL, &textDest);
}

void GUITextField::updateText() {
	SDL_Surface* surf = TTF_RenderText_Solid(getFont(), getText().c_str(), getColor());
	texture = loader.loadTexture(surf);
	SDL_FreeSurface(surf);

	int width;
	int height;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	textDest.x = dest.x + PADDING;
	textDest.y = dest.y + PADDING;
	textDest.h = height;
	textDest.w = width <= dest.w - PADDING ? width : dest.w - PADDING;
}

void GUITextField::tick(int timeDiff) {
	if (focus && sys.getTypedChar()){
		text += sys.getTypedChar();
		updateText();
	}
}

void GUITextField::mouseClick() {
	if (sys.isMouseButtonDown(SDL_BUTTON_LEFT)) {
		focus = !focus;
		if (focus)
			sys.startTyping();
		else
			sys.stopTyping();
	}
}

GUITextField::~GUITextField() {
}
