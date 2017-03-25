#include <iostream>

#include "System.hpp"
#include "Loader.hpp"
#include "GUITextField.hpp"

#define PADDING 5

using namespace mcDirr;

std::shared_ptr<GUITextField> GUITextField::getInstance(TTF_Font* font, const SDL_Color& color, int width) {
	return std::shared_ptr<GUITextField>( new GUITextField(font, color, width) );
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

	SDL_RenderCopy(sys.getRen(), texture, NULL, &textDest);
}

void GUITextField::updateText() {
	SDL_Surface* surf = TTF_RenderUTF8_Solid(getFont(), getText().c_str(), getColor());
	SDL_DestroyTexture(texture);
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
	if (focus) {
		if (sys.getTyped().size() > 0) {
			text += sys.getTyped();
			updateText();
		}
		if (sys.isBackspaceDown() && text.size() > 0 ) {
			text.pop_back();
			updateText();
		}
	}
}

void GUITextField::mouseClick() {
	if (sys.isMouseButtonDown(SDL_BUTTON_LEFT)) {
		setFocused(!focus);
	}
}

void GUITextField::setFocused(bool focs) {
	focus = focs;
	if (focus)
		sys.startTyping();
	else
		sys.stopTyping();
}

void GUITextField::setX(int x) {
	GUIText::setX(x);
	updateText();
}

void GUITextField::setY(int y) {
	GUIText::setY(y);
	updateText();
}

void GUITextField::setWidth(int w) {
	GUIText::setWidth(w);
	updateText();
}

void GUITextField::setHeight(int h) {
	GUIText::setHeight(h);
	updateText();
}

GUITextField::~GUITextField() {
}
