#include <iostream>
#include "Sprite.h"


namespace mcDirr {
	Sprite::Sprite(std::string message):msg(message) {
		//ctor
	}

	void Sprite::tick(int timeDiff) {
	}

	void const Sprite::draw() {
	}

	Sprite::~Sprite() {
		//dtor
	}
}
