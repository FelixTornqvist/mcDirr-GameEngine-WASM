OBJS = Main.o GameEngine.o FramedSprite.o AnimatedSprite.o PhysicalSprite.o Sprite.o System.o VisualSprite.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I /usr/include/SDL2/ -std=c++11
LFLAGS = -Wall $(DEBUG)
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I /usr/include/SDL2/ -std=c++11

#    gcc -I /Library/Frameworks/SDL2.framework/Headers -framework SDL2 your_file.c


game: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LINKER_FLAGS) -o Game

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

GameEngine.o : GameEngine.hpp GameEngine.cpp System.hpp
	$(CC) $(CFLAGS) GameEngine.cpp

FramedSprite.o : FramedSprite.hpp FramedSprite.cpp Sprite.hpp
	$(CC) $(CFLAGS) FramedSprite.cpp

AnimatedSprite.o : AnimatedSprite.hpp AnimatedSprite.cpp FramedSprite.hpp
	$(CC) $(CFLAGS) AnimatedSprite.cpp

PhysicalSprite.o : PhysicalSprite.hpp Sprite.o
	$(CC) $(CFLAGS) PhysicalSprite.cpp

Sprite.o : Sprite.hpp Sprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) Sprite.cpp

System.o : System.hpp System.cpp
	$(CC) $(CFLAGS) System.cpp

VisualSprite.o : VisualSprite.hpp VisualSprite.cpp Sprite.hpp System.hpp
	$(CC) $(CFLAGS) VisualSprite.cpp

clean:
	rm *.o