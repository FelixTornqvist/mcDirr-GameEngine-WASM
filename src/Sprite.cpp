#include <iostream>
#include "Sprite.h"


namespace mcDirr {
	Sprite::Sprite(std::string message):msg(message) {
		//ctor
	}

	void Sprite::tick(int timeDiff) {
		std::cout << '\t' << this->msg << " tick" << timeDiff << std::endl;
	}

	void const Sprite::draw() {
		std::cout << '\t' << this->msg << " draw" << std::endl;
	}

	Sprite::~Sprite() {
		//dtor
	}
}
