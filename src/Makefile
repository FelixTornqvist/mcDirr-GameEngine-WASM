OBJS = Main.o GameEngine.o Sprite.o FramedSprite.o AnimatedSprite.o System.o VisualSprite.o MobileSprite.o AnimatedMobileSprite.o ImmobileSprite.o InteractionSprite.o Projectile.o SantaHero.o Loader.o Level.o
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

GameEngine.o : GameEngine.hpp GameEngine.cpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) GameEngine.cpp

FramedSprite.o : FramedSprite.hpp FramedSprite.cpp Sprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) FramedSprite.cpp

AnimatedSprite.o : AnimatedSprite.hpp AnimatedSprite.cpp FramedSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) AnimatedSprite.cppw

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

InteractionSprite.o : InteractionSprite.hpp InteractionSprite.cpp AnimatedMobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) InteractionSprite.cpp


Projectile.o : Projectile.hpp Projectile.cpp InteractionSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Projectile.cpp

SantaHero.o : SantaHero.hpp SantaHero.cpp AnimatedMobileSprite.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) SantaHero.cpp



clean:
	rm *.o