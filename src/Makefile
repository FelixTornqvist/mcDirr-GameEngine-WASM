OBJS = Main.o GameEngine.o Sprite.o FramedSprite.o AnimatedSprite.o PhysicalSprite.o System.o VisualSprite.o Loader.o
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
	$(CC) $(CFLAGS) $(COMPILERFLAG) AnimatedSprite.cpp

PhysicalSprite.o : PhysicalSprite.hpp Sprite.o
	$(CC) $(CFLAGS) $(COMPILERFLAG) PhysicalSprite.cpp

Sprite.o : Sprite.hpp Sprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Sprite.cpp

System.o : System.hpp System.cpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) System.cpp

VisualSprite.o : VisualSprite.hpp VisualSprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) VisualSprite.cpp

Loader.o : Loader.hpp Loader.cpp System.hpp
	$(CC) $(CFLAGS) $(COMPILERFLAG) Loader.cpp


clean:
	rm *.o