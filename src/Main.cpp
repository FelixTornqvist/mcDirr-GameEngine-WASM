#include <iostream>
#include "Sprite.h"
#include "GameEngine.h"

#define FPS 60

using namespace std;
using namespace mcDirr;

int main(int argc, char** argv) {
	//test code
	cout << "hello world!" << endl;
	Sprite* s1 = new Sprite("sprite1");
	Sprite* s2 = new Sprite("sprite2");
	GameEngine* ge = new GameEngine("mcDirr - The gaem", FPS);

	ge->add(s1);
	ge->add(s2);

	ge->run();

	return 0;
}

