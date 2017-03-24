OBJS = Main.o GameEngine.o Sprite.o Background.o FramedSprite.o AnimatedSprite.o System.o VisualSprite.o MobileSprite.o AnimatedMobileSprite.o ImmobileSprite.o Projectile.o SantaHero.o EvilCat.o Particle.o Obstacle.o Loader.o Level.o GUIText.o GUITextField.o PauseScreen.o GUIScreen.o GUIElement.o GUIButton.o Screen.o 


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I/usr/include/SDL2/
LFLAGS = -Wall $(DEBUG)
CFLAGSSPRITE = -I/Sprite
COMPILERFLAG = -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I /usr/include/SDL2/

#    gcc -I /Library/Frameworks/SDL2.framework/Headers -framework SDL2 your_file.c

game: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LINKER_FLAGS) $(COMPILERFLAG) -o Game

Main.o: Main.cpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Main.cpp

GameEngine.o : GameEngine.hpp GameEngine.cpp System.hpp Level.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GameEngine.cpp

FramedSprite.o : FramedSprite.hpp FramedSprite.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) FramedSprite.cpp

Background.o : Background.hpp Background.cpp VisualSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Background.cpp

AnimatedSprite.o : AnimatedSprite.hpp AnimatedSprite.cpp FramedSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) AnimatedSprite.cpp

Sprite.o : Sprite.hpp Sprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Sprite.cpp

System.o : System.hpp System.cpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) System.cpp

VisualSprite.o : VisualSprite.hpp VisualSprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) VisualSprite.cpp

MobileSprite.o : MobileSprite.hpp MobileSprite.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) MobileSprite.cpp

AnimatedMobileSprite.o : AnimatedMobileSprite.hpp AnimatedMobileSprite.cpp AnimatedSprite.hpp MobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) AnimatedMobileSprite.cpp

ImmobileSprite.o : ImmobileSprite.hpp ImmobileSprite.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) ImmobileSprite.cpp

Loader.o : Loader.hpp Loader.cpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Loader.cpp

Level.o : Level.hpp Level.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Level.cpp

Projectile.o : Projectile.hpp Projectile.cpp AnimatedMobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Projectile.cpp

SantaHero.o : SantaHero.hpp SantaHero.cpp AnimatedMobileSprite.hpp Level.hpp GameEngine.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) SantaHero.cpp

Obstacle.o : Obstacle.hpp Obstacle.cpp AnimatedMobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Obstacle.cpp

EvilCat.o : EvilCat.hpp EvilCat.cpp AnimatedMobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) EvilCat.cpp

Particle.o : Particle.hpp Particle.cpp MobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Particle.cpp

GUIText.o : GUIText.hpp GUIText.cpp GUIElement.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GUIText.cpp

GUIScreen.o : GUIScreen.hpp GUIScreen.cpp Screen.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GUIScreen.cpp

GUIElement.o : GUIElement.hpp GUIElement.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GUIElement.cpp

GUIButton.o : GUIButton.hpp GUIButton.cpp GUIElement.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GUIButton.cpp

GUITextField.o : GUITextField.hpp GUITextField.cpp GUIText.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GUITextField.cpp

Screen.o : Screen.hpp Screen.cpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Screen.cpp

PauseScreen.o : PauseScreen.hpp PauseScreen.cpp GUIScreen.hpp GUIButton.hpp GUIText.hpp GUITextField.hpp GameEngine.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) PauseScreen.cpp


clean:
	rm *.o
	rm Game