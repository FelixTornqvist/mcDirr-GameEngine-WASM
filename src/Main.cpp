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
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);
	Sprite* s1 = new TexturedSprite("media/ebbug.png");
	Sprite* s2 = new TexturedSprite("media/gubbe.bmp");

	ge.add(s1);
	ge.add(s2);


	ge.run();

	return 0;
}

