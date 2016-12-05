#include <iostream>
#include "Sprite.h"
#include "TexturedSprite.h"
#include "GameEngine.h"

#define FPS 60

using namespace std;
using namespace mcDirr;

int main(int argc, char** argv) {
	//test code
	cout << "hello world!" << endl;
	GameEngine* ge = new GameEngine("mcDirr - The gaem", FPS);
	Sprite* s1 = new TexturedSprite("media/ebbug.png");
	Sprite* s2 = new TexturedSprite("media/gubbe.png");

	ge->add(s1);

	ge->run();

	return 0;
}

