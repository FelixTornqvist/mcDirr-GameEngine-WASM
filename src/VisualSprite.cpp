#include "VisualSprite.hpp"
#include "System.hpp"

namespace mcDirr {
	
	VisualSprite::VisualSprite(SDL_Surface* s, int x, int y) :
		Sprite(s, x, y) {
	}

	void VisualSprite::tick(int timeDiff) {
	}

	void VisualSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &dest);
	}

	VisualSprite::~VisualSprite() {
	}
}
