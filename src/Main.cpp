#include <iostream>
#include "Sprite.h"
#include "Sprite.h"
#include "GameEngine.h"

#define FPS 60

using namespace std;
using namespace mcDirr;

int main(int argc, char** argv) {
	//test code
	cout << "hello world!" << endl;
	GameEngine ge = GameEngine("mcDirr - The gaem", FPS);
	Sprite* s1 = new Sprite("media/ebbug.png");
	Sprite* s2 = new Sprite("media/gubbe.bmp");

	ge.add(s1);
	ge.add(s2);


	ge.run();

	return 0;
}

